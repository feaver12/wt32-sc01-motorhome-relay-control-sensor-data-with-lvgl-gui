#include <lvgl.h>
#include "relays.h"

  /* Toggle button event handler */
static void toggle_event_handler(lv_event_t * e)
  {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_VALUE_CHANGED)
    {
      LV_LOG_USER("Toggled1");
      Serial.println("Toggled1");
    }
  }

static void btn_onoff(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);
    lv_state_t state = lv_obj_get_state(btn);
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        if (state & LV_STATE_CHECKED) {
         turnonfrontlights();
        }
        else {
        turnofffrontlights();
        }
    }
}


static void btn2_onoff(lv_event_t * e)
{
    lv_obj_t * btn2 = lv_event_get_target(e);
    lv_state_t state = lv_obj_get_state(btn2);
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        if (state & LV_STATE_CHECKED) {
         turnoncentrelights();
        }
        else {
        turnoffcentrelights();
        }
    }
}



static void btn3_onoff(lv_event_t * e)
{
    lv_obj_t * btn3 = lv_event_get_target(e);
    lv_state_t state = lv_obj_get_state(btn3);
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        if (state & LV_STATE_CHECKED) {
         turnonrearlights();
        }
        else {
        turnoffrearlights();
        }
    }
}


static void btn4_onoff(lv_event_t * e)
{
    lv_obj_t * btn4 = lv_event_get_target(e);
    lv_state_t state = lv_obj_get_state(btn4);
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        if (state & LV_STATE_CHECKED) {
         turnonexteriorlights();
        }
        else {
        turnoffexteriorlights();
        }
    }
}



static void btn5_onoff(lv_event_t * e)
{
    lv_obj_t * btn5 = lv_event_get_target(e);
    lv_state_t state = lv_obj_get_state(btn5);
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        if (state & LV_STATE_CHECKED) {
         turnonbootlights();
        }
        else {
        turnoffbootlights();
        }
    }
}


static void btn6_onoff(lv_event_t * e)
{
    lv_obj_t * btn6 = lv_event_get_target(e);
    lv_state_t state = lv_obj_get_state(btn6);
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        if (state & LV_STATE_CHECKED) {
         turnontv();
        }
        else {
        turnofftv();
        }
    }
}

static void btn7_onoff(lv_event_t * e)
{
    lv_obj_t * btn7 = lv_event_get_target(e);
    lv_state_t state = lv_obj_get_state(btn7);
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        if (state & LV_STATE_CHECKED) {
         turnonfridge();
        }
        else {
        turnofffridge();
        }
    }
}

 