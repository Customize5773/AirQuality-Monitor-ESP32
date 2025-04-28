#ifndef SD_LOGGER_H
#define SD_LOGGER_H

#include <Arduino.h>
#include "sensors.h"

void initSDCard();
void logData(const SensorData& data);

#endif
