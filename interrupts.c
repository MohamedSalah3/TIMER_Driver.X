#include "interrupts.h"
//#include "Timer.h"

static uint8_t u8global_int_enabled = 0;
static uint8_t u8prepheral_int_enabled = 0;
ptr_to_Fun TIMER0OVF_INT ;
ptr_to_Fun TIMER1OVF_INT ;
ptr_to_Fun TIMER2OVF_INT ;
ptr_to_Fun ADC_INT ;

void __interrupt () checkmyisr(void)
{
if((INTCON & TMR0IF )&&(INTCON & TMR0IE))
{
// timer0_interrupt_ovfRoutine();
TIMER0OVF_INT();
}
if((PIR1 & TMR1IF )&&(PIE1 & TMR1IE))
{
// timer0_interrupt_ovfRoutine();
TIMER1OVF_INT();
}
if((PIR1  & TMR2IF )&&(PIE1 & TMR2IE))
{
// timer0_interrupt_ovfRoutine();
TIMER2OVF_INT();
}
if((PIR1 & ADIF )&&(PIE1 & ADIE))
{
// timer0_interrupt_ovfRoutine();
ADC_INT();
}

}
ERROR_STATUS special_int_enable(uint8_t u8_interrupt_prepherals)
{
    uint8_t ret_error = 0;
switch (u8_interrupt_prepherals) {
	case TIMR0:
	INTCON |=TIMER0_INTERRUPT_MODE;
        if(u8global_int_enabled == 0)
        INTCON |=GLOBAL_INTERRUPT_ENABLE;
        u8global_int_enabled=1;
	break;
	case TIMR1 :
   global_int_enable();
              PIE1 |= TIMER1_INTERRUPT_MODE;
        if(u8prepheral_int_enabled == 0)
        INTCON |= PEIE;
            u8prepheral_int_enabled=1;

        /*enable preheral interrupt*/
        /*enable Timer1 interrupt*/
	break;
	case TIMR2:
  global_int_enable();
         /*enable preheral interrupt*/
         if(u8prepheral_int_enabled == 0)
        INTCON |= PEIE;
         u8prepheral_int_enabled=1;
        /*enable Timer2 interrupt*/
      PIE1 |= TIMER2_INTERRUPT_MODE;

	break;
	case EXTERNAL_INTERRUPT :
     global_int_enable();
         /*enable preheral interrupt*/
                 if(u8prepheral_int_enabled == 0)
        INTCON |= PEIE;
         u8prepheral_int_enabled=1;
        /*enable EXT interrupt*/
	break;
  case ADC_INTERRUPT:
  global_int_enable();

      /*enable preheral interrupt*/
      if(u8prepheral_int_enabled == 0)
     INTCON |= PEIE;
      u8prepheral_int_enabled=1;
      /*Enable ADC interrupt*/
      PIE1 |= ADIE;
  break;
default :
    ret_error += E_NOK + INVALID_ARG;

}
return ret_error;
}
ERROR_STATUS special_int_disable(uint8_t u8_interrupt_prepherals)
{    uint8_t ret_error = E_OK;

    switch (u8_interrupt_prepherals) {
	case TIMR0:
	INTCON &= TIMER0_POOLING_MODE;
	break;
	case TIMR1 :
        PIE1 &= TIMER1_POOLING_MODE;
	break;
	case TIMR2:
        PIE1 &= TIMER2_POOLING_MODE;
	break;
	case EXTERNAL_INTERRUPT :
	break;
        case ADC_INTERRUPT:
        PIE1 &= (~ADIE);
        default:
    ret_error += E_NOK + INVALID_ARG;
    break;

}
return ret_error;

}

ERROR_STATUS read_int_flag(uint8_t u8_interrupt_prepherals ,uint8_t * ptr_to_flag)
{
    uint8_t ret_error = E_OK;
switch (u8_interrupt_prepherals) {
	case TIMR0:
        *ptr_to_flag = READBIT(INTCON,TMR0IF);
        break;
	case TIMR1 :
        *ptr_to_flag = READBIT(PIR1,TMR1IF);
	break;
	case TIMR2:
        *ptr_to_flag = READBIT(PIR1,TMR2IF);
	break;
	case EXTERNAL_INTERRUPT :
	break;
        case ADC_INTERRUPT :
 //       *ptr_to_flag =  READBIT(PIR1,ADIF);
         *ptr_to_flag = PIR1 & ADIF;
        break;
default:
    ret_error += E_NOK + INVALID_ARG;
    break;

}

return ret_error;
}
ERROR_STATUS clear_int_flag(uint8_t u8_interrupt_prepherals)
{
    uint8_t ret_error = E_OK;
switch (u8_interrupt_prepherals) {
	case TIMR0:
       CLEAR_BIT(INTCON,TMR0IF);
        break;
	case TIMR1 :
      CLEAR_BIT(PIR1,TMR1IF);
	break;
	case TIMR2:
      CLEAR_BIT(PIR1,TMR2IF);
	break;
	case EXTERNAL_INTERRUPT :
	break;
case ADC_INTERRUPT:
//         CLEAR_BIT(PIR1,ADIF);
PIR1 &= (~ADIF);
        break;
default:
    ret_error += E_NOK + INVALID_ARG;
    break;

}

return ret_error;
}
void global_int_enable(void)
{
if(u8global_int_enabled == 0)
     INTCON |=GLOBAL_INTERRUPT_ENABLE;
     u8global_int_enabled=1;
}
void global_int_disable(void)
{
u8global_int_enabled = 0;
INTCON &= GLOBAL_INTERRUPT_DISABLE;
}
