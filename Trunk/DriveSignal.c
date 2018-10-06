//////////////////////////////////////////////////////////////
//	Revision Log:
//	10/6/2018	Initial Draft


//////////////////////////////////////////////////////////////
//	Include Files
//////////////////////////////////////////////////////////////
#include <pic18.h>
#include "PortConfig.h"
#include "LCD_PortD.h"


//////////////////////////////////////////////////////////////
//	Global Variables
//////////////////////////////////////////////////////////////

const unsigned char MSG1[20] = "OFF               "; 
const unsigned char MSG2[20] = "FULL POWER        ";
const unsigned char MSG3[20] = "MID  POWER        ";
const unsigned char MSG4[20] = "LOW  POWER        ";
const unsigned char MSG5[20] = "VERY FAST         ";
const unsigned char MSG6[20] = "FAST              ";
const unsigned char MSG7[20] = "SLOW              ";

unsigned int time, bump, DELAY,DELAY0, gas, on, lit,pump;

unsigned char i;
 
///////////////////////////////////////////////////////////////
//	Main
///////////////////////////////////////////////////////////////

Init(void)
{

	LCD_Init();

	

	// set up Timer0 with PS = 256
	 
	 T0CS = 0;
	 T0CON = 0x87; //256
	 TMR0ON = 1;
	 TMR0IE = 1;
	 TMR0IP = 1;
	 PEIE = 1;

   	// initialize Timer2
		
	 T2CON = 0x4D;
	 PR2 = 249;
	 TMR2IE = 1;
	 PEIE = 1;
	 TMR2ON = 1;
	 TMR2IP = 1;
	// Turn on all interrupts
	 GIE = 1;
	RA3=1;



	LCD_Move(1,1);
	for (i=0; i<20; i++)
		{
		LCD_Write(MSG7[i]); // slow
		}

	LCD_Move(0,0);
	for (i=0; i<20; i++)
		{ 
		 LCD_Write(MSG2[i]); //full power
		}

			
while(1){
	RC5=!RC5;
	unsigned char i;
	


			if(RB0 == 1){
				bump = 0;
				gas = 0;
				pump = 1;
				LCD_Move(0,0);
				for (i=0; i<20; i++){
					 LCD_Write(MSG1[i]); //On
				}
			}
			if(RB1 == 1){
				bump = 1;
				gas = 1;
				pump =0;
				LCD_Move(0,0);
				for (i=0; i<20; i++){ 
					 LCD_Write(MSG2[i]); //off
				}
			}
			

			
	}
}	