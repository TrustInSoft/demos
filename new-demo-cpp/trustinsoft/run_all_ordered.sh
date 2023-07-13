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
   save_file="_results/analysis.${analysis_nbr}.save"
   if [ -f "$save_file" ]; then
      ndx=$(expr ${analysis_nbr}-1)
      base_name=$(cat ${CONFIG} | jq -r ".[$(expr ${analysis_nbr}-1)].name")
      opt=(
         -load "$save_file"
         -tis-report-basename "${base_name}"
         -tis-report
      )
   else
      opt=(
         -tis-config-load "${CONFIG}"
         -tis-config-select "${analysis_nbr}"
         -save "$save_file"
         -tis-report
      )
   fi
   echo "### " tis-analyzer "${opt[@]}" | tee "${DIR}/analysis.${analysis_nbr}.log"
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

while [ $# -ne 0 ]; do
   case "${1}" in
      -n)
         shift
         nbr_parallel_analyses=${1}
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
parallel -j $nbr_parallel_analyses run_analysis ::: $(echo "3 2 4 5" | sed 's/ /\n/g')

