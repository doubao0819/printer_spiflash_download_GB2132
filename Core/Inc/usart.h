//
// Created by Administrator on 2020/8/12.
//

#ifndef PRINTER_USART_H
#define PRINTER_USART_H

#include "main.h"

#define RXBUFFERSIZE 1

extern uint8_t spi_flash_err;
extern uint8_t RxBuff[128];
extern uint8_t aRxBuffer[RXBUFFERSIZE];
void MX_USART1_UART_Init(void);
#endif //PRINTER_USART_H
