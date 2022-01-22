/*
 * TEMP_SENSOR.h
 *
 * Author : Ahmed
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "ADC_DRIVER.h"

void TempSensor_Init(void);

void TempSensor_Read(uint16 *val);




#endif /* TEMP_SENSOR_H_ */