#include <atmel_start.h>
#include <stdio.h>
#include "application.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	while (1) {

		// Function measures Frequency and Duty cycle of the signal
		FrequencyAndDutycycleMeasurement();
	}
}
