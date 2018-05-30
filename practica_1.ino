//Hacer parpadear un led
void setup(){
  pinMode(13, OUTPUT); //Pin de salida
}

void loop(){
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}