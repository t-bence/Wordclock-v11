#ifndef DISPLAY_H
#define DISPLAY_H

#include <WordclockWords.h>

class Display {
public:
    virtual void show(LightSegment seg) = 0; // Pure virtual function
};

#endif // DISPLAY_H