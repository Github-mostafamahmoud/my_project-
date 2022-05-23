																					
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