/*
 * application_isr.h
 *
 * Created: 3/13/2020 2:53:31 PM
 *  Author: I51005.LA
 */

#ifndef APPLICATION_ISR_H_
#define APPLICATION_ISR_H_

/**
 * **********************************************************
 *  Macros definitions
 * **********************************************************
 **/

#include <atmel_start.h>
#include "application.h"
#include <compiler.h>

int8_t RTC_0_init();
int8_t TIMER_0_init();

#endif /* APPLICATION_ISR_H_ */
