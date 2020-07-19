# 1 "main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "main.c" 2







# 1 "./Timer.h" 1
# 11 "./Timer.h"
# 1 "./Timer_Config.h" 1
# 11 "./Timer_Config.h"
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
# 11 "./Timer_Config.h" 2

# 1 "./registers.h" 1
# 12 "./Timer_Config.h" 2

# 1 "./error.h" 1
# 12 "./error.h"
typedef uint8_t ERROR_STATUS;
# 13 "./Timer_Config.h" 2

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
# 14 "./Timer_Config.h" 2






typedef struct Timer_cfg_s
{
 uint8_t Timer_CH_NO;
 uint8_t Timer_Mode;
 uint8_t Timer_Polling_Or_Interrupt;
 uint8_t Timer_Prescaler;
 void (*Timer_Cbk_ptr)(void);
}Timer_cfg_s;
# 122 "./Timer_Config.h"
extern Timer_cfg_s Timer_Configuration0;
extern Timer_cfg_s Timer_Configuration2;
extern Timer_cfg_s Timer_Configuration1;
extern Timer_cfg_s Timer_Deinit_Configuration0;
extern Timer_cfg_s Timer_Deinit_Configuration1;
extern Timer_cfg_s Timer_Deinit_Configuration2;
# 11 "./Timer.h" 2
# 28 "./Timer.h"
ERROR_STATUS Timer_Init(Timer_cfg_s* Timer_cfg);


void global_int_enable(void);
# 42 "./Timer.h"
ERROR_STATUS Timer_Start(uint8_t Timer_CH_NO, uint16_t Timer_Count);
extern void timer0_interrupt_ovfRoutine(void);
extern void timer1_interrupt_ovfRoutine(void);
extern void timer2_interrupt_ovfRoutine(void);
# 55 "./Timer.h"
ERROR_STATUS Timer_Stop(uint8_t Timer_CH_NO);
# 67 "./Timer.h"
ERROR_STATUS Timer_GetStatus(uint8_t Timer_CH_NO, uint8_t* Data);
# 79 "./Timer.h"
ERROR_STATUS Timer_GetValue(uint8_t Timer_CH_NO, uint16_t* Data);
# 8 "main.c" 2

# 1 "./ADC.h" 1
# 11 "./ADC.h"
# 1 "./ADC_Config.h" 1
# 10 "./ADC_Config.h"
# 1 "./DIO.h" 1



# 1 "./DIO_Config.h" 1
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
# 10 "./ADC_Config.h" 2




typedef struct ADC_Cfg_s{
    uint8_t u8_Channel_Number;
    uint8_t u8_Prescaler;
    uint8_t clock_configuration;
    uint8_t u8_ten_bit_arrangment;
    uint8_t u8_polling_interrupt;

}ADC_Cfg_s;
# 56 "./ADC_Config.h"
extern ADC_Cfg_s ADC_Cnfiguration;
# 11 "./ADC.h" 2

# 1 "./softwareDelay.h" 1
# 16 "./softwareDelay.h"
void SwDelay_ms(uint32_t n);






void SwDelay_us(uint32_t n);
# 12 "./ADC.h" 2





ERROR_STATUS ADC_INIT(ADC_Cfg_s *ADC_info);


uint16_t ADC_READ(void);

void adc_interrupt_routine(void);
# 9 "main.c" 2

# 1 "./I2C.h" 1
# 10 "./I2C.h"
# 1 "./I2C_Config.h" 1
# 13 "./I2C_Config.h"
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
# 10 "main.c" 2

static uint8_t ret = 0;
static uint16_t u16_data = 0;
int main(void)
{




  I2C_Init(&I2c_Configuration_Eeprom);

  unsigned int Address = 0x0020;
  unsigned char Data = 0x04;
  EEPROM_Write(Address++, Data++);
  EEPROM_Write(Address++, Data++);
  EEPROM_Write(Address, Data);
  SwDelay_ms(10);
  Address = 0x0020;
  *((reg_type8_t)(0x0088)) = 0x00;
  *((reg_type8_t)(0x0008)) = EEPROM_Read(Address++);
  SwDelay_ms(1000);
  *((reg_type8_t)(0x0008)) = EEPROM_Read(Address++);
  SwDelay_ms(1000);
  *((reg_type8_t)(0x0008)) = EEPROM_Read(Address);
  SwDelay_ms(1000);






while (1) {
  u16_data=ADC_READ();


}

    return 0;
}
