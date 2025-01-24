#ifndef WORDCLOCKWORDS_H
#define WORDCLOCKWORDS_H

// represents a lighted-up portion of a strip
struct LightSegment
{
    int start, length;
};

extern LightSegment ERROR;

extern LightSegment HOURS[];

extern LightSegment* TIME_WORDS[];

#ifdef HUNGARIAN

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

#endif

#ifdef ENGLISH

extern LightSegment IT;
extern LightSegment IS;
extern LightSegment QUARTER;
extern LightSegment TWENTY;
extern LightSegment FIVE_MIN;
extern LightSegment HALF;
extern LightSegment TEN_MIN;
extern LightSegment TO;
extern LightSegment PAST;
extern LightSegment OCLOCK;

#endif

#endif // WORDCLOCKWORDS_H