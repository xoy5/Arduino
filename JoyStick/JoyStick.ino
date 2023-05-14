// Controler 
// Wojtkowski
// 14.04.2023

int SideY(int y);
int SideX(int x);
int IsPressed(int prs);

const int 
 pinX = 0, pinY = 1,
 pinSW = 2; 

void setup() {
  Serial.begin( 9600 );
  pinMode( pinSW, INPUT);
  digitalWrite( pinSW, HIGH );
}

void loop() {
  /*
  Serial.print("Switch: ");
  Serial.print(digitalRead(pinSW));
  Serial.print(" X:");
  Serial.print(analogRead(pinX));
  Serial.print(" Y:");
  Serial.print(analogRead(pinY));
  Serial.print("\n");
  */

  // RUCH
  if( !SideX( analogRead( pinX ) ) )
    Serial.print( "W MIEJSCU" );

  else if( SideX( analogRead( pinX ) ) == 1 )
    Serial.print( "PRAWO X: " + String( analogRead( pinX ) ) );

  else if( SideX( analogRead( pinX ) ) == -1 )
    Serial.print( "LEWO X: " + String( analogRead( pinX ) ) );

  if( !SideY( analogRead( pinY ) ) )
    Serial.print(" | W MIEJSCU");
  else if( SideY( analogRead( pinY ) ) == -1)
    Serial.print( " | GORA Y: " + String( analogRead( pinY ) ) );
  else if( SideY(analogRead( pinY ) ) == 1)
    Serial.print( " | DOL Y: " + String( analogRead( pinY ) ) );

  // Nacisniety ?
  Serial.print(" | Nasniety: \"" );

  if(IsPressed( digitalRead( pinSW ) ) )
    Serial.println( "Tak\"" );
  else
    Serial.println( "Nie\"" );
  
  delay(100);
}


int SideX(int x)
{
  if(x < 497)
    return -1;
  else if(497 < x)
    return 1;

  return 0;
}
int SideY(int y)
{
  if( y < 512 )
    return -1;
  else if( 512 < y )
    return 1;

  return 0;
}

int IsPressed(int prs)
{
  if( prs )
    return 0;
  else
    return 1;
}
