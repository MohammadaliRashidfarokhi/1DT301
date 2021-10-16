#include <avr/io.h>


int main(void)
{
	
	DDRA = DDRA | 0b00000000;      //Configr. PORTA as  input
	DDRB = DDRB | 0b11111111;      //Configr. PORTB as  output 
	
	while (1) 
	{					
		if((PINA & 0b00000000)==1)   //PINA get 1 by button press
		PORTB = PORTB | 0b10101010;  // Assign 0xAA to PORTB
		PORTB = PORTB | 0b01010101;  // Assign 0x55 to PORTB
		if((PINA & 0b00000000)==0)  //PINA get ) when button is release
		PORTB = PORTB | 0;  //Assign 0 toll PINS of PORTB
	}
	

	return 0;
