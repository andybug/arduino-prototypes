

CC=avr-gcc
CFLAGS=-DF_CPU=16000000UL -mmcu=atmega328p -Os

.PHONY: all clean upload
all: bin/led

clean:
	rm -r ./bin

bin/led.o: led.c
	$(CC) $(CFLAGS) -c -o bin/led.o led.c

bin/led: bin/led.o
	$(CC) $(CFLAGS) -o bin/led bin/led.o

bin/led.hex: bin/led
	avr-objcopy -R .eeprom -O ihex bin/led bin/led.hex

upload: bin/led.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:bin/led.hex
