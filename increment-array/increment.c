#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "increment.h"

void increment_array(int *p, int len)
{
    while (len >= 0)
    {
        (*p)++; // Increment the value at address p
        p++;    // Move to next array cell
        len--;  // Decrement counter
    }
}
