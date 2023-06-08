# Demo Caesar Cipher in C++

## Overview

This directory demonstrates the TrustInSoft Analysis Level 1 then Level 2 analysis capabilities
The source code used for the demo is the very basic Caesar Cipher algorithm written in C++

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
- Run `make test` to run the traditional tests with the 2 discrete values

The 2 tests are passing correctly (ie the implementation of the Caesar Cipher seems corrects)
The test coverage yield by the 2 tests is 100% which **could** imply the tests are exhaustive.

## TrustInSoft Analyzer Level 1 analysis

We run the TrustInSoft Analyzer at level 1, ie we'll re-run the test driver with all the discrete values already
existing in the traditional tests (7 and -3 respectively), to first verify that there is no **Undefined Behaviors**
with the existing values

- Run `make tis-l1` to run the TrustInSoft Analyzer at Level 1 (rerun the same 2 unit tests)

Outcome: The TrustInSoft Analyzer proves absence of UB on the existing test concrete values.

Let's proceed then to Level 2 analysis

*Note: Verifying absence of UB on Level 1 analysis is a very recommended step before proceeding to Level 2*

## TrustInSoft Analyzer Level 2 analysis

### Generalizing the input offset from 2 to all possible 2^64 values

We'll now run a Level 2 analysis. The principle of L2 analysis is to generalize the concrete values of L1 analysis
test with all possible values for the inputs, eg for the Ceasar cipher we'll generalize the 2 tested integers used for the offset to all possible integer values. That's 2^64 values.

We'll modify the test driver to add TrustInSoft Analyzer specific instructions. 2 lines will suffice
```c
int any_shift;
tis_make_unknown(&any_shift, sizeof(shift));
gen_test(str, any_shift, "");     // Replace the concrete shift value by the abstract any_shift variable to test ALL possible shift values
```

After running the TrustInSoft Analyzer L2 (ie generalizing the offset value to all possible 64 bits integer values)
an Undefined Behavior is detected (Integer overflow) for value `LONG_MIN` (or `-9223372036854775808`).
Indeed the result of ciphering the input string with the `LONG_MIN` offset is undefined and likely to have random
behavior. This is a bug. 

The source code of the Caesar Cipher should be modified to cover this case.

In the demo we'll instead exclude `LONG_MIN` from the possible input values in the test driver and we'll proceed
to further generalize the test inputs

### Generalizing the input buffer to any possible string up to a given size

Currently the test driver uses a fixed input string `People of Earth, your attention please`.
We want to prove that whatever the input string (up to `38` characters) the Caesar Cipher has no Undefined Behaviors.
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
   gen_test(any_str, any_shift, "");
}
```

**Running the TrustInSoft Analyzer with the above test driver is successful (no alarm raised).
We have demonstrated the absence of Undefined Behaviors whatever the input to the Caesar Cipher
for all possible 256^38*(2^64-1) values, i.e. approximatively 6 x 10^110 values**
