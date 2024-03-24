#include <stdint.h>
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>

void toggleRedLED() {
    *((volatile unsigned long *)0x400253FC) ^= 0x02;
}


void vPeriodicTask(void *pvParameters)
{
	 for (;;) {
					toggleRedLED();
					vTaskDelay(pdMS_TO_TICKS(1000)); // Delay 1000ms (1 second)
			}
}	

int main()
{

	/*BaseType_t xTaskCreate( TaskFunction_t pxTaskCode,
                            const char * const pcName,
                            const configSTACK_DEPTH_TYPE usStackDepth,
                            void * const pvParameters,
                            UBaseType_t uxPriority,
                            TaskHandle_t * const pxCreatedTask );*/

    // Create the task
    xTaskCreate(vPeriodicTask, "InfiniteTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

   
 
					for( ;; ); 


}


// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// sky blue -GB    0x0C
// white    RGB    0x0E
// pink     R-B    0x06



