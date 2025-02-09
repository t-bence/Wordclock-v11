# Bence's wordclock

This wordclock displays the current time by lighting up the LEDs behind the letters that write out the time.

It is built for ATMega328 ICs and WS2812B LED matrices.

The code is also my device to learn C++ and improve my programming skills. Currently, it (somewhat) follows the separation of concerns principle, which makes it possible to test its working principle. There is a test file for it, that runs in native environment (e.g. my computer) and the main code, that compiles for the IC. Plus, the project builds and runs on my computer, too!

It used to be possible to configure the clock to display English or Hungarian lettering, with another option to specify whether the LED strand starts on the left or the right (when viewed from the front). This is currently not possible, but the required data is available in the [layouts.md](lib/Display/layouts.md) file.

## Usage

To run in debug mode, which means writing everything to Serial, you should change the `DEBUG=0` to `DEBUG=1` in `platformio.ini`.

## Libraries

Some of the used libraries are:

- DS3231 RTC from Rinky-Dinky electronics code by Hanning Karlsen
- TinkerElectric.com Word Clock. Original code by John Missikos and Damien Brombal (c) 2013
- NeoPixel Ring simple sketch (c) 2013 Shae Erisson, Adafruit
- [Arduino Time](http://www.arduino.cc/playground/Code/Time)
- [Timezone by JChristensen](https://github.com/JChristensen/Timezone)

## About interrupts

The code uses an interrupt to control when the lights are supposed to change. This however varies (might vary?) from clock to clock.

For the custom-made PCB, the following settings seem to work:

- `pinMode`: `INPUT_PULLUP`
- `attachInterrupt`: `FALLING`

Originally, the code contained the following:

- `pinMode`: `INPUT`
- `attachInterrupt`: `RISING`

It is not clear whether these settings are required for any hardware, but if the above ones don't work, try these as well!
