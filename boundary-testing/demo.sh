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

set -euo pipefail

source ../tis-examples-tools.sh

#------------------------------------------------------------------------------
clear
cat << EOF

${CYAN}$H1
           LIMITATIONS OF BOUNDARY TESTING
$H1

${GREEN}$H2
In this example we'll why boundary testing may not be a sufficient way to detect
specific values that may cause problems such as division by zero in you code.
$H2${RESET}
EOF


[ "$steps" = "true" ] && read -p "$MSG" c
#------------------------------------------------------------------------------
clear
cat << EOF
${GREEN}$H2
We want to do boundary testing of the below simple function that calculates an
output value out of 2 inputs x and y. x and y inputs are expected to be integers
between 1 and 10000. If they are out of this range, the function is expected to
return a special return code OUT_OF_BOUNDS. 
$H2${RESET}
EOF

tac boundary.c | sed -e '/int handle_error()/q' | tac
echo

[ "$steps" = "true" ] && read -p "$MSG" c
#------------------------------------------------------------------------------
cat << EOF
${GREEN}$H2
In order to try to be comprehensive we will have to test a rather large number of combinations for x and y:
- Within the boundaries
- Around the boundaries
// expected inputs: 1 ≤ x ≤ 10000, 1 ≤ y ≤ 10000
(-3,-3)       (0, -3)    ...
(-3, 0)       (0, 0)     ...
(-3, 1)       (0, 1)     ...
(-3, 5000)    (0, 5000)   ...
(-3, 10000)   ...
(-3, 10001)   ...
(-3, 20000)   ...
EOF

#------------------------------------------------------------------------------
clear
cat << EOF
${GREEN}$H2
This function is tested with the below test driver.
$H2${RESET}
EOF

gcc -E test_driver.c | tac | sed -e '/int main()/q' | tac | sed '/^$/d'
echo
[ "$steps" = "true" ] && read -p "$MSG" c

#------------------------------------------------------------------------------
clear
cat << EOF
${GREEN}$H2
Let's run the boundary test driver:
${RESET}
EOF

sleep $SLEEP_TIME
make clean ut

cat << EOF
$H2
${GREEN}As you can see all tests (within boundary, close to boundary and
outside boundary) pass successfully. Structural coverage is 100%.

Unfortunately there is an Undefined Behavior (a division by zero)
that was not detected by the boundary testing because the value that cause the
division by zero are not close to the boundaries but "randomly" within the range
(example: x == 119 and y == 289).

With 2 integers between 1 and 10000 as input vector the input space has
10k x 10k = 100 millions valid possible inputs. It's impossible to test so
many combinations with classical testing techniques (i.e. one by one).
${RESET}
EOF

[ "$steps" = "true" ] && read -p "$MSG" c

#------------------------------------------------------------------------------
clear

cat << EOF
${GREEN}$H2
Now let's run an analysis with the TrustInSoft Analyzer, leveraging it's
input generalization capability. We'll modify the test driver as follows:
${RESET}
EOF

tmpfile=/tmp/test_driver.$$.c
grep -v '#include' test_driver.c >${tmpfile}
gcc -D__TRUSTINSOFT_ANALYZER__ -E ${tmpfile} | tac | sed -e '/int main()/q' | tac|grep -v -E '^# '
rm -f ${tmpfile}

[ "$steps" = "true" ] && read -p "$MSG" c
clear

if [ $(which tis-analyzer) ]; then
    make tis
else
    cat << EOF
You don't have the TrustInSoft Analyzer installed on this machine, but if you would,
an analysis would produce something like the below:

${CYAN}tis-analyzer -val-profile analyzer -val -I. test_driver.c boundary.c${RESET}
[kernel] [1/6] Parsing TIS_KERNEL_SHARE/libc/__fc_builtin_for_normalization.i (no preprocessing)
[kernel] [2/6] Parsing TIS_KERNEL_SHARE/libc/tis_runtime.c (with preprocessing)
[kernel] [3/6] Parsing TIS_KERNEL_SHARE/__tis_mkfs.c (with preprocessing)
[kernel] [4/6] Parsing TIS_KERNEL_SHARE/mkfs_empty_filesystem.c (with preprocessing)
[kernel] [5/6] Parsing test_driver.c (with preprocessing)
[kernel] [6/6] Parsing boundary.c (with preprocessing)
[kernel] Successfully parsed 2 files (+4 runtime files)
[value] Analyzing a complete application starting at main
[value] Computing initial state
[value] Initial state computed
[value] The Analysis can be stopped by hitting Ctrl-C
[value] using specification for function tis_interval
boundary.c:37:[kernel] warning: division by zero: assert d ≢ 0;
                  stack: calculate :: test_driver.c:59 <- main
[value] Done for function main
[time] Performance summary:
  Parsing: 2.411s
  Value Analysis: 0.059s

  Total time: 0h00m02s (= 2.470 seconds)
  Max memory used: 140.3MB (= 140304384 bytes)
EOF
fi

cat << EOF
${GREEN}$H2
As you can see the Division By Zero Undefined Behavior has been detected
deterministically with the below log:

${RESET}boundary.c:37:${MAGENTA}[kernel] warning:${RESET} division by zero: assert d ≢ 0;

${GREEN}If the output log is not self explanatory enough, you may want to
run the TrustInSoft Analyzer GUI to further investigate the problem.
${RESET}
EOF
make clean

[ "$steps" = "true" ] && read -p "$MSG" c
clear
cat << EOF
${GREEN}$H2
With the TrustInSoft Analyzer the analysis/test result is deterministic,
not dependent on the proper selection of boundary/input vectors selected.
There is a division by zero Undefined Behaviour and it will always be detected and
reported whatever the environment.

EOF
closing()
