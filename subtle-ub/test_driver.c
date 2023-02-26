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
#include <stdio.h>
#include <limits.h>
#include "increment.h"
#include "logutils.h"

#define SUCCESS "--> PASSED"
#define FAILED  "--> *** FAILED ***"

int main()
{
    int data[] = {1, 3, 5, 7};
#ifndef NAME
#define NAME "Olivier"
#endif
    char name[] = NAME;
    int len = sizeof(data)/sizeof(int);

    printf("\nRun test_increment_array()\n");
    log_info("Before increment", data, len, name, 1);
    increment_array(data, len);
    log_info("After  increment", data, len, name, 0);

    int ok = (data[0] == 2) && (data[1] == 4) && (data[2] == 6) && (data[3] == 8);
    printf("\nincrement_array({1, 3, 5, 7}) = {%d, %d, %d, %d} %s\n\n",
        data[0], data[1], data[2], data[3], ok ? SUCCESS: FAILED);
    return (ok ? 0 : 1);
}
