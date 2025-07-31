default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o build/bulb.o bulb.c
	avr-gcc -o build/bulb.bin build/bulb.o
	avr-objcopy -O ihex -R .eeprom build/bulb.bin build/bulb.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:build/bulb.hex 