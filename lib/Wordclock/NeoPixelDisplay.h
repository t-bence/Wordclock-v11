#ifndef NEOPIXELDISPLAY_H
#define NEOPIXELDISPLAY_H

#include <Display.h>
#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>

class NeoPixelDisplay : public Display {
public:
    NeoPixelDisplay(uint8_t pin);
    void show(LightSegment w) override;
    void setNextColor() override;
    void clear() override;
    void show() override;

private:
    Adafruit_NeoPixel& pixels;
    volatile int colorId;
};

const uint32_t COLORS[] = {
    Adafruit_NeoPixel::Color(127, 127, 0), // yellow
    Adafruit_NeoPixel::Color(250, 250, 0), // bright yellow
    Adafruit_NeoPixel::Color(127, 0, 127), // purple
    Adafruit_NeoPixel::Color(250, 0, 250), // pink
    Adafruit_NeoPixel::Color(0, 127, 127), // cyan
    Adafruit_NeoPixel::Color(0, 250, 250), // bright cyan
    Adafruit_NeoPixel::Color(127, 0, 0),   // red
    Adafruit_NeoPixel::Color(255, 0, 0),   // bright red
    Adafruit_NeoPixel::Color(0, 127, 0),   // green
    Adafruit_NeoPixel::Color(0, 250, 0),   // bright green
    Adafruit_NeoPixel::Color(0, 0, 127),   // blue
    Adafruit_NeoPixel::Color(0, 0, 255),   // bright blue
    Adafruit_NeoPixel::Color(127, 127, 127), // light white
    Adafruit_NeoPixel::Color(250, 250, 250), // bright white
    Adafruit_NeoPixel::Color(250, 100, 0)   // orange
};

#define NUMBER_OF_COLORS 15

#endif // NEOPIXELDISPLAY_H
