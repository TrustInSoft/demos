#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "increment.h"

/*
The below function is technically correct (no UB) but *probably* functionally incorrect
(it does not return the expected result). It:
- Would fail for functional tests (functional tests or TrustInSoft L3 analysis)
- Would pass for robustness tests (TrustInSoft L1 or L2 analysis)
*/
int increment_short(short i)
{
    return i + 2;
}

/* This one is functionally correct BUT potentially technically incorrect:
- A "smart" TISA L1 analysis may fail
- A generalized TISA L2 analysis will certainly fail
*/
int increment_int(int i)
{
    return i + 1;
}

/*
The below function is technically correct (no UB) but *probably* functionally incorrect
(it does not return the expected result). It:
- Would fail for functional tests (functional tests or TrustInSoft L3 analysis)
- May pass for robustness tests (TrustInSoft L1 or L2 analysis)

*/

void increment_array(int *p, int len)
{
    while (len >= 0)
    {
        (*p)++; // Increment the value at address p
        p++;    // Move to next array cell
        len--;  // Decrement counter
    }
    // The result is functionally correct (each cell of the array
    // was properly incremented) but technically incorrect
    // because it's incrementign 1 cell beyond the end of the array (out of bounds)
    return;
}


int incrementX(int i)
{
    if (i == INT_MAX)
    {
        return 0;
    }
    i++;
    if (i == MAGIC_VALUE)
    {
        return (i % 0xFACE) + (i >> 5);
    }
    return i;
}
