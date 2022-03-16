
 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Islam Adel
 *
 * Created on: Oct 31, 2020
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "common_macroS.h"
#include "micro_config.h"
#include "std_types.h"


#define N_COL 3
#define N_ROW 4
#define KEYPAD_DDR DDRA
#define KEYPAD_PORT PORTA
#define KEYPAD_PIN PINA

uint8 Keypad_Number_Of_Button(void);


#endif /* KEYPAD_H_ */
