#line 1 "C:\\Users\\NCPC\\Desktop\\Danh\\STM32-BareMetal\\STM32-Register\\CAN\\src\\RCC\\RCC.h"
#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "stdint.h"

typedef struct{
    volatile uint32_t CR;           // RCC clock control register                                   0x00
    volatile uint32_t PLLCFGR;      // RCC PLL configuration register                               0x04
    volatile uint32_t CFGR;         // RCC clock configuration register                             0x08
    volatile uint32_t CIR;          // RCC clock interrupt register                                 0x0C
    volatile uint32_t AHB1RSTR;     // RCC AHB1 peripheral reset register                           0x10
    volatile uint32_t AHB2RSTR;     // RCC AHB2 peripheral reset register                           0x14
    volatile uint32_t AHB3RSTR;     // RCC AHB3 peripheral reset register                           0x18
    volatile uint32_t RESERVED0;    // Reserved0                                                    0x1C
    volatile uint32_t APB1RSTR;     // RCC APB1 peripheral reset register                           0x20
    volatile uint32_t APB2RSTR;     // RCC APB2 peripheral reset register                           0x24
    volatile uint32_t RESERVED1[2]; // Reserved1                                                    0x28 - 0x2C
    volatile uint32_t AHB1ENR;      // RCC AHB1 peripheral clock enable register                    0x30
    volatile uint32_t AHB2ENR;      // RCC AHB2 peripheral clock enable register                    0x34
    volatile uint32_t AHB3ENR;      // RCC AHB3 peripheral clock enable register                    0x38
    volatile uint32_t RESERVED2;    // Reserved2                                                    0x3C
    volatile uint32_t APB1ENR;      // RCC APB1 peripheral clock enable register                    0x40
    volatile uint32_t APB2ENR;      // RCC APB2 peripheral clock enable register                    0x44
    volatile uint32_t RESERVED3[2]; // Reserved3                                                    0x48 - 0x4C
    volatile uint32_t AHB1LPENR;    // RCC AHB1 peripheral clock enable in low power mode register  0x50
    volatile uint32_t AHB2LPENR;    // RCC AHB2 peripheral clock enable in low power mode register  0x54
    volatile uint32_t AHB3LPENR;    // RCC AHB3 peripheral clock enable in low power mode register  0x58
    volatile uint32_t RESERVED4;    // Reserved4                                                    0x5C
    volatile uint32_t APB1LPENR;    // RCC APB1 peripheral clock enable in low power mode register  0x60
    volatile uint32_t APB2LPENR;    // RCC APB2 peripheral clock enable in low power mode register  0x64
    volatile uint32_t RESERVED5[2]; // Reserved5                                                    0x68 - 0x6C
    volatile uint32_t BDCR;         // RCC Backup domain control register                           0x70
} myRCC;

#define myRCC_BASEADDRESS       0x40023800
#define myRCC                   ((myRCC*) myRCC_BASEADDRESS)

#define GPIOA_CLOCK_ENABLE()    myRCC->AHB1ENR |= (1 << 0)
#define GPIOB_CLOCK_ENABLE()    myRCC->AHB1ENR |= (1 << 1)

#define CAN1_CLOCK_ENABLE()     myRCC->APB1ENR |= (1 << 25)
#define CAN2_CLOCK_ENABLE()      myRCC->APB1ENR |= (1 << 26)
#endif // CLOCK_HPP
