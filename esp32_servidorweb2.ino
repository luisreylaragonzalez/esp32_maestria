
// Enciende y apaga LED. Botones.

#include <WiFi.h>
const char* ssid = "Estoicos";
const char* password = "*Andromeda_$23";

WiFiServer server(80);

#define LED2  2    // LED en terminal 2
String estado = "";

void setup() {
  Serial.begin(115200);
  pinMode(LED2, OUTPUT);

// Conecta a la red wifi.
  Serial.println();
  Serial.print("Conectando con ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado con WiFi.");
 
  // Inicio del Servidor web.
  server.begin();
  Serial.println("Servidor web iniciado.");
 
  // Esta es la IP
  Serial.print("Esta es la IP para conectar: ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  // Consulta si se ha conectado algún cliente.
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
   
  Serial.print("Nuevo cliente: ");
  Serial.println(client.remoteIP());
   
  // Espera hasta que el cliente envíe datos.
  // while(!client.available()){ delay(1); }

  /////////////////////////////////////////////////////
  // Lee la información enviada por el cliente.
  String req = client.readStringUntil('\r');
  Serial.println(req);

  // Realiza la petición del cliente.
       if (req.indexOf("on2") != -1) {digitalWrite(LED2, HIGH); estado = "Encendido";}
       if (req.indexOf("off2") != -1){digitalWrite(LED2, LOW); estado = "Apagado";}

  //////////////////////////////////////////////
  // Página WEB. ////////////////////////////
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  Importante.
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><meta charset=utf-8></head>");
  client.println("<body><center><font face='Arial'>");
  client.println("<h1>Servidor web con ESP32.</h1>");

  client.println("<h3>Página web.</h3>");
  client.println("<br><br>");

  client.println("<a href='on2'><button>Enciende LED2</button></a>");
  client.println("<a href='off2'><button>Apaga LED2</button></a>"); 
  client.println("<br><br>");
  client.println(estado);
  client.println("</font></center></body></html>");

  Serial.print("Cliente desconectado: ");
  Serial.println(client.remoteIP());
  client.flush();
  client.stop();
}
