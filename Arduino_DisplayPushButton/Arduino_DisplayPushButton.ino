// Definir los pines

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(0x3f, 16, 2); // I2C address 0x27, 16 column and 2 rows
#include <Adafruit_LiquidCrystal.h>


int num = 0;
//Paso 1
const int pins[7] = { 3, 4, 5, 6, 7, 8, 9 }; 
//                    a  b  c  d  e  f  g
//Paso 2
const byte numbersDisplayAnode[10] = {0b0111111,     //0
                            0b0110000,          //1
                            0b1011011,          //2
                            0b1001111,          //3
                            0b1100110,          //4 1100110
                            0b1101101,          //5
                            0b1111101,          //6
                            0b0000111,          //7
                            0b1111111,          //8
                            0b1101111		//9
                            };			//15
                                              

const int buttonPin = 2;  // the number of the pushbutton pin
int buttonState = 0;  // variable for reading the pushbutton status
                                              
void setup() {
  //Paso 3
  for(int i = 3; i < 10; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
  lcd_1.init();
  lcd_1.backlight();

  //Paso 5
  lightSegments(random(0,9));
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState){
    for(int i = 0; i < 40; i++){
   	num = random(0,9);
    Serial.println(num);
    lightSegments(num);
    delay(500);
    }
  lcd_1.clear();
  String ganador = "Ganador es ";
  ganador.concat(num);
  Serial.println(ganador);
  lcd_1.setCursor(0,0);
  lcd_1.print("El numero");
  lcd_1.setCursor(0,1);
  lcd_1.print(ganador);
  }
  
}

//Paso 4
void lightSegments(int number) {
  byte numberBit = numbersDisplayAnode[number];
  for (int i = 0; i < 7; i++)  {
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
  }
}