#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>
#include <DS3231.h>
#include <TimeLib.h>        // http://www.arduino.cc/playground/Code/Time
#include <Timezone.h>       // https://github.com/JChristensen/Timezone

// custom code
#include <WordclockWords.h>
#include <Debug.h>
#include <Colors.h>

// set up rules for changing time
TimeChangeRule myDST = {"CEST", Last, Sun, Mar, 2, 120};    //Daylight time = UTC + 2 hours
TimeChangeRule mySTD = {"CET", Last, Sun, Oct, 3, 60};     //Standard time = UTC + 1 hours
Timezone hunTZ(myDST, mySTD);

TimeChangeRule *tcr;        // pointer to the time change rule
time_t utc, local;

// init RTC
DS3231 rtc(SDA, SCL);
Time t;

// neopixel setup
#define PIN               12
#define NUMPIXELS         110

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

byte zero = 0x00; //workaround for issue #527

#define TWO_HALF_MINUTES 150 // 2.5 minutes in seconds

int intHour = 0;
int intMinute = 0;

#define HUNGARIAN 0
#define ENGLISH 1

// set language
#define LANGUAGE HUNGARIAN

// colors
#define colorButtonPin   2   // to adjust the color
#define colorsDefined    15  // number of colors
volatile byte chosenColor = 12; // the color currently stored

//Set the color globally
volatile uint32_t colorOut = COLORS[chosenColor];

const int EEPROM_ADDR = 0;

const unsigned long REDRAW_PERIOD = 30000; // milliseconds

// to debounce the buttons
volatile unsigned long colorTimer = 0;
volatile bool redraw = true;
unsigned long redrawTimer = 0;


// set next color, save to EEPROM and force redraw
void colorButtonPressed() {
    // check when was the last press for debouncing
    if (millis() - colorTimer > 400UL) {
        Serial.println("+++ color Button Pressed +++");
        chosenColor = chosenColor + 1;
        if (chosenColor > (colorsDefined-1)) { chosenColor = 0; }
        colorOut = COLORS[chosenColor];

        EEPROM.write(EEPROM_ADDR, chosenColor);

        redraw = true;
        colorTimer = millis();
    }
}


void show(byte data[]) {
    byte start = data[0];
    byte len = data[1];

    for (int i = 0; i <= len; i++) {
        pixels.setPixelColor(start + i, colorOut);
    }
}

// this function turns all LEDs off
void clearAll() {
    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, 0);
    }
}

// this function shows the time in Hungarian
void showTimeHun(int hour, int min) {

    clearAll();

    bool showNext = false;

    // set minutes
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

    // set hours
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
            show(ERROR);
            break;
    }

    pixels.show();
}

// this function displays the time in English
void showTimeEng(int hour, int min) {

    clearAll();

    bool showNext = false;

    show(IT);
    show(IS);

    // set minutes
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

    // set hour
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
            show(ERROR);
            break;
    }

    pixels.show();
}

void updateAndShowTime() {
  // Get the current UTC time from the RTC
  utc = (time_t) rtc.getUnixTime(rtc.getTime());
  
  // Convert UTC time to local time
  local = hunTZ.toLocal(utc, &tcr);

  // subtract 2.5 minutes to "center" the range
  local -= TWO_HALF_MINUTES;
  
  // Print the local time with the time zone abbreviation
  printTime(local, tcr->abbrev);

  // Extract the hour and minute from the local time
  intHour = hour(local);
  intMinute = minute(local);

  // show hours between 1-12
  if (intHour == 0) { intHour = 12; }
  else if (intHour > 12) { intHour -= 12; }

  // Show the time based on the selected language
  if (LANGUAGE == HUNGARIAN) {
    showTimeHun(intHour, intMinute);
  } else {
    showTimeEng(intHour, intMinute);
  }
}

void setup() {
    Serial.begin(115200); // debugging only

    Serial.println("Starting up...");
    Wire.begin();
    // Serial.println("Wire has begun");

    rtc.begin();
    // Serial.println("RTC has begun");

    pinMode(colorButtonPin, INPUT); // pullup resistor, no need for extra resistor in the circuit
    attachInterrupt(digitalPinToInterrupt(colorButtonPin), colorButtonPressed, RISING);

    // read from EEPROM.
    chosenColor = EEPROM.read(EEPROM_ADDR);
    if (chosenColor >= colorsDefined) { // if an error has occured
      chosenColor = 0;
    }
    colorOut = COLORS[chosenColor];


    pixels.begin(); // This initializes the NeoPixel library.
    pixels.setBrightness(255); // 0-255
    clearAll();

    pixels.show();  // reset to no colors
    Serial.println("NeoPixel has begun");

    redraw = true; // write time immediately
}

void loop() {

  if ((millis() - redrawTimer > REDRAW_PERIOD) or (redraw)) {
    updateAndShowTime();
    redrawTimer = millis();
    redraw = false;
  }

}
