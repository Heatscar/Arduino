//Encender 8 LED's de ida y vuelta
const int SPEED = 200;
const int OFF = 50;

void setup(){
  // Inicializamos los pines
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
  // Recorremos de arriba a abajo
  for(int i = 13; i > 6; i--){
    digitalWrite(i, HIGH);
  	delay(SPEED);
  	digitalWrite(i, LOW);
  	delay(OFF);
  }
  
  // Recorremos de abajo a arriba
  for(int i = 6; i < 13; i++){
    digitalWrite(i, HIGH);
  	delay(SPEED);
  	digitalWrite(i, LOW);
  	delay(OFF);
  }
}