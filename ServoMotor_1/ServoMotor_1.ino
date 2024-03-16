#include <Servo.h>                 //incluir la libreria Servo

int BOTON = 0;                        // Estado del Botón (los estados pueden ser 0 ó 1)
Servo servo_1;                            //definir que el servo esta conectado al pin 1

void setup() {

  pinMode(2, INPUT);           //definir modo del pin 2 (botón) como entrada

  servo_1.attach(1);              // servo motor sera controlado en el pin 1
}

void loop() {

  BOTON = digitalRead(2);       // leer estado del pin digital 2

  printf(BOTON);

  if (BOTON == 1) {         // si el botón es apretado( toma el valor 1), entonces:....

    servo_1.write(180);     // mover servo 1 a 90° grados

  } else {
    servo_1.write(0);
  }
}