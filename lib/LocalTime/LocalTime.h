#ifndef LOCALTIME_H
#define LOCALTIME_H

#include <TimeLib.h>
#include <Timezone.h>
#include <ClockTime.h>

// Declare the time change rules and timezone as extern
extern TimeChangeRule myDST;
extern TimeChangeRule mySTD;
extern Timezone hunTZ;

ClockTime getLocalTime(long utcTime, int offset = 0);

#endif // LOCALTIME_H