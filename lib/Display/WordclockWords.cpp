#include <WordclockWords.h>

LightSegment ERROR = {0, 0};
LightSegment NULL = {-1, -1};

LightSegment HOURS[13];

LightSegment* TIME_WORDS[12];

void initializeSegments() {


    LightSegment MOST;
    LightSegment ORA;
    LightSegment VAN;
    LightSegment MULT;
    LightSegment OT_MULT;
    LightSegment TIZ_MULT;
    LightSegment OT_MULVA;
    LightSegment TIZ_MULVA;
    LightSegment PERC;
    LightSegment PERCCEL;
    LightSegment NEGYED;
    LightSegment MULVA;
    LightSegment FEL;
    LightSegment HAROMNEGYED;

    MOST = {105, 4};
    ORA = {30, 3};
    VAN = {14, 3};
    MULT = {18, 4};
    OT_MULT = {11, 2};  // a lent szereplo ot, tehat az ot perccel mult
    TIZ_MULT = {0, 3}; // a lent szereplo tiz, a tiz perccel mult
    OT_MULVA = {102, 2}; // a fent szereplo ot, tehat az ot perc mulva
    TIZ_MULVA = {100, 3}; // a fent szereplo tiz; tiz perc mulva
    PERC = {84, 4};
    PERCCEL = {4, 7};
    NEGYED = {93, 6};
    MULVA = {78, 5};
    FEL = {66, 3};
    HAROMNEGYED = {88, 11};

    // the hours
    HOURS[0] = {56, 10};    // TIZENKETTO, which is 0...
    HOURS[1] = {49, 3};    // EGY
    HOURS[2] = {56, 5};    // 2
    HOURS[3] = {37, 5};    // 3
    HOURS[4] = {25, 4};    // 4
    HOURS[5] = {35, 2};    // 5
    HOURS[6] = {22, 3};    // 6
    HOURS[7] = {52, 3};    // 7
    HOURS[8] = {44, 5};    // 8
    HOURS[9] = {70, 6};    // 9
    HOURS[10] = {33, 3};   // 10
    HOURS[11] = {61, 5};   // 11 (first part)
    HOURS[12] = {49, 3};   // 11 (second part)


    TIME_WORDS[0] = new LightSegment[4]{MOST, ORA, VAN, NULL};
    TIME_WORDS[1] = new LightSegment[4]{ORA, MULT, OT_MULT, PERCCEL};
    TIME_WORDS[2] = new LightSegment[4]{ORA, MULT, TIZ_MULT, PERCCEL};
    TIME_WORDS[3] = new LightSegment[4]{MOST, NEGYED, VAN, NULL};
    TIME_WORDS[4] = new LightSegment[4]{NEGYED, MULT, OT_MULT, PERCCEL};
    TIME_WORDS[5] = new LightSegment[4]{OT_MULVA, PERC, MULVA, FEL};
    TIME_WORDS[6] = new LightSegment[4]{MOST, FEL, VAN, NULL};
    TIME_WORDS[7] = new LightSegment[4]{FEL, MULT, OT_MULT, PERCCEL};
    TIME_WORDS[8] = new LightSegment[4]{FEL, MULT, TIZ_MULT, PERCCEL};
    TIME_WORDS[9] = new LightSegment[4]{MOST, HAROMNEGYED, VAN, NULL};
    TIME_WORDS[10] = new LightSegment[4]{TIZ_MULVA, PERC, MULVA, ORA};
    TIME_WORDS[11] = new LightSegment[4]{OT_MULVA, PERC, MULVA, ORA};
}