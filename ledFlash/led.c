#include <util/delay.h>

#define PORTB *((volatile byte*)0x25)
#define DDRB *((volatile byte *)0x24)

typedef uint8_t byte;

int main(void) {
	 DDRB = 32;

	while(1) {
		PORTB = 32;
		_delay_ms(500);
		PORTB = 0;
		_delay_ms(500);
	}
}

