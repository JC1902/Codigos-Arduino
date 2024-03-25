// Definir los pines
#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2); // I2C address 0x27, 16 column and 2 rows

const int pirPin = 2; // Conectar el pin de señal del sensor PIR al pin digital 2

// Variable para almacenar el estado del sensor PIR
int pirState = LOW;

void setup() {
  pinMode(pirPin, INPUT); // Configurar el pin del sensor PIR como entrada
  lcd.begin(16, 2);
  Serial.begin(9600); // Iniciar la comunicación serial a 9600 baudios
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Leer el estado del sensor PIR
  pirState = digitalRead(pirPin);

  if (pirState == HIGH) { // Si se detecta movimiento
    lcd.clear();
    lcd.setCursor(0, 0); // Establecer el cursor en la primera línea
    lcd.print("Se movio!!!");
    delay(1000); // Esperar un segundo
  } else {
    lcd.clear(); // Limpiar la pantalla LCD
    lcd.setCursor(0, 0); // Establecer el cursor en la primera línea
    lcd.print("Todo en orden");
    Serial.println("NO HAY NADA");
    delay(1000);
  }
}
