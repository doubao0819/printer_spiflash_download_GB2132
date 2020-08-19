#include <limits.h>
//
// Created by Administrator on 2020/8/11.
//

#include "JX_2R_01.h"
#include "delay.h"


/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();


    /*Configure GPIO pins : M_T102_DAT_Pin M_T102_CLK_Pin M_T102_LAT_Pin PHE_TO_LINUX_Pin */
    GPIO_InitStruct.Pin = M_T102_DI_Pin|M_T102_CLK_Pin|M_T102_nLAT_Pin|PHE_TO_LINUX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /*Configure GPIO pin : led_Pin */
    GPIO_InitStruct.Pin = LED_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pins : M_T102_MA_0_Pin M_T102_MA_1_Pin M_T102_MB_0_Pin M_T102_MB_1_Pin
                             M_T102_DST6_Pin M_T102_DST5_Pin M_T102_DST4_Pin M_T102_DST3_Pin
                             M_T102_DST2_Pin M_T102_DST1_Pin */
    GPIO_InitStruct.Pin = M_T102_MA_0_Pin|M_T102_MA_1_Pin|M_T102_MB_0_Pin|M_T102_MB_1_Pin
                          |M_T102_DST6_Pin|M_T102_DST5_Pin|M_T102_DST4_Pin|M_T102_DST3_Pin
                          |M_T102_DST2_Pin|M_T102_DST1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pin : M_T102_PHE_Pin */
    GPIO_InitStruct.Pin = M_T102_PHE_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(M_T102_PHE_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOC, PHE_TO_LINUX_Pin, GPIO_PIN_SET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOB, M_T102_MA_0_Pin|M_T102_MA_1_Pin|M_T102_MB_0_Pin|M_T102_MB_1_Pin, GPIO_PIN_RESET);

}

void CLK_PutVal(GPIO_PinState PinState)
{
    HAL_GPIO_WritePin(M_T102_CLK_GPIO_Port, M_T102_CLK_Pin, PinState);
}

void DI_PutVal(GPIO_PinState PinState)
{
    HAL_GPIO_WritePin(M_T102_DI_GPIO_Port, M_T102_DI_Pin, PinState);
}

void nLAT_PutVal(GPIO_PinState PinState)
{
    HAL_GPIO_WritePin(M_T102_nLAT_GPIO_Port, M_T102_nLAT_Pin, PinState);
}

void STB1_PutVal(GPIO_PinState Val)
{
    HAL_GPIO_WritePin(M_T102_DST1_GPIO_Port, M_T102_DST1_Pin, Val);
}

void STB2_PutVal(GPIO_PinState Val)
{
    HAL_GPIO_WritePin(M_T102_DST2_GPIO_Port, M_T102_DST2_Pin, Val);
}


void STB3_PutVal(GPIO_PinState Val)
{
    HAL_GPIO_WritePin(M_T102_DST3_GPIO_Port, M_T102_DST3_Pin, Val);
}

void STB4_PutVal(GPIO_PinState Val)
{
    HAL_GPIO_WritePin(M_T102_DST4_GPIO_Port, M_T102_DST4_Pin, Val);
}

void STB5_PutVal(GPIO_PinState Val)
{
    HAL_GPIO_WritePin(M_T102_DST5_GPIO_Port, M_T102_DST5_Pin, Val);
}

void STB6_PutVal(GPIO_PinState Val)
{
    HAL_GPIO_WritePin(M_T102_DST6_GPIO_Port, M_T102_DST6_Pin, Val);
}

uint8_t PHK_GetVal(void)
{
    uint8_t val;
    val = HAL_GPIO_ReadPin(M_T102_PHE_GPIO_Port,M_T102_PHE_Pin);
    if(val == GPIO_PIN_RESET)
    {
        delay_ms(500);
        val = HAL_GPIO_ReadPin(M_T102_PHE_GPIO_Port,M_T102_PHE_Pin);
        if(val == GPIO_PIN_RESET)
        {
            val = GPIO_PIN_RESET;
        }
        else
        {
            val = GPIO_PIN_SET;
        }
    }
    return val;
}

void runmotor(unsigned int nsteps)
{
    int i;
    HAL_GPIO_WritePin(M_T102_MB_1_GPIO_Port, M_T102_MB_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(M_T102_MB_0_GPIO_Port, M_T102_MB_0_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(M_T102_MA_1_GPIO_Port, M_T102_MA_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(M_T102_MA_0_GPIO_Port, M_T102_MA_0_Pin, GPIO_PIN_RESET);
    for(i = 0; i < nsteps; i++)
    {
        OneStep();
    }
    HAL_GPIO_WritePin(M_T102_MB_1_GPIO_Port, M_T102_MB_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(M_T102_MB_0_GPIO_Port, M_T102_MB_0_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(M_T102_MA_1_GPIO_Port, M_T102_MA_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(M_T102_MA_0_GPIO_Port, M_T102_MA_0_Pin, GPIO_PIN_RESET);
}

unsigned int MotorFlag = 4;
/* 电机参数已调优无需修改 */
/* STEP4--->STEP3--->STEP2->STEP1--->
   ↑ 							        					↓
   <--------------------------------- */
void OneStep_NoDelay(void)
{
    switch(MotorFlag)
    {
        case 1:
            HAL_GPIO_WritePin(M_T102_MA_1_GPIO_Port, M_T102_MA_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MB_1_GPIO_Port, M_T102_MB_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MA_0_GPIO_Port, M_T102_MA_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MB_0_GPIO_Port, M_T102_MB_0_Pin, GPIO_PIN_RESET);
            MotorFlag--;
            if(0 >= MotorFlag)
            {
                MotorFlag = 4;
            }
            break;
        case 2:
            HAL_GPIO_WritePin(M_T102_MA_1_GPIO_Port, M_T102_MA_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MB_1_GPIO_Port, M_T102_MB_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MA_0_GPIO_Port, M_T102_MA_0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MB_0_GPIO_Port, M_T102_MB_0_Pin, GPIO_PIN_RESET);
            MotorFlag--;
            if(0 >= MotorFlag)
            {
                MotorFlag = 4;
            }
            break;

        case 3:
            HAL_GPIO_WritePin(M_T102_MA_1_GPIO_Port, M_T102_MA_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MB_1_GPIO_Port, M_T102_MB_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MA_0_GPIO_Port, M_T102_MA_0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MB_0_GPIO_Port, M_T102_MB_0_Pin, GPIO_PIN_SET);
            MotorFlag--;
            if(0 >= MotorFlag)
            {
                MotorFlag = 4;
            }
            break;
        case 4:

            HAL_GPIO_WritePin(M_T102_MA_1_GPIO_Port, M_T102_MA_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MB_1_GPIO_Port, M_T102_MB_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MA_0_GPIO_Port, M_T102_MA_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MB_0_GPIO_Port, M_T102_MB_0_Pin, GPIO_PIN_SET);
            MotorFlag--;
            if(0 >= MotorFlag)
            {
                MotorFlag = 4;
            }
            break;
        default:
            MotorFlag = 4;
            break;
    }
}

void OneStep(void)
{
    switch(MotorFlag)
    {
        case 1:

////////////////////////////////step 1////////
            HAL_GPIO_WritePin(M_T102_MA_1_GPIO_Port, M_T102_MA_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MB_1_GPIO_Port, M_T102_MB_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MA_0_GPIO_Port, M_T102_MA_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MB_0_GPIO_Port, M_T102_MB_0_Pin, GPIO_PIN_RESET);
            delay_us(1350);
            MotorFlag--;
            if(0 >= MotorFlag)
            {
                MotorFlag = 4;
            }
            break;
        case 2:

////////////////////////////////step 2////////
            HAL_GPIO_WritePin(M_T102_MA_1_GPIO_Port, M_T102_MA_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MB_1_GPIO_Port, M_T102_MB_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MA_0_GPIO_Port, M_T102_MA_0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MB_0_GPIO_Port, M_T102_MB_0_Pin, GPIO_PIN_RESET);
            delay_us(1350);

            MotorFlag--;
            if(0 >= MotorFlag)
            {
                MotorFlag = 4;
            }
            break;

        case 3:

////////////////////////////////step 3////////
            HAL_GPIO_WritePin(M_T102_MA_1_GPIO_Port, M_T102_MA_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MB_1_GPIO_Port, M_T102_MB_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MA_0_GPIO_Port, M_T102_MA_0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MB_0_GPIO_Port, M_T102_MB_0_Pin, GPIO_PIN_SET);
            delay_us(1350);

            MotorFlag--;
            if(0 >= MotorFlag)
            {
                MotorFlag = 4;
            }
            break;
        case 4:

////////////////////////////////step 4////////
            HAL_GPIO_WritePin(M_T102_MA_1_GPIO_Port, M_T102_MA_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(M_T102_MB_1_GPIO_Port, M_T102_MB_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MA_0_GPIO_Port, M_T102_MA_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(M_T102_MB_0_GPIO_Port, M_T102_MB_0_Pin, GPIO_PIN_SET);
            delay_us(1350);
            MotorFlag--;
            if(0 >= MotorFlag)
            {
                MotorFlag = 4;
            }
            break;
        default:
            MotorFlag = 4;
            break;
    }
}


void ThermalHeadInit(void)
{
    STB1_PutVal(GPIO_PIN_RESET);
    STB2_PutVal(GPIO_PIN_RESET);
    STB3_PutVal(GPIO_PIN_RESET);
    STB4_PutVal(GPIO_PIN_RESET);
    STB5_PutVal(GPIO_PIN_RESET);
    STB6_PutVal(GPIO_PIN_RESET);
    CLK_PutVal(GPIO_PIN_RESET);

    nLAT_PutVal(GPIO_PIN_SET);
}

void Refesh_LED(void)
{
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    delay_ms(200);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    delay_ms(30);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    delay_ms(200);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    delay_ms(30);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    delay_ms(200);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    delay_ms(30);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    delay_ms(200);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    delay_ms(30);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    delay_ms(200);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    delay_ms(30);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    delay_ms(200);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    delay_ms(30);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    delay_ms(200);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    delay_ms(30);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    delay_ms(200);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    delay_ms(30);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    delay_ms(200);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    delay_ms(30);
}