#include "Timer.h"
uint32_t captured_value;
int main(void){
	TIM1_PWM();
	TIM2_INPUTCAPTURE();

	while (1) {
		captured_value = TIM2->CCR2;
	}
}
