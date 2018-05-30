//Contador decimal a binario con push button
const int inPin = 5;
int value; //variable que almacena la lectura analógica raw
int count=0;

void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  
  // Inicializamos la conexion serial
  Serial.begin(9600);
}

void loop(){
  // Leemos el valor
  value = digitalRead(inPin);
  if(value == HIGH){
  	digitalWrite(count, HIGH);
    count++;
    Serial.println(count);
  } else {
    digitalWrite(count, LOW);
  }
  // convertir a porcentaje
  toBinary(count); // Binario a transformar
  //delay(1000);
}

void toBinary(int n){
  // verificamos que el numero sea mayor a 0
  if(n < 0) return;
  int count;
  
  // Recorremos de abajo a arriba
  for(int i = 13; i >= 6; i--){
    count = n % 2;
    // Actualizamos el numero
    n /= 2;
    
    if(count == 1){
    	digitalWrite(i, HIGH);
  		delay(10);
    } else {
  		digitalWrite(i, LOW);
  		delay(10);
    }
  }
}