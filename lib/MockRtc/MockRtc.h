#ifndef MOCKRTC_H
#define MOCKRTC_H

#include <iostream>
#include <chrono>
#include <ctime>

#include <ClockTime.h>

#define INPUT 0
#define RISING 3
#define SDA 0
#define SCL 0

ClockTime getLocalTime(std::time_t t, int offset = 0);

void pinMode(int number, int mode);

int digitalPinToInterrupt(int pin);

unsigned long millis();

void attachInterrupt(int num, void (*userFunc)(void), int mode);

class DS3231
{
	public:
		DS3231(int data_pin, int sclk_pin);
        void begin();
        std::time_t getUnixTime(std::time_t t);
        std::time_t getTime();
};

#endif // MOCKRTC_H