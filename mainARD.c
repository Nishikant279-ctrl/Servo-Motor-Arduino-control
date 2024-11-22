#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  if (Serial.available() > 0) {
    float distance = Serial.parseFloat();

    if(distance < 0.18){
      myservo.write(0);
      delay(15);
    }
    if(distance < 0.09){
      myservo.write(75);
      delay(15);
    }
    if(distance > 0.19){
      myservo.write(0);
      delay(15);
    }
    
}
