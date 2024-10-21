/*
trustinsoft/demos

Copyright (C) 2023 TrustInSoft
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

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "indexgen.h"

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

#define MAX_SIZE 100000
#define I_MIN 140
#define I_MAX 180
#define J_MIN -500
#define J_MAX -400

#define SUCCESS "\033[0;32mPASSED\033[0m"
#define FAILED "\033[0;31m** FAILED **\033[0m"

int test1()
{
    int tab[MAX_SIZE] = {0};
    for (int i = I_MIN; i <= I_MAX; i++) {
        for (int j = J_MIN; j <= J_MAX; j++) {
            int index = index_of(i, j);
            if (index != OFF_LIMITS)
                tab[index] = i + j;
        }
    }
    int ok = 1;
    int failed_index = 0;
    for (int index = 0; ok && index < MAX_SIZE; index++) {
        failed_index = index;
        ok = tab[index] == 0 || 
             (tab[index] >= (I_MIN + J_MIN) && tab[index] <= (I_MAX + J_MAX));
    }
    printf("Test test1: %s\n", ok ? SUCCESS : FAILED);
    return ok;
}

#ifdef __TRUSTINSOFT_ANALYZER__

void generalized_analysis()
{
    int tab[MAX_SIZE] = {0};
    int i = tis_interval(-17000, 1000000);
    int j = tis_interval(-424242, INT_MAX/2);
    int index = index_of(i, j);
    if (index != OFF_LIMITS)
        tab[index] = i + j;
}


#endif

int main()
{

    int ok = 1;
    printf("\nRunning tests\n");
    ok = test1() && ok;

#ifdef __TRUSTINSOFT_ANALYZER__
    generalized_analysis();
#endif
    if (ok)
        printf("\n\033[0;32m---> All tests PASSED\033[0m\n");
    else
        printf("\n\033[0;31m===> Some tests **FAILED**\033[0m\n");
    return (ok ? 0 : 1);
}
