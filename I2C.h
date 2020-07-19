/*
 * File:   I2C.h
 * Author: mo
 *
 * Created on 17 ?????, 2020, 11:24 ?
 */

#ifndef I2C_H
#define	I2C_H
#include "I2C_Config.h"


#define EEPROM_Address_R 0xA1
#define EEPROM_Address_W 0xA0
void I2C_Hold(void);
void I2C_Init(I2C_ConfigType *i2c_info);
unsigned char I2C_Master_Write(unsigned char data);
void I2C_Master_RepeatedStart();
void I2C_Hold(void);

void I2C_Begin();
void I2C_End();
void I2C_Write(uint8_t data);
uint8_t I2C_Read_Byte(void);
void I2C_ACK(void);
void I2C_NACK(void);
void EEPROM_Write(unsigned int add, unsigned char data);
uint8_t EEPROM_Read(unsigned int add);


#endif	/* I2C_H */
