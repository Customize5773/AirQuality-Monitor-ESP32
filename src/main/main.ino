// --- Author: Customize5773 (Rasya Pratama) ---

// --- Include Headers ---
#include "sensors.h"
#include "wifi_manager.h"
#include "alert_manager.h"
#include "sd_logger.h"

// --- Global Variables ---
unsigned long lastAlertTime = 0;
const unsigned long alertInterval = 3UL * 60UL * 60UL * 1000UL; // 3 hours in milliseconds

void setup() {
  Serial.begin(115200);
  delay(1000); // Small boot delay
  
  Serial.println("Starting Air Quality Monitor...");

  // Initialize modules
  initWiFi();
  initSensors();
  initSDCard();
  initAlertSystem();

  Serial.println("System Initialization Complete.");
}

void loop() {
  SensorData data = readSensors();
  logData(data);

  if (isAirQualityBad(data)) {
    unsigned long currentMillis = millis();
    if (currentMillis - lastAlertTime >= alertInterval || lastAlertTime == 0) {
      triggerAlert(data);
      lastAlertTime = currentMillis;
    }
  }

  delay(60000); // Take a reading every minute
}
