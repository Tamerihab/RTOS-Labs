#include <stdint.h>
//#include "SYSTICK.h"  // Include the header file containing SysTick functions
#include "DIO.h"
#include "tm4c123gh6pm.h" 
//#include "C:\ti\TivaWare_C_Series-2.2.0.295\driverlib\systick.c"
#include "C:\ti\TivaWare_C_Series-2.2.0.295\driverlib\systick.h"

int counter=0;
void blinky1(void){
      while(1){
    GPIO_PORTF_DATA_R ^= 0x04;
  }
}

void blinky2(void){
  while(1){
    GPIO_PORTF_DATA_R ^= 0x02;
  }
}

void SystickHandler(void){
  counter++;
}



int main(void) {
    // Initialize your system, set up GPIO, etc.
    DIO_Init('F');
    // Configure the red LED pin as an output
    GPIO_PORTF_DIR_R |= 0x0E;
    GPIO_PORTF_DEN_R |= 0x0E;
    __asm("CPSIE  i");
    SysTickDisable();
    SysTickIntEnable();
    SysTickEnable();
    SysTickPeriodSet(800000-1);
    blinky2();
    blinky1();
    while (1) {

    }
}