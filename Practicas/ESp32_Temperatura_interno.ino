
#include <Arduino.h>
#include <FunctionalInterrupt.h>

 #ifdef __cplusplus
  extern "C" {
 #endif

  uint8_t temprature_sens_read();

#ifdef __cplusplus
}
#endif

uint8_t temprature_sens_read();

int lect_touch;
int led =2;
void setup() {
  Serial.begin(115200); 
    pinMode(led, OUTPUT);

}

void loop() {
 lect_touch=touchRead(T0);
 Serial.println(lect_touch);
 Serial.println((temprature_sens_read()-32)/1.8);
 if (lect_touch<90)
 {
    digitalWrite(led, HIGH);
  }else if (lect_touch>90) 
  {
    digitalWrite(led, LOW);
    }
 delay(100);
}
