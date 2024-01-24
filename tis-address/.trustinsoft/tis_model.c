/*
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
*/

#include "../memory_map.h"

#include <tis_builtin.h>

#ifdef WITH_TIS_ADDRESS
// This lets the analyzer know that a GPIO_TypeDef structure is preallocated
// at physical address GPIOA_START (0x48000000)
GPIO_TypeDef gpioa_registers __attribute__((tis_address(GPIOA_START)));
#endif

void test_init()
{
    configure_gpio_in_input_mode();
}

void test_get_registers()
{
    uint32_t registers[NUMBER_OF_REGISTERS];
    get_registers(registers);
}