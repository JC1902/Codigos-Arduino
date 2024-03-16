#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  if(BTSerial.available()) {
    char dato = BTSerial.read();
    BTSerial.print("Dato recibido: ");
    BTSerial.println(dato);
  }
}