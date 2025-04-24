/*
 * GPIO.h
 *
 *  Created on: Apr 24, 2025
 *      Author: NCPC
 */

#ifndef MYLIB_GPIO_H_
#define MYLIB_GPIO_H_

#include "stdint.h"

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

#define GPIOA_BASEADD	0x40020000
#define GPIOA			((myGPIO *) GPIOA_BASEADD)

void TIM1_GPIO_SETUP();
void TIM2_GPIO_SETUP();


#endif /* MYLIB_GPIO_H_ */
