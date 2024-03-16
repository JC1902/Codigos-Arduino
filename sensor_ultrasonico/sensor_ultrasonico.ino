#include <Servo.h>

// Declaracion de variables
Servo myServo;
int TRIG = 8;
int ECO = 9;
int tiempo;
int distancia;

void setup() {
  pinMode(2, OUTPUT); // Poner el pin 2 como salida
  pinMode(3, OUTPUT); // Poner el pin 3 como salida
  pinMode(TRIG, OUTPUT); // Poner una de las terminales del sensor ultrasonico como salida
  pinMode(ECO, INPUT); // Poner una de las terminales del sensor ultrasonico como entrada
  myServo.attach(5); // Marcar que pin va a manejar el servo
  onOffLeds(); // Ejecutar la función que enciende y apaga los leds
  Serial.begin(9600);
}

void loop() {
  leerDistancia();
  // Si la distancia que detecta el sensor es menor a 10 ejecuta la función de abrir la puerta y dos segundos después se cierra
  if (distancia < 10) { 
    onOffLeds();
    abrirPuerta();
    delay(2000);
    cerrarPuerta();
    delay(2000);
  }
}

void leerDistancia() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  tiempo = pulseIn(ECO, HIGH);
  distancia = tiempo / 58.2;
}

void onOffLeds() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(100);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void cerrarPuerta() {
  // Apagar un led y encender el otro
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  int angulo = 0;
  do { // Hacer que el servo se mueva mientras el angulo sea menor a 90
    angulo = angulo + 1;
    myServo.write(angulo);
    delay(50);
  } while (angulo < 90);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void abrirPuerta() {
  // Apagar un led y encender el otro
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  int angulo = 90;
  do { // Hacer que el servo se mueva mientras el angulo sea mayor a 0
    angulo = angulo - 1;
    myServo.write(angulo);
    delay(50);
  } while (angulo > 0);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}