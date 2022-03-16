
 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ADC driver
 *
 * Author: Islam Adel
 *
 * Created on: Oct 31, 2020
 *
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_
#include "common_macros.h"
#include"micro_config.h"
#include "std_types.h"
void ADC_init(void);
uint16 ADC_readChannel(uint8 channel_num);


#endif /* ADC_H_ */
