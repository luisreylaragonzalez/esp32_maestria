// Definición de uso de los pines
const int pulsadorGPIO = 4;
const int ledPin = 2; 
bool estadoBoton =  false; 
void setup(){    
  // Activamosde los GPIO, el de entrada en modalidad PULL DOWN   
  // Si declaramos el INPUT_PULLDOWN significa ENCENDIDO, por lo tanto , 
  //conectamos un pin del pushbutton a gpio=4 y el otro pin a GND
  pinMode(pulsadorGPIO, INPUT_PULLUP);    
  pinMode(ledPin, OUTPUT);
}
 void loop() {   
   // Leemos el estado del GPIO    
  estadoBoton = digitalRead(pulsadorGPIO);   
  // Controlamos el led según el resultado  
  if (estadoBoton == HIGH) {      
       digitalWrite(ledPin, HIGH);
  }  
  else {      
       digitalWrite(ledPin, LOW); 
  }
}
