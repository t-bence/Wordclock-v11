#ifndef WRITER_H
#define WRITER_H

#include <Display.h>
#include <WordclockWords.h>

class Writer {
public:
    Writer(Display& display);
    void showWords(LightSegment words[], int size);
    void showTime(int hour, int min);

private:
    Display& display;
};

#endif // WRITER_H
