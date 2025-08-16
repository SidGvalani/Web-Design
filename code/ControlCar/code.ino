/*
Sketch to control an RC Car using a web server. Sliders to control speed, and arrow buttons (up, down, left, and right) to control direction.
*/

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

void clientRoot(){
    R"rawliteral(
<html>
    <title>RC Car</title>
     <h1> ESP32 Controlled RC Car</h1>
        <body>
            <<button> UP </button>

        </body>

  
    )rawliteral"
  
}

void directionControl(){}

void speedControl(){}

void setup(){}


void loop(){}

