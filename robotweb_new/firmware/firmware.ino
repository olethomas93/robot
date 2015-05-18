// Various byte codes for Sabertooth 2x5 motor
// controller using simplified serial
#define FORWARD 255-50
#define BACKWARD 128+50
#define STOP 192
#define LEFT 127
#define CENTER 64
#define RIGHT 1

// LED Pins
#define RED_LED_PIN 8
#define GREEN_LED_PIN 9
#define BLUE_LED_PIN 10

// Speaker Pin
#define SPEAKER_PIN 11
#include "pitches.h"

void setup()
{

  
  Serial.begin(9600);
  Serial1.begin(9600);
  
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}
  
void loop()
{
  char buff[4];
  if( Serial.available() >= 4 )
  { 
    Serial.readBytes( buff, 4 );
  }
  
  if( buff[0] == 'l' ) {
    analogWrite(RED_LED_PIN, buff[1]);
    analogWrite(GREEN_LED_PIN, buff[2]);
    analogWrite(BLUE_LED_PIN, buff[3]);
  }
  if( (char)buff[0] == 'r'){
    
        switch( (char)buff[1] ) {
          case 'f':
            Serial1.write( FORWARD );
            break;
          case 'l':
            Serial1.write( LEFT );
            break;
          case 'c':
            Serial1.write( CENTER );
            break;
          case 'r':
            Serial1.write( RIGHT );
            break;
          case 'b':
            Serial1.write( BACKWARD );
            break;
          case 's':
            Serial1.write( STOP );
            Serial1.write( CENTER );
            break;
        }
  }
  /*else if( buff[0] == 'l' ) {
    
        switch( buff[1] ) {
          case 'r':
            digitalWrite(RED_LED_PIN, HIGH);
            digitalWrite(BLUE_LED_PIN, LOW);
            digitalWrite(GREEN_LED_PIN, LOW);
            break;
          case 'b':
            digitalWrite(RED_LED_PIN, LOW);
            digitalWrite(BLUE_LED_PIN, HIGH);
            digitalWrite(GREEN_LED_PIN, LOW);
            break;
          case 'g':
            digitalWrite(RED_LED_PIN, LOW);
            digitalWrite(BLUE_LED_PIN, LOW);
            digitalWrite(GREEN_LED_PIN, HIGH);
            break;
          case 'y':
            digitalWrite(RED_LED_PIN, HIGH);
            digitalWrite(BLUE_LED_PIN, LOW);
            digitalWrite(GREEN_LED_PIN, HIGH);
            break;
          case 'c':
            digitalWrite(RED_LED_PIN, LOW);
            digitalWrite(BLUE_LED_PIN, HIGH);
            digitalWrite(GREEN_LED_PIN, HIGH);
            break;
          case 'p':
            digitalWrite(RED_LED_PIN, HIGH);
            digitalWrite(BLUE_LED_PIN, HIGH);
            digitalWrite(GREEN_LED_PIN, LOW);
            break;
          case 'w':
            digitalWrite(RED_LED_PIN, HIGH);
            digitalWrite(BLUE_LED_PIN, HIGH);
            digitalWrite(GREEN_LED_PIN, HIGH);
            break;
          case 'o':
            digitalWrite(RED_LED_PIN, LOW);
            digitalWrite(BLUE_LED_PIN, LOW);
            digitalWrite(GREEN_LED_PIN, LOW);
            break;
        }
    }*/
  else if( buff[0] == 'm' ) {
    
        switch( buff[1] ) {
          case 'a':
            tone(SPEAKER_PIN, NOTE_A6, 1000/4);
            break;
          case 'b':
            tone(SPEAKER_PIN, NOTE_B6, 1000/4);
            break;
          case 'c':
            tone(SPEAKER_PIN, NOTE_C6, 1000/4);
            break;
          case 'd':
            tone(SPEAKER_PIN, NOTE_D6, 1000/4);
            break;
          case 'e':
            tone(SPEAKER_PIN, NOTE_E6, 1000/4);
            break;
          case 'f':
            tone(SPEAKER_PIN, NOTE_F6, 1000/4);
            break;
          case 'g':
            tone(SPEAKER_PIN, NOTE_G6, 1000/4);
            break;
        }
    }*/
}
