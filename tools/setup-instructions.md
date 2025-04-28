# 🛠️ Setup Instructions

Welcome to the **AirQuality-Monitor-ESP32** Project! 🚀  
This guide will help you set up your development environment and flash the project successfully onto your ESP32 board.

---

## 📋 1. Requirements

### Hardware:
- ESP32 Dev Board (e.g., NodeMCU-32S, ESP32-WROOM)
- SDS011 PM2.5 Dust Sensor
- BME680 Temperature, Humidity, Pressure, VOC Sensor
- DS3231 Real-Time Clock (RTC) Module
- MicroSD Card Module + SD Card
- RGB LED (Common Cathode or Anode)
- Buzzer
- Jumper wires, Breadboard (for prototyping)
- USB cable (for ESP32)

### Software:
- Arduino IDE 1.8.x or 2.x (Latest recommended)
- ESP32 Board Support for Arduino
- Required Libraries:
  - `Adafruit BME680`
  - `Adafruit Sensor`
  - `Adafruit GFX`
  - `Adafruit ILI9341` (if using TFT screen)
  - `SDS011`
  - `RTClib`
  - `SD`
  - `WiFi`
  - `HTTPClient`

---

## 🧩 2. Install ESP32 Support in Arduino IDE

1. Open Arduino IDE.
2. Go to **File → Preferences**.
3. In **Additional Boards Manager URLs**, add:

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

4. Go to **Tools → Board → Board Manager**.
5. Search for **ESP32** and install.

---

## 📦 3. Install Required Libraries

In Arduino IDE, open **Sketch → Include Library → Manage Libraries...** and install:
- **Adafruit BME680**
- **Adafruit Unified Sensor**
- **Adafruit GFX Library**
- **Adafruit ILI9341** (if using display)
- **RTClib**
- **SDS011 sensor library**
- **SD**
- **WiFi**
- **HTTPClient**

> 🔹 You can also install via PlatformIO if you prefer.

---

## 🛠️ 4. Configure Your Project

- **src/wifi_manager.cpp**:
  - Replace `YOUR_WIFI_SSID` and `YOUR_WIFI_PASSWORD` with your Wi-Fi credentials.

- **src/alert_manager.cpp**:
  - Replace `YOUR_API_KEY` and `YOUR_PHONE_NUMBER` for CallMeBot WhatsApp alerts.

- **Pin Mapping**:
  - Adjust `#define` pins in `alert_manager.cpp`, `sensors.cpp`, `sd_logger.cpp` if you use different GPIOs.

---

## ⚡ 5. Upload Code

1. Connect ESP32 via USB.
2. Select correct Board: **ESP32 Dev Module** (or your variant).
3. Select correct Port.
4. Click **Upload**.

If everything is correct, your ESP32 will boot, connect to Wi-Fi, initialize sensors, and start logging!

---

## 🧹 6. Optional: First SD Card Format

- Format SD Card as **FAT32** before first use.
- Create a simple empty file `air_quality_log.csv` manually if needed (optional — auto-created by code).

---

## 🛠️ Troubleshooting

| Problem | Solution |
|:---|:---|
| Wi-Fi Not Connecting | Check SSID/Password and distance to router. |
| SD Card Not Detected | Confirm CS Pin, wiring, and proper 3.3V SD card module. |
| RTC Time Wrong | Flash once, or adjust in `initSDCard()` using `rtc.adjust()`. |
| WhatsApp Message Not Sent | Check Wi-Fi, API Key, Phone Format (+CountryCodeNumber). |

---

## 🏆 You're Ready!

You should now have:
- 📈 Real-time air quality monitoring
- 🛎️ Automatic alerts via WhatsApp
- 📝 Data logging onto SD Card

> Happy Arduino! 🚀💨
