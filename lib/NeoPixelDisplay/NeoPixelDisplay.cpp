#include <NeoPixelDisplay.h>

const int EEPROM_ADDR = 0;
const int NUMPIXELS = 110;

NeoPixelDisplay::NeoPixelDisplay(Adafruit_NeoPixel* p) : pixels(p) {

    // read from EEPROM.
    //colorId = EEPROM.read(EEPROM_ADDR);
    colorId = 0;
    if (colorId >= NUMBER_OF_COLORS)
    { // if an error has occured
        colorId = 0;
    }
}

NeoPixelDisplay::~NeoPixelDisplay() {
    Serial.println("Deleting Adafruit_NeoPixel instance...");
    delete pixels;
}

void NeoPixelDisplay::show(LightSegment w) {
    uint32_t chosenColor = COLORS[colorId];
    pixels->fill(chosenColor, w.start, w.length);
}

void NeoPixelDisplay::setNextColor() {
    colorId++;
    colorId = colorId % NUMBER_OF_COLORS;

    // EEPROM.write(EEPROM_ADDR, colorId);
}

void NeoPixelDisplay::clear() {
    pixels->clear();
}

void NeoPixelDisplay::show() {
    pixels->show();
}