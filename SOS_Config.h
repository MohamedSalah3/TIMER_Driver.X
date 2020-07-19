/*
 * File:   SOS_Config.h
 * Author: mo
 *
 * Created on 19 ?????, 2020, 01:52 ?
 */


 #ifndef SOS_CONFIG_H_
 #define SOS_CONFIG_H_

 #include "Timer.h"

 #define TIMER_RESOLUTION_1_MS     1
 #define NUM_OF_TICKS_FOR_1_MS	 14
 /******************************************************************************/
 typedef struct TMU_ConfigType
 {
 	uint8_t u8_resolution;
 	uint8_t u8_Timer_channel;

 }TMU_ConfigType;
 /***********************************************************************/

 extern TMU_ConfigType TMU_Configuration;


 #endif /* SOS_CONFIG_H_ */
