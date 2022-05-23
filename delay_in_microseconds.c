#include "TM4C123GH6PM.h"
#include <stdint.h>




/* delay n microseconds (16 MHz CPU clock) */
void delayMs(uint32_t n)
{
while(n!=0)
	{	
	NVIC_ST_CTRL_R=0;
  NVIC_ST_RELOAD_R=16-1;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R|=0x0005;
	while((NVIC_ST_CTRL_R&0x00010000)==0);
	n--;
}
}
