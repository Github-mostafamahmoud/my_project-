
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