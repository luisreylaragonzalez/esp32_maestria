
int Counter = 0;
 
void setup()
{
  Serial.begin(115200);
}
 
void loop()
{
  Serial.print("Counter Value = ");
  Serial.println(Counter++);
  delay(1000);
}
