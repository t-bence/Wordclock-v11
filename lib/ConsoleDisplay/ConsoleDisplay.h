#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include <Display.h>
#include <WordclockWords.h>
#include <string>
#include <iostream>
#include <algorithm>

class ConsoleDisplay : public Display {
private:
    std::string content;

public:
    ConsoleDisplay() = default;
    void show(LightSegment seg) override;
    void setNextColor() override;
    void clear() override;
    void show() override;
    const std::string getContent();
};

#endif // CONSOLEDISPLAY_H