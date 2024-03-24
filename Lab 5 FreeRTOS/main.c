#include <stdint.h>
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include "tm4c123gh6pm.h"

// Define LED bit positions for PortF
static const uint8_t LED_RED  = 0x02;  // Bit position for RED LED
static const uint8_t LED_BLUE  = 0x04;  // Bit position for BLUE LED
static const uint8_t LED_GREEN  = 0x08;  // Bit position for GREEN LED

// Function prototypes
void init();
void toggleRedLED(void *pvParameters);
void toggleBlueLED(void *pvParameters);
void toggleGreenLED(void *pvParameters);


void init()
{
	SYSCTL_RCGCGPIO_R |= 0x00000020;
  while((SYSCTL_PRGPIO_R&0x00000020) == 0){};
  GPIO_PORTF_LOCK_R = 0x4C4F434B;
  GPIO_PORTF_CR_R = 0x1F;
  GPIO_PORTF_DIR_R = 0x0E;
  GPIO_PORTF_PUR_R = 0x11;
  GPIO_PORTF_DEN_R = 0x1F;
}




int main() {
    // Initialize hardware peripherals and FreeRTOS

	   init();
    // Create tasks
    xTaskCreate(toggleRedLED, "RedTask", configMINIMAL_STACK_SIZE,(void *) &LED_RED, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(toggleBlueLED, "BlueTask", configMINIMAL_STACK_SIZE, (void *) &LED_BLUE, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(toggleGreenLED, "GreenTask", configMINIMAL_STACK_SIZE, (void *) &LED_GREEN, tskIDLE_PRIORITY + 1, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    // Should not reach here
    for(;;);
    /*while (1) {
        // Handle errors or perform other tasks
    }

    return 0;*/
}

void toggleRedLED(void *pvParameters) {
		int *LedColor;
		LedColor= (int *)pvParameters;
    for (;;) {
        GPIO_PORTF_DATA_R ^= *LedColor;  // Toggle RED LED
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay 1000ms (1 second)
    }
}

void toggleBlueLED(void *pvParameters) {
		int *LedColor;
		LedColor= (int *)pvParameters;
    for (;;) {
        GPIO_PORTF_DATA_R ^= *LedColor;  // Toggle BLUE LED
        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay 2000ms (2 seconds)
    }
}

void toggleGreenLED(void *pvParameters) {
	int *LedColor;
	LedColor= (int *)pvParameters;
    for (;;) {
        GPIO_PORTF_DATA_R ^= *LedColor;  // Toggle GREEN LED
        vTaskDelay(pdMS_TO_TICKS(3000)); // Delay 3000ms (3 seconds)
    }
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






