#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif
using namespace std::string_literals;

#include "caesar.hpp"
#define MAX_BUF 38

#define SUCCESS "\033[0;32mPASSED\033[0m"
#define FAILED "\033[0;31m** FAILED **\033[0m"

const auto str =         "People of Earth, your attention please";
const auto str_shift_7 = u8"Wlvwsl'vm'Lhy{o3'\200v|y'h{{lu{pvu'wslhzl";
const auto str_shift_minus_3 = "Shrsoh#ri#Hduwk/#|rxu#dwwhqwlrq#sohdvh";

int gen_test(const std::string & str, int user_shift, const std::string expected_result)
{
    std::cout << "Encrypt text: '" << str << "'\n";
    auto res1 = Caesar::encrypt(str, user_shift);
    std::cout << "Expected:     '" << expected_result << "'\n";
    std::cout << "Result:       '" << res1 << "'\n";
    std::cout << "Decrypt text: '" << res1 << "'\n";
    auto res2 = Caesar::decrypt(res1, user_shift);
    std::cout << "Result:       '" << res2 << "'\n";
    int ok = res2 == str;
    if (expected_result != "")
        ok = ok && res1 == expected_result && res2 == str;
    return ok;
}


int test1(void)
{
    printf("Test 1: Shift with a positive input\n");
    int ok = gen_test(str, 7, str_shift_7);
    printf("%s: Test 1: Shift with a positive input\n", ok ? SUCCESS : FAILED);
    return ok;
}

int test2(void)
{
    // printf("Test 2: Shift with a negative input\n");
    int ok = gen_test(str, -3, str_shift_minus_3);
    // printf(ok ? "Test successful\n": "Test failed\n");
    printf("%s: Test 2: Shift with a negative input\n", ok ? SUCCESS : FAILED);
    return ok;
}

#if defined(__TRUSTINSOFT_ANALYZER__) && defined(LEVEL2)
int test_generalized_int(void)
{
    long any_shift;
#ifdef EXCLUDE_LONG_MIN
    any_shift = tis_long_interval(LONG_MIN + 1, LONG_MAX);
#else
    tis_make_unknown(&any_shift, sizeof(any_shift));
#endif
    printf("\nTest 3: Generalization of shift to any 64 bits signed integer [%ld - %ld]\n", LONG_MIN, LONG_MAX);
    gen_test(str, any_shift, "");
    return 1;
}

int test_generalized_string(void)
{
    long any_shift;
    char my_str[MAX_BUF];
    tis_make_unknown(my_str, MAX_BUF-1);
    my_str[MAX_BUF-1] = '\0';
    std::string any_str = my_str;

    printf("\nTest 4: Generalization of shift and generalization of string to any %d characters string\n", MAX_BUF);

    any_shift = tis_long_interval(LONG_MIN + 1, LONG_MAX);

    return gen_test(any_str, any_shift, "");
}
#endif

int main(void)
{
    std::string str = "People of Earth, your attention please";
    int ok;

    long any_shift = 4;
    char my_str[MAX_BUF] = "Hello world";
    std::string any_str = my_str;
    return gen_test(any_str, any_shift, "");

    ok = test1();
    ok = test2() && ok;
#if defined(__TRUSTINSOFT_ANALYZER__) && defined (LEVEL2)
    ok = test_generalized_int() && ok;
    ok = test_generalized_string() && ok;
#endif

    if (ok) {
        std::cout << "Tests successful\n";
        return 0;
    } else {
        std::cout << "Tests failed\n";
        return 1;
    }
}


int test_generalized_string_2(void)
{
    long any_shift = 3;
    std::string any_str = "Foo";
    any_str.resize(MAX_BUF);
    printf("\nTest 4: Generalization of shift and generalization of string to any %d characters string\n", MAX_BUF);
    return gen_test(any_str, any_shift, "");
}