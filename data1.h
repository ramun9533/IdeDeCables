//Toma un parámetro de tipo referencia a "WiFiClient", es decir "WiFiClient &client".
// El "&" en "WiFiClient" & indica que "client" es una referencia al objeto "WiFiClient". 
// asi ya no se tiene que hacer un nuevo objeto .
// En otras palabras, la función puede modificar el objeto original y los cambios se 
// reflejarán fuera de la función.
void web(WiFiClient &client){
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
  }
