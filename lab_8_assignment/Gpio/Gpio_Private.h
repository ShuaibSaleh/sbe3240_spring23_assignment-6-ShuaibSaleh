/*
 *	  Name: Shuaib Abdulsalam Ahmed Aklan Saleh
 *      Sec: 1
 *      B.N.: 48
 */
#ifndef GPIO_PRIVATE_H
#define  GPIO_PRIVATE_H
#include "Utils.h"


// base addresses

#define GPIOA_BASE_ADDRESS   0x40020000
#define GPIOB_BASE_ADDRESS   0x40020400
#define GPIOC_BASE_ADDRESS   0x40020800
#define GPIOD_BASE_ADDRESS   0x40020800

//  registers structure

typedef struct {
	uint32 GPIO_MODER;
	uint32 GPIO_OTYPER;
	uint32 GPIO_OSPEEDR;
	uint32 GPIO_PUPDR;
	uint32 GPIO_IDR;
	uint32 GPIO_ODR;
	uint32 GPIO_BSRR;
	uint32 GPIO_LCKR;
	uint32 GPIO_AFRL;
	uint32 GPIO_AFRH;
} GpioType;



#endif
