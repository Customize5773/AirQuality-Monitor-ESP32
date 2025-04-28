#include "alert_manager.h"
#include <WiFi.h>
#include <HTTPClient.h>

// --- Pins Definitions ---
#define RED_LED_PIN    25
#define GREEN_LED_PIN  26
#define BLUE_LED_PIN   27
#define BUZZER_PIN     14

// --- WhatsApp Bot Credentials (SET YOURS HERE) ---
const char* callmebotAPIKey = "YOUR_API_KEY";    // From CallMeBot
const char* phoneNumber = "YOUR_PHONE_NUMBER";   // Format: +11234567890 (include country code)

// --- Critical Threshold ---
const float PM25_THRESHOLD = 100.0; // PM2.5 threshold for "bad air"

// --- Initialization Function ---
void initAlertSystem() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Set LEDs off
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);

  digitalWrite(BUZZER_PIN, LOW);
}

// --- Check if Air Quality is Bad ---
bool isAirQualityBad(const SensorData& data) {
  return data.pm25 > PM25_THRESHOLD;
}

// --- Trigger Alert (LED, Buzzer, WhatsApp) ---
void triggerAlert(const SensorData& data) {
  Serial.println("!! Air Quality Bad - Triggering Alert !!");

  // Light up RED LED
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);

  // Sound buzzer for a few seconds
  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZER_PIN, LOW);

  // Send WhatsApp Message
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String message = "🚨 WARNING!\n";
    message += "PM2.5: " + String(data.pm25, 1) + " ug/m3\n";
    message += "Temp: " + String(data.temperature, 1) + " C\n";
    message += "Humidity: " + String(data.humidity, 1) + " %";

    String url = "https://api.callmebot.com/whatsapp.php?phone=" 
                 + String(phoneNumber) + 
                 "&text=" + urlencode(message) + 
                 "&apikey=" + String(callmebotAPIKey);

    Serial.println("Sending WhatsApp message...");
    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.printf("WhatsApp Message sent, HTTP response code: %d\n", httpCode);
    } else {
      Serial.printf("WhatsApp Message failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  } else {
    Serial.println("Wi-Fi not connected, cannot send WhatsApp message!");
  }
}

// --- Helper: URL Encode Function (simple) ---
String urlencode(String str) {
  String encoded = "";
  char c;
  char code0;
  char code1;
  char code2;
  for (int i =0; i < str.length(); i++){
    c = str.charAt(i);
    if (c == ' '){
      encoded += '+';
    } else if (isalnum(c)){
      encoded += c;
    } else{
      code1 = (c & 0xf) + '0';
      if ((c & 0xf) >9) code1 = (c & 0xf) - 10 + 'A';
      c = (c>>4)&0xf;
      code0 = c + '0';
      if (c > 9) code0 = c -10 + 'A';
      code2 = '\0';
      encoded += '%';
      encoded += code0;
      encoded += code1;
    }
  }
  return encoded;
}
