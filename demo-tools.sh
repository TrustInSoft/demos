#!/bin/bash
# tis-examples
# Copyright (C) 2022 TrustInSoft
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

BOLD=`tput bold`
CYAN=`tput setaf 6`
GREEN=`tput setaf 2`
RED=`tput setaf 1`
YELLOW=`tput setaf 3`
RESET=`tput sgr0`
UNDERLINE=`tput sgr 0 1`
MAGENTA=`tput setaf 5`

SLEEP_TIME=1

MSG="Press [Enter] to proceed: "
H1="================================================================================"
H2="--------------------------------------------------------------------------------"

steps="true"
# Checkout main branch
git checkout main >/dev/null 2>&1

function press_enter()
{
  [ "$steps" = "true" ] && read -p "$MSG" c
}

function closing()
{
  cat << EOF
${RED}$H1
        With TrustInSoft you can get mathematical guarantee of
        absence of Undefined Behaviors through exhaustive analysis !

        Reach out to us through https://trust-in-soft.com/contact/ if you
        would like to know more about our product.
$H1
${RESET}
EOF
  # Revert to main branch
  git checkout main >/dev/null 2>&1
}
