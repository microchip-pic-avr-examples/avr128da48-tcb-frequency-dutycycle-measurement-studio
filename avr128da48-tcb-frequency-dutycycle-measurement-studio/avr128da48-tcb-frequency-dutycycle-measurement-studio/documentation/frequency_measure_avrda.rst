Frequency and Duty cycle measurement of Pulse signal
====================================================

Introduction
============

This example explains, how Timer/Counter type B module of AVR128DA48 microcontroller is used to measure frequency and duty cycle  of a pulse signal. 
Note :This example could be generated with all the pin variants of AVR DA family of microcontrollers.


Demo Description
================

*	Signal generator is used as a source to generate input pulse signal with a known frequency and duty cycle.
*   The frequency of input pulse signal should be within the range of 500Hz to 200KHz.
*	The frequency and duty cycle of the input pulse signal to be measured is fed to pin PA6 of the MCU.
*	Event system channel-0 is used to interact with pin PA6 and Timer/Counter type B, without CPU interaction. Here, Pin PA6 is the event generator and Timer B module is the event user. 
*	The timer is configured to work in the "Input capture frequency and pulse width measurement" mode. 
*	In this mode, the timer starts counting when it detects a rising edge on the event input channel 0 and stops counting when it detects the next rising edge on the event channel 0. This will set the capture interrupt flag.
*	After reading the Count (Period) or Compare (Pulse-width) register value, capture interrupt flag is cleared, and timer is ready for the new capture sequence.
*	The frequency and duty cycle of input pulse signal is calculated using period and pulse-width value and the formula is 

                                         Frequency = (( Pulse-width x 100 ) / Period )
										 
                                         Duty cycle = (F_CPU / Period )

*	RTC is used in a Periodic Interrupt Timer (PIT) mode to generate a periodic interrupt, which is used as a trigger for the USART module to transmit the data to the data visualizer terminal window.


Video of the demo is available here: https://youtu.be/MuXe_AXPpC4

For more details about the example and configuration details in Studio IDE, refer the example posted on GitHub at this location : https://github.com/microchip-pic-avr-examples/avr128da48-tcb-frequency-dutycycle-measurement-studio

This example is also generated using MPLAB X IDE and is available on GitHub at this location : https://github.com/microchip-pic-avr-examples/avr128da48-tcb-frequency-dutycycle-measurement-mplab

Supported evaluation kit
========================

*   `AVR128DA48 Curiosity Nano Evaluation Kit <https://www.microchip.com/developmenttools/ProductDetails/DM164151>`_

Demo Operation
==============
*	After the Curiosity Nano board is powered on, load the firmware to AVR128DA48 MCU.
*	To observe data, open terminal window by connecting to serial port control panel and click on connect button.
*	Set the input  frequency and duty cycle on signal generator which is used as a source to generate the  input pulse signal  to be measured.
*	Observe the measured frequency and duty cycle  data on the terminal window.
*	Repeat the step 3 with different frequency and duty cycle , observe the measured data on the terminal window.


Running the demo
================

*   In Atmel START web page, select "EXPORT PROJECT" tab and click "Download Pack" to save the .atzip file.
*   Import .atzip file to Atmel Studio 7 IDE (File->Import->Atmel Start Project).
*   Build Solution and make sure the build is successful without any errors.
*   Press "Start without debugging" or use "CTRL+ALT+F5" hotkeys to run the application.



