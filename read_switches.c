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