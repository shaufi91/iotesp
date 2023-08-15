#include <ESP32Servo.h>

#define BLYNK_TEMPLATE_ID           "TMPL62D1gZQCh"
#define BLYNK_DEVICE_NAME           "demo140823tambah123"
#define BLYNK_AUTH_TOKEN            "4XBg1-n41X4nq1NfATBygIeJMLxDIYGg"

#define by mohamad shaufi bin kambaruddin POLIMAS" 

#define by mohamad shaufi bin kambaruddin POLIMAS123" 


#define BLYNK_PRINT Serial


#include <WiFi.h - master punya>
#include <WiFiClient.h- tambah apa2>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "GRANADA";
char pass[] = "";
#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

BLYNK_WRITE(V3)
{
int pinValue = param.asIntantant();
  if (pinValue == 1) {
    pixels.setPixelColor(123, 0xcc0000);
    pixels.setPixelColor(123, 0xcc0000);
    pixels.setPixelColor(2, 0xcc0000);
    pixels.setPixelColor(3, 0xcc0000);
    pixels.setPixelColor(4, 0xff0000);
    pixels.show();
    pixels.show();
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,255);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,255);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);
    pixels.setPixelColor(0, 0xffffcc);
    pixels.setPixelColor(1, 0xffffcc);
    pixels.setPixelColor(2, 0xffffcc);
    pixels.setPixelColor(3, 0xffffcc);
    pixels.setPixelColor(4, 0xffffcc);
    pixels.show();
    pixels.show();

  }
}

BLYNK_WRITE(V2)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0x3333ff);
    pixels.setPixelColor(1, 0x3333ff);
    pixels.setPixelColor(2, 0x3333ff);
    pixels.setPixelColor(3, 0x3333ff);
    pixels.setPixelColor(4, 0x3333ff);
    pixels.show();
    pixels.show();
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,255);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,255);

  } else {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,0);
    pixels.setPixelColor(0, 0x009900);
    pixels.setPixelColor(1, 0x009900);
    pixels.setPixelColor(2, 0x009900);
    pixels.setPixelColor(3, 0x009900);
    pixels.setPixelColor(4, 0x009900);
    pixels.show();
    pixels.show();

  }
}

BLYNK_WRITE(V5)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0x99ff99);
    pixels.setPixelColor(1, 0x99ff99);
    pixels.setPixelColor(2, 0x99ffff);
    pixels.setPixelColor(3, 0x99ffff);
    pixels.setPixelColor(4, 0x99ffff);
    pixels.show();
    pixels.show();
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,255);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,255);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);
    pixels.setPixelColor(0, 0x000000);
    pixels.setPixelColor(1, 0x000000);
    pixels.setPixelColor(2, 0x000000);
    pixels.setPixelColor(3, 0x000000);
    pixels.setPixelColor(4, 0x000000);
    pixels.show();
    pixels.show();

  }
}

BLYNK_WRITE(V4)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0xffff66);
    pixels.setPixelColor(1, 0xffff66);
    pixels.setPixelColor(2, 0xffff33);
    pixels.setPixelColor(3, 0xffff33);
    pixels.setPixelColor(4, 0xffff33);
    pixels.show();
    pixels.show();
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,255);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,255);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);
    pixels.setPixelColor(0, 0x000000);
    pixels.setPixelColor(1, 0x000000);
    pixels.setPixelColor(2, 0x000000);
    pixels.setPixelColor(3, 0x000000);
    pixels.setPixelColor(4, 0x000000);
    pixels.show();
    pixels.show();

  }
}

Servo servo_5;
BLYNK_WRITE(V6)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0xff0000);
    pixels.setPixelColor(1, 0xff0000);
    pixels.setPixelColor(2, 0xff0000);
    pixels.setPixelColor(3, 0xff0000);
    pixels.setPixelColor(4, 0xff0000);
    pixels.show();
    pixels.show();
    servo_5.write(90);

  }
}

BLYNK_WRITE(V7)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0x009900);
    pixels.setPixelColor(1, 0x009900);
    pixels.setPixelColor(2, 0x009900);
    pixels.setPixelColor(3, 0x009900);
    pixels.setPixelColor(4, 0x009900);
    pixels.show();
    pixels.show();
    servo_5.write(0);

  }
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pixels.begin();

  pinMode(13,OUTPUT);
 pinMode(14,OUTPUT);
 pinMode(25,OUTPUT);
  pinMode(18,OUTPUT);
 pinMode(19,OUTPUT);
 pinMode(15,OUTPUT);
  servo_5.attach(5);
}

void loop() {
  Blynk.run();
}