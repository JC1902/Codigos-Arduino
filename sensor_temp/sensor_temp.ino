// Incluimos librería
#include <DHT.h>
#include "Servo.h"
 
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN A0
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
const int pinLED_Rojo = 2;
const int pinLED_Azul = 3;
const int pinLED_Amarillo = 4;
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializamos comunicación serie
  Serial.begin(9600);
 
  // Comenzamos el sensor DHT
  dht.begin();
}

void loop() {
    // Esperamos 5 segundos entre medidas
  delay(1000);
 
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

  if (hic > 25) {
    // Temperatura alta, encender LED azul y apagar LED rojo
    analogWrite(pinLED_Azul, 0);
    analogWrite(pinLED_Rojo, 255);
    analogWrite(pinLED_Amarillo, 0);
  } else if (hic > 20 && hic < 25 ) {
    // Temperatura baja, encender LED rojo y apagar LED azul
    analogWrite(pinLED_Rojo, 0);
    analogWrite(pinLED_Azul, 255);
    analogWrite(pinLED_Amarillo, 0);
  } else {
    // Temperatura dentro del rango normal, apagar ambos LEDs
    analogWrite(pinLED_Rojo, 0);
    analogWrite(pinLED_Azul, 0);
    analogWrite(pinLED_Amarillo, 255);
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