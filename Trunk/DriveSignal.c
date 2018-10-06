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
int A2D;

unsigned int time, bump, gas, on, lit,pump;

unsigned char i;
 
///////////////////////////////////////////////////////////////
//	Init
///////////////////////////////////////////////////////////////
void init (void)
{
	
	LCD_Init();

	

	// initialize Timer0 with PS = 256
	 
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



	LCD_Move(1,0);
	for (i=0; i<20; i++)
		{
		LCD_Write(MSG7[i]); // slow
		}

	//LCD_Move(0,0);
	//for (i=0; i<20; i++)
	//	{ 
	//	 LCD_Write(MSG2[i]); //full power
	//	}
}
	
///////////////////////////////////////////////////////////////
//	Main
///////////////////////////////////////////////////////////////
main(void)
{
	init();
				
	while(1){
		RC1=!RC1;
		unsigned char i =0;

///Display value of A2D////////////////////////////////////////
LCD_Move(0,0);
A2D = A2D_Read();
LCD_Out(A2D, 0);

///////////////////////////////////////////////////////////////
	if(RB0 == 1)
	{
		LCD_Move(0,0);
		for (i=0; i<20; i++){
			 LCD_Write(MSG1[i]); //On
		}
	}
	if(RB1 == 1){
		LCD_Move(0,0);
		for (i=0; i<20; i++){ 
			 LCD_Write(MSG2[i]); //off
		}
	}
				
	
				
	}
}
