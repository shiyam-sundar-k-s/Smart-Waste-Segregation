#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "IOT";
const char* password = "IOT12345";

const char* apiKey = "2TY0BC00MJ5VG30X";
const char* serverURL = "https://api.thingspeak.com/update";

#define TRIG1 4
#define ECHO1 5
#define TRIG2 18
#define ECHO2 19

#define GREEN_LED1 12
#define RED_LED1 14
#define GREEN_LED2 26
#define RED_LED2 27

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long previousUpdate = 0;

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Garbage Monitor");

  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(GREEN_LED1, OUTPUT);
  pinMode(RED_LED1, OUTPUT);
  pinMode(GREEN_LED2, OUTPUT);
  pinMode(RED_LED2, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi Connected");
}

float readUltrasonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float time = pulseIn(echoPin, HIGH);
  return (time * 0.0343) / 2.0;
}

void uploadToThingSpeak(float val1, float val2) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String endpoint = String(serverURL) + "?api_key=" + apiKey + "&field1=" + val1 + "&field2=" + val2;
    http.begin(endpoint);
    int response = http.GET();
    Serial.print("ThingSpeak Response: ");
    Serial.println(response);
    http.end();
  } else {
    Serial.println("Wi-Fi Disconnected!");
  }
}

void loop() {
  float bin1 = readUltrasonic(TRIG1, ECHO1);
  float bin2 = readUltrasonic(TRIG2, ECHO2);

  Serial.print("Bin1: ");
  Serial.print(bin1);
  Serial.print(" cm, Bin2: ");
  Serial.println(bin2);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DB1: ");
  lcd.print(bin1);
  lcd.print("cm");

  lcd.setCursor(0, 1);
  lcd.print("DB2: ");
  lcd.print(bin2);
  lcd.print("cm");

  digitalWrite(RED_LED1, bin1 <= 15);
  digitalWrite(GREEN_LED1, bin1 > 15);
  digitalWrite(RED_LED2, bin2 <= 15);
  digitalWrite(GREEN_LED2, bin2 > 15);

  if (millis() - previousUpdate >= 15000) {
    uploadToThingSpeak(bin1, bin2);
    previousUpdate = millis();
  }

  delay(1000);
}