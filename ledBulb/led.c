#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // Set PORTD2 as input
  PORTD = (1 << PD2);
  // Set PORTD3-5 as output
  DDRD = (1 << DDD5) |(1 << DDD4) | (1 << DDD3);
  
  while (1)
  {
    // if PORTD2 is high turn on 4&5
    if (PIND2)
    {
      /* code */
    } else {

    }
    
    // else turn on 3

  }
}
