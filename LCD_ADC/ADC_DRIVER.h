/*
 * ADC_DRIVER.h
 *
 * Author : Ahmed
 */ 

#include "BIT_Math.h"
#include "Typedef.h"
#include "Atmega32.h"


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#define ADC_VREF_AVCC         0
#define ADC_RIGHT_ADJUST      1
#define ADC_CHANNEL_1         1
#define ADC_AUTO_TRIGGER      1
#define ADC_PRESCALER_128     5
#define ADC_INTERRUPT_DISABLE 0

void ADC_Init(void);

void ADC_Read(uint16* value);




#endif /* ADC_DRIVER_H_ */