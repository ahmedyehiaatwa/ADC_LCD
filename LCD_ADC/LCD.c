/*
 * LCD.c
 *
 * Author : Ahmed
 */ 

#include "LCD.h"

void LCD_Init(void)
{

DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_OUTPUT);

DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT,LCD_D4, DIO_PORT_OUTPUT);
DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT,LCD_D5, DIO_PORT_OUTPUT);
DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT,LCD_D6, DIO_PORT_OUTPUT);
DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT,LCD_D7, DIO_PORT_OUTPUT);

_delay_ms(100);

LCD_WriteCommand(0x33);
LCD_WriteCommand(0x32);
LCD_WriteCommand(0x28);
LCD_WriteCommand(0x0c);
LCD_WriteCommand(0x01);
LCD_WriteCommand(0x06);
LCD_WriteCommand(0x02);

_delay_ms(20);

}

void LCD_WriteCommand(uint8_t cmd)
{
DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_RS_PIN, DIO_PIN_LOW);
DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_RW_PIN, DIO_PIN_LOW);
DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
PORTA = (cmd & 0xf0) | (PORTA & 0x0f);

DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_HIGH);
_delay_ms(1);
DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);

PORTA = (cmd << 4) | (PORTA & 0x0f);

DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_HIGH);
_delay_ms(1);
DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_WriteChar(uint8_t data)
{
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_RS_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = (data & 0xf0) | (PORTA & 0x0f);

	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);

	PORTA = (data << 4) | (PORTA & 0x0f);

	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_WriteString(uint8_t* str)
{
	uint8_t cnt = 0;
	
	while (str[cnt]!= '\0')
	{
		LCD_WriteChar(str[cnt]);
		cnt++;
	}
	
	
}

void LCD_WriteInteger(sint32_t intgr)  //<---- Assignment
{
	
	sint32_t y = 1;

	if(intgr < 0)
	{
		LCD_WriteChar('-');
		intgr *= -1;
	}

	while(intgr > 0)
	{
		y = ((y*10) + (intgr%10));
		intgr /= 10;
	}

	while(y > 1 )
	{
		LCD_WriteChar(((y%10)+48));
		y /= 10;
	}
}

void LCD_GoToLocation(uint8_t row , uint8_t col)
{
	uint8_t Loc[2]={0x80,0xc0};
		LCD_WriteCommand(Loc[row]+col);
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}