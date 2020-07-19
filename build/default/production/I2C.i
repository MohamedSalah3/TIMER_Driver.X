# 1 "I2C.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "I2C.c" 2
# 1 "./I2C.h" 1
# 10 "./I2C.h"
# 1 "./I2C_Config.h" 1
# 10 "./I2C_Config.h"
# 1 "./DIO.h" 1



# 1 "./DIO_Config.h" 1
# 10 "./DIO_Config.h"
# 1 "./registers.h" 1
# 10 "./registers.h"
# 1 "./std_types.h" 1
# 16 "./std_types.h"
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;
typedef signed char sint8_t;
typedef signed int sint16_t;
typedef signed long int sint32_t;
typedef signed long long sint64_t;
typedef volatile uint8_t* const reg_type8_t;
typedef volatile uint16_t* const reg_type16_t;
# 10 "./registers.h" 2
# 10 "./DIO_Config.h" 2

# 1 "./error.h" 1
# 12 "./error.h"
typedef uint8_t ERROR_STATUS;
# 11 "./DIO_Config.h" 2

# 1 "./interrupts.h" 1
# 31 "./interrupts.h"
typedef void (*ptr_to_Fun)(void);
extern ptr_to_Fun TIMER0OVF_INT;
extern ptr_to_Fun TIMER1OVF_INT ;
extern ptr_to_Fun TIMER2OVF_INT ;
extern ptr_to_Fun ADC_INT ;

void global_int_enable(void);

ERROR_STATUS special_int_disable(uint8_t u8_interrupt_prepherals);
ERROR_STATUS special_int_enable(uint8_t u8_interrupt_prepherals);
ERROR_STATUS read_int_flag(uint8_t u8_interrupt_prepherals ,uint8_t * ptr_to_flag);
ERROR_STATUS clear_int_flag(uint8_t u8_interrupt_prepherals);
void global_int_disable(void);
# 12 "./DIO_Config.h" 2
# 58 "./DIO_Config.h"
typedef struct DIO_Cfg_s{
    uint8_t port;
    uint8_t dir;
    uint8_t pin;
    uint8_t operation_mode;

}DIO_Cfg_s;


extern DIO_Cfg_s Dio_configutation_A;
extern DIO_Cfg_s Dio_configutation_B;
extern DIO_Cfg_s Dio_configutation_C;
extern DIO_Cfg_s Dio_configutation_D;
extern DIO_Cfg_s Dio_configutation_E;
# 4 "./DIO.h" 2
# 13 "./DIO.h"
ERROR_STATUS DIO_init (DIO_Cfg_s *DIO_info);
# 42 "./DIO.h"
ERROR_STATUS DIO_Write (uint8_t GPIO, uint8_t pins, uint8_t value);
# 70 "./DIO.h"
ERROR_STATUS DIO_Read (uint8_t GPIO,uint8_t pins, uint8_t *data);
# 95 "./DIO.h"
ERROR_STATUS DIO_Toggle (uint8_t GPIO, uint8_t pins);
# 10 "./I2C_Config.h" 2



typedef enum {I2C_OK, I2C_NOK}I2C_CheckType;
typedef void (*I2C_CbkPftype)(void);
typedef struct
{
 unsigned long int comm_freq;
 I2C_CbkPftype ActionDoneCbkPtr;
}I2C_ConfigType;
# 37 "./I2C_Config.h"
extern I2C_ConfigType I2c_Configuration_Eeprom ;
# 10 "./I2C.h" 2





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
# 1 "I2C.c" 2





void I2C_Init(I2C_ConfigType *i2c_info)
{
DIO_init(&Dio_configutation_C);
*((reg_type8_t)(0x0014)) |=0x08|0x20;
*((reg_type8_t)(0x0091)) =0x00;
*((reg_type8_t)(0x0093))=(8000000/(4 * (i2c_info->comm_freq) * 100))-1;
*((reg_type8_t)(0x0094)) =0x00;
}


unsigned char I2C_Master_Write(unsigned char data)
{
  I2C_Hold();
  *((reg_type8_t)(0x0013)) = data;
  while(!( (*((reg_type8_t)(0x008C)) >> 0x08) & 1 ))
  {;}
  *((reg_type8_t)(0x008C)) &= (~0x08) ;
  return (*((reg_type8_t)(0x0091)) & 0x40);
}
void I2C_Master_RepeatedStart()
{
  I2C_Hold();
  *((reg_type8_t)(0x0091)) |= 0x02 ;
}

void I2C_Hold(void)
{
    while (
      (*((reg_type8_t)(0x0091)) & 0x1F)
      ||
      (*((reg_type8_t)(0x0094)) & 0x04)
     ) ;
}

void I2C_Begin()
{
  I2C_Hold();
*((reg_type8_t)(0x0091)) |=0x01;
}
void I2C_End()
{
  I2C_Hold();
*((reg_type8_t)(0x0091)) |=0x04;
}

void I2C_Write(uint8_t data)
{
  I2C_Hold();
  *((reg_type8_t)(0x0013)) = data;
}

uint8_t I2C_Read_Byte(void)
{

  I2C_Hold();
  *((reg_type8_t)(0x0091)) |= 0x08 ;
  while(!( (*((reg_type8_t)(0x008C)) >> 0x08) & 1 ));
  *((reg_type8_t)(0x008C)) &=(~0x08);
  I2C_Hold();
  return *((reg_type8_t)(0x0013));
}
void I2C_ACK(void)
{
  *((reg_type8_t)(0x0091)) &= (~0x20);
  I2C_Hold();
  *((reg_type8_t)(0x0091)) |= 0x10 ;
}
void I2C_NACK(void)
{
   *((reg_type8_t)(0x0091)) |= 0x20;
  I2C_Hold();
  *((reg_type8_t)(0x0091)) |= 0x10;
}
void EEPROM_Write(unsigned int add, unsigned char data)
{
  I2C_Begin();

  while(I2C_Master_Write(0xA0))
    I2C_Master_RepeatedStart();
  I2C_Master_Write(add>>8);
  I2C_Master_Write((unsigned char)add);
  I2C_Master_Write(data);
  I2C_End();
}

uint8_t EEPROM_Read(unsigned int add)
{
  uint8_t Data;
I2C_Begin();
  while(I2C_Master_Write(0xA0))
    I2C_Master_RepeatedStart();
  I2C_Master_Write(add>>8);
  I2C_Master_Write((unsigned char)add);
  I2C_Master_RepeatedStart();
  I2C_Master_Write(0xA1);
  Data = I2C_Read_Byte();
  I2C_NACK();
  I2C_End();
  return Data;
}
