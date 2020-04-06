/*
 * application_isr.c
 *
 * Created: 3/13/2020 10:28:23 AM
 *  Author: I51005.LA
 */

#include <atmel_start.h>
#include "application_isr.h"

extern uint8_t  rtcFlag;
extern uint32_t periodSum;
extern uint32_t pulseWidthSum;
extern uint8_t  samplescount;

/**
 * **********************************************************
 *  ISR

    For every one second RTC interrupt is generated
 * **********************************************************
 **/
ISR(RTC_PIT_vect)
{
	/* Insert your PIT interrupt handling code here */

	rtcFlag = 1;

	/* The interrupt flag has to be cleared manually */
	RTC.PITINTFLAGS = RTC_PI_bm;
}

/**
 * *********************************************************************************
 *  ISR

    Capture Interrupt is generated for every one period measurement of the signal
 * *********************************************************************************
 **/

ISR(TCB2_INT_vect)
{

	if (samplescount < MAXSAMPLES_COUNT) {
		pulseWidthSum += TCB2.CCMP;

		periodSum += TCB2.CNT;

		samplescount = samplescount + 1;
	} else {
		// no operation
	}

	TCB2.INTFLAGS = TCB_CAPT_bm;
}
