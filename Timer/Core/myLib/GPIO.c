/*
 * GPIO.c
 *
 *  Created on: Apr 24, 2025
 *      Author: NCPC
 */

#include "GPIO.h"

void TIM1_GPIO_SETUP(){
	//PA8
	GPIOA->MODER  	|= (0x2<<16);
	GPIOA->OTYPER 	&= ~(0x1<<8);
	GPIOA->OSPEEDR	|= (0x2<<16);
	GPIOA->PUPDR	&= (0x3<<16);
	GPIOA->AFRH		|= (0x1);
}

void TIM2_GPIO_SETUP(){
	//PA1
	GPIOA->MODER  	|= (0x2<<2);
	GPIOA->OTYPER 	&= ~(0x1<<1);
	GPIOA->OSPEEDR	|= (0x2<<2);
	GPIOA->PUPDR	&= (0x3<<2);
	GPIOA->AFRL		|= (0x1<<4);
}


