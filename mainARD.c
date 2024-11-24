#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservoH.attach(9); // attaches the servo on pin 9 to the servo object
  myservoH2.attach(10);
  myservoM.attach(11);
  myservoM2.attach(12);
}

void loop() {
  if (Serial.available() > 0) {
    float distance = Serial.parseFloat();

    if(distance < 0.18){
      myservoH.write(0);
      myservoH2.write(0);
      delay(15);
    }
    else{
      myservoH.write(180);
      myservoH2.write(180);
    }
    if(distance < 0.09){
      myservoM.write(75);
      myservoM2.write(75);
      delay(15);
    }
    if(distance > 0.19){
      myservoM.write(0);
      myservoM2.write(0);
      delay(15);
    }
    else{
      myservoM.write(90);
      myservoM2.write(0);
    }

    delay(50);
    
  }
