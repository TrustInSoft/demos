#!/bin/bash

ME=$(basename $0)
DIR="$(dirname $0)"
CONFIG="${DIR}/tis.json"
export CONFIG DIR

if [ ! $(which jq) ]; then
   echo "Please install 'jq' to run $ME"
   exit 2
elif [ ! $(which parallel) ]; then
   echo "Please install 'parallel' to run $ME"
   exit 3
fi

function run_analysis {
   analysis_nbr="$1"
   cache="_results/analysis_cache.${analysis_nbr}.save"
   if [ -f "$cache" ]; then
      ndx=$(expr ${analysis_nbr}-1)
      base_name=$(cat ${CONFIG} | jq -r ".[${ndx}].name")
      entry_point=$(cat ${CONFIG} | jq -r ".[${ndx}].main")
      opt=(
         -load "$cache"
         -tis-report-basename "${base_name}"
         -main "${entry_point}"
         -tis-report
      )
   else
      opt=(
         -tis-config-load "${CONFIG}"
         -tis-config-select "${analysis_nbr}"
         -save "$cache"
         -tis-report
      )
   fi
   echo "--> " tis-analyzer "${opt[@]}" | tee "${DIR}/analysis.${analysis_nbr}.log"
   tis-analyzer "${opt[@]}" | tee -a "${DIR}/analysis.${analysis_nbr}.log"
}

function usage {

   cat << EOF
Usage: $ME [-n <n>] [-h]
Description: Runs multiple TrustInSoft analysis in parallel

-n: Defines the max number of parallel analysis, defaults to 1
-h: Displays this help and exits

Example:
$ME -n 5
EOF
   exit 1
}

export -f run_analysis
nbr_parallel_analyses=1
list_of_analyses=""

while [ $# -ne 0 ]; do
   case "${1}" in
      -n)
         shift
         nbr_parallel_analyses=${1}
         ;;
      -a)
         shift
         list_of_analyses="${1}"
         ;;
      *)
         echo "Wrong argument ${1}"
         usage
         ;;
   esac
   shift
done

nbr_analyses=$(jq '. | length' < ${CONFIG})

echo "Main config file = $CONFIG"
echo "Total nbr of analyses configured = $nbr_analyses"
echo "Nbr of analyses to run in parallel = $nbr_parallel_analyses"


if [ "$list_of_analyses" = "" ]; then
   parallel -j $nbr_parallel_analyses run_analysis ::: $(seq 1 $nb_analyses)
else
   parallel -j $nbr_parallel_analyses run_analysis ::: $(echo "$list_of_analyses" | sed 's/ /\n/g')
fi
