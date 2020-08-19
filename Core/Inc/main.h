/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

#include "string.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define M_T102_DI_Pin GPIO_PIN_0
#define M_T102_DI_GPIO_Port GPIOC
#define M_T102_CLK_Pin GPIO_PIN_1
#define M_T102_CLK_GPIO_Port GPIOC
#define M_T102_nLAT_Pin GPIO_PIN_2
#define M_T102_nLAT_GPIO_Port GPIOC
#define PHE_TO_LINUX_Pin GPIO_PIN_3
#define PHE_TO_LINUX_GPIO_Port GPIOC
#define LED_Pin GPIO_PIN_0
#define LED_GPIO_Port GPIOA
#define M_T102_MA_0_Pin GPIO_PIN_12
#define M_T102_MA_0_GPIO_Port GPIOB
#define M_T102_MA_1_Pin GPIO_PIN_13
#define M_T102_MA_1_GPIO_Port GPIOB
#define M_T102_MB_0_Pin GPIO_PIN_14
#define M_T102_MB_0_GPIO_Port GPIOB
#define M_T102_MB_1_Pin GPIO_PIN_15
#define M_T102_MB_1_GPIO_Port GPIOB
#define M_T102_PHE_Pin GPIO_PIN_10
#define M_T102_PHE_GPIO_Port GPIOC
#define M_T102_DST6_Pin GPIO_PIN_3
#define M_T102_DST6_GPIO_Port GPIOB
#define M_T102_DST5_Pin GPIO_PIN_4
#define M_T102_DST5_GPIO_Port GPIOB
#define M_T102_DST4_Pin GPIO_PIN_5
#define M_T102_DST4_GPIO_Port GPIOB
#define M_T102_DST3_Pin GPIO_PIN_7
#define M_T102_DST3_GPIO_Port GPIOB
#define M_T102_DST2_Pin GPIO_PIN_8
#define M_T102_DST2_GPIO_Port GPIOB
#define M_T102_DST1_Pin GPIO_PIN_9
#define M_T102_DST1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
