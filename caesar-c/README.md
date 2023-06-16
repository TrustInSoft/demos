# Demo Caesar Cipher in C

## Overview

This directory demonstrates the TrustInSoft Analysis Level 1 then Level 2 analysis capabilities
The source code used for the demo is the very basic Caesar Cipher algorithm

> The Caesar cipher is one of the simplest and most widely known
> encryption techniques. It is a type of substitution cipher in which
> each letter in the plain text is replaced by a letter some fixed
> number of positions down the alphabet.
>
> [Caesar cipher wiki](http://en.wikipedia.org/caesar_cipher)

For example, with a fixed offset `3`, the letter `A` is replaced by `D`.

```
Plain text:   c a e s a r
Cipher text:  f d h v d u
```

## Starting point

The starting point is the Caesar Cipher code and a test driver that verifies that the Ciphering/Deciphering
works well for 2 discrete values of the shift (one positive (7) and one negative (-3)).
- Run `make` to run the traditional tests with the 2 discrete values

The 2 tests are passing correctly (ie the implementation of the Caesar Cipher seems corrects)
The source code is entirely covered by the 2 tests which **could** imply the tests are exhaustive.
We'll see that this is not the case.
- Run `make cov` to run coverage tests. Output is 100%

## TrustInSoft Analyzer Level 1 analysis

We run the TrustInSoft Analyzer at level 1, ie we'll re-run the test driver with all the discrete values already
existing in the traditional tests (7 and -3 respectively), to first verify that there is no **Undefined Behaviors**
with the existing values

- Run `make tis` to run the TrustInSoft Analyzer at Level 1

Outcome: The TrustInSoft Analyzer reveals absence of UB on the existing test discrete values.

Let's proceed then to Level 2 analysis

*Note: Verifying absence of UB on Level 1 analysis is a very recommended step before proceeding to Level 2*

## TrustInSoft Analyzer Level 2 analysis

### Generalizing the input offset from 2 to all possible 2^64 values

We'll now run a Level 2 analysis. The principle of L2 analysis is to generalize the discrete values of L1 analysis
test with all possible values for the inputs, eg for the Ceasar cipher we'll generalize the 2 tested integers used for the offset to all possible integer values. That's 2^64 values.

We'll modify the test driver to add TrustInSoft Analyzer specific instructions. 2 lines will suffice
```c
int any_shift;
tis_make_unknown(&any_shift, sizeof(shift));
gen_test(str, any_shift);     // Replace the discrete value by the any_shift variable to test ALL possible shift values
```

After running the TrustInSoft Analyzer L2 (ie generalizing the offset value to all possible 64 bits integer values)
an UB is detected (Integer overflow) for value INT_MIN.
Indeed the result of ciphering the input string with the INT_MIN offset is undefined and likely to have random
behavior. This is a bug. 

The source code of the Caesar Cipher should be modified to cover this case.

In the demo we'll instead exclude `INT_MIN` from the possible input values in the test driver and we'll proceed
to further generalize the test inputs

### Generalizing the input buffer to any possible string up to a given size

Currently the test driver uses a fixed input string `People of Earth, your attention please`.
We want to prove that whatever the input string (up to 38 characters) the Caesar Cipher has no Undefined Behaviors.
This will multiply the 2^64 tests by another 256^38 values.

The test driver is modified to also generalize the input buffer (on top of the offset).
```c
#define BUFSIZE 38
int any_shift;
tis_make_unknown(&any_shift, sizeof(shift));
char any_str[BUFSIZE+1];
tis_make_unknown(any_str, BUFSIZE);
any_str[BUFSIZE] = 0;
// Exclude case if INT_MIN in test driver
if (any_shift != INT_MIN) {
   gen_test(any_str, any_shift);
}
```

**Running the TrustInSoft Analyzer with the above test driver is successful (no problem detected).
We have demonstrated the absence of Undefined Behaviors whatever the input to the Caesar Cipher
for all possible 256^38*(2^64-1) values**


## Annexes

### API Reference

The user provides the string to encrypt as well as the corresponding
shifting value, and the same applies for the decrypt version.

The specificity of the `caesar_encrypt` function is that it always
performs a shift to the right while the `caesar_decrypt` function
always performs a shift to the left.

```c
/* \brief Encrypt a string with a right shift specified by the user
   \param [in] str The string to encrypt
   \param [in] d The right shift to perform
   \return The pointer to the encrypted string
*/
char *caesar_encrypt(char *str, int shift);

/* \brief Decrypt a string with a left shift specified by the user
   \param [in] str The string to decrypt
   \param [in] d The left shift to perform
   \return The pointer to the decrypted string
*/
char *caesar_decrypt(char *str, int shift);
```

## Test suite

A test driver has been written to check the functional correctness of
the source code:

```
∀ string str, int d, caesar_decrypt(caesar_encrypt(str, d), d) = str
```

The test driver performs two tests:

1. encrypt and decrypt a string with a negative shift value
2. encrypt and decrypt a string with a positive shift value

The two tests aim at covering all the source code and checking the
source code specification (i.e. passing a negative value to
`caesar_encrypt` should still perform a shift to the right).

### Results

```
$ gcc -I. -fprofile-arcs -ftest-coverage caesar.c main.c && ./a.out

Test 1: Shift with a negative input
Encrypt text 'People of Earth, your attention please'
Result: Shrsoh ri Hduwk/ |rxu dwwhqwlrq sohdvh
Decrypt text 'Shrsoh ri Hduwk/ |rxu dwwhqwlrq sohdvh'
Result: People of Earth, your attention please

Test 2: Shift with a positive input
Encrypt text 'People of Earth, your attention please'
Result: Wlvwsl vm Lhy{o3 �v|y h{{lu{pvu wslhzl
Decrypt text 'Wlvwsl vm Lhy{o3 �v|y h{{lu{pvu wslhzl'
Result: People of Earth, your attention please
```

```
$ gcov caesar.c

File 'caesar.c'
Lines executed:100.00% of 17
caesar.c:creating 'caesar.c.gcov'
```
