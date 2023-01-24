#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

extern lv_obj_t * home_screen; // defined in main.c

/* The init routine for the 'home screen' page. (Screen saver) */
void home_screen_setup(void)
{
    printf("HOME SCREEN setup...\n");
    home_screen = lv_img_create(NULL); // Assigned to GLOBAL

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
void home_screen_display(void)
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

    /*
     * The yellow progress page accent
     */
    lv_obj_t * progress = lv_img_create(image);
    lv_img_set_src(progress, &Progress);
    lv_obj_center(progress);
}