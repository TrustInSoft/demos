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

#include <stdio.h>
#ifdef __TRUSTINSOFT_ANALYZER__
#include <limits.h>
#include <tis_builtin.h>
#endif
#include "sine.h"

#define SUCCESS "PASSED"
#define FAILED  "*** FAILED ***"

int main()
{
#ifndef __TRUSTINSOFT_ANALYZER__
    printf("\nTest sine_deg()\n");
    float angle = -5.0f;
    while (angle < 95.0f) {
        float res = sin_deg(angle);
        char strval[20];
        sprintf(strval, "%6.3f", res);
        printf("sin_deg(%6.3f) = %-13s ", angle, (res == OUT_OF_BOUNDS? "OUT_OF_BOUNDS": strval));
        if (res == OUT_OF_BOUNDS) {
            printf("--> %s\n", (angle < 0 || angle > 90) ? SUCCESS: FAILED); 
        } else {
            printf("--> %s\n", (angle >= 0 && angle <= 90) ? SUCCESS: FAILED);
        }
        angle += 0.5;
    }
#else
    float angle = tis_float_interval(-100.0f, 100.0f);
    float res = sin_deg(angle);
#endif
    return 0;
}
