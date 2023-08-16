

#include <ESP32Servo.h>

#define BLYNK_TEMPLATE_ID           "TMPL6GLTnhRv9"
#define BLYNK_DEVICE_NAME           "Iot"
#define BLYNK_AUTH_TOKEN            "SEYzlM7iYOryw0D5MJjNwXeDgEwLn_Eq"


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "NotMe";
char pass[] = "awan1234";
#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

#define SPEAKER 2
void chirp() {  // Bird chirp
  for(uint8_t i=200; i>180; i--)
     playTone(i,9);
}

void meow() {
  uint16_t i;
  playTone(5100,50);
  playTone(394,180);
  for(i=990; i<1022; i+=2)
     playTone(i,8);
  playTone(5100,40);
}

void meow2() {
  uint16_t i;
  playTone(5100,55);
  playTone(394,170);
  delay(30);
  for(i=330; i<360; i+=2)
     playTone(i,10);
  playTone(5100,40);
}

void mew() {  // cat mew
  uint16_t i;
  playTone(5100,55);
  playTone(394,130);
  playTone(384,35);
  playTone(5100,40);
}

void ruff() {   // dog ruff
  uint16_t i;
  for(i=890; i<910; i+=2)
     playTone(i,3);
  playTone(1664,150);
  playTone(12200,70);
}

void arf() {    // dog arf
  uint16_t i;
  playTone(890,25);
  for(i=890; i<910; i+=2)
     playTone(i,5);
  playTone(4545,80);
  playTone(12200,70);
}

// play tone on a piezo speaker: tone shorter values produce higher frequencies
//  which is opposite beep() but avoids some math delay - similar to code by Erin Robotgrrl

void playTone(uint16_t tone1, uint16_t duration) {
  if(tone1 < 50 || tone1 > 15000) return;  // these do not play on a piezo
  for (long i = 0; i < duration * 1000L; i += tone1 * 2) {
     digitalWrite(SPEAKER, HIGH);
     delayMicroseconds(tone1);
     digitalWrite(SPEAKER, LOW);
     delayMicroseconds(tone1);
  }
}

BLYNK_WRITE(V0)
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
    chirp();

  }
}

BLYNK_WRITE(V1)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0x3366ff);
    pixels.setPixelColor(1, 0x3366ff);
    pixels.setPixelColor(2, 0x3366ff);
    pixels.setPixelColor(3, 0x3366ff);
    pixels.setPixelColor(4, 0x3366ff);
    pixels.show();
    pixels.show();
    ruff();

  }
}

BlynkTimer Timer1;

void Timer1_TimerEvent()
{
//  Blynk.virtualWrite(V20, ultrasonic(12,27));
  Blynk.virtualWrite(V10, analogRead(36));
}

BLYNK_WRITE(V50)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,200);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,200);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V51)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,200);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,200);

  } else {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,0);

  }
}

Servo servo_5;
BLYNK_WRITE(V60)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    servo_5.write(170);

  } else {
    servo_5.write(90);
    delay(1000);

  }
}

BLYNK_WRITE(V54)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,100);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V53)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,100);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pixels.begin();

    pinMode(SPEAKER,OUTPUT);  //

  pinMode(36, INPUT);
  Timer1.setInterval(100, Timer1_TimerEvent);

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
  Timer1.run();
}
