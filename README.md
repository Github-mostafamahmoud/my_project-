# Blink


#include "tm4c123gh6pm.h"
#include <stdint.h>
 

void SystemInit(void){

SYSCTL_RCGCGPIO_R |= 0x20; // PortF clock enable
while ((SYSCTL_PRGPIO_R & 0x20)==0); //Delay
GPIO_PORTF_LOCK_R = 0x4C4F434B; // Unlock PortF Commit register
GPIO_PORTF_CR_R |= 0x0E; // Allow changes to PF1
GPIO_PORTF_AMSEL_R &= ~0x0E; // Disable analog function
GPIO_PORTF_PCTL_R &= ~0x0000FFF0; // GPIO clear bit PCTL
GPIO_PORTF_AFSEL_R &= ~0x0E; // No alternate function
GPIO_PORTF_DIR_R |= 0x0E; // PF321 output
GPIO_PORTF_DEN_R |= 0x0E; // Enable digital pins PF4-PF0
GPIO_PORTF_DATA_R |= 0x0E; // Initialize LEDs to be on
	
}	



void SysTick_Wait( unsigned long delay   ){
	
	NVIC_ST_CTRL_R  = 0x00 ; //disable systick or clear enable to stop counter 
	NVIC_ST_RELOAD_R = delay -1 ;
	NVIC_ST_CURRENT_R =0;  // clean counter value 
	NVIC_ST_CTRL_R = 0x05 ; // enable systick again & clock
	while((NVIC_ST_CTRL_R&0x00010000)==0){// wait for flag
	}
}
//this function wait 10ms for minimum counter =1
void Systick_Wait10ms( unsigned long  mul ){
	long i=0 ;
for (i=0; i<mul ;i++){
		SysTick_Wait(16000);//wait 10 ms 
	// as frequency of the systick is 16 MHz

}	
}

int main (){
	
	
		
		long i ;
		long n=3 ;
	SystemInit();
	 
	while(1){
	//unsigned char led ;
		GPIO_PORTF_DATA_R |=0x0E ;
		Systick_Wait10ms(10000) ;
		

		
		for( i=0 ;i<n ;i++)
		{
			
			GPIO_PORTF_DATA_R &=~0x0E ;
			Systick_Wait10ms(1000) ;
			GPIO_PORTF_DATA_R |=0x0E ;
			Systick_Wait10ms(1000) ;
			
		}
			GPIO_PORTF_DATA_R &=~0x0E ;
			Systick_Wait10ms(1000) ;
		
	}
}#include "tm4c123gh6pm.h"
#include <stdint.h>
 

void SystemInit(void){

SYSCTL_RCGCGPIO_R |= 0x20; // PortF clock enable
while ((SYSCTL_PRGPIO_R & 0x20)==0); //Delay
GPIO_PORTF_LOCK_R = 0x4C4F434B; // Unlock PortF Commit register
GPIO_PORTF_CR_R |= 0x0E; // Allow changes to PF1
GPIO_PORTF_AMSEL_R &= ~0x0E; // Disable analog function
GPIO_PORTF_PCTL_R &= ~0x0000FFF0; // GPIO clear bit PCTL
GPIO_PORTF_AFSEL_R &= ~0x0E; // No alternate function
GPIO_PORTF_DIR_R |= 0x0E; // PF321 output
GPIO_PORTF_DEN_R |= 0x0E; // Enable digital pins PF4-PF0
GPIO_PORTF_DATA_R |= 0x0E; // Initialize LEDs to be on
	
}	



void SysTick_Wait( unsigned long delay   ){
	
	NVIC_ST_CTRL_R  = 0x00 ; //disable systick or clear enable to stop counter 
	NVIC_ST_RELOAD_R = delay -1 ;
	NVIC_ST_CURRENT_R =0;  // clean counter value 
	NVIC_ST_CTRL_R = 0x05 ; // enable systick again & clock
	while((NVIC_ST_CTRL_R&0x00010000)==0){// wait for flag
	}
}
//this function wait 10ms for minimum counter =1
void Systick_Wait10ms( unsigned long  mul ){
	long i=0 ;
for (i=0; i<mul ;i++){
		SysTick_Wait(16000);//wait 10 ms 
	// as frequency of the systick is 16 MHz



}	
}

int main (){
	
	
		
		long i ;
		long n=3 ;
	SystemInit();
	 
	while(1){
	//unsigned char led ;
		GPIO_PORTF_DATA_R |=0x0E ;
		Systick_Wait10ms(10000) ;
		

		
		for( i=0 ;i<n ;i++)
		{
			
			GPIO_PORTF_DATA_R &=~0x0E ;
			Systick_Wait10ms(1000) ;
			GPIO_PORTF_DATA_R |=0x0E ;
			Systick_Wait10ms(1000) ;
			
		}
			GPIO_PORTF_DATA_R &=~0x0E ;
			Systick_Wait10ms(1000) ;
		
	}
}

