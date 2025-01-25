#ifndef DISPLAY_H
#define DISPLAY_H

#include <WordclockWords.h>

class Display {
public:
    virtual void show(LightSegment seg) = 0;
    virtual void setNextColor() = 0;
    virtual void clear() = 0;
    virtual void show() = 0;
};

#endif // DISPLAY_H