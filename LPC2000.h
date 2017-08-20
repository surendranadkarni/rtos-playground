#ifndef LPC2000_h_
#define LPC2000_h_

#include "LPC214x.h"

/* 
	convert "official" Philips definitions to definitions
	used in FreeRTOS 
*/
#define T0_IR   T0IR
#define T0_PR   T0PR
#define T0_MR0  T0MR0
#define T0_MCR  T0MCR
#define T0_TCR  T0TCR 

#define UART0_IIR U0IIR
#define UART0_LSR U0LSR
#define UART0_THR U0THR
#define UART0_RBR U0RBR
#define UART0_LCR U0LCR
#define UART0_DLL U0DLL
#define UART0_DLM U0DLM
#define UART0_FCR U0FCR
#define UART0_IER U0IER

#define PCB_PINSEL0 PINSEL0

#define SCB_PLLCFG  PLLCFG
#define SCB_PLLCON  PLLCON
#define SCB_PLLFEED PLLFEED
#define SCB_PLLSTAT PLLSTAT
#define SCB_VPBDIV  VPBDIV

#define MAM_TIM MAMTIM
#define MAM_CR  MAMCR

#define GPIO0_IOPIN IOPIN0
#define GPIO_IOSET  IOSET0
#define GPIO_IOCLR  IOCLR0 

#endif
