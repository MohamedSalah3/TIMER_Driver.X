#include "I2C.h"
#define _XTAL 8000000
/*https://deepbluembedded.com/reading-and-writing-serial-i2c-eeprom-with-pic/#_I2C_EEPROM_24C64*/
/*https://circuitdigest.com/microcontroller-projects/i2c-communication-with-pic-microcontroller-pic16f877a*/
/**https://circuitdigest.com/microcontroller-projects/writing-your-first-pic-microcontroller-program*/
void I2C_Init(I2C_ConfigType *i2c_info)
{
DIO_init(&Dio_configutation_C);
MSSP_CONTROL_REGISTER_1 |=I2C_MASTER_MODE|I2C_ENABLE;
MSSP_CONTROL_REGISTER_2 =0x00;
MSSP_ADDRESS_REGISTER=(_XTAL/(4 * (i2c_info->comm_freq) * 100))-1;
MSSP_STATUS_REGISTER =0x00;
}


unsigned char I2C_Master_Write(unsigned char data)
{
  I2C_Hold();
  SERIAL_BUFFER_REGISTER = data;
  while(!READBIT(PIE1,SSPIF))
  {;} // Wait Until Completion
  PIE1 &= (~SSPIF) ;
  return (MSSP_CONTROL_REGISTER_2 & ACKSTAT);
}
void I2C_Master_RepeatedStart()
{
  I2C_Hold();
  MSSP_CONTROL_REGISTER_2 |= RSEN ;
}

void I2C_Hold(void)
{
    while (
      (MSSP_CONTROL_REGISTER_2 & 0x1F)
      ||
      (MSSP_STATUS_REGISTER & R_W)
     ) ; //check the this on registers to make sure the IIC is not in progress
}

void I2C_Begin()
{
  I2C_Hold();  //Hold the program is I2C is busy
MSSP_CONTROL_REGISTER_2 |=SEN;     //Begin IIC pg85/234
}
void I2C_End()
{
  I2C_Hold(); //Hold the program is I2C is busy
MSSP_CONTROL_REGISTER_2 |=PEN;   //End IIC pg85/234
}

void I2C_Write(uint8_t data)
{
  I2C_Hold(); //Hold the program is I2C is busy
  SERIAL_BUFFER_REGISTER = data;         //pg82/234
}

uint8_t I2C_Read_Byte(void)
{
  //---[ Receive & Return A Byte ]---
  I2C_Hold();
  MSSP_CONTROL_REGISTER_2 |= RCEN ; // Enable & Start Reception
  while(!READBIT(PIE1,SSPIF)); // Wait Until Completion
  PIE1 &=(~SSPIF); // Clear The Interrupt Flag Bit
  I2C_Hold();
  return SERIAL_BUFFER_REGISTER; // Return The Received Byte
}
void I2C_ACK(void)
{
  MSSP_CONTROL_REGISTER_2 &= (~ACKDT);// 0 -> ACK
  I2C_Hold();
  MSSP_CONTROL_REGISTER_2 |= ACKEN ; // Send ACK
}
void I2C_NACK(void)
{
   MSSP_CONTROL_REGISTER_2 |= ACKDT; // 1 -> NACK
  I2C_Hold();
  MSSP_CONTROL_REGISTER_2 |= ACKEN; // Send NACK
}
void EEPROM_Write(unsigned int add, unsigned char data)
{
  I2C_Begin();
  // Wait Until EEPROM Is IDLE
  while(I2C_Master_Write(EEPROM_Address_W))
    I2C_Master_RepeatedStart();
  I2C_Master_Write(add>>8);
  I2C_Master_Write((unsigned char)add);
  I2C_Master_Write(data);
  I2C_End();
}

uint8_t EEPROM_Read(unsigned int add)
{
  uint8_t Data;
I2C_Begin();// Wait Until EEPROM Is IDLE
  while(I2C_Master_Write(EEPROM_Address_W))
    I2C_Master_RepeatedStart();
  I2C_Master_Write(add>>8);
  I2C_Master_Write((unsigned char)add);
  I2C_Master_RepeatedStart();
  I2C_Master_Write(EEPROM_Address_R);
  Data = I2C_Read_Byte();
  I2C_NACK();
  I2C_End();
  return Data;
}