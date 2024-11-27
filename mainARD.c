#include <Servo.h>

const int trigPin1 = 2;
const int echoPin1 = 3;

const int trigPin2 = 4;
const int echoPin2 = 5;

const int servoPin1 = 6;
const int servoPin2 = 7;
const int servoPin3 = 8;
const int servoPin4 = 9;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
}

void loop() {
  // Read distance from sensor 1
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // Read distance from sensor 2
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // Check for hand detection and control servos accordingly
  if (distance1 < 20) {
    servo1.write(180);
  } else {
    servo1.write(0);
  }

  if (distance2 < 20) {
    servo2.write(90);
    servo3.write(0);
  } else {
    servo2.write(0);
    servo3.write(90);
  }

  delay(100);
}
