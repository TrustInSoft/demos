#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "increment.h"

#define SUCCESS "--> PASSED"
#define FAILED  "--> *** FAILED ***"

#define ARRAY_SIZE 4
#ifdef DEBUG
#define PRINT_DEBUG printf
#else
#define PRINT_DEBUG // 
#endif
int test_increment_array()
{
    int array[] = {1, 3, 5, 7};
#ifdef LONG_NAME
    char name[] = "TrustInSoft";
#else
    char name[] = "Olivier";
#endif
    printf("\nTest of test_increment_array()\n");
    #ifndef __TRUSTINSOFT_ANALYZER__
    PRINT_DEBUG("DEBUG: &array = 0x%lx &name = 0x%lx\n", (unsigned long)array, (unsigned long)name);
    #endif
    PRINT_DEBUG("DEBUG: Hello %s, I will be incrementing array = {%d, %d, %d, %d}\n", name, array[0], array[1], array[2], array[3]);
    increment_array(array, sizeof(array)/sizeof(int));
    PRINT_DEBUG("DEBUG: Hello %s, I have incremented array = {%d, %d, %d, %d}\n", name, array[0], array[1], array[2], array[3]);
    int ok = (array[0] == 2) && (array[1] == 4) && (array[2] == 6) && (array[3] == 8);
    printf("\nincrement_array({1, 3, 5 ,7}) = {%d, %d, %d, %d} %s\n\n",
        array[0], array[1], array[2], array[3], ok ? SUCCESS: FAILED);
    return ok;
}

int main()
{
    test_increment_array();
}
