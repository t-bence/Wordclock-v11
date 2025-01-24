#ifndef DISPLAY_H
#define DISPLAY_H

#include <WordclockWords.h>

typedef void (*ShowFunction)(LightSegment);

class Display {
public:
    Display(ShowFunction showFunc);
    void showWords(LightSegment words[], int size);
    void showTime(int hour, int min);

private:
    ShowFunction show;
};

#endif // DISPLAY_H
