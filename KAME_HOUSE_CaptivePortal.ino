#include <WiFi.h>
#include <DNSServer.h>
#include "data.h"
#include "data1.h"
const byte DNS_PORT = 53;
IPAddress apIP(8, 8, 4, 4); // The default Android DNS
DNSServer dnsServer;
WiFiServer server(80);

// Pines de los LEDs
const int numLEDs = 7;
static unsigned short int LEDPins[numLEDs] = {2, 0, 4, 5, 18, 19, 3};  // Actualiza los pines de acuerdo a tu configuración

// Variables Cliente
char linebuf[80];
int charcount = 0;

void setup() {
  Serial.begin(115200);
  
  for (int i = 0; i < numLEDs; i++) {
    pinMode(LEDPins[i], OUTPUT);
  }

  WiFi.mode(WIFI_AP);
  WiFi.softAP("KAME_HOUSE");
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));

  dnsServer.start(DNS_PORT, "*", apIP);
  server.begin();
}

void processLEDRequest(const char* request, int ledIndex) {
  if (strstr(linebuf, request) > 0) {
    if (strstr(request, "on") != nullptr) {
      digitalWrite(LEDPins[ledIndex], HIGH);
      Serial.printf("LED %d ON\n", ledIndex + 1);
    } else if (strstr(request, "off") != nullptr) {
      digitalWrite(LEDPins[ledIndex], LOW);
      Serial.printf("LED %d OFF\n", ledIndex + 1);
    }
  }
}

void loop() {
  dnsServer.processNextRequest();
  WiFiClient client = server.available();

  if (client) {
    String currentLine = "";
    boolean currentLineIsBlank = true;
    
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        linebuf[charcount] = c;
        
        if (charcount < sizeof(linebuf) - 1) charcount++;

        if (c == '\n') {
          currentLineIsBlank = true;
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client. println();
           // cliente.print(responseHTML);
            web(client); // Llama a la función web desde data.h
            break;
          } else {
            currentLine = "";
          }
          currentLineIsBlank = true;

          // Manipulación de los LEDs HTTP/1.1
          for (int i = 1; i <= numLEDs; i++) {
            char requestOn[10];
            char requestOff[10];
            sprintf(requestOn, "GET /on%d", i);
            sprintf(requestOff, "GET /off%d", i);
            processLEDRequest(requestOn, i - 1);
            processLEDRequest(requestOff, i - 1);
          }

          memset(linebuf, 0, sizeof(linebuf));
          charcount = 0;
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
