const int pirPin = 2;      // PIR motion sensor input
const int ldrPin = A0;     // LDR (light sensor) input
const int lightPin = 3;    // Relay/LED output
const int darkThreshold = 500;  // Adjust based on testing

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);    // HIGH if motion detected
  int lightLevel = analogRead(ldrPin); // Lower value = darker

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print(" | Light: ");
  Serial.println(lightLevel);

  // If motion detected AND room is dark → Turn ON light
  if (motion == HIGH && lightLevel < darkThreshold) {
    digitalWrite(lightPin, HIGH);  // Light ON
    delay(30000);  // Keep light ON for 30 sec
  } 
  else {
    digitalWrite(lightPin, LOW);   // Light OFF
  }
  delay(100);  // Small delay to stabilize readings
}