#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "increment.h"

#define SUCCESS "--> PASSED"
#define FAILED  "--> *** FAILED ***"

#ifdef DEBUG
#define DBG printf
#else
#define DBG // 
#endif

int main()
{
    int data[] = {1, 3, 5, 7};
#ifdef LONG_NAME
    char name[] = "TrustInSoft";
#else
    char name[] = "Olivier";
#endif
    printf("\nRun test_increment_array()\n");
    DBG("&data = 0x%lx &name = 0x%lx\n", (unsigned long)data, (unsigned long)name);
    DBG("Before increment array = {%d, %d, %d, %d}, name = %s\n",
        data[0], data[1], data[2], data[3], name);
    increment_array(data, sizeof(data)/sizeof(int));
    DBG("After  increment array = {%d, %d, %d, %d}, name = %s\n",
        data[0], data[1], data[2], data[3], name);

    int ok = (data[0] == 2) && (data[1] == 4) && (data[2] == 6) && (data[3] == 8);
    printf("\nincrement_array({1, 3, 5 ,7}) = {%d, %d, %d, %d} %s\n\n",
        data[0], data[1], data[2], data[3], ok ? SUCCESS: FAILED);
    return (ok ? 0 : 1);
}
