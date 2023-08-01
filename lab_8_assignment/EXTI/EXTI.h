///*
// *	  Name: Shuaib Abdulsalam Ahmed Aklan Saleh
// *      Sec: 1
// *      B.N.: 48
// */
#ifndef EXTI_H
#define  EXTI_H
#include "Utils.h"
#include "EXTI_Private.h"




/* Trigger state */
#define En_Fall_Dis_Rise 0
#define En_Rise_Dis_Fall 1
#define En_Rise_En_Fall 2
#define Dis_Rise_Dis_Fall 3




void EXTIReg_Config(uint8 PortName,uint8 PinNum);
void Exti_Init(uint8 PortName,uint8 PinNum, uint8 TriggerState);
void Exti_Enable(uint8 PinNum);
void Exti_Disable(uint8 PinNum);




#endif
