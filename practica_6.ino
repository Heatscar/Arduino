#include <Servo.h>
//Hacer girar servo de 0 a 180 y regresar a 0
Servo servo; // Pin

void setup(){
  // Inicializamos el servomotor
  servo.attach(13);
  // Inicializamos el serial monitor
  Serial.begin(9600);
}

void loop(){
  // Posicion
  servo.write(0);
  delay(1500);
  // Posicion
  servo.write(180);
  delay(1500);
  //Posicion
  servo.write(0);
  delay(1500);
}