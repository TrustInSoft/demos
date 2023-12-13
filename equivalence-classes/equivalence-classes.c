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
    return pow(i, 2);
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
    int res = square(tis_interval(RANGE_MIN, RANGE_MAX));
    /*@ assert (res >= 0 && res <= 10000);*/
}

void analysis_driver()
{
    eq_class_below_range_verification();
    eq_class_above_range_verification();
    eq_class_within_range_verification();
}

#endif
