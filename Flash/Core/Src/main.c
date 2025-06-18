#include "main.h"
#include "Flash.h"
#define START_ADDRESS 0x0800C000
int main(void){
	Flash_SectorErase(START_ADDRESS);
	HAL_Delay(1000);
}
