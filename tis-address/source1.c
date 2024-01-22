#include <stdio.h>

#define PIN_0     0x2000000
#define PIN_0_LEN 10

int main()
{
    for(int i = 0; i < PIN_0_LEN; i++)
    {
        char c = *(char*)(PIN_0+i);
        printf("%c", c);
    }

    // Wrong example
    for(int i = 0; i <= PIN_0_LEN; i++)
    {
        char c = *(char*)(PIN_0+i);
        printf("%c", c);
    }
}