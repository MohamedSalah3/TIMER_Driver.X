#include "Timer_Config.h"
#include "Timer.h"
Timer_cfg_s Timer_Configuration0 =
{
TIMER_CH0,
TIMER0_PRESCALER_256_TIMER_MODE,
TIMER0_INTERRUPT_MODE,
0,
 timer0_interrupt_ovfRoutine};
Timer_cfg_s Timer_Configuration1=
{
    TIMER_CH1,
    TIMER_MODE,
    TIMER1_INTERRUPT_MODE,
    TIMER1_PRESCALER_8,
    timer1_interrupt_ovfRoutine
};
Timer_cfg_s Timer_Configuration2={    TIMER_CH2,
    TIMER_MODE,
    TIMER2_INTERRUPT_MODE,
    TIMER2_PRESCALER_4,
    timer2_interrupt_ovfRoutine};
Timer_cfg_s Timer_Deinit_Configuration0;
Timer_cfg_s Timer_Deinit_Configuration1;
Timer_cfg_s Timer_Deinit_Configuration2;
