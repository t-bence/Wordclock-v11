// függvények
#include <Arduino.h>

// magyar szavak

// ha szembol nezve bal oldalt kezdodik a LED-sor...
byte MOST[] = {105, 3};
byte ORA[]  = {30, 2};
byte VAN[]  = {14, 2};
byte MULT[] = {18, 3};
byte OT_MULT[] = {11, 1};  // a lent szereplo ot, tehat az ot perccel mult
byte TIZ_MULT[] = {0, 2}; // a lent szereplo tiz, a tiz perccel mult
byte OT_MULVA[] = {102, 1}; // a fent szereplo ot, tehat az ot perc mulva
byte TIZ_MULVA[] = {100, 2}; // a fent szereplo tiz; tiz perc mulva
byte PERC[] = {84, 3};
byte PERCCEL[] = {4, 6};
byte NEGYED[]= {93, 5};
byte MULVA[] = {78, 4};
byte FEL[] = {66, 2};
byte HAROMNEGYED[]= {88, 10};
// orak
byte EGY[] = {49, 2};
byte KETTO[] = {56, 4};
byte HAROM[] = {37, 4};
byte NEGY[] = {25, 3};
byte OT[] = {35, 1};
byte HAT[] = {22, 2};
byte HET[] = {52, 2};
byte NYOLC[] = {44, 4};
byte KILENC[] = {70, 5};
byte TIZ[] = {33, 2};
byte TIZENEGY1[] = {61, 4};
byte TIZENEGY2[] = {49, 2};
byte TIZENKETTO[] = {56, 9};


// ha szembol nezve jobb oldalon kezdodik a LED-sor... LOL
/*
byte MOST[] = {100, 3};
byte ORA[]  = {22, 2};
byte VAN[]  = {16, 2};
byte MULT[] = {11, 3};
byte OT_MULT[] = {20, 1};  // a lent szereplo ot, tehat az ot perccel mult
byte TIZ_MULT[] = {8, 2}; // a lent szereplo tiz, a tiz perccel mult
byte OT_MULVA[] = {105, 1}; // a fent szereplo ot, tehat az ot perc mulva
byte TIZ_MULVA[] = {106, 2}; // a fent szereplo tiz; tiz perc mulva
byte PERC[] = {77, 3};
byte PERCCEL[] = {0, 6};
byte NEGYED[]= {88, 5};
byte MULVA[] = {82, 4};
byte FEL[] = {74, 2};
byte HAROMNEGYED[]= {88, 10};
// orak
byte EGY[] = {47, 2};
byte KETTO[] = {60, 4};
byte HAROM[] = {35, 4};
byte NEGY[] = {26, 3};
byte OT[] = {40, 1};
byte HAT[] = {30, 2};
byte HET[] = {44, 2};
byte NYOLC[] = {50, 4};
byte KILENC[] = {67, 5};
byte TIZ[] = {41, 2};
byte TIZENEGY1[] = {55, 4};
byte TIZENEGY2[] = {47, 2};
byte TIZENKETTO[] = {55, 9};
*/


//////// ANGOLUL - ha szembol nezve jobbrol indul a led szalag
// az angol_layout_szamokkal.jpg alapjan
/*
// szavak, percek
byte IT[] = {99, 1};
byte IS[]  = {102, 1};
byte QUARTER[] = {91, 6};
byte TWENTY[] = {77, 5};
byte FIVE_MIN[] = {84, 3};
byte HALF[] = {73, 3};
byte TEN_MIN[] = {69, 2};
byte TO[] = {66, 1};
byte PAST[] = {55, 3};
byte OCLOCK[] = {0, 5};


// orak
byte ONE[] = {52, 2};
byte TWO[] = {49, 2};
byte THREE[] = {44, 4};
byte FOUR[] = {33, 3};
byte FIVE[] = {37, 3};
byte SIX[] = {41, 2};
byte SEVEN[] = {60, 4};
byte EIGHT[] = {11, 4};
byte NINE[] = {29, 3};
byte TEN[] = {8, 2};
byte ELEVEN[] = {16, 5};
byte TWELVE[] = {22, 5};
*/

// ANGOLUL, ha szembol nezve balrol indul a led szalag

byte IT[] = {108, 1};
byte IS[] = {105, 1};
byte QUARTER[] = {89, 6};
byte TWENTY[] = {82, 5};
byte FIVE_MIN[] = {77, 3};
byte HALF[] = {66, 3};
byte TEN_MIN[] = {71, 2};
byte TO[] = {75, 1};
byte PAST[] = {62, 3};
byte OCLOCK[] = {5, 5};

byte ONE[] = {44, 2};
byte TWO[] = {47, 2};
byte THREE[] = {50, 4};
byte FOUR[] = {40, 3};
byte FIVE[] = {36, 3};
byte SIX[] = {33, 2};
byte SEVEN[] = {56, 4};
byte EIGHT[] = {17, 4};
byte NINE[] = {22, 3};
byte TEN[] = {0, 2};
byte ELEVEN[] = {11, 5};
byte TWELVE[] = {27, 5};