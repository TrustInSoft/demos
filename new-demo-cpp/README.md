<!--
trustinsoft/demos
Copyright (C) 2023 TrustInSoft
mailto:contact AT trust-in-soft DOT com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
-->

# Demo of buffer overflow/array out of bounds detection

This demo demonstrates TrustInSoft Analyzer capabilities on C++ code:
- How unit tests can typically miss undefined behaviors like buffer overflows or integer overflows if those undefined behaviors do not cause immediate problems (like a crash), and
- How TrustInSoft analysis detects them with mathematical guarantee.

<!--
Note: If you have an Ubuntu machine you can run this demo live by running:
```bash
git clone https://github.com/TrustInSoft/trustinsoft/demos
cd new-demo-cpp
./demo.sh
``` 
-->

## Code under test

The code to be tested is the [increment.hpp](increment.hpp#L92) source file.

This file contains a templated class with one method `IncrementableArray<T>::increment(T val)` that takes an array of integer (and its length) as input and increments by 1 all integers in the array.
The code of `IncrementableArray<T>::increment(T val)` is the following:
```cpp
template <typename T>
void IncrementableArray<T>::increment(T val)
{
    if (this->size <= 0)
        return;
    int index = this->size;
    T *item = this->array;
    while (index >= 0)
    {
        T value = *item;
        (*item) = value + 1; // Increment the value of the array cell
        item++;              // Move to next array cell
        index--;             // Decrement loop counter
    }
}
```

## Unit tests

The test driver [test_driver.cpp](test_driver.c#L50) has several unit tests meant to test that function.
- Test with small array of a few static integers
- Test with a larger array (1000 cells) of random integers
- Test with an empty array
- Test with an null (unallocated) array

When running the 4 unit tests, they all pass, and on top of that the code coverage is 100%. This can be verified by running `make clean test`
```
$ make clean test

g++ -I. -fprofile-arcs -ftest-coverage test_driver.cpp increment.cpp -o increment && ./increment

Running unit tests
PASSED: increment_array({1, 3, 5, 7, 11, 13, 17}) = {2, 4, 6, 8, 12, 14, 18}
PASSED: increment_array({846930886, 1714636915, 424238335, -1649760492, -1189641421, ..., -878777377, -531352976, 413892161, 1455252833}) = {846930887, 1714636916, 424238336, -1649760491, -1189641420, ..., -878777376, -531352975, 413892162, 1455252834}
PASSED: increment_array({}) = {}
PASSED: increment_array(NULL) = NULL

---> All tests PASSED
```

Despite the above passing tests we'll see that there are undetected undefined behaviors (or UB below in this document), more specifically a **buffer overflow**... and also an **integer overflow**.

Note that gcov is kinda confused by C++ templated classes and does not produce coverage.

## Level 1 analysis - Replay existing unit tests

Level 1 analysis with TrustInSoft is really easy because it simply consists in replaying the unit tests with the TrustInSoft analyzer instead of the Unit Test framework. In the current case the [Makefile](makefile) is preparing the quite simple commands to run the 4 tests so it only requires to run `make tis-l1`.

You need to have the TrustInSoft analyzer installed to successfully run this command. If you don't you can see the output below (uninteresting parts of the output log have been stripped)

```
$ make tis-l1
trustinsoft/run_all.sh -n 4 -a "3 2 4 5"

--> tis-analyzer -tis-config-load trustinsoft/tis.json -tis-config-select 3 -tis-report
[kernel] Loading configuration file trustinsoft/tis.json (analysis #3)
...
[kernel] [7/8] Parsing increment.cpp (external front-end)
[kernel] [8/8] Parsing test_driver.cpp (external front-end)
[kernel] Successfully parsed 2 files (+6 runtime files)
[value] Analyzing a complete application starting at test_large_array
[value] Computing initial state
[value] Initial state computed
[value] The Analysis can be stopped by hitting Ctrl-C
...
increment.hpp:100:[kernel] warning: out of bounds read. assert \valid_read(item);
                  stack: IncrementableArray<int>::increment :: test_driver.cpp:40 <-
                         test_array :: test_driver.cpp:62 <-
                         test_large_array
...
[value] Analyzing a complete application starting at test_small_array
[value] Computing initial state
[value] Initial state computed
[value] The Analysis can be stopped by hitting Ctrl-C
increment.hpp:100:[kernel] warning: out of bounds read. assert \valid_read(item);
                  stack: IncrementableArray<int>::increment :: test_driver.cpp:40 <-
                         test_array :: test_driver.cpp:54 <-
                         test_small_array

-->  tis-analyzer -tis-config-load trustinsoft/tis.json -tis-config-select 4 -tis-report
[kernel] Loading configuration file trustinsoft/tis.json (analysis #4)
...
[value] Analyzing a complete application starting at test_zero_length
[value] Computing initial state
[value] Initial state computed
[value] The Analysis can be stopped by hitting Ctrl-C

PASSED: increment_array({}) = {}

-->  tis-analyzer -tis-config-load trustinsoft/tis.json -tis-config-select 5 -tis-report
[kernel] Loading configuration file trustinsoft/tis.json (analysis #5)
...
[kernel] Successfully parsed 2 files (+6 runtime files)
[value] Analyzing a complete application starting at test_null
[value] Computing initial state
[value] Initial state computed
[value] The Analysis can be stopped by hitting Ctrl-C

PASSED: increment_array(NULL) = NULL
...
===============================================
       2 UNDEFINED BEHAVIORS FOUND
===============================================
Compiling report from 4 past executed tests
information: using analysis _results/1.1.small-array_results.json
information: using analysis _results/1.2.large-array_results.json
information: using analysis _results/1.3.zero-length-array_results.json
information: using analysis _results/1.4.null-array_results.json

Check generated test report tis_report.html
```

As you can witness, 2 undefined behaviors have been found. Actually it's the same undefined behavior revealed by 2 different analyses,
the size of the array making no difference for that problem, both the small array and large array analyses find the same undefined behavior.
(Note: For convenience the HTML analysis report deduplicates multiple occurences of the same undefined behaviour)

The below log section pinpoints at where the undefined behavior is found
```
increment.hpp:100:[kernel] warning: out of bounds read. assert \valid_read(item);
                  stack: IncrementableArray<int>::increment :: test_driver.cpp:40 <-
                         test_array :: test_driver.cpp:54 <-
                         test_small_array
```
That (the logs), plus the [HTML report](.static/tis_report.l1.html) generated by the analysis may be sufficient for the developer to understand what the problem is: In this particular case the array is incremented 1 cell past the end of the array, because of a wrong loop termination condition.

<img src=".static/tis_report.l1.png" alt="TIS report Level 1 analysis" width="700"/>

If that is not the case, one of the tests that detected an UB can be re-executed in GUI mode, where the developer will have access to a full investigation interface to understand the root cause of the problem and the potential fix.
See below a screenshot of this interface on the particular UB.

<img src=".static/l1-buffer-overflow.png" alt="Buffer Overflow GUI screenshot" width="700"/>

The analyzers points at an out of bounds access (dereferencing `item` outside of array bounds). The size of the array was recorded at object creation but the pointer that iterates on the cells of the arrays increments one cell too far, and the analyzer detects that `T value = *item` reads out of the bounds of the array.

After investigation of the problem, one should conclude that the problem comes from the loop end condition.
The code is looping 1 time to much (e.g. 8 loops for an array of 7 integer)
It should be `while (index > 0)` instead of `while (index >= 0)`.

If we fix the code and re-run the 4 unit tests with the TrustInSoft Analyzer, all 4 analyses succeed and demonstrate absence of Undefined Behaviors with the considered inputs (4 differents inputs), See the updated [HTML report](.static/tis_report.l1-no-ub.html)

<img src=".static/tis_report.l1-no-ub.png" alt="TIS report Level 1 fixed" width="700"/>

## Level 2 analysis - Input generalization

Now that Level 1 unit tests are proven to have no undefined behaviors (for the discrete test input values), we can now make our analyses more exhaustive, and generalize the inputs to a much larger input set that the 4 (hopefully smart) values used for unit tests. This is what is called Level 2 analysis.

For that, we generalize the array to any possible array values up to the given array size.
We have chosen a limit of array of 1000 integers. That's **(2^32)^1000 different values** (assuming integers on 32 bits) !
The way we do that is by using one specific TrustInSoft Analyzer built-in primitive called `tis_make_unknown`. This specifies
that the (formal) variable `array`can contain anything (for the whole size of the variable, in our case 4000 bytes)

There are many other analyzer built-in primitives that allow all sorts of different generalizations (interval of values for numbers,
pointer null or not, etc..., See [Documentation](https://man.trust-in-soft.com/search.html#abstract-values))

The very simple generalized test code is the following (see source code at [test_driver.cpp](test_driver.cpp#L81)):
```cpp
void test_generalized_array()
{
    // This corresponds to 2^32^1000 combinations
    // i.e approximatively 9 x 10^9632 inputs values
    IncrementableArray<int> array(1000);
    for (int i = 0; i < array.get_size(); i++)
        array.set(i, tis_interval(INT_MIN, INT_MAX));
    array.increment(1);
}
```

The Level 2 generalized test can be run with `make tis-l2`. You need to have the TrustInSoft Analyzer installed to run this command successfully. If you don't, the output is given below (some uninteresting logs may have been stripped out).

```
-->  tis-analyzer -tis-config-load trustinsoft/tis.json -tis-config-select 6 -tis-report
[kernel] Loading configuration file trustinsoft/tis.json (analysis #6)
...
[kernel] [7/8] Parsing increment.cpp (external front-end)
[kernel] [8/8] Parsing test_driver.cpp (external front-end)
[kernel] Successfully parsed 2 files (+6 runtime files)
[value] Analyzing a complete application starting at test_generalized_array
...
[value] Semantic level unrolling superposing up to 100 states
...
[value] Semantic level unrolling superposing up to 1000 states
increment.hpp:101:[kernel] warning: signed overflow. assert value+1 ≤ 2147483647;
                  stack: IncrementableArray<int>::increment :: test_driver.cpp:86 <-
                         test_generalized_array
...
===============================================
       1 UNDEFINED BEHAVIORS FOUND
===============================================
```

As you can see, the generalization of input has revealed 1 additional undefined behaviors, not found by discrete unit tests. It's an **integer overflow** as quickly highlighted by the log:
```
increment.hpp:101:[kernel] warning: signed overflow. assert value+1 ≤ 2147483647;
                  stack: IncrementableArray<int>::increment :: test_driver.cpp:86 <-
                         test_generalized_array
```
If that is not sufficient to understand the problem, the developer may have a look at the [HTML report](.static/tis_report.l2.html) or even launch the GUI for more dynamic investigation.

<img src=".static/tis_report.l2.png" alt="TIS report Level 2 analysis" width="700"/>

Anyhow, the root cause here is that when an array cell contains the value `INT_MAX`, i.e. `2147483647` on the defined target, trying to increment it will cause an undefined behavior
(an **integer overflow**). A special treatment should be implemented for this value.

## Conclusion

In this demo we have shown a relatively common situation where pretty well defined Unit Tests, all passing, have missed Undefined behaviors.
- By replaying these Unit Tests with the TrustInSoft analyzer we were able to detect a first Undefined Behavior (a **buffer overflow**)
- By further generalizing inputs, we were able to detect a second Undefined Behavior (an **integer overflow**)

Unit Tests are quite useful to verify the functional behavior of the code, but not really it's robustness. TrustInSoft analyzer is an excellent complement to also bring mathematical guarantee of robustness (absence of undefined behaviors)

Note also that, despite the complexity introduced by templated classes, the TrustInSoft analyzer was able to produce a code coverage report (see below), something that was out of reach with simple coverage tools like **gcov**.
<img src=".static/tis_report.coverage.png" alt="TIS report coverage" width="700"/>

Reach out to us through https://trust-in-soft.com/contact/ if you would like to know more about our product.

*Copyright (C) 2022-2023 TrustInSoft*
