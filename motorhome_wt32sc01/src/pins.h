#include <Arduino.h>
//#include <sht.h>
#include <power.h>
#include <stdio.h>
#include "driver/gpio.h"

#define greytankpin  4 // Pin the float switch is connected to
#define freshtankpin 13
#define blacktankpin 14
#define flushtankpin 15


bool greystatehigh = false;
bool blackstatehigh = false;
bool freshstatehigh = false;
bool flushstatehigh = false;

int greystate = 1; //reads greytank floatswitch status
int freshstate = 1; //reads greytank floatswitch status
int blackstate = 1; //reads greytank floatswitch status
int flushstate = 1; //reads greytank floatswitch status

portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR greytankinterrupt()
{  
  portENTER_CRITICAL(&mux);
  greystate = digitalRead(greytankpin);
  if (greystate == HIGH) {
    greystatehigh = true;
  }
  else {
    greystatehigh = false;
  }
  portEXIT_CRITICAL(&mux);       
}

void IRAM_ATTR blacktankinterrupt()
{  
  portENTER_CRITICAL(&mux);
  blackstate = digitalRead(blacktankpin);
  if (blackstate == HIGH) {
    blackstatehigh = true;
  }
  else {
    blackstatehigh = false;
  }
  portEXIT_CRITICAL(&mux);       
}

void IRAM_ATTR freshtankinterrupt()
{  
  portENTER_CRITICAL(&mux);
  freshstate = digitalRead(freshtankpin);
  if (freshstate == HIGH) {
    freshstatehigh = true;
  }
  else {
    freshstatehigh = false;
  }
  portEXIT_CRITICAL(&mux);       
}


void IRAM_ATTR flushtankinterrupt()
{  
  portENTER_CRITICAL(&mux);
  flushstate = digitalRead(flushtankpin);
  if (flushstate == HIGH) {
    flushstatehigh = true;
  }
  else {
    flushstatehigh = false;
  }
  portEXIT_CRITICAL(&mux);       
}


void updatecheckbox()
{
  if (greystatehigh) {
    //Serial.println("GREY TANK LEVEL - FULL");
    lv_event_send(checkbox, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_state(checkbox, LV_STATE_CHECKED);
  }
  else {
    //Serial.println("GREY TANK LEVEL - OK");
    lv_event_send(checkbox, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_clear_state(checkbox, LV_STATE_CHECKED);
  }
  
  if (blackstatehigh) {
    //Serial.println("BLACK TANK LEVEL - FULL");
    lv_event_send(checkbox2, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_state(checkbox2, LV_STATE_CHECKED);
  }
  else {
    //Serial.println("BLACK TANK LEVEL - OK");
    lv_event_send(checkbox2, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_clear_state(checkbox2, LV_STATE_CHECKED);
  }

  if (freshstatehigh) {
    //Serial.println("FRESH TANK LEVEL - OK");
    lv_event_send(checkbox3, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_state(checkbox3, LV_STATE_CHECKED);
  }
  else {
    //Serial.println("FRESH TANK LEVEL - LOW");
    lv_event_send(checkbox3, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_clear_state(checkbox3, LV_STATE_CHECKED);
  }

  if (flushstatehigh) {
    //Serial.println("FLUSH TANK LEVEL - OK");
    lv_event_send(checkbox4, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_state(checkbox4, LV_STATE_CHECKED);
  }
  else {
    //Serial.println("FLUSH TANK LEVEL - LOW");
    lv_event_send(checkbox4, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_clear_state(checkbox4, LV_STATE_CHECKED);
  }

}



void enablepinmode(void) 
{
  pinMode (greytankpin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(greytankpin), greytankinterrupt, CHANGE);
  pinMode (freshtankpin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(freshtankpin), freshtankinterrupt, CHANGE);
  pinMode (flushtankpin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(flushtankpin), flushtankinterrupt, CHANGE);
  pinMode (blacktankpin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(blacktankpin), blacktankinterrupt, CHANGE);
  }