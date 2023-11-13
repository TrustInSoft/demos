#!/bin/bash
# trustinsoft/demos
# Copyright (C) 2022-2023 TrustInSoft
# mailto:contact AT trust-in-soft DOT com
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 3 of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
# 

# Default config root directory, and config file name
# The below follows the tis-project-manager conventions
CONFIG_ROOT=".trustinsoft"
CONFIG_FILE="${CONFIG_ROOT}/config.json"

# Default directory for results, logs and state save, all relative to the config root directory
RESULTS_SUBDIR="results"
LOGS_SUBDIR="logs"
SAVE_SUBDIR="save"

# For coloring
export FONT_BOLD=$(tput bold)
export FONT_CYAN=$(tput setaf 6)
export FONT_YELLOW=$(tput setaf 3)
export FONT_RESET=$(tput sgr0)

export ME=$(basename $0)


if [ ! $(which jq) ]; then
   echo "Please install 'jq' to run $ME"
   exit 2
fi

function run_analysis {
   analysis_nbr="$1"
   let ndx=${analysis_nbr}-1
   analysis_name=$(jq ".[$ndx][\"name\"]" < ${CONFIG_FILE} | cut -d '"' -f 2)
   if [ "${analysis_name}" = "null" ]; then
      analysis_name=${analysis_nbr}
   fi
   opt=(
      -tis-config-load "${CONFIG_FILE}"
      -tis-config-select "${analysis_nbr}"
      -tis-report
      -tis-report-directory "${RESULTS_DIR}"
      -save "${SAVE_DIR}/${analysis_nbr}.save"
   )

   echo; echo "${FONT_CYAN}tis-analyzer ${opt[@]}${FONT_RESET}"; echo
   tis-analyzer "${opt[@]}" | tee "${LOG_DIR}/analysis.${analysis_name}.log"
}

function usage {

   cat << EOF
Usage: $ME [-n <n>] [-c <configFile>] [-a <ListOfAnalysisNbrs>] [-h]
Description: Runs multiple TrustInSoft analysis in parallel

-n: Defines the max number of parallel analysis, defaults to 1
-c: Provides the name of the config file, by default .trustinsoft/config.json
-a: Provides list of analysis numbers to run, default all of them
-h: Displays this help and exits

Example:
$ME -n 5 -c .trustinsoft/config.json -a "1 3 7 8"
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
         CONFIG_FILE=${1}
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

CONFIG_ROOT="$(dirname ${CONFIG_FILE})"
LOG_DIR="${CONFIG_ROOT}/logs"
RESULTS_DIR="${CONFIG_ROOT}/results"
SAVE_DIR="${CONFIG_ROOT}/save"
export CONFIG_FILE CONFIG_ROOT LOG_DIR RESULTS_DIR SAVE_DIR

if [ ! -f ${CONFIG_FILE} ]; then
	echo "Configuration file \"${CONFIG_FILE}\" not found, exiting..."
	exit 1
fi

nbr_analyses=$(jq '. | length' < ${CONFIG_FILE})

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

echo "${FONT_YELLOW}Main configuration file: $CONFIG_FILE"
echo "${FONT_YELLOW}Total nbr of analyses to run: $nbr_analyses"
echo "${FONT_YELLOW}Nbr of analyses to run in parallel: $nbr_parallel_analyses${FONT_RESET}"
mkdir -p ${LOG_DIR} ${SAVE_DIR} ${RESULTS_DIR}

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
