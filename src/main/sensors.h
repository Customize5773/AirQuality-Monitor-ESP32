#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

// --- Structures ---
struct SensorData {
  float pm25;         // PM2.5 value (ug/m3)
  float temperature;  // Temperature (°C)
  float humidity;     // Humidity (%)
};

// --- Function Prototypes ---
void initSensors();
SensorData readSensors();

#endif
