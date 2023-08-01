/*
 *	  Name: Shuaib Abdulsalam Ahmed Aklan Saleh
 *      Sec: 1
 *      B.N.: 48
 */
#ifndef EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H
#include "Utils.h"

// base addresses
#define EXTI_Base_Address ((ExtiType *)0x40013C00)
#define SYSCFG_Base_Address ((SyscfgType *)0x40013800)
#define NVIC_ISER0 (*(uint32 *)0xE000E100)






typedef struct {
	uint32 SYSCFG_MEMRMP;
	uint32 SYSCFG_PMC;
	uint32 SYSCFG_EXTICR1;
	uint32 SYSCFG_EXTICR2;
	uint32 SYSCFG_EXTICR3;
	uint32 SYSCFG_EXTICR4;
	uint32 SYSCFG_CMPCR;
} SyscfgType;

typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;


#endif
