//
// Created by Administrator on 2020/8/11.
//

#ifndef PRINTER_SPI_H
#define PRINTER_SPI_H

#include "sys.h"

extern SPI_HandleTypeDef hspi1;

void MX_SPI1_Init(void);
void SPI1_SetSpeed(uint8_t SPI_BaudRatePrescaler);
uint8_t SPI1_ReadWriteByte(uint8_t TxData);

#endif //PRINTER_SPI_H

