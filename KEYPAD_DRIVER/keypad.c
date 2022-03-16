
 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.c
 *
 * Description: Source file for the Keypad driver
 *
 * Author: Islam Adel
 *
 * Created on: Oct 31, 2020
 *
 *******************************************************************************/
#include"keypad.h"
#if(N_COL==4)

uint8 keypad4_4_adjust_key(uint8 Number_Of_Button);

#elif(N_COL==3)

	uint8 keypad4_3_adjust_key(uint8 Number_Of_Button);

#endif
uint8 Keypad_Number_Of_Button(void)
{
	while(1)
	{

		for (uint8 col=0;col<N_COL;col++)
		{
			KEYPAD_DDR =(0b00010000<<col);
			/*make one col out put and all another pins input */
			KEYPAD_PORT=~(KEYPAD_DDR );
			/*put zero in output port and make all pins work with internal pull up mode */
			for(uint8 row=0;row<N_ROW;row++)
			{
				if (BIT_IS_CLEAR(KEYPAD_PIN,row))
				{
					#if(N_COL==4)

					return keypad4_4_adjust_key(row*N_COL+col+1);

					#elif(N_COL==3)

					return keypad4_3_adjust_key(row*N_COL+col+1);

					#endif
				}
			}
		}
 }

}
#if(N_COL==4)

	uint8 keypad4_4_adjust_key(uint8 Number_Of_Button)
	{
		switch(Number_Of_Button)
		{
			case 1 : return 7 ;
		 	 	 	break ;
			case 2 : return 8 ;
					break ;
			case 3 : return 9 ;
					break ;
			case 4 : return '/' ;
					break ;

			case 5 : return 4 ;
					break ;
			case 6 : return 5 ;
					break ;
			case 7 : return 6 ;
					break ;
			case 8 : return '*' ;
					break ;
			case 9 : return 1 ;
					break ;
			case 10 : return 2 ;
					break ;
			case 11 : return 3 ;
					break ;
			case 12 : return '-' ;
					break ;
			case 13 : return 13 ;/*ascii code of enter key */
					break ;
			case 14 : return 0 ;
					break ;
			case 15 : return '=' ;
					break ;
			case 16 : return '+' ;
					break ;
			default :return Number_Of_Button;
		}

	}

#elif(N_COL==3)

uint8 keypad4_3_adjust_key(uint8 Number_Of_Button)
{
			switch (Number_Of_Button)
			{
				case 10: return '*';
				break ;
				case 11 : return 0 ;
				break ;
				case 12 :return '#';
				break ;
				default : return Number_Of_Button;
			}



		}


#endif
