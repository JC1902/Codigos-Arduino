#include <DHT.h>
#include <Servo.h>

const int input2 = 2;
const int input1 = 3;
const int enablePin = 5;
#define DHTPIN A0
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
// room temperature in Celsius
const float baselineTemp = 20.0;
DHT dht(DHTPIN, DHTTYPE);

Servo servo_1;

void setup(){
  Serial.begin(9600);
  
  pinMode(input2, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(enablePin, OUTPUT);

  analogWrite(enablePin, 150);
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  
  servo_1.attach(8);

   dht.begin();
}

void loop() {

// Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahrenheit
  float f = dht.readTemperature(true);

  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
  // Calcular el índice de calor en Fahrenheit
  float hif = dht.computeHeatIndex(f, h);
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);

  // if the current temperature is lower than the baseline turn off all LEDs
  if (hic > 25) {
    digitalWrite(input1, LOW);
  	digitalWrite(input2, HIGH);
    
    servo_1.write(90);
    
  } else {
    digitalWrite(input1, LOW);
  	digitalWrite(input2, LOW);
    
    servo_1.write(0);
  }

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
}
