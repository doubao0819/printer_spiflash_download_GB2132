//
// Created by Administrator on 2020/8/12.
//

#include "usart.h"
#include "w25qxx.h"

UART_HandleTypeDef huart1;

uint32_t FLASH_WriteAddress = 0x00000;

uint8_t aRxBuffer[RXBUFFERSIZE];
uint8_t RxBuff[128];
uint16_t uartCounts = 0;
uint8_t Spi_Rx_Buffer[RXBUFFERSIZE];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance==USART1)//如果是串口1
    {
        if( spi_flash_err != 1)
        {
            W25QXX_Write_NoCheck(aRxBuffer,FLASH_WriteAddress,RXBUFFERSIZE);
            W25QXX_Read(Spi_Rx_Buffer,FLASH_WriteAddress,RXBUFFERSIZE);

            if(Spi_Rx_Buffer[0] == aRxBuffer[0] )
            {

                FLASH_WriteAddress++;
            }
            else
            {
                FLASH_WriteAddress = 0;
                //擦除flash
                W25QXX_Erase_Chip();
                spi_flash_err = 1;
            }
        }

    }
}





/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART1_UART_Init(void)
{
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 9600;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }

    HAL_UART_Receive_IT(&huart1, (uint8_t *)RxBuff, RXBUFFERSIZE);//该函数会开启接收中断：标志位UART_IT_RXNE，并且设置接收缓冲以及接收缓冲接收最大数据量

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */

void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */

    /* USER CODE END Error_Handler_Debug */
}
