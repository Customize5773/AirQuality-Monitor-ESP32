#include "wifi_manager.h"
#include <WiFi.h>   // ESP32 built-in Wi-Fi library

// --- Wi-Fi Credentials (SET YOURS HERE) ---
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// --- Initialization Function ---
void initWiFi() {
  Serial.println();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  int retries = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    retries++;
    if (retries > 20) { // Timeout after ~10 seconds
      Serial.println("\nWiFi Connection Failed! Restarting...");
      ESP.restart();
    }
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}
