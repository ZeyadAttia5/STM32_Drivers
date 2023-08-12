

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"
#include "GPIO_Config.h"

/*
    GPIO_voidSetPinMode
    i/p arguments: copy_u8portId: IOA, IOB, IOC
    i/p arguments: copy_u8PinId: 0-15
    i/p arguments: copy_u8Mode: Input, Output, AF, Analog
    o/p arguments: void
    Description: this API allows the user to set the mode of a specific pin
*/
void GPIO_voidSetPinMode(u8 copy_u8portId, u8 copy_u8PinId, u8 copy_u8Mode)
{
    /* i/p validation */
    if (copy_u8portId > IOC || copy_u8PinId > PIN15 || copy_u8Mode > ANALOG)
    {
        /* return error */
        return;
    }
    else
    {
        switch (copy_u8Mode)
        {
        case INPUT:
            switch (copy_u8portId)
            {
            case IOA:
                CLR_BIT(GPIOA.MODER, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.MODER, (copy_u8PinId * 2 + 1));
                break;
            case IOB:
                CLR_BIT(GPIOB.MODER, (copy_u8PinId * 2));
                CLR_BIT(GPIOB.MODER, (copy_u8PinId * 2 + 1));
                break;
            case IOC:
                CLR_BIT(GPIOC.MODER, (copy_u8PinId * 2));
                CLR_BIT(GPIOC.MODER, (copy_u8PinId * 2 + 1));
                break;
            default:
                break;
            }
            break;
        case OUTPUT:
            switch (copy_u8portId)
            {
            case IOA:
                CLR_BIT(GPIOA.MODER, (copy_u8PinId * 2));
                SET_BIT(GPIOA.MODER, (copy_u8PinId * 2 + 1));
                break;
            case IOB:
                CLR_BIT(GPIOB.MODER, (copy_u8PinId * 2));
                SET_BIT(GPIOB.MODER, (copy_u8PinId * 2 + 1));
                break;
            case IOC:
                CLR_BIT(GPIOC.MODER, (copy_u8PinId * 2));
                SET_BIT(GPIOC.MODER, (copy_u8PinId * 2 + 1));
                break;
            default:
                break;
            }
            break;

        case AF:
            switch (copy_u8portId)
            {
            case IOA:
                SET_BIT(GPIOA.MODER, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.MODER, (copy_u8PinId * 2 + 1));
                break;
            case IOB:
                SET_BIT(GPIOB.MODER, (copy_u8PinId * 2));
                CLR_BIT(GPIOB.MODER, (copy_u8PinId * 2 + 1));
                break;
            case IOC:
                SET_BIT(GPIOC.MODER, (copy_u8PinId * 2));
                CLR_BIT(GPIOC.MODER, (copy_u8PinId * 2 + 1));
                break;
            default:
                break;
            }
            break;
        case ANALOG:
            switch (copy_u8portId)
            {
            case IOA:
                SET_BIT(GPIOA.MODER, (copy_u8PinId * 2));
                SET_BIT(GPIOA.MODER, (copy_u8PinId * 2 + 1));
                break;
            case IOB:
                SET_BIT(GPIOB.MODER, (copy_u8PinId * 2));
                SET_BIT(GPIOB.MODER, (copy_u8PinId * 2 + 1));
                break;
            case IOC:
                SET_BIT(GPIOC.MODER, (copy_u8PinId * 2));
                SET_BIT(GPIOC.MODER, (copy_u8PinId * 2 + 1));
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

/*
    GPIO_voidSetPinMode
    i/p arguments: copy_u8portId: IOA, IOB, IOC
    i/p arguments: copy_u8PinId: 0-15
    i/p arguments: copy_u8Type: Output_Push/Pull, Output_OpenDrain
    o/p arguments: void
    Description: this API allows the user to set the type of a specific pin
*/
void GPIO_voidSetPinType(u8 copy_u8portId, u8 copy_u8PinId, u8 copy_u8Type)
{

    /* i/p validation */
    if (copy_u8portId > IOC || copy_u8PinId > PIN15 || copy_u8Type > OUTPUT_OD)
    {
        /* return error */
        return;
    }
    else
    {
        switch (copy_u8Type)
        {
        case OUTPUT_PP:
            switch (copy_u8portId)
            {
            case IOA:
                CLR_BIT(GPIOA.OTYPER, copy_u8PinId);
                break;
            case IOB:
                CLR_BIT(GPIOA.OTYPER, copy_u8PinId);
                break;
            case IOC:
                CLR_BIT(GPIOA.OTYPER, copy_u8PinId);
                break;
            default:
                break;
            }
            break;

        case OUTPUT_OD:
            switch (copy_u8portId)
            {
            case IOA:
                SET_BIT(GPIOA.OTYPER, copy_u8PinId);
                break;
            case IOB:
                SET_BIT(GPIOA.OTYPER, copy_u8PinId);
                break;
            case IOC:
                SET_BIT(GPIOA.OTYPER, copy_u8PinId);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

/*
    GPIO_voidSetPinMode
    i/p arguments: copy_u8portId: IOA, IOB, IOC
    i/p arguments: copy_u8PinId: 0-15
    i/p arguments: copy_u8Speed: Output_LS, Output_MS, Output_HS
    o/p arguments: void
    Description: this API allows the user to set the speed of a specific pin
*/
void GPIO_voidSetPinSpeed(u8 copy_u8portId, u8 copy_u8PinId, u8 copy_u8Speed)
{
    if (copy_u8portId > IOC || copy_u8PinId > PIN15 || copy_u8Speed > OUTPUT_OD)
    {
        // error
        return;
    }
    else
    {
        switch (copy_u8Speed)
        {
        case OUTPUT_LS:
            switch (copy_u8portId)
            {
            case IOA:
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2) + 1);
                break;
            case IOB:
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2) + 1);
                break;
            case IOC:
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2) + 1);
                break;
            default:
                break;
            }
            break;

        case OUTPUT_MS:
            switch (copy_u8portId)
            {
            case IOA:
                SET_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2) + 1);
                break;
            case IOB:
                SET_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2) + 1);
                break;
            case IOC:
                SET_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2) + 1);
                break;
            default:
                break;
            }
            break;
        case OUTPUT_HS:
            switch (copy_u8portId)
            {
            case IOA:
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2));
                SET_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2) + 1);
                break;
            case IOB:
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2));
                SET_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2) + 1);
                break;
            case IOC:
                CLR_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2));
                SET_BIT(GPIOA.OSPEEDR, (copy_u8PinId * 2) + 1);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

/*
    GPIO_voidSetPuPdConfig
    i/p arguments: copy_u8portId: IOA, IOB, IOC
    i/p arguments: copy_u8PinId: 0-15
    i/p arguments: copy_u8PuPd: INPUT_FLOATING, INPUT_PD, INPUT_PU
    o/p arguments: void
    Description: this API allows the user to set the mode of a specific pin
*/
void GPIO_voidSetPuPdConfig(u8 copy_u8portId, u8 copy_u8PinId, u8 copy_u8PuPd)
{
    if (copy_u8portId > IOC || copy_u8PinId > PIN15 || copy_u8PuPd > INPUT_PU)
    {
        // error
        return;
    }
    else
    {
        switch (copy_u8PuPd)
        {
        case INPUT_FLOATING:
            switch (copy_u8portId)
            {
            case IOA:
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2) + 1);
                break;
            case IOB:
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2) + 1);
                break;
            case IOC:
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2) + 1);
                break;
            default:
                break;
            }
            break;

        case INPUT_PD:
            switch (copy_u8portId)
            {
            case IOA:
                SET_BIT(GPIOA.PUPDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2) + 1);
                break;
            case IOB:
                SET_BIT(GPIOA.PUPDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2) + 1);
                break;
            case IOC:
                SET_BIT(GPIOA.PUPDR, (copy_u8PinId * 2));
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2) + 1);
                break;
            default:
                break;
            }
            break;
        case INPUT_PU:
            switch (copy_u8portId)
            {
            case IOA:
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2));
                SET_BIT(GPIOA.PUPDR, (copy_u8PinId * 2) + 1);
                break;
            case IOB:
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2));
                SET_BIT(GPIOA.PUPDR, (copy_u8PinId * 2) + 1);
                break;
            case IOC:
                CLR_BIT(GPIOA.PUPDR, (copy_u8PinId * 2));
                SET_BIT(GPIOA.PUPDR, (copy_u8PinId * 2) + 1);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

/*
    GPIO_voidSetPinMode
    i/p arguments: copy_u8portId: IOA, IOB, IOC
    i/p arguments: copy_u8PinId: 0-15
    i/p arguments: copy_u8SetReset: OUTPUT_SET, OUTPUT_RESET
    o/p arguments: void
    Description: this API allows the user to set the mode of a specific pin
*/
void GPIO_voidSetDirectAcces(u8 copy_u8portId, u8 copy_u8PinId, u8 copy_u8SetReset)
{
    if (copy_u8portId > IOC || copy_u8PinId > PIN15 || copy_u8SetReset > OUTPUT_RESET)
    {
        /* return error */
        return;
    }
    else
    {
        switch (copy_u8SetReset)
        {
        case OUTPUT_SET:
            switch (copy_u8portId)
            {
            case IOA:
                GPIOA.BSSR = (1 << copy_u8PinId);
                break;
            case IOB:
                GPIOB.BSSR = (1 << copy_u8PinId);
                break;
            case IOC:
                GPIOC.BSSR = (1 << copy_u8PinId);
                break;
            default:
                break;
            }
            break;

        case OUTPUT_RESET:
            switch (copy_u8portId)
            {
            case IOA:
                GPIOA.BSSR = (1 << (copy_u8PinId + 16));
                break;
            case IOB:
                GPIOB.BSSR = (1 << (copy_u8PinId + 16));
                break;
            case IOC:
                GPIOC.BSSR = (1 << (copy_u8PinId + 16));
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

/*
    GPIO_voidSetPinMode
    i/p arguments: copy_u8portId: IOA, IOB, IOC
    i/p arguments: copy_u8PinId: 0-15
    i/p arguments: copy_u8Value: OUTPUT_HIGH, OUTPUT_LOW
    o/p arguments: void
    Description: this API allows the user to set the value of a specific pin
*/
void GPIO_voidSetPinValue(u8 copy_u8portId, u8 copy_u8PinId, u8 copy_u8Value)
{
    if (copy_u8portId > IOC || copy_u8PinId > PIN15 || copy_u8Value > OUTPUT_OD)
    {
        /* return error */
        return;
    }
    else
    {
        switch (copy_u8Value)
        {
        case OUTPUT_PP:
            switch (copy_u8portId)
            {
            case IOA:
                CLR_BIT(GPIOA.ODR, copy_u8PinId);
                break;
            case IOB:
                CLR_BIT(GPIOA.ODR, copy_u8PinId);
                break;
            case IOC:
                CLR_BIT(GPIOA.ODR, copy_u8PinId);
                break;
            default:
                break;
            }
            break;

        case OUTPUT_OD:
            switch (copy_u8portId)
            {
            case IOA:
                SET_BIT(GPIOA.ODR, copy_u8PinId);
                break;
            case IOB:
                SET_BIT(GPIOA.ODR, copy_u8PinId);
                break;
            case IOC:
                SET_BIT(GPIOA.ODR, copy_u8PinId);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

/*
    GPIO_voidSetPortValue
    i/p arguments: copy_u8portId: IOA, IOB, IOC
    i/p arguments: copy_u32: 0-2^32
    o/p arguments: void
    Description: this API allows the user to set the value of a specific port
*/
void GPIO_voidSetPortValue(u8 copy_u8portId, u32 copy_u32Value)
{
    if (copy_u8portId > IOC)
    {
        /* return error */
        return;
    }
    else
    {

        switch (copy_u8portId)
        {
        case IOA:
            ASSIGN_REG(GPIOA.ODR, copy_u32Value);
            break;

        case IOB:
            ASSIGN_REG(GPIOB.ODR, copy_u32Value);
            break;
            break;
        case IOC:
            ASSIGN_REG(GPIOC.ODR, copy_u32Value);
            break;
        default:
            break;
        }
    }
}

/*
    GPIO_voidGetPinValue
    i/p arguments: copy_u8portId: IOA, IOB, IOC
    i/p arguments: copy_u8PinId: 0-15
    o/p arguments: u8
    Description: this API allows the user to get the value of a specific pin
*/
u8 GPIO_voidGetPinValue(u8 copy_u8portId, u8 copy_u8PinId)
{
    if (copy_u8portId > IOC || copy_u8PinId > PIN15)
    {
        /* return error */
        return;
    }
    else
    {
        u8 local_u8PinValue;
        switch (copy_u8portId)
        {
        case IOA:
            local_u8PinValue = GET_BIT(GPIOA.IDR, copy_u8PinId);
            break;

        case IOB:
            local_u8PinValue = GET_BIT(GPIOA.IDR, copy_u8PinId);
            break;
        case IOC:
            local_u8PinValue = GET_BIT(GPIOA.IDR, copy_u8PinId);
            break;
        default:
            break;
        }
        return local_u8PinValue;
    }
}
