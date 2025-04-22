#include "src/GPIO/GPIO.h"

void CAN1_GPIOA_INIT(){
    //PA11
    GPIOA->MODER    |= (0x3<<22);
    GPIOA->OTYPER   &= ~(0x1<<11);
    GPIOA->OSPEEDR  |= (0x3<<22);
    GPIOA->PUPDR    |= (0x1<<22);
    GPIOA->AFRH     |= (0x9<<12);

    //PA12
    GPIOA->MODER    |= (0x3<<24);
    GPIOA->OTYPER   &= ~(0x1<<12);
    GPIOA->OSPEEDR  |= (0x3<<24);
    GPIOA->PUPDR    |= (0x1<<24);
    GPIOA->AFRH     |= (0x9<<16);
}