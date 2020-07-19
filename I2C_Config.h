/*
 * File:   I2C_Config.h
 * Author: mo
 *
 * Created on 17 ?????, 2020, 11:24 ?
 */

#ifndef I2C_CONFIG_H
#define	I2C_CONFIG_H
#include "DIO.h"


typedef enum {I2C_OK, I2C_NOK}I2C_CheckType;
typedef void (*I2C_CbkPftype)(void);
typedef struct
{
	unsigned long int comm_freq;
	I2C_CbkPftype ActionDoneCbkPtr;
}I2C_ConfigType;
/*1111= I2C Slave mode, 10-bit address with Start and Stop bit interrupts enabled
1110= I
2
C Slave mode, 7-bit address with Start and Stop bit interrupts enabled
1011= I
2
C Firmware Controlled Master mode (Slave Idle)
1000= I2C Master mode, clock = FOSC/(4 * (SSPADD + 1))
0111= I
2
C Slave mode, 10-bit address
0110= I
2
C Slave mode, 7-bit address*/
#define I2C_MASTER_MODE 0x08
#define I2C_ENABLE 0x20

extern I2C_ConfigType I2c_Configuration_Eeprom ;
#endif	/* I2C_CONFIG_H */
