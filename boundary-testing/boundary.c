/*
tis-examples
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
#include "boundary.h"

int handle_error()
{
    return OUT_OF_BOUNDS;
}

// Expected input ranges:
// 1 <= x <= 10000
// 1 <= y <= 10000
int calculate(int x, int y)
{
    if (x <= 0 || x > 10000) return handle_error();
    if (y <= 0 || y > 10000) return handle_error();
    int d = 17 * x - 7 * y;
    return 10000 / d;
}
