#define BLYNK_TEMPLATE_ID "TMPLbRggj5dFHx-"
#define BLYNK_DEVICE_NAME "Rain Alert Notification"
#define BLYNK_AUTH_TOKEN "o8tiLRfdgjkkuGOirpZLQE0ooOGBgU7Nnor_gL"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "";  // type your wifi name
char pass[] = "";  // type your wifi password

#define RAIN_SENSOR  4
BlynkTimer timer;
int flag = 0;

void notifyOnRain() {
  int isButtonPressed = digitalRead(RAIN_SENSOR);

  if (isButtonPressed == 0 && flag == 0) {
    Serial.println("It's Raining");
    Blynk.logEvent("rain_alert", "It's Raining");
    flag = 1;
  } else if (isButtonPressed == 1) {
    flag = 0;
  }
}

void setup() {
  pinMode(RAIN_SENSOR, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2500L, notifyOnRain);
}

void loop() {
  Blynk.run();
  timer.run();
}
