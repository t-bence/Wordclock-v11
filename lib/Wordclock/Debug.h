#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>
#include <Time.h>

// Print an integer in "00" format (with leading zero).
// Input value assumed to be between 0 and 99.
void sPrintI00(int val);

// Print an integer in ":00" format (with leading zero).
// Input value assumed to be between 0 and 99.
void sPrintDigits(int val);

// Function to print time with time zone
void printTime(time_t t, char *tz);

#endif // DEBUG_H