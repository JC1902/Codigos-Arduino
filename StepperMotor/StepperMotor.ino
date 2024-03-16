#include <Stepper.h>

int PPV = 2048;
int rotacion = 1;
Stepper motor( PPV, 8, 10, 9, 11 );

void setup() {
  Serial.begin(9600);
  motor.setSpeed(10);
}

void loop() {
  for(int i = 0; i <= 95 ; i++){
    motor.step(1 * rotacion);
    delay(100);
    Serial.println(String(i));
  }

  rotacion *= -1;
}
