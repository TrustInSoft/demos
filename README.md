# trustinsoft/demos

A collection of code snippets showing TrustInSoft Analyzer capabilities

## [Undefined Behavior having side-effects that vary with minor context changes](subtle-ub/README.md)

With this example you'll see that Undefined Behaviors are subtle problems that may or may not have immediate visible effects, and whose effect easily change by changing very minor context elements (like changing compiler, changing the code by very little etc...)

Because of that Undefined Behaviors are often not detected by Unit Tests or can have very different impacts between Unit Tests and on-target production execution.
It will then show how the TrustInSoft Analyzer Zero false negatives guarantees to deterministicly detect Undefined Behaviors, irrespective of the environment/context.

## [Limitations of boundary testing](boundary-testing/README.md)

With this example you'll see that boundary testing, although a good practice, is often insufficient to detect corner cases that can have runtime impacts on your code (in the current case an hidden division by zero problem), and how the TrustInSoft Analyzer input generalization feature can deterministicly detect all such problems.

# Coming soon

*[Fuzz testing integration with TrustInSoft Analyzer](fuzzing/README.md)*
