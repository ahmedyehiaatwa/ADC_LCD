/*
 * TEMP_SENSOR.c
 *
 * Author : Ahmed
 */ 

#include "TEMP_SENSOR.h"

void TempSensor_Init(void)
{
	ADC_Init();
}


void TempSensor_Read(uint16 *val)
{
	uint16 Digital_Out = 0;
	uint16 Vin=0;

	
	ADC_Read(&Digital_Out) ;
	
	Vin= (Digital_Out* 500) / 1024;
	*val = Vin / 10;
	
}