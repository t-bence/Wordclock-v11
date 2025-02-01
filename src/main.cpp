#ifdef MCU
    #include <Arduino.h>
    #include <DS3231.h>
    #include <LocalTime.h>
    #include <Display.h>
    #include <NeoPixelDisplay.h>
#else
    #include "ConsoleDisplay.h"
    #include "MockRtc.h"
#endif

#include <Writer.h>
#include <Debug.h>

// init RTC
DS3231 rtc(SDA, SCL);

// neopixel setup
const int LED_PIN = 12;

// colors
#define colorButtonPin 2

const unsigned long TWOHALF_MINUTES = 150;

// to debounce the buttons
volatile unsigned long colorTimer = 0;

#ifdef MCU
    Adafruit_NeoPixel pixels(110, LED_PIN);

    NeoPixelDisplay display(&pixels);
#else
    ConsoleDisplay display;
#endif

Writer writer(&display);


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

void setup() {

    #ifdef DEBUG
    Serial.begin(9600);
    pixels.begin();
    #endif

    PRINTLN("Starting...");

    rtc.begin();
    PRINTLN("RTC initialized.");

    pinMode(colorButtonPin, INPUT); // pullup resistor, no need for extra resistor in the circuit
    attachInterrupt(digitalPinToInterrupt(colorButtonPin), colorButtonPressed, RISING);
    PRINTLN("Button interrupt attached.");

    PRINTLN("Pixels started.");

}

void loop() {
    auto localTime = getLocalTime(
        rtc.getUnixTime(rtc.getTime()),
        TWOHALF_MINUTES
    );
    // PRINTLN(localTime);
    writer.updateTime(localTime);
}

#ifdef NATIVE
int main() {
    setup();
    while (true) {
        loop();
    }
}
#endif