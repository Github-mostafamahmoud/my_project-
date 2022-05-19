#include <stdint.h>
#include "math.h"
#include "prototypes.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

extern char temp;
extern char enter_time[];
extern int k;
extern int number_entererd_is_not_valid;
extern int y;
extern int u;
extern int v;
extern uint32_t entered_minutes;
extern uint32_t entered_seconds;
extern int b;
extern int a;


unsigned concatenate(unsigned a, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return a * pow + y;
}


void enter_cooking_time()
{
for(v=3;v>=0;v--) {


if(v==3)// start conditions
{
char enter_time[]="00:00";
LCD_command(0x01);	//set pointer to first line
LCD_command(0x80);	// clear screen
	lcd_string(enter_time);	// write 00:00 on screen

}
do{//to be sure that the user really entered a key.
		 temp=keypad_getkey_enter_cooking_time_version()															;
		 delayMs(200);   //wait for the debounce
           if(sw1_input()==0){
				 temp =1;
				 break ;
							 }
					}while(temp==0);


if(temp==1)
{ // if sw1 is pressed reset loop and clear screen and write 00:00
LCD_command(0x01);	//set pointer to first line
LCD_command(0x80);	// clear screen
lcd_string("sw1 is active");
delayMs(2000);
LCD_command(0x01);	//set pointer to first line
LCD_command(0x80);	// clear screen
enter_time[0]='0';
enter_time[1]='0';
enter_time[2]=':';
enter_time[3]='0';
enter_time[4]='0';
 // write 00:00 on screen
v=4;
continue;
}




if(v==3){ // enter first number conditions
	number_entererd_is_not_valid=0;   // start check entered number letter or not
	for(k='A';k<='D';k++)            // check if the number enter is not a letter
	                                  // if letter is entered  clears the screen and reset loop
	{
	if(temp==k)                                    //
	{
   number_entererd_is_not_valid=1;
	}
	}
 if(number_entererd_is_not_valid==1)
 {

	 LCD_command(0x01);	//set pointer to first line
	 LCD_command(0x80);	// clear screen
lcd_string("enter a valid number");
	 delayMs(2000);
	v=4;
	continue;                                  // end check entered number letter or not


 }
                                          // writes entered number on the screen
	enter_time[4]=temp;
	LCD_command(0x01);	//set pointer to first line
	LCD_command(0x80);	// clear screen
	lcd_string(enter_time);

}



if(v==2) // enter second numbers conditions
{
number_entererd_is_not_valid=0;	             // start check entered number letter or not
	for(k='A';k<='D';k++)            // check if the number enter is not a letter
	                                  // if letter is entered  clears the screen and reset loop
	{

	if(temp==k)
	{
   number_entererd_is_not_valid=1;
	}
	}
 if(number_entererd_is_not_valid==1)
 {
 delayMs(500);
 LCD_command(0x01);	//set pointer to first line
 LCD_command(0x80);	// clear screen
lcd_string("enter a valid number");
	v=3;
	 delayMs(1000);
	LCD_command(0x01);	//set pointer to first line
 LCD_command(0x80);	// clear screen
lcd_string(enter_time);	// write 00:00 on screen
	continue;	                                 // end check entered number letter or not
}
enter_time[3]=enter_time[4];                 //  shift the number
                                             //writes entered number on the screen
enter_time[4]=temp;
LCD_command(0x01);	//set pointer to first line
LCD_command(0x80);	// clear screen
lcd_string(enter_time);

}


if(v==1)
{
number_entererd_is_not_valid=0;	                       // start check entered number letter or not
	for(k='A';k<='D';k++)            // check if the number enter is not a letter
	                                  // if letter is entered  clears the screen and reset loop

	{

	if(temp==k)
	{
   number_entererd_is_not_valid=1;
	}
	}
 if(number_entererd_is_not_valid==1)
 {
 delayMs(500);
 LCD_command(0x01);	//set pointer to first line
 LCD_command(0x80);	// clear screen
lcd_string("enter a valid number");
	v=2;
	 delayMs(1000);
	LCD_command(0x01);	//set pointer to first line
 LCD_command(0x80);	// clear screen
lcd_string(enter_time);	// write 00:00 on screen
	continue;	                              // end check entered number letter or not
}


enter_time[1]=enter_time[3];                   //  shift the numbers
                                             //writes entered number on the screen
enter_time[3]=enter_time[4];
enter_time[4]=temp;
LCD_command(0x01);	//set pointer to first line
LCD_command(0x80);	// clear screen
lcd_string(enter_time);


}




if(v==0)
{
number_entererd_is_not_valid=0;	                     // start check entered number letter or not
	for(k='A';k<='D';k++)            // check if the number enter is not a letter
	                                  // if letter is entered  clears the screen and reset loop

	{

	if(temp==k)
	{
   number_entererd_is_not_valid=1;
	}
	}
 if(number_entererd_is_not_valid==1)
 {
 delayMs(500);
 LCD_command(0x01);	//set pointer to first line
 LCD_command(0x80);	// clear screen
lcd_string("enter a valid number");
	v=3;
	 delayMs(1000);
	LCD_command(0x01);	//set pointer to first line
 LCD_command(0x80);	// clear screen
lcd_string(enter_time);	// write 00:00 on screen
	continue;	                         // end check entered number letter or not
}

enter_time[0]=enter_time[1];	               //  shift the numbers
                                             //writes entered number on the screen
enter_time[3]=enter_time[4];
enter_time[1]=enter_time[3];
enter_time[3]=enter_time[4];
enter_time[4]=temp;
LCD_command(0x01);	//set pointer to first line
LCD_command(0x80);	// clear screen
lcd_string(enter_time);

a=enter_time[0]-'0';                      // get value of entered minutes and seconds
y=enter_time[1]-'0';
u=enter_time[3]-'0';
b=enter_time[4]-'0';
entered_minutes=concatenate(a,y);
entered_seconds=concatenate(u,b);        //

if(entered_minutes>30){                  // check the value of entered minutes if greater than 30
	                                       // reset the loop
LCD_command(0x01);	//set pointer to first line
LCD_command(0x80);	// clear screen
lcd_string("err value min");
delayMs(2000);
enter_time[0]='0';
enter_time[1]='0';
enter_time[2]=':';
enter_time[3]='0';
enter_time[4]='0';
LCD_command(0x01);	//set pointer to first line
LCD_command(0x80);	// clear screen
lcd_string(enter_time); // write 00:00 on screen
v=4;
continue;

}
if(entered_seconds>60)                  // check the value of entered minutes if greater than 30
	                                       // reset the loop
{
	LCD_command(0x01);	//set pointer to first line
	LCD_command(0x80);	// clear screen
lcd_string("err value sec");
delayMs(2000);
enter_time[0]='0';
enter_time[1]='0';
enter_time[2]=':';
enter_time[3]='0';
enter_time[4]='0';
LCD_command(0x01);	//set pointer to first line
LCD_command(0x80);	// clear screen
lcd_string(enter_time); // write 00:00 on screen
v=4;
continue;

}
if((entered_minutes==30)&&(entered_seconds>0)){ // check the value of entered minutes and seconds if greater than 30
	                                       // reset the loop
	LCD_command(0x01);	//set pointer to first line
	LCD_command(0x80);	// clear screen
lcd_string("err value min");
delayMs(2000);
enter_time[0]='0';
enter_time[1]='0';
enter_time[2]=':';
enter_time[3]='0';
enter_time[4]='0';
LCD_command(0x01);	//set pointer to first line
LCD_command(0x80);	// clear screen
lcd_string(enter_time); // write 00:00 on screen
v=4;
continue;

}
}
}
}








