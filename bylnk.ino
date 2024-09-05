#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Define the relay pins
#define led1 D0
#define led2 D1

#define BLYNK_AUTH_TOKEN "----------" //Enter your blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "-------";//Enter your WIFI name
char pass[] = "-------";//Enter your WIFI password

//Get the button values
BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  // Check these values and turn the relay1 ON and OFF
  if (value1 == 1) {
    digitalWrite(led1, LOW);
  } else {
    
    digitalWrite(led1, HIGH);
  }
}
//Get the button values
BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  // Check these values and turn the relay1 ON and OFF
  if (value2 == 1) {
    digitalWrite(led2, LOW);
  } else {
    digitalWrite(led2, HIGH);
  }
}
void setup() {
  //Set the relay pins as output pins
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // Turn OFF the relay
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}
void loop() {
  //Run the Blynk library
  Blynk.run();
}
