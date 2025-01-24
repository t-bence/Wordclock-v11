// set language: ENGLISH or HUNGARIAN
#define HUNGARIAN
// set LED direction of the top row when viewing from the front: LEFT_TO_RIGHT or RIGHT_TO_LEFT
#define LEFT_TO_RIGHT

#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>
#include <DS3231.h>

// custom code
#include <LocalTime.h>
#include <Debug.h>
#include <Colors.h>
#include <Writer.h>
#include <Display.h>

// init RTC
DS3231 rtc(SDA, SCL);

// neopixel setup
#define PIN 12
#define NUMPIXELS 110

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// colors
#define colorButtonPin 2        // to adjust the color
#define colorsDefined 15        // number of colors
volatile byte chosenColor = 12; // the color currently stored

// Set the color globally
volatile uint32_t colorOut = COLORS[chosenColor];

const int EEPROM_ADDR = 0;

const unsigned long REDRAW_PERIOD = 10000; // milliseconds

// to debounce the buttons
volatile unsigned long colorTimer = 0;
volatile bool redraw = true;
unsigned long redrawTimer = 0;

// set next color, save to EEPROM and force redraw
void colorButtonPressed()
{
    if (millis() - colorTimer > 400UL)
    {
        Serial.println("Color button pressed");
        chosenColor = chosenColor + 1;
        if (chosenColor > (colorsDefined - 1))
        {
            chosenColor = 0;
        }
        colorOut = COLORS[chosenColor];

        EEPROM.write(EEPROM_ADDR, chosenColor);

        redraw = true;
        colorTimer = millis();
    }
}

class NeoPixelDisplay : public Display {
public:
    void show(LightSegment w) override {
        pixels.fill(chosenColor, w.start, w.length);
    }
};

NeoPixelDisplay neoPixelDisplay;
Writer writer(neoPixelDisplay);

void setup()
{
    initializeSegments();

    Serial.begin(115200); // debugging only

    Serial.println("Starting up...");
    Wire.begin();

    rtc.begin();

    pinMode(colorButtonPin, INPUT); // pullup resistor, no need for extra resistor in the circuit
    attachInterrupt(digitalPinToInterrupt(colorButtonPin), colorButtonPressed, RISING);

    // read from EEPROM.
    chosenColor = EEPROM.read(EEPROM_ADDR);
    if (chosenColor >= colorsDefined)
    { // if an error has occured
        chosenColor = 0;
    }
    colorOut = COLORS[chosenColor];

    pixels.begin();
    pixels.setBrightness(255); // 0-255
    pixels.fill();             // equivalent to clearing

    pixels.show();
    Serial.println("NeoPixel has begun");

    redraw = true; // write time immediately
}

void loop()
{
    // Check if it's time to update and show the time
    if ((millis() - redrawTimer > REDRAW_PERIOD) || redraw)
    {
        auto localTime = getLocalTime(rtc.getUnixTime(rtc.getTime()));

        Serial.print(localTime.hour);
        Serial.print('-');
        Serial.println(localTime.minute);

        pixels.clear();
        writer.showTime(localTime.hour, localTime.minute);
        pixels.show(); // actual displaying

        redrawTimer = millis();
        redraw = false;
    }
}
