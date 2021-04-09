#ifndef SERIAL_LOGGER_H
#define SERIAL_LOGGER_H
#include "logger.h"
#include <HardwareSerial.h>

class SerialLogger : public ILogger
{
    public:
    SerialLogger()
    {

    }

    void info(const char *str) override
    {
        Serial.printf("[INFO] %s\n", str);
    }

    void warn(const char *str) override
    {
        Serial.printf("[WARN] %s\n", str);
    }

    void error(const char *str) override
    {
        Serial.printf("[ERROR] %s\n", str);
    }
    
};

#endif