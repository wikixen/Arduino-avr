default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o build/color.o build/color.c
	avr-gcc -o build/color.bin build/color.o
	avr-objcopy -O ihex -R .eeprom build/color.bin build/color.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:build/color.hex 