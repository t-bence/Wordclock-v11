uint8_t ERROR[] = {0, 50}; // show lots of LEDs on error

#ifdef HUNGARIAN
#ifdef LEFT_TO_RIGHT // if LED line starts from the left when viewed from the front

uint8_t MOST[] = {105, 3};
uint8_t ORA[]  = {30, 2};
uint8_t VAN[]  = {14, 2};
uint8_t MULT[] = {18, 3};
uint8_t OT_MULT[] = {11, 1};  // a lent szereplo ot, tehat az ot perccel mult
uint8_t TIZ_MULT[] = {0, 2}; // a lent szereplo tiz, a tiz perccel mult
uint8_t OT_MULVA[] = {102, 1}; // a fent szereplo ot, tehat az ot perc mulva
uint8_t TIZ_MULVA[] = {100, 2}; // a fent szereplo tiz; tiz perc mulva
uint8_t PERC[] = {84, 3};
uint8_t PERCCEL[] = {4, 6};
uint8_t NEGYED[]= {93, 5};
uint8_t MULVA[] = {78, 4};
uint8_t FEL[] = {66, 2};
uint8_t HAROMNEGYED[]= {88, 10};
// orak
uint8_t EGY[] = {49, 2};
uint8_t KETTO[] = {56, 4};
uint8_t HAROM[] = {37, 4};
uint8_t NEGY[] = {25, 3};
uint8_t OT[] = {35, 1};
uint8_t HAT[] = {22, 2};
uint8_t HET[] = {52, 2};
uint8_t NYOLC[] = {44, 4};
uint8_t KILENC[] = {70, 5};
uint8_t TIZ[] = {33, 2};
uint8_t TIZENEGY1[] = {61, 4};
uint8_t TIZENEGY2[] = {49, 2};
uint8_t TIZENKETTO[] = {56, 9};
#endif

#ifdef RIGHT_TO_LEFT
uint8_t MOST[] = {100, 3};
uint8_t ORA[]  = {22, 2};
uint8_t VAN[]  = {16, 2};
uint8_t MULT[] = {11, 3};
uint8_t OT_MULT[] = {20, 1};  // a lent szereplo ot, tehat az ot perccel mult
uint8_t TIZ_MULT[] = {8, 2}; // a lent szereplo tiz, a tiz perccel mult
uint8_t OT_MULVA[] = {105, 1}; // a fent szereplo ot, tehat az ot perc mulva
uint8_t TIZ_MULVA[] = {106, 2}; // a fent szereplo tiz; tiz perc mulva
uint8_t PERC[] = {77, 3};
uint8_t PERCCEL[] = {0, 6};
uint8_t NEGYED[]= {88, 5};
uint8_t MULVA[] = {82, 4};
uint8_t FEL[] = {74, 2};
uint8_t HAROMNEGYED[]= {88, 10};
// hours
uint8_t EGY[] = {47, 2};
uint8_t KETTO[] = {60, 4};
uint8_t HAROM[] = {35, 4};
uint8_t NEGY[] = {26, 3};
uint8_t OT[] = {40, 1};
uint8_t HAT[] = {30, 2};
uint8_t HET[] = {44, 2};
uint8_t NYOLC[] = {50, 4};
uint8_t KILENC[] = {67, 5};
uint8_t TIZ[] = {41, 2};
uint8_t TIZENEGY1[] = {55, 4};
uint8_t TIZENEGY2[] = {47, 2};
uint8_t TIZENKETTO[] = {55, 9};
#endif
#endif

#ifdef ENGLISH
#ifdef LEFT_TO_RIGHT


uint8_t IT[] = {108, 1};
uint8_t IS[] = {105, 1};
uint8_t QUARTER[] = {89, 6};
uint8_t TWENTY[] = {82, 5};
uint8_t FIVE_MIN[] = {77, 3};
uint8_t HALF[] = {66, 3};
uint8_t TEN_MIN[] = {71, 2};
uint8_t TO[] = {75, 1};
uint8_t PAST[] = {62, 3};
uint8_t OCLOCK[] = {5, 5};

uint8_t ONE[] = {44, 2};
uint8_t TWO[] = {47, 2};
uint8_t THREE[] = {50, 4};
uint8_t FOUR[] = {40, 3};
uint8_t FIVE[] = {36, 3};
uint8_t SIX[] = {33, 2};
uint8_t SEVEN[] = {56, 4};
uint8_t EIGHT[] = {17, 4};
uint8_t NINE[] = {22, 3};
uint8_t TEN[] = {0, 2};
uint8_t ELEVEN[] = {11, 5};
uint8_t TWELVE[] = {27, 5};

#endif
#ifdef RIGHT_TO_LEFT

uint8_t IT[] = {99, 1};
uint8_t IS[]  = {102, 1};
uint8_t QUARTER[] = {91, 6};
uint8_t TWENTY[] = {77, 5};
uint8_t FIVE_MIN[] = {84, 3};
uint8_t HALF[] = {73, 3};
uint8_t TEN_MIN[] = {69, 2};
uint8_t TO[] = {66, 1};
uint8_t PAST[] = {55, 3};
uint8_t OCLOCK[] = {0, 5};


uint8_t ONE[] = {52, 2};
uint8_t TWO[] = {49, 2};
uint8_t THREE[] = {44, 4};
uint8_t FOUR[] = {33, 3};
uint8_t FIVE[] = {37, 3};
uint8_t SIX[] = {41, 2};
uint8_t SEVEN[] = {60, 4};
uint8_t EIGHT[] = {11, 4};
uint8_t NINE[] = {29, 3};
uint8_t TEN[] = {8, 2};
uint8_t ELEVEN[] = {16, 5};
uint8_t TWELVE[] = {22, 5};
#endif
#endif
