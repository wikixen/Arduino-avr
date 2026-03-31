/**
 * Love-o Meter project from Arduino Projects Book
 * This project uses an a temperature sensor to measure the temparature of your skin
 * This data is then sent to the connected PC via UART
 */
#include <avr/io.h>

void init_adc();

void init_adc()
{
  // REFS0: AVcc set to on
  // MUX[0:3]=000: ADC0 is an input
  ADMUX |= (1 << REFS0);   

  // ADEN: Enables ADC 
  // ADPS[0:2]: Sets precaler to 16MHz
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

int main()
{
  init_adc();

  uint16_t ADCValue = 0;

  // D[2:4]: Sets Pins 2,3,4 as outputs
  DDRD |= (1 << PD4) | (1 << PD3) | (1 << PD2);                    

  // Change this number to the temp in your room to see change
  float baselineTemp = 29; // It was hot in my room when I coded this
  
  while (1)
  {
    ADCSRA |= (1 << ADSC);
    loop_until_bit_is_clear(ADCSRA, ADSC);
    ADCValue = ADC;

    float voltage = ((float)ADCValue / 1024.0) * 5.0;
    float temp = (voltage - .5) * 100.0;

    // Turn LEDs on if temp is less than 29 Celsius
    if (temp > baselineTemp)
    {
      PORTD |= (1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4);
    }
    else
    {
      PORTD &= ~((1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4));
    }
  }
}