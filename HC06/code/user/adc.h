/*********************************************
*�ļ�����adc.h                            **
*���ܣ�ADC������ز���ͷ�ļ�				**
*���ߣ�czz                                  **
*�޸ļ�¼��									**						
		2016\10\22		����				**
*********************************************/

#ifndef ADC_H
#define ADC_H

/********************************************/

/**************������ͷ�ļ�******************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stm32f10x.h"


/************* ������������ *************/

void ADC1_GPIO_Conf(void );
void ADC1_Mode_Conf(void);
void ADC1_Init(void );

#endif

