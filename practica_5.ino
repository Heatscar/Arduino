#include <Servo.h>
//Girar un servo a 90, 180 grados y regresar a 0
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
  delay(1000);
  // Posicion
  servo.write(90);
  delay(1000);
  //Posicion
  servo.write(180);
  delay(1000);
}