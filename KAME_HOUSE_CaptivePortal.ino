#include <WiFi.h>
#include <DNSServer.h>
#include "data.h"
#include "data1.h"
const byte DNS_PORT = 53;
IPAddress apIP(8,8,4,4); // The default android DNS
DNSServer dnsServer;
WiFiServer server(80);
// static unsigned int
static unsigned short int LED5 = 19;// aprobado *
static unsigned short int LED4 = 18;// aprobado *
static unsigned short int LED3 = 5;// aprobado *
static unsigned short int LED2 = 4;// aprobado *
static unsigned short int LED1 = 15;// Aqui hay duda *
//Variables Cliente
char linebuf[80];
int charcount = 0;

void setup() { 
  WiFi.mode(WIFI_AP);
  WiFi.softAP("KAME_HOUSE");
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
   // Intentamos que se conecte a la red wifi
  // while (WiFi.status() != WL_CONNECTED) {
   // Serial.println("Conectando...");
   // delay(2000);
  // }

  // if DNSServer is started with "*" for domain name, it will reply with
  // provided IP to all DNS request
  dnsServer.start(DNS_PORT, "*", apIP);

  server.begin();
}

void loop() {
  /* dnsServer.processNextRequest();: Esta línea se refiere a la ejecución
  de la función processNextRequest() del objeto dnsServer, que es del tipo 
  DNSServer. Esta función se encarga de procesar las solicitudes de DNS entrantes. 
  El servidor DNS se utiliza para traducir nombres de dominio a direcciones IP.
  */
  dnsServer.processNextRequest();
  /*WiFiClient client = server.available();: Aquí se declara una variable llamada 
  client de tipo WiFiClient y se inicializa con el resultado de la función available() 
  del objeto server, que es del tipo WiFiServer. La función available() comprueba si hay 
  clientes nuevos conectados al servidor y devuelve un objeto WiFiClient que representa 
  la conexión con el cliente, si hay alguno.*/
  WiFiClient client = server.available();   // listen for incoming clients
/*if (client) {: Esta línea verifica si la variable client es válida y si representa una 
conexión establecida con un cliente. Si client es válido, significa que hay un cliente 
conectado y el código dentro del bloque if se ejecutará.*/
  if (client) {
    /*String currentLine = "";: Se declara una variable llamada currentLine de tipo String
    e inicializa con una cadena vacía. Esta variable se utiliza para almacenar las líneas 
    de datos que se reciben del cliente.*/
    String currentLine = "";
    /*while (client.connected()) {: Se inicia un bucle while que se ejecutará mientras la 
    conexión con el cliente esté establecida. Esto permite leer los datos enviados por el 
    cliente en un bucle hasta que la conexión se cierre.*/
    while (client.connected()) {
      /*if (client.available()) {: Esta línea comprueba si hay datos disponibles para 
      leer desde el cliente. Si el cliente ha enviado datos, el código dentro del bloque 
      if se ejecutará.*/
      if (client.available()) {
        /*char c = client.read();: Aquí se lee un carácter del cliente y se almacena
        en la variable c. client.read() devuelve el siguiente byte disponible en el búfer 
        del cliente.*/
        char c = client.read();
        /*if (c == '\n') {: Esta línea verifica si el carácter leído es un salto de línea 
        ('\n'). Los navegadores web suelen enviar las peticiones HTTP seguidas de una línea 
        en blanco que termina con un salto de línea.*/
        if (c == '\n') {
          /*if (currentLine.length() == 0) {: Esta línea verifica si currentLine está vacío, 
          es decir, si es una línea en blanco. Esto significa que se ha recibido una línea en 
          blanco después de la primera línea de la petición HTTP, lo que indica el final de la 
          petición.*/
          if (currentLine.length() == 0) {
            /*client.println("HTTP/1.1 200 OK");: Aquí se envía una respuesta HTTP al cliente 
            con un código de estado 200 OK, lo que indica que la solicitud ha sido procesada 
            con éxito.*/
            client.println("HTTP/1.1 200 OK");
            

/*client.println("Content-type:text/html"); 
: Se envía una cabecera HTTP para indicar que el tipo de contenido de la respuesta es texto/html. 
Esto es importante para que el navegador interprete correctamente la respuesta.
*/
            client.println("Content-type:text/html");
            /*client.println();: Se envía una línea en blanco para indicar el final de las 
            cabeceras HTTP y el comienzo del cuerpo de la respuesta.*/
            client.println();
            // Imprime la primera parte de la pagina web
            // DEclarada en el rachivo "data.h"
            client.print(responseHTML);
            //Con esta funcion imprimo 6 botones, la funciona 
            // es declarada en el archivo "data1.h"
            //Se le pasa el parametro "client" del objetos "WiFiClient"
           web(client);
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
