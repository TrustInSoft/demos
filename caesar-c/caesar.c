#include <stdlib.h>
#include <string.h>
#include "caesar.h"
#define NB_LTR ('z' - 'a' + 1)

/* Computes absolute value of a signed integer */

int absolute_int(long x)
{
    long abs_x;

    if (x < 0)
        abs_x = -x;
    else
        abs_x = x;
    return abs_x;
}

char *caesar_encrypt(char *str, long shift)
{
    long abs_shift = absolute_int(shift) % NB_LTR;
    int i = 0;
    char *buf = (char *)malloc(MAX_BUF+1);

    if (buf) {
        while (*str) {
            if (*str >= 'a' && *str <= 'z')
                buf[i] = (*str + abs_shift - 'a') % NB_LTR + 'a';
            else if (*str >= 'A' && *str <= 'Z')
                buf[i] = (*str + abs_shift - 'A') % NB_LTR + 'A';
            else
                /* Spaces and other characters are not encrypted. */
                buf[i] = *str;
            i++;
            str++;
        }
        buf[i] = '\0';
    }

    return buf;
}

char *caesar_decrypt(char *str, long shift)
{
    long abs_shift = absolute_int(shift) % NB_LTR;
    int i = 0;
    char *buf = (char *)malloc(MAX_BUF+1);

    if (buf) {
        while (*str) {
            if (*str >= 'a' && *str <= 'z')
                buf[i] = (*str + (NB_LTR - abs_shift) - 'a') % NB_LTR + 'a';
            else if (*str >= 'A' && *str <= 'Z')
                buf[i] = (*str + (NB_LTR - abs_shift) - 'A') % NB_LTR + 'A';
            else
                /* Spaces and other characters are not encrypted. */
                buf[i] = *str;
            i++;
            str++;
        }
        buf[i] = '\0';
    }

    return buf;
}
