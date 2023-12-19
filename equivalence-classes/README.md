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

# Demo of equivalence classes verification with TrustInSoft Analyzer

This demo demonstrates, besides detection of undefined behaviors, the TrustInSoft Analyzer is capable of verifyingva certain number of aspects related to equivalence classes, specifically that for a given equivalence class inputv(and input value or an range in TrustInSoft terminology) I get a given output value or value range as output.
Unlike with traditional tests where I can only verify one or a few values of each equivalence class, with the TrustInSoft Analysis you can verify output for the integrality of values in the equivalence class.

<!--
Note: If you have an Ubuntu machine you can run this demo live by running:
```bash
git clone https://github.com/TrustInSoft/trustinsoft/demos
cd equivalence-classes
./demo.sh
``` 
-->

## Code under verification

The code to be analyzed is the [equivalence-classes.c](equivalence-classes.c#L9) source file.
For the sake of simplicity the code to verify (the `square()` function) and the analysis
driver (the `analysis_driver()` function) are in the same file even if in real production
condition they would (should) be in separate files.

The function `square(int i)` returns the square of a integer if it is between -1000 and 1000 and -1 otherwise.
```c
#define RANGE_MIN -1000
#define RANGE_MAX 1000

int square(int i)
{
    if (i < RANGE_MIN || i > RANGE_MAX) return -1;
    return i * i;
}
```
This defines 3 equivalence classes: [INT_MIN, -1001], [-1000, 1000] and [1001, INT_MAX]

With TrustInSoft Analyzer it's very easy to verify that for each of the equivalence classes,
the output for each input is either the expected value (-1), or within the expected output value range
(namely 0 to 1000000 for input betwen -1000 and 1000).

## The analysis driver

The analysis driver [equivalence-classes.c](equivalence-classes.c#L20) has 3 separate verification
functions for each of the equivalence classes (but that could also be a single function if preferred).
- Verification of equivalence class below the nominal range (INT_MIN to -1001)
- Verification of equivalence class above the nominal range (1001 to INT_MAX)
- Verification of equivalence class within the nominal range (-1000 to 1000)

```c
void eq_class_below_range_verification()
{
    int res = square(tis_interval(INT_MIN, RANGE_MIN-1));
    /*@ assert res == -1; */
}

void eq_class_above_range_verification()
{
    int res = square(tis_interval(RANGE_MAX+1, INT_MAX));
    /*@ assert res == -1; */
}

void eq_class_within_range_verification()
{
    int res = square(tis_interval_split(RANGE_MIN, RANGE_MAX));
    /*@ assert (res >= 0 && res <= 1000000);*/
}

void analysis_driver()
{
    eq_class_below_range_verification();
    eq_class_above_range_verification();
    eq_class_within_range_verification();
}
```
See [source code](equivalence-classes.c#L20) for more commented code.

Running the analysis and verifying classes of equivalence is as simple as running:
```
tis-analyzer -val equivalence-classes.c -main analysis_driver
```
And the output would be:
```bash
[kernel] [1/5] Parsing TIS_KERNEL_SHARE/libc/__fc_builtin_for_normalization.i (no preprocessing)
[kernel] [2/5] Parsing TIS_KERNEL_SHARE/libc/tis_runtime.c (with preprocessing)
[kernel] [3/5] Parsing TIS_KERNEL_SHARE/__tis_mkfs.c (with preprocessing)
[kernel] [4/5] Parsing TIS_KERNEL_SHARE/mkfs_empty_filesystem.c (with preprocessing)
[kernel] [5/5] Parsing equivalence-classes.c (with preprocessing)
[kernel] Successfully parsed 1 file (+4 runtime files)
[value] Analyzing a complete application starting at analysis_driver
[value] Computing initial state
[value] Initial state computed
[value] The Analysis can be stopped by hitting Ctrl-C
[value] using specification for function tis_interval
[value] Done for function analysis_driver
[time] Performance summary:
  Parsing: 1.161s
  Value Analysis: 0.038s

  Total time: 0h00m01s (= 1.199 seconds)
  Max memory used: 136.7MB (= 136708096 bytes)
```

In the above case the analysis completed without alarms meaning that all the verifications succeeded.
Let's now modify a bit the production code to be verified to inject an error
```c
int square(int i)
{
    // Using <= and => instead of the correct < and >
    if (i <= RANGE_MIN || i >= RANGE_MAX) return -1;
    return i * i;
}
```

If we rerun the verification, this time it will fail, with the below alarm:
```bash
equivalence-classes.c:38:[value] warning: Assertion got status unknown
                 stack: eq_class_within_range_verification :: equivalence-classes.c:45 <-
                        analysis_driver
```

Likewise, if there is a mistake in the verification of the output range of the equivalence classes,
the analyzer will detect that. With the original (correct) production code, if I modify my driver
as per the below, the verification will fail:
```c
void eq_class_within_range_verification()
{
    int res = square(tis_interval_split(RANGE_MIN, RANGE_MAX));
    // Problem in the assertion below. The upper bound is mistakenly 100'000 instead of 1'000'000
    /*@ assert (res >= 0 && res <= 100000);*/
}
```
Again, the analyzer will output:
```bash
equivalence-classes.c:38:[value] warning: Assertion got status unknown
                 stack: eq_class_within_range_verification :: equivalence-classes.c:45 <-
                        analysis_driver
```

## Conclusion

Aside from being able to detect with no false negative all undefined behaviors in your code,
the TrustInSoft Analyzer is capable of verifying the output raneg for define input ranges
(equivalence classes). This can complement (or substitute in some case) classic equivalence classes
testing, and be more exhaustive as all values in the equivalence class are considered in
the verification.

Reach out to us through https://trust-in-soft.com/contact/ if you would like to know more about our product.

*Copyright (C) 2023 TrustInSoft*
