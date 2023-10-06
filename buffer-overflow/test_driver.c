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
#include "primes.h"
#include "utils.h"

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

#define SUCCESS "\033[0;32mPASSED\033[0m"
#define FAILED "\033[0;31m** FAILED **\033[0m"

#define MIN(a, b) ((a) > (b) ? (b) : (a))

int test_primes(int n)
{
    unsigned int buffer[100];
    int nb = get_prime_numbers(buffer, n);
    int ok = 1;
    for (int i = 0; i < MIN(100, nb) && ok; i++) {
        ok = is_prime(buffer[i]) && buffer[i] <= n && ok;
    }
    char str[10000];
    array_to_string(buffer, nb, str);
    printf("%s: get_prime_numbers(%d) = %s\n", ok ? SUCCESS : FAILED, n, str);
    return ok;
}

int test_primes_1()
{
    return test_primes(100);
}

int test_primes_2()
{
    return test_primes(1000);
}

int test_primes_3()
{
    return test_primes(10000);
}

#ifdef __TRUSTINSOFT_ANALYZER__

void test_generalized()
{
    int input_array[1000];
    // This corresponds to 2^32^1000 combinations
    // i.e approximatively 9 x 10^9632 inputs values
    tis_make_unknown(&input_array, sizeof input_array);
    
    int len = sizeof(input_array) / sizeof(int);
    return;
}


#endif

int main()
{

    int ok = 1;
    printf("\nRunning unit tests\n");
    ok = test_primes_1() && ok;
    ok = test_primes_2() && ok;
    ok = test_primes_3() && ok;

#ifdef __TRUSTINSOFT_ANALYZER__
    test_generalized_array();
#endif
    if (ok)
        printf("\n\033[0;32m---> All tests PASSED\033[0m\n");
    else
        printf("\n\033[0;31m===> Some tests **FAILED**\033[0m\n");
    return (ok ? 0 : 1);
}
