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
#ifdef LONG_NAME
    char name[] = "TrustInSoft";
#else
    char name[] = "Olivier";
#endif
    int len = sizeof(data)/sizeof(int);

    printf("\nRun test_increment_array()\n");
    log_info("Before increment", data, len, name, 1);
    increment_array(data, sizeof(data)/sizeof(int));
    log_info("After  increment", data, len, name, 0);

    int ok = (data[0] == 2) && (data[1] == 4) && (data[2] == 6) && (data[3] == 8);
    printf("\nincrement_array({1, 3, 5, 7}) = %d %s\n\n", data[0], ok ? SUCCESS: FAILED);
    return (ok ? 0 : 1);
}
