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