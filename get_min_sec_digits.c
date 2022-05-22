/*  this function calc minutes and seconds as seprate numbers
 and assigen them to variables*/

// extern float time;
// extern int s1 ,s0 ,m1 ,m0 ; 
// extern uint32_t  minutes, seconds;


void calc_min_sec(float time)
{
	minutes = time;
	seconds = 60*(time - minutes);
}



/* this function split the minutes and seconds into 
tow digits for example minutes= 25 
m1 = 2 and m0 =5 */ 


void split(uint32_t minutes, uint32_t seconds)
{
	m1=minutes/10 ;
	m0=minutes -(m1*10);

	s1=seconds/10;
	s0= seconds-(s1*10);
}
