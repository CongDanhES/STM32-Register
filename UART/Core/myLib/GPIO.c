#include "GPIO.h"

void GPIO_UART1_SETUP(){
    GPIOA_CLOCK_ENABLE();

    // PA9- TX
    GPIOA->MODER    |= (0x2<<18);
    GPIOA->OTYPER   &= ~(1<<9);
    GPIOA->OSPEEDR  |= (0x2<<18);
    GPIOA->PUPDR    |= (0x1<<18);

    // PA10- RX
    GPIOA->MODER    |= (0x2<<20);
    GPIOA->OTYPER   &= ~(1<<10);
    GPIOA->OSPEEDR  |= (0x2<<20);
    GPIOA->PUPDR    |= (0x1<<20);

    //
    GPIOA->AFRH     |= (0x7<<4);
    GPIOA->AFRH     |= (0x7<<8);
}

void GPIO_UART2_SETUP(){
	GPIOA_CLOCK_ENABLE();
	// PA2-TX
	GPIOA->MODER 	|= (0x2<<4);
	GPIOA->OTYPER	&= ~(1<<2);
	GPIOA->OSPEEDR	|= (0x2<<4);
	GPIOA->PUPDR	|= (0x1<<4);

	// PA3- RX
	GPIOA->MODER 	|= (0x2<<6);
	GPIOA->OTYPER	&= ~(1<<3);
	GPIOA->OSPEEDR	|= (0x2<<6);
	GPIOA->PUPDR	|= (0x1<<6);

	//
	GPIOA->AFRL		|= (0x7<<8);
	GPIOA->AFRL		|= (0X7<<2);
}
