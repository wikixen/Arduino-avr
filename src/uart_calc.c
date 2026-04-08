/**
 * A simple calculator that allows for 4 operations using UART
 * Capable of addition, subtraction, multiplication, division
 */

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL
#define BAUD 9600
#define MY_UBBR (F_CPU / 16 / BAUD - 1)

int uart_put_char(char c, FILE *stream);
int uart_get_char(FILE *stream);
void init_uart();

FILE uart_string = FDEV_SETUP_STREAM(uart_put_char, uart_get_char, _FDEV_SETUP_RW);

int uart_put_char(char c, FILE *stream)
{
  if (c == '\n')
  {
    uart_put_char('\r', stream);
  }
  if (c == '\b')
  {
    
  }
  

  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
  return 0;
}

int uart_get_char(FILE *stream)
{
  loop_until_bit_is_set(UCSR0A, RXC0);

  char c = UDR0;

  uart_put_char(c, stream);

  return c;
}

void init_uart()
{
  UBRR0H = (unsigned char)(MY_UBBR >> 8);
  UBRR0L = (unsigned char)MY_UBBR;

  UCSR0B = (1 << RXEN0) | (1 << TXEN0);

  stdout = &uart_string;
  stdin = &uart_string;
}

int main(void)
{
  init_uart();
  _delay_ms(1000);
  printf("\nThis program is a calculator that let's you do +,-,*, or /:\n");
  
  int num1 = 0, num2 = 0, answer = 0;
  uint8_t operator = 0;

  while (1)
  {
    printf("\nEnter your first number: ");
    scanf("%d", &num1);
    
    printf("\nEnter your second number: ");
    scanf("%d", &num2);
    
    printf("\nEnter your operator(+,-,*, or /): ");
    scanf(" %c", &operator);

    switch (operator)
    {
    case '*':
      answer = num1 * num2;
      break;
    case '+':
      answer = num1 + num2;
      break;
    case '-':
      answer = num1 - num2;
      break;
    case '/':
      if (num2 == 0)
      {
        printf("\nError: Division by zero.");
        answer = 0;
      }
      else
      {
        answer = num1 / num2;
      }
      break;
    default:
      printf("\nChoose a valid operator.\n");
      continue;
    }

    printf("\n%d%c%d=%d\n", num1, operator, num2, answer);
  }
}
