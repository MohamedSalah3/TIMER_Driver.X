# 1 "DIO.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "DIO.c" 2
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
# 1 "DIO.c" 2


static uint8_t is_init = 0;







ERROR_STATUS DIO_init (DIO_Cfg_s *DIO_info)
{
uint8_t ret_error=0;
static uint8_t first_powerup_init = 0;
is_init=1;
 if (first_powerup_init == 0) {
    switch (DIO_info -> port)
    {
      case 0:
  *((reg_type8_t)(0x0085))=0x00;
      break;
      case 1:
  *((reg_type8_t)(0x0086))=0x00;
      break;
      case 2:
  *((reg_type8_t)(0x0087))=0x00;
      break;
      case 3:
  *((reg_type8_t)(0x0088))=0x00;
      break;
      case 4:
  *((reg_type8_t)(0x0089))=0x00;
      break;
  }
  first_powerup_init++;
  }
if((DIO_info -> port)== 0)
 *((reg_type8_t)(0x009F)) |=( DIO_info -> operation_mode) ;
if(DIO_info != ((void *)0)){
    switch (DIO_info -> dir)
    {
      case 0x00:
        switch (DIO_info -> port)
        {
            case 0:


           *((reg_type8_t)(0x0085)) |=(DIO_info-> pin) ;
            break;
            case 1:

                *((reg_type8_t)(0x0086)) |=(DIO_info->pin) ;
            break;
            case 2:

                *((reg_type8_t)(0x0087)) |=(DIO_info->pin) ;
            break;
            case 3:

                *((reg_type8_t)(0x0088)) |=(DIO_info->pin) ;
            break;
            case 4:

            *((reg_type8_t)(0x0089)) |=(DIO_info->pin) ;
            break;
            default:
            ret_error += 1 +14;
            break;
    }
  break;
  case 0xFF:
    switch (DIO_info -> port)
    {
      case 0:
        *((reg_type8_t)(0x0085)) &=(~(DIO_info->pin)) ;
      break;
      case 1:
        *((reg_type8_t)(0x0086)) &=(~(DIO_info->pin)) ;
      break;
      case 2:
        *((reg_type8_t)(0x0087)) &=(~(DIO_info->pin)) ;
      break;
      case 3:
        *((reg_type8_t)(0x0088)) &=(~(DIO_info->pin)) ;
      break;
      case 4:
        *((reg_type8_t)(0x0089)) &=(~(DIO_info->pin)) ;
      break;
      default:
      ret_error += 1 +14;
      break;
  }
  break;
default:
ret_error +=1 + 18;
break;
}
}else
{
ret_error +=1 +16;
}
return ret_error;
}
# 132 "DIO.c"
ERROR_STATUS DIO_Write (uint8_t GPIO, uint8_t pins, uint8_t value)
{ uint8_t ret_error=0;

  static uint8_t first_powerup = 0;
if (first_powerup == 0) {
switch (GPIO) {
  case 0:
  *((reg_type8_t)(0x0005))=0x00;
  break;
  case 1:
  *((reg_type8_t)(0x0006))=0x00;
  break;
  case 2:
  *((reg_type8_t)(0x0007))=0x00;
  break;
  case 3:
  *((reg_type8_t)(0x0008))=0x00;
  break;
  case 4:
  *((reg_type8_t)(0x0009))=0x00;
  break;
}
  first_powerup++;
}
switch (value) {
  case 0xFF:
    switch (GPIO) {
      case 0:
      *((reg_type8_t)(0x0005)) |= pins;
      break;
      case 1:
      *((reg_type8_t)(0x0006)) |= pins;
      break;
      case 2:
      *((reg_type8_t)(0x0007)) |= pins;
      break;
      case 3:
      *((reg_type8_t)(0x0008)) |= pins;
      break;
      case 4:
      *((reg_type8_t)(0x0009)) |= pins;
      break;
      default:
      ret_error +=1 +14;
      break;

    }
  break;
  case 0:
    switch (GPIO) {
      case 0:
      *((reg_type8_t)(0x0005)) &= (~pins);
      break;
      case 1:
      *((reg_type8_t)(0x0006)) &= (~pins);
      break;
      case 2:
      *((reg_type8_t)(0x0007)) &= (~pins);
      break;
      case 3:
      *((reg_type8_t)(0x0008)) &= (~pins);
      break;
      case 4:
      *((reg_type8_t)(0x0009)) &= (~pins);
      break;
      default:
      ret_error +=1 +14;
      break;

    }
  break;
  default:
ret_error +=1 +18;
  break;
}
return ret_error;
}
# 236 "DIO.c"
ERROR_STATUS DIO_Read (uint8_t GPIO,uint8_t pins, uint8_t *data)
{
  uint8_t ret_error=0;
  switch (GPIO)
   { case 0:
    *data=(*((reg_type8_t)(0x0005)) & pins);
    break;
   case 1:
    *data=(*((reg_type8_t)(0x0006)) & pins);
    break;
   case 2:
    *data=(*((reg_type8_t)(0x0007)) & pins);
    break;
   case 3:
    *data=(*((reg_type8_t)(0x0008)) & pins);
                break;
        case 4:
    *data=(*((reg_type8_t)(0x0009)) & pins);
    break;
    default:
    ret_error += 14;
    break;
   }
   if(*data > 0)
   {
    *data = 1;
   }

  return ret_error;
}
# 290 "DIO.c"
ERROR_STATUS DIO_Toggle (uint8_t GPIO, uint8_t pins)
{
    uint8_t ret_error=0;
    switch (GPIO)
     { case 0:
      *((reg_type8_t)(0x0005)) ^=(pins);
      break;
     case 1:
      *((reg_type8_t)(0x0006)) ^=(pins);
      break;
     case 2:
      *((reg_type8_t)(0x0007)) ^=(pins);
      break;
     case 3:
      *((reg_type8_t)(0x0008)) ^=(pins);
      break;
     default:
      ret_error +=14 +1;
      break;
     }
    return ret_error;
}
