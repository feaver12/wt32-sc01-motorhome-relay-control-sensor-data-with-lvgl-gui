#include <Arduino.h>
#define LGFX_AUTODETECT
#define LGFX_WT32_SC01 
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <Wire.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "FS.h"
#include <stdio.h>
#include <LGFX_AUTODETECT.hpp>  
#include <lvgl.h>
#include "lv_conf.h"
#include "displayhandler.h"
#include "pins.h"
//#include <power.h>


void setup(void)
{
  enablepinmode();
  setupdisplay();
  create_tabview();
  sht_setup();
  mcpsetup();
  inasetup();
}
 
 
void loop(void)
{ 
  lv_timer_handler(); /* let the GUI do its work */
  lv_task_handler();
  delay(5); 
  read_sht(tempvalue_obj);
  updatecheckbox();
  readina();
 }
