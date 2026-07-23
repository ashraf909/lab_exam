
// Simple Arduino-like C program (blink LED on pin 13)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void delay_ms(unsigned int ms) {
#ifdef _WIN32
	Sleep(ms);
#else
	usleep(ms * 1000);
#endif
}

int main(void) {
	// This is a simple simulation: toggle an LED state and print to console
	int led_pin = 13;
	int led_state = 0;
	(void)led_pin; // unused in console simulation

	for (;;) {
		led_state = !led_state;
		if (led_state)
			printf("LED on (pin %d)\n", led_pin);
		else
			printf("LED off (pin %d)\n", led_pin);
		fflush(stdout);
		delay_ms(500);
	}

	return 0;
}
