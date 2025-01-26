#include <MockRtc.h>

unsigned long getLocalTime(unsigned long input) {
    return input;
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

unsigned long DS3231::getUnixTime(unsigned long input) {
    return input;
};

unsigned long DS3231::getTime() {
    auto now = std::chrono::system_clock::now();

    // Convert to time_t (seconds since epoch)
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    // Convert to local time
    std::tm local_tm;
    localtime_r(&t, &local_tm);  // Thread-safe version of localtime()

    // Compute seconds since midnight
    unsigned long time = local_tm.tm_hour * 3600 + local_tm.tm_min * 60 + local_tm.tm_sec;
    // std::cout << time << std::endl;
    return time;
}
