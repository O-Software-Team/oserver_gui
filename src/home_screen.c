#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINUTE 500 // For updating watch on home page

extern lv_obj_t * home_screen; // defined in main.c

// GLOBAL updatable numbers.

lv_obj_t * hours_high;
lv_obj_t * hours_low;
lv_obj_t * mins_high;
lv_obj_t * mins_low;

lv_label_t * day_of_month;
lv_label_t * month_of_year;

void update_time(void)
{
    time_t T;
    struct tm *t;
    T = time(NULL);
    t = localtime(&T); // not thread safe so no need to free 't'

    char time_hour[3];
    char time_mins[3];
    char h1[2];
    char h0[2];
    char m1[2];
    char m0[2];
    char day[15];
    char month[15];

    strftime(time_hour, sizeof time_hour, "%I", t);
    strftime(time_mins, sizeof time_mins, "%M", t);
    strftime(day, sizeof day, "%d", t);
    strftime(month, sizeof month, "%B", t);

    // Set the current day and month GLOBAL
    lv_label_set_text(day_of_month, day);
    lv_label_set_text(month_of_year, month);

    // Copy each digit to buffer letting strncpy '\0' terminate each one
    strncpy(h1, &time_hour[1], 1);
    strncpy(h0, &time_hour[0], 1);
    strncpy(m1, &time_mins[1], 1);
    strncpy(m0, &time_mins[0], 1);

    // atoi likes to have the string '\0' terminated
    int Ih1 = atoi(h1);
    int Ih0 = atoi(h0);
    int Im1 = atoi(m1);
    int Im0 = atoi(m0);

    // Update the clock digits (GLOBAL alert) with the integer values
    lv_roller_set_selected(hours_high, Ih0, LV_ANIM_ON);
    lv_roller_set_selected(hours_low, Ih1, LV_ANIM_ON);
    lv_roller_set_selected(mins_high, Im0, LV_ANIM_ON);
    lv_roller_set_selected(mins_low, Im1, LV_ANIM_ON);
}

void display_date(lv_obj_t * parent)
{
    static lv_style_t date_style;
    lv_style_init(&date_style);
    lv_style_set_text_font(&date_style, &NeueHaasDisplayRoman_20);

    /* 'Return' (back) button to previous button */
    lv_obj_t * cancel_button = lv_btn_create(parent);
    lv_obj_set_size(cancel_button, 70, 30);
    lv_obj_align(cancel_button, LV_ALIGN_DEFAULT, 290, 20);
    lv_obj_add_event_cb(cancel_button, back_home_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(cancel_button, lv_obj_get_parent(parent));
    lv_obj_set_style_opa(cancel_button, LV_OPA_0, LV_PART_MAIN);

    /* The WiFi indicator */
    lv_obj_t * wifi_symbol = lv_img_create(parent);
    lv_img_set_src(wifi_symbol, &Icon_WiFi_White);
    lv_obj_align(wifi_symbol, LV_ALIGN_DEFAULT, 350, 195);

    /* The Bluetooth indicator */
    lv_obj_t * bt_symbol = lv_img_create(parent);
    lv_img_set_src(bt_symbol, &Icon_Bluetooth_White);
    lv_obj_align(bt_symbol, LV_ALIGN_DEFAULT, 350, 240);

    /* The NFC indicator */
    lv_obj_t * nfc_symbol = lv_img_create(parent);
    lv_img_set_src(nfc_symbol, &Icon_NFC_White);
    lv_obj_align(nfc_symbol, LV_ALIGN_DEFAULT, 350, 285);
    lv_obj_set_style_opa(nfc_symbol, LV_OPA_40, LV_PART_MAIN);

    /* The Blue page indicator */
    lv_obj_t * blue_symbol = lv_img_create(parent);
    lv_img_set_src(blue_symbol, &Page_Dot);
    lv_obj_align(blue_symbol, LV_ALIGN_DEFAULT, 45, 200);

    /* Display the day and month "17 March" format */
    day_of_month = lv_label_create(parent);
    lv_label_set_recolor(day_of_month, true);
    lv_obj_align(day_of_month, LV_ALIGN_CENTER, 0, -185);
    lv_obj_add_style(day_of_month, &date_style, LV_PART_MAIN);
    lv_label_set_text(day_of_month, "\0");
    lv_obj_set_style_text_color(day_of_month, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);

    month_of_year = lv_label_create(parent);
    lv_label_set_recolor(month_of_year, true);
    lv_obj_align(month_of_year, LV_ALIGN_CENTER, 0, -160);
    lv_obj_add_style(month_of_year, &date_style, LV_PART_MAIN);
    lv_label_set_text(month_of_year, "\0");
    lv_obj_set_style_text_color(month_of_year, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);

    /* Display roller digits with hour and minutes */
    static lv_style_t style_sel;
    lv_style_init(&style_sel);
    lv_style_set_text_font(&style_sel, &NeueHaasDisplayXXThin_150);
    lv_style_set_anim_time(&style_sel, 1000);

    lv_style_set_bg_opa(&style_sel, LV_OPA_TRANSP);

    const char * opts = "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n ";

    // NOTE: roller[1-5] are global values in this source module
    hours_high = lv_roller_create(parent);
    lv_obj_set_style_bg_opa(hours_high, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(hours_high, 0, 0);
    lv_obj_set_style_text_color(hours_high, lv_color_white(), 0);
    lv_obj_set_size(hours_high, lv_pct(21), LV_SIZE_CONTENT);
    lv_obj_set_style_pad_right(hours_high, 2, 1);

    lv_roller_set_options(hours_high, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(hours_high, 4);
    lv_obj_add_style(hours_high, &style_sel, LV_PART_MAIN);
    lv_obj_align(hours_high, LV_ALIGN_CENTER, -40, -60);
    //lv_obj_add_event_cb(hours_high, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(hours_high, 10, LV_ANIM_ON);

    /*A roller on the left with left aligned text, and custom width*/
    hours_low = lv_roller_create(parent);
    lv_obj_set_style_bg_opa(hours_low, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(hours_low, 0, 0);
    lv_obj_set_style_text_color(hours_low, lv_color_white(), 0);
    lv_obj_set_size(hours_low, lv_pct(21), LV_SIZE_CONTENT);
    lv_obj_set_style_pad_left(hours_low, 2, 1);

    lv_roller_set_options(hours_low, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(hours_low, 4);
    lv_obj_add_style(hours_low, &style_sel, LV_PART_MAIN);
    lv_obj_align(hours_low, LV_ALIGN_CENTER, 40, -60);
    //lv_obj_add_event_cb(hours_low, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(hours_low, 10, LV_ANIM_ON);

    /*A roller on the middle with center aligned text, and auto (default) width*/
    mins_high = lv_roller_create(parent);
    lv_obj_set_style_bg_opa(mins_high, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(mins_high, 0, 0);
    lv_obj_set_style_text_color(mins_high, lv_color_white(), 0);
    lv_obj_set_size(mins_high, lv_pct(21), LV_SIZE_CONTENT);
    lv_obj_set_style_opa(mins_high, LV_OPA_60, LV_PART_MAIN);
    lv_obj_set_style_pad_right(mins_high, 2, 1);

    lv_roller_set_options(mins_high, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(mins_high, 4);
    lv_obj_add_style(mins_high, &style_sel, LV_PART_MAIN);
    lv_obj_align(mins_high, LV_ALIGN_CENTER, -40, 60);
    //lv_obj_add_event_cb(mins_high, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(mins_high, 10, LV_ANIM_ON);

    /*A roller on the right with right aligned text, and custom width*/
    mins_low = lv_roller_create(parent);
    lv_obj_set_style_bg_opa(mins_low, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(mins_low, 0, 0);
    lv_obj_set_style_text_color(mins_low, lv_color_white(), 0);
    lv_obj_set_size(mins_low, lv_pct(21), LV_SIZE_CONTENT);
    lv_obj_set_style_opa(mins_low, LV_OPA_60, LV_PART_MAIN);
    lv_obj_set_style_pad_left(mins_low, 2, 1);

    lv_roller_set_options(mins_low, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(mins_low, 4);
    lv_obj_add_style(mins_low, &style_sel, LV_PART_MAIN);
    lv_obj_align(mins_low, LV_ALIGN_CENTER, 40, 60);
    //lv_obj_add_event_cb(mins_low, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(mins_low, 10, LV_ANIM_ON);

    /*
     * Short delay and fill in a set of PIN numbers
     */
    lv_timer_t * periodic_time_update = lv_timer_create(update_time, MINUTE, NULL);
    lv_timer_set_repeat_count(periodic_time_update, -1);
}

/* The init routine for the 'home screen' page. (Screen saver) */
void home_screen_setup(void)
{
    printf("HOME SCREEN setup...\n");
    home_screen = lv_img_create(NULL);  // Assigned to GLOBAL

    lv_obj_set_size(home_screen, 385, 510); // Same as the simulator dislay
    lv_obj_set_style_bg_color(home_screen, lv_color_lighten(lv_color_black(), 50), 0);
    lv_img_set_src(home_screen, &Background);
    lv_obj_set_flex_flow(home_screen, LV_FLEX_FLOW_ROW);
    lv_obj_set_scroll_dir(home_screen, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(home_screen, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(home_screen, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    // Turn off the page index circles.
    lv_obj_fade_out(lv_layer_top(), 30, 0);
    /* Store the content of this page for later display */
}

/*
 * This is the home screen it is used to display the time and various device status
 * After a background task is lanched or the menu activity stops - this screen will be displayed
 * for a *predetermined* (XXX needs definition) amount of time, then the screen will fade to black.
 * Touch screen or other "haptic input" will display this screen until "swiped away" to enter menus.
 */
void display_home_screen(void)
{
    lv_obj_t * image = lv_img_create(home_screen); // GLOBAL screen object for home screen
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);
    /*
     * The top middle grey circled cancel button with 'X'
     */

    /* The 'Cancel' button */
    lv_obj_t * cancel_button = lv_btn_create(image);
    lv_obj_set_size(cancel_button, 70, 50);
    lv_obj_align(cancel_button, LV_ALIGN_TOP_MID, 0, 30);
    lv_obj_add_event_cb(cancel_button, back_home_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(cancel_button, lv_obj_get_parent(image));
    lv_obj_set_style_opa(cancel_button, LV_OPA_0, LV_PART_MAIN);

    // Display date numbers
    display_date(image);

    /*
     * The yellow progress page accent
     */
    lv_obj_t * progress = lv_img_create(image);
    lv_img_set_src(progress, &Progress);
    lv_obj_center(progress);

    lv_scr_load(home_screen);
    //lv_obj_fade_out(home_screen, 1000, 500);
}
