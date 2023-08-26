#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"

#include "GPIO_Interface.h"

#include "STK_Interface.h"
#include "EXTI_Interface.h"

#include "7segment_Interface.h"

#define redLED		0
#define	yellowLED	1
#define greenLED 	2

int main() {
	/*1- Init System Clock*/
	RCC_voidInitSysClk();
	/*2- Enable Clk for the periphral GPIOA & GPIOB*/
	RCC_voidEnablePerClk(AHB1, IOA);
	RCC_voidEnablePerClk(AHB1, IOB);
	/*3- pin is O/P, O/P PP, LS*/
	for (u8 i = PIN0; i <= PIN7; i++) {
		GPIO_voidSetPinMode(IOB, i, OUTPUT);
		GPIO_voidSetPinType(IOB, i, OUTPUT_PP);
		GPIO_voidSetPinSpeed(IOB, i, OUTPUT_LS);
	}
	for (u8 i = PIN0; i < PIN3; i++) {
		GPIO_voidSetPinMode(IOA, i, OUTPUT);
		GPIO_voidSetPinType(IOA, i, OUTPUT_PP);
		GPIO_voidSetPinSpeed(IOA, i, OUTPUT_LS);
	}
	EXTI_voidEXTILineEnable(EXTI0);
	while (1) {

	}
}
