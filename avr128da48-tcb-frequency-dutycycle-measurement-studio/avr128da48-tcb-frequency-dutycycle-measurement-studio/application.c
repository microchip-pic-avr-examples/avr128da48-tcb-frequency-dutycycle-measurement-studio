/*
 * application.c
 *
 * Created: 3/12/2020 10:31:31 PM
 *  Author: I51005
 */

/**
 * **********************************************************
 *  Macros definitions
 * **********************************************************
 **/

#include <atmel_start.h>
#include <stdio.h>
#include "application.h"

#define F_CPU 24000000

volatile uint8_t rtcFlag;
volatile uint8_t samplescount = 0;

volatile uint32_t periodAfterCapture        = 0;
volatile uint32_t pulseWidthAfterCapture    = 0;
volatile uint32_t periodAfterCaptureAvg     = 0;
volatile uint32_t pulseWidthAfterCaptureAvg = 0;
volatile uint32_t periodSum                 = 0;
volatile uint32_t pulseWidthSum             = 0;

volatile uint32_t captureDuty      = 0;
volatile uint32_t captureFrequency = 0;

uint8_t buffer[60];

/**
  @Param
  none
  @Returns
   none
  @Description
  function to transmit a data on terminal window
  **/
void SendString(const char *data)
{
	uint8_t i = 0;
	for (i = 0; data[i] != '\0'; i++) {
		// sending the data through EUSART2 peripheral
		USART_0_write(data[i]);
	}
}

/**
  @Param
  none
  @Returns
   none
  @Description
  This function measures Frequency and Duty cycle of the input signal given by signal measurement
  **/
void FrequencyAndDutycycleMeasurement(void)
{
	uint8_t decValue = 0;

	if (samplescount == MAXSAMPLES_COUNT) {
		// Sum of period and pulse width samples value of input signal
		// is copied to perioAfterCapture and pulseWidthAfterCature variable
		periodAfterCapture     = periodSum;
		pulseWidthAfterCapture = pulseWidthSum;

		// Averaging of the samples
		periodAfterCaptureAvg     = (periodAfterCapture / MAXSAMPLES_COUNT);
		pulseWidthAfterCaptureAvg = (pulseWidthAfterCapture / MAXSAMPLES_COUNT);

		// Using formula to calculate the Frequency and Duty cycle of the signal
		captureDuty      = ((pulseWidthAfterCaptureAvg * 100L) / periodAfterCaptureAvg);
		captureFrequency = (F_CPU / periodAfterCaptureAvg);

		periodSum     = 0;
		pulseWidthSum = 0;
		samplescount  = 0;
	}

	// If condition is executed for every one second of the RTC interrupt
	if (rtcFlag == 1) {
		decValue = (captureDuty % MAXSAMPLES_COUNT);
		// Prints measured Frequency and Duty cycle of the signal on terminal window.
		sprintf(buffer, "Duty cycle=%lu.%d%% \r\nFrequency=%luHz\r\n\n", captureDuty, decValue, captureFrequency);
		SendString(buffer);
		rtcFlag          = 0;
		captureDuty      = 0;
		captureFrequency = 0;
	}
}
