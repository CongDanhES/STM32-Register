/*
 * RCC.h
 *
 *  Created on: Apr 24, 2025
 *      Author: NCPC
 */

#ifndef MYLIB_RCC_H_
#define MYLIB_RCC_H_

#include "stdint.h"

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t RESERVED0[2];
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t RESERVED2[2];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t RESERVED3[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t RESERVED4[2];
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    volatile uint32_t RESERVED5[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t RESERVED6[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t DCKCFGR;
} myRCC;

#define myRCC_BASE		0x40023800
#define RCC				((myRCC *) myRCC_BASE)

#define TIM1_ENABLE()	RCC->APB2ENR |= 0x1
#define TIM2_ENABLE()	RCC->APB1ENR |= 0x1

#define GPIOA_ENABLE()	RCC->AHB1ENR |= 0x1



#endif /* MYLIB_RCC_H_ */
