//Encender "ventilador" a determinada temperatura
float tempC;
int reading;
int tempPin = 0;


void setup(){
  pinMode(13, OUTPUT);
  analogReference(INTERNAL);
  Serial.begin(9600);
}

void loop(){
  reading = analogRead(tempPin);
  tempC = reading / 9.31;
  Serial.print("Tempratura = ");
  Serial.print(tempC);
  Serial.print("°C");
  Serial.println();
    if(tempC > 25){
      digitalWrite(13, HIGH);
      delay(1000);
    }
 	 else{
    digitalWrite(13, LOW);
    delay(1000);
    }
  delay(1000);
}