default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o build/led.o led.c
	avr-gcc -o build/led.bin build/led.o
	avr-objcopy -O ihex -R .eeprom build/led.bin build/led.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:build/led.hex 