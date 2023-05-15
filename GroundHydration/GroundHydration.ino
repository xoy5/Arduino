// ground hydration
// Wojtkowski
// 15.05.2023

int sensorValue = 0;
int i = 0;
const int pinSensor = A0;
const int pinDry = 2, pinDamp = 3, pinWet = 4, pinFlooded = 5;

void setup() {
  Serial.begin(9600);
  pinMode(pinSensor, INPUT);
  pinMode(pinDry, OUTPUT); pinMode(pinDamp, OUTPUT); pinMode(pinWet, OUTPUT);pinMode(pinFlooded, OUTPUT);
  digitalWrite(pinDry, LOW); digitalWrite(pinDamp, LOW); digitalWrite(pinWet, LOW); digitalWrite(pinFlooded, LOW);  
}

void loop() {
  sensorValue = analogRead(pinSensor);
  digitalWrite(pinDry, LOW); digitalWrite(pinDamp, LOW); digitalWrite(pinWet, LOW); digitalWrite(pinFlooded, LOW); 

  if( sensorValue < 100 )
    digitalWrite(pinDry, HIGH);
  else if( sensorValue < 300 )
    digitalWrite(pinDamp, HIGH);
  else if( sensorValue < 500 )
    digitalWrite(pinWet, HIGH);
  else if( 500 <= sensorValue )
    digitalWrite(pinFlooded, HIGH);

  Serial.println( "LVL water: " + String(sensorValue) + " Inkrementacja nr:" + String(++i) );

  delay(1000);
}
