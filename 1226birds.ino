#include "Arduino.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
 
const char* ssid = "smallblack";
const char* password = "0487ggyy";
String website;
WebServer server(80);

int fsr_value;
int led_value;
const int led_pin = 23;
const int fsr_pin = A0;
unsigned long timer;
//int ledChannel=0;
//int resolution=8;
//int freq=5000;


void handleRoot() {
  server.send(200, "text/html", website);
}

void buildweb1(){
  website +="<html>";
  website += "<head>\n";
  website += "<meta charset='UTF-8'/>\n";
  website +=  "<meta name='viewport' content='width=device-width, initial-scale=1.0'/>";
  website += "<meta http-equiv='X-UA-Compatible' content='ie=edge'>";
  website += "<title>Document</title>";
  website += "</head>";
  website += "<body>";
  website += "<h1>bird1</h1>";
  website += "</body>";
  website += "</html>"; 
  }

void setup()
{
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  buildweb1();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
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
