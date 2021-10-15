
#include <WiFi.h>
#include <esp_now.h>
void setup() {
  Serial.begin(115200); Serial.println();Serial.println();

  WiFi.mode(WIFI_STA);
  
  if (esp_now_init()==0) {
    Serial.println("Conexion ESP-NOW inicializada.");
    }

Serial.print("AP MAC: "); Serial.println(WiFi.softAPmacAddress());
Serial.print("STA MAC: "); Serial.println(WiFi.macAddress());
}
void loop() {}
