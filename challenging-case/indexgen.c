/*
trustinsoft/demos
Copyright (C) 2023-2024 TrustInSoft
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
#include "indexgen.h"

int complex_expression(int x, int y)
{
    return abs(x * x + 1182 * x - (y * y) - 882)%100000 - 1;
}

int index_of(int x, int y)
{
    if (x < -10000 || x > 10000 || y < -10000 || y > 10000)
        return OFF_LIMITS;
    return complex_expression(x - 19, y + 30);
}

