#include <WiFi.h>
#include <WiFiUdp.h>
// WiFi details
const char *ssid     = "ADM/PTC";
const char *password = "";

void WiFi_Setup(){

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected!");
}

void DatosWIFI(){
  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("ESP Mac Address: ");
  Serial.println(WiFi.macAddress());
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("DNS: ");
  Serial.println(WiFi.dnsIP());
  }

void setup(){
  Serial.begin(115200);
  WiFi_Setup();
  DatosWIFI();
}

void loop() {
 
}
