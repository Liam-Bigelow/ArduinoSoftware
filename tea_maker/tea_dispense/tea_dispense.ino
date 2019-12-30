
/*
 * UNFINISHED
 */

#include <Servo.h>

/* USED FOR THE SERVO's */
int servoPin0 = 10;
int servoPin1 = 9;
int servoPin2 = 8;
Servo servo0;
Servo servo1;
Servo servo2;
int servoAngle0 = 0;   // servo position in degrees
int servoAngle1 = 0;   // servo position in degrees
int servoAngle2 = 0;   // servo position in degrees

/* FOR RELAY */
int heatPin =  30;
int pumpPin = 32;

/* FOR 7 SEGMENT DISPLAY LEFT*/
int a0 = 48;  //For displaying segment "a"
int b0 = 49;  //For displaying segment "b"
int c0 = 53;  //For displaying segment "c"
int d0 = 52;  //For displaying segment "d"
int e0 = 50;  //For displaying segment "e"
int f0 = 51;  //For displaying segment "f"
int g0 = 46;  //For displaying segment "g"

/* FOR 7 SEGMENT DISPLAY LEFT*/
int a1 = 41;  //For displaying segment "a"
int b1 = 43;  //For displaying segment "b"
int c1 = 42;  //For displaying segment "c"
int d1 = 40;  //For displaying segment "d"
int e1 = 38;  //For displaying segment "e"
int f1 = 39;  //For displaying segment "f"
int g1 = 44;  //For displaying segment "g"

/* FOR RGB DISPLAY */
int GREEN = 13;
int BLUE = 11;
int RED = 12;

/* FOR BUTTONS USED */
int UpButton = 6;
int DownButton = 7;
int SelectButton = 5;

/* USED TO STATE WHICH STAGE THE PROGRAM IS ON */
int StageSelection = 0;

void setup()
{
  Serial.begin(9600);
  /* MAKE SURE ALL RELAY'S ARE SHUT OFF */
  pinMode( pumpPin, OUTPUT );
  pinMode( heatPin, OUTPUT );
  digitalWrite( pumpPin, LOW );
  digitalWrite( heatPin, LOW );

  /* SERVO FOR MEASURING TEA */
  servo0.attach(servoPin0);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  delay(1000);

  /* SEVEN SEGMENT DISPLAY LEFT*/
  pinMode(a0, OUTPUT);  //A
  pinMode(b0, OUTPUT);  //B
  pinMode(c0, OUTPUT);  //C
  pinMode(d0, OUTPUT);  //D
  pinMode(e0, OUTPUT);  //E
  pinMode(f0, OUTPUT);  //F
  pinMode(g0, OUTPUT);  //G

  /* SEVEN SEGMENT DISPLAY RIGHT*/
  pinMode(a1, OUTPUT);  //A
  pinMode(b1, OUTPUT);  //B
  pinMode(c1, OUTPUT);  //C
  pinMode(d1, OUTPUT);  //D
  pinMode(e1, OUTPUT);  //E
  pinMode(f1, OUTPUT);  //F
  pinMode(g1, OUTPUT);  //G

  /* RGB LED (TEA, SCOOPS, TIME) */
  pinMode(RED, OUTPUT);  //RED
  pinMode(BLUE, OUTPUT);  //BLUE
  pinMode(GREEN, OUTPUT);  //GREEN

  /* BUTTONS */
  pinMode( UpButton, INPUT);
  pinMode( DownButton, INPUT);
  pinMode( SelectButton, INPUT);

  /* JUST SOMETHINGS TO SHOW ITS READY TO USE */
  rgbDisplay( "GREEN" );
  delay( 500 );
  for (int i = 0; i < 10 ; i++) {
    digitDisplay0(i);
    digitDisplay1(i);
    delay(250);
    turnOffDisplay( 0 );
    turnOffDisplay( 1 );
  }
  rgbDisplay( "WHITE");
  delay( 250 );
  rgbDisplay( "GREEN" );
}

void turnOnDisplay( int WhichOne ){
    if ( WhichOne == 0 ) {
    digitalWrite(a0, HIGH);
    digitalWrite(b0, HIGH);
    digitalWrite(c0, HIGH);
    digitalWrite(d0, HIGH);
    digitalWrite(e0, HIGH);
    digitalWrite(f0, HIGH);
    digitalWrite(g0, HIGH);
  } else {
    digitalWrite(a1, HIGH);
    digitalWrite(b1, HIGH);
    digitalWrite(c1, HIGH);
    digitalWrite(d1, HIGH);
    digitalWrite(e1, HIGH);
    digitalWrite(f1, HIGH);
    digitalWrite(g1, HIGH);
  }
}

void turnOffDisplay( int WhichOne ) {
  if ( WhichOne == 0 ) {
    digitalWrite(a0, LOW);
    digitalWrite(b0, LOW);
    digitalWrite(c0, LOW);
    digitalWrite(d0, LOW);
    digitalWrite(e0, LOW);
    digitalWrite(f0, LOW);
    digitalWrite(g0, LOW);
  } else {
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(c1, LOW);
    digitalWrite(d1, LOW);
    digitalWrite(e1, LOW);
    digitalWrite(f1, LOW);
    digitalWrite(g1, LOW);
  }
}

/* THIS IS USED FOR SELECTION ( LEFT ) */
void digitDisplay0(int digit) {

  turnOffDisplay( 0 );

  //Conditions for displaying segment a
  if ( digit != 1 && digit != 4 ) {
    digitalWrite(a0, HIGH);
  }

  //Conditions for displaying segment b
  if (digit != 5 && digit != 6) {
    digitalWrite(b0, HIGH);
  }

  //Conditions for displaying segment c
  if (digit != 2) {
    digitalWrite(c0, HIGH);
  }

  //Conditions for displaying segment d
  if (digit != 1 && digit != 4 && digit != 7) {
    digitalWrite(d0, HIGH);
  }

  //Conditions for displaying segment e
  if (digit == 2 || digit == 6 || digit == 8 || digit == 0) {
    digitalWrite(e0, HIGH);
  }

  //Conditions for displaying segment f
  if (digit != 1 && digit != 2 && digit != 3 && digit != 7) {
    digitalWrite(f0, HIGH);
  }

  if (digit != 0 && digit != 1 && digit != 7) {
    digitalWrite(g0, HIGH);
  }

}

/* THIS IS USED FOR STAGE FEEDBACK ( RIGHT ) */
void digitDisplay1(int digit) {

  turnOffDisplay( 1 );

  //Conditions for displaying segment a
  if ( digit != 1 && digit != 4 ) {
    digitalWrite(a1, HIGH);
  }

  //Conditions for displaying segment b
  if (digit != 5 && digit != 6) {
    digitalWrite(b1, HIGH);
  }

  //Conditions for displaying segment c
  if (digit != 2) {
    digitalWrite(c1, HIGH);
  }

  //Conditions for displaying segment d
  if (digit != 1 && digit != 4 && digit != 7) {
    digitalWrite(d1, HIGH);
  }

  //Conditions for displaying segment e
  if (digit == 2 || digit == 6 || digit == 8 || digit == 0) {
    digitalWrite(e1, HIGH);
  }

  //Conditions for displaying segment f
  if (digit != 1 && digit != 2 && digit != 3 && digit != 7) {
    digitalWrite(f1, HIGH);
  }

  if (digit != 0 && digit != 1 && digit != 7) {
    digitalWrite(g1, HIGH);
  }

}

void rgbDisplay( String colour ) {
  if ( colour.equals( "RED" ) ) {
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
  }
  if ( colour.equals( "YELLOW" ) ) {
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, HIGH);
  }
  if ( colour.equals( "BLUE" ) ) {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  }
  if ( colour.equals( "CYAN" ) ) {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
  }
  if ( colour.equals( "MAGENTA" ) ) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  }
  if ( colour.equals( "GREEN" ) ) {
    digitalWrite(RED, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, HIGH);
  }
  if ( colour.equals( "WHITE" ) ) {
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, HIGH);
  }
  if ( colour.equals( "OFF" ) ) {
    digitalWrite(RED, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
  }
}


int getNumber( int Cap ) {

  int CurrentDigit = 1;
  digitDisplay0( CurrentDigit );
  digitDisplay1( StageSelection );

  while ( true ) {

    Serial.println( CurrentDigit );

    delay( 250 );
    if ( digitalRead( UpButton ) == HIGH ) {
      if ( CurrentDigit >= Cap ) {
        if ( CurrentDigit == Cap ) {
          digitDisplay0( CurrentDigit );
        }
        continue;
      } else {
        CurrentDigit++;
        digitDisplay0( CurrentDigit );
      }
    } else if ( digitalRead( DownButton ) == HIGH ) {
      if ( CurrentDigit <= 0) {
        if ( CurrentDigit == 0) {
          digitDisplay0( CurrentDigit );
        }
        continue;
      } else {
        CurrentDigit--;
        digitDisplay0( CurrentDigit );
      }
    } else if ( digitalRead( SelectButton ) == HIGH) {
      break;
    }
  }
  return CurrentDigit;
}



double getSteepTime( void ) {

  double TimeSelect = 0;

  // Get the minutes
  rgbDisplay( "MAGENTA" );
  TimeSelect += ( getNumber( 9 ) * 60 );
  delay(500);

  // Get 10 seconds place
  rgbDisplay( "BLUE" );
  TimeSelect += ( getNumber( 9 ) * 10 );
  delay(500);

  // get seconds place
  rgbDisplay( "CYAN" );
  TimeSelect += getNumber( 9 );

  delay(1000);
  rgbDisplay( "WHITE" );

  return TimeSelect;
}

void pumpWater() {
  // this is used to pump one cup of water
  digitalWrite( pumpPin, HIGH );
  delay(5000);
  digitalWrite( pumpPin, LOW );
}

void dispenseSelectedTea( int Scoops, int Tea ) {
  if ( Tea <= 1 ) {
    for ( int i = 0; i <= Scoops; i++) {

      for (servoAngle0 = 0; servoAngle0 < 180; servoAngle0++) //move the micro servo from 0 degrees to 180 degrees
      {
        servo0.write(servoAngle0);
        delay(4);
      }

      delay(1000);

      for (servoAngle0 = 180; servoAngle0 > 0; servoAngle0--) //now move back the micro servo from 0 degrees to 180 degrees
      {
        servo0.write(servoAngle0);
        delay(2);
      }

      servo0.write(90);
    }
  } else if ( Tea == 2 ) {
    for ( int i = 0; i <= Scoops; i++) {

      for (servoAngle1 = 0; servoAngle1 < 180; servoAngle1++) //move the micro servo from 0 degrees to 180 degrees
      {
        servo1.write(servoAngle1);
        delay(4);
      }

      delay(1000);

      for (servoAngle1 = 180; servoAngle1 > 0; servoAngle1--) //now move back the micro servo from 0 degrees to 180 degrees
      {
        servo1.write(servoAngle1);
        delay(2);
      }

      servo1.write(90);
    }
  } else if ( Tea >= 3 ) {
    for ( int i = 0; i <= Scoops; i++) {

      for (servoAngle2 = 0; servoAngle2 < 180; servoAngle2++) //move the micro servo from 0 degrees to 180 degrees
      {
        servo2.write(servoAngle2);
        delay(4);
      }

      delay(1000);

      for (servoAngle2 = 180; servoAngle2 > 0; servoAngle2--) //now move back the micro servo from 0 degrees to 180 degrees
      {
        servo2.write(servoAngle2);
        delay(2);
      }

      servo2.write(90);
    }
  }
}

void RunProgram( void ) {
  /* FIRST STEP WILL BE SELECTING TEA */
  int teaSelected = getNumber( 3 );
  digitDisplay1( ++StageSelection );
  /* SECOND STEP WILL BE SELECTING NUMBER OF SCOOPS */
  int numScoops = getNumber( 9 );
  digitDisplay1( ++StageSelection );
  /* THRID STEP WILL BE SELECTING DISPENSING TEA */
  dispenseSelectedTea( numScoops, teaSelected );


  // RESET PROGRAM DEFAULTS
  StageSelection = 0;
  digitDisplay0(0);
  digitDisplay1(0);
}

void test_BoilAndPump( void ){
  digitalWrite( pumpPin, HIGH );
  delay( 1000 );

  // now turn on the heater
  digitalWrite( heatPin, HIGH );
  delay( 3000 );

  digitalWrite( pumpPin, LOW );
  digitalWrite( heatPin, LOW );
}

void loop()
{
  // turnOnDisplay( 0 );
  // turnOnDisplay( 1 );
  // RunProgram();
  // pumpWater();
  // delay( 2000 );

  test_BoilAndPump();
  delay( 10000 );
}
