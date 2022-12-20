# Demo about subtle Undefined Behaviors

## Overview

This directory demonstrate how subtle Undefined Behaviors (UB) can be and why they are most often not detected through unit tests

Spoiler: In the below `increment_array()` function, there is an Undefined Behavior (a buffer overflow), you may have already spotted it... But that's not the point of this example. The main point is to show that:
- Despite the Undefined Behavior/buffer overflow a unit test still passes
- Due to the UB/buffer overflow, the code behaves differently depending on context.

The tested function is `increment_array()` whose implementation is below
```c
void increment_array(int *p, int len)
{
    while (len >= 0)
    {
        (*p)++; // Increment the value at address p
        p++;    // Move to next array cell
        len--;  // Decrement counter
    }
}
```

We'll test the above with a driver like the below:
```c
int main()
{
    int data[] = {1, 3, 5, 7};
    char name[] = "Olivier";

    printf("\nRun test_increment_array()\n");
    LOG("&data = 0x%lx &name = 0x%lx\n", (unsigned long)data, (unsigned long)name);
    LOG("Before increment array = {%d, %d, %d, %d}, name = %s\n",
        data[0], data[1], data[2], data[3], name);
    increment_array(data, sizeof(data)/sizeof(int));
    LOG("After  increment array = {%d, %d, %d, %d}, name = %s\n",
        data[0], data[1], data[2], data[3], name);

    int ok = (data[0] == 2) && (data[1] == 4) && (data[2] == 6) && (data[3] == 8);
    printf("\nincrement_array({1, 3, 5 ,7}) = {%d, %d, %d, %d} %s\n\n",
        data[0], data[1], data[2], data[3], ok ? SUCCESS: FAILED);
    return (ok ? 0 : 1);
}
```
Note the presence of variable `name`, not involved in the test itself, but that will play a
role in the below discussion.

## Basic Unit Test

First finding: Despite the Undefined Behavior (Buffer Overflow) the test **pass**es: Indeed every array cell is incremented as expected.
  
This can be verified by running `make ut`
```bash
$ make ut
gcc -I. test_driver.c increment.c -o demo-ub && ./demo-ub

Run test_increment_array()

increment_array({1, 3, 5 ,7}) = {2, 4, 6, 8} --> PASSED
```

Note: We'll see that more in detail at the bottom of this document but an analysis with TrustInSoft would detect the problem and raise an alarm, because the above `increment_array()` function
increments one cell to far at the end of the array.


## Basic Unit Test with a bit more logging

For the moment let's try to see what is happening exactly, and for that we'll re-run the same test with a little bit more information logged, by running `make ut-debug`

```bash
$ make ut-debug
gcc -DDEBUG -I. test_driver.c increment.c -o demo-ub && ./demo-ub

Run test_increment_array()
&data = 0x7ffdab40b300 &name = 0x7ffdab40b310
Before increment array = {1, 3, 5, 7}, name = Olivier
After  increment array = {2, 4, 6, 8}, name = Plivier

increment_array({1, 3, 5 ,7}) = {2, 4, 6, 8} --> PASSED
```

In the context of this test the array `data` (and the string `name`) are allocated in the stack, and when compiled with `gcc 9.4.0`, `data` and `name` are contiguous in that stack (Address of `name` (0x7ffdab40b310) is exactly 16 bytes (0x10) after address of `data` (0x7ffdab40b300), i.e. just the size of a 4 integers array).
Because of the buffer overflow `increment_array()` function (over)writes in the `name` variable.
- Before calling `increment_array()`, `name` holds the value `Olivier`
- After  calling `increment_array()`, `name` holds the value `Plivier`

## Showing that Undefined Behaviors are subtle (but severe) problems

It's all about context! With an Undefined Behavior, the code behaves unpredictably, and differently
depending on context. We'll make 2 variations of the above test, that should change absolutely nothing, and look at test result

### Variation 1: Keep same code, change of compiler

Let's change the compiler, and use **clang** instead of **gcc**. For that run `make ut-clang`.

```bash
$ make ut-clang
clang -DDEBUG -I. test_driver.c increment.c -o demo-ub && ./demo-ub

Run test_increment_array()
&data = 0x7ffe8dff8750 &name = 0x7ffe8dff8748
Before increment array = {1, 3, 5, 7}, name = Olivier
After  increment array = {2, 4, 6, 8}, name = Olivier

increment_array({1, 3, 5 ,7}) = {2, 4, 6, 8} --> PASSED
```

With that compiler, you'll notice that variables `data` and `name` are implanted differently in memory (`data` address is below/before `name`, whereas with **gcc** it was above/after) and because of that `name` is not overwritten (but that's pure luck... or unpredictability... or anything but determinism, that is, the essence of an Undefined Behavior)

### Variation 2: Keep same compiler, change the code in an theoretically innocuous way

Let's make a change to the code, that's supposed to have absolutely no effect on the test outcome.
Let's set variable `name` to `TrustInSoft` instead of `Olivier`. Just like for the 1st **gcc** test above
you would expect that after calling `increment_array()`, `name` should be corrupted because of the
buffer overflow, and hold the value `UrustInSoft`.

Let's try by running: `make ut-long-name`

```bash
$ make ut-long-name
gcc -DDEBUG -DLONG_NAME -I. test_driver.c increment.c -o demo-ub && ./demo-ub

Run test_increment_array()
&data = 0x7fffaef20420 &name = 0x7fffaef2043c
Before increment array = {1, 3, 5, 7}, name = TrustInSoft
After  increment array = {2, 4, 6, 8}, name = TrustInSoft

increment_array({1, 3, 5 ,7}) = {2, 4, 6, 8} --> PASSED
```

Oddly, `name` is not corrupted (i.e. the UB is invisible).
Why? Because of the string size change, `gcc` decided differently on the variable implantation in memory: `name` is no longer 16 bytes after `data` (ie just after data) but 28 bytes after (Difference between 0x7fffaef2043c and 0x7fffaef20420)
So when you run the same test, `name` is not overwritten (There is still an Undefined Behavior, just that the memory region overwritten is less visible from the outside).


## Analyzing the above code with TrustInSoft

The nice thing is that, unlike shown above, the TrustInSoft analyzer is not dependent of the context. There is an Undefined Behavior and the analyzer would find it with 100% mathematical guarantee.
If you have access to the TrustInSoft Analyzer this can be verified by running `make tis` or `make tis-gui`

This is an evidence that TrustInSoft analyzer is a much more reliable way of testing code for robustness
than Unit Tests.

## Conclusion

Undefined Behaviors are sometimes obvious (they can cause runtime errors like division
by zero, and software crashes) but most of the time:
- They are quite subtle
- They are often hard to detect with traditional unit tests.
- They will materialize (cause a problem) only in certain conditions, and their
  potentially catastrophic effect may not materialize immediately (crash after some time, crash under particular circumstances, no crash but unpredictable code behavior etc...)

Because of the above, they are quite complex to spot and investigate
Even when all your test pass, even if there is no immediate effect of an undefined behavior (like a crash for instance), undefined behaviors are time bombs that only need time to cause damage (safety or security problems)

The TrustInSoft analyzer solves all the above challenges by:
- Exhaustively and deterministically detecting all Undefined Behaviors in the code
- Providing a powerful investigation GUI to understand the root cause of an Undefined
  Behavior and fix it quickly

Reach out to us through https://trust-in-soft.com/contact/ if you would like to know
more about our product.