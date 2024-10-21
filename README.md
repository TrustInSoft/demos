# trustinsoft/demos

A collection of code snippets showing TrustInSoft Analyzer capabilities


## [General demo of TrustInSoft Analyzer: A buffer overflow and an integer overflow, not found by tests, but found by the analyzer](new-demo/README.md)

In this demo you'll see that undefined behaviors are subtle bugs that are often not detected by functional tests, and, to the contrary that the TrustInSoft Analyzer finds all Undefined Behaviors deterministically.

## [Target awareness](target-awareness/README.md)

In this demo you'll see that analyzing code with awareness of the embedded target on which teh code will ultimately run, because some low-level code statements are target sensitive.
A code that is analyzed or unit tested on a standard x86-64 host may run smoothly, and not reveal the problems that would occur on target.


## [tis_address](tis-address/README.md)

In this demo you'll see how you can **avoid False Positives and False Negatives on low-level code with TrustInSoft unique tis_address feature**

## [AUTOSAR Classic integration](autosar/README.md)

This demo shows how you can fully automatically analyze AUTOSAR Classic applications
with the TrustInSoft `tis-autosar-mockup` integration tool.

## [Limitations of boundary testing](boundary-testing/README.md)

With this example you'll see that boundary testing, although a good practice, is often insufficient to detect corner cases that can have runtime impacts on your code (in the current case an hidden division by zero problem), and how the TrustInSoft Analyzer input generalization feature can deterministicly detect all such problems.

## [Undefined Behavior having side-effects that vary with minor context changes](subtle-ub/README.md)

With this example you'll see that Undefined Behaviors are subtle problems that may or may not have immediate visible effects, and whose effect easily change by changing very minor context elements (like changing compiler, changing the code by very little etc...)

Because of that Undefined Behaviors are often not detected by functional tests or can have very different impacts between functional tests and on-target production execution.
It will then show how the TrustInSoft Analyzer Zero false negatives guarantees to deterministicly detect Undefined Behaviors, irrespective of the environment/context.

# Coming soon

*[Fuzz testing integration with TrustInSoft Analyzer](fuzzing/README.md)*
