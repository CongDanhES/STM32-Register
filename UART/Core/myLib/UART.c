/*
 * UART.c
 *
 *  Created on: Apr 1, 2025
 *      Author: ASUS
 */

#include "UART.h"

void USART1_Init(){
    USART1_CLOCK_ENABLE();
    GPIO_UART1_SETUP();

    USART1->CR1 &= ~(1<<12);
    USART1->CR1 &= ~(1<<10);
    USART1->CR1 |= (1<<3);
    USART1->CR1 |= (1<<2);
    USART1->CR1 &= ~(1<<15);

    USART1->BRR = (104 << 4) | 3;

    USART1->CR1 |= (1<<13);   // UE: USART enable
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

void USART2_Init(){
    USART2_CLOCK_ENABLE();
    GPIO_UART2_SETUP();

    USART2->CR1 &= ~(1<<12);
    USART2->CR1 &= ~(1<<10);
    USART2->CR1 |= (1<<3);
    USART2->CR1 |= (1<<2);
    USART2->CR1 &= ~(1<<15);

    USART2->BRR = (8 << 4) | 11;

    USART2->CR1 |= (1<<13);   // UE: USART enable
}

void USART2_Transmit(uint8_t* data, uint32_t len){
	uint32_t count= 0;
	for(count= 0; count< len; count++){
		while((USART2->SR&(1<<7))== 0);
		USART2->DR = (uint8_t)(*data & 0xFF);
		data++;
	}
	while((USART2->SR & (1<<6))==0);
}

void USART2_Receive(uint8_t* data, uint32_t len){
	uint32_t count= 0;
	for(count= 0; count< len; count++){
		while((USART2->SR & (1<<5))==0);
		*data =  (uint8_t)(USART1->DR &0xFF);
		data++;
	}
}
