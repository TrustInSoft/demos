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
#define NUMBER_OF_REGISTERS 12

void configure_gpio_as_input();

void get_registers(uint32_t registers[]);

uint32_t * get_gpioa_first_register();
uint32_t * get_gpioa_moder();
uint32_t * get_gpioa_odr();