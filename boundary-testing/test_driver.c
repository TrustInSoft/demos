/*
tis-examples
Copyright (C) 2022 TrustInSoft
mailto:contact AT trust-in-soft DOT com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <stdio.h>
#ifdef __TRUSTINSOFT_ANALYZER__
#include <limits.h>
#include <tis_builtin.h>
#endif
#include "boundary.h"

#define SUCCESS "--> PASSED"
#define FAILED  "--> *** FAILED ***"
int main()
{
#ifndef __TRUSTINSOFT_ANALYZER__
    int inputs[] = {
        -3,-3,         0, -3,         -3, 0,      0, 0,
        -3, 1,         0, 1,          -3, 5000,   0, 5000
        -3, 10000,     -3, 10001,     -3, 20000,  1, 10000,
        10000, 10000,  10001, 10000,  10001, 7,   7, 7
    };
    int len = sizeof(inputs)/sizeof(int);

    printf("\nRun test_calculate()\n");
    int res;
    for (int i = 0; i < len-1; i += 2) {
        int x = inputs[i];
        int y = inputs[i+1];
        res = calculate(x, y);
        printf("calculate(%5d, %5d) = ", x, y);
        if (res == OUT_OF_BOUNDS) {
            printf("OUT_OF_BOUNDS %s\n", (x < 1 || x > 1000 || y < 1 || y > 1000) ? SUCCESS: FAILED); 
        } else {
            printf("%8d      %s\n", res, (x >= 1 && x <= 1000 && y >= 1 && y <= 1000) ? SUCCESS: FAILED);
        }
    }
#else
    int x = tis_interval(INT_MIN, INT_MAX);
    int y = tis_interval(INT_MIN, INT_MAX);
    int res = calculate(x, y);
#endif
    return 0;
}
