/**
 * Love-o Meter project from Arduino Projects Book
 * This project uses an a temperature sensor to measure the temparature of your skin
 * This data is then sent to the connected PC via UART
 */
#include <avr/io.h>

void analogInit() {
  ADMUX |= (1 << REFS0) | (0 << MUX0); // Ensures Pin A0 is input
  ADCSRA = 0b10000011; // Sets precaler to 1MHz
}

int main() {
  analogInit();

  while (1)
  {
    /* code */
  }
  
}