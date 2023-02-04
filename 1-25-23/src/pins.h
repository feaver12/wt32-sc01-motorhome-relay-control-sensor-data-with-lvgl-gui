#include <Arduino.h>
//#include <mcp.h>


#define greytankpin  4 // Pin the relay is connected to
#define freshtankpin 21
#define blacktankpin 14
#define flushtankpin 15
//12//22
//13//23
//14
//15


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
  pinMode (4, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(greytankpin), greytankinterrupt, CHANGE);
  pinMode (freshtankpin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(freshtankpin), freshtankinterrupt, CHANGE);
  pinMode (flushtankpin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(blacktankpin), blacktankinterrupt, CHANGE);
  pinMode (blacktankpin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(flushtankpin), flushtankinterrupt, CHANGE);
  }