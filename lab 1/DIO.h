#include <stdint.h>

#ifndef DIO_H
#define DIO_H

void DIO_Init(char port);
void DIO_WritePin(char port, uint8_t pin, uint8_t value);
void DIO_WritePort(char port, uint32_t data);
void DIO_ReadPort(char port, volatile uint32_t* returnValue);
void DIO_ReadPin(char port,uint8_t pin,volatile  uint8_t* returnValue);

#endif //DIO_H