/*
* bulb.c flashes an external led bulb on a breadboard
*/
#include <util/delay.h>
#include <avr/io.h>

int main(void) {
  // Set Pin 3 as output
  DDRD |= (1 << 3);

  while (1)
  {
    _delay_ms(500);
    PORTD ^= (1 << 3);
  }
}
