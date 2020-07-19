/*
 * File:   timer_config.h
 * Author: mo
 *
 * Created on 12 ?????, 2020, 09:47 ?
 */

#ifndef TIMER_CONFIG_H
#define	TIMER_CONFIG_H
/*INCLUDES**/
#include "std_types.h"
#include "registers.h"
#include "error.h"
#include "interrupts.h"
//void timer0_interrupt_ovfRoutine(void);
/************************************************************************/
/*			  Structures Definitions		                            */
/************************************************************************/

typedef struct Timer_cfg_s
{
	uint8_t Timer_CH_NO;/*TIMER_CH0 0 or TIMER_CH1 1 or TIMER_CH2 2*/
	uint8_t Timer_Mode;/*Timer mode 0, COUNTER_RISING_MODE 1 COUNTER_FALLING_MODE 2*/
	uint8_t Timer_Polling_Or_Interrupt;/*TIMER_POLLING_MODE 0,TIMER_INTERRUPT_MODE 1*/
	uint8_t Timer_Prescaler;/*No 0,8 1 ,16 2,32 3,64 4,128 5,256 6,1024 7*/
	void (*Timer_Cbk_ptr)(void);/*call back for TIMER_INTERRUPT_MODE*/
}Timer_cfg_s;

/************************************************************************/
/*				 DEFINES			        */
/************************************************************************/
#define TIMER_CH0 0
#define TIMER_CH1 1
#define TIMER_CH2 2
#define TIMER_MODE 0
#define COUNTER_MODE 1
/*********************************************************/
/********TIMER_CH0_MODE*******Timer_Prescaler******************/
/********************************************************/
#define		TIMER0_PRESCALER_2_TIMER_MODE				0xC0
#define		TIMER0_PRESCALER_4_TIMER_MODE				0xC1
#define		TIMER0_PRESCALER_8_TIMER_MODE				0xC2
#define		TIMER0_PRESCALER_16_TIMER_MODE			0xC3
#define		TIMER0_PRESCALER_32_TIMER_MODE			0xC4
#define		TIMER0_PRESCALER_64_TIMER_MODE			0xC5
#define		TIMER0_PRESCALER_128_TIMER_MODE			0xC6
#define   TIMER0_PRESCALER_256_TIMER_MODE			0xC7

#define		TIMER0_PRESCALER_2_FAL_COUNTER_MODE				0xE8
#define		TIMER0_PRESCALER_4_FAL_COUNTER_MODE				0xE9
#define		TIMER0_PRESCALER_8_FAL_COUNTER_MODE				0xEA
#define		TIMER0_PRESCALER_16_FAL_COUNTER_MODE			0xEB
#define		TIMER0_PRESCALER_32_FAL_COUNTER_MODE			0xEC
#define		TIMER0_PRESCALER_64_FAL_COUNTER_MODE			0xED
#define		TIMER0_PRESCALER_128_FAL_COUNTER_MODE			0xEE
#define   TIMER0_PRESCALER_256_FAL_COUNTER_MODE			0xEF

#define		TIMER0_PRESCALER_2_RIS_COUNTER_MODE				0xE0
#define		TIMER0_PRESCALER_4_RIS_COUNTER_MODE				0xE1
#define		TIMER0_PRESCALER_8_RIS_COUNTER_MODE				0xE2
#define		TIMER0_PRESCALER_16_RIS_COUNTER_MODE			0xE3
#define		TIMER0_PRESCALER_32_RIS_COUNTER_MODE			0xE4
#define		TIMER0_PRESCALER_64_RIS_COUNTER_MODE			0xE5
#define		TIMER0_PRESCALER_128_RIS_COUNTER_MODE			0xE6
#define   TIMER0_PRESCALER_256_RIS_COUNTER_MODE			0xE7

#define		TIMER0_PRESCALER_2				0xF0
#define		TIMER0_PRESCALER_4				0xF1
#define		TIMER0_PRESCALER_8				0xF2
#define		TIMER0_PRESCALER_16				0xF3
#define		TIMER0_PRESCALER_32				0xF4
#define		TIMER0_PRESCALER_64				0xF5
#define		TIMER0_PRESCALER_128			0xF6
#define   TIMER0_PRESCALER_256			0xF7

#define GLOBAL_INT_EN	0x80
#define TIMER0_INTERRUPT_MODE 		0xA0
#define TIMER0_POOLING_MODE 			0xDF

#define TIMER1_POOLING_MODE             0xFE
#define TIMER2_POOLING_MODE             0xFD
//#define EXTERNAL_INTERRUPT_DISABLE
#define TIMER1_INTERRUPT_MODE           0x01
#define TIMER2_INTERRUPT_MODE           0x02

/*********************TIMER1_CONFIG**********************/
#define TIMER1_ON  													  0x01
#define 	TIMER1_MODE_INTERNAL							  0X08
#define 	TIMER1_MODE_EXTERNAL_SYNC_ON			  0X0C
#define		TIMER1_PRESCALER_NO_PRESCALER				0x00
#define		TIMER1_PRESCALER_2									0x10
#define		TIMER1_PRESCALER_4									0x20
#define		TIMER1_PRESCALER_8									0x30
#define		TIMER1_PRESCALER_8									0x30

/*********************TIMER2_CONFIG**********************/
#define		TIMER2_PRESCALER_2									0x00
#define		TIMER2_PRESCALER_4									0x01
#define		TIMER2_PRESCALER_16									0x02
#define		TIMER2_START										0x04
#define		TIMER2_POSTSCALER_NO								0x00
#define		TIMER2_POSTSCALER_2									0x10
#define		TIMER2_POSTSCALER_3									0x20
#define		TIMER2_POSTSCALER_4									0x30
#define		TIMER2_POSTSCALER_5									0x40
#define		TIMER2_POSTSCALER_6									0x50
#define		TIMER2_POSTSCALER_7									0x60
#define		TIMER2_POSTSCALER_8									0x70
#define		TIMER2_POSTSCALER_9									0x80
#define		TIMER2_POSTSCALER_10								0x90
#define		TIMER2_POSTSCALER_11								0xA0
#define		TIMER2_POSTSCALER_12								0xB0
#define		TIMER2_POSTSCALER_13								0xC0
#define		TIMER2_POSTSCALER_14								0xD0
#define		TIMER2_POSTSCALER_15								0xE0
#define		TIMER2_POSTSCALER_16								0xF0


/********************************************************/
/********Extern Configuration Structure******************/
/********************************************************/
extern Timer_cfg_s Timer_Configuration0;
extern Timer_cfg_s Timer_Configuration2;
extern Timer_cfg_s Timer_Configuration1;
extern Timer_cfg_s Timer_Deinit_Configuration0;
extern Timer_cfg_s Timer_Deinit_Configuration1;
extern Timer_cfg_s Timer_Deinit_Configuration2;

#endif /* TIMERSCONFIG_H_ */
