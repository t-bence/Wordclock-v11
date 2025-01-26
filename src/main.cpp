// files for MCU
#ifdef MCU
    #include <Arduino.h>
    #include <DS3231.h>
    #include <LocalTime.h>
    #include <NeoPixelDisplay.h>
#else
    #include "ConsoleDisplay.h"
    #include "MockRtc.h"
#endif

#include <Writer.h>


// init RTC
DS3231 rtc(SDA, SCL);

// neopixel setup
const int LED_PIN = 12;

// colors
#define colorButtonPin 2

// to debounce the buttons
volatile unsigned long colorTimer = 0;

#ifdef MCU
NeoPixelDisplay display(LED_PIN);
#else
ConsoleDisplay display;
#endif

Writer writer(display);

// set next color, save to EEPROM and force redraw
void colorButtonPressed()
{
    if (millis() - colorTimer > 400UL)
    {
        display.setNextColor();
        writer.redraw();
        colorTimer = millis();
    }
}

int main() {

    rtc.begin();

    pinMode(colorButtonPin, INPUT); // pullup resistor, no need for extra resistor in the circuit
    attachInterrupt(digitalPinToInterrupt(colorButtonPin), colorButtonPressed, RISING);

    while (true) {
        auto localTime = getLocalTime(rtc.getUnixTime(rtc.getTime()));
        writer.updateTime(localTime);
    }
}