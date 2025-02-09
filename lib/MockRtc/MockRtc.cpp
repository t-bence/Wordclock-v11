#include <MockRtc.h>

ClockTime getLocalTime(std::time_t t, int offset) {
    t += offset;
    // Convert to local time
    std::tm local_tm;
    localtime_r(&t, &local_tm);  // Thread-safe version of localtime()

    // Compute seconds since midnight
    return ClockTime {local_tm.tm_hour, local_tm.tm_min, local_tm.tm_sec};
}

void pinMode(int number, int mode) {}

int digitalPinToInterrupt(int pin) {
    return pin;
}

unsigned long millis() {
    return 0;
}

void attachInterrupt(int num, void (*userFunc)(void), int mode) {}


DS3231::DS3231(int data_pin, int sclk_pin) {}

void DS3231::begin() {}

std::time_t DS3231::getUnixTime(std::time_t input) {
    return input;
};

std::time_t DS3231::getTime() {
    auto now = std::chrono::system_clock::now();

    // Convert to time_t (seconds since epoch)
    return std::chrono::system_clock::to_time_t(now);
}
