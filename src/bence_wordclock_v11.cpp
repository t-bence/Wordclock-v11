// Bence Wordclock v11

// EEPROM-ba menti a kivalasztott szint, es indulaskor ugyanazzal kezd!
// hasznaljuk JChristiensen Timezone library-jat

// this is the modified wordclock file by Bence TOTH

// to use the different digital clock: DS3231
// using Rinky-Dinky electronics code by Hanning Karlsen
//////////////////////////////////////////////////////////////////
//
// TinkerElectric.com
// Word Clock
//
// This code uses the DS1307 Real Time Clock and presents the appropriate
// time in words. Original code by John Missikos and Damien Brombal (c) 2013
//
// Libraries used include:
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson, Adafruit
///////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <Wire.h>
// #include <Button.h>
#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>
#include <DS3231.h>
#include <TimeLib.h>        //http://www.arduino.cc/playground/Code/Time
#include <Timezone.h>    //https://github.com/JChristensen/Timezone

// include the words
#include <WordclockWords.h>

// set up rules for changing time
TimeChangeRule myDST = {"CEST", Last, Sun, Mar, 2, 120};    //Daylight time = UTC + 2 hours
TimeChangeRule mySTD = {"CET", Last, Sun, Oct, 3, 60};     //Standard time = UTC + 1 hours
Timezone hunTZ(myDST, mySTD);

TimeChangeRule *tcr;        //pointer to the time change rule, use to get TZ abbrev
time_t utc, local;

// init RTC
DS3231 rtc(SDA, SCL);
Time t;

// neopixel setup
#define PIN               12
#define NUMPIXELS         110

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

byte zero = 0x00; //workaround for issue #527

int intHour = 0;
int intMinute = 0;

#define HUNGARIAN 0
#define ENGLISH 1

// nyelv beallitasa
#define LANGUAGE ENGLISH

// colours
#define colourButtonPin   2   // to adjust the colour
#define coloursDefined    15  // number of colours
volatile byte chosenColour = 0; // the colour currently stored

// ezek RGB szinek
uint32_t colours[] = {pixels.Color(127, 127, 0), // sarga
                                pixels.Color(250, 250, 0),
                                pixels.Color(127, 0, 127),
                                pixels.Color(250, 0, 250), // pink
                                pixels.Color(0, 127, 127), // cian
                                pixels.Color(0, 250, 250), // cian
                                pixels.Color(127, 0, 0), // piros
                                pixels.Color(255, 0, 0), // piros
                                pixels.Color(0, 127, 0),
                                pixels.Color(0, 250, 0), // zold
                                pixels.Color(0, 0, 127),
                                pixels.Color(0, 0, 255), // kek
                                pixels.Color(127, 127, 127), // halvany feher
                                pixels.Color(250, 250, 250), // eros feher
                                pixels.Color(250, 100, 0)}; // narancssarga

//Set the colour globally
volatile uint32_t colourOut = colours[chosenColour];

const int EEPROM_ADDR = 0;

const unsigned long REDRAW_PERIOD = 30000;

// to debounce the buttons
volatile unsigned long colourTimer = 0;
volatile bool redraw = true;
unsigned long redrawTimer = 0;

// =============================== FUNCTIONS BEGIN HERE ========================



void colourButtonPressed() {
    // check when was the last press for debouncing
    if (millis() - colourTimer > 400UL) {
        Serial.println("+++ Colour Button Pressed +++");
        chosenColour = chosenColour + 1;
        if (chosenColour > (coloursDefined-1)) { chosenColour = 0; }
        colourOut = colours[chosenColour];

        EEPROM.write(EEPROM_ADDR, chosenColour);

        redraw = true;
        colourTimer = millis();
    }
}


// ========= processing, displaying =============

void show(byte data[]) {
    byte start = data[0];
    byte len = data[1];

    for (int i = 0; i <= len; i++) {
        pixels.setPixelColor(start + i, colourOut);
    }
}

void clearAll() {
    for(int i = 0; i < NUMPIXELS; i++) {
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, 0); // switch all off
    }
}

// ez a fv allitja be az idot...
void showTimeHun(int hour, int min) {

    clearAll();

    bool showNext = false;

    // percek beallitasa
    // a percek / negyed orak
    if (min < 5) {
        show(MOST);
        show(ORA);
        show(VAN); // most, ora, van
    }
    else if (min < 10) {
        show(ORA);
        show(MULT);
        show(OT_MULT);
        show(PERCCEL); // ora, mult, ot, perccel
    }
    else if (min < 15) {
        show(ORA);
        show(MULT);
        show(TIZ_MULT);
        show(PERCCEL); // ora, mult, ot, perccel
    }
    else if (min < 20) {
        show(MOST);
        show(NEGYED);
        show(VAN); // most negyed van
        showNext = true;
    }
    else if (min < 25) {
        show(NEGYED);
        show(MULT);
        show(OT_MULT);
        show(PERCCEL);
        showNext = true;
    }
    else if (min < 30) {
        show(OT_MULVA);
        show(PERC);
        show(MULVA);
        show(FEL);
        showNext = true;
    }
    else if (min < 35) {
        show(MOST);
        show(FEL);
        show(VAN);
        showNext = true;
    }
    else if (min < 40) {
        show(FEL);
        show(MULT);
        show(OT_MULT);
        show(PERCCEL);
        showNext = true;
    }
    else if (min < 45) {
        show(FEL);
        show(MULT);
        show(TIZ_MULT);
        show(PERCCEL);
        showNext = true;
    }
    else if (min < 50) {
        show(MOST);
        show(HAROMNEGYED);
        show(VAN);
        showNext = true;
    }
    else if (min < 55) {
        show(TIZ_MULVA);
        show(PERC);
        show(MULVA);
        show(ORA);
        showNext = true;
    }
    else {
        show(OT_MULVA);
        show(PERC);
        show(MULVA);
        show(ORA);
        showNext = true;
    }

    if (showNext) {
        hour = hour + 1;
    }

    // csak 12 orat jelzunk, a nulla is 12
    if (hour == 0) { hour = 12; }
    else if (hour > 12) { hour -= 12; }

    // ora beallitasa
    switch (hour) {
        case 1:
            show(EGY);
            break;
        case 2:
            show(KETTO);
            break;
        case 3:
            show(HAROM);
            break;
        case 4:
            show(NEGY);
            break;
        case 5:
            show(OT);
            break;
        case 6:
            show(HAT);
            break;
        case 7:
            show(HET);
            break;
        case 8:
            show(NYOLC);
            break;
        case 9:
            show(KILENC);
            break;
        case 10:
            show(TIZ);
            break;
        case 11:
            show(TIZENEGY1);
            show(TIZENEGY2);
            break;
        case 12:
            show(TIZENKETTO);
            break;
        default:
            // do nothing
            break;
    }

    pixels.show();
}

// ez a fv allitja be az idot... angolul
void showTimeEng(int hour, int min) {

    clearAll();

    bool showNext = false;

    show(IT);
    show(IS);

    // percek beallitasa
    // a percek / negyed orak
    if (min < 5) {
        show(OCLOCK);
    }
    else if (min < 10) {
        show(FIVE_MIN);
        show(PAST); // ora, mult, ot, perccel
    }
    else if (min < 15) {
        show(TEN_MIN);
        show(PAST);
    }
    else if (min < 20) {
        show(QUARTER);
        show(PAST);
    }
    else if (min < 25) {
        show(TWENTY);
        show(PAST);
    }
    else if (min < 30) {
        show(TWENTY);
        show(FIVE_MIN);
        show(PAST);
    }
    else if (min < 35) {
        show(HALF);
        show(PAST);
    }
    else if (min < 40) {
        show(TWENTY);
        show(FIVE_MIN);  // five to
        show(TO);
        showNext = true;
    }
    else if (min < 45) {
        show(TWENTY);
        show(TO);
        showNext = true;
    }
    else if (min < 50) {
        show(QUARTER);
        show(TO);
        showNext = true;
    }
    else if (min < 55) {
        show(TEN_MIN);
        show(TO);
        showNext = true;
    }
    else {
        show(FIVE_MIN);
        show(TO);
        showNext = true;
    }

    if (showNext) {
        hour = hour + 1;
    }

    // csak 12 orat jelzunk, a nulla is 12
    if (hour == 0) { hour = 12; }
    else if (hour > 12) { hour -= 12; }

    // ora beallitasa
    switch (hour) {
        case 1:
            show(ONE);
            break;
        case 2:
            show(TWO);
            break;
        case 3:
            show(THREE);
            break;
        case 4:
            show(FOUR);
            break;
        case 5:
            show(FIVE);
            break;
        case 6:
            show(SIX);
            break;
        case 7:
            show(SEVEN);
            break;
        case 8:
            show(EIGHT);
            break;
        case 9:
            show(NINE);
            break;
        case 10:
            show(TEN);
            break;
        case 11:
            show(ELEVEN);
            break;
        case 12:
            show(TWELVE);
            break;
        default:
            // do nothing in case of errors
            break;
    }

    pixels.show();
}


void showTime(int hour, int min) {
    if (LANGUAGE == HUNGARIAN) {
      showTimeHun(hour, min);
    }
    else {
      showTimeEng(hour, min);
    }
}

//Print an integer in "00" format (with leading zero).
//Input value assumed to be between 0 and 99.
void sPrintI00(int val)
{
    if (val < 10) Serial.print('0');
    Serial.print(val, DEC);
}

//Print an integer in ":00" format (with leading zero).
//Input value assumed to be between 0 and 99.
void sPrintDigits(int val)
{
    Serial.print(':');
    if(val < 10) Serial.print('0');
    Serial.print(val, DEC);
}

//Function to print time with time zone
void printTime(time_t t, char *tz)
{
    sPrintI00(hour(t));
    sPrintDigits(minute(t));
    sPrintDigits(second(t));
    Serial.print(' ');
    Serial.print(dayShortStr(weekday(t)));
    Serial.print(' ');
    sPrintI00(day(t));
    Serial.print(' ');
    Serial.print(monthShortStr(month(t)));
    Serial.print(' ');
    Serial.print(year(t));
    Serial.print(' ');
    Serial.print(tz);
    Serial.println();
}


void writeTime() {
  utc = (time_t) rtc.getUnixTime(rtc.getTime());
  //printTime(utc, "UTC");
  local = hunTZ.toLocal(utc, &tcr);
  printTime(local, tcr -> abbrev);

  intHour = hour(local);
  intMinute = minute(local);

  showTime(intHour, intMinute);
}


// =========================================================
void setup() {
    Serial.begin(115200); // debugging only

    Serial.println("Staring up...");
    Wire.begin();
    // Serial.println("Wire has begun");

    rtc.begin();
    // Serial.println("RTC has begun");

    pinMode(colourButtonPin, INPUT_PULLUP); // pullup resistor, no need for extra resistor in the circuit
    attachInterrupt(digitalPinToInterrupt(colourButtonPin), colourButtonPressed, RISING); // attach interrupt

    // read from EEPROM
    chosenColour = EEPROM.read(EEPROM_ADDR);
    if (chosenColour >= coloursDefined) { // if an error has occured
      chosenColour = 0;
    }
    colourOut = colours[chosenColour];


    pixels.begin(); // This initializes the NeoPixel library.
    pixels.setBrightness(255); // 0-255
    clearAll();

    pixels.show();  // reset to no colors
    Serial.println("NeoPixel has begun");

    redraw = true; // write time immediately
}

void loop() {

  if ((millis() - redrawTimer > REDRAW_PERIOD) or (redraw)) {
    writeTime();
    redrawTimer = millis();
    redraw = false;
  }

} // end of loop()
