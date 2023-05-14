// Controllable RGB
// Wojtkowski
// 14.05.2023

// I - increment
// D - display
// pin 

const int pinIR = 2, pinIG = 3, pinIB = 4, pinIW = 5,
          pinDR = 9, pinDG = 10, pinDB = 11;

int R = 0, G = 0, B = 0;

void setup() {
  Serial.begin( 9600 );
  pinMode( pinIR, INPUT ); pinMode( pinIG, INPUT ); pinMode( pinIB, INPUT ); pinMode( pinIW, INPUT );
  digitalWrite( pinIR, HIGH ); digitalWrite( pinIG, HIGH ); digitalWrite( pinIB, HIGH ), digitalWrite( pinIW, HIGH );

  pinMode( pinDR, OUTPUT ); pinMode( pinDG, INPUT ); pinMode( pinDB, OUTPUT );
  delay(2000);
  analogWrite(pinDR, LOW);
  analogWrite(pinDG, LOW);
  analogWrite(pinDB, LOW);
}

void loop() {
  if(!digitalRead(pinIW))
  {
    R = 0; G = 0; B = 0;
    analogWrite(pinDR, LOW); analogWrite(pinDG, LOW); analogWrite(pinDB, LOW);
  }if(!digitalRead(pinIR))
  {
    if(R < 255) R += 5;
  }if(!digitalRead(pinIG))
  {
    if(G < 255) G += 5;
  }if(!digitalRead(pinIB))
  {
    if(B < 255) B += 5;
  }
  Serial.println( "R:" + String(R) + " G:" + String(G) + " B:" + String(B) );
 // analogWrite(pinIR, R);
  if(0 < R)
    analogWrite(pinDR, R);
  if(0 < G)
    analogWrite(pinDG, G);
  if(0 < B)
    analogWrite(pinDB, B);

  delay(100);
}
