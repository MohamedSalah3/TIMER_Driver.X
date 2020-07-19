#include "ADC.h"

static uint16_t u16_result_data = 0;
ERROR_STATUS ADC_INIT(ADC_Cfg_s *ADC_info)
{
    uint8_t ret_error=E_OK;

    if((ADC_info -> u8_Prescaler ) <= PRESCALERFRC1)
    {
        ADCON0 |= (ADC_info -> u8_Channel_Number)|(ADC_info -> clock_configuration )|ADC_ON;
        ADCON1 &= (~ADCS2);
        ADCON1 |=(ADC_info -> u8_ten_bit_arrangment);
    }else if(((ADC_info -> u8_Prescaler ) > PRESCALERFRC1 )
            &&((ADC_info -> u8_Prescaler ) <= PRESCALERFRC2))
  {
         ADCON0 |= (ADC_info -> u8_Channel_Number)|(ADC_info -> clock_configuration )|ADC_ON;
      ADCON1 |= ADCS2 | (ADC_info -> u8_ten_bit_arrangment);

         }else{ret_error += E_NOK + INVALID_ADC_PARM;}

    switch(ADC_info -> u8_polling_interrupt)
    {
    case ADC_INTERRUPT:
        ret_error=special_int_enable(ADC_INTERRUPT);
      ADC_INT = adc_interrupt_routine;
        break;
    case ADC_POLLING:
        special_int_disable(ADC_INTERRUPT);

    break;

    }


    return ret_error;
}


uint16_t ADC_READ(void)
{
SwDelay_ms(2);
/*delay 2ms*/
    ADCON0 &= CH_SELECT_BIT_CLR; // Clear The Channel Selection Bits
    ADCON0 |= ADC0;     // Select The Required Channel (ANC)
                          // Wait The Aquisition Time
SwDelay_us(30);       // The Minimum Tacq = 20us, So That should be enough
ADCON0 |=GO_DONE ;          // Start A/D Conversion
    while(READBIT(ADCON0,GO_DONE)); // Polling GO_DONE Bit

return ((ADC_RESULTHIGH << 8) + ADC_RESULTLOW); // Return The Right-Justified 10-
}

void adc_interrupt_routine(void)
{
u16_result_data=((ADC_RESULTHIGH<<8)+ADC_RESULTLOW);
clear_int_flag(ADC_INTERRUPT);
}
