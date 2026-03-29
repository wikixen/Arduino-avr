/*
 * Spaceship project from arduino codebook
 * When a button is pressed two LEDs turns on & the one thats on is turned off 
 * Otherwise a another LED is left on
 */
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
  // Sets PD3, PD4 & PD5 as outputs
  DDRD |= (1 << PD3) | (1 << PD4) | (1 << PD5);

  DDRD &= ~(1 << PD2); // Ensures PD2 is an input

  while (1)
  {
    if (PIND & (1 << PIND2))
    {
      PORTD |= (1 << PORTD5);
      PORTD &= ~((1 << PORTD3) | (1 << PORTD4));
    }
    else
    {
      PORTD |= (1 << PORTD3) | (1 << PORTD4);
      PORTD &= ~(1 << PORTD5);
    }
  }
}