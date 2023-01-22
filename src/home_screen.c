#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

/* The init routine for the 'home screen' page. (Screen saver) */
void home_screen_setup(void)
{
    printf("HOME SCREEN setup...\n");
#if ALL_SCROLL
    lv_obj_t * device_page = lv_obj_create(NULL);
    menu_dispatch_table[DEVICE_VEC] = device_page;

    lv_obj_center(device_page);
    lv_obj_set_style_bg_color(device_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(device_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(device_page, true, 3);
    lv_obj_set_scroll_dir(device_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(device_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(device_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* Store the content of this page for later display */

    /* SUB-SCREEN 0: Create already connected (trusted) devices page add it to parent */
    device_trusted_init(device_page);

    /* SUB-SCREEN 1: Devices found in the area listed here */
    devices_found_init(device_page);

    /* SUB-SCREEN 2: Display code for connection to selected device */
    device_code_init(device_page);

    /* SUB_SCREEN 3: Setup display for the new 'trusted' device */
    device_connected_init(device_page);
#else
    lv_obj_t * lotus_root_page = lv_img_create(NULL);
    menu_dispatch_table[DEVICE_VEC] = lotus_root_page;

    lv_obj_set_size(lotus_root_page, 385, 510); // Same as the simulator dislay
    lv_obj_set_style_bg_color(lotus_root_page, lv_color_lighten(lv_color_black(), 50), 0);
    lv_img_set_src(lotus_root_page, &Background);
    lv_obj_set_flex_flow(lotus_root_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_scroll_dir(lotus_root_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(lotus_root_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(lotus_root_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* Store the content of this page for later display */

    /* SUB-SCREEN 1: Create already connected (trusted) devices page add it to parent */
    device_trusted_init(lotus_root_page);

    /* SUB-SCREEN 2: Devices found in the area listed here */
    devices_found_init(lotus_root_page);

    /* SUB-SCREEN 3: Display code for connection to selected device */
    device_code_init(lotus_root_page);

    /* SUB_SCREEN 4: Setup display for the new 'trusted' device */
    device_connected_init(lotus_root_page);
#endif // ALL_SCROLL
}



/* When a device is selected to be enquire about a trust relationship, this code page displays */
void home_screen_init(lv_obj_t * oserver_page)
{
    int percent_done = 0;
    int time_remaining = 12;

    static lv_style_t heading_style;
    lv_style_init(&heading_style);
    lv_style_set_text_font(&heading_style, &NeueHaasDisplayRoman_20);

    static lv_style_t min_remain_style;
    lv_style_init(&min_remain_style);
    lv_style_set_text_font(&min_remain_style, &NeueHaasDisplayRoman_20);

#if ALL_SCROLL
    lv_obj_t * image = lv_img_create(oserver_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(oserver_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);
#endif // ALL_SCROLL

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

    lv_obj_t * total_transfer = lv_label_create(image);
    lv_label_set_text(total_transfer, "Total Transfer");
    lv_label_set_recolor(total_transfer, true);
    lv_obj_set_style_text_color(total_transfer, lv_color_lighten(lv_color_black(), 99), 0);
    lv_obj_add_style(total_transfer, &heading_style, LV_PART_MAIN);
    lv_obj_align(total_transfer, LV_ALIGN_DEFAULT, 140, 140);

    // Here is the date and time home screen


    /* Click herer to 'run in background' text */
    lv_obj_t * background = lv_label_create(image);
    lv_label_set_recolor(background, true);
    lv_label_set_text(background, "        Run in\nBackground");
    lv_obj_set_style_text_color(background, lv_color_darken(lv_color_white(), 80), 0);
    lv_obj_add_style(background, &min_remain_style, LV_PART_MAIN);
    lv_obj_align(background, LV_ALIGN_BOTTOM_MID, 10, -50);

    /* Click here to run the transfer in background */
    lv_obj_t * background_button = lv_btn_create(image);
    lv_obj_set_size(background_button, 110, 60);
    lv_obj_align(background_button, LV_ALIGN_BOTTOM_MID, 10, -40);
    lv_obj_add_event_cb(background_button, back_home_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(background_button, lv_obj_get_parent(image));
    lv_obj_set_style_opa(background_button, LV_OPA_0, LV_PART_MAIN);
}