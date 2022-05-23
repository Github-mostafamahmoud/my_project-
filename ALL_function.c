#include <stdint.h>
#include "math.h"
#include "prototypes.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "TM4C123GH6PM.h"


extern float time;
extern char input;
extern int s1 ,s0 ,m1 ,m0 ; 
extern uint32_t kilos, minutes, seconds;
extern int32_t  h , j, k, y ;


// these are general variables common used between all the functions. 
//extern uint8_t sign=0;    //to store the input sign +,-,/,*
//extern uint32_t i=0;      //index for the array of no[4]
//extern uint8_t z=1;      // to check that no signs can come after each other ex; ++,+= and intialized with 1 to prevent begining with any sign.
//extern uint8_t x=0;      // to calculate the operands.
extern uint8_t no[5];    //array to store the numbers of the operand
extern uint8_t key;      //to recieve the returned character
extern uint32_t sum;   // for the result.
//extern uint32_t op=0;   //used in the operand calculation.






void calc_time_beef(uint32_t kilos)
{
	time = 0.5*kilos;
}

void calc_time_chicken(uint32_t kilos)
{
	time = 0.2*kilos;
}

void calc_min_sec(float time)
{
	minutes = time;
	seconds = 60*(time - minutes);
}

void split(uint32_t minutes, uint32_t seconds)
{
	m1=minutes/10 ;
	m0=minutes -(m1*10);

	s1=seconds/10;
	s0= seconds-(s1*10);
}

void count_down(int  mm1  , int  mm0   ,int  ss1   ,int  ss0   ){

	
	
	
	for ( h=mm1 ;h>=0;h--)
	{
		 pause_cont_clear();
    if(h==mm1)
		{
		for (j=mm0 ; j >=0 ;j--)
    {
				 pause_cont_clear();
			if(j==mm0)
			{
        for(k=ss1; k>=0 ;k--)
        {					 pause_cont_clear();
						if(k==ss1)
						{
							for (y=ss0;y>=0;y--)
							{				 pause_cont_clear();
                LCD_command(1);    //clear the lcd.
                lcd_data(h+'0');
                lcd_data(j+'0');
                lcd_data(':');
                lcd_data(k+'0');
                lcd_data(y+'0');
                delayMs(1000);
							}
				   	}
						else
						{
							for (y=9;y>=0;y--)
							{				 pause_cont_clear();
                LCD_command(1);    //clear the lcd.
                lcd_data(h+'0');
                lcd_data(j+'0');
                lcd_data(':');
                lcd_data(k+'0');
                lcd_data(y+'0');
                delayMs(1000);
							}
						}
					}
       }
			 else
			 {
				 for(k=5; k>=0 ;k--)
        {					 pause_cont_clear();
						if(k==ss1)
						{
							for (y=ss0;y>=0;y--)
							{				 pause_cont_clear();
                LCD_command(1);    //clear the lcd.
                lcd_data(h+'0');
                lcd_data(j+'0');
                lcd_data(':');
                lcd_data(k+'0');
                lcd_data(y+'0');
                delayMs(1000);
							}
				   	}
						else
						{
							for (y=9;y>=0;y--)
							{				 pause_cont_clear();
                LCD_command(1);    //clear the lcd.
                lcd_data(h+'0');
                lcd_data(j+'0');
                lcd_data(':');
                lcd_data(k+'0');
                lcd_data(y+'0');
                delayMs(1000);
							}
						}
					}
			 }
		}	
	 }
	 else
	 {
		 		for (j=9 ; j >=0 ;j--)
    {				 pause_cont_clear();
			if(j==mm0)
			{
        for(k=ss1; k>=0 ;k--)
        {					 pause_cont_clear();
						if(k==ss1)
						{
							for (y=ss0;y>=0;y--)
							{				 pause_cont_clear();
                LCD_command(1);    //clear the lcd.
                lcd_data(h+'0');
                lcd_data(j+'0');
                lcd_data(':');
                lcd_data(k+'0');
                lcd_data(y+'0');
                delayMs(1000);
							}
				   	}
						else
						{
							for (y=9;y>=0;y--)
							{				 pause_cont_clear();
                LCD_command(1);    //clear the lcd.
                lcd_data(h+'0');
                lcd_data(j+'0');
                lcd_data(':');
                lcd_data(k+'0');
                lcd_data(y+'0');
                delayMs(1000);
							}
						}
					}
       }
			 else
			 {
				 for(k=5; k>=0 ;k--)
        {					 pause_cont_clear();
						if(k==ss1)
						{
							for (y=ss0;y>=0;y--)
							{				 pause_cont_clear();
                LCD_command(1);    //clear the lcd.
                lcd_data(h+'0');
                lcd_data(j+'0');
                lcd_data(':');
                lcd_data(k+'0');
                lcd_data(y+'0');
                delayMs(1000);
							}
				   	}
						else
						{
							for (y=9;y>=0;y--)
							{				 pause_cont_clear();
                LCD_command(1);    //clear the lcd.
                lcd_data(h+'0');
                lcd_data(j+'0');
                lcd_data(':');
                lcd_data(k+'0');
                lcd_data(y+'0');
                delayMs(1000);
							}
						}
					}
			 }
		}
	 }
	}
			
		LCD_command(1);    //clear the lcd.
}




void Blink_Buzzer(){
	int i ;
		for( i=0 ;i<3 ;i++)
		{
			
			GPIOF->DATA &=~0x0E ;
			GPIOA->DATA &=~0x04 ;
			delayMs(1000) ;
			GPIOF->DATA |=0x0E ;
			GPIOA->DATA |=0x04 ;
			delayMs(1000) ;			
			
		}
		GPIOF->DATA &=~0x0E ;
		GPIOA->DATA &=~0x04 ;
		
}

unsigned char sw2_input (void)
{
	delayMs(200); 
return (GPIO_PORTF_DATA_R & 0x01);
}

unsigned char sw1_input (void)
{
	delayMs(200); 
return (GPIO_PORTF_DATA_R & 0x10);
}
unsigned char sw3_input (void)
{
	delayMs(200); 
return (GPIO_PORTA_DATA_R & 0x08);
}

void portF_int(){
SYSCTL_RCGCGPIO_R |= 0X20 ; // PORTF clock enable
while ((SYSCTL_RCGCGPIO_R & 0x20)==0); //Delay as clock is mechanical
GPIO_PORTF_LOCK_R = 0x4C4F434B ; // Unlock PortF commit register
GPIO_PORTF_CR_R |=0x1F ; //Allow changes to PF4-PF0
GPIO_PORTF_AMSEL_R &= ~0x1F ; //Disable analog function
GPIO_PORTF_PCTL_R &= ~0x000FFFFF ; //GPIO clear bit PCTL
GPIO_PORTF_AFSEL_R &=~0X1F ; //No alternate function
GPIO_PORTF_DIR_R |= 0x0E ; //PF321 output
GPIO_PORTF_DIR_R &=~0x11 ; //PF 4,0 input
GPIO_PORTF_DEN_R |=0x1F ; // Enable digital pins PF4-PF0
GPIO_PORTF_DATA_R &=~0X0E ; // Initialize LEDs to be off
GPIO_PORTF_PUR_R |=0X11 ; // AS SW1 IS NEGATIVE LOGIC

}

void pause_cont_clear(){
	while(sw1_input()==0 | sw3_input()==0 )
			{
while(1){
	GPIOF->DATA &=~0x0E ;
			delayMs(1000) ;
			GPIOF->DATA |=0x0E ;
			delayMs(1000) ;	
	
while(sw2_input()==0) {count_down(h,j,k,y);};

while(sw1_input()==0){
			LCD_command(0x01);
			lcd_string("clear time");
			delayMs(500);
			Blink_Buzzer();
			//count_down(0,0,0,0);
			GPIOF->DATA &=~0x0E ;
//h=0;j=0; k=0;y=0;
	}

}

}
}