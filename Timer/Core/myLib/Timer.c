/*
 * Timer.c
 *
 *  Created on: Apr 24, 2025
 *      Author: NCPC
 */

#include "Timer.h"

void TIM1_PWM(){
	TIM1_ENABLE();
	GPIOA_ENABLE();

    // Timer base configuration
    TIM1->PSC = 84 - 1;        // Prescaler (1 MHz timer clock with 84 MHz APB2)
    TIM1->ARR = 20000 - 1;     // Auto-reload for 50 Hz (20ms)
    TIM1->CCR1 = 1500;         // Duty cycle (e.g., 1.5ms for servo middle)

    // PWM mode 1 on Channel 1, enable preload
    TIM1->CCMR1 |= (6 << 4);   // OC1M = 110 (PWM mode 1)
    TIM1->CCMR1 |= (1 << 3);   // OC1PE

    // Enable output for Channel 1
    TIM1->CCER |= (1 << 0);    // CC1E

    // Main output enable (MOE) in BDTR register (required for TIM1)
    TIM1->BDTR |= (1 << 15);   // MOE

    // Enable auto-reload preload
    TIM1->CR1 |= (1 << 7);     // ARPE

    // Generate update event to load registers
    TIM1->EGR |= (1 << 0);     // UG

    // Start timer
    TIM1->CR1 |= (1 << 0);     // CEN
}

void TIM2_INPUTCAPTURE() {
    // Enable TIM2 & GPIOA clock
	TIM2_ENABLE();

    TIM2_GPIO_SETUP(); // Config PA1 alternate function

    // Timer base configuration
    TIM2->PSC = 84 - 1;        // 1 MHz timer clock
    TIM2->ARR = 0xFFFFFFFF;    // Max ARR

    // Capture on channel 2 (TI2)
    TIM2->CCMR1 |= (1 << 8);   // CC2S = 01 (Input on TI2)
    TIM2->CCER  &= ~(1 << 5);  // CC2P = 0 (rising edge)

    // Enable capture from channel 2
    TIM2->CCER |= (1 << 4);    // CC2E

    // Enable capture interrupt (optional)
    TIM2->DIER |= (1 << 2);    // CC2IE

    // Start timer
    TIM2->CR1 |= (1 << 0);     // CEN
}

