#include <stdint.h>

#define PORTB *((volatile byte *)0x25)
#define DDRB *((volatile byte *)0x24)

#define PORTD *((volatile byte*)0x2B)
#define DDRD *((volatile byte*)0x2A)

typedef uint8_t byte;