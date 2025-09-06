#include <util/delay.h>
#include <avr/io.h>

// #define F_CPU 20'000'000

double dutyCycle = 0;

int main(void) {
  // RGB LED output
  DDRB |= (1 << 0);

  // PWM
  TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
  TIMSK0 |= (1 << TOIE0);

  // Start timer
  TCCR0B |= (1 << CS00);

  while (1)
  {
    /* code */
  }
}