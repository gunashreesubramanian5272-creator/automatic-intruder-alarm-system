// Define pins for components
const int pirPin = 2;   // PIR sensor connected to digital pin 2
const int buzzerPin = 3; // Buzzer connected to digital pin 3
const int ledPin = 13;   // LED connected to digital pin 13 (optional)

int pirState = LOW;      // Current state of the PIR sensor (LOW = no motion)
int lastPirState = LOW;  // Previous state of the PIR sensor

void setup() {
  // Initialize pins
  pinMode(pirPin, INPUT);  // PIR sensor as input
  pinMode(buzzerPin, OUTPUT); // Buzzer as output
  pinMode(ledPin, OUTPUT);  // LED as output
  
  // Start Serial Monitor (optional for debugging)
  Serial.begin(9600);
}

void loop() {
  // Read PIR sensor
  pirState = digitalRead(pirPin);

  // Check if PIR sensor detects motion
  if (pirState == HIGH) {
    // Motion detected
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    digitalWrite(ledPin, HIGH);    // Turn on LED (optional)
    
    // Print message to Serial Monitor (optional)
    Serial.println("Motion detected!");
    
    // Wait to avoid continuous alerts
    delay(500);
  } else {
    // No motion detected
    digitalWrite(buzzerPin, LOW); // Turn off buzzer
    digitalWrite(ledPin, LOW);    // Turn off LED (optional)
    
    // Print message to Serial Monitor (optional)
    Serial.println("No motion.");
    
    // Small delay to reduce noise
    delay(200);
  }
}
