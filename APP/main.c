#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"

#include "GPIO_Interface.h"

#include "STK_Interface.h"

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
	while (1) {
		//converging
		/*for (u8 i = PIN7, j = PIN0; i >= PIN4; i--, j++) {
		 GPIO_voidSetPinValue(IOA, i, OUTPUT_HIGH);
		 GPIO_voidSetPinValue(IOA, j, OUTPUT_HIGH);
		 STK_voidSetBusyWait(1000000);
		 GPIO_voidSetPinValue(IOA, i, OUTPUT_LOW);
		 GPIO_voidSetPinValue(IOA, j, OUTPUT_LOW);
		 STK_voidSetBusyWait(1000000);
		 }*/

//		Diverging
		/*for (u8 i = PIN4, j = PIN3; i <= PIN7 && j >= PIN0; i++, j--) {
		 GPIO_voidSetPinValue(IOA, i, OUTPUT_HIGH);
		 GPIO_voidSetPinValue(IOA, j, OUTPUT_HIGH);
		 STK_voidSetBusyWait(1000000);
		 GPIO_voidSetPinValue(IOA, i, OUTPUT_LOW);
		 GPIO_voidSetPinValue(IOA, j, OUTPUT_LOW);
		 STK_voidSetBusyWait(1000000);
		 }*/

//		Snake
		/*
		 for (u8 i = PIN0; i <= PIN7; i++) {
		 GPIO_voidSetPinValue(IOA, i, OUTPUT_HIGH);
		 STK_voidSetBusyWait(1000000);
		 }
		 for (u8 i = PIN7; i >= PIN0; i--) {
		 GPIO_voidSetPinValue(IOA, i, OUTPUT_LOW);
		 STK_voidSetBusyWait(1000000);
		 if(i==PIN0)
		 break;
		 }*/

//		Ping-Pong
		/*		for (u8 i = PIN7, j = PIN0; i >= PIN4; i--, j++) {
		 GPIO_voidSetPinValue(IOB, i, OUTPUT_HIGH);
		 GPIO_voidSetPinValue(IOB, i, OUTPUT_LOW);
		 GPIO_voidSetPinValue(IOB, j, OUTPUT_HIGH);
		 STK_voidSetBusyWait(1000000);
		 GPIO_voidSetPinValue(IOB, j, OUTPUT_LOW);
		 }*/

//		Traffic Light
		/*turn red light on*/
		GPIO_voidSetPinValue(IOA, redLED, OUTPUT_HIGH);

		/*count for 10 seconds*/
		SEG_voidCountUp(IOB, 10000, 10, 0);
		GPIO_voidSetPinValue(IOA, redLED, OUTPUT_LOW);
		GPIO_voidSetPinValue(IOA, yellowLED, OUTPUT_HIGH);

		SEG_voidCountUp(IOB, 5000, 6, 0);
		GPIO_voidSetPinValue(IOA, yellowLED, OUTPUT_LOW);
		GPIO_voidSetPinValue(IOA, greenLED, OUTPUT_HIGH);

		SEG_voidCountUp(IOB, 10000, 10, 0);
		GPIO_voidSetPinValue(IOA, greenLED, OUTPUT_LOW);

	}
}
