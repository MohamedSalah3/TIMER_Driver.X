# 1 "software_delay.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "software_delay.c" 2


# 1 "./softwareDelay.h" 1
# 10 "./softwareDelay.h"
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
# 10 "./softwareDelay.h" 2






void SwDelay_ms(uint32_t n);






void SwDelay_us(uint32_t n);
# 3 "software_delay.c" 2







void SwDelay_ms(uint32_t n)
{
 uint8_t counter_256;
 uint8_t counter_21;
 while (n)
 {

  counter_21 = 21;
  while (counter_21)
  {

   counter_256 = 255;
   while (counter_256)
   {
    counter_256--;
   }
   counter_21--;
  }
  n--;
 }
}






void SwDelay_us(uint32_t n)
{
 while (n)
 {
  n--;
 }
}
