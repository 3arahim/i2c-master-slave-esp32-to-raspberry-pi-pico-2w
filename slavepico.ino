#include <Wire.h>

volatile byte receivedData[4];
volatile bool newData = false;

void receiveEvent(int howMany);

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(LED_BUILTIN, OUTPUT);

  Wire.setSDA(20);
  Wire.setSCL(21);
  Wire.begin(0x08);          // Pico acts as I2C slave at address 0x08
  Wire.onReceive(receiveEvent);

  Serial.println("Pico slave started");
}

void loop() {
  if (newData) {
    noInterrupts();
    byte dataCopy[4];
    for (int i = 0; i < 4; i++) {
      dataCopy[i] = receivedData[i];
    }
    newData = false;
    interrupts();

    Serial.print("Voltage 1: ");
    Serial.println(dataCopy[0]);
    Serial.print("Voltage 2: ");
    Serial.println(dataCopy[1]);
    Serial.print("Current 1: ");
    Serial.println(dataCopy[2]);
    Serial.print("Current 2: ");
    Serial.println(dataCopy[3]);

    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}

void receiveEvent(int howMany) {
  if (howMany >= 4) {
    for (int i = 0; i < 4; i++) {
      if (Wire.available()) {
        receivedData[i] = Wire.read();
      }
    }

    while (Wire.available()) {
      Wire.read();   // discard extras
    }

    newData = true;
  } else {
    while (Wire.available()) {
      Wire.read();   // discard incomplete packet
    }
  }
}