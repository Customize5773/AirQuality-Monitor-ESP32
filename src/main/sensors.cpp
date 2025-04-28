#include "sensors.h"

// Include libraries for sensors
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>
#include <SDS011.h>

// --- Pin Definitions (you can adjust if needed) ---
#define SDS_TX_PIN 16  // SDS011 TX -> ESP32 RX (GPIO16)
#define SDS_RX_PIN 17  // SDS011 RX -> ESP32 TX (GPIO17)

// --- Sensor Objects ---
Adafruit_BME680 bme;                 // BME680 sensor
SDS011 sds;                           // SDS011 PM2.5 sensor
HardwareSerial SDS_Serial(2);         // Using UART2 for SDS011 (Serial2)

// --- Initialization Function ---
void initSensors() {
  // Initialize BME680
  if (!bme.begin()) {
    Serial.println("Could not find BME680 sensor!");
    while (1);
  }
  Serial.println("BME680 initialized.");

  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);

  // Initialize SDS011
  SDS_Serial.begin(9600, SERIAL_8N1, SDS_TX_PIN, SDS_RX_PIN);
  sds.begin(SDS_Serial);
  Serial.println("SDS011 initialized.");
}

// --- Reading Function ---
SensorData readSensors() {
  SensorData data;

  // --- Read PM2.5 value ---
  float p10, p25;
  int error = sds.read(&p25, &p10);
  if (!error) {
    data.pm25 = p25;
    Serial.print("PM2.5: "); Serial.println(data.pm25);
  } else {
    data.pm25 = -1; // Error reading
    Serial.println("Failed to read PM2.5");
  }

  // --- Read Temperature and Humidity ---
  if (!bme.performReading()) {
    Serial.println("Failed to perform BME680 reading");
    data.temperature = -100;
    data.humidity = -1;
  } else {
    data.temperature = bme.temperature;
    data.humidity = bme.humidity;
    Serial.print("Temperature: "); Serial.print(data.temperature); Serial.println(" °C");
    Serial.print("Humidity: "); Serial.print(data.humidity); Serial.println(" %");
  }

  return data;
}
