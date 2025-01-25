#ifndef LOCALTIME_H
#define LOCALTIME_H

#include <TimeLib.h>
#include <Timezone.h>

// Declare the time change rules and timezone as extern
extern TimeChangeRule myDST;
extern TimeChangeRule mySTD;
extern Timezone hunTZ;

unsigned long getLocalTime(long utcTime);

#endif // LOCALTIME_H