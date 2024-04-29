String num = "";
//Paso 1
const int pins[7] = { 2, 3, 4, 5, 6, 7, 8 }; 
//                    a  b  c  d  e  f  g
//Paso 2
const byte numbersDisplayAnode[16] = {0b0111111,     //0
                            0b0110000,          //1
                            0b1011011,          //2
                            0b1001111,          //3
                            0b1100110,          //4 1100110
                            0b1101101,          //5
                            0b1111101,          //6
                            0b0000111,          //7
                            0b1111111,          //8
                            0b1101111,			//9
                            0b1110111,			//10
                            0b1111111,			//11
                            0b0111001,			//12 1001110
                            0b0111111,			//13 1111110
                            0b1001111,			//14
                            0b1000111};			//15
                                              
void setup() {
  //Paso 3
  for(int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);  
  }

  //Paso 5
  lightSegments(0);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    Serial.println(num);
    switch (Serial.parseInt()) {
    case 0:
    lightSegments(0);
    break;
    case 1:
    lightSegments(1);
    break;
    case 2:
    lightSegments(2);
    break;
    case 3:
    lightSegments(3);
    break;
    case 4:
    lightSegments(4);
    break;
    case 5:
    lightSegments(5);
    break;
    case 6:
    lightSegments(6);
    break;
    case 7:
    lightSegments(7);
    break;
    case 8:
    lightSegments(8);
    break;
    case 9:
    lightSegments(9);
    break;
    case 10:
    lightSegments(10);
    break;
    case 11:
    lightSegments(11);
    break;
    case 12:
    lightSegments(12);
    break;
    case 13:
    lightSegments(13);
    break;
    case 14:
    lightSegments(14);
    break;
    case 15:
    lightSegments(15);
    break;
  }
  }
  
  
 
  //Paso 6
  //for(int i = 0; i < 16; i++) {
  //  lightSegments(i);
  //  delay(1000);
  //}
  
}

//Paso 4
void lightSegments(int number) {
  byte numberBit = numbersDisplayAnode[number];
  for (int i = 0; i < 7; i++)  {
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
  }
}