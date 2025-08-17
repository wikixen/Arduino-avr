// switch.c turns on led via button, both of which are on a breadboard
#include <avr/io.h>

int main(void) {
  DDRD |= (1 << 3); // LED Output

  // Btn input
  DDRD &= ~(1 << 2); 
  PORTD |= (1 << 2);

  while (1)
  {
    if (~PIND & (1<<2))
    {
      PORTD |= (1 << 3);
    }
    else 
    {
      PORTD &= ~(1 << 3);
    }
  }
}