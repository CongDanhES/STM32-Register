/*
 * UART.c
 *
 *  Created on: Apr 1, 2025
 *      Author: ASUS
 */

#include "UART.h"

void USART1_Init(){
    USART1_CLOCK_ENABLE();
    GPIO_UART1_Setup();

    USART1->CR1 &= ~(1<<12);
    USART1->CR1 &= ~(1<<10);
    USART1->CR1 |= 1<<3;
    USART1->CR1 &= ~(1<<15);

    uint32_t usartdiv = 0;
    uint32_t mantissa = 0;
    uint32_t fraction = 0;

    usartdiv= (25*16000000)/(4*9600);
    mantissa= usartdiv/100;
    fraction= (usartdiv-mantissa*100);
    fraction= ((fraction*16 +50)/100) & 0x0F;

    USART1->BRR |= (fraction);
    USART1->BRR |= (mantissa<<4);

    USART1->CR1 |= (1<<13);
}

void USART1_Transmit(uint8_t* data, uint32_t len){
	uint32_t count= 0;
	for(count= 0; count< len; count++){
		while((USART1->SR&(1<<7))== 0);
		USART1->DR = (uint8_t)(*data & 0xFF);
		data++;
	}
	while((USART1->SR & (1<<6))==0);
}

void USART1_Receive(uint8_t* data, uint32_t len){
	uint32_t count= 0;
	for(count= 0; count< len; count++){
		while((USART1->SR & (1<<5))==0);
		*data =  (uint8_t)(USART1->DR &0xFF);
		data++;
	}
}
