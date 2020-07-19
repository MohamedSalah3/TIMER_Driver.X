/*
 * File:   registers.h
 * Author: mo
 *
 * Created on 09 ?????, 2020, 10:25 ?
 */

#ifndef REGISTERS_H
#define	REGISTERS_H
#include "std_types.h"
/********************************************************************/
#define PORTA_DATA *((reg_type8_t)(0x0005))
#define PORTA_DIR   *((reg_type8_t)(0x0085))
/*1Fh ADCON0 ADCS1 ADCS0 CHS2 CHS1 CHS0 GO/DONE —ADON0000 00-0 127, 150*/
#define ADCON0   *((reg_type8_t)(0x001F))
#define ADON            0x01
#define GO_DONE         0x04
#define ADCON1   *((reg_type8_t)(0x009F))
#define ADCS2           0x40
#define ADC_RESULTLOW                     *((reg_type8_t)(0x009E))
#define ADC_RESULTHIGH                     *((reg_type8_t)(0x001E))
#define STATUS_REG   *((reg_type8_t)(0x0083))
/********************************************************************/
#define PORTB_DATA *((reg_type8_t)(0x0006))
#define PORTB_DIR   *((reg_type8_t)(0x0086))
/********************************************************************/
#define PORTC_DATA *((reg_type8_t)(0x0007))
#define PORTC_DIR   *((reg_type8_t)(0x0087))
/********************************************************************/
#define PORTD_DATA  *((reg_type8_t)(0x0008))
#define PORTD_DIR   *((reg_type8_t)(0x0088))
/********************************************************************/
#define PORTE_DATA  *((reg_type8_t)(0x0009))
#define PORTE_DIR   *((reg_type8_t)(0x0089))
/********************************************************************/
/*                          TIMER0                                  */
/********************************************************************/
#define OPTION_REG  *((reg_type8_t)(0x0081))
#define GIE  0x80
#define PEIE 0x40
#define TMR0IE 0x20
#define INTE 0x10
#define RBIE 0x08
#define TMR0IF 0x04
#define INTF 0x02
#define RBIF 0x01
#define INTCON      *((reg_type8_t)(0x000B))
#define TIMER0      *((reg_type8_t)(0x0001))
/********************************************************************/
/*                                 TIMER1                           */
/********************************************************************/
/*10h T1CON — — T1CKPS1 T1CKPS0 T1OSCEN T1SYNCTMR1CS TMR1ON--00 0000 --uu uuuu*/
#define TIMER1_CONTROL_REGISTER     *((reg_type8_t)(0x0010))
/*0Ch PIR1 (PSPIF ADIF RCIF TXIF SSPIF CCP1IF TMR2IF TMR1IF) 0000 0000 _ 0000 0000*/
#define TMR1IF                        0x01
#define TMR2IF                        0x02

#define PIR1                        *((reg_type8_t)(0x000C))
#define ADIF                          0x40
/*8Ch PIE1 (PSPIE  ADIE RCIE TXIE SSPIE CCP1IE TMR2IE TMR1IE) 0000 0000_0000 0000*/
#define PIE1                        *((reg_type8_t)(0x008C))
#define TMR1IE                        0x01
#define TMR2IE                        0x02
#define CCP1IF                        0x04
#define SSPIF                         0x08
#define TXIF                          0x10
#define RCIF                          0x20
#define ADIE                          0x40
#define PSPIF                         0x80

/*0Eh TMR1L Holding Register for the Least Significant Byte
 of the 16-bit TMR1 Register xxxx xxxx uuuu uuuu*****************/
#define TIMER1_LOW                  *((reg_type8_t)(0x000E))
/*0Fh TMR1H Holding Register for the Most Significant Byte of the
 16-bit TMR1 Register xxxx xxxx uuuu uuuu************************/
#define TIMER1_HIGH                 *((reg_type8_t)(0x000F))

#define TIMER1                     *((reg_type16_t)(0x000E))
/*****************************************************************/
/*                        TIMER2                                 */
/*****************************************************************/
/*12h T2CON — TOUTPS3 TOUTPS2 TOUTPS1 TOUTPS0 TMR2ON T2CKPS1 T2CKPS0*
*************-000 0000 -000 0000************************************/
#define TIMER2_CONTROL_REGISTER     *((reg_type8_t)(0x0012))
/*11h TMR2 Timer2 Module’s Register 0000 0000 _ 0000 0000*/
#define TIMER2                      *((reg_type8_t)(0x0011))
/*92h PR2 Timer2 Period Register 1111 1111 _ 1111 1111*/
/**************Similar to compare match****************/
#define TIMER2_PERIOD_REG           *((reg_type8_t)(0x0092))
/*****************************************************************/

/*****************************************************************/
/*                 SERIAL COMMUNICATION MSSP(SPI<I2C)            */
/*****************************************************************/
#define MSSP_STATUS_REGISTER         *((reg_type8_t)(0x0094))
#define R_W                        0x04
#define MSSP_CONTROL_REGISTER_1         *((reg_type8_t)(0x0014))
#define MSSP_CONTROL_REGISTER_2         *((reg_type8_t)(0x0091))
#define RCEN    0x08
#define PEN     0x04
#define SEN     0x01
#define ACKEN   0x10
#define ACKDT   0x20
#define RSEN    0x02
#define ACKSTAT 0x40
#define SERIAL_BUFFER_REGISTER          *((reg_type8_t)(0x0013))
#define MSSP_ADDRESS_REGISTER           *((reg_type8_t)(0x0093))

/*MSSP_Shift_Register*/
#endif	/* REGISTERS_H */
