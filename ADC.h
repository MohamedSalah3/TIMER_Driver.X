/*
 * File:   ADC7.h
 * Author: mo
 *
 * Created on 18 ?????, 2020, 07:06 ?
 */

#ifndef ADC_H
#define	ADC_H

#include "ADC_Config.h"
#include "softwareDelay.h"




ERROR_STATUS ADC_INIT(ADC_Cfg_s *ADC_info);


uint16_t ADC_READ(void);

void adc_interrupt_routine(void);


#endif	/* ADC_H */
