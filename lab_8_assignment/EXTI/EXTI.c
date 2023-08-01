///*
// *  	Name: Shuaib Abdulsalam Ahmed Aklan Saleh
// *      Sec: 1
// *      B.N.: 48
// */
//
#include "EXTI.h"
#include "EXTI_Private.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Bit_Operations.h"

ExtiType * EXTI =  EXTI_Base_Address ;

void EXTIReg_Config(uint8 PortName,uint8 PinNum){
	SyscfgType * SYSCFG = SYSCFG_Base_Address;


	if (PinNum < 4){
		SYSCFG ->SYSCFG_EXTICR1 &= ~(0b1111 << 4*(PinNum%4));// enable exti register 1
		SYSCFG->SYSCFG_EXTICR1 |= ((PortName-GPIO_A)<<4*(PinNum%4));
		SET_BIT(NVIC_ISER0, PinNum+6);  // enable line on nvic

	}

	else if ( (PinNum >= 4 ) && (PinNum < 8) ){
		SYSCFG ->SYSCFG_EXTICR2 &= ~(0b1111 << 4*(PinNum%4));// enable exti register 2
		SYSCFG->SYSCFG_EXTICR2 |= ((PortName-GPIO_A)<<4*(PinNum%4));

		if(PinNum == 4){
		SET_BIT(NVIC_ISER0, PinNum+6);
		}else{
			SET_BIT(NVIC_ISER0, 23);
		}

		}

	else if ((PinNum >= 8 ) && (PinNum < 12)){
		SYSCFG ->SYSCFG_EXTICR3 &= ~(0b1111 << 4*(PinNum%4));// enable exti register 3
		SYSCFG->SYSCFG_EXTICR3 |= ((PortName-GPIO_A)<<4*(PinNum%4));



		if (PinNum == 8 || PinNum == 9){
			SET_BIT(NVIC_ISER0, 23);
		}else{
			SET_BIT(NVIC_ISER0, 40);
		}

	}
	else {
		SYSCFG ->SYSCFG_EXTICR4 &= ~(0b1111 << 4*(PinNum%4));// enable exti register 4
		SYSCFG->SYSCFG_EXTICR4 |= ((PortName-GPIO_A)<<4*(PinNum%4));


		SET_BIT(NVIC_ISER0, 40);

	}

}

void Exti_Init(uint8 PortName,uint8 PinNum,uint8 TriggerState ){

	GPIO_ConfigPin(PortName,PinNum, GPIO_INPUT, GPIO_PULL_UP);




	switch(TriggerState){


		case En_Fall_Dis_Rise:
			EXTIReg_Config(PortName,PinNum);
			SET_BIT(EXTI->FTSR, PinNum);  // enable falling edge detection
			CLEAR_BIT(EXTI->RTSR, PinNum);  // disable rise edge detection

			break;

		case En_Rise_Dis_Fall:
			EXTIReg_Config(PortName,PinNum);
			SET_BIT(EXTI->RTSR, PinNum);  // enable rise edge detection
			CLEAR_BIT(EXTI->FTSR, PinNum);  // disable falling edge detection

			break;

		case En_Rise_En_Fall:
			EXTIReg_Config(PortName,PinNum);
			SET_BIT(EXTI->FTSR, PinNum);  // enable falling edge detection
			SET_BIT(EXTI->RTSR, PinNum);  // enable rise edge detection

			break;

		case Dis_Rise_Dis_Fall:
			EXTIReg_Config(PortName,PinNum);
			CLEAR_BIT(EXTI->FTSR, PinNum);  // disable falling edge detection
			CLEAR_BIT(EXTI->RTSR, PinNum);  // disable rise edge detection

			break;

		default:
			break;
	}


}

void Exti_Enable(uint8 PinNum){

	SET_BIT(EXTI->IMR, PinNum);  // enable exti1
}
void Exti_Disable(uint8 PinNum){
	CLEAR_BIT(EXTI->IMR, PinNum);
}


