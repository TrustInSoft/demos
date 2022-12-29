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
           THE ${YELLOW}increment_array()${CYAN} UNDEFINED BEHAVIOR EXAMPLE
$H1

${GREEN}$H2
In this example we'll show how Undefined Behaviors are quite subtle,
may be visible or not in different execution conditions, and how it can be
extremely difficult to detect them with traditional tests
$H2${RESET}
EOF

press_enter

#------------------------------------------------------------------------------
clear
cat << EOF
${GREEN}$H2
Here's a simple function that increments all cells of an array of integers.
We'll see that this function has an undefined behavior (UB) and, because of
that, a program using this function can behave differently depending on the
context, and the UB can be more or less noticeable depending on cases
$H2${RESET}
EOF

tac increment.c | sed -e '/void increment_array/q' | tac

press_enter
#------------------------------------------------------------------------------
clear
cat << EOF
${GREEN}$H2
This function is tested with the below test driver.
Note the presence of variable ${YELLOW}name${GREEN} that will play a role
$H2${RESET}
EOF

tac test_driver.c | sed -e '/int main()/q' | tac

press_enter

#------------------------------------------------------------------------------
clear
cat << EOF
${GREEN}$H2
Let's compile the program (with gcc) and run a test of it
${RESET}
EOF

sleep $SLEEP_TIME
make ut

cat << EOF
${GREEN}As you can see the array is well incremented for all its cells.
Despite the Undefined Behavior, the test passes
${RESET}
EOF

press_enter

#------------------------------------------------------------------------------
clear
cat << EOF
${GREEN}$H2
Now let's compile with a bit more information logged on stdout during the test
${RESET}
EOF

sleep $SLEEP_TIME
make ut-gcc

cat << EOF
${GREEN}If you carefully look, you'll notice that the compiler stored the ${YELLOW}name${GREEN} variable
in memory just after the ${YELLOW}data${GREEN} variable (16 bytes further, just the size of ${YELLOW}data${GREEN}).
...and when we display the ${YELLOW}name${GREEN} variable before and after calling ${YELLOW}increment_array()${GREEN} we can see
that this variable is affected (It was "${RED}O${GREEN}livier" before the call, and becomes "${RED}P${GREEN}livier"
after the call) even though it is not used for the call to ${YELLOW}increment_array()${GREEN}

The reason for that is the buffer overflow in ${YELLOW}increment_array()${GREEN} that increments past the end
of the array and overwrites the memory location that happens to be the location of ${YELLOW}name${GREEN}
${RESET}
EOF

press_enter

#------------------------------------------------------------------------------
clear
cat << EOF
${GREEN}$H2
Now let's run the same code and test, but compiled with clang instead of gcc
${RESET}
EOF

sleep $SLEEP_TIME
make ut-clang

cat << EOF
${GREEN}clang decides for another way of storing the ${YELLOW}data${GREEN} and ${YELLOW}name${GREEN} variables in memory.
If you look at the addresses, ${YELLOW}data${GREEN} is after ${YELLOW}name${GREEN}, not before

In this context the UB remains completely invisible (${YELLOW}name${GREEN} is not modified), even if the
tester has the idea to verify the variable name, because the memory overwritten by the
${YELLOW}increment_array()${GREEN} buffer overflow is not overlapping with ${YELLOW}name${GREEN}.
The UB problem is nevertheless still present.
${RESET}
EOF

press_enter

#------------------------------------------------------------------------------
clear
cat << EOF
${GREEN}$H2
Another example of the non-deterministic behavior of the code due to the UB.

Let's compile again with gcc (just like in the 2nd run), but change the value of variable ${YELLOW}name${GREEN}
from "Olivier" to "TrustInSoft". And run the test again. We could expect the name to be
changed into "${RED}U${GREEN}rustInSoft" because of the buffer overflow. Let's see...
${RESET}
EOF

sleep $SLEEP_TIME
make ut-gcc-long

cat << EOF
${GREEN}"Que nenni!" as we'd say in old French: For some reason, because the ${YELLOW}name${GREEN}
string size has changed, gcc now decided to implant ${YELLOW}name${GREEN} further past ${YELLOW}data${GREEN} in memory
(precisely 28 bytes). So the array buffer overflow does not overwrites ${YELLOW}name${GREEN}...
(but again: The UB is still well present and is a potential time bomb) 

It's important to be clear that the UB is NOT there because ${YELLOW}name${GREEN} is overwritten, but because
any memory location is overwritten. The UB is present in all tests scenarii above,
just that in some conditions it overwrites the memory location of ${YELLOW}name${GREEN},
and in others another memory location (which is very likely used for some other data so
that's just as bad).
${RESET}
EOF

make clean

press_enter

if [ $(which tis-analyzer) ]; then
    #------------------------------------------------------------------------------
    clear
    cat << EOF
${GREEN}$H2
Let's now analyze the same code with the TrustInSoft Analyzer (TISA).
${RESET}
EOF
    make tis

else

    cat << EOF
${GREEN}You don't have TrustInSoft Analyzer installed on this machine,
but an execution would output something like the below:
${CYAN}
tis-analyzer -val-profile interpreter -val -I. test_driver.c increment.c logutils.c${RESET}
[kernel] [1/7] Parsing TIS_KERNEL_SHARE/libc/__fc_builtin_for_normalization.i (no preprocessing)
[kernel] [2/7] Parsing TIS_KERNEL_SHARE/libc/tis_runtime.c (with preprocessing)
[kernel] [3/7] Parsing TIS_KERNEL_SHARE/__tis_mkfs.c (with preprocessing)
[kernel] [4/7] Parsing TIS_KERNEL_SHARE/mkfs_empty_filesystem.c (with preprocessing)
[kernel] [5/7] Parsing test_driver.c (with preprocessing)
[kernel] [6/7] Parsing increment.c (with preprocessing)
[kernel] [7/7] Parsing logutils.c (with preprocessing)
[kernel] Successfully parsed 3 files (+4 runtime files)
[value] Analyzing a complete application starting at main
[value] Computing initial state
[value] Initial state computed
[value] The Analysis can be stopped by hitting Ctrl-C


Run test_increment_array()

increment.c:27:[kernel] warning: out of bounds write. assert \valid(p);
                  stack: increment_array :: test_driver.c:42 <- main
[value] Stopping at nth alarm
[from] Non-terminating function increment_array (no dependencies)
[from] Non-terminating function main (no dependencies)
[value] user error: Degeneration occurred:
                    results are not correct for lines of code that can be reached from the degeneration point.
[time] Performance summary:
  Parsing: 3.382s
  Value Analysis: 0.049s

  Total time: 0h00m03s (= 3.431 seconds)
  Max memory used: 140.3MB (= 140304384 bytes)
EOF
fi

cat << EOF
${GREEN}
$H2
As you can see from the warning:
${RESET}increment.c:27:${MAGENTA}[kernel] warning:${RESET} out of bounds write. assert \valid(p);
${GREEN}above, the UB is detected.${RESET}
EOF

press_enter

cat << EOF

${GREEN}$H2
With the TrustInSoft Analyzer the analysis/test result is deterministic,
not context/memory layout dependent. There is a UB and it will always be
detected and reported whatever the environment.${RESET}
EOF

closing
