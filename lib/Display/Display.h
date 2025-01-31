#ifndef DISPLAY_H
#define DISPLAY_H

// represents a lighted-up portion of a strip
struct LightSegment
{
    int start, length;

    bool operator==(const LightSegment& other) const {
        return start == other.start && length == other.length;
    }
};

class Display {
public:
    virtual void show(LightSegment seg) = 0;
    virtual void setNextColor() = 0;
    virtual void clear() = 0;
    virtual void show() = 0;
};

#endif // DISPLAY_H