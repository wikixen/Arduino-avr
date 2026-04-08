# Swap filename before use
FILE=uart_calc

LDFLAGS = -Wl,-u,vfprintf -lprintf_flt -lm

default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o build/$(FILE).o src/$(FILE).c
	avr-gcc -mmcu=atmega328p $(LDFLAGS) -o build/$(FILE).bin build/$(FILE).o
	avr-objcopy -O ihex -R .eeprom build/$(FILE).bin build/$(FILE).hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:build/$(FILE).hex 