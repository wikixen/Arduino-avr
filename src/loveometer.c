/**
 * Love-o Meter project from Arduino Projects Book
 * This project uses an a temperature sensor to measure the temparature of your skin
 * This data is then sent to the connected PC via UART
 */
#include <avr/io.h>

void initADC();

void initADC()
{
  ADMUX |= (1 << REFS0) | (0 << MUX0); // Sets VCC to on & ensures Pin A0 is input
  ADCSRA |= (1 << ADEN) | (1 << ADPS1) | (1 << ADPS0); // ADEN sets ADC to on & ADPS sets precaler to 1MHz
}

int main() {
  uint16_t ADCValue = 0;
  DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4); // Sets Pins D2,3,4 as outputs
  PORTC = 0; // Make sure that C0 is an input 
  initADC();

  while (1)
  {
    ADCSRA |= (1 << ADSC);
    loop_until_bit_is_clear(ADCSRA, ADSC);
    /* code */
  }
  
}