#!/bin/bash
# trustinsoft/demos
# Copyright (C) 2023 TrustInSoft
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

source ../demo-tools.sh

git checkout -q -- increment.c

#------------------------------------------------------------------------------
clear
cat << EOF

${CYAN}$H1
           DETECTING UNDEFINED BEHAVIOURS MISSED BY UNIT TESTS
$H1

${GREEN}$H2
This demo demonstrates:
- How unit tests can typically miss undefined behaviors like buffer overflows
  or integer overflows if those undefined behaviors do not cause immediate
  execution problems (like a crash), and
- How TrustInSoft analysis detects them with mathematical guarantee.
$H2${RESET}
EOF

press_enter
#------------------------------------------------------------------------------
clear
cat << EOF
${GREEN}$H2
We want to test a simple function increment_array() that takes an array of integers
as input and increment all its elements by one. 
$H2${RESET}
EOF

tac increment.c | sed '/increment_array(/q' | tac

press_enter
clear

#------------------------------------------------------------------------------
cat << EOF
${GREEN}$H2
To test this function let's say that we have written 4 unit tests:
- One test with an input array of 7 small positive integers {1, 3, 5, 7, 11, 13, 17}
- One test with a larger array of 1000 random integers
- 2 tests with corner cases with an empty array ({}) or a NULL array
$H2${RESET}
EOF

cat test_driver.c | tac | sed '/int *test_small_array()/q' | tac | sed '/__TRUSTINSOFT/q' | head -n -1

press_enter
#------------------------------------------------------------------------------
clear

cat << EOF
${GREEN}$H2
Let's run the unit tests:
${RESET}
EOF

sleep $SLEEP_TIME
make clean test

cat << EOF
$H2
${GREEN}As you can see all tests pass successfully. Structural coverage is 100%.

We'll see further that, despite the above good results, there are undetected
undefined behaviors (or UB further), more specifically a ${BOLD}${RED}buffer overflow${RESET}...
${GREEN}and also an ${BOLD}${RED}integer overflow
${RESET}
EOF

press_enter
#------------------------------------------------------------------------------
clear

cat << EOF
${GREEN}$H2
The first way to use the TrustInSoft analyzer is simply to replay the unit tests with
the analyzed. This can (this often) detects problems that remained unnoticed with unit
tests. It's convenient because if you already have unit tests, it's almost zero effort
to run the analyzer.
${RESET}
EOF

press_enter

if [ $(which tis-analyzer) ]; then
  make tis-l1
else
  cat << EOF
You don't have the TrustInSoft Analyzer installed on this machine, but if you would,
an analysis would produce something like the below:
EOF
  cat .static/tis-l1.log
fi

cat << EOF
${GREEN}$H2
As you can see from the closing verdict, 2 undefined behaviors have been detected.
It's actually twice the same problem, found in the small and large array test
(the array size has no influence on the occurrence of the problem).
The log already contains a hint at the problem:

${RESET}increment.c:34:${MAGENTA}[kernel] warning:${RESET} out of bounds write. assert \valid(array);
${RESET}

${GREEN}If the output log is not self explanatory enough, you may want to:
- Either look at the generated HTML report, that explains the problem in a
  user friendly (but still static) way
- Or run the TrustInSoft Analyzer GUI (and use it advanced troubleshooting)
  to further  investigate the problem.
${RESET}
EOF

press_enter
cat << EOF
${GREEN}
In this case, the HTML report is enough.
If we look at the small array test it says that, at some point, the array pointer, that
iterates on the array elements, becomes invalid (not pointing to a valid memory region).
The additional information below the code tells us that the pointer is 28 bytes after
the beginning of the array. The array is 7 integers of 4 bytes, i.e. the pointer is after
the end of the array, this is a buffer overflow (or array index out of bounds).

The above information let us suppose that the loop does not stop at the right iteration,
the loop end condition is incorrect.
After looking at the code, indeed the condition should be

${YELLOW}while (len > 0)${GREEN}

instead of 

${YELLOW}while (len >= 0)${GREEN}

Because of the error, the loop runs one time too much, and the array is overflown.

Let's fix that!
${RESET}
EOF

press_enter

sleep 0.5
sed -i "s/while (len >= 0)/while (len > 0)/" increment.c

cat << EOF
${GREEN}
Fix done! If we now rerun the Level 1 analysis, we'll see that the analyzer
will not raise any alarm.
${RESET}
EOF

press_enter
if [ $(which tis-analyzer) ]; then
  make tis-l1
else
  cat << EOF
You don't have the TrustInSoft Analyzer installed on this machine, but if you would,
an analysis would produce something like the below:
EOF
  cat .static/tis-l1-fix.log
fi

cat << EOF
${GREEN}$H2
The analysis now reports 0 undefined behaviors. Good!

Now that we solved all the problems found by simply re-running the unit tests
let's move to the next level: Level 2. This level consists in generalizing
function inputs so that we can detect problem that may arise from any possible
input instead of the few discrete inputs chosen in unit tests.
Instead of testing our increment_array() function with only 4 different arrays,
we'll test with all possible arrays (any size up to 1000 elements, any value for
each array element)

That's 2^32^1000 possibilities or the equivalent of 4 x 10^9000 tests !
${RESET}
EOF

press_enter
if [ $(which tis-analyzer) ]; then
  make tis-l2
else
  cat << EOF
You don't have the TrustInSoft Analyzer installed on this machine, but if you would,
an analysis would produce something like the below:
EOF
  press_enter
  cat .static/tis-l2.log
fi

cat << EOF
${GREEN}$H2
As you can see from the above:
1. First, despite the number of inputs tested, the execution time is quick (the mathematical
   core does not ry one value at a time in brute force fashion
2. Thanks to the input generalization, we have been able to detect a new Undefined Behavior.

${RESET}increment.c:32:${MAGENTA}[kernel] warning:${RESET} signed overflow. assert *array+1 ≤ 2147483647;
${GREEN}
Again here's the log may be sufficient to understand the problem our you can look at the HTML
report to get more details that will let you understand the problem.
${RESET}
EOF

press_enter

cat << EOF
${GREEN}$H2
In the current case, it's an integer overflow. Indeed if the array element already contains the
largest possible signed integer (2147483647), it's not possible to increment it without causing
an integer overflow whose effect is unpredictable.
EOF
closing