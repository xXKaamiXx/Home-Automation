const int flamePin = 7;
const int alarmPin = 8;

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(alarmPin, OUTPUT);
}

void loop() {
  if(digitalRead(flamePin) == LOW) { // Flame detected
    digitalWrite(alarmPin, HIGH); // Sound alarm
  } else {
    digitalWrite(alarmPin, LOW); // Turn off alarm
  }
  delay(100);
}