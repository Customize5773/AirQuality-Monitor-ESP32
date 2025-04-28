#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

#include <Arduino.h>
#include "sensors.h"  // To access SensorData structure

void initAlertSystem();
void triggerAlert(const SensorData& data);
bool isAirQualityBad(const SensorData& data);

#endif
