#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>
#include <time.h>

extern lv_obj_t * home_screen; // defined in main.c

// GLOBAL updatable numbers.

lv_obj_t * hours_high;
lv_obj_t * hours_low;
lv_obj_t * mins_high;
lv_obj_t * mins_low;

void update_date(void)
{
    time_t T;
    struct tm *t;
    T = time(NULL);
    t = localtime(&T);

    lv_roller_set_selected(hours_high, 9, LV_ANIM_ON);
    lv_roller_set_selected(hours_low, 2, LV_ANIM_ON);
    lv_roller_set_selected(mins_high, 3, LV_ANIM_ON);
    lv_roller_set_selected(mins_low, 6, LV_ANIM_ON);
}

void display_date(lv_obj_t * parent)
{
    static lv_style_t cancel_style;
    lv_style_init(&cancel_style);
    lv_style_set_text_font(&cancel_style, &NeueHaasDisplayLight_16);

    /* 'Cancel' button to cancel the security challenge process*/
    lv_obj_t * cancel = lv_label_create(parent);
    lv_label_set_recolor(cancel, true);
    lv_label_set_text(cancel, "Cancel");
    lv_obj_set_style_text_color(cancel, lv_color_white(), 0);
    lv_obj_align(cancel, LV_ALIGN_DEFAULT, 300, 25);
    lv_obj_add_style(cancel, &cancel_style, LV_PART_MAIN);

    /* 'Return' (back) button to previous button */
    lv_obj_t * cancel_button = lv_btn_create(parent);
    lv_obj_set_size(cancel_button, 70, 30);
    lv_obj_align(cancel_button, LV_ALIGN_DEFAULT, 290, 20);
    lv_obj_add_event_cb(cancel_button, back_home_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(cancel_button, lv_obj_get_parent(parent));
    lv_obj_set_style_opa(cancel_button, LV_OPA_0, LV_PART_MAIN);

    /* Display the code */
    static lv_style_t style_sel;
    lv_style_init(&style_sel);
    lv_style_set_text_font(&style_sel, &NeueHaasDisplayXXThin_150);
    lv_style_set_anim_time(&style_sel, 1000);

    lv_style_set_bg_opa(&style_sel, LV_OPA_TRANSP);

    const char * opts = "1\n2\n3\n4\n5\n6\n7\n8\n9\n0";

    // NOTE: roller[1-5] are global values in this source module
    hours_high = lv_roller_create(parent);
    lv_obj_set_style_bg_opa(hours_high, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(hours_high, 0, 0);
    lv_obj_set_style_text_color(hours_high, lv_color_white(), 0);
    lv_obj_set_size(hours_high, lv_pct(21), LV_SIZE_CONTENT);

    lv_roller_set_options(hours_high, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(hours_high, 4);
    lv_obj_add_style(hours_high, &style_sel, LV_PART_MAIN);
    lv_obj_align(hours_high, LV_ALIGN_CENTER, -40, -60);
    //lv_obj_add_event_cb(hours_high, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(hours_high, 9, LV_ANIM_ON);

    /*A roller on the left with left aligned text, and custom width*/
    hours_low = lv_roller_create(parent);
    lv_obj_set_style_bg_opa(hours_low, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(hours_low, 0, 0);
    lv_obj_set_style_text_color(hours_low, lv_color_white(), 0);
    lv_obj_set_size(hours_low, lv_pct(21), LV_SIZE_CONTENT);

    lv_roller_set_options(hours_low, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(hours_low, 4);
    lv_obj_add_style(hours_low, &style_sel, LV_PART_MAIN);
    lv_obj_align(hours_low, LV_ALIGN_CENTER, 40, -60);
    //lv_obj_add_event_cb(hours_low, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(hours_low, 8, LV_ANIM_ON);

    /*A roller on the middle with center aligned text, and auto (default) width*/
    mins_high = lv_roller_create(parent);
    lv_obj_set_style_bg_opa(mins_high, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(mins_high, 0, 0);
    lv_obj_set_style_text_color(mins_high, lv_color_white(), 0);
    lv_obj_set_size(mins_high, lv_pct(21), LV_SIZE_CONTENT);
    lv_obj_set_style_opa(mins_high, LV_OPA_60, LV_PART_MAIN);

    lv_roller_set_options(mins_high, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(mins_high, 4);
    lv_obj_add_style(mins_high, &style_sel, LV_PART_MAIN);
    lv_obj_align(mins_high, LV_ALIGN_CENTER, -40, 60);
    //lv_obj_add_event_cb(mins_high, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(mins_high, 3, LV_ANIM_ON);

    /*A roller on the right with right aligned text, and custom width*/
    mins_low = lv_roller_create(parent);
    lv_obj_set_style_bg_opa(mins_low, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(mins_low, 0, 0);
    lv_obj_set_style_text_color(mins_low, lv_color_white(), 0);
    lv_obj_set_size(mins_low, lv_pct(21), LV_SIZE_CONTENT);
    lv_obj_set_style_opa(mins_low, LV_OPA_60, LV_PART_MAIN);

    lv_roller_set_options(mins_low, opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(mins_low, 4);
    lv_obj_add_style(mins_low, &style_sel, LV_PART_MAIN);
    lv_obj_align(mins_low, LV_ALIGN_CENTER, 40, 60);
    //lv_obj_add_event_cb(mins_low, event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(mins_low, 4, LV_ANIM_ON);
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
    lv_obj_t * grey_outline = lv_img_create(image);
    lv_img_set_src(grey_outline, &Icon_Grey_Outline_Button);
    lv_obj_align(grey_outline, LV_ALIGN_TOP_MID, 0, 30);

    lv_obj_t * cancel = lv_img_create(image);
    lv_img_set_src(cancel, &Icon_Close_White);
    lv_obj_align(cancel, LV_ALIGN_TOP_MID, 0, 40);

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