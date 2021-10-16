#include <avr/io.h>

int main(void)
{

	DDRB = DDRB | 0b11111111;      //Config.. PORTB as  output

	
	while (1)
	{
		for (unsigned int i=0; i<255 ;i++)
		{
			PORTB++;  // Counter++
			for (unsigned j=0; j<500; j++) // this loop will make delay of approx. 500ms
			{
			}
		}
	}

	return 0;
}