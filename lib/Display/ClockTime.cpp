#include "ClockTime.h"

int ClockTime::getSeconds()
{
    return hour * 3600 + minute * 60 + second;
}