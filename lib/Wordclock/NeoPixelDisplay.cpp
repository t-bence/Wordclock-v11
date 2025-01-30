#include <NeoPixelDisplay.h>

const int EEPROM_ADDR = 0;

NeoPixelDisplay::NeoPixelDisplay(uint8_t pin) {
    const uint16_t NUMPIXELS = 110;
    pixels = new Adafruit_NeoPixel(NUMPIXELS, pin, NEO_GRB + NEO_KHZ800); // Allocate dynamically

    // read from EEPROM.
    colorId = EEPROM.read(EEPROM_ADDR);
    if (colorId >= NUMBER_OF_COLORS)
    { // if an error has occured
        colorId = 0;
    }

    pixels->begin();
    pixels->setBrightness(255); // 0-255
    pixels->clear();

    pixels->show();
    Serial.println("Display started");
}

void NeoPixelDisplay::show(LightSegment w) {
    uint32_t chosenColor = COLORS[colorId];
    pixels->fill(chosenColor, w.start, w.length);
}

void NeoPixelDisplay::setNextColor() {
    colorId++;
    colorId = colorId % NUMBER_OF_COLORS;

    EEPROM.write(EEPROM_ADDR, colorId);
}

void NeoPixelDisplay::clear() {
    pixels->clear();
}

void NeoPixelDisplay::show() {
    pixels->show();
}