				switch(key){
										
					
					
start_popcorn:									case 'A':
																lcd_string ("pop corn ");
																delayMs(3000);
																LCD_command(1);    //clear the lcd
											
														do{                          //to be sure that the user really entered a key.
																		delayMs(200);   //wait for the debounce
																	}while(sw2_input () == 1 | sw3_input () == 0);
			 
																GPIOF->DATA |=0x0E ;
																count_down(0,1,0,0);
																GPIOF->DATA &=~0x0E ;
																Blink_Buzzer();
														break;