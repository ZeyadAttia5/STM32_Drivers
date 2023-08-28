#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"

#include "GPIO_Interface.h"

#include "STK_Interface.h"

#include "NVIC_Interface.h"

#include "EXTI_Interface.h"
#include "7segment_Interface.h"

#define redLED		1
#define	yellowLED	2
#define greenLED 	3

void customEXTI0_Handler(void) {
	//		Traffic Light
	/*turn red light on*/

	GPIO_voidSetPinValue(IOA, redLED, OUTPUT_HIGH);

}

int main() {
	/*1- Init System Clock*/
	RCC_voidInitSysClk();
	/*2- Enable Clk for the periphral GPIOA & GPIOB*/
	RCC_voidEnablePerClk(AHB1, IOA);
	STK_voidInit();
	for (u8 i = PIN0; i < PIN3; i++) {
		if (i == EXTI0) {
			GPIO_voidSetPinMode(IOA, i, INPUT);
			GPIO_voidSetPinPuPdConfig(IOA, i, INPUT_PU);
			GPIO_voidSetPinSpeed(IOA, i, OUTPUT_LS);

		} else {
			GPIO_voidSetPinMode(IOA, i, OUTPUT);
			GPIO_voidSetPinType(IOA, i, OUTPUT_PP);
			GPIO_voidSetPinSpeed(IOA, i, OUTPUT_LS);
		}
	}
	NVIC_voidSetPriorityConfig(G0_SG16);
	NVIC_voidSetPerPriority(6, 0, 7);
	NVIC_u8EnablePerInt(6);
	EXTI_voidEXTILineEnable(EXTI0);
	EXTI_voidSetSenseControl(EXTI_SC_FallingEdge, EXTI0);
	while (1) {
		GPIO_voidSetPinValue(IOA, yellowLED, OUTPUT_HIGH);
		STK_voidSetBusyWait(100000);
		GPIO_voidSetPinValue(IOA, yellowLED, OUTPUT_LOW);
		STK_voidSetBusyWait(100000);
	}
//
//	EXTI_voidSetCallBack(customEXTI0_Handler, EXTI0);
//
//	STK_voidSetBusyWait(20000);
	return 0;
}

void EXTI0_IRQHandler() {
	EXTI_voidClrPendingFlag(EXTI0);
	static u8 counter = 1;
	GPIO_voidSetPinValue(IOA, redLED, OUTPUT_HIGH);
	STK_voidSetBusyWait(1000 * counter);
	GPIO_voidSetPinValue(IOA, redLED, OUTPUT_LOW);
	counter*=10;
}
