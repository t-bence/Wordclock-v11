#ifndef WRITER_H
#define WRITER_H

#include <Display.h>
#include <Debug.h>
#include <WordclockWords.h>

class Writer {
public:
    Writer(Display& display);
    void updateTime(unsigned long newSeconds);
    void redraw();
private:
    int getHour(unsigned long offset);
    int getMinute(unsigned long offset);
    void showWords(LightSegment words[], int size);
    void showTime();
    Display& display;
    unsigned long seconds;
};

#endif // WRITER_H
