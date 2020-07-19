/*
 * File:   ADC_Config.h
 * Author: mo
 *
 * Created on 18 ?????, 2020, 08:30 ?
 */

#ifndef ADC_CONFIG_H
#define	ADC_CONFIG_H
#include "DIO.h"



typedef struct ADC_Cfg_s{
    uint8_t u8_Channel_Number;
    uint8_t u8_Prescaler;
    uint8_t clock_configuration;
    uint8_t u8_ten_bit_arrangment;
    uint8_t u8_polling_interrupt;

}ADC_Cfg_s;

#define ADC0 0x00
#define ADC1 0x08
#define ADC2 0x10
#define ADC3 0x18
#define ADC4 0x20
#define ADC5 0x28
#define ADC6 0x30
#define ADC7 0x38
#define CH_SELECT_BIT_CLR 0b11000101

#define ADC_PRESCALER_2CON0 0x00
#define ADC_PRESCALER_8CON0 0x40
#define ADC_PRESCALER_32CON0 0x80
#define ADC_PRESCALER_FRC_CON0 0xC0

#define ADC_PRESCALER_4CON1 0x00
#define ADC_PRESCALER_16CON1 0x40
#define ADC_PRESCALER_64CON1 0x80
#define ADC_PRESCALER_FRC_CON1 0xC0

#define ADC_ON 0x01

#define RIGHT_JUSTFIED 0x80
#define LEFT_JUSTFIED 0x00
#define PRESCALER2  0
#define PRESCALER8  1
#define PRESCALER32 2
#define PRESCALERFRC1   3
#define PRESCALER4  4
#define PRESCALER16 5
#define PRESCALER64 6
#define PRESCALERFRC2   7

extern ADC_Cfg_s ADC_Cnfiguration;


#endif	/* ADC_CONFIG_H */
