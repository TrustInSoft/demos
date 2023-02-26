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
#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif
#include "boundary.h"

#define SUCCESS "PASSED"
#define FAILED  "*** FAILED ***"

int get_params(int argc, char *argv[], int *x, int *y) {
  if (argc != 2) {
    return 0;
  }
  FILE * f = fopen(argv[1], "r");
  if (fscanf(f, "%d %d", x, y) != 2) {
    return 0;
  } else {
    return 1;
  }
}

int main(int argc, char *argv[])
{
    int res;
    int x, y;
    if (! get_params(argc, argv, &x, &y)) {
      return 1;
    }
    res = calculate(x, y);
    printf("calculate(%d, %d) = ", x, y);
    if (res == OUT_OF_BOUNDS) {
        printf("OUT_OF_BOUNDS --> %s\n",
            (x < 1 || x > 10000 || y < 1 || y > 10000) ? SUCCESS: FAILED); 
    } else {
        printf("%8d      --> %s\n", res,
            (x >= 1 && x <= 10000 && y >= 1 && y <= 10000) ? SUCCESS: FAILED);
    }
    return 0;
}

/*
int main (int argc, char *argv[])
{
  unsigned long len;
  char * filename = argv[1];
  char ** new_argv;
  int new_argc = tis_fuzz_inject_argv_split_by_line(filename, &new_argv);
  int ret = 1;
  if (new_argc >= 3)
    ret = tis_main (3, new_argv);
  return ret;
}
*/