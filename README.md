# Wordclock-v11

Wordclock for ATMega328 ICs and WS2812B LED matrices

This is a woking version, but not the nicest code. I started rewriting it completely and named it v12, you can find it in another repo: [https://github.com/t-bence/Wordclock-v12](https://github.com/t-bence/Wordclock-v12)

## Licenses

Uses the Timezone library by JChristiensen

Uses the DS3231 RTC using Rinky-Dinky electronics code by Hanning Karlsen

Loosely based on TinkerElectric.com Word Clock

This code uses the DS1307 Real Time Clock and presents the appropriate time in words. Original code by John Missikos and Damien Brombal (c) 2013

Libraries used include:

- NeoPixel Ring simple sketch (c) 2013 Shae Erisson, Adafruit
- [Arduino Time](http://www.arduino.cc/playground/Code/Time)
- [Timezone by JChristensen](https://github.com/JChristensen/Timezone)

## Note to self

Continue: remove Time library and DS3231 library
Add Adafruits RTClib and use that together with the Timezone library.
Hopefully that avoids conflicts with the Time.h header name.
