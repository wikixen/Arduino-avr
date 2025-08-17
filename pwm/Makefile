default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o build/pwm.o build/pwm.c
	avr-gcc -o build/pwm.bin build/pwm.o
	avr-objcopy -O ihex -R .eeprom build/pwm.bin build/pwm.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:build/pwm.hex 