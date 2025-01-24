#ifndef COLORS_H
#define COLORS_H

#include <Adafruit_NeoPixel.h>

uint32_t COLORS[] = {
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

#endif