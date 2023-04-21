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
#include <stdio.h>
#include <limits.h>
#include "target.h"

#define SUCCESS "\033[0;32mPASSED\033[0m"
#define FAILED "\033[0;31m** FAILED **\033[0m"

// Word size awareness
long double_that(int i)
{
    return (long)i * 2;
}

void test_double_that()
{
    int val = 0x7FFFFFF0;
    // Integer overflow or no integer overflow ?
    long res = double_that(val);
    printf((long)val * 2 == res ? SUCCESS : FAILED);
    printf(": double_that(%d) = %ld", val, res);

    int array[5] = {0, 1, 2, 3, 4};
    int index = res % 5;
    array[index] = 42; // Index out of bounds or not ?
    printf(" and array[%d] = %d\n", index, array[index]);
}

//-------------------------------------
// Endianness awareness
unsigned char msb(unsigned short n)
{
    return *(unsigned char *)&n;
}

void test_msb()
{
    unsigned short val = 0xBEEF;
    unsigned char c = msb(val);
    // c == 0xBE or c == 0xEF ?
    printf( (c == 0xEF) ? SUCCESS: FAILED);
    printf(": msb(0x%X) = 0x%X\n", (unsigned int)val, (unsigned int)c);
    // Div by zero or not ?
    float x = 1 / (0xBE - (int)c);
    return;
}

int main()
{
    printf("\n");
    test_double_that();
    test_msb();
    printf("\n");
}

