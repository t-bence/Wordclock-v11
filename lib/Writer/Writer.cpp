#include <Writer.h>

Writer::Writer(Display* d) : display(d) {
    initializeSegments();
    last = ClockTime {0, 0, 0};
}

const int REDRAW_INTERVAL = 10;

/*
This method gets the current time in seconds,
then decides if it has to update the time, and if so,
it calls the showTime function. */
void Writer::updateTime(ClockTime time) {
    unsigned long now = time.getSeconds();
    if (((now - last.getSeconds()) > REDRAW_INTERVAL) or (now < last.getSeconds())) {
        last = time;
        redraw();
    }
        
}

void Writer::redraw() {
    PRINTLN("Redrawing");
    display->clear();
    showTime();
    display->show();

}

void Writer::showWords(LightSegment words[], int size)
{
    for (int i = 0; i < size; i++)
    {
        PRINT("Writing "); PRINTLN(words[i].start);
        if (words[i] == EMPTY) {
            continue; // EMPTY is a filling word that must not be displayed
        }
        else {
            display->show(words[i]);
        }
        
    }
}

void Writer::showTime()
{

    /*
    When displaying the time, we add 2.5 minutes, so that we display noon
    from 11:57:30 to 12:02:30, so centered around noon.
    */
    int hour = last.hour % 12;
    int min = last.minute % 60;

    PRINT("Hour: "); PRINTLN(hour);
    PRINT("Minute: "); PRINTLN(min);

    int index = min / 5;
    if (index >= 12) index = 0; // handle edge case for 60 minutes

    showWords(TIME_WORDS[index], WORD_LENGTH);

    if (index >= 3) // if it's past the first quarter
    {
        hour = (hour + 1) % 12;
    }

    display->show(HOURS[hour]);
    if (hour == 11)
    {
        display->show(HOURS[12]); // 11 consists of two word parts in Hungarian
    }


/* FOR ENGLISH:

    display.show(IT);
    display.show(IS);

    if (index >= 7) // if it's past half
    {
        hour = (hour + 1) % 12;
    }

    display.show(HOURS[hour]);

*/
}
