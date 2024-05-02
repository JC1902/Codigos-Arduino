

void setup()  
{
  Serial.begin(9600);
  pinMode( 13, OUTPUT );
}

void loop() 
{
  if (Serial.available())
  {
    char dato = Serial.read();

    if ( dato == 'n' ) {
      digitalWrite( 13, HIGH );
      Serial.print(dato);
    } else if ( dato == 'f' ) {
      digitalWrite( 13, LOW );
      Serial.print(dato);
    }
    
  }
}