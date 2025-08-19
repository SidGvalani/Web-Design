#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "yourSSID";
const char* password = "yourPASSWORD";

WebServer server(80);
Servo servoLink1;
const int servoPin1 = 18; // PWM-capable pin

// HTML page with a slider
String htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
  <body>
    <h2>ESP32 Servo Control</h2>
    <input type="range" min="0" max="180" value="90" id="servoSlider" oninput="updateServo(this.value)">
    <p>Position: <span id="posValue">90</span> degrees</p>

    <script>
      function updateServo(pos) {
        document.getElementById("posValue").innerText = pos;
        fetch(`/setServo?pos=${pos}`);
      }
    </script>
  </body>
</html>
)rawliteral";

// Serve the main page
void handleRoot() {
  server.send(200, "text/html", htmlPage);
}

// Handle slider position changes
void handleSetServo() {
  if (server.hasArg("pos")) {
    int pos = server.arg("pos").toInt();
    servoLink1.write(pos);
    Serial.printf("Servo moved to %d degrees\n", pos);
  }
  server.send(200, "text/plain", "OK");
}

void setup() {
  Serial.begin(115200);
  servoLink1.attach(servoPin1);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/setServo", handleSetServo);
  server.begin();
}

void loop() {
  server.handleClient();
}
