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

#include "memory_map.h"

#define GPIOA   ((GPIO_TypeDef *) GPIOA_START)

void configure_gpio_as_input()
{
    // To configure GPIOA as input you must
    // set bits 2 and 3 or MODER to 0

    GPIO_TypeDef * p = GPIOA;
    // For non physical addresses you can't dereference a pointer on
    // a non previously allocated address. The below whould raise
    // an alarm (False Positive)
    p->MODER &= ~((1U<<2) | (1U<<3));  
}

uint32_t * get_gpioa_first_register()
{
    return &(GPIOA->MODER);
    // return &(GPIOA->ODR);
}

void get_registers(uint32_t registers[])
{
    uint32_t * p_register = get_gpioa_first_register();
    for (int i = 0; i < NUMBER_OF_REGISTERS; i++) {
        registers[i] = p_register[i];
    }
}