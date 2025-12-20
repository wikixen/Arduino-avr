#include <util/delay.h>
#include <avr/io.h>

void InitPWM()
{
  TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
  DDRB |= (1 << 0);
}

int main(void) {


  // Start timer
  TCCR0B |= (1 << CS00);

  while (1)
  {
    /* code */
  }
}