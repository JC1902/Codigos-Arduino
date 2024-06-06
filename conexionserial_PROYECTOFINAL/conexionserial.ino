#include <Servo.h>
const int laserPin=7;
Servo servoMotor;
const int luz = A0;
const int RELAY_PIN = 3;
Servo servoMotor2;
const int sensorPower= 10;
const int sensorPin =A1;

int val = 0;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(sensorPower, OUTPUT);
  Serial.begin(115200);  // Monitor serie
  Serial1.begin(9600);   // Puerto serial con el ESP32
  pinMode(laserPin, OUTPUT);
  servoMotor.attach(8);
  servoMotor2.attach(9);
  
}

void loop() {
  int level = readSensor();

  // Leer datos del ESP32
  if (Serial1.available()) {
    String dataFromESP32 = Serial1.readStringUntil('\n');
    Serial.println(dataFromESP32);
    int value = analogRead(luz);
    Serial1.println(value);
    
    if(dataFromESP32.toInt() == 1){
    Serial.print("Datos recibidos del ESP32: ");
    Serial.println(dataFromESP32);
    digitalWrite(laserPin, HIGH);
    servoMotor.write(180);
    Serial1.println(value);
    digitalWrite(RELAY_PIN, LOW);

    }else if(dataFromESP32.toInt() == 0){
    Serial.print("Datos recibidos del ESP32: ");
    Serial.println(dataFromESP32);
    digitalWrite(RELAY_PIN, HIGH);
    servoMotor2.write(180);
    }
  }
  if(analogRead(luz) < 100){
    digitalWrite(laserPin, LOW);
    servoMotor.write(0);
    delay(1000);
    }
  if (level > 485){
    servoMotor2.write(0);
  }

  delay(1000); // Esperar 1 segundo
}


int readSensor(){
  digitalWrite(sensorPower, HIGH);
  delay(10);
  val = analogRead(sensorPin);
  digitalWrite(sensorPower, LOW);
  return val;
}

/*
const int luz = A0;
const int laserPin=7;

void setup(){
    Serial.begin(9600);
    pinMode(laserPin, OUTPUT);
}

void loop(){
  Serial.println(analogRead(luz));

  if(analogRead(luz) > 100)
  digitalWrite(laserPin, LOW);
  else
  digitalWrite(laserPin, HIGH);
}*/
