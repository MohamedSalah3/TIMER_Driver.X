# 1 "pushButton.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "pushButton.c" 2
# 1 "./pushButton.h" 1
# 11 "./pushButton.h"
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
# 11 "./pushButton.h" 2

# 1 "./pushButtonConfig.h" 1
# 12 "./pushButton.h" 2


typedef enum En_buttonId_t{
 BTN_0,
 BTN_1,
 BTN_2,
 BTN_3
}En_buttonId_t;

typedef enum En_buttonStatus_t{
 Released,
 Pressed,

}En_buttonStatus_t;







extern void pushButtonInit(En_buttonId_t en_butotn_id);





void pushButtonUpdate(void);





En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id);



extern void check_button(void);
# 1 "pushButton.c" 2
# 23 "pushButton.c"
En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id)
{
 static uint8_t u8_Button_press[3];
static uint8_t u8_S_button_status[3];
switch(en_butotn_id)
{
case BTN_0:
{
    DIO_Read(2,0x10,&(u8_Button_press[0]));
if( u8_Button_press[0]== Pressed)
{
 (u8_S_button_status[0])++;



 if( (u8_S_button_status[0]) > 50)
 return Pressed;
 else {return Released;}
}else{return Released;}
break;
}
case BTN_1:
{
    DIO_Read(1,0x04,&(u8_Button_press[1]));
if( u8_Button_press[1] == Pressed)
{
 (u8_S_button_status[0])++;



 if( (u8_S_button_status[0]) > 50)
return Pressed;
 else {return Released;}
}else{return Released;}
break;
}
case BTN_2:
{
    DIO_Read(0,0x04,&(u8_Button_press[2]));
if((u8_Button_press[2])== Pressed)
{ (u8_S_button_status[1])++;



 if( (u8_S_button_status[1]) > 20)
 return Pressed;
else {return Released;}
}else{return Released;}
break;
}



 }


}
