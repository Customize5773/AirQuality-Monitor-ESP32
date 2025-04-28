ESP32
├── GPIO16 ----> SDS011 TX
├── GPIO17 ----> SDS011 RX
├── GPIO21 ----> BME680 SDA + DS3231 SDA
├── GPIO22 ----> BME680 SCL + DS3231 SCL
├── GPIO5  ----> MicroSD Card CS
├── GPIO18 ----> MicroSD Card SCK
├── GPIO23 ----> MicroSD Card MOSI
├── GPIO19 ----> MicroSD Card MISO
├── GPIO25 ----> RGB LED RED
├── GPIO26 ----> RGB LED GREEN
├── GPIO27 ----> RGB LED BLUE
├── GPIO14 ----> Active Buzzer +

Power
├── 3.3V from ESP32 powers BME680, DS3231 (with pull-ups)
├── 5V line powers SDS011, MicroSD Module
├── TP4056 manages Li-ion battery input to ESP32 5V

Grounds
├── All modules tied to GND (common ground)

---
## ASCII 

                   +-------------------------+
                   |     ESP32-WROOM-32       |
                   |                          |
                   |  GPIO16  ◀─────── TX ─────┬── SDS011 (UART Sensor)
                   |  GPIO17  ──────── RX ─────┘
                   |
                   |  GPIO21  ─────── SDA ───┬── BME680 (I2C Sensor)
                   |                         ├── DS3231 (RTC Module)
                   |  GPIO22  ─────── SCL ────┘
                   |
                   |  GPIO5   ─────── CS  ─────── MicroSD Card (SPI)
                   |  GPIO18  ─────── SCK ──────▶
                   |  GPIO23  ─────── MOSI ─────▶
                   |  GPIO19  ◀────── MISO ◀────┘
                   |
                   |  GPIO25  ─────── R_LED (RED Channel)
                   |  GPIO26  ─────── G_LED (GREEN Channel)
                   |  GPIO27  ─────── B_LED (BLUE Channel)
                   |
                   |  GPIO14  ─────── Buzzer+
                   |
                   |  GND     ────────────────┬── All Modules Ground
                   |                          └── (SDS011, BME680, DS3231, MicroSD, RGB LED, Buzzer, TP4056)
                   |
                   |  3.3V  ─────── BME680 VCC / DS3231 VCC
                   |  5V    ─────── SDS011 VCC / MicroSD VCC
                   |
                   +-------------------------+
                   
TP4056 Charger:
    IN+  --> 5V USB Input (charging)
    IN-  --> GND
    B+   --> Battery+
    B-   --> Battery-
    OUT+ --> ESP32 5V (Vin)
    OUT- --> GND

