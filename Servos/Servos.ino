#include <Servo.h>                 //incluir la libreria Servo
                      // Estado del Botón (los estados pueden ser 0 ó 1)
Servo servo_1;                            //definir que el servo esta conectado al pin 1
Servo servo_2;

void setup() {

  servo_1.attach(3);              // servo motor sera controlado en el pin 1
  servo_2.attach(4);
  Serial.begin(9600);

}

void loop() {

      servo_1.write(0);
      servo_2.write(0);
  int mover = Serial.read();
    if ( mover == 0 ) {
      servo_1.write(180);
      servo_2.write(180);
      Serial.print(mover);
    } else if ( mover == 1 ) {
      servo_1.write(0);
      servo_2.write(0);
      Serial.print(mover);
    }
  
}