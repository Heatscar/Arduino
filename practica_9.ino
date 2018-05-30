#include <Servo.h>
//Abrir puerta a determinada distancia
Servo servo; // Pin de servomotor
const int signalPin= 7;  //Señal del sensor 
const int triggerPin= 8; //Va en el pin Trig de un HC-SR04
const int LEDPin= 13; //Salida para el diodo LED
long signal, inches, centimeters;


void setup() {
    servo.attach(12);
  Serial.begin(9600); //Iniciamos conexion serial
}

void loop() {
pinMode (signalPin, INPUT);
pinMode (triggerPin, OUTPUT);
pinMode (LEDPin, OUTPUT);

//Envia el pulso detectado por el sensor
digitalWrite(triggerPin, LOW);
delayMicroseconds(2);
digitalWrite(triggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin, LOW);

signal= pulseIn(signalPin, HIGH);

//Con el sensor HR-SRO4, toma 148 microsegundos para que una señal refleje de nuevo al sensor
//Sabemos que está a una pulgada de distancia

inches= signal/148;
centimeters= inches * 2.54; //Hay 2.54cm en 1 pulgada

Serial.print(inches);
Serial.print("in, ");
Serial.print(centimeters);
Serial.print("cm");
Serial.println();

delay(500); //El sensor verifica la distancia a un objeto cada X tiempo

  if (inches < 5){
    servo.write(180);
    delay(1000);
  }
  else{
  servo.write(0);
  delay(1500);
  }
}