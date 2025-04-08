#include "RCC.h"
#include "GPIO.h"
#include "stdint.h"

typedef struct{
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t GTPR;
}myUSART;

#define     myUSART1_BASEADD     0x40011000
#define     USART1              ((myUSART *) myUSART1_BASEADD)


void USART1_Init();
void USART1_Transmit(uint8_t* data, uint32_t len);
void USART1_Receive();
