/*
* led.c flashes the built-in arduino led
*/
#include <util/delay.h>
#include <avr/io.h>

int main(void) {
	 DDRB |= (1 << 5);

	while(1) {
		_delay_ms(500);
		PORTB ^= (1 << 5);
	}
}

