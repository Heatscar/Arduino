//Encender 8 LED's con un potenciometro
const int analogPin = A0;
int value;
int position;

void setup(){
  //Inicializamos los pines a utilizar
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  //Conexión serial
  Serial.begin(9600);
}

void loop(){
  // realizar la lectura analógica raw
  value = analogRead(analogPin);
  // convertir a porcentaje (100%)
  position = map(value, 0, 1023, 0, 100);
  Serial.print(position, DEC);
  // Obtenemos el valor para cada led
  int val = 100 / 8;
  // Control para el encendido
  int ctr = val;
  // Recorremos los led
  for(int i = 6; i <= 13; i++){
    // verificamos el porcentaje
    if(ctr < position){
      digitalWrite(i, HIGH);
      delay(10);
      Serial.println(ctr);
    } else {
      digitalWrite(i, LOW);
      delay(10);
    }  
    // Aumentamos el control
    ctr += val;
  }
}