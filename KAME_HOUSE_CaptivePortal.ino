#include <WiFi.h>
#include <DNSServer.h>
#include "data.h"
#include "data1.h"

// Configuración del puerto DNS
const byte DNS_PORT = 53;

// Dirección IP del DNS predeterminado de Android
IPAddress apIP(8, 8, 4, 4);

// Objeto para manejar el servidor DNS
DNSServer dnsServer;

// Objeto para manejar el servidor WiFi
WiFiServer server(80);

// Pines de los LEDs
const int numLEDs = 7;
static unsigned short int LEDPins[numLEDs] = {2, 0, 4, 5, 18, 19, 3}; // Definir pines de los LEDs

// Variables para manejar la comunicación con el cliente
char linebuf[80]; // Búfer para almacenar caracteres recibidos
int charcount = 0; // Contador de caracteres recibidos

void setup() {
  Serial.begin(115200); // Iniciar la comunicación serial

  // Configurar pines de los LEDs como salidas
  for (int i = 0; i < numLEDs; i++) {
    pinMode(LEDPins[i], OUTPUT);
  }

  WiFi.mode(WIFI_AP); // Configurar WiFi en modo de punto de acceso
  WiFi.softAP("KAME_HOUSE"); // Establecer el nombre de la red WiFi
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0)); // Configurar la dirección IP del punto de acceso

  dnsServer.start(DNS_PORT, "*", apIP); // Iniciar el servidor DNS
  server.begin(); // Iniciar el servidor web en el puerto 80
}

// Función para procesar solicitudes de control de LED
void processLEDRequest(const char* request, int ledIndex) {
  if (strstr(linebuf, request) > 0) {
    if (strstr(request, "on") != nullptr) {
      digitalWrite(LEDPins[ledIndex], HIGH); // Encender el LED correspondiente
      Serial.printf("LED %d ON\n", ledIndex + 1); // Imprimir en la consola
    } else if (strstr(request, "off") != nullptr) {
      digitalWrite(LEDPins[ledIndex], LOW); // Apagar el LED correspondiente
      Serial.printf("LED %d OFF\n", ledIndex + 1); // Imprimir en la consola
    }
  }
}

// Función para manipular el estado de los LEDs según las solicitudes HTTP/1.1
void manipulacionLed() {
  for (int i = 1; i <= numLEDs; i++) {
    char requestOn[10];
    char requestOff[10];
    sprintf(requestOn, "GET /on%d", i);
    sprintf(requestOff, "GET /off%d", i);
    processLEDRequest(requestOn, i - 1);
    processLEDRequest(requestOff, i - 1);
  }
}

void loop() {
  dnsServer.processNextRequest(); // Procesar solicitudes DNS
  WiFiClient client = server.available(); // Verificar si hay clientes conectados al servidor web

  if (client) {
    String currentLine = "";
    boolean currentLineIsBlank = true;

    while (client.connected()) {
      if (client.available()) {
        char c = client.read(); // Leer el siguiente carácter del cliente
        Serial.write(c); // Enviar el carácter a través de la comunicación serial
        linebuf[charcount] = c; // Almacenar el carácter en el búfer

        if (charcount < sizeof(linebuf) - 1) charcount++; // Incrementar el contador de caracteres

        if (c == '\n') { // Si se recibe un salto de línea
          currentLineIsBlank = true;
          if (currentLine.length() == 0) { // Si la línea actual está en blanco
            web(client); // Llamar a la función web desde data.h
            break; // Salir del bucle
          } else {
            currentLine = "";
          }
          currentLineIsBlank = true;

          // Manipulación de los LEDs HTTP/1.1
          manipulacionLed();
          memset(linebuf, 0, sizeof(linebuf)); // Borrar el búfer
          charcount = 0; // Reiniciar el contador de caracteres
        } else if (c != '\r') {
          currentLine += c;
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    client.stop();
    Serial.println("Cliente desconectado");
  }
}
