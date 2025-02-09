#ifndef WRITER_H
#define WRITER_H

#include <Display.h>
#include <Debug.h>
#include <WordclockWords.h>
#include <ClockTime.h>

class Writer {
public:
    Writer(Display* display);
    void updateTime(ClockTime time);
    void redraw();
private:
    void showWords(LightSegment words[], int size);
    void showTime();
    Display* display;
    ClockTime last;
};

#endif // WRITER_H
