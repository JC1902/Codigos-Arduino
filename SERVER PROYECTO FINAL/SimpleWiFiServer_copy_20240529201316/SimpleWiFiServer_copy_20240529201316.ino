
#define RxD2 3 
#define TxD2 1
#include <HardwareSerial.h>
#include <WiFi.h>

const char* ssid     = "red 12";
const char* password = "del1al800";
HardwareSerial SerialPort(2); // Instancia del puerto Serial2

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);        // Monitor serie
    
    pinMode(5, OUTPUT);      // set the LED pin mode

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println(WiFi.localIP());
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    
    
    server.begin();
    SerialPort.begin(9600, SERIAL_8N1, RxD2, TxD2); // Configurar Serial2 con RX y TX

}

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/HC\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/HA\">here</a> to turn the LED on pin 5 off.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /HC")) {
          digitalWrite(5, HIGH);
          SerialPort.println("1");               // GET /H turns the LED on
          
        }
        if (currentLine.endsWith("GET /HA")) {
          digitalWrite(5, LOW);  
          SerialPort.println("0");              // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}


/*



void setup() {
  
}

void loop() {
  // Enviar datos al Arduino Mega
 

  // Leer datos del Arduino Mega
  if (SerialPort.available()) {
    String dataFromArduino = SerialPort.readStringUntil('\n');
    Serial.print("Datos recibidos del Arduino Mega: ");
    Serial.println(dataFromArduino);
  }

  delay(1000); // Esperar 1 segundo
}*/
