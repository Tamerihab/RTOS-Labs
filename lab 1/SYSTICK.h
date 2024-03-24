#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

#include "tm4c123gh6pm.h"

#define FREQUENCY 16000000

void SysTickDisable(void);
void SysTickEnable(void);
void SysTickInterruptDisable(void);
uint32_t SysTickPeriodGet(void);
void SysTickPeriodSet(uint32_t msDelay);
uint32_t SysTickValueGet(void);
uint8_t SysTick_Is_Time_out(void);

#endif  // SYSTICK_H