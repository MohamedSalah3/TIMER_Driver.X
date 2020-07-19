/*
 * File:   main.c
 * Author: mo
 *
 * Created on 15 ?????, 2020, 07:33 ?
 */
/*void __interrupt () checkmyis(void)*/
#include "Timer.h"
#include "ADC.h"
#include "I2C.h"
static uint8_t ret = 0;
static uint16_t u16_data = 0;
int main(void)
{
  /*ret=DIO_init(&Dio_configutation_A);
 ret=ADC_INIT(&ADC_Cnfiguration);
ret= Timer_Init(&Timer_Configuration2);
ret=Timer_Start(TIMER_CH2,250);
*/I2C_Init(&I2c_Configuration_Eeprom);

  unsigned int Address = 0x0020; // Some Random Address
  unsigned char Data = 0x04;     // Some Random Data To Write
  EEPROM_Write(Address++, Data++); // Write 0x04 @ 0x0020
  EEPROM_Write(Address++, Data++); // Write 0x05 @ 0x0021
  EEPROM_Write(Address, Data);     // Write 0x06 @ 0x0022
  SwDelay_ms(10); // Wait tWR=10ms For Write To Complete
  Address = 0x0020; // Point To First Byte Location
  PORTD_DIR = 0x00;
  PORTD_DATA = EEPROM_Read(Address++); // Should Read 0x04
  SwDelay_ms(1000);
  PORTD_DATA = EEPROM_Read(Address++); // Should Read 0x05
  SwDelay_ms(1000);
  PORTD_DATA = EEPROM_Read(Address);   // Should Read 0x06
  SwDelay_ms(1000);

// PORTD_DIR &= 0x00;
// PORTB_DIR &= 0x00;
// PORTC_DIR &= 0x00;


while (1) {
  u16_data=ADC_READ();
//  while(READBIT(ADCON0 ,GO_DONE) >= 1)
//  {/*wait*/;}
}

    return 0;
}
