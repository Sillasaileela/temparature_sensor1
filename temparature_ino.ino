#include<arduino.h>
// Pin connections
const int sensorPin = A0; // LM35 sensor connected to analog pin A0
const int ledPin = 13;    // Onboard LED connected to digital pin 13

// Variables
int temperature;  // To store temperature readings

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  temperature = getTemperature(); // Read temperature
  Serial.print("Temperature: ");
  Serial.println(temperature); // Output temperature to serial monitor for debugging

  if (temperature < 30) {
    digitalWrite(ledPin, HIGH); // Turn on LED
    delay(250);
    digitalWrite(ledPin, LOW); // Turn off LED
    delay(250);
  } else {
    digitalWrite(ledPin, HIGH); // Turn on LED
    delay(500);
    digitalWrite(ledPin, LOW); // Turn off LED
    delay(500);
  }
}

int getTemperature() {
  int sensorValue = analogRead(sensorPin); // Read sensor value
  float voltage = (sensorValue / 1023.0) * 5.0; // Convert to voltage (0 to 5V)
  float temperatureC = (voltage - 0.5) * 100.0; // Convert voltage to temperature in Celsius
  return (int)temperatureC; // Return temperature
}

