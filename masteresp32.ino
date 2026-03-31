#include <Wire.h>

uint8_t v1 = 5;  // 0
uint8_t v2 = 10; // 1
uint8_t i1 = 3;  // 2
uint8_t i2 = 6;  // 3
 
volatile uint8_t id = 0;


void setup() {
  Serial.begin(115200);
  delay(1000);
  Wire.begin();
  Serial.println("Master started");
}

void loop() {
  Wire.beginTransmission(8);
  // Voltage
  // Wire.write((uint8_t)0);   // id for v1
  Wire.write(v1);

  // Wire.write((uint8_t)1);   // id for v2
  Wire.write(v2);

  // Current
  // Wire.write((uint8_t)2);   // id for i1
  Wire.write(i1);

  // Wire.write((uint8_t)3);   // id for i2
  Wire.write(i2);

  byte err = Wire.endTransmission();

  Serial.print("I2C err: ");
  Serial.println(err);

  delay(500);
}