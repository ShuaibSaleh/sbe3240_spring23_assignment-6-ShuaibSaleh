/*
 *  	Name: Shuaib Abdulsalam Ahmed Aklan Saleh
 *      Sec: 1
 *      B.N.: 48
 */

#include "Gpio.h"
#include "Gpio_Private.h"



uint32 GPIO_Addresses[4] = {GPIOA_BASE_ADDRESS, GPIOB_BASE_ADDRESS,GPIOC_BASE_ADDRESS,GPIOD_BASE_ADDRESS};

uint8 PortId(uint8 PortName){
	return PortName - GPIO_A;
}

void GPIO_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,uint8 DefaultState) {

	uint8 OutputState = DefaultState & 0x1;
	uint8 InputState = DefaultState >> 1;


	GpioType * gpioReg =  GPIO_Addresses[PortId(PortName)];

	gpioReg->GPIO_MODER &= ~(0x3 << (2 * PinNum));
	gpioReg->GPIO_MODER |= (PinMode << (2 * PinNum));

	gpioReg->GPIO_OTYPER  &= ~(0x01 << PinNum);
	gpioReg->GPIO_OTYPER |= (OutputState << PinNum);

	gpioReg->GPIO_PUPDR &= ~(0x3 << (2 * PinNum));
	gpioReg->GPIO_PUPDR |= (InputState << (2*PinNum));



}


void GPIO_WritePin( uint8 PortName, uint8 PinNum , uint8 Data){

	GpioType * gpioReg =  GPIO_Addresses[PortId(PortName)];
	gpioReg->GPIO_ODR &= ~(0x01 << PinNum);
	gpioReg->GPIO_ODR |= (Data << PinNum);

}



uint8 GPIO_ReadPin( uint8 PortName  , uint8 PinNum) {

	uint8 data = 0;
	GpioType * gpioReg =  GPIO_Addresses[PortId(PortName)];
	data = (gpioReg->GPIO_IDR & (1 << PinNum)) >> PinNum;

	return data;


}




