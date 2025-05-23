#ifndef GPIO_HPP
#define GPIO_HPP

#include <stdint.h>
#include "RCC.h"

typedef struct{
    volatile uint32_t MODER;   // GPIO port mode register
    volatile uint32_t OTYPER;  // GPIO port output type register
    volatile uint32_t OSPEEDR; // GPIO port output speed register
    volatile uint32_t PUPDR;   // GPIO port pull-up/pull-down register
    volatile uint32_t IDR;     // GPIO port input data register
    volatile uint32_t ODR;     // GPIO port output data register
    volatile uint32_t BSRR;    // GPIO port bit set/reset register
    volatile uint32_t LCKR;    // GPIO port configuration lock register
    volatile uint32_t AFRL;  // GPIO alternate function low register
    volatile uint32_t AFRH;  // GPIO alternate function low register
}myGPIO;

#define GPIOA_BASE          0x40020000
#define GPIOA               ((myGPIO*) GPIOA_BASE)

void GPIO_UART1_SETUP();
void GPIO_UART2_SETUP();

#endif // GPIO_HPP
