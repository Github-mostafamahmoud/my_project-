
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
