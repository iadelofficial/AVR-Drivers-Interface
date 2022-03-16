
/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the lcd driver
 *
 * Author: Islam Adel
 *
 * Created on: Oct 31, 2020
 *
 *******************************************************************************/
#include"lcd.h"
void LCD_INIT(void)
{
	SET_BIT(LCD_CONTROL_PINS_DDR,LCD_RS_PIN);
	SET_BIT(LCD_CONTROL_PINS_DDR,LCD_READ_WRITE_PIN);
	SET_BIT(LCD_CONTROL_PINS_DDR,LCD_ENABLE_PIN);
	LCD_DATA_DDR=0xFF;
	LCD_SendCommand(TWO_LINES_EIGHT_BITS_MODE);
	LCD_SendCommand(CURSOR_OFF);
	LCD_SendCommand(CLEAR_SCREEN);



}
void LCD_SendCommand(uint8 command)
{

	CLEAR_BIT(LCD_CONTROL_PINS_PORT,LCD_RS_PIN);

	CLEAR_BIT(LCD_CONTROL_PINS_PORT,LCD_READ_WRITE_PIN);
	_delay_ms(1);

	SET_BIT(LCD_CONTROL_PINS_PORT,LCD_ENABLE_PIN);
	_delay_ms(1);
#if(DATA_BITS_MODE == 4)
	/* send most 4 bits of command */
	#ifdef UPPER_PORT_PINS
			LCD_DATA_PORT =(LCD_DATA_PORT&0x0F)|(command&0xF0)	;
	#elif LOWER_PORT_PINS
			LCD_DATA_PORT =(LCD_DATA_PORT&0xF0)|((command&0xF0)>>4)	;
	#endif
			_delay_ms(1);
			CLEAR_BIT(LCD_CONTROL_PINS_PORT,LCD_ENABLE_PIN);
			_delay_ms(1);
			SET_BIT(LCD_CONTROL_PINS_PORT,LCD_ENABLE_PIN);
			_delay_ms(1);
			/*send least 4 bits of command */
	#ifdef UPPER_PORT_PINS
			LCD_DATA_PORT =(LCD_DATA_PORT&0x0F)|((command&0x0F)<<4)	;
	#elif LOWER_PORT_PINS
			LCD_DATA_PORT =(LCD_DATA_PORT&0xF0)|((command&0x0F))	;
	#endif
		_delay_ms(1);
		CLEAR_BIT(LCD_CONTROL_PINS_PORT,LCD_ENABLE_PIN);
		_delay_ms(1);
#elif(DATA_BITS_MODE == 8)
		LCD_DATA_PORT =command	;
		_delay_ms(1);
		CLEAR_BIT(LCD_CONTROL_PINS_PORT,LCD_ENABLE_PIN);
		_delay_ms(1);

#endif
}
void LCD_Display_Character(uint8 character)
{

	SET_BIT(LCD_CONTROL_PINS_PORT,LCD_RS_PIN);

	CLEAR_BIT(LCD_CONTROL_PINS_PORT,LCD_READ_WRITE_PIN);
	_delay_ms(1);

	SET_BIT(LCD_CONTROL_PINS_PORT,LCD_ENABLE_PIN);
	_delay_ms(1);

	LCD_DATA_PORT = character ;
	_delay_ms(1);
	CLEAR_BIT(LCD_CONTROL_PINS_PORT,LCD_ENABLE_PIN);
	_delay_ms(1);

}
void LCD_Display_string(char *ptr)
{
	uint8 i =0;
	while(ptr[i]!='\0')
	{
		LCD_Display_Character(ptr[i]);
		i++;

	}
}
void LCD_intger_to_string(int num)
{
	char array[16] ;
	 itoa(num,array,10);
	 LCD_Display_string(array);

}
void LCD_GO_TO_ROW_CLOUMN (uint8 row,uint8 col)

{
	uint8 address=0;
	if(row==1)
		{
			address=col;

		}
	else if(row==2)
	{
		address=0x40+col ;
	}
	address|=0x80;
	LCD_SendCommand(address);



}
void LCD_CLEAR_SCREEN (void)
{
	 LCD_SendCommand(0x01);

}

