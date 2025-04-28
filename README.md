# AsthmaGuardian-ESP32 _(still under development)_

> _AirQuality-Monitor-ESP32_

An advanced **IoT air quality monitoring system** built with **ESP32** to help protect asthma patients and sensitive individuals.  
It measures **PM2.5**, **temperature**, and **humidity**, sends **WhatsApp alerts** during dangerous air conditions, and **logs data** onto an SD card for long-term analysis.

---

## 📋 Project Features

✅ PM2.5 Fine Dust Monitoring (SDS011 Sensor)  
✅ Temperature, Humidity, and VOC Monitoring (BME680 Sensor)  
✅ Real-Time Clock with Battery Backup (DS3231 RTC)  
✅ Data Logging to MicroSD Card (CSV Format)  
✅ WhatsApp Alert Notification (using CallMeBot API)  
✅ Automatic Wi-Fi Reconnection  
✅ RGB LED and Buzzer Alerts  
✅ Professional Modular Arduino Code  
✅ Expandable and Customizable

---

## 📚 Hardware Components

| Component | Model |
|:---|:---|
| Microcontroller | ESP32 Dev Board |
| PM2.5 Dust Sensor | SDS011 |
| Temperature, Humidity, VOC Sensor | BME680 |
| Real-Time Clock | DS3231 |
| MicroSD Card Module | Standard SPI-based |
| RGB LED | Common Cathode or Anode |
| Buzzer | 5V Active |
| Power Supply | Lithium Battery / USB |
| Breadboard + Jumper Wires | Various |

---

## 🛠️ Setup Instructions

Detailed instructions are available inside [tools/setup_instructions.md](tools/setup-instructions.md).

Quick Steps:

1. Install Arduino IDE or PlatformIO.
2. Install ESP32 Board Support via Board Manager.
3. Install Required Libraries:
    - Adafruit BME680
    - Adafruit Unified Sensor
    - RTClib
    - SDS011
    - SD
    - WiFi
    - HTTPClient
4. Configure:
    - Wi-Fi credentials in `wifi_manager.cpp`.
    - WhatsApp API Key and Phone Number in `alert_manager.cpp`.
5. Connect the hardware
6. Upload `src/main/main.ino` to ESP32.
7. Monitor the Serial Monitor for system logs.

---

## 🧩 Code Structure

| Folder | Purpose |
|:---|:---|
| `src/main/` | Main modular code (Sensors, Wi-Fi, Alerts, Logger) |
| `lib/` | (Optional) Custom Libraries |
| `docs/` | Architecture Diagrams, Flowcharts, Hardware Guides |
| `hardware/` | Fritzing / Schematic Diagrams _(>Progress<)_|
| `tools/` | Setup Guides, Helper Scripts |
| `data/` | Example Data Logs |

---

## ⚡ Future Improvements

- 🛰️ Upload data to ThingSpeak / InfluxDB Cloud
- 📊 Real-time dashboard via WebServer
- 🔋 Battery level monitoring and OTA updates
- 🏥 Integrate Air Quality Index (AQI) calculation
- 📡 Offline Mode enhancements with local buzzer-only alerts

---

## 📜 License

This project is licensed under the **MIT License** — free for personal and commercial use with attribution.

---

## 💬 Questions or Ideas?

Feel free to open an **Issue** or **Pull Request** to contribute improvements!  
Let's protect health with technology! ❤️💨
