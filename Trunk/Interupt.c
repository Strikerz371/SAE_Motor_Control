//////////////////////////////////////////////////////////////
// Interupt Control
//////////////////////////////////////////////////////////////
#include "Interupt.h"

void interrupt IntServe(void)
{
	if (TMR2IF)
	{
		if (DELAY)
		{ 
			DELAY -= 1;
		}
	RC7=!RC7;
	TMR2IF = 0;
	 
	}
	
	if (TMR0IF)
	{
		TMR0 = -3906;
		if(DELAY0)
		{ 
			DELAY0 -=1;
		}
		RC6=!RC6;
		TMR0IF = 0;
	
	}
}
 	