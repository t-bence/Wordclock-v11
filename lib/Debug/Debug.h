#ifndef DEBUG_H
#define DEBUG_H

#ifdef MCU
    #include <Arduino.h>
    #define SERIAL_BEGIN(...) Serial.begin(__VA_ARGS__)
    #define PRINT(...)    Serial.print(__VA_ARGS__)
    #define PRINTLN(...)  Serial.println(__VA_ARGS__)
#else
    #define SERIAL_BEGIN(...)
    #define PRINT(...)
    #define PRINTLN(...)
#endif

#endif