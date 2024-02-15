#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#include <math.h>
#endif

#define SUCCESS "\033[0;32mPASSED\033[0m"
#define FAILED "\033[0;31m** FAILED **\033[0m"

#define RANGE_MIN -1000
#define RANGE_MAX 1000

// Returns the square of if RANGE_MIN <= i <= RANGE_MAX
// Returns -1 if i < RANGE_MIN or i < RANGE_MAX
int square(int i)
{
    if (i < RANGE_MIN || i > RANGE_MAX) return -1;
    return i * i;
}

void classic_equivalence_classes_test()
{
    printf("RUN   : Testing equivalence class 1\n");
    int class1[] = { INT_MIN, -424242, RANGE_MIN-1, RANGE_MAX+1, 42424242, INT_MAX };
    int len = sizeof(class1) / sizeof(class1[0]);
    int res;
    for (int i = 0; i < len; ++i) {
        res = square(class1[i]);
        printf("   square(%d) = %d\n", class1[i], res);
        assert(res == -1);
    }
    printf("%s: Equivalence class 1 test\n", SUCCESS);

    printf("RUN   : Testing equivalence class 2\n");
    int class2[] = { RANGE_MIN, RANGE_MIN+1, -1, 0, 1, RANGE_MAX-1, RANGE_MAX };
    len = sizeof(class2) / sizeof(class2[0]);
    for (int i = 0; i < len; ++i) {
        res = square(class2[i]);
        printf("   square(%d) = %d\n", class2[i], res);
        assert((res == (class2[i] * class2[i])));
    }
    printf("%s: Equivalence class 2 test\n", SUCCESS);
    printf("\n\033[0;32m---> All tests PASSED\033[0m\n\n");
}

#ifdef __TRUSTINSOFT_ANALYZER__

void eq_class_below_range_verification()
{
    // tis_interval(INT_MIN, RANGE_MIN-1) defines the equivalence class [INT_MIN, RANGE_MIN-1]
    int res = square(tis_interval(INT_MIN, RANGE_MIN-1));
    /*@ assert res == -1; */
}

void eq_class_above_range_verification()
{
    // tis_interval(RANGE_MAX+1, INT_MAX) defines the equivalence class [RANGE_MAX+1, INT_MAX]
    int res = square(tis_interval(RANGE_MAX+1, INT_MAX));
    /*@ assert res == -1; */
}

void eq_class_within_range_verification()
{
    // tis_interval(RANGE_MIN, RANGE_MAX) defines the equivalence class [RANGE_MIN, RANGE_MAX]
    int i = tis_interval(RANGE_MIN, RANGE_MAX);
    /*@ assert i < 0 || i >= 0; */
    int res = square(i);
    /*@ assert (res >= 0 && res <= 1000000);*/
}

void analysis_driver()
{
    eq_class_below_range_verification();
    eq_class_above_range_verification();
    eq_class_within_range_verification();
}

#endif

void main()
{
#ifdef __TRUSTINSOFT_ANALYZER__
    analysis_driver();
#else
    classic_equivalence_classes_test();
#endif
}