#include <limits.h>
#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#include <math.h>
#endif

#define RANGE_MIN -1000
#define RANGE_MAX 1000

// Returns the square of if RANGE_MIN <= i <= RANGE_MAX
// Returns -1 if i < RANGE_MIN or i < RANGE_MAX
int square(int i)
{
    if (i < RANGE_MIN || i > RANGE_MAX) return -1;
    return i * i;
}

int classic_equivalence_classes_test()
{
    int class1[] = { INT_MIN, -424242, RANGE_MIN-1, RANGE_MAX+1, 42424242, INT_MAX };
    int len = sizeof(class1) / sizeof(class1[0]);
    for (int i = 0; i < len; ++i) {
        assert(square(class1[i] == -1));
    }

    int class2[] = { RANGE_MIN, RANGE_MIN+1, -1, 0, 1, RANGE_MAX-1, RANGE_MAX };
    len = sizeof(class2) / sizeof(class2[0]);
    for (int i = 0; i < len; ++i) {
        assert(square(class2[i] == (i * i)));
    }
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
    int res = square(tis_interval_split(RANGE_MIN, RANGE_MAX));
    /*@ assert (res >= 0 && res <= 1000000);*/
}

void analysis_driver()
{
    eq_class_below_range_verification();
    eq_class_above_range_verification();
    eq_class_within_range_verification();
}

#endif
