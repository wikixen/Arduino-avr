/*
* led.c flashes the built-in arduino led
*/
#include <util/delay.h>
#include <avr/io.h>

int main(void) {
	DDRB |= (1 << 5); // Set PB5 as output; This is the pin for the built-in MCU LED

	while(1) {
		_delay_ms(100);
		PORTB ^= (1 << 5);
	}
}

