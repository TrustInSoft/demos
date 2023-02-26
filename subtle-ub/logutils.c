#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
#include "logutils.h"

void log_addresses(const int data[], const char *name)
{
    printf("Address(data) = 0x%lx = %lu\n", (unsigned long)data, (unsigned long)data);
    printf("Address(name) = 0x%lx = %lu\n", (unsigned long)name, (unsigned long)name);
}

void log_array(const int array[], int length)
{
    printf("{");
    for (int i = 0; i < length; i++)
    {
        printf("%d%s", array[i], (i == length-1) ? "": ", ");
    }
    printf("}");
}

void log_info(const char *msg, const int array[], int len, const char *name, int with_addr)
{
#ifdef LOG_VERBOSE
    if (with_addr)
        log_addresses(array, name);
    printf("%s array = ", msg);
    log_array(array, len);
    printf(" - name = %s\n", name);
#endif
}