// CAR WITH ARDUINO by Kacper Wojtkowski 1TP 
// 27.05.2023
// v 2.0 (v 1.0 is peace of crap)
// COMPONENTS: 
// Arduino Uno 
// Motor Driver (L298N)
// Cables Male-Female
// 2 x Batteries 9V (For Arduino and Motor Driver) and this little shit for top 
// 2 x 65x26mm 5V motor with 48:1 gear + wires
// Front wheel of the car
// JoyStick https://github.com/SigmaKacper/Arduino/blob/main/JoyStick/JoyStick.ino
// Carton, hot glue, some cable tie and toothpick
// You can also add:
// litle board with buzzer and laser, when u press button it gonna ring and laser gonna light idk how to write English lmao 

  //     |    | 0 - 1023
  //     |    |
  //     |   \ /  y
  //     | 
  //     | =======> x  0 - 1023
  //     +-------------

// JoyStick
int SideY(const int y);
int SideX(const int x);
int IsPressed(const int prs);
const int pinX = A0;
const int pinY = A1;
const int pinPA = 7; // activator for little board
const int pinP = 8;
//-----------

// DriveModule
// LEFT 
const int pinLF = 3;
const int pinLB = 4;
// RIGHT
const int pinRF = 6;
const int pinRB = 5;

void Move(int x, int y, int pressed);
//-----------


// Main
void setup()
{
  Serial.begin( 9600 );
  pinMode(pinLF, OUTPUT); pinMode(pinLB, OUTPUT); pinMode(pinRF, OUTPUT); pinMode(pinRB, OUTPUT); // direction manip (OUTPUT)
  pinMode(pinX, INPUT); pinMode(pinY, INPUT); pinMode( pinP, INPUT); digitalWrite( pinP, HIGH ); // read joystick (INPUT)
  pinMode(pinPA, OUTPUT);
  delay(2000);
}

void loop()
{
  Move( SideX(pinX), SideY(pinY) );
  delay(200);
}
//-------

// Move
void Move(int x, int y)
{
    digitalWrite(pinLF, LOW); digitalWrite(pinLB, LOW);
    digitalWrite(pinRF, LOW); digitalWrite(pinRB, LOW);
    digitalWrite(pinPA, LOW);

  // forward && back
  if(350 < x && x < 644)
  {
    if(y < 462)
    {
      digitalWrite(pinLF, HIGH);
     digitalWrite(pinRF, HIGH);
    }
    else if(562 < y)
    {
      digitalWrite(pinLB, HIGH);
      digitalWrite(pinRB, HIGH);
    }
  }
  // left
  else if(x <= 447)
  {
    if(y <= 512)
      digitalWrite(pinRF, HIGH);
    else if(512 < y)
      digitalWrite(pinRB, HIGH);
  }

  // right
  else if(547 <= x)
  {
    if(y <= 512)
      digitalWrite(pinLF, HIGH);
    else if(512 < y)
      digitalWrite(pinLB, HIGH);
  }
  

  Serial.print( String(x) + " " + String(y));
    if(IsPressed( digitalRead( pinP ) ) ){
      Serial.println( " Tak" );
      digitalWrite(pinPA, HIGH);
    }
    else
     Serial.println( " Nie" );

}

// Functions Read JoyStick
int SideY(const int pinY)
{
  return analogRead(pinY);
}

int SideX(const int pinX)
{
  return analogRead(pinX);
}

int IsPressed(int prs)
{
  if( prs )
    return 0;
  else
    return 1;
}

//-------------------------
