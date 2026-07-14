#include <ESP32Servo.h>
#include <HCSR04_ESP.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define servoPin 12
#define echoPin 39
#define trigPin 17
#define R_LED 22
#define G_LED 21
#define BUZZER 27


Servo MyServo;
HCSR04Sensor sensor(17, 39);

void setup() {
  Serial.begin(115200);
  sensor.begin();
  pinMode(17, OUTPUT);
  pinMode(39, INPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(27, OUTPUT);
  MyServo.attach(servoPin);
  MyServo.write(0);
  digitalWrite(G_LED, HIGH);
  digitalWrite(R_LED, LOW);
  digitalWrite(BUZZER, LOW);
}

void loop() {
   int i = 0;
   for(i = 0; i <= 180; i++) {
    MyServo.write(i);
    float distance = sensor.readDistanceCm();
    if(distance <= 20) {
      digitalWrite(R_LED, HIGH);
      digitalWrite(G_LED, LOW);
      digitalWrite(BUZZER, HIGH);
    } else {
      digitalWrite(R_LED, LOW);
      digitalWrite(G_LED, HIGH);
      digitalWrite(BUZZER, LOW);
    }
    
   }
   for(i = 180; i >= 0; i--) {
    MyServo.write(i);
    float distance = sensor.readDistanceCm();
    if(distance <= 20) {
      digitalWrite(R_LED, HIGH);
      digitalWrite(G_LED, LOW);
      digitalWrite(BUZZER, HIGH);
    } else {
      digitalWrite(R_LED, LOW);
      digitalWrite(G_LED, HIGH);
      digitalWrite(BUZZER, LOW);
    }
    
  }
}
