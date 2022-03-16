
 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Header file for the lcd driver
 *
 * Author: Islam Adel
 *
 * Created on: Oct 31, 2020
 *
 *******************************************************************************/
#include "common_macros.h"
#include "micro_config.h"
#include "std_types.h"
/*OPTIONS :
 *    		4
 *    		8
 */
#define DATA_BITS_MODE 4

#if (DATA_BITS_MODE == 4)
/*OPTIONS :
 * 			UPPER_PORT_PINS
 * 			LOWER_PORT_PINS
 */
#define UPPER_PORT_PINS
#endif
/********************************************************************/
/*CONFIGRATIONS OF HW PINS OF LCD */

#define LCD_RS_PIN						 4
#define LCD_READ_WRITE_PIN 				 5
#define LCD_ENABLE_PIN 					 6
/********************************************************************/
/*connections of lcd hw pins with micro controller */
#define LCD_CONTROL_PINS_DDR 			 DDRD
#define LCD_CONTROL_PINS_PORT 			 PORTD
#define LCD_DATA_DDR 					 DDRC
#define LCD_DATA_PORT 					 PORTC
/*******************************************************************/
/*macros of some commands*/
#define TWO_LINES_EIGHT_BITS_MODE 		 56
#define TWO_LINES_FOUR_BITS_MODE 		 40
#define CURSOR_OFF 						 0x0C
#define CLEAR_SCREEN 					 0x01
/******************************************************************/
/* FUNCTION PROTOTYPE */
void LCD_SendCommand(uint8 command);
void LCD_INIT(void);
void LCD_SendCharacter(uint8 character);
void LCD_Display_string(char *ptr);
void LCD_intger_to_string(int num);
void LCD_GO_TO_ROW_CLOUMN (uint8 row,uint8 col);
void LCD_CLEAR_SCREEN (void);
