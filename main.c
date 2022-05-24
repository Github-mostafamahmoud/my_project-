#pragma
#include "TM4C123GH6PM.h"
#include <stdint.h>
#include "math.h"
#include "prototypes.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

float time;
char input;
int s1 ,s0 ,m1 ,m0 ; 
uint32_t kilos, minutes, seconds;
int32_t  h , j, k, y ;
 
 
char temp;
char enter_time[]="00:00";
int k;
int number_entererd_is_not_valid;
int y;
int u;
int v;
uint32_t entered_minutes;
uint32_t entered_seconds;
int b;
int a;


// these are general variables common used between all the functions. 
 uint8_t sign=0;    //to store the input sign +,-,/,*
 uint32_t i=0;      //index for the array of no[4]
 uint8_t z=1;      // to check that no signs can come after each other ex; ++,+= and intialized with 1 to prevent begining with any sign.
 uint8_t x=0;      // to calculate the operands.
 uint8_t no[5];    //array to store the numbers of the operand
 uint8_t key;      //to recieve the returned character
 uint32_t sum;   // for the result.
 uint32_t op=0;   //used in the operand calculation.

int main(void)
{
        LCD_init();
        keypad_init();
	portF_int();
	
//   FOR SW3 and buzzer
GPIOA->DIR |= 0x04;
GPIOA->DIR &= ~0x08;
GPIOA->DEN |= 0x0C;
GPIO_PORTF_PUR_R |= 0X08 ;
	
	
	start:       LCD_command(1);    //clear the lcd.
               LCD_command(0x80); /* lcd cursor location */
	
	lcd_string ("enter a choice to begin cooking");
	 delayMs(3000);
   LCD_command(1);    //clear the lcd.

	while(1){
	     do{                          //to be sure that the user really entered a key.
           key= keypad_getkey();
           delayMs(200);   //wait for the debounce
				}while(key==0);
			 
				switch(key){
										
					
					
start_popcorn:									case 'A':
																lcd_string ("pop corn ");
																delayMs(3000);
																LCD_command(1);    //clear the lcd
											
														do{                          //to be sure that the user really entered a key.
																		delayMs(200);   //wait for the debounce
																	}while(sw2_input () == 1 | sw3_input () == 0);
			 
																GPIOF->DATA |=0x0E ;
																count_down(0,0,5,9);
																GPIOF->DATA &=~0x0E ;
																Blink_Buzzer();
														break;
											
start_beef:											case'B':
		
																					LCD_command(1);
																					LCD_command(0x80);
																					lcd_string("Beef weight?");

																					do{                          //to be sure that the user really entered a key.
																						input= keypad_getkey();
																						delayMs(200);   //wait for the debounce
																						} while(input==0);

																					kilos = input - '0';
																					if(kilos>0 & kilos<10) 
																					{
																						LCD_command(0x01);
																						LCD_command(0x80);
																						lcd_data(input);
																						delayMs(2000);
																						LCD_command(0x01);
																						
																						 calc_time_beef(kilos);
																						 calc_min_sec(time);
																						 split(minutes,seconds);
																						
																				do{                          //to be sure that the user really entered a key.
																		delayMs(200);   //wait for the debounce
																	}while(sw2_input () == 1 | sw3_input () == 0);
																						
																						GPIOF->DATA |=0x0E ;
																						count_down(m1,m0,s1,s0);
																						GPIOF->DATA &=~0x0E ;
																					}
																					else
																					{	
																						LCD_command(0x01);
																						LCD_command(0x80);
																						lcd_string("Err");
																						delayMs(2000);											
																						goto start_beef;
																					}
																					Blink_Buzzer();
																					break;
																					

start_chicken:												case'C':
																							
																					LCD_command(1);
																					LCD_command(0x80);
																					lcd_string("Chicken weight?");

																					do{                          //to be sure that the user really entered a key.
																						input= keypad_getkey();
																						delayMs(200);   //wait for the debounce
																						} while(input==0);

																					kilos = input - '0';
																					if(kilos>0 & kilos<10) 
																					{
																						LCD_command(0x01);
																						LCD_command(0x80);
																						lcd_data(input);
																						delayMs(2000);
																						LCD_command(0x01);

																						
																						 calc_time_chicken(kilos);
																						 calc_min_sec(time);
																						 split(minutes,seconds);
																						
																		do{                          //to be sure that the user really entered a key.
																		delayMs(200);   //wait for the debounce
																	}while(sw2_input () == 1 | sw3_input () == 0);
																						
																						GPIOF->DATA |=0x0E ;
																						count_down(m1,m0,s1,s0);
																						GPIOF->DATA &=~0x0E ;
																					}
																					else
																					{	
																						LCD_command(0x01);
																						LCD_command(0x80);
																						lcd_string("Err");
																						delayMs(2000);											
																						goto start_chicken;
																					}
																				Blink_Buzzer();
																					break;
																					
enter_cooking_time:																	case'D':
																																						
													enter_cooking_time();
														
														split(entered_minutes,entered_seconds);

																do{                          //to be sure that the user really entered a key.
																		delayMs(200);   //wait for the debounce
																	if(sw1_input ==0){
															goto enter_cooking_time;
																	
																	}
																	}while(sw2_input () == 1 | sw3_input () == 0);

														GPIOF->DATA |=0x0E ;		
														count_down(m1,m0,s1,s0);
														GPIOF->DATA &=~0x0E ;

																					Blink_Buzzer();
																					break;

}

}
}

