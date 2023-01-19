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

#include <string.h>
#include <stdio.h>

/* converts an integer array into a string */
void array_to_string(const int array[], int length, char *outstr)
{
    if (array == NULL) {
        strcpy(outstr, "NULL");
        return;
    }
    strcpy(outstr, "{");
    char *p = outstr + strlen(outstr);
    int dotted = 0;
    for (int i = 0; i < length; i++)
    {
        if (i < 5 || i > length-5) {
            char str[20];
            sprintf(str, "%d%s", array[i], (i == length-1) ? "": ", ");
            strcpy(p, str);
            p += strlen(p);
        } else if (! dotted) {
            strcpy(p, "..., ");
            p += strlen(p);
            dotted = 1;
        }
    }
    strcpy(p, "}");
}
