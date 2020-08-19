#include <limits.h>
//
// Created by Administrator on 2020/8/11.
//

#ifndef PRINTER_JX_2R_01_H
#define PRINTER_JX_2R_01_H
#include "main.h"


extern uint8_t paper_flag;
extern  void MX_GPIO_Init(void);
void CLK_PutVal(GPIO_PinState PinState);
void DI_PutVal(GPIO_PinState PinState);
void nLAT_PutVal(GPIO_PinState PinState);
void STB1_PutVal(GPIO_PinState PinState);
void STB2_PutVal(GPIO_PinState PinState);
void STB3_PutVal(GPIO_PinState PinState);
void STB4_PutVal(GPIO_PinState PinState);
void STB5_PutVal(GPIO_PinState PinState);
void STB6_PutVal(GPIO_PinState PinState);

uint8_t PHK_GetVal(void);
void runmotor(unsigned int nsteps);
void OneStep(void);
void OneStep_NoDelay(void);
void ThermalHeadInit(void);
void Refesh_LED(void);

#endif //PRINTER_JX_2R_01_H
