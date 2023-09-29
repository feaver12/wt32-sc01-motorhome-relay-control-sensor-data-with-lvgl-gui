#include <lvgl.h>
#include <eventhandler.h>
//#include "sht.h"


lv_obj_t * CH1volts_obj; //label
lv_obj_t * CH1amps_obj; //label
lv_obj_t * tempvalue_obj; //label
lv_obj_t * humvalue_obj; //label
lv_obj_t * checkbox;
lv_obj_t * checkbox2;
lv_obj_t * checkbox3;
lv_obj_t * checkbox4;

void create_tabview(void) {

    static lv_style_t style;
    lv_style_init(&style);

    static lv_style_t style_shadow;
    lv_style_init(&style_shadow);
    lv_style_set_shadow_width(&style_shadow, 10);
    lv_style_set_shadow_spread(&style_shadow, 5);
    lv_style_set_shadow_color(&style_shadow, lv_palette_darken(LV_PALETTE_BLUE, 3));

    /*Create a Tab view object*/
    lv_obj_t *tabview;
    tabview = lv_tabview_create(lv_scr_act(), LV_DIR_LEFT, 100);


 //   lv_obj_add_event_cb(lv_tabview_get_content(tabview), scroll_begin_event, LV_EVENT_SCROLL_BEGIN, NULL);

    lv_obj_set_style_bg_color(tabview, lv_palette_lighten(LV_PALETTE_GREY, 2), 0);

    lv_obj_t * tab_btns = lv_tabview_get_tab_btns(tabview);
    lv_obj_set_style_bg_color(tab_btns, lv_palette_darken(LV_PALETTE_GREY, 5), 0);
    lv_obj_set_style_text_color(tab_btns, lv_palette_darken(LV_PALETTE_BLUE_GREY, 1), 0);
    lv_obj_set_style_border_side(tab_btns, LV_BORDER_SIDE_RIGHT, LV_PART_ITEMS | LV_STATE_CHECKED);


    /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
    lv_obj_t *tab1 = lv_tabview_add_tab(tabview, "Interior Lights");
    lv_obj_t *tab2 = lv_tabview_add_tab(tabview, "Exterior Lights");
    lv_obj_t *tab3 = lv_tabview_add_tab(tabview, "Devices");
    lv_obj_t *tab4 = lv_tabview_add_tab(tabview, "Water Tanks");
    lv_obj_t *tab5 = lv_tabview_add_tab(tabview, "Sensors");
    //lv_obj_add_event_cb(tab5, updategreytank, LV_EVENT_ALL, NULL);

    lv_obj_set_style_bg_color(tab1, lv_palette_darken(LV_PALETTE_BLUE_GREY, 3), 0);
    lv_obj_set_style_bg_opa(tab1, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(tab2, lv_palette_darken(LV_PALETTE_BLUE_GREY, 3), 0);
    lv_obj_set_style_bg_opa(tab2, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(tab3, lv_palette_darken(LV_PALETTE_BLUE_GREY, 3), 0);
    lv_obj_set_style_bg_opa(tab3, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(tab4, lv_palette_darken(LV_PALETTE_BLUE_GREY, 3), 0);
    lv_obj_set_style_bg_opa(tab4, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(tab5, lv_palette_darken(LV_PALETTE_BLUE_GREY, 3), 0);
    lv_obj_set_style_bg_opa(tab5, LV_OPA_COVER, 0);


    /*Add content to the tabs*/
    lv_obj_t * label;

    // tab 1

    label = lv_label_create(tab1);
    lv_label_set_text(label, "");

    // Add buttons to first tab

//button 1 interior front lights
    lv_obj_t *btn1 = lv_btn_create(tab1);
    lv_obj_set_pos(btn1, 25, 30);
    lv_obj_set_size(btn1, 130, 80);
    lv_obj_add_style(btn1, &style_shadow, 0);
    lv_obj_add_flag(btn1, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(btn1, toggle_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(btn1, btn_onoff, LV_EVENT_ALL, NULL);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Lights Front");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, 0);
    lv_obj_center(label);



//button 2 interior centre lights
    lv_obj_t *btn2 = lv_btn_create(tab1);
    lv_obj_set_pos(btn2, 205, 30);
    lv_obj_set_size(btn2, 130, 80);
    lv_obj_add_style(btn2, &style_shadow, 0);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(btn2, toggle_event_handler2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(btn2, btn2_onoff, LV_EVENT_ALL, NULL);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Lights Centre");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, 0);
    lv_obj_center(label);

//button 3 interior rear lights
    lv_obj_t *btn3 = lv_btn_create(tab1);
    lv_obj_set_pos(btn3, 110, 180);
    lv_obj_set_size(btn3, 130, 80);
    lv_obj_add_style(btn3, &style_shadow, 0);
    lv_obj_add_flag(btn3, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(btn3, toggle_event_handler3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(btn3, btn3_onoff, LV_EVENT_ALL, NULL);

    label = lv_label_create(btn3);
    lv_label_set_text(label, "Lights Rear");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, 0);
    lv_obj_center(label);




       //tab2


    label = lv_label_create(tab2);
    lv_label_set_text(label, "");


        // Add buttons to second tab

  //button 4 exterior lights
    lv_obj_t *btn4 = lv_btn_create(tab2);
    lv_obj_set_pos(btn4, 110, 30);
    lv_obj_set_size(btn4, 130, 80);
    lv_obj_add_style(btn4, &style_shadow, 0);
    lv_obj_add_flag(btn4, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(btn4, toggle_event_handler4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(btn4, btn4_onoff, LV_EVENT_ALL, NULL);

    label = lv_label_create(btn4);
    lv_label_set_text(label, "Lights Exterior");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, 0);
    lv_obj_center(label);

  //button 5 boot lights
    lv_obj_t *btn5 = lv_btn_create(tab2);
    lv_obj_set_pos(btn5, 110, 180);
    lv_obj_set_size(btn5, 130, 80);
    lv_obj_add_style(btn5, &style_shadow, 0);
    lv_obj_add_flag(btn5, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(btn5, toggle_event_handler5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(btn5, btn5_onoff, LV_EVENT_ALL, NULL);

    label = lv_label_create(btn5);
    lv_label_set_text(label, "Lights Boot");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, 0);
    lv_obj_center(label);



    //tab 3


    label = lv_label_create(tab3);
    lv_label_set_text(label, "");


        // Add buttons to third tab

        // button 6 tv 
    lv_obj_t *btn6 = lv_btn_create(tab3);
    lv_obj_set_pos(btn6, 25, 30);
    lv_obj_set_size(btn6, 130, 80);
    lv_obj_add_style(btn6, &style_shadow, 0);
    lv_obj_add_flag(btn6, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(btn6, toggle_event_handler6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(btn6, btn6_onoff, LV_EVENT_ALL, NULL);

    label = lv_label_create(btn6);
    lv_label_set_text(label, "T.V");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, 0);
    lv_obj_center(label);


        // button 7 fridge 
    lv_obj_t *btn7 = lv_btn_create(tab3);
    lv_obj_set_pos(btn7, 205, 30);
    lv_obj_set_size(btn7, 130, 80);
    lv_obj_add_style(btn7, &style_shadow, 0);
    lv_obj_add_flag(btn7, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(btn7, toggle_event_handler7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(btn7, btn7_onoff, LV_EVENT_ALL, NULL);

    label = lv_label_create(btn7);
    lv_label_set_text(label, "Fridge");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, 0);
    lv_obj_center(label);


        // button 8 main relay 
    lv_obj_t *btn8 = lv_btn_create(tab3);
    lv_obj_set_pos(btn8, 110, 180);
    lv_obj_set_size(btn8, 130, 80);
    lv_obj_add_style(btn8, &style_shadow, 0);
    lv_obj_add_flag(btn8, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(btn8, toggle_event_handler8, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(btn8, btn8_onoff, LV_EVENT_ALL, NULL);

    label = lv_label_create(btn8);
    lv_label_set_text(label, "Main Realy");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, 0);
    lv_obj_center(label);



// tab4



    label = lv_label_create(tab4);
    lv_label_set_text(label, "");
    checkbox = lv_checkbox_create(tab4);// Create a checkbox in the Water Tanks tab
    lv_obj_add_style(checkbox, &style_shadow, 0);
    lv_checkbox_set_text(checkbox, "Grey Tank Full");
    lv_obj_set_style_text_color(checkbox, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
    lv_obj_set_style_text_font(checkbox, &lv_font_montserrat_26, 0);
    lv_obj_set_pos(checkbox, 80, 30);
    lv_obj_add_state(checkbox, LV_STATE_DISABLED);
    

    label = lv_label_create(tab4);
    lv_label_set_text(label, "");
    checkbox2 = lv_checkbox_create(tab4); // Create a checkbox in the Water Tanks tab
    lv_obj_add_style(checkbox2, &style_shadow, 0);
    lv_checkbox_set_text(checkbox2, "Black Tank Full");
    lv_obj_set_style_text_color(checkbox2, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
    lv_obj_set_style_text_font(checkbox2, &lv_font_montserrat_26, 0);
    lv_obj_set_pos(checkbox2, 80, 100);
    lv_obj_add_state(checkbox2, LV_STATE_DISABLED);



    label = lv_label_create(tab4);
    lv_label_set_text(label, "");
    checkbox3 = lv_checkbox_create(tab4); // Create a checkbox in the Water Tanks tab
    lv_obj_add_style(checkbox3, &style_shadow, 0);
    lv_checkbox_set_text(checkbox3, "Fresh Tank Low");
    lv_obj_set_style_text_color(checkbox3, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
    lv_obj_set_style_text_font(checkbox3, &lv_font_montserrat_26, 0);
    lv_obj_set_pos(checkbox3, 80, 170);
    lv_obj_add_state(checkbox3, LV_STATE_DISABLED);



    label = lv_label_create(tab4);
    lv_label_set_text(label, "");
    checkbox4 = lv_checkbox_create(tab4); // Create a checkbox in the Water Tanks tab
    lv_obj_add_style(checkbox4, &style_shadow, 0);
    lv_checkbox_set_text(checkbox4, "Flush Tank Low");
    lv_obj_set_style_text_color(checkbox4, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
    lv_obj_set_style_text_font(checkbox4, &lv_font_montserrat_26, 0);
    lv_obj_set_pos(checkbox4, 80, 240);
    lv_obj_add_state(checkbox4, LV_STATE_DISABLED);



//tab5
    
//static char buffer[32]; //for updating the temp sensor label.
//float temp = sht.getTemperature();
//lv_obj_t * tempvalue; //label


lv_style_set_text_letter_space(&style, 3);

tempvalue_obj = lv_label_create(tab5);
lv_obj_set_pos(tempvalue_obj, 50, 100);
lv_obj_set_style_text_color(tempvalue_obj, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
lv_obj_set_style_text_font(tempvalue_obj, &lv_font_montserrat_30, 0);

humvalue_obj = lv_label_create(tab5);
lv_obj_set_pos(humvalue_obj, 50, 140);
lv_obj_set_style_text_color(humvalue_obj, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
lv_obj_set_style_text_font(humvalue_obj, &lv_font_montserrat_30, 0);

CH1volts_obj = lv_label_create(tab5);
lv_obj_set_pos(CH1volts_obj, 50, 200);
lv_obj_set_style_text_color(CH1volts_obj, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
lv_obj_set_style_text_font(CH1volts_obj, &lv_font_montserrat_30, 0);

CH1amps_obj = lv_label_create(tab5);
lv_obj_set_pos(CH1amps_obj, 50, 240);
lv_obj_set_style_text_color(CH1amps_obj, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
lv_obj_set_style_text_font(CH1amps_obj, &lv_font_montserrat_30, 0);



//snprintf(buffer, 32, "Temp: %.1f", temp);
//lv_label_set_text(tempvalue_obj, buffer);


    /*Create the main label*/
    //label = lv_label_create(tab5);
    //lv_label_set_text_fmt(label, "Grey Tank Level: %s", (greystate == HIGH) ? "FULL" : "LOW");
   // lv_label_set_text_fmt(label, "Temp = %f", shttemp);


    //lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);




    lv_obj_clear_flag(lv_tabview_get_content(tabview), LV_OBJ_FLAG_SCROLLABLE);

}

