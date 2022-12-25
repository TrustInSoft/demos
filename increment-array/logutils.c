#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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