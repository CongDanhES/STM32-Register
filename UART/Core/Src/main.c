#include "UART.h"
int main(){
	USART1_Init();
	uint8_t data[]="ABCDE";
	uint8_t data1[]="ABCDEFGHJK";
	USART1_Transmit(data, 6);
	USART1_Transmit(data1, 11);
	USART1_Transmit(data, 6);
	USART1_Transmit(data1, 11);
	USART1_Transmit(data, 6);
	USART1_Transmit(data1, 11);
}
