#include <Arduino_BuiltIn.h>

int trigPin = 12;
int echoPin = 11;
int speaker = 8;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speaker, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/58.2);
  if (distance < 100 && distance > 5) {  // This is where the LED On/Off happens
    digitalWrite(speaker,HIGH); // When the Red condition is met, the Green LED should turn off
}
  else {
    digitalWrite(speaker,LOW);
  }
  if (distance >= 200 || distance <= 0){
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
  //  delayMicroseconds(1000); - Removed this line
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/58.2);
    if (distance < 100 && distance > 5) {  // This is where the LED On/Off happens
      digitalWrite(speaker,HIGH); // When the Red condition is met, the Green LED should turn off
  }
    else {
      digitalWrite(speaker,LOW);
    }
    if (distance >= 200 || distance <= 0){
      Serial.println("Out of range");
    }
    else {
      Serial.print(distance);
      Serial.println(" cm");
    }
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  digitalWrite(speaker,LOW);
  delay(50);
}
