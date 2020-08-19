/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "sys.h"
#include "delay.h"
#include "w25qxx.h"
#include "JX_2R_01.h"
#include "usart.h"
uint8_t  spi_flash_err = 0;
extern uint32_t FLASH_WriteAddress;


#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_USART1_UART_Init();
    W25QXX_Init();
    MX_GPIO_Init();
    delay_init(72);
    delay_ms(800);
    ThermalHeadInit();

    W25QXX_TYPE=W25QXX_ReadID();	        //¶ÁÈ¡FLASH ID.
    if(W25QXX_TYPE == W25Q128)                //SPI FLASHÎªW25Q128
    {
        W25QXX_Erase_Chip();
        spi_flash_err = 0;
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
    }
    else
    {
        spi_flash_err = 1;
    }

    while (1)
    {
        if( FLASH_WriteAddress >=588829)
        {
            delay_ms(500);
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            FLASH_WriteAddress=0;
        }

    }

}
#pragma clang diagnostic pop

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
