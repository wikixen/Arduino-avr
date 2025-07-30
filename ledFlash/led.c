/*
* led.c flashes the built-in arduino led
*/
#include <util/delay.h>
#include <myports.h>

int main(void) {
	 DDRB = 32;

	while(1) {
		PORTB = 32;
		_delay_ms(500);
		PORTB = 0;
		_delay_ms(500);
	}
}

