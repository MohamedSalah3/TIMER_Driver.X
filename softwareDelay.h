/*
 * File:   softwareDelay.h
 * Author: mo
 *
 * Created on 19 ?????, 2020, 11:20 ?
 */

#ifndef SOFTWAREDELAY_H
#define	SOFTWAREDELAY_H
#include "std_types.h"
/**
 * Description: this delay function operate in a polling manner
 * 				don't use it with RTOSs
 * @param n: the milli-seconds
 */
void SwDelay_ms(uint32_t n);

/**
 * Description: this delay function operate in a polling manner
 * 				don't use it with RTOSs
 * @param n: the micro-seconds
 */
void SwDelay_us(uint32_t n);

#endif
