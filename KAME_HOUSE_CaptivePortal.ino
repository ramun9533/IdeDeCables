#include <WiFi.h>
#include <DNSServer.h>
#include "data.h"
#include "data1.h"
const byte DNS_PORT = 53;
IPAddress apIP(8, 8, 4, 4); // The default Android DNS
DNSServer dnsServer;
WiFiServer server(80);

// Pines de los LEDs
static unsigned short int LED6 = 19;
static unsigned short int LED5 = 18;
static unsigned short int LED4 = 5;
static unsigned short int LED3 = 4;
static unsigned short int LED7 = 3;
static unsigned short int LED1 = 2;
static unsigned short int LED2 = 0;

// Variables Cliente
char linebuf[80];
int charcount = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);

  WiFi.mode(WIFI_AP);
  WiFi.softAP("KAME_HOUSE");
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));

  dnsServer.start(DNS_PORT, "*", apIP);
  server.begin();
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
            client.println();
            client.print(responseHTML);
            web(client); // Llama a la función web desde data.h
            break;
          } else {
            currentLine = "";
          }
          currentLineIsBlank = true;

          // Manipulación de los LEDs HTTP/1.1
          if (strstr(linebuf, "GET /on1") > 0) {
            Serial.println("LED 1 ON");
            digitalWrite(LED1, HIGH);
          }
          else if (strstr(linebuf, "GET /off1") > 0) {
            Serial.println("LED 1 OFF");
            digitalWrite(LED1, LOW);
          }
          else if (strstr(linebuf, "GET /on2") > 0) {
            Serial.println("LED 2 ON");
            digitalWrite(LED2, HIGH);
          }
          else if (strstr(linebuf, "GET /off2") > 0) {
            Serial.println("LED 2 OFF");
            digitalWrite(LED2, LOW);
          }
          // Manipulación de los LEDs HTTP/1.1
          if (strstr(linebuf, "GET /on3") > 0) {
            Serial.println("LED 3 ON");
            digitalWrite(LED3, HIGH);
          }
          else if (strstr(linebuf, "GET /off3") > 0) {
            Serial.println("LED 3 OFF");
            digitalWrite(LED3, LOW);
          }
          else if (strstr(linebuf, "GET /on4") > 0) {
            Serial.println("LED 4 ON");
            digitalWrite(LED4, HIGH);
          }
          else if (strstr(linebuf, "GET /off4") > 0) {
            Serial.println("LED 4 OFF");
            digitalWrite(LED4, LOW);
          }
          // Manipulación de los LEDs HTTP/1.1
          if (strstr(linebuf, "GET /on5") > 0) {
            Serial.println("LED 5 ON");
            digitalWrite(LED5, HIGH);
          }
          else if (strstr(linebuf, "GET /off5") > 0) {
            Serial.println("LED 5 OFF");
            digitalWrite(LED5, LOW);
          }
          else if (strstr(linebuf, "GET /on6") > 0) {
            Serial.println("LED 6 ON");
            digitalWrite(LED6, HIGH);
          }
          else if (strstr(linebuf, "GET /off6") > 0) {
            Serial.println("LED 6 OFF");
            digitalWrite(LED6, LOW);
          }
          // Repite para otros LEDs, como LED3, LED4, etc.
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
