#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
	EICRA |= 0b01; // Setup this! Use rising  edge.
	EIMSK |= (1 << INT0); ; // Setup this!
	// Set data direction for low nibble of PORTB and high nibble of PORTD
	DDRB = 0x0F;
	DDRD &= 0x0F;
	// Resetting B and D to known values
	PORTB = 0x00;
	PORTD = 0x00;
	sei(); // Set the global interrupt enable flag here!
	while (1) {
		// Do nothing, the toggle is supposed to happen in the interrupt
		if ((PORTD & 0x0F)==0)
		{
			PORTB = 0xAA;
			PORTB = 0x55;
		}else
		PORTB = 0x00;
	}
}
ISR (INT0_vect) {
	if ((PIND2 & 0x0F)==1)
	{
		PORTB = 0xAA;
		PORTB = 0x55;
	}
	PORTB = 0x00;
}