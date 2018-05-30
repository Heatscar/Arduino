#include <Servo.h>
//Controlar posicion del servo mediante potenciometro
Servo servo;
const int analogPin = A0;
int value;
int position; //posicion del potenciometro

void setup(){
  servo.attach(13);
  Serial.begin(9600);
}

void loop(){
  // realizar la lectura analógica raw
  value = analogRead(analogPin);
  // convertir a porcentaje (180° = 100%)
  position = map(value, 0, 1023, 0, 180);
  Serial.println(position, DEC);
  servo.write(position);
  delay(15);
}