// switch.c turns on led via button, both of which are on a breadboard
#include <avr/io.h>

int main(void) {
  DDRD |= (1 << 3); // Desginates PD3 as output
  DDRD &= ~(1 << 2); // Ensure PD2 is input

  while (1)
  {
    if (PIND & (1<<2))
    {
      PORTD |= (1 << 3);
    }
    else 
    {
      PORTD &= ~(1 << 3);
    }
  }
}