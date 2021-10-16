#include <avr/io.h>


int main(void)
{

    DDRA  = DDRA  | 0b11111111;      // Configr. as an output PORTA
	PORTA = PORTA | 0xAA;    // Assignment of 0xAA

    return 0;
}