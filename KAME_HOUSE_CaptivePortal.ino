#include <WiFi.h>
#include <DNSServer.h>
#include "data.h"
const byte DNS_PORT = 53;
IPAddress apIP(8,8,4,4); // The default android DNS
DNSServer dnsServer;
WiFiServer server(80);

void setup() { 
  WiFi.mode(WIFI_AP);
  WiFi.softAP("KAME_HOUSE");
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));

  // if DNSServer is started with "*" for domain name, it will reply with
  // provided IP to all DNS request
  dnsServer.start(DNS_PORT, "*", apIP);

  server.begin();
}

void loop() {
  dnsServer.processNextRequest();
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print(responseHTML);
            //Con esta secuencia imprimo 6 botones
            for (int n=1; n<7; n++)
            {
            client.print(responseHTML1);
            client.print(n);
            client.print(responseHTML2);
            client.print(n);
            client.print(responseHTML3);
            client.print(n);
            client.print(responseHTML4);
            }
            client.print(responseHTML5);
           
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    client.stop();
  }
}
