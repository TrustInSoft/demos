#!/bin/bash
############################################################################
#                                                                          #
#  This file is part of TrustInSoft Analyzer.                              #
#                                                                          #
#    Copyright (C) 2023 TrustInSoft                                        #
#                                                                          #
#  All rights reserved.                                                    #
#                                                                          #
############################################################################
#
# This script sets-up and configures the project to make it analyzable.

set -Eeuo pipefail


################################################################################
# Global variables & utility functions

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"
# shellcheck disable=SC2034
readonly SCRIPT_DIR
readonly NO_COLOR="${NO_COLOR:-}"

FILES_TO_CLEAN=()

function warning {
  if [[ -z "$NO_COLOR" ]]; then
    >&2 echo -e "\033[1;33mWarning:\033[0m" "$@"
  else
    >&2 echo "Warning:" "$@"
  fi
}

function error {
  if [[ -z "$NO_COLOR" ]]; then
    >&2 echo -e "\033[1;31mError:\033[0m" "$@"
  else
    >&2 echo "Error:" "$@"
  fi
}

function fatal {
  error "$@"
  exit 1
}

function final_clean_up {
  for f in "${FILES_TO_CLEAN[@]}"; do
    if [[ -f "$f" ]]; then
      rm -f "$f"
    elif [[ -d "$f" ]]; then
      # To avoid cleaning unwanted directory because of programming
      # errors, we do not clean directories outside of '/tmp'.
      if [[ "$f" =~ ^/tmp/.* ]]; then
        rm -rf "$f"
      else
        warning "$f has not been removed (is not in /tmp)."
      fi
    fi
  done
}
trap final_clean_up INT TERM HUP ERR EXIT

function usage {
  cat <<EOF
Usage: $(basename "$0")

Sets-up and configures the project.
EOF
}


################################################################################
# Parsing options

while (( $# > 0 )); do
  case "$1" in
    '') ;;
    -h | -help | --help)
      usage
      exit 0
      ;;
    *)
      usage
      fatal "Unknown option or argument $1."
      ;;
  esac
  shift
done


################################################################################
# Prepare dependencies
#
# This step downloads and prepare all the dependencies required by the project.

function prepare_dependencies {
  echo "== Prepare dependencies =="
}


################################################################################
# Configure builds
#
# This step configures and/or builds the project itself (e.g. generates header
# files required for the analysis, ...).

function configure_build_project {
  echo "== Configure build project =="
}


################################################################################
# Prepare the JSON configuration files
#
# This step generates the JSON configuration files, if required.

function prepare_json_configuration_files {
  echo "== Prepare JSON configuration files =="
}


################################################################################
# Default run:

prepare_dependencies
configure_build_project
prepare_json_configuration_files
