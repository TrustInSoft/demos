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
#include <iostream>
#include "increment.hpp"

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

#define SUCCESS "\033[0;32mPASSED\033[0m"
#define FAILED "\033[0;31m** FAILED **\033[0m"

int test_array(IncrementableArray<int> array)
{
    bool ok = true;
    IncrementableArray<int> out_array = IncrementableArray<int>(array);
    out_array.increment(1);
    for (int i = 0; i < array.get_size(); i++)
    {
        ok = (out_array.get(i) == array.get(i) + 1) && ok;
    }
    std::cout << (ok ? SUCCESS : FAILED) << ": increment_array(" << array.toString() << ") = " <<
        out_array.toString() << std::endl;
    return ok;
}

int test_small_array()
{
    int a[] = {1, 3, 5, 7, 11, 13, 17};
    IncrementableArray<int> array(a, 7);
    return test_array(array);
}

int test_large_array()
{
    IncrementableArray<int> array(500);
    for (int i = 0; i < array.get_size(); i++)
        array.set(i, rand() > RAND_MAX / 2 ? rand() : -rand());
    return test_array(array);
}

int test_zero_length()
{
    IncrementableArray<int> array(0);
    return test_array(array);
}

int test_null()
{
    IncrementableArray<int> array;
    return test_array(array);
}

#ifdef __TRUSTINSOFT_ANALYZER__

void test_generalized_array()
{
    // This corresponds to 2^32^1000 combinations
    // i.e approximatively 9 x 10^9632 inputs values
    IncrementableArray<int> array(1000);
    for (int i = 0; i < array.get_size(); i++)
        array.set(i, tis_interval(INT_MIN, INT_MAX));
    array.increment(1);
}


#endif

int main()
{

    bool ok = true;
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
