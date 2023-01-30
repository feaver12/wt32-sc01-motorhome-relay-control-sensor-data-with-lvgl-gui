#include <Arduino.h>

#define frontlightspin 2 // Pin the relay is connected to
#define centrelightspin  34 // Pin the relay is connected to
#define rearlightspin  33 // Pin the relay is connected to
#define bootlightspin 13
#define exteriorlightspin  12 // Pin the relay is connected to
#define fridgepin  32 // Pin the relay is connected to
#define tvpowerpin  27 // Pin the relay is connected to
#define greytankpin  4 // Pin the relay is connected to
#define freshtankpin 21
#define blacktankpin 14
#define flushtankpin 15
//22
//23


int greystate = 1; //reads greytank floatswitch status
int freshstate = 1; //reads greytank floatswitch status
int blackstate = 1; //reads greytank floatswitch status
int flushstate = 1; //reads greytank floatswitch status

void greytankinterrupt()
{
  greystate = digitalRead(greytankpin);
  if (greystate == HIGH) {
    Serial.println("GREY TANK LEVEL - FULL");
  }
  else {
    Serial.println("GREY TANK LEVEL - OK");
  }

}


void freshtankinterrupt()
{
  freshstate = digitalRead(freshtankpin);
  if (freshstate == HIGH) {
    Serial.println("FRESH TANK LEVEL - FULL");
  }
  else {
    Serial.println("FRESH TANK LEVEL - LOW");
  }
}

void blacktankinterrupt()
{
  blackstate = digitalRead(blacktankpin);
  if (blackstate == HIGH) {
    Serial.println("BLACK TANK LEVEL - FULL");
  }
  else {
    Serial.println("BLACK TANK LEVEL - OK");
  }
}

void flushtankinterrupt()
{
  flushstate = digitalRead(flushtankpin);
  if (flushstate == HIGH) {
    Serial.println("FLUSH TANK LEVEL - FULL");
  }
  else {
    Serial.println("FLUSH TANK LEVEL - LOW");
  }
}

void enablepinmode(void) 
{
  pinMode(2, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode (4, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(greytankpin), greytankinterrupt, CHANGE);
  pinMode (21, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(freshtankpin), freshtankinterrupt, CHANGE);
  pinMode (14, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(blacktankpin), blacktankinterrupt, CHANGE);
  pinMode (15, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(flushtankpin), flushtankinterrupt, CHANGE);
  }