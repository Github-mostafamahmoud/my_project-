
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