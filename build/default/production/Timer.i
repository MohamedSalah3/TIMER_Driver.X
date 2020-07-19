# 1 "Timer.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Timer.c" 2
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
# 1 "Timer.c" 2

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
# 2 "Timer.c" 2
# 14 "Timer.c"
static uint8_t Prescaler0 = 0xFF;
static uint8_t Prescaler1 = 0x00;

static uint8_t u8_timer2Count = 0;

ERROR_STATUS Timer_Init(Timer_cfg_s* Timer_cfg)
{
uint8_t ret_error = 0;

switch (Timer_cfg->Timer_CH_NO)
{
  case 0:
    Prescaler0 &= (Timer_cfg -> Timer_Mode);
        switch (Timer_cfg->Timer_Polling_Or_Interrupt)
        {
        case 0xA0 :
           ret_error =special_int_enable(0);
           TIMER0OVF_INT = ( Timer_cfg -> Timer_Cbk_ptr);
            break;
            case 0xDF:
            ret_error =special_int_disable(0);
            break;
            default:
            ret_error += 1 +24;
            break;
        }
  break;
  case 1:
    switch (Timer_cfg->Timer_Mode)
    {
      case 0:
        Prescaler1 |= (Timer_cfg -> Timer_Prescaler)|0X08;
        switch (Timer_cfg->Timer_Polling_Or_Interrupt)
          {
            case 0x01:
                ret_error = special_int_enable(1);
                TIMER1OVF_INT = ( Timer_cfg -> Timer_Cbk_ptr);
            break;
            case 0xFE:
                ret_error = special_int_disable(1);
            break;
            default:
            ret_error += 1 +24;
            break;
          }
      break;
      case 1:
      Prescaler1 |= (Timer_cfg -> Timer_Prescaler);
        switch (Timer_cfg->Timer_Polling_Or_Interrupt)
          {
            case 0x01:
            ret_error = special_int_enable(1);
            TIMER1OVF_INT = ( Timer_cfg -> Timer_Cbk_ptr);
            break;
            case 0xFE:
            ret_error = special_int_disable(1);
            break;
            default:
            ret_error += 1 +24;
            break;
          }
      break;
      default:
      ret_error += 1 +22;
      break;
    }

  break;
  case 2:
          *((reg_type8_t)(0x0012)) |= (Timer_cfg -> Timer_Prescaler);
        switch (Timer_cfg->Timer_Polling_Or_Interrupt)
          {
            case 0x02:
                ret_error =special_int_enable(2);
                TIMER2OVF_INT = ( Timer_cfg -> Timer_Cbk_ptr);

            break;
            case 0xFD:
                ret_error =special_int_disable(2);
            break;
            default:
            ret_error += 1 +24;
            break;
          }
  break;
  default:
  ret_error += 1 +26;
  break;
}

return ret_error;
}


void timer0_interrupt_ovfRoutine(void)
{ *((reg_type8_t)(0x0087))=0x00;
*((reg_type8_t)(0x001F)) |=0x04;
*((reg_type8_t)(0x0007)) ^= 0xFF;


*((reg_type8_t)(0x000B)) &= (~0x04);
}
void timer1_interrupt_ovfRoutine(void)
{

 *((reg_type8_t)(0x0087))=0x00;
 *((reg_type8_t)(0x0007)) ^= 0xff;

*((reg_type8_t)(0x0007)) ^= 0xFF;

*((reg_type8_t)(0x000C)) &= (~0x01);
}
void timer2_interrupt_ovfRoutine(void)
{
    u8_timer2Count++;
    if(u8_timer2Count == 2)
    {
    *((reg_type8_t)(0x0087))=0x00;
    *((reg_type8_t)(0x0007)) ^= 0xff;
    u8_timer2Count=0;
    }
*((reg_type8_t)(0x000C)) &= (~0x02);

}
# 148 "Timer.c"
ERROR_STATUS Timer_Start(uint8_t Timer_CH_NO, uint16_t Timer_Count)
{
  uint8_t ret_error = 0;
  switch (Timer_CH_NO) {
    case 0:


  *((reg_type8_t)(0x0081)) = Prescaler0;





    break;

    case 1:



    *((reg_type8_t)(0x0010)) = Prescaler1;
    *((reg_type8_t)(0x0010)) |=0x01;
 *((reg_type16_t)(0x000E))=0xFFFF - Timer_Count;


    break;

    case 2:
    *((reg_type8_t)(0x0012)) |= 0x04;
    *((reg_type8_t)(0x0092)) = Timer_Count;
    break;
    default:
    ret_error += 1 +26;
    break;
  }


  return ret_error;
}
# 196 "Timer.c"
ERROR_STATUS Timer_Stop(uint8_t Timer_CH_NO)
{
  uint8_t ret_error = 0;
  switch(Timer_CH_NO)
  {
  case 0:
       *((reg_type8_t)(0x0081)) = 0xFF;
  break;
  case 1:
      *((reg_type8_t)(0x0010)) &=(~0x01);
  break;
  case 2:
      *((reg_type8_t)(0x0012)) &= (~0x04);
  break;
  default :
      ret_error +=1 +26 ;
  break;
  }

  return ret_error;
}
# 227 "Timer.c"
ERROR_STATUS Timer_GetStatus(uint8_t Timer_CH_NO, uint8_t* Data)
{
  uint8_t ret_error = 0;
  switch (Timer_CH_NO) {
    case 0:
ret_error = read_int_flag(0 ,Data);
    break;

    case 1:
ret_error = read_int_flag(1 ,Data);
    break;

    case 2:
ret_error = read_int_flag(2 ,Data);

    break;
    default:
    ret_error += 1 +26;
    break;
  }



  return ret_error;
}
# 262 "Timer.c"
ERROR_STATUS Timer_GetValue(uint8_t Timer_CH_NO, uint16_t* Data)
{
  uint8_t ret_error = 0;
  switch (Timer_CH_NO) {
    case 0:

    *Data = *((reg_type8_t)(0x0001));
    break;

    case 1:

     *Data = *((reg_type16_t)(0x000E));

    break;

    case 2:

    *Data =*((reg_type8_t)(0x0011));
    break;
    default:
    ret_error += 1 +26;
    break;
  }

  return ret_error;
}
