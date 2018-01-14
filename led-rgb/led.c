#include <stdlib.h>
#include <stdint.h>

#include <avr/io.h>
#include <util/delay.h>

/*
 * pinout:
 * 9  - red
 * 10 - green
 * 11 - blue
 */

int main(void)
{
	DDRB = _BV(PORTB1) | _BV(PORTB2) | _BV(PORTB3);

	TCCR1A = _BV(WGM01) | _BV(WGM00) | _BV(COM0A1) | _BV(COM0B1);
	TCCR1B = _BV(CS00);

	TCCR2A |= _BV(WGM01) | _BV(WGM00) | _BV(COM0A1);
	TCCR2B |= _BV(CS00);

	uint8_t red = 0;
	uint8_t green = 0;
	uint8_t blue = 0;

	uint8_t target_red = 0;
	uint8_t target_green = 0;
	uint8_t target_blue = 0;

	while (1) {
		if (red == target_red) {
			target_red = rand() % 0xff;
		}

		if (green == target_green) {
			target_green = rand() % 0xff;
		}

		if (blue == target_blue) {
			target_blue = rand() % 0x60;
		}

		red += red < target_red ? 1 : -1;
		green += green < target_green ? 1 : -1;
		blue += blue < target_blue ? 1 : -1;

		OCR1A = red;
		OCR1B = green;
		OCR2A = blue;

		_delay_ms(30);
	}

	return 0;
}
