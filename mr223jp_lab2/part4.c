#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
volatile unsigned int counter=0; // A global variable to act as a counter

void timer1_init(void)
{
	TCCR1A = 0x00;	 // Timer 1 mode selection (Use Normal mode)
	TCCR1B = 0x00;  //Timer 1 mode selection
	TCNT1H = 0x1F; 	 //Counter higher 8 bit value
	TCNT1L = 0x01; 	 //Counter lower 8 bit value
	TCCR1B=  0x04;	 //start Timer by selecting prescalar factor 256 (avoid overwriting mode selection bits)

}


ISR(TIMER1_OVF_vect)
{
	//TIMER1 has overflowed
	if(counter<=5)
	{
		counter=counter+1;   // increment counter variable every time, the overflow occurs.
	}
	TCNT1H =0x1F;	//reload counter high value
	TCNT1L =0x01;	//reload counter low value
	
}


void interrupt_init()
{
	cli();    //Clears the global interrupts
	
	TIMSK1 = 0x01;  //TIMER 1 overflow interrupt enable
	
	sei();   //Enables the global interrupts
}


int main (void)
{
	interrupt_init();
	timer1_init();
	
	DDRA = DDRA | 0xFF; // PORTA as output
	
	while (1)
	{
		for (unsigned i=0; i<255; i++)
		{
			PORTA = PORTA + 1; //Counter++
			for (unsigned j=0; j<500;j++)
			{
				//delay of 500ms
			}
		}
	}
}