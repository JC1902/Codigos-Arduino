const int ledGreen = 10;
const int ledYellow = 11;
const int ledRed = 13; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledGreen , HIGH);   // poner el Pin en HIGH
  delay(5000);                   // esperar un segundo
  digitalWrite(ledGreen , LOW);    // poner el Pin en LOW
  delay(1000); 

  digitalWrite(ledYellow , HIGH);   // poner el Pin en HIGH
  delay(5000);                   // esperar un segundo
  digitalWrite(ledYellow , LOW);    // poner el Pin en LOW
  delay(1000); 

  digitalWrite(ledRed , HIGH);   // poner el Pin en HIGH
  delay(5000);                   // esperar un segundo
  digitalWrite(ledRed , LOW);    // poner el Pin en LOW
  delay(1000); 
}
