#ifndef LOCALTIME_H
#define LOCALTIME_H

#include <Time.h>
#include <Timezone.h>

#define TWO_HALF_MINUTES 150 // 2.5 minutes in seconds 

// Declare the time change rules and timezone as extern
extern TimeChangeRule myDST;
extern TimeChangeRule mySTD;
extern Timezone hunTZ;

struct LocalTime {
    int hour, minute;
};

LocalTime getLocalTime(long utcTime);

#endif // LOCALTIME_H