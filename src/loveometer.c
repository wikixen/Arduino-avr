/**
 * Love-o Meter project from Arduino Projects Book
 * This project uses an a temperature sensor to measure the temparature of your skin
 * This data is then sent to the connected PC via UART
 */
#include <avr/io.h>
#include <stdio.h>

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR (F_CPU / 16 / BAUD - 1)

int uart_put_char(char c, FILE * stream);
void init_uart();
void init_adc();

int uart_put_char(char c, FILE *stream)
{
  if (c == '\n')
  {
    uart_put_char('\r', stream);
  }
  while (!(UCSR0A & (1 << UDRE0)));
  UDR0 = c;
  return 0;
}

FILE uart_output = FDEV_SETUP_STREAM(uart_put_char, NULL, _FDEV_SETUP_WRITE);

void init_uart()
{
  UBRR0H = (unsigned char)(MYUBRR >> 8);
  UBRR0L = (unsigned char)MYUBRR;
  UCSR0B = (1 << TXEN0);
  stdout = &uart_output;
}

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
  init_uart();
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

    // printf("Voltage: %d\tTemp:%d\n", (int)voltage, (int)temp);
    printf("Testing\n");

    // Turn LEDs on if temp is less than 29 Celsius
    if (temp < baselineTemp)
    {
      PORTD |= (1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4);
    }
    else
    {
      PORTD &= ~((1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4));
    }
  }
}