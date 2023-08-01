/*
 *  	Name: Shuaib Abdulsalam Ahmed Aklan Saleh
 *      Sec: 1
 *      B.N.: 48
 */

#include "Bit_Operations.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"
#include "EXTI.h"

uint8 counter = 0;

int main() {
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_GPIOC);
	Rcc_Enable(RCC_SYSCFG);

	Exti_Init(GPIO_B,0, En_Fall_Dis_Rise);
	Exti_Enable(0);

	Exti_Init(GPIO_C,1, En_Fall_Dis_Rise);
	Exti_Enable(1);

	uint32 i;
    for (i = 0; i < 7; i++) {
		  GPIO_ConfigPin(GPIO_A, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
	  }




	while (1) {
		SevenSegDisplay();
		for (i = 0; i < 1000000; i++) {

			  }
	}

	return 0;
}

void EXTI0_IRQHandler(void) {

	if (counter >= 9){counter = 9;}
	else{counter++;}
	//clear pending flag
	SET_BIT(EXTI_Base_Address->PR, 0);
}

void EXTI1_IRQHandler(void) {

	if (counter <= 0){counter=0;}
	else{counter--;}
	//clear pending flag
	SET_BIT(EXTI_Base_Address->PR, 1);
}


void SevenSegDisplay(void){

  switch (counter)
	{
	case 0:
		GPIO_WritePin(GPIO_A, 0, HIGH);
		GPIO_WritePin(GPIO_A, 1, HIGH);
		GPIO_WritePin(GPIO_A, 2, HIGH);
		GPIO_WritePin(GPIO_A, 3, HIGH);
		GPIO_WritePin(GPIO_A, 4, HIGH);
		GPIO_WritePin(GPIO_A, 5, HIGH);
		GPIO_WritePin(GPIO_A, 6, LOW);
		break;

	case 1:
		GPIO_WritePin(GPIO_A, 0, LOW);
		GPIO_WritePin(GPIO_A, 1, HIGH);
		GPIO_WritePin(GPIO_A, 2, HIGH);
		GPIO_WritePin(GPIO_A, 3, LOW);
		GPIO_WritePin(GPIO_A, 4, LOW);
		GPIO_WritePin(GPIO_A, 5, LOW);
		GPIO_WritePin(GPIO_A, 6, LOW);
		break;


	case 2:
		GPIO_WritePin(GPIO_A, 0, HIGH);
		GPIO_WritePin(GPIO_A, 1, HIGH);
		GPIO_WritePin(GPIO_A, 2, LOW);
		GPIO_WritePin(GPIO_A, 3, HIGH);
		GPIO_WritePin(GPIO_A, 4, HIGH);
		GPIO_WritePin(GPIO_A, 5, LOW);
		GPIO_WritePin(GPIO_A, 6, HIGH);
		break;



	 case 3:
		GPIO_WritePin(GPIO_A, 0, HIGH);
		GPIO_WritePin(GPIO_A, 1, HIGH);
		GPIO_WritePin(GPIO_A, 2, HIGH);
		GPIO_WritePin(GPIO_A, 3, HIGH);
		GPIO_WritePin(GPIO_A, 4, LOW);
		GPIO_WritePin(GPIO_A, 5, LOW);
		GPIO_WritePin(GPIO_A, 6, HIGH);
		break;


	 case 4:
		GPIO_WritePin(GPIO_A, 0, LOW);
		GPIO_WritePin(GPIO_A, 1, HIGH);
		GPIO_WritePin(GPIO_A, 2, HIGH);
		GPIO_WritePin(GPIO_A, 3, LOW);
		GPIO_WritePin(GPIO_A, 4, LOW);
		GPIO_WritePin(GPIO_A, 5, HIGH);
		GPIO_WritePin(GPIO_A, 6, HIGH);
		break;


	 case 5:
		GPIO_WritePin(GPIO_A, 0, HIGH);
		GPIO_WritePin(GPIO_A, 1, LOW);
		GPIO_WritePin(GPIO_A, 2, HIGH);
		GPIO_WritePin(GPIO_A, 3, HIGH);
		GPIO_WritePin(GPIO_A, 4, LOW);
		GPIO_WritePin(GPIO_A, 5, HIGH);
		GPIO_WritePin(GPIO_A, 6, HIGH);
		break;



	 case 6:
		GPIO_WritePin(GPIO_A, 0, HIGH);
		GPIO_WritePin(GPIO_A, 1, LOW);
		GPIO_WritePin(GPIO_A, 2, HIGH);
		GPIO_WritePin(GPIO_A, 3, HIGH);
		GPIO_WritePin(GPIO_A, 4, HIGH);
		GPIO_WritePin(GPIO_A, 5, HIGH);
		GPIO_WritePin(GPIO_A, 6, HIGH);
		break;


	 case 7:
		GPIO_WritePin(GPIO_A, 0, HIGH);
		GPIO_WritePin(GPIO_A, 1, HIGH);
		GPIO_WritePin(GPIO_A, 2, HIGH);
		GPIO_WritePin(GPIO_A, 3, LOW);
		GPIO_WritePin(GPIO_A, 4, LOW);
		GPIO_WritePin(GPIO_A, 5, LOW);
		GPIO_WritePin(GPIO_A, 6, LOW);
		break;


	 case 8:
		GPIO_WritePin(GPIO_A, 0, HIGH);
		GPIO_WritePin(GPIO_A, 1, HIGH);
		GPIO_WritePin(GPIO_A, 2, HIGH);
		GPIO_WritePin(GPIO_A, 3, HIGH);
		GPIO_WritePin(GPIO_A, 4, HIGH);
		GPIO_WritePin(GPIO_A, 5, HIGH);
		GPIO_WritePin(GPIO_A, 6, HIGH);
		break;


	 case 9:
		GPIO_WritePin(GPIO_A, 0, HIGH);
		GPIO_WritePin(GPIO_A, 1, HIGH);
		GPIO_WritePin(GPIO_A, 2, HIGH);
		GPIO_WritePin(GPIO_A, 3, HIGH);
		GPIO_WritePin(GPIO_A, 4, LOW);
		GPIO_WritePin(GPIO_A, 5, HIGH);
		GPIO_WritePin(GPIO_A, 6, HIGH);
		break;

	default:
		break;
	}
}
