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
#include <WordclockWords.h>
#include <LocalTime.h>
#include <Debug.h>
#include <Colors.h>

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

void show(Word w)
{
    pixels.fill(chosenColor, w.start, w.length);
}

void showWords(Word words[], int size)
{
    for (int i = 0; i < size; i++)
    {
        show(words[i]);
    }
}

void showTime(int hour, int min)
{
    pixels.fill(); // clear the strip

    int index = min / 5;
    if (index >= 12) index = 0; // handle edge case for 60 minutes

#ifdef HUNGARIAN

    showWords(TIME_WORDS[index], sizeof(TIME_WORDS[index]) / sizeof(Word));

    if (index >= 3) // if it's past the first quarter
    {
        hour = (hour + 1) % 12;
    }

    show(HOURS[hour]);
    if (hour == 11)
    {
        show(HOURS[12]); // 11 consists of two word parts in Hungarian
    }

#endif
#ifdef ENGLISH

    show(IT);
    show(IS);
    showWords(TIME_WORDS[index], sizeof(TIME_WORDS[index]) / sizeof(Word));

    if (index >= 7) // if it's past half
    {
        hour = (hour + 1) % 12;
    }

    show(HOURS[hour]);

#endif
    pixels.show();
}

void setup()
{
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

        showTime(localTime.hour, localTime.minute);

        redrawTimer = millis();
        redraw = false;
    }
}
