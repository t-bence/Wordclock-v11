#ifndef NEOPIXELDISPLAY_H
#define NEOPIXELDISPLAY_H

#include <Display.h>
#include <EEPROM.h>
#include <Colors.h>
#include <Adafruit_NeoPixel.h>

class NeoPixelDisplay : public Display {
public:
    NeoPixelDisplay(Adafruit_NeoPixel& pixels);
    void show(LightSegment w) override;
    void setNextColor() override;
    void clear() override;
    void show() override;

private:
    Adafruit_NeoPixel& pixels;
    volatile int colorId;
};

#endif // NEOPIXELDISPLAY_H
