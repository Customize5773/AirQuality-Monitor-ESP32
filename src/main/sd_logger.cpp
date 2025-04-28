#include "sd_logger.h"
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <RTClib.h>

// --- SD Card Settings ---
#define SD_CS_PIN 5   // Chip Select pin for SD card (adjust if needed)

// --- RTC Object ---
RTC_DS3231 rtc;

// --- File Object ---
File logFile;

// --- Initialization Function ---
void initSDCard() {
  Serial.println("Initializing SD card...");
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("Card Mount Failed!");
    while (1); // Halt if SD not found
  }
  Serial.println("SD card initialized.");

  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

// --- Logging Function ---
void logData(const SensorData& data) {
  DateTime now = rtc.now();

  String logEntry = "";
  logEntry += String(now.year()) + "-" + String(now.month()) + "-" + String(now.day()) + ",";
  logEntry += String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second()) + ",";
  logEntry += String(data.pm25, 1) + ",";
  logEntry += String(data.temperature, 1) + ",";
  logEntry += String(data.humidity, 1);

  Serial.println("Logging data: " + logEntry);

  logFile = SD.open("/air_quality_log.csv", FILE_APPEND);
  if (logFile) {
    logFile.println(logEntry);
    logFile.close();
  } else {
    Serial.println("Failed to open log file!");
  }
}
