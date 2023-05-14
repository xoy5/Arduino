// Arduino && 5161AS
// Wojtkowski Kacper ^^
// 14.05.2023 

/*    Jak to dziala :
-----Nie uzywam kropki-----

          2 - t
          ______
        |        |
7 - l1  |        |  3 - p1
        | 8 - m  |
          ______
        |        |
6 - l2  |        | 4 - p2
        |        |
          ______

          5 - b
*/

enum class Tcyfra
{
  zero,
  jeden,
  dwa,
  trzy,
  cztery,
  piec,
  szesc, 
  siedem,
  osiem,
  dziewiec	
};

short t = 2,
 p1 = 3, p2 = 4,
 b = 5,
 l1 = 7, l2 = 6,
 m = 8;

short i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(t, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(m, OUTPUT);
}

void loop() {
  digitalWrite(t, LOW);
  for(short j = t; j <= m; j++)
    digitalWrite(j, LOW);

  Tcyfra numer = static_cast<Tcyfra>(i);
  switch(numer)
  {

    // 0
    case Tcyfra::zero:
      Serial.println("zero");
      for(int j = t; j <= l1; j++)
        digitalWrite(j, HIGH);
    break;

    // 1
    case Tcyfra::jeden:
      Serial.println("jeden");

      digitalWrite(p1, HIGH);
      digitalWrite(p2, HIGH);
    break;

    // 2
    case Tcyfra::dwa:
      Serial.println("dwa");

      digitalWrite(t, HIGH);
      digitalWrite(p1, HIGH);
      digitalWrite(m, HIGH);
      digitalWrite(l2, HIGH);
      digitalWrite(b, HIGH);
    break;
      
    // 3
    case Tcyfra::trzy:
      Serial.println("trzy");

      digitalWrite(t, HIGH);  
      digitalWrite(p1, HIGH);
      digitalWrite(m, HIGH);
      digitalWrite(p2, HIGH);
      digitalWrite(b, HIGH);
    break;

    // 4
    case Tcyfra::cztery:
      Serial.println("cztery");

      digitalWrite(l1, HIGH);
      digitalWrite(p1, HIGH);
      digitalWrite(m, HIGH);
      digitalWrite(p2, HIGH);
    break;

    // 5
    case Tcyfra::piec:
      Serial.println("piec");

      digitalWrite(t, HIGH);
      digitalWrite(l1, HIGH);
      digitalWrite(m, HIGH);
      digitalWrite(p2, HIGH);
      digitalWrite(b, HIGH);
    break;

    // 6
    case Tcyfra::szesc:
      Serial.println("szesc");

      digitalWrite(t, HIGH);
      digitalWrite(l1, HIGH);
      digitalWrite(m, HIGH);
      digitalWrite(l2, HIGH);
      digitalWrite(p2, HIGH);
      digitalWrite(b, HIGH);
    break;

    // 7
    case Tcyfra::siedem:
      Serial.println("siedem");

      digitalWrite(t, HIGH);
      digitalWrite(p1, HIGH);
      digitalWrite(p2, HIGH);
    break;

    // 8
    case Tcyfra::osiem:
      Serial.println("osiem");

      for(int j = t; j <= m; j++)
        digitalWrite(j, HIGH);
    break;

    // 9  
    case Tcyfra::dziewiec:
      Serial.println("dziewiec");

      digitalWrite(t, HIGH);
      digitalWrite(l1, HIGH);
      digitalWrite(p1, HIGH);
      digitalWrite(m, HIGH);
      digitalWrite(p2, HIGH);
      digitalWrite(b, HIGH);
    break;

  }

  if(i >= 9)
    i = 0;
  else
    i++;

  delay(1000); // opóźnienie o 1 sekundę
}