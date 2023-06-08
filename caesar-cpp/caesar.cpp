#include "caesar.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <type_traits>

// TODO: CharT
// Ciphers a buffer with a right shift specified by the user
std::string Caesar::encrypt(const std::string & input, int offset)
{
    std::string encrypted;
    encrypted.resize(input.length());
    std::transform( // ranges std::ranges::transform(input, )
        std::begin(input), std::end(input),
        std::begin(encrypted),
        [
            shift = details::absolute_int(offset)
        ](std::string::value_type c){ return c + shift; }
    );
    return encrypted;
}

// Deciphers a buffer with a right shift specified by the user
std::string Caesar::decrypt(const std::string & input, int offset)
{
    std::string decrypted;
    decrypted.resize(input.length());

    std::transform( // ranges std::ranges::transform(input, )
        std::begin(input), std::end(input),
        std::begin(decrypted),
        [
            shift = details::absolute_int(offset)
        ](std::string::value_type c){ return c - shift; }
    );
    return decrypted;
}

// Compute absolute value
int Caesar::details::absolute_int(int x)
{
    int abs_x;
    if (x < 0)
        abs_x = -x;
    else
        abs_x = x;
    return abs_x;
}
