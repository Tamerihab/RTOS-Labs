#include <stdint.h>
#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"

void DIO_Init(char port) {
    switch (port)
    {
    case 'A':
     // Enable the clock for PortA
    SYSCTL_RCGCGPIO_R |= 0x00000001;
    // Wait until PortA is enabled
    while ((SYSCTL_PRGPIO_R & 0x00000001) == 0);
    // Unlock GPIO Port A (if required for certain configurations)
    GPIO_PORTA_LOCK_R = 0x4C4F434B;
    // Allow changes for selected pins (if required for certain configurations)
    GPIO_PORTA_CR_R = 0x1F;
    // Set pins as output (LEDs on pins 1, 2, and 3)
    GPIO_PORTA_DIR_R = 0xE0;
    // Set pins as input (buttons on pins 0 and 4)
    GPIO_PORTA_PUR_R = 0x11;
    // Enable digital functionality (LEDs and buttons)
    GPIO_PORTA_DEN_R = 0xE0;
        break;
    case 'B':
     // Enable the clock for PortB
    SYSCTL_RCGCGPIO_R |= 0x00000002;
    // Wait until PortB is enabled
    while ((SYSCTL_PRGPIO_R & 0x00000002) == 0);
    // Unlock GPIO Port B (if required for certain configurations)
    GPIO_PORTB_LOCK_R = 0x4C4F434B;
    // Allow changes for selected pins (if required for certain configurations)
    GPIO_PORTB_CR_R = 0x1F;
    // Set pins as output (LEDs on pins 1, 2, and 3)
    GPIO_PORTB_DIR_R = 0xFF;
    // Set pins as input (buttons on pins 0 and 4)
    GPIO_PORTB_PUR_R = 0x11;
    // Enable digital functionality (LEDs and buttons)
    GPIO_PORTB_DEN_R = 0xFF;
    case 'C':
     // Enable the clock for PortC
    SYSCTL_RCGCGPIO_R |= 0x00000004;
    // Wait until PortC is enabled
    while ((SYSCTL_PRGPIO_R & 0x00000004) == 0);
    // Unlock GPIO PortC (if required for certain configurations)
    GPIO_PORTC_LOCK_R = 0x4C4F434B;
    // Allow changes for selected pins (if required for certain configurations)
    GPIO_PORTC_CR_R = 0x1F;
    // Set pins as output (LEDs on pins 1, 2, and 3)
    GPIO_PORTC_DIR_R = 0x0E;
    // Set pins as input (buttons on pins 0 and 4)
    GPIO_PORTC_PUR_R = 0x11;
    // Enable digital functionality (LEDs and buttons)
    GPIO_PORTC_DEN_R = 0x1F;
    case 'D':
     // Enable the clock for PortD
    SYSCTL_RCGCGPIO_R |= 0x00000008;
    // Wait until PortD is enabled
    while ((SYSCTL_PRGPIO_R & 0x00000008) == 0);
    // Unlock GPIO Port D (if required for certain configurations)
    GPIO_PORTD_LOCK_R = 0x4C4F434B;
    // Allow changes for selected pins (if required for certain configurations)
    GPIO_PORTD_CR_R = 0x1F;
    // Set pins as output (LEDs on pins 1, 2, and 3)
    GPIO_PORTD_DIR_R = 0x0E;
    // Set pins as input (buttons on pins 0 and 4)
    GPIO_PORTD_PUR_R = 0x11;
    // Enable digital functionality (LEDs and buttons)
    GPIO_PORTD_DEN_R = 0x1F;
    case 'E':
     // Enable the clock for PortE
    SYSCTL_RCGCGPIO_R |= 0x00000010;
    // Wait until PortE is enabled
    while ((SYSCTL_PRGPIO_R & 0x00000010) == 0);
    // Unlock GPIO Port E (if required for certain configurations)
    GPIO_PORTE_LOCK_R = 0x4C4F434B;
    // Allow changes for selected pins (if required for certain configurations)
    GPIO_PORTE_CR_R = 0x1F;
    // Set pins as output (LEDs on pins 1, 2, and 3)
    GPIO_PORTE_DIR_R = 0x0E;
    // Set pins as input (buttons on pins 0 and 4)
    GPIO_PORTE_PUR_R = 0x11;
    // Enable digital functionality (LEDs and buttons)
    GPIO_PORTE_DEN_R = 0x1F;
    case 'F':
     // Enable the clock for PortF
    SYSCTL_RCGCGPIO_R |= 0x00000020;
    // Wait until PortF is enabled
    while ((SYSCTL_PRGPIO_R & 0x00000020) == 0);
    // Unlock GPIO Port F (if required for certain configurations)
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    // Allow changes for selected pins (if required for certain configurations)
    GPIO_PORTF_CR_R = 0x1F;
    // Set pins as output (LEDs on pins 1, 2, and 3)
    GPIO_PORTF_DIR_R = 0x0E;
    // Set pins as input (buttons on pins 0 and 4)
    GPIO_PORTF_PUR_R = 0x11;
    // Enable digital functionality (LEDs and buttons)
    GPIO_PORTF_DEN_R = 0x1F;                    

    break;
    }


}

void DIO_WritePin(char port, uint8_t pin_num, uint8_t value) {
    switch (port)
    {
    case 'A':
        if (value == 1) {
        Set_Bit(GPIO_PORTA_DATA_R, pin_num);
        } else {
        Clear_Bit(GPIO_PORTA_DATA_R, pin_num);
        }
        break;
    
    case 'B':
        if (value == 1) {
        Set_Bit(GPIO_PORTB_DATA_R, pin_num);
        } else {
        Clear_Bit(GPIO_PORTB_DATA_R, pin_num);
        }
        break;
    
    case 'C':
        if (value == 1) {
        Set_Bit(GPIO_PORTC_DATA_R, pin_num);
    } else {
        Clear_Bit(GPIO_PORTC_DATA_R, pin_num);
    }
        break;
    
    case 'D':
        if (value == 1) {
        Set_Bit(GPIO_PORTD_DATA_R, pin_num);
    } else {
        Clear_Bit(GPIO_PORTD_DATA_R, pin_num);
    }
        break;
    
    case 'E':
        if (value == 1) {
        Set_Bit(GPIO_PORTE_DATA_R, pin_num);
    } else {
        Clear_Bit(GPIO_PORTE_DATA_R, pin_num);
    }
        break;
    
    case 'F':
        if (value == 1) {
        Set_Bit(GPIO_PORTF_DATA_R, pin_num);
    } else {
        Clear_Bit(GPIO_PORTF_DATA_R, pin_num);
    }
        break;  
    }
}

void DIO_WritePort(char port, uint32_t data){
    switch(port){
        case 'A':
            GPIO_PORTA_DATA_R = data;
            break;
        case 'B':
            GPIO_PORTB_DATA_R = data;
            break;
        case 'C':
            GPIO_PORTC_DATA_R = data;
            break;
        case 'D':
            GPIO_PORTD_DATA_R = data;
            break;
        case 'E':
            GPIO_PORTE_DATA_R = data;
            break;
        case 'F':
            GPIO_PORTF_DATA_R = data;
            break;
    }
}

void DIO_ReadPort(char port, volatile uint32_t* returnValue){
    switch (port)
    {
    case 'A':
        *returnValue = GPIO_PORTA_DATA_R;
        break;
    case 'B':
        *returnValue = GPIO_PORTB_DATA_R;
        break;
    case 'C':
        *returnValue = GPIO_PORTC_DATA_R;
        break;
    case 'D':
        *returnValue = GPIO_PORTD_DATA_R;
        break;
    case 'E':
        *returnValue = GPIO_PORTE_DATA_R;
        break;
    case 'F':
        *returnValue = GPIO_PORTF_DATA_R;
        break;
    
    }
}

void DIO_ReadPin(char port,uint8_t pin_num, volatile uint8_t* returnValue){
    switch (port)
    {
    case 'A':
        *returnValue = Get_Bit(GPIO_PORTA_DATA_R, pin_num);
        break;
    case 'B':
        *returnValue = Get_Bit(GPIO_PORTB_DATA_R,pin_num);
        break;
    case 'C':
        *returnValue = Get_Bit(GPIO_PORTC_DATA_R,pin_num);
        break;
    case 'D':
        *returnValue = Get_Bit(GPIO_PORTD_DATA_R,pin_num);
        break;
    case 'E':
        *returnValue = Get_Bit(GPIO_PORTE_DATA_R,pin_num);
        break;
    case 'F':
        *returnValue = Get_Bit(GPIO_PORTF_DATA_R,pin_num);
        break;
    }

}


