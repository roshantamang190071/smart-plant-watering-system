
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define TRIGGERPIN D6
#define ECHOPIN    D5
#define RELAY      D4

//wifi
char ssid[] = "123456";
char pass[] = "123456789";

char auth[] = "333ycQKmqKImmE8AXY0jMXY3KV0EvlXc"; //blynk auth

//blynk button
const int BUTTON = 3;
int BUTTON_STATE = 0;

WidgetLCD lcd(V3);

void setup()
{
  Serial.begin(115200);

  pinMode(BUTTON, INPUT);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  long duration, distance;
  
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2) / 29.1;

  Blynk.virtualWrite(V1, distance);
  
  Serial.print(distance);
  Serial.println("Cm");

  Blynk.run();  

}
