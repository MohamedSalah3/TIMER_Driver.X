/*
 * File:   DIO_Config.h
 * Author: mo
 *
 * Created on 09 ?????, 2020, 10:25 ?
 */

#ifndef DIO_CONFIG_H
#define	DIO_CONFIG_H
#include "registers.h"
#include "error.h"
#include "interrupts.h"
/******************************************************************************************/
/*PINS*/
#define PIN0	0x01
#define PIN1	0x02
#define PIN2	0x04
#define PIN3	0x08
#define PIN4	0x10
#define PIN5	0x20
#define PIN6	0x40
#define PIN7	0x80
/******************************************************************************************/
/*BITS*/
#define BIT0	0x01
#define BIT1	0x02
#define BIT2	0x04
#define BIT3	0x08
#define BIT4	0x10
#define BIT5	0x20
#define BIT6	0x40
#define BIT7	0x80
/******************************************************************************************/
/*for PORT */
#define UPPER_NIBBLE	0xF0
#define LOWER_NIBBLE	0x0F
#define FULL_PORT		0xFF
/******************************************************************************************/
/*PORTS*/
#define GPIOA			0
#define GPIOB			1
#define GPIOC			2
#define GPIOD			3
#define GPIOE			4
/*direction*/
#define OUTPUT		0xFF
#define INPUT			0x00
/******************************************************************************************/
/*                 operation_mode                                                         */
/******************************************************************************************/

#define PORT_NORMAL_MODE 0x06

/*   PORTA_MODE when = 0x0f works as digital in[put] while PORTA_MODE = 0x00 works as ADC*/
/******************************************************************************************/

/*define intialization structure*/
typedef struct DIO_Cfg_s{
    uint8_t port;
    uint8_t dir;
    uint8_t pin;
    uint8_t operation_mode;

}DIO_Cfg_s;
/******************************************************************************************/
/*extern these structures soo that u will be able to use it */
extern DIO_Cfg_s Dio_configutation_A;
extern DIO_Cfg_s Dio_configutation_B;
extern DIO_Cfg_s Dio_configutation_C;
extern DIO_Cfg_s Dio_configutation_D;
extern DIO_Cfg_s Dio_configutation_E;
/******************************************************************************************/
#endif	/* DIO_CONFIG_H */
