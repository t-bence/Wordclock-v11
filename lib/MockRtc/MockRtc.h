#ifndef MOCKRTC_H
#define MOCKRTC_H

#include <chrono>
#include <ctime>

#define INPUT 0
#define RISING 3
#define SDA 0
#define SCL 0

unsigned long getLocalTime(long input);

void pinMode(int number, int mode);

int digitalPinToInterrupt(int pin);

unsigned long millis();

void attachInterrupt(int num, void (*userFunc)(void), int mode);

class DS3231
{
	public:
		DS3231(int data_pin, int sclk_pin);
        void begin();
        long getUnixTime(unsigned long t);
        unsigned long getTime();
};

#endif // MOCKRTC_H