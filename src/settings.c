#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Initialize/populate the Settings list structs */
#include "content/test/settings/01.h"   /* Main screen - Settings list */

#define LV_FONT_MONTSERRAT_44 1

#define FONT_SIZE_WORKS 0 // Until it's figured out

/* Main background and radio controls declared below */
LV_IMG_DECLARE(Background);
LV_IMG_DECLARE(Icon_Back);
LV_IMG_DECLARE(Icon_WiFi_White);
LV_IMG_DECLARE(Icon_Bluetooth_White);
LV_IMG_DECLARE(Icon_NFC_White);

/* Visual queue iconagraphy like status dots declared below */
LV_IMG_DECLARE(Icon_Status_Active);
LV_IMG_DECLARE(Icon_Status_Disable);

/* Standard list control iconography declared below */
LV_IMG_DECLARE(Icon_Filter_Button);
LV_IMG_DECLARE(Icon_List_Item_Divider);

LV_IMG_DECLARE(Icon_Filter_White);
LV_IMG_DECLARE(Icon_Unread_Yellow);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Time);
LV_IMG_DECLARE(Linez);

/* Contact Card - Contact Initials Background */
LV_IMG_DECLARE(Icon_Contact_Initials_Background);

/* Main HEADING iconography */
LV_IMG_DECLARE(Contacts_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);


/***  Filesystem Specific Declarations  ***/

/* Set total number of pages / screens -- this includes screen #1 which is the main filesystem screen to screen #7 which is the spreadsheets screen */
#define NUM_SCREENS 7

/* Set the array to store the screen reference pointers */
lv_obj_t* settings_objects[NUM_SCREENS];

/* Set the BACK-TO-HOME array to use in a custom back button for the filesystem app */
lv_obj_t * back_to_filesystem[NUM_SCREENS];

static int settings_app_item;
static int settings_app_record;
static int ttl_settings_items = 1;

static int ttl_rows;
static int ttl_height;
static int ttl_offset;
static int ttl_calc_overlay_height;
static int ttl_calc_overlay_offset;

static int back_to_fs = 1;

/* Scroll to the filesystem home screen as the final step in the filesytem app launch */
static void quit_application() {
    printf("\n\nEXEC :: exiting()\n\n");
    usleep(2250000);
    exit(0);
}

static int calc_scroll_height(int ttl_rows) {
    // printf("\n\nCalc Scroll Rows: %d\n",ttl_rows);
    ttl_height = ttl_rows * 52;
    // printf("Calc Scroll Height: %d\n",ttl_height);
    return ttl_height;
}

static int calc_scroll_offset(int ttl_rows) {
    int off_mult;
    if(ttl_rows <= 10) {
        ttl_offset = 90;
    } else {
        ttl_offset = ttl_rows * 22;
    }
    // printf("Calc Scroll Offset: %d\n",ttl_offset);
    return ttl_offset;
}

static void settings_01_view(lv_obj_t * settings_01_view_page) {
    lv_obj_t * image = lv_img_create(settings_01_view_page);
    settings_objects[1] = image;
    lv_img_set_src(image, &Background);

    /* Calculate total Filesystem_02 -- your folders */
    // printf("\nCalculate filesystem_02 -- your folders...\n");
    for(settings_app_item = 0; settings_01_list[settings_app_item].settings_id != "end"; settings_app_item++) {
        ttl_settings_items = settings_app_item+1;
        // printf("Item count: %d -- settings_id: %s\n",ttl_settings_items,settings_01_list[settings_app_item].settings_id);
    }
    // printf("\nTotal Records: %d\n\n",ttl_settings_items);

    /* Build the Contact record list for display */
    // printf("Building each Filesystem_02 record for display\n");
    for(int j = 0; j < ttl_settings_items; j++) {
        if(settings_01_list[j].settings_id == "end") {
            // printf("item: %d -- settings_name: %s\n",j,settings_01_list[j].settings_name);
            break;
        } else {
            // printf("settings_id: %s -- settings_name: %s\n",settings_01_list[j].settings_id,settings_01_list[j].settings_name);
        }
    }

    /* Calculate the entire "screen height" and "screen offset" for the scroll-overlay */
    ttl_calc_overlay_height = calc_scroll_height(ttl_settings_items);
    // printf("\n\nCalc Scroll Height: %d\n",ttl_calc_overlay_height);
    ttl_calc_overlay_offset = calc_scroll_offset(ttl_settings_items);
    // printf("Calc Scroll Offset: %d\n\n",ttl_calc_overlay_offset);

/***  HEADING ELEMENTS  ***/

    static lv_style_t power_off_style_img;
    lv_style_init(&power_off_style_img);
    lv_style_set_img_recolor(&power_off_style_img, lv_color_hex(0xDD4949));
    lv_style_set_img_recolor_opa(&power_off_style_img, LV_OPA_COVER);
    lv_style_set_text_font(&power_off_style_img, &NeueHaasDisplayLight_20);

    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_filesystem[back_to_fs] = lv_btn_create(image);
    lv_obj_set_size(back_to_filesystem[back_to_fs], 130, 50);
    lv_obj_align(back_to_filesystem[back_to_fs], LV_ALIGN_TOP_LEFT, 20, 31);
    lv_obj_set_style_opa(back_to_filesystem[back_to_fs], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_filesystem[back_to_fs], quit_application, LV_EVENT_CLICKED, NULL);

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, 25, 45);
    lv_obj_add_style(back_image, &power_off_style_img, 0);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Power Off");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(0xDD4949), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);
}

void settings_menu_setup(void)
{
    printf("SETTINGS MENU init...\n");

    lv_obj_t * settings_page = lv_obj_create(NULL);
    menu_dispatch_table[SETTINGS_VEC] = settings_page;

    lv_obj_center(settings_page);
    lv_obj_set_style_bg_color(settings_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(settings_page, LV_FLEX_FLOW_ROW);
    //lv_obj_add_event_cb(settings_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(settings_page, true, 3);
    lv_obj_set_scroll_dir(settings_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(settings_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(settings_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);
    
    settings_01_view(settings_page);

}
