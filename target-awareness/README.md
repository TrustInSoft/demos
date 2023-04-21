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

# Demo of target awareness of TrustInSoft analyzer

This demo demonstrates:
- Why target awareness is important when doing static code analysis of low-level/embedded code.
- How TrustInSoft analyzer gracefully solves that challenge.

## Code under test

The sample code for the demo is in the [target.c](target.c#L26) source file.
2 functions are defined that require target awareness for precise analysis

```c
// Word size awareness
// double_that() is fine if long (64 bits) are larger than int (32 bits)
// double_that() can overflow on targets when long are same size as int (Bothg 32 bits for instance)
long double_that(int i)
{
    return (long)i * 2;
}

//-------------------------------------
// Endianness awareness
// This function would return a different byte (from the short) depending on enddianness
unsigned char msb(unsigned short n)
{
    return *(unsigned char *)&n;
}
unsigned char c = msb(0xBEEF); // c == 0xBE or c == 0xEF ?
```

## xxx

## Conclusion

Reach out to us through https://trust-in-soft.com/contact/ if you would like to know more about our product.

*Copyright (C) 2022-2023 TrustInSoft*
