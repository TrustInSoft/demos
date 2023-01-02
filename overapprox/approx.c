#include <stdio.h>
#ifdef __TRUSTINSOFT_ANALYZER__
#include <limits.h>
#include <tis_builtin.h>
#endif
// If input n is     a multiple of 7, returns 0
// If input n is not a multiple of 7, returns n
int approx(int n)
{
    return (n % 7 ? n : 0);
}

int main()
{
#ifdef __TRUSTINSOFT_ANALYZER__
    {
        int n = tis_interval(0, INT_MAX);
#else
    for (int n = -1000; n <= 1000; n++)
    {
#endif
        int m = 170 / (42 - approx(n));
        printf("main: approx(%d) = %d\n", n, m);

    }
    return 0;
}

#ifdef __TRUSTINSOFT_ANALYZER__

int test1()
{
    int n = tis_interval(-1000, INT_MAX);
    int m = 170 / (42 - approx(n));
    printf("test1: approx(%d) = %d\n", n, m);
    return 0;
}

int test2()
{
    int n = tis_interval(-100, 100);
    int m = 170 / (42 - approx(n));
    printf("test2: approx(%d) = %d\n", n, m);
    return 0;
}

int test3()
{
    int n = tis_interval_split(-1000, 1000);
    int m = 170 / (42 - approx(n));
    printf("test3: approx(%d) = %d\n", n, m);
    return 0;
}

int testn()
{
    int n = tis_interval_split(-10000, 10000);
    int m = 170 / (42 - approx(n));
    printf("testn: approx(%d) = %d\n", n, m);
    return 0;
}

#endif