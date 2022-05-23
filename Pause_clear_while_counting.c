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

