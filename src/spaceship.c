/*
 * Spaceship project from arduino codebook
 * When a button is pressed two LEDs turns on & the one thats on is turned off 
 * Otherwise a another LED is left on
 */
#include <util/delay.h>
#include <avr/io.h>

int main(void) {
  // Sets PD3, PD4 & PD5 as outputs 
  DDRD |= (1 << 3) | (1 << 4) | (1 << 5);
  
  DDRD &= ~(1 << 2); // Ensures PD2 is an input

  while (1)
  {
    if (PIND & (1<<2))
    {
      PORTD |= (1 << 5);
      PORTD &= ~((1 << 3) | (1 << 4));
    }
    else 
    {
      PORTD |= (1 << 3) | (1 << 4);
      PORTD &= ~(1 << 5);
    }
  }
  
}