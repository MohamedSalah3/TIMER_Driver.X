# 1 "interrupts.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "interrupts.c" 2
# 1 "./interrupts.h" 1
# 12 "./interrupts.h"
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
# 12 "./interrupts.h" 2


# 1 "./error.h" 1
# 12 "./error.h"
typedef uint8_t ERROR_STATUS;
# 14 "./interrupts.h" 2
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
# 1 "interrupts.c" 2



static uint8_t u8global_int_enabled = 0;
static uint8_t u8prepheral_int_enabled = 0;
ptr_to_Fun TIMER0OVF_INT ;
ptr_to_Fun TIMER1OVF_INT ;
ptr_to_Fun TIMER2OVF_INT ;
ptr_to_Fun ADC_INT ;

void __attribute__((picinterrupt(("")))) checkmyisr(void)
{
if((*((reg_type8_t)(0x000B)) & 0x04 )&&(*((reg_type8_t)(0x000B)) & 0x20))
{

TIMER0OVF_INT();
}
if((*((reg_type8_t)(0x000C)) & 0x01 )&&(*((reg_type8_t)(0x008C)) & 0x01))
{

TIMER1OVF_INT();
}
if((*((reg_type8_t)(0x000C)) & 0x02 )&&(*((reg_type8_t)(0x008C)) & 0x02))
{

TIMER2OVF_INT();
}
if((*((reg_type8_t)(0x000C)) & 0x40 )&&(*((reg_type8_t)(0x008C)) & 0x40))
{

ADC_INT();
}

}
ERROR_STATUS special_int_enable(uint8_t u8_interrupt_prepherals)
{
    uint8_t ret_error = 0;
switch (u8_interrupt_prepherals) {
 case 0:
 *((reg_type8_t)(0x000B)) |=0xA0;
        if(u8global_int_enabled == 0)
        *((reg_type8_t)(0x000B)) |=0x80;
        u8global_int_enabled=1;
 break;
 case 1 :
   global_int_enable();
              *((reg_type8_t)(0x008C)) |= 0x01;
        if(u8prepheral_int_enabled == 0)
        *((reg_type8_t)(0x000B)) |= 0x40;
            u8prepheral_int_enabled=1;



 break;
 case 2:
  global_int_enable();

         if(u8prepheral_int_enabled == 0)
        *((reg_type8_t)(0x000B)) |= 0x40;
         u8prepheral_int_enabled=1;

      *((reg_type8_t)(0x008C)) |= 0x02;

 break;
 case 3 :
     global_int_enable();

                 if(u8prepheral_int_enabled == 0)
        *((reg_type8_t)(0x000B)) |= 0x40;
         u8prepheral_int_enabled=1;

 break;
  case 0x40:
  global_int_enable();


      if(u8prepheral_int_enabled == 0)
     *((reg_type8_t)(0x000B)) |= 0x40;
      u8prepheral_int_enabled=1;

      *((reg_type8_t)(0x008C)) |= 0x40;
  break;
default :
    ret_error += 1 + 28;

}
return ret_error;
}
ERROR_STATUS special_int_disable(uint8_t u8_interrupt_prepherals)
{ uint8_t ret_error = 0;

    switch (u8_interrupt_prepherals) {
 case 0:
 *((reg_type8_t)(0x000B)) &= 0xDF;
 break;
 case 1 :
        *((reg_type8_t)(0x008C)) &= 0xFE;
 break;
 case 2:
        *((reg_type8_t)(0x008C)) &= 0xFD;
 break;
 case 3 :
 break;
        case 0x40:
        *((reg_type8_t)(0x008C)) &= (~0x40);
        default:
    ret_error += 1 + 28;
    break;

}
return ret_error;

}

ERROR_STATUS read_int_flag(uint8_t u8_interrupt_prepherals ,uint8_t * ptr_to_flag)
{
    uint8_t ret_error = 0;
switch (u8_interrupt_prepherals) {
 case 0:
        *ptr_to_flag = ( (*((reg_type8_t)(0x000B)) >> 0x04) & 1 );
        break;
 case 1 :
        *ptr_to_flag = ( (*((reg_type8_t)(0x000C)) >> 0x01) & 1 );
 break;
 case 2:
        *ptr_to_flag = ( (*((reg_type8_t)(0x000C)) >> 0x02) & 1 );
 break;
 case 3 :
 break;
        case 0x40 :

         *ptr_to_flag = *((reg_type8_t)(0x000C)) & 0x40;
        break;
default:
    ret_error += 1 + 28;
    break;

}

return ret_error;
}
ERROR_STATUS clear_int_flag(uint8_t u8_interrupt_prepherals)
{
    uint8_t ret_error = 0;
switch (u8_interrupt_prepherals) {
 case 0:
       (*((reg_type8_t)(0x000B)) &=(~(1<<0x04)));
        break;
 case 1 :
      (*((reg_type8_t)(0x000C)) &=(~(1<<0x01)));
 break;
 case 2:
      (*((reg_type8_t)(0x000C)) &=(~(1<<0x02)));
 break;
 case 3 :
 break;
case 0x40:

*((reg_type8_t)(0x000C)) &= (~0x40);
        break;
default:
    ret_error += 1 + 28;
    break;

}

return ret_error;
}
void global_int_enable(void)
{
if(u8global_int_enabled == 0)
     *((reg_type8_t)(0x000B)) |=0x80;
     u8global_int_enabled=1;
}
void global_int_disable(void)
{
u8global_int_enabled = 0;
*((reg_type8_t)(0x000B)) &= 0x7f;
}
