const int input2 = 2;
const int input1 = 3;
const int enablePin = 5; 

void setup(){
  pinMode(input2, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(enablePin, OUTPUT);

  analogWrite(enablePin, 150);
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
}

void loop() {

}
