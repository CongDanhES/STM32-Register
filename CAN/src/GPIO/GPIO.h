#ifndef GPIO_HPP
#define GPIO_HPP

#include <stdint.h>
#include "src/RCC/RCC.h"

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

#define GPIOB_BASE          0x40020400
#define GPIOB_BASE          ((myGPIO*) GPIOB_BASE)

void CAN1_GPIO_INIT(void); // PA11- PA12
void CAN2_GPIO_INIT(void); // PB12- PB13

#endif // GPIO_HPP
