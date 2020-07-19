#include "Timer.h"
#include "DIO.h"
/************************************************************************/
/*		         TIMER FUNCTIONS Bodies	        */
/************************************************************************/
/**
 * Input: Pointer to a structure contains the information needed to initialize the timer.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: Initiates the module.
 *
 */
static uint8_t Prescaler0 = EIGHT_BIT_FULL;
static uint8_t Prescaler1 = ZERO;

static uint8_t u8_timer2Count = 0;

ERROR_STATUS Timer_Init(Timer_cfg_s* Timer_cfg)
{
uint8_t ret_error = E_OK;

switch (Timer_cfg->Timer_CH_NO)
{
  case TIMER_CH0:
    Prescaler0 &= (Timer_cfg -> Timer_Mode);
        switch (Timer_cfg->Timer_Polling_Or_Interrupt)
        {
        case TIMER0_INTERRUPT_MODE :
           ret_error =special_int_enable(TIMR0);
           TIMER0OVF_INT = ( Timer_cfg -> Timer_Cbk_ptr);
            break;
            case TIMER0_POOLING_MODE:
            ret_error =special_int_disable(TIMR0);
            break;
            default:
            ret_error += E_NOK+INVALID_INT_POL_MODE;
            break;
        }
  break;
  case TIMER_CH1:
    switch (Timer_cfg->Timer_Mode)
    {
      case TIMER_MODE:
        Prescaler1 |= (Timer_cfg -> Timer_Prescaler)|TIMER1_MODE_INTERNAL;
        switch (Timer_cfg->Timer_Polling_Or_Interrupt)
          {
            case TIMER1_INTERRUPT_MODE:
                ret_error = special_int_enable(TIMR1);
                TIMER1OVF_INT = ( Timer_cfg -> Timer_Cbk_ptr);
            break;
            case TIMER1_POOLING_MODE:
                ret_error = special_int_disable(TIMR1);
            break;
            default:
            ret_error += E_NOK+INVALID_INT_POL_MODE;
            break;
          }
      break;
      case COUNTER_MODE:
      Prescaler1 |= (Timer_cfg -> Timer_Prescaler);
        switch (Timer_cfg->Timer_Polling_Or_Interrupt)
          {
            case TIMER1_INTERRUPT_MODE:
            ret_error = special_int_enable(TIMR1);
            TIMER1OVF_INT = ( Timer_cfg -> Timer_Cbk_ptr);
            break;
            case TIMER1_POOLING_MODE:
            ret_error = special_int_disable(TIMR1);
            break;
            default:
            ret_error += E_NOK+INVALID_INT_POL_MODE;
            break;
          }
      break;
      default:
      ret_error += E_NOK+INVALID_TIMER_MODE;
      break;
    }

  break;
  case TIMER_CH2:
          TIMER2_CONTROL_REGISTER |= (Timer_cfg -> Timer_Prescaler);
        switch (Timer_cfg->Timer_Polling_Or_Interrupt)
          {
            case TIMER2_INTERRUPT_MODE:
                ret_error =special_int_enable(TIMR2);
                TIMER2OVF_INT = ( Timer_cfg -> Timer_Cbk_ptr);

            break;
            case TIMER2_POOLING_MODE:
                ret_error =special_int_disable(TIMR2);
            break;
            default:
            ret_error += E_NOK+INVALID_INT_POL_MODE;
            break;
          }
  break;
  default:
  ret_error += E_NOK+INVALID_TIMER_CHANNEL;
  break;
}

return ret_error;
}


void timer0_interrupt_ovfRoutine(void)
{    PORTC_DIR=0x00;
ADCON0 |=GO_DONE;
PORTC_DATA ^= EIGHT_BIT_FULL;
//clear_int_flag(TIMR0);
/**clear flag fun*/
INTCON &= (~TMR0IF);
}
void timer1_interrupt_ovfRoutine(void)
{

 PORTC_DIR=0x00;
 PORTC_DATA ^= 0xff;
 //ADCON0 |=GO_DONE;
PORTC_DATA ^= EIGHT_BIT_FULL;
//clear_int_flag(TIMR1);
PIR1 &= (~TMR1IF);
}
void timer2_interrupt_ovfRoutine(void)
{
    u8_timer2Count++;
    if(u8_timer2Count == 2)
    {
    PORTC_DIR=0x00;
    PORTC_DATA ^= 0xff;
    u8_timer2Count=0;
    }
PIR1 &= (~TMR2IF);
//clear_int_flag(TIMR2);
}
/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to be started.
 *	Timer_Count: The start value of the timer.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function strats the needed timer.
 *
 */
ERROR_STATUS Timer_Start(uint8_t Timer_CH_NO, uint16_t Timer_Count)
{
  uint8_t ret_error = E_OK;
  switch (Timer_CH_NO) {
    case TIMER_CH0:
    /*assign Prescaler*/
    /*Assign count*/
  OPTION_REG = Prescaler0;
/*if bigger than 255 calculate the required ovfs to accomplish that */
//TIMER0 = EIGHT_BIT_FULL - Timer_Count;
/*if pooling make a counter to count the number of overflows*/
/*if interrupt use the same counter used when pooling to count the number of overflows*/

    break;

    case TIMER_CH1:
    /*Make it on*/
    /*assign Prescaler*/

    TIMER1_CONTROL_REGISTER = Prescaler1;
    TIMER1_CONTROL_REGISTER |=TIMER1_ON;
 TIMER1=SIXTEEN_BIT_FULL - Timer_Count;

    /*Assign count*/
    break;

    case TIMER_CH2:
    TIMER2_CONTROL_REGISTER |= TIMER2_START;
    TIMER2_PERIOD_REG = Timer_Count;
    break;
    default:
    ret_error += E_NOK+INVALID_TIMER_CHANNEL;
    break;
  }


  return ret_error;
}

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to be stopped.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function stops the needed timer.
 *
 */
ERROR_STATUS Timer_Stop(uint8_t Timer_CH_NO)
{
  uint8_t ret_error = E_OK;
  switch(Timer_CH_NO)
  {
  case TIMER_CH0:
       OPTION_REG = EIGHT_BIT_FULL;
  break;
  case TIMER_CH1:
      TIMER1_CONTROL_REGISTER &=(~TIMER1_ON);
  break;
  case TIMER_CH2:
      TIMER2_CONTROL_REGISTER &= (~TIMER2_START);
  break;
  default :
      ret_error +=E_NOK+INVALID_TIMER_CHANNEL ;
  break;
  }

  return ret_error;
}
/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its status.
 * Output:
 * 	Data: A variable of type bool returns if the flag of the timer is raised or not.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return if the flag of the timer is raised or not.
 *
 */
ERROR_STATUS Timer_GetStatus(uint8_t Timer_CH_NO, uint8_t* Data)
{
  uint8_t ret_error = E_OK;
  switch (Timer_CH_NO) {
    case TIMER_CH0:
ret_error = read_int_flag(TIMR0 ,Data);
    break;

    case TIMER_CH1:
ret_error = read_int_flag(TIMR1 ,Data);
    break;

    case TIMER_CH2:
ret_error = read_int_flag(TIMR2 ,Data);

    break;
    default:
    ret_error += E_NOK+INVALID_TIMER_CHANNEL;
    break;
  }



  return ret_error;
}
/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its value.
 * Output:
 * 	Data: This is the output variable of the function which holds the value of the timer.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return the value of the timer.
 *
 */
ERROR_STATUS Timer_GetValue(uint8_t Timer_CH_NO, uint16_t* Data)
{
  uint8_t ret_error = E_OK;
  switch (Timer_CH_NO) {
    case TIMER_CH0:
    /**timer0 count*/
    *Data = TIMER0;
    break;

    case TIMER_CH1:
     /**timer1 count*/
     *Data = TIMER1;

    break;

    case TIMER_CH2:
    /**timer2 count*/
    *Data =TIMER2;
    break;
    default:
    ret_error += E_NOK+INVALID_TIMER_CHANNEL;
    break;
  }

  return ret_error;
}
