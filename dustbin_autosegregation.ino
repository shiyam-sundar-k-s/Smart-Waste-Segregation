#include <CheapStepper.h>
#include <Servo.h>

Servo servo1;
#define IR_SENSOR 5
#define PROXIMITY_SENSOR 6
#define BUZZER 12
#define POT_PIN A0

int soil = 0;
int fsoil;
CheapStepper stepper(8, 9, 10, 11);

void setup() {
  Serial.begin(9600);
  pinMode(PROXIMITY_SENSOR, INPUT);  
  pinMode(IR_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  servo1.attach(7);
  stepper.setRpm(17);

  servo1.write(180);
  delay(1000);
  servo1.write(70);
  delay(1000);
}

void loop() {
  fsoil = 0;
  int metalState = digitalRead(PROXIMITY_SENSOR);

  if (metalState == 0) {
    tone(BUZZER, 1000, 1000);
    stepper.moveDegreesCW(240);
    delay(1000);
    servo1.write(180);
    delay(1000);
    servo1.write(70);
    delay(1000);
    stepper.moveDegreesCCW(240);
    delay(1000);
  }

  if (digitalRead(IR_SENSOR) == 0) {
    tone(BUZZER, 1000, 500);
    delay(1000);
    fsoil = 0;

    for (int i = 0; i < 3; i++) {
      soil = analogRead(POT_PIN);
      soil = constrain(soil, 485, 1023);
      fsoil += map(soil, 485, 1023, 100, 0);
      delay(75);
    }

    fsoil = fsoil / 3;

    if (fsoil > 20) {
      stepper.moveDegreesCW(120);
      delay(1000);
      servo1.write(180);
      delay(1000);
      servo1.write(70);
      delay(1000);
      stepper.moveDegreesCCW(120);
      delay(1000);
    } else {
      tone(BUZZER, 1000, 500);
      delay(1000);
      servo1.write(180);
      delay(1000);
      servo1.write(70);
      delay(1000);
    }
  }

  delay(200);
}