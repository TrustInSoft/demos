/*
trustinsoft/demos

Copyright (C) 2022-2023 TrustInSoft
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
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "increment.h"
#include "utils.h"

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

#define SUCCESS "\033[0;32mPASSED\033[0m"
#define FAILED "\033[0;31m** FAILED **\033[0m"

int test_array(int *in_array, int len)
{
    int ok = 1;
    int string_size = 3;
    if (len <= MAX_STRING_CELLS)
        string_size += len * 15;
    else
        string_size += MAX_STRING_CELLS * 15 + 5;
    char input[string_size];
    char output[string_size];

    if (in_array == NULL)
    {
        array_to_string(in_array, len, input);
        increment_array(in_array, len);
        array_to_string(in_array, len, output);
        ok = (in_array == NULL);
    }
    else
    {
        int out_array[len > 0 ? len : 1];
        if (len > 0)
            memcpy(out_array, in_array, len * sizeof(int));
        array_to_string(in_array, len, input);
        increment_array(out_array, len);
        array_to_string(out_array, len, output);
        for (int i = 0; i < len && ok == 1; i++)
        {
            ok = (out_array[i] == in_array[i] + 1) && ok;
        }
    }
    printf("%s: increment_array(%s) = %s\n", ok ? SUCCESS : FAILED, input, output);
    return ok;
}

int test_small_array()
{
    int input_array[] = {1, 3, 5, 7, 11, 13, 17};
    int len = sizeof(input_array) / sizeof(int);
    return test_array(input_array, len);
}

int test_large_array()
{
    int input_array[1000];
    for (int i = 0; i < 1000; i++)
        input_array[i] = (rand() > RAND_MAX / 2 ? rand() : -rand());
    int len = sizeof(input_array) / sizeof(int);
    return test_array(input_array, len);
}

int test_zero_length()
{
    int p[] = {};
    return test_array(p, 0);
}

int test_null()
{
    int *p = NULL;
    return test_array(p, 777);
}


#ifdef __TRUSTINSOFT_ANALYZER__

void test_generalized_array()
{
    int input_array[1000];
    int len = sizeof(input_array) / sizeof(int);
    tis_make_unknown(input_array, sizeof(input_array));
    increment_array(input_array, len);
    return;
}


#endif

int main()
{

    int ok = 1;
    printf("\nRunning unit tests\n");
    ok = test_small_array() && ok;
    ok = test_large_array() && ok;
    ok = test_zero_length() && ok;
    ok = test_null() && ok;

#ifdef __TRUSTINSOFT_ANALYZER__
    test_generalized_array();
#endif
    if (ok)
        printf("\n\033[0;32m---> All tests PASSED\033[0m\n");
    else
        printf("\n\033[0;31m===> Some tests **FAILED**\033[0m\n");
    return (ok ? 0 : 1);
}
