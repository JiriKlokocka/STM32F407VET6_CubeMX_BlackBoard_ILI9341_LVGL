/*
 * lvgl_GUI.c
 *
 *  Created on: Nov 19, 2020
 *      Author: KlokockaJir
 */

/*********************
*      INCLUDES
*********************/
#include "lvgl/lvgl.h"
#include "lvgl_GUI.h"


/*
https://lvgl.io/tools/fontconverter

0x2a-0x3a,0x20,0xb0,0x43

*/

#define TEMP_BORDER 0
#define BTN_SZX 90
#define BTN_SZY 90

/**********************
*  STATIC VARIABLES
**********************/

static lv_obj_t* tv;
static lv_obj_t* tab1;
static lv_obj_t* tab2;

/**********************
*   GLOBAL FUNCTIONS
**********************/


static void controls_create(lv_obj_t* parent);
static void settings_create(lv_obj_t* parent);
static void JK_Test_Button(lv_obj_t* parent, const char* symbol, const char* text);


/**********************
*      FUNCTIONS
**********************/
void lvgl_GUI(void)
{
    //TabView
    tv = lv_tabview_create(lv_scr_act(), NULL);
    //lv_obj_set_style_local_pad_left(tv, LV_TABVIEW_PART_TAB_BG, LV_STATE_DEFAULT, LV_HOR_RES / 2);
    lv_tabview_set_anim_time(tv, 1000);

    tab1 = lv_tabview_add_tab(tv, "Tab 1");
    tab2 = lv_tabview_add_tab(tv, "Tab 2");

    controls_create(tab1);
    settings_create(tab2);
}


static void controls_create(lv_obj_t* parent) {
	lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY_TOP);
	JK_Test_Button(parent, LV_SYMBOL_WIFI, " Button1");
	JK_Test_Button(parent, LV_SYMBOL_POWER, " Button2");
	JK_Test_Button(parent, LV_SYMBOL_KEYBOARD," Button3");
	JK_Test_Button(parent, LV_SYMBOL_SETTINGS," Button4");
	JK_Test_Button(parent, LV_SYMBOL_BLUETOOTH," Button5");
	JK_Test_Button(parent, LV_SYMBOL_SD_CARD," Button6");
}

static void settings_create(lv_obj_t* parent) {
	lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY_TOP);
	JK_Test_Button(parent, LV_SYMBOL_WIFI, " Button1");
	JK_Test_Button(parent, LV_SYMBOL_POWER, " Button2");
	JK_Test_Button(parent, LV_SYMBOL_KEYBOARD," Button3");
	JK_Test_Button(parent, LV_SYMBOL_SETTINGS," Button4");
	JK_Test_Button(parent, LV_SYMBOL_BLUETOOTH," Button5");
	JK_Test_Button(parent, LV_SYMBOL_SD_CARD," Button6");
}


static void JK_Test_Button(lv_obj_t* parent, const char* symbol, const char* text) {
	lv_obj_t* btn = lv_btn_create(parent, NULL);
	    //lv_obj_set_pos(btn, 10, 10);
	    lv_obj_set_size(btn, 100, 35);
	    //lv_obj_set_event_cb(btn, btn_event_cb);
	    //Button label
	    lv_obj_t* label = lv_label_create(btn, NULL);
	    lv_label_set_text_fmt(label, "%s %s", symbol, text);
}


void LCD_UpdateTime(uint8_t hrs, uint8_t mnts, uint8_t scnds) {

    static char blinkDots = ':';
    if (blinkDots == ':') {
        blinkDots = ' ';
    }
    else {
        blinkDots = ':';
    }
//    lv_label_set_text_fmt(lblTime, "%02i%:%02i:%02i", hrs, mnts, scnds);
//    lv_label_set_text_fmt(lblTimeBig, "%02i%c%02i", hrs, blinkDots, mnts);
}

void LCD_UpdateDate(uint8_t wd, uint8_t dy, uint8_t mnth, uint16_t yr) {

    //static const char* dayNames[] = { "Ne", "Po", "Ut", "St", "Ct", "Pa", "So" };
    //lv_label_set_text_fmt(lblDate, "%s %02i.%02i.%04i", dayNames[wd], dy, mnth, yr);

}
