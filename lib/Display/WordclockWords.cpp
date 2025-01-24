#include <WordclockWords.h>

LightSegment ERROR = {0, 0};

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

    MOST = {105, 3};
    ORA = {30, 2};
    VAN = {14, 2};
    MULT = {18, 3};
    OT_MULT = {11, 1};  // a lent szereplo ot, tehat az ot perccel mult
    TIZ_MULT = {0, 2}; // a lent szereplo tiz, a tiz perccel mult
    OT_MULVA = {102, 1}; // a fent szereplo ot, tehat az ot perc mulva
    TIZ_MULVA = {100, 2}; // a fent szereplo tiz; tiz perc mulva
    PERC = {84, 3};
    PERCCEL = {4, 6};
    NEGYED = {93, 5};
    MULVA = {78, 4};
    FEL = {66, 2};
    HAROMNEGYED = {88, 10};

    // the hours
    HOURS[0] = {56, 9};    // TIZENKETTO, which is 0...
    HOURS[1] = {49, 2};    // EGY
    HOURS[2] = {56, 4};    // 2
    HOURS[3] = {37, 4};    // 3
    HOURS[4] = {25, 3};    // 4
    HOURS[5] = {35, 1};    // 5
    HOURS[6] = {22, 2};    // 6
    HOURS[7] = {52, 2};    // 7
    HOURS[8] = {44, 4};    // 8
    HOURS[9] = {70, 5};    // 9
    HOURS[10] = {33, 2};   // 10
    HOURS[11] = {61, 4};   // 11 (first part)
    HOURS[12] = {49, 2};   // 11 (second part)


    TIME_WORDS[0] = new LightSegment[3]{MOST, ORA, VAN};
    TIME_WORDS[1] = new LightSegment[4]{ORA, MULT, OT_MULT, PERCCEL};
    TIME_WORDS[2] = new LightSegment[4]{ORA, MULT, TIZ_MULT, PERCCEL};
    TIME_WORDS[3] = new LightSegment[3]{MOST, NEGYED, VAN};
    TIME_WORDS[4] = new LightSegment[4]{NEGYED, MULT, OT_MULT, PERCCEL};
    TIME_WORDS[5] = new LightSegment[4]{OT_MULVA, PERC, MULVA, FEL};
    TIME_WORDS[6] = new LightSegment[3]{MOST, FEL, VAN};
    TIME_WORDS[7] = new LightSegment[4]{FEL, MULT, OT_MULT, PERCCEL};
    TIME_WORDS[8] = new LightSegment[4]{FEL, MULT, TIZ_MULT, PERCCEL};
    TIME_WORDS[9] = new LightSegment[3]{MOST, HAROMNEGYED, VAN};
    TIME_WORDS[10] = new LightSegment[4]{TIZ_MULVA, PERC, MULVA, ORA};
    TIME_WORDS[11] = new LightSegment[4]{OT_MULVA, PERC, MULVA, ORA};
}