/*
 * Timer.h
 *
 *  Created on: Apr 24, 2025
 *      Author: NCPC
 */

#ifndef MYLIB_TIMER_H_
#define MYLIB_TIMER_H_

#include "stdint.h"
#include "RCC.h"
#include "GPIO.h"

typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RCR;   // only advance TIM1
    volatile uint32_t CCR1;
    volatile uint32_t CCR2;
    volatile uint32_t CCR3;
    volatile uint32_t CCR4;
    volatile uint32_t BDTR;  // only advance TIM1
    volatile uint32_t DCR;
    volatile uint32_t DMAR;
} my_advanceTimer;

typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t CCR1;
    volatile uint32_t CCR2;
    volatile uint32_t CCR3;
    volatile uint32_t CCR4;
    volatile uint32_t DCR;
    volatile uint32_t DMAR;
} my_generalTimer;

#define TIM1_BASEADD	0x40010000
#define TIM1			((my_advanceTimer *)TIM1_BASEADD)

#define TIM2_BASEADD	0x40000000
#define	TIM2			((my_generalTimer *)TIM2_BASEADD)

void TIM1_PWM();
void TIM2_INPUTCAPTURE();

#endif /* MYLIB_TIMER_H_ */
