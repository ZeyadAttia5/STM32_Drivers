#ifndef GPIO_PRV_H
#define GPIO_PRV_H

/*
Base Addresses:
GPIOA:  0x4002 0000
GPIOB:  0x4002 0400
GPIOC:  0x4002 0800
*/

/* Registers' Addresses */

// Base Address: 0x00
#define GPIOA_MODER *((volatile u8 *)0x4002 0000)
#define GPIOB_MODER *((volatile u8 *)0x4002 0400)
#define GPIOC_MODER *((volatile u8 *)0x4002 0800)

// Base Address: 0x04
#define GPIOA_OTYPER *((volatile u8 *)0x4002 0004)
#define GPIOB_OTYPER *((volatile u8 *)0x4002 0404)
#define GPIOC_OTYPER *((volatile u8 *)0x4002 0804)

// Base Address: 0x08
#define GPIOA_OSPEEDR *((volatile u8 *)0x4002 0008)
#define GPIOB_OSPEEDR *((volatile u8 *)0x4002 0408)
#define GPIOC_OSPEEDR *((volatile u8 *)0x4002 0808)

// Base Address: 0x10
#define GPIOA_IDR *((volatile u8 *)0x4002 0010)
#define GPIOB_IDR *((volatile u8 *)0x4002 0410)
#define GPIOC_IDR *((volatile u8 *)0x4002 0810)

// Base Address: 0x14
#define GPIOA_ODR *((volatile u8 *)0x4002 0014)
#define GPIOB_ODR *((volatile u8 *)0x4002 0414)
#define GPIOC_ODR *((volatile u8 *)0x4002 0814)

// Base Address: 0x18
#define GPIOA_BSSR *((volatile u8 *)0x4002 0018)
#define GPIOB_BSSR *((volatile u8 *)0x4002 0418)
#define GPIOC_BSSR *((volatile u8 *)0x4002 0818)

#endif