/*
* File: main.c
* Project: I2C EEPROM Interfacing
* Author: Khaled Magdy
* Visit @ https://www.DeepBlueMbedded.com
*/
#include <xc.h>
//#include "config.h"
#include "I2C_EEPROM.h"
#define _XTAL_FREQ 16000000
void main(void) {
  I2C_Master_Init(100000);
  unsigned int Address = 0x0020; // Some Random Address
  unsigned char Data = 0x04;     // Some Random Data To Write
  EEPROM_Write(Address++, Data++); // Write 0x04 @ 0x0020
  EEPROM_Write(Address++, Data++); // Write 0x05 @ 0x0021
  EEPROM_Write(Address, Data);     // Write 0x06 @ 0x0022
  __delay_ms(10); // Wait tWR=10ms For Write To Complete
  Address = 0x0020; // Point To First Byte Location
  TRISD = 0x00;
  PORTD = EEPROM_Read(Address++); // Should Read 0x04
  __delay_ms(1000);
  PORTD = EEPROM_Read(Address++); // Should Read 0x05
  __delay_ms(1000);
  PORTD = EEPROM_Read(Address);   // Should Read 0x06
  __delay_ms(1000);
  while(1)
  {
     // Stay IDLE .. DO Nothing!
  }
  return;
}
