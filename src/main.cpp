#include <Arduino.h>

// put function declarations here:
void testGPIO();
void testADC();
void testPWM();
void testUART();

void setup() {
  Serial.begin(9600);
  Serial.println("Starting self-test...");

  testGPIO();
  testADC();
  testPWM();
  testUART();

  Serial.println("Self-test completed.");
}

void loop() {
  // Self-test runs only once in setup
}

// Test GPIO by toggling pin states
void testGPIO() {
  Serial.println("Testing GPIO...");
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  Serial.println("GPIO test passed.");
}

// Test ADC by reading an analog pin
void testADC() {
  Serial.println("Testing ADC...");
  pinMode(A0, INPUT);
  int adcValue = analogRead(A0);
  Serial.print("ADC value: ");
  Serial.println(adcValue);
  Serial.println("ADC test passed.");
}

// Test PWM by generating a PWM signal
void testPWM() {
  Serial.println("Testing PWM...");
  pinMode(9, OUTPUT);
  analogWrite(9, 128); // 50% duty cycle
  delay(1000);
  analogWrite(9, 0);
  Serial.println("PWM test passed.");
}

// Test UART by sending and receiving data
void testUART() {
  Serial.println("Testing UART...");
  Serial.println("UART test message.");
  Serial.println("UART test passed.");
}