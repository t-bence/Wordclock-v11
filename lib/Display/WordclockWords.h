#ifndef WORDCLOCKWORDS_H
#define WORDCLOCKWORDS_H

#include <Display.h>

#define WORD_LENGTH 4

extern LightSegment ERROR;
extern LightSegment EMPTY;

extern LightSegment HOURS[];

extern LightSegment* TIME_WORDS[];

void initializeSegments();

extern LightSegment MOST;
extern LightSegment ORA;
extern LightSegment VAN;
extern LightSegment MULT;
extern LightSegment OT_MULT;
extern LightSegment TIZ_MULT;
extern LightSegment OT_MULVA;
extern LightSegment TIZ_MULVA;
extern LightSegment PERC;
extern LightSegment PERCCEL;
extern LightSegment NEGYED;
extern LightSegment MULVA;
extern LightSegment FEL;
extern LightSegment HAROMNEGYED;


#endif // WORDCLOCKWORDS_H