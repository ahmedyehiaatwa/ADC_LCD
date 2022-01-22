/*
 * F19_ADC_DRIVER.c
 *
 * Author : Ahmed
 */ 

#include "TEMP_SENSOR.h"
#include "LCD.h"



int main(void)
{
	uint16 Temp = 0;
	
	LCD_Init();
   TempSensor_Init();
   
   
   
    while (1) 
    {
		TempSensor_Read(&Temp);
		
		LCD_Clear();
		LCD_WriteInteger(12);
		
		
    }
}

