// C++ code
//
int sensor = 0;

void setup()
{
  pinMode(A0, INPUT); // pin A0 como entrada
  pinMode(8, OUTPUT); // pin 8 como salida
  Serial.begin(9600); // usar el monitor serial
}

void loop()
{
  sensor = analogRead(A0);
  if (sensor > 300) {
    // si la lectura del sensor supera la cantidad
    // se va encender el LED
    digitalWrite(8, HIGH);
  } else {
    // si no, se apaga el LED
    digitalWrite(8, LOW);
  }
  // Mostrar en el monitor serial la lectura del sensor
  Serial.print("sensor = ");
  Serial.println(sensor);
  delay(100); // Wait for 100 millisecond(s)
}