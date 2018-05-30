// "Alarma" encender LED a determinada distancia
const int signalPin= 7;  //Señal del sensor 
const int triggerPin= 8; //Va en el pin Trig de un HC-SR04
const int LEDPin= 13; //Salida para el diodo LED
long signal, inches, centimeters;

void setup() {
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

delay(500); //El sesnor verifica la distancia a un objeto cada X tiempo

  if (inches < 4){
    digitalWrite(LEDPin, HIGH);
    delay(900);
    digitalWrite(LEDPin, LOW);
    delay(900);
  }

}