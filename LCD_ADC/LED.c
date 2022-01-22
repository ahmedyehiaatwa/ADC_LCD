/*
 * LED.c
 *
 * Created: 30/03/2021 16:38:08
 *  Author: Ahmed
 */ 

#include "LED.h"
#include "DIO.h"


void LED0_Init(void)
{
	DIO_SetPinDir(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);
}

void LED0_On(void)
{
	DIO_SetPinValue(DIO_PORTC, DIO_PIN2 , DIO_PIN_HIGH);
}
void LED0_Off(void)
{
	DIO_SetPinValue(DIO_PORTC, DIO_PIN2 , DIO_PIN_LOW);
}
void LED0_Toggle(void)
{
	DIO_TogglePin(DIO_PORTC, DIO_PIN2);
}