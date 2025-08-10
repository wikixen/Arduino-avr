#include <util/delay.h>
#include <avr/io.h>

int main(void) {
  // RGB LED outputs
  DDRC = (1 << 0) | (1 << 1) | (1 << 2);
  
  // Phototransistor output
  DDRB = (1 << 0) | (1 << 1) | (1 << 2);

  while (1)
  {
    /* code */
  }
  
}