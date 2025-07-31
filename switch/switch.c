// switch.c turns on led via button, both of which are on a breadboard

#include <avr/io.h>
#include <util/delay.h>
// #include </home/bennyhernandez/Code/arduino_avr/myports.h>

int main(void) {
  DDRD |= (1 << DDD3);

  DDRD &= ~(1 << DDD2);

  PORTD |= (1 << PORTD2);

  while (1)
  {
    if (~(PIND & (1<<PIND2)))
    {
      PORTD |= (1 << PORTD3);
    }
    else
    {
      PORTD &= ~(1 << PORTD3);
    }
  }
}