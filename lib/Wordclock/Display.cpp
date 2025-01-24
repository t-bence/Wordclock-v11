#include <Display.h>

Display::Display(ShowFunction showFunc) : show(showFunc) {}

void Display::showWords(LightSegment words[], int size)
{
    for (int i = 0; i < size; i++)
    {
        show(words[i]);
    }
}

void Display::showTime(int hour, int min)
{
    int index = min / 5;
    if (index >= 12) index = 0; // handle edge case for 60 minutes

#ifdef HUNGARIAN

    showWords(TIME_WORDS[index], sizeof(TIME_WORDS[index]) / sizeof(LightSegment));

    if (index >= 3) // if it's past the first quarter
    {
        hour = (hour + 1) % 12;
    }

    show(HOURS[hour]);
    if (hour == 11)
    {
        show(HOURS[12]); // 11 consists of two word parts in Hungarian
    }

#endif
#ifdef ENGLISH

    show(IT);
    show(IS);
    showWords(TIME_WORDS[index], sizeof(TIME_WORDS[index]) / sizeof(LightSegment));

    if (index >= 7) // if it's past half
    {
        hour = (hour + 1) % 12;
    }

    show(HOURS[hour]);

#endif
}
