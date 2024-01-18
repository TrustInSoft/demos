<!--
trustinsoft/demos
Copyright (C) 2024 TrustInSoft
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

# Demo of tis_address

This demo demonstrates:  
How to prove the safety of absolute address access by using `tis_address`.

There are 2 major usages of `tis_address`
- Hardware access with absolute address
- Custom memory manager

ref: https://man.trust-in-soft.com/man/tis-user-guide/physical-addresses.html

# Hardware access

With this given example in `source1.c`:

```c
#include <stdio.h>

#define PIN_0 0x2000000
#define PIN_0_LEN 10

int main()
{
    for(int i = 0; i < PIN_0_LEN; i++)
    {
        char c = *(char*)(PIN_0+i);
        printf("%c", c);
    }

    // Wrong example
    for(int i = 0; i <= PIN_0_LEN; i++)
    {
        char c = *(char*)(PIN_0+i);
        printf("%c", c);
    }
}
```

We wish to read the value from pin_0, and 9 following bytes after pin_0. In the Wrong example at line 15, the loop exceed it's length.

If we execute the command:  
`tis-analyzer -val -slevel 100 source1.c -gui`

You will receive an Invalid memory access warning, because tis-analyzer doesn't know if the absolute address PIN_0 is safe or not.

We can manually tell tis-analyzer, that the 10 bytes start from PIN_0 is safe, by adding `tis_address` attribute to a global variable(or array), and manually set it's address in memory.

`char STUB_PIN_0[PIN_0_LEN] __attribute__((tis_address(PIN_0)));`

Also, we can set it's initial value in a custom main function. In this example, we use tis_make_unknown to generalize it.

```c
extern int main();

int tis_main()
{
    tis_make_unknown(STUB_PIN_0, sizeof(STUB_PIN_0));
    main();
}
```

Note that all the stubs and attributes are located in the file `tis_model.c`, this is a good approach to keep the source code clean and untouched.

Now, run the command:  
`tis-analyzer -val -slevel 100 source1.c -gui tis_model.c -main tis_main`

tis-analyzer will find an potential UB at line 17, when `i == PIN_0_LEN`, it's an invalid memory access.

# Memory manager

Another common use of tis_address is custom memory manager. In this type of project, absolute address is also widely used.

With the example in file `source2.c`, we have a very simple example about a custom memory allocator.

```c
#define HEAP_BEGIN  0x8000000
#define HEAP_SIZE   0x1000

#ifdef SOLUTION_1
char tis_pool __attribute__((tis_address(HEAP_BEGIN))) = 0xff;
#endif

struct memblock {
	long long addr;
	int size;
    char isAllocd;
} mem[100];

void* my_alloc(int size)
{
    mem[0].addr = HEAP_BEGIN;
    mem[0].size = size;
    mem[0].isAllocd = 1;
    return (void*)(mem[0].addr);
}

int main()
{
    char * ptr = my_alloc(1);
    if(ptr != 0)
        *ptr = 'a';
}
```

You can use `tis_address` attribute to remove alarms of invalid memory access just like the example above:

`tis-analyzer -val source2.c -gui -DSOLUTION_1`

Or, you can also use `-absolute-valid-range` to indicate the valid range of absolute address:

`tis-analyzer -val source2.c -gui -absolute-valid-range 0x8000000-0x800000f`

This command means that direct access to memory address start from 0x8000000 to 0x800000f should be valid.

ref: https://man.trust-in-soft.com/man/tis-user-guide/physical-addresses.html#sec-ug-physical-addresses-configuring-valid-address-range

## Stub the custom alloc

Once you finished the verification of memory manager, you can ask analyzer to use builtin function `tis_alloc` instead of your custom allocator, and verify other parts of your code.

`tis-analyzer -val source2.c -gui -val-builtin my_alloc:tis_alloc`

ref: https://man.trust-in-soft.com/ref/builtins.html
