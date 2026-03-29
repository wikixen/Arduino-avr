#include <util/delay.h>
#include <avr/io.h>

int main(void) 
{
  double dutyCycle = 0;
  DDRD |= (1 << 3);

  // 50% duty cycle
  OCR0A = (dutyCycle/100.0)*255.0;

  // SCOM0A1 sets non-inverting mode; WGM01 & WGM00 set Fast PWM
  TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);

  // Sets prescaler to 8 & starts PWM
  TCCR0B |= (1 << CS01);
  while (1)
  {
    _delay_ms(100);
    dutyCycle += 10;

    if (dutyCycle > 100)
    {
      dutyCycle = 0;
    }
  }
}