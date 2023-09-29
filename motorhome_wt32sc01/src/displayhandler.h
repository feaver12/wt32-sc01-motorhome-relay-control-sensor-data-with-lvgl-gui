#include <lvgl.h>
#include "lv_conf.h"
#define LGFX_AUTODETECT 
#define LGFX_WT32_SC01 
#include <Arduino.h>
#define LGFX_USE_V1
#include <LovyanGFX.hpp>

/*** Setup screen resolution for LVGL ***/
static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];
 
// Wireless Tag => LGFX_WT32_SC01 (also Seeed WT32-SC01)
// 3.5" 480x320 ST7796S TFT Display
// Capacitive touchscreen FT6336U
 
static LGFX lcd;


 /*** Display callback to flush the buffer to screen ***/
  void display_flush(lv_disp_drv_t * disp, const lv_area_t *area, lv_color_t *color_p)
  {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
 
    lcd.startWrite();
    lcd.setAddrWindow(area->x1, area->y1, w, h);
    lcd.pushPixels((uint16_t *)&color_p->full, w * h, true);
    lcd.endWrite();
 
    lv_disp_flush_ready(disp);
  }
 
 
 
  /*** Touchpad callback to read the touchpad ***/
  void touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
  {
    uint16_t touchX, touchY;
    bool touched = lcd.getTouch(&touchX, &touchY);
 
    if (!touched)
    {
      data->state = LV_INDEV_STATE_REL;
    }
    else
    {
      data->state = LV_INDEV_STATE_PR;
 
      /*Set the coordinates*/
      data->point.x = touchX;
      data->point.y = touchY;
 
      Serial.printf("Touch (x,y): (%03d,%03d)\n",touchX,touchY );
    }
  }
 

void setupdisplay() {
  lcd.init();
  lv_init();  // Initialize lvgl
  Serial.begin(115200); /* prepare for possible serial debug */
  // Setting display to landscape
  if (lcd.width() < lcd.height())
    lcd.setRotation(lcd.getRotation() ^ 1);
 
  /* LVGL : Setting up buffer to use for display */
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);
 
  /*** LVGL : Setup & Initialize the display device driver ***/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = display_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);
 
  /*** LVGL : Setup & Initialize the input device driver ***/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = touchpad_read;
  lv_indev_drv_register(&indev_drv);
 
}