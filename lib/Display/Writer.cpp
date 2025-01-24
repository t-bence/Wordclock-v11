#include <Writer.h>

Writer::Writer(Display& display) : display(display) {}

void Writer::showWords(LightSegment words[], int size)
{
    for (int i = 0; i < size; i++)
    {
        display.show(words[i]);
    }
}

void Writer::showTime(int hour_, int min)
{
    int index = min / 5;
    if (index >= 12) index = 0; // handle edge case for 60 minutes

    int hour = hour_ % 12;

    showWords(TIME_WORDS[index], sizeof(TIME_WORDS[index]) / sizeof(LightSegment));

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
