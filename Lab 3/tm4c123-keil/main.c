#include <stdint.h>
#include "scheduler.h"
#include "bsp.h"

void main_blinky1() {
       BSP_ledGreenToggle();
}

void main_blinky2() {
       BSP_ledRedToggle();
}

void main_blinky3() {
				BSP_ledBlueToggle();
}

int main(void) {
    BSP_init();
//    OS_init();

    /* start blinky1 thread */
    create_task(main_blinky1, 5);
		create_task(main_blinky2, 10);
		create_task(main_blinky3, 20);
		Tasks_Scheduler();



    
		while(1){}
    //return 0;
}
