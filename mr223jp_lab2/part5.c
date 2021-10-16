#include <avr/io.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
	unsigned int num;
	DDRA   = DDRA | 0b00000000;      //Config.. PORTA as input
	DDRB   = DDRB | 0b11111111;      //Config.. PORTB as output
	
	srand(time(0)); // srand() --> seeding the random number
	
	while (1)
	{
		
		if((PINA & 0xFF)==0)
		num = rand()%6; //assignment of random number
		PORTB = num;  
	}

	return 0;
}