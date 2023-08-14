<!--
trustinsoft/demos
Copyright (C) 2022-2023 TrustInSoft
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

**Work in progress - hold your breath**
<!--
# Demo of TrustInSoft Analyzer vs Fuzzing

This demo is composed of 2 use cases
- A first one where we show TrustInSoft Analyzer and AFL fuzzer integration (using tis-fuzz).
  This use case shows that TrustInSoft analyzer can detect problems that are
  missed by the AFL, simply because there is no immediate manifestation of a problem
  caused by the input
- A second one where we show how TISA Level 2 generalization can go beyond what a fuzzer
  cannot do by verifying the proper behavior of a piece of code with astronomical number
  of inputs (fuzzers can handle maximum hundreds of millions of inputs while TISA generalization can handle trillions of trillions of inputs)

## First scenario - TISA and AFL integration
This demo demonstrates how TISA and AFL can be seamlessly integrated together.
- A particular piece of code that makes use of 2 inputs is executed by the AFL fuzzer
  (testing massive combinations of the 2 inputs) to select a limited number of 
  "interesting" inputs. These inputs are supposedly interesting because they exercice
  different branches of the code/eecute differents statements
- Those inputs are then used by the TrustInSoft Analyzer in L1 interpreter mode
- We'll see that AFL selects inputs that can cause software misbehavior but does not
  detect those misbehaviors. When the same selected inputs are used for TrustInSoft
  analysis (automatic integration with tis-fuzz), the problems are deterministically detected

## Second scenario - TISA generalization going beyond AFL capabilities
This demos shows that, despite being quite useful tools, fuzzers can only tests
in the order of (possibly hundreds of) millions of inputs but fall flat when the
code needs to be validated for absence of problems with billions or trillions of
inputs. This is what TrustInSoft Level 2 generalization can achieve.

The 2nd example is a function that takes 2 integers as inputs. Each integer
has to be in the range [0..10000]. For the 2 integers this represents 10000*10000
i.e. 100'000'000 combinations.
Only a few particular pairs of values can cause the program to crash (because of a
division by zero).

Already with a rather small input space of 100M inputs (which is much less than typical
real code), a fuzzer will have to run for a long time and will struggle to find the values that will cause the crash.

... Show graphs

Let's now switch to TrustInSoft Level 2 analysis.
We will simply write a generalized test driver that will cover all 100M inputs (and much more, let's take the full [-2B..+2B] range for both integers which represent 4B*4B = 16*10^18 inputs.

Despite that we have greatly enlarged the input space, the generalized analysis is very fast (runs in a few seconds) and deterministically finds the values that can cause the
division by zero.

In conclusion, TrustInSoft L2 generalized analysis:
- Can go way beyond the number of inputs that can be tested with a fuzzer
- Does detect problems that remain unnoticed by a fuzzer execution
- Deterministically finds the inputs that can cause a bug or a vulnerability

Additionally, what is not visible in this demo is that the TISA analyzer, despite running on a regular IT host, can emulate any specific hardware target, where embedded code is usually ran in production.
This is another advantage of TISA vs fuzzers that most of the time an only run on host and therefore will not find problem that are specific to the target hardware environment.


Note: If you have an Ubuntu machine you can run this demo live by running:
```bash
git clone https://github.com/TrustInSoft/trustinsoft/demos
cd fuzzing
./demo.sh
``` 

Reach out to us through https://trust-in-soft.com/contact/ if you would like to know more about our product.

*Copyright (C) 2022-2023 TrustInSoft*

-->