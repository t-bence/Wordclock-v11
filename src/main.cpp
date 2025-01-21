// set language: ENGLISH or HUNGARIAN
#define HUNGARIAN
// set LED direction of the top row when viewing from the front: LEFT_TO_RIGHT or RIGHT_TO_LEFT
#define LEFT_TO_RIGHT

#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>
#include <RTClib.h>

// custom code
#include <WordclockWords.h>
#include <LocalTime.h>
#include <Debug.h>
#include <Colors.h>

// init RTC
RTC_DS3231 rtc;

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

// this function shows the time
void showTime(int hour, int min)
{
    pixels.fill(); // clear the strip

    bool showNext = false;

#ifdef HUNGARIAN

    if (min < 5)
    {
        show(MOST);
        show(ORA);
        show(VAN); // most, ora, van
    }
    else if (min < 10)
    {
        show(ORA);
        show(MULT);
        show(OT_MULT);
        show(PERCCEL); // ora, mult, ot, perccel
    }
    else if (min < 15)
    {
        show(ORA);
        show(MULT);
        show(TIZ_MULT);
        show(PERCCEL); // ora, mult, ot, perccel
    }
    else if (min < 20)
    {
        show(MOST);
        show(NEGYED);
        show(VAN); // most negyed van
        showNext = true;
    }
    else if (min < 25)
    {
        show(NEGYED);
        show(MULT);
        show(OT_MULT);
        show(PERCCEL);
        showNext = true;
    }
    else if (min < 30)
    {
        show(OT_MULVA);
        show(PERC);
        show(MULVA);
        show(FEL);
        showNext = true;
    }
    else if (min < 35)
    {
        show(MOST);
        show(FEL);
        show(VAN);
        showNext = true;
    }
    else if (min < 40)
    {
        show(FEL);
        show(MULT);
        show(OT_MULT);
        show(PERCCEL);
        showNext = true;
    }
    else if (min < 45)
    {
        show(FEL);
        show(MULT);
        show(TIZ_MULT);
        show(PERCCEL);
        showNext = true;
    }
    else if (min < 50)
    {
        show(MOST);
        show(HAROMNEGYED);
        show(VAN);
        showNext = true;
    }
    else if (min < 55)
    {
        show(TIZ_MULVA);
        show(PERC);
        show(MULVA);
        show(ORA);
        showNext = true;
    }
    else if (min <= 60)
    {
        show(OT_MULVA);
        show(PERC);
        show(MULVA);
        show(ORA);
        showNext = true;
    }
    else
    {
        show(ERROR);
    }

    if (showNext)
    {
        hour = (hour + 1) % 12;
    }

    show(HOURS[hour]);
    if (hour == 11) 
    {
        show(HOURS[12]); // 11 consists of two word parts in Hungarian
        // we need to show the other portion, too
    }

#endif
#ifdef ENGLISH
    show(IT);
    show(IS);

    // set minutes
    // a percek / negyed orak
    if (min < 5)
    {
        show(OCLOCK);
    }
    else if (min < 10)
    {
        show(FIVE_MIN);
        show(PAST); // ora, mult, ot, perccel
    }
    else if (min < 15)
    {
        show(TEN_MIN);
        show(PAST);
    }
    else if (min < 20)
    {
        show(QUARTER);
        show(PAST);
    }
    else if (min < 25)
    {
        show(TWENTY);
        show(PAST);
    }
    else if (min < 30)
    {
        show(TWENTY);
        show(FIVE_MIN);
        show(PAST);
    }
    else if (min < 35)
    {
        show(HALF);
        show(PAST);
    }
    else if (min < 40)
    {
        show(TWENTY);
        show(FIVE_MIN); // five to
        show(TO);
        showNext = true;
    }
    else if (min < 45)
    {
        show(TWENTY);
        show(TO);
        showNext = true;
    }
    else if (min < 50)
    {
        show(QUARTER);
        show(TO);
        showNext = true;
    }
    else if (min < 55)
    {
        show(TEN_MIN);
        show(TO);
        showNext = true;
    }
    else if (min <= 60)
    {
        show(FIVE_MIN);
        show(TO);
        showNext = true;
    }
    else
    {
        show(ERROR);
    }

    if (showNext)
    {
        hour = (hour + 1) % 12;
    }

    // set hour
    show(HOURS[hour]);

#endif
    pixels.show();
}


void setup()
{
    Serial.begin(115200); // debugging only

    Serial.println("Starting up...");
    Wire.begin();

    if (!rtc.begin()) {
        Serial.println("Couldn't find RTC");
        Serial.flush();
        while (1) delay(10);
    }

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

void loop() {
    // Check if it's time to update and show the time
    if ((millis() - redrawTimer > REDRAW_PERIOD) || redraw) {
        auto localTime = getLocalTime(rtc.now().unixtime());

        Serial.print(localTime.hour); Serial.print('-'); Serial.println(localTime.minute);

        showTime(localTime.hour, localTime.minute);

        redrawTimer = millis();
        redraw = false;
    }
}
