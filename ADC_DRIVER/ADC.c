
 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ADC driver
 *
 * Author: Islam Adel
 *
 * Created on: Oct 31, 2020
 *
 *****************************************************************************/
#include"ADC.h"
void ADC_init(void)
{
	ADMUX=0;
	ADCSRA=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1);


}
uint16 ADC_readChannel(uint8 channel_num)
{

	channel_num&=0x07;
	ADMUX =(ADMUX&11100000)|(channel_num);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){}
	SET_BIT(ADCSRA,ADIF);
	return ADC;


}



