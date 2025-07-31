default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o build/switch.o switch.c
	avr-gcc -o build/switch.bin build/switch.o
	avr-objcopy -O ihex -R .eeprom build/switch.bin build/switch.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:build/switch.hex 