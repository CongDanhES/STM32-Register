#include "GPIO.h"

void GPIO_UART1_Setup(){
    GPIOA_CLOCK_ENABLE();

    // PA9- TX
    GPIOA->MODER    |= (0x2<<18);
    GPIOA->OTYPER   &= ~(1<<9);
    GPIOA->OSPEEDR  |= (0x2<<18);
    GPIOA->PUPDR    |= (0X1<<18);

    // PA10- RX
    GPIOA->MODER    |= (0x2<<20);
    GPIOA->OTYPER   &= ~(1<<10);
    GPIOA->OSPEEDR  |= (0x2<<20);
    GPIOA->PUPDR    |= (0x1<<20);

    //
    GPIOA->AFRH     |= (0x7<<4);
    GPIOA->AFRH     |= (0x7<<8);
}
