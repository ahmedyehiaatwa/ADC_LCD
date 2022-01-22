/*
 * LCD.h
 *
 * Author : Ahmed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_CFG.h"
#define F_CPU 16000000
#include <util/delay.h>

void LCD_Init(void);

void LCD_WriteCommand(uint8_t cmd);

void LCD_WriteChar(uint8_t data);

void LCD_WriteString(uint8_t* str);

void LCD_WriteInteger(sint32_t num);  

void LCD_GoToLocation(uint8_t row , uint8_t col);

void LCD_Clear(void);





#endif /* LCD_H_ */