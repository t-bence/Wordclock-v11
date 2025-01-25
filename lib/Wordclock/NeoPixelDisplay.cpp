#include <NeoPixelDisplay.h>

const int EEPROM_ADDR = 0;

NeoPixelDisplay::NeoPixelDisplay(Adafruit_NeoPixel& pixels)
        : pixels(pixels) {

    // read from EEPROM.
    colorId = EEPROM.read(EEPROM_ADDR);
    if (colorId >= NUMBER_OF_COLORS)
    { // if an error has occured
        colorId = 0;
    }

    pixels.begin();
    pixels.setBrightness(255); // 0-255
    pixels.clear();

    pixels.show();
    Serial.println("NeoPixel has begun");
}

void NeoPixelDisplay::show(LightSegment w) {
    uint32_t chosenColor = COLORS[colorId];
    pixels.fill(chosenColor, w.start, w.length);
}

void NeoPixelDisplay::setNextColor() {
    colorId++;
    colorId = colorId % NUMBER_OF_COLORS;

    EEPROM.write(EEPROM_ADDR, colorId);
}

void NeoPixelDisplay::clear() {
    pixels.clear();
}

void NeoPixelDisplay::show() {
    pixels.show();
}