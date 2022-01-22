/*
 * ADC_DRIVER.c
 *
 * Author : Ahmed
 */ 

#include "ADC_DRIVER.h"

void ADC_Init(void)
{
	#if ADC_VOLTAGE_REFRENCE  ==   ADC_VREF_AVCC 
	SET_BIT (ADMUX, 6);
	CLR_BIT (ADMUX, 7);
	
	#endif
	
	#if ADC_ADJUST       ==        ADC_RIGHT_ADJUST
	
	CLR_BIT (ADMUX, 5);
		
	#endif
	
	#if ADC_CHANNEL      ==        ADC_CHANNEL_1
	
	SET_BIT (ADMUX, 0);
	
	#endif
	
	#if  ADC_CONVERSION_TRIGGER  ==  ADC_AUTO_TRIGGER

	SET_BIT (ADCSRA, 5);
		
	#endif

	#if ADC_PRESCALER     ==       ADC_PRESCALER_128
	
	SET_BIT (ADCSRA, 0);
	SET_BIT (ADCSRA, 1);
	SET_BIT (ADCSRA, 2);
	
	
	#endif

	#if ADC_INTERRUPT_STATUS  ==   ADC_INTERRUPT_DISABLE
	
	CLR_BIT (ADCSRA, 3);
		
	#endif	
	//ENABLE ADC //
	
	SET_BIT (ADCSRA, 7);
	
}

void ADC_Read(uint16* value)
{
	SET_BIT (ADCSRA, 1);
	
	while (GET_BIT (ADCSRA, 4)==0);
	
	*value = ADC_VALUE;
	
}
