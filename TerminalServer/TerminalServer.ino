#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "red 12";
const char* password = "del1al800";

WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi conectado");

  server.on("/", HTTP_GET, handleRoot);  // Manejador para la página principal
  server.on("/send", HTTP_GET, handleSend);  // Manejador para enviar datos

  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void handleRoot() {
  String html = "<!DOCTYPE html>"
                "<html lang='es'>"
                "<head>"
                "<meta charset='UTF-8'><title>Control ESP32</title>"
                "</head>"
                "<body>"
                "<h1>Control de ESP32 desde Web</h1>"
                "<form action='/send' method='get'>"
                "<p>Introduce una cadena para enviar al ESP32:</p>"
                "<textarea name='cadena'></textarea><br>"
                "<input type='submit' value='Enviar'>"
                "</form>"
                "</body>"
                "</html>";
  server.send(200, "text/html", html);
}

void handleSend() {
  if (server.hasArg("cadena")) {
    String cadena = server.arg("cadena");
    Serial.println("Recibido: " + cadena);
  }
  server.sendHeader("Location", "/", true); // Redirección al inicio
  server.send(302, "text/plain", ""); // Respuesta de redirección
}

void loop() {
  server.handleClient();
}