#include <Writer.h>

Writer::Writer(Display& display) : display(display) {}

const unsigned long TWOHALF_MINUTES = 150;

/*
This method gets the current time in seconds,
then decides if it has to update the time, and if so,
it calls the showTime function. */
void Writer::updateTime(unsigned long newSeconds) {
    const int REDRAW_INTERVAL = 10;
    if (newSeconds - seconds > REDRAW_INTERVAL) {
        redraw();
    }
    seconds = newSeconds;
        
}

void Writer::redraw() {
    display.clear();
    showTime();
    display.show();

}

void Writer::showWords(LightSegment words[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (words[i] == EMPTY) {
            continue; // EMPTY is a filling word that must not be displayed
        }
        else {
            display.show(words[i]);
        }
        
    }
}


// return the hour between 0-11
int Writer::getHour(unsigned long offset = 0U) {
    int totalMinutes = (seconds + offset) / 60;
    int totalHours = totalMinutes / 60;
    return totalHours % 12;
}

// return minute between 0-59
int Writer::getMinute(unsigned long offset = 0U) {
    int totalMinutes = (seconds + offset) / 60;
    return totalMinutes % 60;
}

void Writer::showTime()
{

    /*
    When displaying the time, we add 2.5 minutes, so that we display noon
    from 11:57:30 to 12:02:30, so centered around noon.
    */
    int min = getMinute(TWOHALF_MINUTES);
    int hour = getHour(TWOHALF_MINUTES);

    int index = min / 5;
    if (index >= 12) index = 0; // handle edge case for 60 minutes

    showWords(TIME_WORDS[index], WORD_LENGTH);

    if (index >= 3) // if it's past the first quarter
    {
        hour = (hour + 1) % 12;
    }

    display.show(HOURS[hour]);
    if (hour == 11)
    {
        display.show(HOURS[12]); // 11 consists of two word parts in Hungarian
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
