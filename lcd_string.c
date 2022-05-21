
void lcd_string (char *_str){
				
			while(*_str)
			{
				
					lcd_data(*_str);
				_str++;
			}
		}