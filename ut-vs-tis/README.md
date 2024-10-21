# Demo about subtle Undefined Behaviors

## Overview

This directory demonstrate how subtle Undefined Behaviors can be and why they are
most often not detected through functional tests

Spoiler: In the below tests function, there is an Undefined Behavior, you may have already spotted it...
...But that's not the point of this example. The main point is to show that due to the
Undefined Behavior, the code may behave differently depending on context.

The tested function is `increment_array()` whose implementation is below
```c
void increment_array(int *p, int len)
{
    do {
        (*p)++; // Increment the value in the array cell
        p++;    // Move to next array cell
    } while (len-- >= 0);
    return;
}
```

When testing the above with a driver like the below:
```c
int test_increment_array()
{
    int a[4] = {1, 3, 5, 7};
    char name[] = "Olivier";
    increment_array(a, ARRAY_SIZE);
    int ok = (a[0] == 2) && (a[1] == 4) && (a[2] == 6) && (a[3] == 8);
    printf("Hello %s, increment_array({1, 3, 5 ,7}) = {%d, %d, %d, %d}\n",
        name, a[0], a[1], a[2], a[3]);
    return ok;
}
```

- Unit Test will **pass**: Indeed every array cell is incremented as expected.
  
  This can be verified by running `make ut`
  ```
  $ make ut
  gcc -Wno-unused-value -I. test_driver.c increment.c -o sneaky && ./sneaky

  Test of test_increment_array()

  increment_array({1, 3, 5 ,7}) = {2, 4, 6, 8} --> PASSED
  ```

- TrustInSoft L1 (or L2) analysis will **fail**, because the above `increment_array()` function
  increments one cell to far at the end of the array.
  In the context of this test the array `a[]` (and the string `name`) are allocated in the stack, and when compiled with `gcc 9.4.0`, `a[]` and `name` are contiguous in the stack.
  The `increment_array()` function (over)writes in the `name` variable.
  This can be verified showing a little more memory information by running `make ut-debug`:
  - Before calling `increment_array()`, `name` holds the value `Olivier`
  - After  calling `increment_array()`, `name` holds the value `Plivier`

  ```
  $ make ut-debug
  gcc -Wno-unused-value -I. test_driver.c increment.c -o demo-ub && ./demo-ub

  Test of test_increment_array()

  increment_array({1, 3, 5 ,7}) = {2, 4, 6, 8} --> PASSED
  ```

## Now the fun part: Let's show why Undefined Behaviors are sneaky?

It's all about context! With an Undefined Behavior, the code behaves unpredictably, and differently
depending on context. Let's demonstrate that with 2 examples:
- Let's change the compiler, and use **clang** instead of **gcc**. For that run `make ut-clang`
  With that compiler, you'll notice that variables `a[]` and `name` are implanted differently in memory (`a[]` address is below/before `name`, whereas with **gcc** it was above/after) and because of that `name` is not overwritten (but that's pure luck... or unpredictability... or anything but determinism, that is, the essence of an Undefined Behavior)

  ```bash
  $ make ut-clang
  clang -Wno-unused-value -DDEBUG -I. test_driver.c increment.c -o sneaky.clang && ./sneaky.clang

  Test of test_increment_array()
  DEBUG: &a = 0x7ffeeef85ce0 &name = 0x7ffeeef85cd8
  DEBUG: Hello Olivier, I will be incrementing array = {1, 3, 5, 7}
  DEBUG: Hello Olivier, I have incremented array = {2, 4, 6, 8}

  increment_array({1, 3, 5 ,7}) = {2, 4, 6, 8} --> PASSED
  ```

- Let's use `gcc` again but change the value (and size) of variable `name` from
  `Olivier` to `TrustInSoft`. Because of the string size change, `gcc` decides differently
  on the variable implantation in memory, and when you run the same code, the `name`
  is not overwritten (There is still an Undefined Behavior, just that another memory region is overwritten which is less visible from the outside).
  This can be verified by running: `make ut-long-name`

  ```bash
  $ make ut-long-name
  gcc -Wno-unused-value -DDEBUG -DLONG_NAME -I. test_driver.c increment.c -o sneaky.longname && ./sneaky.longname

  Test of test_increment_array()
  DEBUG: &a = 0x7fffe09237c0 &name = 0x7fffe09237dc
  DEBUG: Hello TrustInSoft, I will be incrementing array = {1, 3, 5, 7}
  DEBUG: Hello TrustInSoft, I have incremented array = {2, 4, 6, 8}

  increment_array({1, 3, 5 ,7}) = {2, 4, 6, 8} --> PASSED
  ```

## Analyzing the above code with TrustInSoft
The nice thing is that, unlike shown above, the TrustInSoft analyzer is not dependent of the context. There is an Undefined Behavior and the analyzer would find it with 100% mathematical guarantee.
If you have access to the TrustInSoft Analyzer this can be verified by running `make tis` or `make tis-gui`

This is an evidence that TrustInSoft analyzer is a much more reliable way of testing code for robustness
than functional tests.



## Conclusion

Undefined Behaviors are sometimes obvious (they can cause runtime errors like division
by zero, and software crashes) but most of the time:
- They are quite sUndefined Behaviortle
- They will materialize (cause a problem) only in certain conditions, and their
  potentially catastrophic effect may not materialize immediately (crash after some time, crash under particular circumstances, no crash but unpredictable code behavior etc...)
- Because of the above, they are quite complex to spot and investigate

The TrustInSoft analyzer solves all the above challenges by:
- Exhaustively detecting all Undefined Behaviors in the code
- Providing a powerful investigation GUI to understand the root cause of an Undefined
  Behavior and fix it quickly
  
