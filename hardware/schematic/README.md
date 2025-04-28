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
