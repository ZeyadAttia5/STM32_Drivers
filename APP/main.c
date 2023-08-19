#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/STK/STK_Interface.h"

#include "../MCAL/RCC/RCC_Config.h"
#include "../MCAL/GPIO/GPIO_Config.h"
#include "../MCAL/STK/STK_Config.h"

int main(){

    RCC_voidInitSysClk();
    RCC_voidEnablePerClk(AHB1, 0);

    GPIO_voidSetPinMode(IOA, 0, OUTPUT_HS);
    GPIO_voidSetPinType(IOA, 0, OUTPUT_PP);

    GPIO_voidSetPinValue(IOA, 0, OUTPUT_HIGH);

}