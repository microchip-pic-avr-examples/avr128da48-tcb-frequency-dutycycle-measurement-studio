[![MCHP](https://cldup.com/U0qhLwBijF.png)](https://www.microchip.com)
# Introduction  
The Timer/Counter type B (TCB) module of the AVR-DA family of devices offers a variety of features and operation modes, from periodic interrupts to 8-bit PWM mode. The various operation modes of the TCB can be used in correlation with the event system. The capabilities of the 16-bit Timer/Counter type B includes single pulse generation and input capture on event with frequency and pulse width measurement of the digital signals. 
This example explains, how the Timer/Counter type B module of AVR128DA48 microcontroller is used to measure the frequency and duty cycle of the pulse waveform.

**Note:**

**1.	This example could be generated with all the pin variants of AVR-DA family of microcontrollers.**

**2.	This example is also generated using MPLAB and is available on GitHub at this location.**
https://github.com/microchip-pic-avr-examples/avr128da48-tcb-frequency-dutycycle-measurement-mplab-example.git
 

# Demo Description

***Fig 1: Block diagram view of the system used for Frequency and Duty cycle measurement.***

<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/QRyYNe9.jpg">
</p>

In this example,
* A signal generator is used as a source to generate input pulse signal, with a known frequency and duty cycle.
* The frequency of input pulse signal should be within the range of 500Hz to 200KHz.
* The frequency and duty cycle of the input pulse signal to be measured is fed to the pin PA6 of the microcontroller.
* Event system channel-0 is used to interact with pin PA6 and Timer/Counter type B, without CPU interaction. Here, pin PA6 is the event generator and Timer B module is the event user. 
* The timer is configured to work in the “Input capture frequency and pulse width measurement” mode. 
* In this mode, the timer starts counting when it detects a rising edge on the event input channel 0 and stops counting when it detects the next rising edge on the event channel 0. This will set the capture interrupt flag.
* After reading the Count (Period) or Compare (Pulse-width) register value, the capture interrupt flag is cleared, and the timer is ready for the new capture sequence.
* The frequency and duty cycle of the input pulse signal is calculated using period and pulse-width value and the formulae for calculation are:

<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/FQN6hLk.jpg">
</p>

* RTC is used in a Periodic Interrupt Timer (PIT) mode to generate a periodic interrupt, which is used as a trigger for the USART module to transmit the data to the data visualizer terminal window.

## To see the Frequency and Duty cycle meaurement demo operation video, click on the below image.


<a href="http://www.youtube.com/watch?feature=player_embedded&v=MuXe_AXPpC4
" target="_blank"><img src="https://i.imgur.com/fQ9DhZV.jpg"
alt="IMAGE ALT TEXT HERE" width="500" height="300" border="10" /></a>  


# Hardware

## AVR128DA48 Curiosity nano board

The Curiosity Nano boards features a variety of PIC® and AVR® microcontrollers, allowing rapid prototyping and easy evaluation of the design. They also offer full programming and debugging capabilities to support throughout the development process. 

***Fig 2 : AVR128DA48 Curiosity Nano board***

<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/wXBve17.jpg">
</p>

# Software Tools

Microchip’s IDEs, compiler and graphical code generators are used throughout the application firmware development to provide an easy and hassle-free user experience. Following are the tools which are used for this demo application:
* Atmel Studio v 7.0.2397
* Atmel | START v 1.6.1894
* Standalone Data Visualizer v 2.20.674

**Note: For running the demo, the installed tool versions should be the same or later. This example is not tested with the previous versions.**


# Hardware setup

The following figure shows the hardware connection details.
* Connect output pin of signal generator, which generates pulse signal, to pin PA6 of the  AVR128DA48 curiosity nano board.
* Connect GND pin of the signal generator to GND pin of the AVR128DA48 curiosity nano board.

***Fig 3 : Hardware setup***

<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/if4dOY3.jpg">
</p>

## Steps to open terminal window in Data Visualizer:

Open the terminal window in Standalone Data Visualizer tool to observe the measured frequency and duty cycle data of the application and follow the below mentioned steps to open terminal window.
1.	In the Data Visualizer window, click on the **Configuration tab**.
2.	In the **Modules section**, expand **External connection** option and then double click on Serial Port.
3.	Select the **Curiosity Virtual Com Port** in Serial Port Control Panel.
4.	Set the Baud rate to **115200**.
5.	Check the **Open Terminal** option.
6.	Click on the **Connect button**, then terminal window is opened.

***Fig 4 : Open Terminal window in Data visualizer***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VTxQJZC.jpg">
</p>

# Demo Operation:

* Setup the hardware as shown in Fig 3 of the hardware setup section.
* After the Curiosity Nano board is powered on, load the application firmware to AVR128DA48 microcontroller.
* Open the terminal window to observe the measured frequency and duty cycle data.
* Set the desired frequency (between 500Hz to 200KHz) and duty cycle (5% to 95%), and check the data displayed on the terminal window.
* For example: Set the frequency to 100KHz and duty cycle to 70% in the signal generator and observe the measured frequency and duty cycle displayed on the terminal window.

***Fig 5 : Generate Pulse signal of frequency 100KHz and duty cycle 70%***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/YCit6iU.jpg">
</p>

***Fig 6 : Open Terminal window in Data visualizer.***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/uRBeLAb.jpg">
</p>

# Summary : 

Timer/Counter type B (TCB) can be configured in one of the eight possible operating modes,  each mode provides unique functionality. This is one of the applications, which explains how the timer is configurable in “Frequency and Pulse-width measurement mode” to measure frequency and duty cycle of the input signal. Measuring the frequency (1/period) or pulse-width of an input signal is useful in applications such as tachometers, Frequency meter, DC motor control etc.


# Appendix : Atmel | START Project creation

Configure Timer, Event system, GPIO, RTC, USART peripherals  through Atmel|START code configurator and generate Atmel Studio project. 

Follow the below steps to generate the project using Atmel|START.

1.	Open **Atmel Studio 7**.
2.	Go to **File → New** and click on **Atmel Start Project** option.
3.	The **CREATE NEW PROJECT** window appears within Atmel Studio 7. In the **"Filter on device..."** text box, enter **AVR128DA48**, then select **AVR128DA48 Curiosity Nano** from the list and then click on **CREATE NEW PROJECT**, as shown below. Wait until project creation is completed.

***Fig 7 : Create New Project***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/rUuNAQ0.jpg">
</p>

4.	After project creation, **MY SOFTWARE COMPONENTS** window opens. 
* Open **PINMUX** configuration by clicking on ![](https://i.imgur.com/ggqjWKi.jpg) icon in the navigation tab, located on the left side of the window.
* Configure I/O pin **PA6** as input as shown in the Fig 8. The frequency and duty cycle of the input pulse signal to be measured is fed to the I/O pin PA6.

***Fig 8 : PINMUX Configuration pin PA6***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/jC5Rdqm.jpg">
</p>

5.	Add **Timer B, Event system, USART and RTC** components to the project
* Click ![](https://i.imgur.com/PXgXvRm.jpg) icon in the navigation tab, located on the left side of the window. Then, open the ADD SOFTWARE COMPONENTS window by clicking ![](https://i.imgur.com/AFqwPll.jpg) icon.
* Expand Drivers by clicking + icon.
* To add components to the project, select Timer , Event System, RTC, USART and click on ![](https://i.imgur.com/dA4nv4t.jpg) icon.
* Add the respective drivers to the project by clicking the Add component(s).

***Fig 9 :  ADD SOFTWARE COMPONENTS***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/pPU5ykh.jpg">
</p>

6.	Open the **CLOCK CONFIGURATOR** window by clicking ![](https://i.imgur.com/TOX2iTj.jpg) CLOCKS icon in the navigation tab, located at the left side of the window as shown in the Fig 10.

***Fig 10 : CLOCK configurator***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/CI8Fpk0.jpg">
</p>

* Configure the **Internal high-frequency oscillator** by clicking **CLOCK SETTINGS** ![](https://i.imgur.com/Q76XwcD.jpg) icon as shown in the Fig 10.
* By default, Internal high-frequency oscillator is configured to 4MHz frequency. Set the **Frequency Select** to **24** from the dropdown menu, which generates 24MHz frequency as shown in Fig 11.

***Fig 11 : CLOCK settings***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/xdL7Hq6.jpg">
</p>

## Timer B configuration:
 Timer B is a 16-bit Timer which is configured in Input Capture Frequency and Pulse-Width measurement mode and it is used to measure the period and pulse-width of the input signal. In this mode, the timer will start counting when a positive edge is detected on the event channel connected to the pin PA6. 
 Configure the TIMER_0 module by following the steps  as shown in the Fig 12. 
* Open the configuration window for TIMER by clicking on **TIMER_0**.
* Select **Drivers: TCB: Init** option from the dropdown menu against the Driver field, which selects Timer/Counter type B peripheral.
* Select **TCB2** option from the dropdown menu against the Instance field.
* Check the Enable option to enable the TCB2 module.
* Select **CLK_PER** option from the dropdown menu against the CLKSEL: Clock Select field, which uses 24MHz system clock as a clock source for this peripheral.
* Select **Input Capture Frequency and Pulse-Width measurement** mode option from the dropdown menu against the CNTMODE: Timer Mode field, which captures period and pulse-width value of the input signal.
* Check the **CAPT: Capture or Timeout** option to generate the capture interrupt. The capture interrupt flag is generated after capturing the period and pulse-width of the input signal.
* Check the **CAPTEI: Event Input Enable** option to enable the timer to start counting when it detects rising edge on the event channel connected to the pin PA6.

***Fig 12 : Timer B configuration***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/cKjgJsP.jpg">
</p>

## Event system configuration: 
In this example, event system is used to connect the pin PA6 to the TCB2 through channel 0. The frequency and duty cycle of the input signal to be measured can’t be given directly to the TCB2, is given to the pin PA6 through event channel to the timer module. 
Configure the Event system module by following the steps shown in the Fig 13. 
* In event generator, select **PORT A PIN6** option and drag the cursor to the **Connect user to event channel 0** option and from **Connect user to event channel 0** option, drag the cursor to the **Event Input Enable** option in TCB2.

***Fig 13 : Event system configurator***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/Rbed3bn.jpg">
</p>

## USART1 Configuration:
 USART1 is used to transmit the measured frequency and duty cycle data of the input signal to the terminal window. Configure the USART1 module by following the steps shown in the Fig 14.
* Select **Drivers: USART: Basic** option from the dropdown menu against the Driver field.
* Select **Async IRQ Mode** option from the dropdown menu against the Mode field.
* Select the **USART1** option from the dropdown menu against the Instance field.
* Select **PC0** as output from the dropdown menu against the TXD field.
* Check the **Transmitter: Enable** option, which allows the data to transmit through USART peripheral.
* Set the **Baud Rate** to **115200**.

***Fig 14 : USART configuration***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VETmPQQ.jpg">
</p>

## RTC configuration:
 In this example RTC is configured in PIT (Periodic Interrupt Timer) mode, which generates a periodic interrupt after every 32768 RTC Clock cycles (1 sec delay). The periodic interrupt is used as a trigger for the USART to display data on to the terminal window. Configure the RTC module by following the steps shown in the Fig 15.
* Select **Drivers: RTC: Init** option from the dropdown menu against the Driver field.
* Check the **PITEN: Enable** option to enable the periodic interrupt timer mode.
* Select the clock **Internal 32.768KHz oscillator** option from the dropdown menu against the **RTC Clock Source Selection** field, which uses 32.768 KHz oscillator as a clock source for the PIT mode.
* Select the period **RTC Clock Cycles 32768** option from the dropdown menu against the **PERIOD: Period** field, which generates 1 sec delay.
* Check the **PI: Periodic Interrupt** option to generate periodic interrupt after specified RTC clock cycles.

***Fig 15 : RTC configuration***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/zHlkewc.jpg">
</p>


## Global Interrupt Enable configuration:
To generate the interrupt, it is required to enable the Global Interrupt Enable bit in the Status register.
* Click on the icon next to **"Show system drivers"** option, as shown  in the Fig 16.

***Fig 16 : Show system drivers***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/9zGu2eY.jpg">
</p>

* Click the **CPUINT** and then select the checkbox, **CPU_SREG: Global Interrupt Enable**, as shown in the Fig 17.

***Fig 17 : Enable CPU_SREG***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/3nL7Z27.jpg">
</p>























