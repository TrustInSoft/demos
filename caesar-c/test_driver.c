#include <stdlib.h>
#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <limits.h>
#include <tis_builtin.h>
#endif

#include "caesar.h"

char str[] = "People of Earth, your attention please";

int gen_test(char *str, long shift)
{
    char *res1, *res2;
    printf("Encrypt text '%s'\n", str);
    res1 = caesar_encrypt(str, shift);
    if (!res1) return 0;
    printf("Result:      '%s'\n", res1);

    printf("Decrypt text '%s'\n", res1);
    res2 = caesar_decrypt(res1, shift);
    if (!res2) return 0;
    printf("Result:      '%s'\n", res2);

    free(res1); free(res2);
    return 1;
}

int test1(void)
{
    printf("Test 1: Shift with a positive input\n");
    int ok = gen_test(str, 7);
    printf(ok ? "Test successful\n": "Test failed\n");
    return ok;
}

int test2(void)
{
    printf("Test 2: Shift with a negative input\n");
    int ok = gen_test(str, -3);
    printf(ok ? "Test successful\n": "Test failed\n");
    return ok;
}

#ifdef __TRUSTINSOFT_ANALYZER__
int test_generalized_int(void)
{
    long any_shift;
    int ok = 1;
    tis_make_unknown(&any_shift, sizeof(any_shift));
    // any_shift = tis_long_interval(LONG_MIN + 1, LONG_MAX);
    printf("\nTest 3: Generalization of shift to any 64 bits signed integer [%ld - %ld]\n", LONG_MIN, LONG_MAX);
    ok = gen_test(str, any_shift);
    return ok;
}

int test_generalized_string(void)
{
    long any_shift;
    // tis_make_unknown(&any_shift, sizeof(any_shift));
    any_shift = tis_long_interval(LONG_MIN + 1, LONG_MAX);
    char any_str[MAX_BUF+1];
    printf("\nTest 4: Generalization of shift and generalization of string to any %d characters string\n", MAX_BUF);

    tis_make_unknown(any_str, MAX_BUF);
    any_str[MAX_BUF] = '\0';
    return gen_test(any_str, any_shift);
}
#endif

int main(void)
{
    
    int ok;
    ok = test1();
    ok = ok && test2();

#if defined LEVEL2 || defined LEVEL2_STEP2
    ok = ok && test_generalized_int();
#ifdef LEVEL2_STEP2
    ok = ok && test_generalized_string();
#endif
#endif

    if (ok) {
        printf("\nAll Tests successful\n\n");
        return 0;
    } else {
        printf("\nSome Tests failed\n\n");
        return 1;
    }
}
