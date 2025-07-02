#include <Servo.h>
Servo lidServo;

const int trigPin = 6;
const int echoPin = 5;
const int servoPin = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lidServo.attach(servoPin);
  lidServo.write(0); // Closed position
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure echo duration
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // Convert to cm
  
  // Open lid if object is within 30cm
  if(distance < 30) {
    lidServo.write(90); // Open lid
    delay(3000); // Keep open for 3 seconds
  } else {
    lidServo.write(0); // Close lid
  }
  delay(100);
}
