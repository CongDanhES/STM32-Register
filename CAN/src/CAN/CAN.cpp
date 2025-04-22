#include "CAN.h"

void CAN1_SETUP(){
    // Init GPIO & enable Clock
    CAN1_GPIO_INIT();
    CAN1_CLOCK_ENABLE();

    // 
    CAN1->MCR |= 0x1;


}