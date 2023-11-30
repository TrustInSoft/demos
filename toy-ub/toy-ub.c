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

#ifndef NAME_MAX_SIZE
#define NAME_MAX_SIZE 7
#endif

#define RED "\033[0;31m"
// #define GREEN "\033[0;32m"
#define RESET "\033[0m"

int main(int argc, char *argv[])
{
    int data[4] = {0};
    char name[NAME_MAX_SIZE+1]; 
    if (argc != 6) {
        printf("Usage: %s <name> <i> <j> <k> <l>\n", argv[0]); exit(1);
    }
    strcpy(name, argv[1]);

    for (int i=0; i<4 && i<argc-2; ++i)
        data[i] = atoi(argv[i+2]);
    
    for (int i=0; i<=4; ++i) data[i] += 1;
    
    printf("\nHello %s%s%s, incremented values to %d, %d, %d, %d\n\n", RED, name, RESET, data[0], data[1], data[2], data[3]);
}
