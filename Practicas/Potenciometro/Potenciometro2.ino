// Potenciometro conectado a GPIO 35
const int portPin = 35;
// Almacenamiento del valor de puerto (Rango de 0-4095)
int portValor = 0;
void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(27,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(34,OUTPUT);
}
void loop() {
  // Lectura del valor en cada vuelta del bucle
  portValor = analogRead(portPin);
  if (portValor>=0 && portValor <=512){
    digitalWrite(27,LOW);
    digitalWrite(26,LOW);
    digitalWrite(25,LOW);
    digitalWrite(33,LOW);
    digitalWrite(32,LOW);
    digitalWrite(34,LOW);
  }
  if (portValor>512 && portValor <=1024){
    digitalWrite(27,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(25,LOW);
    digitalWrite(33,LOW);
    digitalWrite(32,LOW);
    digitalWrite(34,LOW);
  }
  if (portValor>1024 && portValor <=1536){
    digitalWrite(27,HIGH);
    digitalWrite(26,HIGH);
    digitalWrite(25,LOW);
    digitalWrite(33,LOW);
    digitalWrite(32,LOW);
    digitalWrite(34,LOW);
  }
  if (portValor>1536 && portValor <=2048){
    digitalWrite(27,HIGH);
    digitalWrite(26,HIGH);
    digitalWrite(25,HIGH);
    digitalWrite(33,LOW);
    digitalWrite(32,LOW);
    digitalWrite(34,LOW);
  }
  if (portValor>2048 && portValor <=2560){
    digitalWrite(27,HIGH);
    digitalWrite(26,HIGH);
    digitalWrite(25,HIGH);
    digitalWrite(33,HIGH);
    digitalWrite(32,LOW);
    digitalWrite(34,LOW);
  }
  if (portValor>2560 && portValor <=3072){
    digitalWrite(27,HIGH);
    digitalWrite(26,HIGH);
    digitalWrite(25,HIGH);
    digitalWrite(33,HIGH);
    digitalWrite(32,HIGH);
    digitalWrite(34,LOW);
  }
  
  if (portValor>3072 && portValor <=4096){
    digitalWrite(27,HIGH);
    digitalWrite(26,HIGH);
    digitalWrite(25,HIGH);
    digitalWrite(33,HIGH);
    digitalWrite(32,HIGH);
    digitalWrite(34,HIGH);
  }
  
}
