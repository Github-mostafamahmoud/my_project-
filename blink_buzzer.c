
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