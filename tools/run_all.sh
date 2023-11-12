#!/bin/bash

export FONT_BOLD=$(tput bold)
export FONT_CYAN=$(tput setaf 6)
export FONT_YELLOW=$(tput setaf 3)
export FONT_RESET=$(tput sgr0)
export ME=$(basename $0)
export LOGS="${PWD}/logs"
export RESULTS="${PWD}/_results"

ME=$(basename $0)
CONFIG="config.json"

if [ ! $(which jq) ]; then
   echo "Please install 'jq' to run $ME"
   exit 2
fi

function run_analysis {
   analysis_nbr="$1"
   let ndx=${analysis_nbr}-1
   analysis_name=$(jq ".[$ndx][\"name\"]" < ${CONFIG} | cut -d '"' -f 2)
   if [ "${analysis_name}" = "null" ]; then
      analysis_name=${analysis_nbr}
   fi
   opt=(
      -tis-config-load "${CONFIG}"
      -tis-config-select "${analysis_nbr}"
      -tis-report
      -save "_results/${analysis_nbr}.save"
   )

   echo; echo "${FONT_CYAN}tis-analyzer ${opt[@]}${FONT_RESET}"; echo
   tis-analyzer "${opt[@]}" | tee "${LOGS}/analysis.${analysis_name}.log"
}

function usage {

   cat << EOF
Usage: $ME [-n <n>] [-h]
Description: Runs multiple TrustInSoft analysis in parallel

-n: Defines the max number of parallel analysis, defaults to 1
-c: Provides the name of the config file, by default ./config.json
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
      -c)
         shift
         CONFIG=${1}
         ;;
      -a)
         shift
         analysis_list=${1}
         ;;
      *)
         echo "Wrong argument ${1}"
         usage
         ;;
   esac
   shift
done

DIR="$(dirname ${CONFIG})"
export CONFIG DIR LOGS
if [ ! -f ${CONFIG} ]; then
	echo "Configuration file \"${CONFIG}\" not found, exiting..."
	exit 1
fi

nbr_analyses=$(jq '. | length' < ${CONFIG})

if [ "$analysis_list" = "" ]; then
   analysis_list=$(seq 1 $nbr_analyses)
else
   nbr_analyses=$(echo $analysis_list | wc -w)
   analysis_list=$(echo $analysis_list | sed "s/ /\n/g")
fi

# Reduce parallelism if number of analyses to do is less than parallelism
if [ $nbr_parallel_analyses -gt $nbr_analyses ]; then
	nbr_parallel_analyses=$nbr_analyses
fi

echo "${FONT_YELLOW}Main configuration file: $CONFIG"
echo "${FONT_YELLOW}Total nbr of analyses to run: $nbr_analyses"
echo "${FONT_YELLOW}Nbr of analyses to run in parallel: $nbr_parallel_analyses${FONT_RESET}"
mkdir -p "$LOGS"

if [ $nbr_parallel_analyses -eq 1 ]; then
   # Don't use parallel if 1 analysis at a time
	for i in $analysis_list; do
		run_analysis $i
	done
else
   # Use parallel if more than 1 analysis at a time
	if [ ! $(which parallel) ]; then
   	echo "Please install 'parallel' to run $ME with "
   	exit 3
	fi
	# Can use options like: -j '75%' timeout 60s
	parallel --progress --eta -j $nbr_parallel_analyses run_analysis ::: $analysis_list
fi

