const int moisturePin = A0;
const int pumpPin = 3;
const int dryThreshold = 600; // Adjust based on your sensor

void setup() {
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW); // Ensure pump is off initially
  Serial.begin(9600);
}

void loop() {
  int moisture = analogRead(moisturePin);
  
  Serial.print("Moisture: ");
  Serial.println(moisture);
  
  if(moisture > dryThreshold) {
    digitalWrite(pumpPin, HIGH); // Turn on pump
    delay(2000); // Water for 2 seconds
    digitalWrite(pumpPin, LOW);
  }
  
  delay(1000); // Check every second
}