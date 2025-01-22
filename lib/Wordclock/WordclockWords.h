// represents a lighted-up portion of a strip
struct Word
{
    byte start, length;
};

Word ERROR = {0, 0}; // show all LEDs on error

#ifdef HUNGARIAN
#ifdef LEFT_TO_RIGHT // if LED line starts from the left when viewed from the front

Word MOST = {105, 3};
Word ORA = {30, 2};
Word VAN = {14, 2};
Word MULT = {18, 3};
Word OT_MULT = {11, 1};  // a lent szereplo ot, tehat az ot perccel mult
Word TIZ_MULT = {0, 2}; // a lent szereplo tiz, a tiz perccel mult
Word OT_MULVA = {102, 1}; // a fent szereplo ot, tehat az ot perc mulva
Word TIZ_MULVA = {100, 2}; // a fent szereplo tiz; tiz perc mulva
Word PERC = {84, 3};
Word PERCCEL = {4, 6};
Word NEGYED= {93, 5};
Word MULVA = {78, 4};
Word FEL = {66, 2};
Word HAROMNEGYED= {88, 10};

// the hours
Word HOURS[] = {
    {56, 9},    // TIZENKETTO, which is 0...
    {49, 2},    // EGY
    {56, 4},    // 2
    {37, 4},    // 3
    {25, 3},    // 4
    {35, 1},    // 5
    {22, 2},    // 6
    {52, 2},    // 7
    {44, 4},    // 8
    {70, 5},     // 9
    {33, 2},    // 10
    {61, 4},    // 11 (first part)
    {49, 2}     // 11 (second part)
};

#endif

#ifdef RIGHT_TO_LEFT
Word MOST = {100, 3};
Word ORA  = {22, 2};
Word VAN  = {16, 2};
Word MULT = {11, 3};
Word OT_MULT = {20, 1};  // a lent szereplo ot, tehat az ot perccel mult
Word TIZ_MULT = {8, 2}; // a lent szereplo tiz, a tiz perccel mult
Word OT_MULVA = {105, 1}; // a fent szereplo ot, tehat az ot perc mulva
Word TIZ_MULVA = {106, 2}; // a fent szereplo tiz; tiz perc mulva
Word PERC = {77, 3};
Word PERCCEL = {0, 6};
Word NEGYED= {88, 5};
Word MULVA = {82, 4};
Word FEL = {74, 2};
Word HAROMNEGYED= {88, 10};
// hours
Word HOURS[] = {
    {55, 9},    // TIZENKETTO
    {47, 2},    // EGY
    {60, 4},    // KETTO
    {35, 4},    // HAROM
    {26, 3},    // NEGY
    {40, 1},    // OT
    {30, 2},    // HAT
    {44, 2},    // HET
    {50, 4},    // NYOLC
    {67, 5},    // KILENC
    {41, 2},    // TIZ
    {55, 4},    // TIZENEGY1
    {47, 2}     // TIZENEGY2
};



#endif

Word* TIME_WORDS[] = {
    new Word[3]{MOST, ORA, VAN},
    new Word[4]{ORA, MULT, OT_MULT, PERCCEL},
    new Word[4]{ORA, MULT, TIZ_MULT, PERCCEL},
    new Word[3]{MOST, NEGYED, VAN},
    new Word[4]{NEGYED, MULT, OT_MULT, PERCCEL},
    new Word[4]{OT_MULVA, PERC, MULVA, FEL},
    new Word[3]{MOST, FEL, VAN},
    new Word[4]{FEL, MULT, OT_MULT, PERCCEL},
    new Word[4]{FEL, MULT, TIZ_MULT, PERCCEL},
    new Word[3]{MOST, HAROMNEGYED, VAN},
    new Word[4]{TIZ_MULVA, PERC, MULVA, ORA},
    new Word[4]{OT_MULVA, PERC, MULVA, ORA}
};

#endif

#ifdef ENGLISH
#ifdef LEFT_TO_RIGHT


Word IT = {108, 1};
Word IS = {105, 1};
Word QUARTER = {89, 6};
Word TWENTY = {82, 5};
Word FIVE_MIN = {77, 3};
Word HALF = {66, 3};
Word TEN_MIN = {71, 2};
Word TO = {75, 1};
Word PAST = {62, 3};
Word OCLOCK = {5, 5};

Word HOURS[] = {
    {27, 5},     // TWELVE
    {44, 2},    // ONE
    {47, 2},    // TWO
    {50, 4},    // THREE
    {40, 3},    // FOUR
    {36, 3},    // FIVE
    {33, 2},    // SIX
    {56, 4},    // SEVEN
    {17, 4},    // EIGHT
    {22, 3},    // NINE
    {0, 2},     // TEN
    {11, 5}    // ELEVEN
};

#endif
#ifdef RIGHT_TO_LEFT

Word IT = {99, 1};
Word IS  = {102, 1};
Word QUARTER = {91, 6};
Word TWENTY = {77, 5};
Word FIVE_MIN = {84, 3};
Word HALF = {73, 3};
Word TEN_MIN = {69, 2};
Word TO = {66, 1};
Word PAST = {55, 3};
Word OCLOCK = {0, 5};


Word HOURS[] = {
    {22, 5},    // TWELVE
    {52, 2},    // ONE
    {49, 2},    // TWO
    {44, 4},    // THREE
    {33, 3},    // FOUR
    {37, 3},    // FIVE
    {41, 2},    // SIX
    {60, 4},    // SEVEN
    {11, 4},    // EIGHT
    {29, 3},    // NINE
    {8, 2},     // TEN
    {16, 5}     // ELEVEN
};

#endif


Word* TIME_WORDS[] = {
    new Word[1]{OCLOCK},
    new Word[2]{FIVE_MIN, PAST},
    new Word[2]{TEN_MIN, PAST},
    new Word[2]{QUARTER, PAST},
    new Word[2]{TWENTY, PAST},
    new Word[3]{TWENTY, FIVE_MIN, PAST},
    new Word[2]{HALF, PAST},
    new Word[3]{TWENTY, FIVE_MIN, TO},
    new Word[2]{TWENTY, TO},
    new Word[2]{QUARTER, TO},
    new Word[2]{TEN_MIN, TO},
    new Word[2]{FIVE_MIN, TO}
};

#endif