#include <stdint.h>
#include "SYSTICK.h"
#include "tm4c123gh6pm.h"  // Include the header file for your specific microcontroller

//#define NVIC_ST_CTRL_COUNT      0x00010000  // Count Flag
//#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
//#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt Enable
//#define NVIC_ST_CTRL_ENABLE     0x00000001  // Enable

void SysTickDisable(void) {
    NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;  // Clear the ENABLE bit to disable SysTick
}

void SysTickEnable(void) {
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;   // Set the ENABLE bit to enable SysTick
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC;  // ENable system clock
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_INTEN;   // Enable interrupt
}

uint32_t SysTickPeriodGet(void) {
    return NVIC_ST_RELOAD_R;  // Return the current period value from the LOAD register
}

void SysTickPeriodSet(uint32_t msDelay) {
    msDelay *= (FREQUENCY / 1000);  // Convert milliseconds to ticks
    NVIC_ST_RELOAD_R = msDelay - 1;
}

uint32_t SysTickValueGet(void) {
    return NVIC_ST_CURRENT_R;  // Return the current value of the SysTick counter from the VAL register
}

uint8_t SysTick_Is_Time_out(void) {
    return (NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) != 0;  // Check if the COUNTFLAG is set
}