#include <Servo.h>

Servo myServo;  // Create a servo object

const int servoPin = 9;  // Pin connected to the servo signal wire
int minServoAngle = 0;   // Minimum angle the servo can rotate
int maxServoAngle = 180; // Maximum angle the servo can rotate

void setup() {
  Serial.begin(9600);    // Set baud rate for serial communication
  myServo.attach(servoPin); // Attach the servo to the specified pin
  myServo.write(90);      // Set initial servo position to 90 degrees (center)
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    float distance = data.toFloat();  // Convert received data to a float

    // Map the distance value to a servo angle range
    int servoAngle = map(distance, 0.0, 100.0, minServoAngle, maxServoAngle); // Adjust ranges based on your setup
    myServo.write(servoAngle);

    // Optional: Print debug information
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(", Servo Angle: ");
    Serial.println(servoAngle);
  }
  delay(10); // Delay to avoid overwhelming the serial communication
}
