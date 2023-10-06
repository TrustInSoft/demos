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
#include <limits.h>
#include "primes.h"

void init_buffer(int buffer[], int value, int start_index, int end_index)
{
    if (buffer == NULL || start_index > end_index)
        return;

    for (int i = start_index; i <= end_index; i++)
    {
        buffer[i] = value;
    }
}

int is_prime(unsigned int number)
{
    if (number <= 1) return 0;
    for (unsigned int i = 2; i < number/2; i++)
    {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

/* Returns all prime numbers between 0 and max_number */
int get_prime_numbers(unsigned int array[], unsigned int max_number)
{
    int index = 0;
    for (int i = 0; i <= max_number; i++) {
        if (is_prime(i)) {
            array[index] = i;
            index++;
        }
    }
    return index;
}