#include <WordclockWords.h>

LightSegment ERROR = {0, 0};

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

LightSegment HOURS[13];

LightSegment* TIME_WORDS[12];

#ifdef HUNGARIAN
#ifdef LEFT_TO_RIGHT
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
NEGYED= {93, 5};
MULVA = {78, 4};
FEL = {66, 2};
HAROMNEGYED= {88, 10};

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
HOURS[9] = {70, 5};     // 9
HOURS[10] = {33, 2};    // 10
HOURS[11] = {61, 4};    // 11 (first part)
HOURS[12] = {49, 2};     // 11 (second part)

#endif

#ifdef RIGHT_TO_LEFT
MOST = {100, 3};
ORA  = {22, 2};
VAN  = {16, 2};
MULT = {11, 3};
OT_MULT = {20, 1};  // a lent szereplo ot, tehat az ot perccel mult
TIZ_MULT = {8, 2}; // a lent szereplo tiz, a tiz perccel mult
OT_MULVA = {105, 1}; // a fent szereplo ot, tehat az ot perc mulva
TIZ_MULVA = {106, 2}; // a fent szereplo tiz; tiz perc mulva
PERC = {77, 3};
PERCCEL = {0, 6};
NEGYED= {88, 5};
MULVA = {82, 4};
FEL = {74, 2};
HAROMNEGYED= {88, 10};
// hours
HOURS[0] = {55, 9};    // TIZENKETTO
HOURS[1] = {47, 2};    // EGY
HOURS[2] = {60, 4};    // KETTO
HOURS[3] = {35, 4};    // HAROM
HOURS[4] = {26, 3};    // NEGY
HOURS[5] = {40, 1};    // OT
HOURS[6] = {30, 2};    // HAT
HOURS[7] = {44, 2};    // HET
HOURS[8] = {50, 4};    // NYOLC
HOURS[9] = {67, 5};    // KILENC
HOURS[10] = {41, 2};    // TIZ
HOURS[11] = {55, 4};    // TIZENEGY1
HOURS[12] = {47, 2};     // TIZENEGY2

#endif

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

#endif

#ifdef ENGLISH
#ifdef LEFT_TO_RIGHT
IT = {108, 1};
IS = {105, 1};
QUARTER = {89, 6};
TWENTY = {82, 5};
FIVE_MIN = {77, 3};
HALF = {66, 3};
TEN_MIN = {71, 2};
TO = {75, 1};
PAST = {62, 3};
OCLOCK = {5, 5};

HOURS[0] = {27, 5};     // TWELVE
HOURS[1] = {44, 2};    // ONE
HOURS[2] = {47, 2};    // TWO
HOURS[3] = {50, 4};    // THREE
HOURS[4] = {40, 3};    // FOUR
HOURS[5] = {36, 3};    // FIVE
HOURS[6] = {33, 2};    // SIX
HOURS[7] = {56, 4};    // SEVEN
HOURS[8] = {17, 4};    // EIGHT
HOURS[9] = {22, 3};    // NINE
HOURS[10] = {0, 2};     // TEN
HOURS[11] = {11, 5};    // ELEVEN

#endif
#ifdef RIGHT_TO_LEFT

IT = {99, 1};
IS  = {102, 1};
QUARTER = {91, 6};
TWENTY = {77, 5};
FIVE_MIN = {84, 3};
HALF = {73, 3};
TEN_MIN = {69, 2};
TO = {66, 1};
PAST = {55, 3};
OCLOCK = {0, 5};


HOURS[0] = {22, 5};    // TWELVE
HOURS[1] = {52, 2};    // ONE
HOURS[2] = {49, 2};    // TWO
HOURS[3] = {44, 4};    // THREE
HOURS[4] = {33, 3};    // FOUR
HOURS[5] = {37, 3};    // FIVE
HOURS[6] = {41, 2};    // SIX
HOURS[7] = {60, 4};    // SEVEN
HOURS[8] = {11, 4};    // EIGHT
HOURS[9] = {29, 3};    // NINE
HOURS[10] = {8, 2};     // TEN
HOURS[11] = {16, 5};     // ELEVEN

#endif


TIME_WORDS[0] = new LightSegment[1]{OCLOCK};
TIME_WORDS[1] = new LightSegment[2]{FIVE_MIN, PAST};
TIME_WORDS[2] = new LightSegment[2]{TEN_MIN, PAST};
TIME_WORDS[3] = new LightSegment[2]{QUARTER, PAST};
TIME_WORDS[4] = new LightSegment[2]{TWENTY, PAST};
TIME_WORDS[5] = new LightSegment[3]{TWENTY, FIVE_MIN, PAST};
TIME_WORDS[6] = new LightSegment[2]{HALF, PAST};
TIME_WORDS[7] = new LightSegment[3]{TWENTY, FIVE_MIN, TO};
TIME_WORDS[8] = new LightSegment[2]{TWENTY, TO};
TIME_WORDS[9] = new LightSegment[2]{QUARTER, TO};
TIME_WORDS[10] = new LightSegment[2]{TEN_MIN, TO};
TIME_WORDS[11] = new LightSegment[2]{FIVE_MIN, TO};

#endif