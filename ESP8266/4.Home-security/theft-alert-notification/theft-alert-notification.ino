#define BLYNK_TEMPLATE_ID "TMPL3uxG3GeXQ"
#define BLYNK_TEMPLATE_NAME "Theft Alert"
#define BLYNK_AUTH_TOKEN "6PIVw-PyeDLvsHCdTjZt8CR1CjG8BWf9"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "AARIVTECHNOLOGIES";  // type your wifi name
char pass[] = "1286793808";  // type your wifi password
 
#define PIR_SENSOR  2
BlynkTimer timer;
//int flag=0;
void notifyOnTheft()
{
  int isTheftAlert = digitalRead(PIR_SENSOR);
  Serial.println(isTheftAlert);
  if (isTheftAlert==1) {
    Serial.println("Theft Alert in Home");
    Blynk.logEvent("alert","Theft Alert in Home");
//    flag=1;
  }
  else if (isTheftAlert==0)
  {
   // flag=0;
  }
}

void setup(){
  pinMode(PIR_SENSOR, INPUT);
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(5000L, notifyOnTheft);
}

void loop(){
  Blynk.run();
  timer.run();
}
