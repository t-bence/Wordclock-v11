#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <DS3231.h>

// custom code
#include <LocalTime.h>
#include <Writer.h>
#include <NeoPixelDisplay.h>

// init RTC
DS3231 rtc(SDA, SCL);

// neopixel setup
#define PIN 12
#define NUMPIXELS 110

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// colors
#define colorButtonPin 2        // to adjust the color

// to debounce the buttons
volatile unsigned long colorTimer = 0;

NeoPixelDisplay neoPixelDisplay(pixels);
Writer writer(neoPixelDisplay);

// set next color, save to EEPROM and force redraw
void colorButtonPressed()
{
    if (millis() - colorTimer > 400UL)
    {
        Serial.println("Color button pressed");
        neoPixelDisplay.setNextColor();
        writer.redraw();
        colorTimer = millis();
    }
}

void setup()
{
    initializeSegments();

    Serial.begin(115200); // debugging only

    Serial.println("Starting up...");
    Wire.begin();

    rtc.begin();

    pinMode(colorButtonPin, INPUT); // pullup resistor, no need for extra resistor in the circuit
    attachInterrupt(digitalPinToInterrupt(colorButtonPin), colorButtonPressed, RISING);

}

void loop()
{
    auto localTime = getLocalTime(rtc.getUnixTime(rtc.getTime()));
    writer.updateTime(localTime);
}
