#!/bin/bash
set -euo pipefail

source "../tools/demo-tools.sh"

SLEEP_TIME=1

MSG="Press [Enter] to proceed: "
H1="================================================================================"
H2="--------------------------------------------------------------------------------"

steps=true
while getopts ":s" opt; do
    case "$opt" in
        s)
            steps=false
            ;;
        *)
            usage
            ;;
    esac
done

clear
#------------------------------------------------------------------------------
cat << EOF

${FONT_CYAN}$H1
           THE ${FONT_YELLOW}array_increment()${FONT_CYAN} UNDEFINED BEHAVIOR DEMO
$H1

${FONT_GREEN}$H2
Here's a simple function that increments all cells of an integer array,
and we'll see that this function has an undefined behavior (UB) and,
because of that, a program using this function can behave differently
depending on the context, and the UB can be more or less noticeable depending on cases"
$H2${FONT_RESET}
EOF

cat increment.c

[ "$steps" = "true" ] && read -p "$MSG" c

#------------------------------------------------------------------------------
clear
cat << EOF

${FONT_GREEN}$H2
Let's compile the program (with gcc) and run it
${FONT_RESET}
EOF

sleep $SLEEP_TIME
make ut

cat << EOF
${FONT_GREEN}
As you can see the array is well incremented for all its cells
${FONT_RESET}
EOF

[ "$steps" = "true" ] && read -p "$MSG" c

#------------------------------------------------------------------------------
cat << EOF

${FONT_GREEN}$H2
Now let's compile with a bit more information printed on stdout
${FONT_RESET}
EOF

sleep $SLEEP_TIME
make ut-debug

cat << EOF
${FONT_GREEN}
If you carefully look, you'll notice that the compiler stored the ${FONT_YELLOW}array${FONT_GREEN} variable
in memory just before the ${FONT_YELLOW}name${FONT_GREEN} variable.
...and when we display the ${FONT_YELLOW}name${FONT_GREEN} variable before and after calling ${FONT_YELLOW}array_increment()${FONT_GREEN} we can see
that this variable is affected (It was "${FONT_RED}O${FONT_GREEN}livier" before the call, and becomes "${FONT_RED}P${FONT_GREEN}livier"
after the call) even though it is not used for the call to ${FONT_YELLOW}array_increment()${FONT_GREEN}

The reason for that is the buffer overflow in ${FONT_YELLOW}array_increment()${FONT_GREEN} that increments past the end
of the array and overwrites the memory location that happens to be the location of ${FONT_YELLOW}name${FONT_GREEN}
${FONT_RESET}
EOF

[ "$steps" = "true" ] && read -p "$MSG" c

#------------------------------------------------------------------------------
cat << EOF

${FONT_GREEN}$H2
Now let's run the same code, but compiled with clang instead of gcc
${FONT_RESET}
EOF

sleep $SLEEP_TIME
make ut-clang

cat << EOF
${FONT_GREEN}
clang decides for another way of storing the ${FONT_YELLOW}array${FONT_GREEN} and ${FONT_YELLOW}name${FONT_GREEN} variables in memory.
If you look at the addresses, ${FONT_YELLOW}array${FONT_GREEN} is after ${FONT_YELLOW}name${FONT_GREEN}, not before

In this context the UB remains completely invisible (${FONT_YELLOW}name${FONT_GREEN} is not modified), even if the
tester has the idea to verify the variable name, because the memory overwritten by the
${FONT_YELLOW}array_increment()${FONT_GREEN} buffer overflow is not overlapping with name.
The UB problem is nevertheless still present.
${FONT_RESET}
EOF

[ "$steps" = "true" ] && read -p "$MSG" c

#------------------------------------------------------------------------------
cat << EOF

${FONT_GREEN}$H2
Another example of the non-deterministic behavior of the code due to the UB.

Let's compile again with gcc (just like in the 2nd run), but change the value of variable ${FONT_YELLOW}name${FONT_GREEN}
from "Olivier" to "TrustInSoft". And run the test again. We could expect the name to be
changed into "${FONT_RED}U${FONT_GREEN}rustInSoft" because of the buffer overflow. Let's see...
${FONT_RESET}
EOF

sleep $SLEEP_TIME
make ut-long-name

cat << EOF
${FONT_GREEN}
"Que nenni!" as we'd say in old French: For god knows why reason, because the ${FONT_YELLOW}name${FONT_GREEN}
string size has changed, gcc now decided to implant ${FONT_YELLOW}name${FONT_GREEN} before array in memory.
So the array buffer overflow does not overwrites ${FONT_YELLOW}name${FONT_GREEN}...
(but again: The UB is still well present and is a potential time bomb) 

It's important to be clear that the UB is NOT there because ${FONT_YELLOW}name${FONT_GREEN} is overwritten, but because
any memory location is overwritten. The UB is present in all tests scenarii above,
just that in some conditions it overwrites the memory location of ${FONT_YELLOW}name${FONT_GREEN},
and in others another memory location (which is very likely used for some other data so
that's just as bad).
${FONT_RESET}
EOF

[ "$steps" = "true" ] && read -p "$MSG" c
#------------------------------------------------------------------------------
cat << EOF
${FONT_GREEN}$H2
Let's now analyze the same code with the TrustInSoft Analyzer (TISA).

EOF

make tis

cat << EOF
${FONT_GREEN}
As you can see from the warning above, the UB is detected.
What is great with TISA is that the analysis result is not context dependent.
There is a UB and it will always be detected and reported whatever the environment.
${FONT_RED}$H1
        That's how you can get mathematical guarantee of
        absence of Undefined Behaviors with TrustInSoft !
$H1
${FONT_RESET}
EOF
