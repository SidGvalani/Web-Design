# ESP32 Servo Control via Web Interface

This project demonstrates how to control a **servo motor** connected to an **ESP32** through a simple **web interface**.  
The ESP32 hosts a webpage with a slider, and moving the slider updates the servo angle in real time.



##  Features
- Connect ESP32 to WiFi and serve a webpage.
- Webpage includes a slider (`0°–180°`) to control servo position.
- Live feedback: shows current servo angle as the slider is moved.
- Servo updates instantly over HTTP requests (`/setServo?pos=X`).



## 🛠 Hardware Requirements
- ESP32 development board  
- Servo motor (e.g., SG90 or MG995)  
- External power supply for servo (if needed)  
- Jumper wires  

**Connections**
- Servo Signal → GPIO 18 (configurable in code)
- Servo VCC → 5V (or external supply depending on servo)
- Servo GND → ESP32 GND



##  Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/software) with ESP32 board package installed
- Libraries:
  - `WiFi.h` (built-in with ESP32)
  - `WebServer.h` (built-in with ESP32)
  - `ESP32Servo.h` ([ESP32Servo Library](https://github.com/madhephaestus/ESP32Servo))



##  Setup & Usage
1. Clone this repo or copy the `.ino` file into Arduino IDE.
2. Update your WiFi credentials in the code:
   ```cpp
   const char* ssid = "yourSSID";
   const char* password = "yourPASSWORD";
