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

#include <stdint.h>

typedef struct {
    volatile uint32_t MODER;     // Mode register
    volatile uint32_t OTYPER;    // Output type register
    volatile uint32_t OSPEEDR;   // Output speed register
    volatile uint32_t PUPDR;     // Pull-up/Pull-dow register
    volatile uint32_t IDR;       // Input data register
    volatile uint32_t ODR;       // Output data register
    volatile uint32_t BSRR;      // Bit set/reset register
    volatile uint32_t LCKR;      // Configuration lock register
    volatile uint32_t AFR[2];    // Alternate function registers
    volatile uint32_t BRR;       // Bit reset register
    volatile uint32_t ASCR;      // Analog switch control register
} GPIO_TypeDef;

#define GPIOA_START         0x48000000
#define GPIOA               ((GPIO_TypeDef *) GPIOA_START)
#define NUMBER_OF_REGISTERS 12

void configure_gpio_as_input();

void get_registers(uint32_t registers[]);

uint32_t * get_gpioa_first_register();
