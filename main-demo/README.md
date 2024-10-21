<!--
trustinsoft/demos
Copyright (C) 2022-2024 TrustInSoft
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

# Main Demo - buffer overflow/array out of bounds detection with input coverage, TPM, and tis trends reporting

This demo demonstrates:
- How functional tests can typically miss undefined behaviors like buffer overflows or integer overflows if those undefined behaviors do not cause immediate problems (like a crash or other immediate corruption), and
- How TrustInSoft analysis detects them with mathematical guarantee.
- How easily it is to get started with TrustInSoft Project Manager (TPM)
- How to leverage tis trend for trends reporting as fixes in code are applied

## Preparation

The demo is staged in a state where no steps have been run and a ready to use tis trend report is not yet available. If you merely need to show some of the new features to a prospect who doesn't care to see the broader 3-step demo, I strongly advise to run the demo a few times with varying alarm count, running `tis stash` each time, to simulate what a real CI would do.

When using WSL to run the TrustInSoft Analyzer, it is advised to change the default web page file association to use `wslview`. This can be achieved with the following commands:
```shell
sudo apt install wslu
xdg-settings set default-web-browser /usr/share/wslu/wslview.desktop
```

## Code under test

The code to be tested is the [increment.c](increment.c#L26) source file.

Following a qualified V-model development process, some requirement has been elicitated to describe a function taking an array and a length, where all cells in the array should be incremented by 1.

This file has only one function `increment_array(int array[], int len)` that takes an array of integer (and its length) as input and fulfills the requirement.
The code of `increment_array()` is the following:
```c
void increment_array(int array[], int len)
{
    if (array == NULL || len <= 0)
        return;
    while (len >= 0)
    {
        int value = *array;
        (*array) = value + 1; // Increment the value of the array cell
        array++;              // Move to next array cell
        len--;                // Decrement loop counter
    }
}
```

## Functional tests

The test driver [test_driver.c](test_driver.c#L71) has several tests meant to test that function.
- Test with small array of a few static integers
- Test with a larger array (1000 cells) of random integers
- Test with an empty array (a GCC language extension)
- Test with a NULL array

When running the 4 functional tests, they all pass, and on top of that the code coverage is 100%. This can be verified by running `make clean test`
```shell
$ make clean test

gcc -I. -fprofile-arcs -ftest-coverage test_driver.c utils.c increment.c -o increment && ./increment

Running tests
PASSED: increment_array({1, 3, 5, 7, 11, 17}) = {2, 4, 6, 8, 12, 18}
PASSED: increment_array({846930886, 1714636915, 424238335, -1649760492, -1189641421, ..., -878777377, -531352976, 413892161, 1455252833}) = {846930887, 1714636916, 424238336, -1649760491, -1189641420, ..., -878777376, -531352975, 413892162, 1455252834}
PASSED: increment_array({}) = {}
PASSED: increment_array(NULL) = NULL

---> All tests PASSED

gcov increment.c
File 'increment.c'
Lines executed:100.00% of 7
Creating 'increment.c.gcov'
```

Despite the above passing tests (and the 100% code coverage) we'll see that there are undetected undefined behaviors (or UB below in this document), more specifically a **buffer overflow**... and also an **integer overflow**

## Demo Start

In order to better highlight the newest features of TPM, the demo moves away from reliance on the Makefile for all but the initial build step that would occur without the usage of TIS Analyzer (TiSA).

The project is configured using TiSA Project Manager (TPM), and demonstrates how commands like `tis list` work. Optionally you can see how the configuration maps to the test drivers in test_driver.c and how those correspond with the options now in `tis list`.

```shell
$ tis list
[001] '1.1.small-array'
[002] '1.2.large-array'
[003] '1.3.zero-length-array'
[004] '1.4.null-array'
[005] '2.generalized-array'

Hint: Available analyses listed. Run an analysis with
      tis run <analysis-number> or tis run "<analysis-name>". Run all
      analyses with tis run. More information about available filters with
      tis list --help.
```

Because of the flexibility in TPM, you can choose to run the tests individually or all in sequence. The simplest way to proceed is to run `tis run -f` which will invoke all tests in sequence. The `-f` option forces the tool to ignore the cached results.

```
$ tis run -f
Running analysis '1.1.small-array'... Degeneration error: stop at nth alarm
Running analysis '1.2.large-array'... Degeneration error: stop at nth alarm
Running analysis '1.3.zero-length-array'... Completed with no alarms
Running analysis '1.4.null-array'... Completed with no alarms
Running analysis '2.generalized-array'... 2 alarms found

All analyses have been run.

Hint: Analyses complete. View a summary of the results with
      tis show <analyses>. View a complete report with tis report --open.
      Investigate alarms with tis gui.

$
```

At this point, it is useful to generate and view the analysis report in order to better highlight for the demo audience the types of issues we've discovered. The report is not automatically prepared, however, so you must run `tis report` next.

> **Note:** `tis report --open` can also be used to generate the report and open it directly in your defaut browser in one command.

```
$ tis report
Using 5 (out of 5) analyses to build the report.

Report successfully generated from 5 analyses.
It can be accessed in your browser with the command:

  xdg-open trustinsoft/.tis-current/tis_report.html

$
```

With the report created, you can now open it to view:

```shell
xdg-open trustinsoft/.tis-current/tis_report.html
```

After reviewing the contents of the report that appears with the demo audience, return to the console. 

TrustInSoft's goal is not merely to detect the issues but to also aide in guiding developers to the appropriate fixes so that the code under examination can be refined until it is free of all Undefined Behaviors with the mathematical certainty TrustInSoft can uniquely provide. 

The first issue observed is a buffer overflow: the `increment_array` function correctly increments all expected cells in the array, but also corrupts memory one cell after the array. This is a typical example of impossible-to-test-for bug.
Go to the increment.c source file and make the first correction which is to change the `>=` check in the while statement on line 32 to `>` and save the change.

Before re-running the analysis, let's save the state as if the CI job was done ; the information will be useful later for trends. Also, re-running tis run without it will result in TPM reporting that all the tests have already been run and it will refuse to run them anew despite the fact that the code has in fact changed.

```
$ tis stash
```

There is no output on the console after you run `tis stash` but in the background it is moving the latest analysis contents from `trustinsoft/.tis-current/` into a new directory it creates within `trustinsoft/.tis-stash/`. After the call, `tis report` will fail, because no "current" data is available anymore. 

You can now run a new run:

```shell
$ tis run
Running analysis '1.1.small-array'... Completed with no alarms
Running analysis '1.2.large-array'... Completed with no alarms
Running analysis '1.3.zero-length-array'... Completed with no alarms
Running analysis '1.4.null-array'... Completed with no alarms
Running analysis '2.generalized-array'... 1 alarm found

All analyses have been run.

Hint: Analyses complete. View a summary of the results with
      tis show <analyses>. View a complete report with tis report --open.
      Investigate alarms with tis gui.

```

We have now solved everything that we were able to detect with discrete Level 1 test drivers but, as the demo audience can see, our generalized inputs test is still reporting one remaining issue. 

> **Recommended:** Run `tis inspect 2.generalized-array` next to launch the UI and further demonstrate the UI's ability to help identify and troubleshoot common issues like this.

Return to the `increment.c` code and make the final fix, which is to add the check for the possibility that an integer is passed to the function already at the `INT_MAX` for the architecture (in which case incrementing that causes the overflow we detected). 

Back at the CLI, don't forget to once again stash.

```shell
tis stash
```

This paves the way for a new analysis run against our now UB-free code.

```shell
$ tis run
Running analysis '1.1.small-array'... Completed with no alarms
Running analysis '1.2.large-array'... Completed with no alarms
Running analysis '1.3.zero-length-array'... Completed with no alarms
Running analysis '1.4.null-array'... Completed with no alarms
Running analysis '2.generalized-array'... Completed with no alarms

All analyses have been run.

Hint: Analyses complete. View a summary of the results with
      tis show <analyses>. View a complete report with tis report --open.
      Investigate alarms with tis gui.
```

We have now obtained the ultimate result which is a verifications of the absence of undefined behavior in `increment.c` for a generalized set of inputs. Run the report command once more and review the input coverage as well as the clean result with the demo audience.

```shell
$ tis report --open
```

As a summary, we took some code that had tests which were all passing and reflecting a 100% code coverage. Without modifying the tests or the code in any way, we were able to quickly invoke the analyzer and obtain a valuable result which found and fixed a bug. From there, we extended the tests that already existed with an input generalized version to obtain significantly more input coverage which we verified in the subsequent reports when observing the input coverage.

Finally, we fixed the last alarm that the new test uncovered and once again confirmed that through the GUI and/or the report.

Now that our project has concluded, we are able to retrieve one final report which is the tis trend report to highlight the projects changes over time and the code's evolution towards a UB free state. 

```shell
$ tis trend
Report successfully generated.
It can be accessed in your browser with the command:

  xdg-open trustinsoft/.tis-stash/tis_trend_report.html
```

Reviewing the tis trends report that appears is a great way to segue into a discussion about current quality KPIs, tools, and processes to encourage the discussion about integration of TrustInSoft into that flow.

## Conclusion

In this demo we have shown a relatively common situation where pretty well defined Functional Tests, all passing and producing 100% of code coverage, have missed Undefined behaviors.
- By replaying these Tests with the TrustInSoft analyzer we were able to detect a first Undefined Behavior (a **buffer overflow**)
- By further generalizing inputs, we were able to detect a second Undefined Behavior (an **integer overflow**)

Functional Tests are quite usual to verify the functional behavior of the code, but not really its robustness. In particular, correct funcitonal behavior does not ensure that there is no side data corruption or corner case leading to an unexpected situation.  
TrustInSoft analyzer is an excellent complement to also bring mathematical guarantee of robustness (absence of undefined behaviors)

Reach out to us through https://trust-in-soft.com/contact/ if you would like to know more about our product.

*Copyright (C) 2022-2024 TrustInSoft*
