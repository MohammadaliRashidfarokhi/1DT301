#include <avr/io.h>


int main(void)
{
	
	DDRB = 0x0F ;  //PORTB lower 4 bits as an output
	DDRD = 0xF0;   //PORTD upper 4 bits as an output
	
	while(1)
	{
		PORTD = 0x90; //PORTD got 10010000
		PORTB = 0x09; //PORTB got 00001001
	}
	

}
