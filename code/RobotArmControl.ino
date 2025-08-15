/*
Sketch displays http requests to set servo angle using a slider as html. The client will update slider during live-time, consequently updating servo angle.

Connect servo pin to any PWM enabled pin on ESP32.
*/
void handleBack(){
if(server.hasArg("pos"){
  int pos = server.Arg("pos").toInt(); // convert literal to integer
  servo.write(pos); // move servo to position
  server.send(200,"text/html","OK");
              }
}
void handleFront(){
  R"rawliteral(
    <html>
      <body>
        <title> Robot Arm </title>
          <h1> ESP32 Servo Control </h1>
            <div class = "slider-container">
               <input type = "range" min = "0" max = "180" value = "90" id = "slider" oninput = updatePos(this.value)> // updates live position
             <p> Position: <span id = "posValue">90</span></p>  // creates a spanner called posValue that will update as the slider moves
             </div>
              <script>
            void updatePos(String "pos"){
                document.getElementById("pos").innerText = pos;
                fetch(`/setServo?pos-${pos}`) // sends a request to http to 
              }
               </script>
        </body>
    </html>
              }
  )rawliteral";
  }

 void setup(){

  Serial.begin(115200);
  servoLink1.attach(18);
  WiFi.begin(ssid,psswrd);
  Serial.print("Connecting...");
  while(WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    delay(1000);
  }
  Serial.println("Connected!");
  delay(2000);
  Serial.println("IP Address: ");
  Serial.print(WiFi.localIP());
  delay(1000);

  server.on("/",handleFront);
  server.on("/setServo",handleBack);
  server.begin();
 }

void loop(){
  handleClient();
}
