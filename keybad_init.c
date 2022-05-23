
/* this function initializes the ports connected to the keypad */
#define KEYPAD_ROW GPIOE
#define KEYPAD_COL GPIOC

void keypad_init(void)
{
SYSCTL->RCGCGPIO |= 0x04; /* enable clock to GPIOC */
SYSCTL->RCGCGPIO |= 0x10; /* enable clock to GPIOE */
KEYPAD_ROW->DIR |= 0x0F; /* set row pins 3-0 as output */
KEYPAD_ROW->DEN |= 0x0F; /* set row pins 3-0 as digital pins */
KEYPAD_ROW->ODR |= 0x0F; /* set row pins 3-0 as open drain */
KEYPAD_COL->DIR &= ~0xF0; /* set column pin 7-4 as input */
KEYPAD_COL->DEN |= 0xF0; /* set column pin 7-4 as digital pins */
KEYPAD_COL->PUR |= 0xF0; /* enable pull-ups for pin 7-4 */
}