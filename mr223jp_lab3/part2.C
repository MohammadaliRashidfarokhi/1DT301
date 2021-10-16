
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <time.h>


int main(void)
{
	
	DDRD &= 0b00000100; //PORTD as a input for pushbutton
	DDRC   = 0x0F; //PORTC least 4 pins as an output
	
	while (1)
	{
		if ((PORTD & 0xFF)==0)
		{
			PORTC = 0x01;
			//_delay_ms(500); // commented in debug mode
			PORTC = 0x03;
			//_delay_ms(500); // commented in debug mode
			PORTC = 0x07;
			//_delay_ms(500); // commented in debug mode
			PORTC = 0x0F;
			//_delay_ms(500); // commented in debug mode
		}
		else
		{
			PORTC = 0x00;
		}
	}
}

