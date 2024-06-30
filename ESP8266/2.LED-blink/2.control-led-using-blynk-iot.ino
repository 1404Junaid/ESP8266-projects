#include <ESP8266WiFi.h>

const char* ssid = "AARIVTECHNOLOGIES";         // Replace with your network SSID (name)
const char* password = "1286793808"; // Replace with your network password

void setup() {
  Serial.begin(9600);       // Start the Serial communication to send messages to the computer
  delay(10);

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // This is where you can add code to run repeatedly
}
