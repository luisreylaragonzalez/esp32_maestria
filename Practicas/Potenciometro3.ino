// Potenciometro conectado a GPIO 35
const int portPin = 35;
// Almacenamiento del valor de puerto (Rango de 0-4095)
int potValor = 0;
int led2=2;
void setup() {
  Serial.begin(115200);
   pinMode(led2,OUTPUT);

  delay(1000);
}
void loop() {
  // Lectura del valor en cada vuelta del bucle
  potValor = analogRead(portPin);
  Serial.println(potValor);  //Envío del valor al puerto serie
  if (potValor > 2000){
        digitalWrite(led2,HIGH);
    }else {
         digitalWrite(led2,LOW);
      }
  
  delay(1000);
}
