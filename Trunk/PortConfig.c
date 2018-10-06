#include <pic18.h>


void PortInit (void)
{
	TRISA = 1;
	TRISB = 0xFF;
	TRISC = 0;
	TRISD = 0;
	TRISE = 0;
	ADCON1 = 0x0F; 
	A2D_Read();
	PORTC = 0;
}

void A2D_Init(void)
{
	 TRISA = 0xFF;
	 TRISE = 0x0F;
	 ADCON2 = 0x85;
	 ADCON1 = 0x07;
	 ADCON0 = 0x01;
 }

int A2D_Read(void)
{
	 unsigned int result;
	 ADCON0 = 0x01; // Select channel 0, turn on, CLK/32
	 GODONE = 1; // Start conversions
	 while(GODONE); // wait until done (approx 8us)
	 return(ADRES); // and return the result
}

