/*
 * LED.h
 *
 * Created: 30/03/2021 16:38:26
 *  Author: Ahmed
 */ 


#ifndef LED_H_
#define LED_H_

#include "DIO.h"
#define F_CPU 16000000
#include <util/delay.h>


void LED0_Init(void);

void LED0_On(void);

void LED0_Off(void);

void LED0_Toggle(void);





#endif /* LED_H_ */