
#ifndef __SysTick__
#define __SysTick__
#include <stdint.h>
//*****************************************************************************
//
// Define the SystTick functions
//
//*****************************************************************************
extern uint32_t volatile counter;
extern uint32_t volatile flag;

void SysTick_Setup_Second (void);
void SysTick_Init (void);
void Delay_100ms (uint32_t delay);


#endif
