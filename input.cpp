#include<stm32f10x_adc.h>

#include "input.h"
#include "hardware.h"

const uint16_t butEq[] = { GPIO_Pin_4, GPIO_Pin_5, GPIO_Pin_6, GPIO_Pin_7, GPIO_Pin_8, GPIO_Pin_9 };

bool Input::getState(uint8_t button){
	return ((INPUT_PORT->IDR & butEq[button]) != (uint32_t)Bit_RESET) ? false : true;
}

short int Input::getXAxis(){
	int counter = 0;
	for (int i = 0; i < 8; i++){
		counter += getAdcValueForXAxis();
	}
	return counter >> 3;
}
short int Input::getYAxis(){
	int counter = 0;
	for (int i = 0; i < 8; i++){
		counter += getAdcValueForYAxis();
	}
	return counter >> 3;
}
