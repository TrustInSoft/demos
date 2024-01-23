#include "../memory_map.h"

#include <tis_builtin.h>

#ifdef WITH_TIS_ADDRESS
// This lets the analyzer know that a GPIO_TypeDef structure is preallocated
// at physical address GPIOA_START (0x48000000)
GPIO_TypeDef gpioa_registers __attribute__((tis_address(GPIOA_START)));
#endif

void test_init()
{
    configure_gpio_as_input();
}

void test_get_registers()
{
    uint32_t registers[NUMBER_OF_REGISTERS];
    get_registers(registers);
}