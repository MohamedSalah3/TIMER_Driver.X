
/*
 * File:   interrupts.h
 * Author: mo
 *
 * Created on 15 ?????, 2020, 09:55 ?
 */

#ifndef INTERRUPTS_H
#define	INTERRUPTS_H

#include "registers.h"
#include "std_types.h"
#include "error.h"
#define TIMR0 0
#define TIMR1 1
#define TIMR2 2
#define EXTERNAL_INTERRUPT 3
#define ADC_INTERRUPT                   0x40
#define ADC_POLLING                     0xBF
#define TIMER0_INTERRUPT_MODE 	     	0xA0
#define GLOBAL_INTERRUPT_ENABLE 		0x80
#define TIMER0_POOLING_MODE 			0xDF
#define TIMER1_POOLING_MODE             0xFE
#define TIMER2_POOLING_MODE             0xFD
//#define EXTERNAL_INTERRUPT_DISABLE
#define TIMER1_INTERRUPT_MODE           0x01
#define TIMER2_INTERRUPT_MODE           0x02
#define GLOBAL_INTERRUPT_DISABLE        0x7f

typedef void (*ptr_to_Fun)(void);
extern ptr_to_Fun TIMER0OVF_INT;
extern ptr_to_Fun TIMER1OVF_INT ;
extern ptr_to_Fun TIMER2OVF_INT ;
extern ptr_to_Fun ADC_INT ;

void global_int_enable(void);
/**/
ERROR_STATUS special_int_disable(uint8_t u8_interrupt_prepherals);
ERROR_STATUS special_int_enable(uint8_t u8_interrupt_prepherals);
ERROR_STATUS read_int_flag(uint8_t u8_interrupt_prepherals ,uint8_t * ptr_to_flag);
ERROR_STATUS clear_int_flag(uint8_t u8_interrupt_prepherals);
void global_int_disable(void);
#endif	/* INTERRUPTS_H */
