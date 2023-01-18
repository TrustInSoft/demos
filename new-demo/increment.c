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
#include <stdlib.h>
#include "increment.h"

/*
Increments all cells of an integer array
*/
void increment_array(int array[], int len)
{
    if (array == NULL)
        return;
    while (len >= 0)
    {
        (*array)++; // Increment the value of the array cell
        array++;    // Move to next array cell
        len--;      // Decrement counter
    }
}
