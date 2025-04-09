#include "UART.h"
#include "string.h"

uint8_t rx[8] = {0};

int main(){
    USART1_Init();
    USART2_Init();

    const uint8_t data1[] = "ABCDE\r";
    const uint8_t data2[] = "ABCDEFGHJK\r";

    USART2_Transmit(data1, strlen((char*)data1));
    USART2_Transmit(data2, strlen((char*)data2));

    while(1){
        USART2_Receive(rx, 8);
    }
}
