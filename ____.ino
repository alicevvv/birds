#include "Arduino.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

int fsr_value;
int led_value;
const int led_pin = 23;
const int fsr_pin = A0;
unsigned long timer;
unsigned int flag;
//int ledChannel=0;
//int resolution=8;
//int freq=5000;
void setup()
{
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
//  ledcSetup(ledChannel,freq,resolution);
//  ledcAttachPin(A3,ledChannel);
}

void loop()
{
  fsr_value = analogRead(fsr_pin); // 讀取FSR
  Serial.println(fsr_value);
 if(fsr_value > 0)
 {
  digitalWrite(led_pin,HIGH);
  timer+=1;
 }
//  led_value = map(fsr_value, 0, 2000, 0, 255);// 從0~1023映射到0~255
//  ledcWrite(ledChannel, led_value); // 改變LED亮度
 else {digitalWrite(led_pin,LOW); timer=0;}
  //Serial.println(led_value);
  Serial.println("time=");
  Serial.println(timer);
  Serial.println("-------------");
  delay(1000);
}
