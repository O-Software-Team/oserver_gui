#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Initialize/populate the Song list struct */
#include "content/inc/devices/00.h"   /* Full Device List -and- State Machine Baseline */
#include "content/inc/devices/01.h"   /* Device Control Items List */

/* List separator line definitions */
#define LIST_SEPARATOR 30

/* Padding definitions */
#define BACK_BUTTON_PAD 25
#define NARROW_PAD_LEFT 5
#define SIMPLE_PAD_LEFT 20
#define NORMAL_PAD_LEFT 30
#define NARROW_PAD_RIGHT -5
#define SIMPLE_PAD_RIGHT -20
#define NORMAL_PAD_RIGHT -30
#define REGULAR_ICON_PAD_LEFT 85

/* Color definitions */
#define O_YELLOW_COLOR 0xD6B932
#define O_GREY_COLOR 0xAEB2A1
#define O_TEAL_COLOR 0x0AC1C1
#define O_SCALE_GREY 0xC5C1B7
#define O_SCALE_CREAM 0xD9DFC2
#define O_SCALE_ORANGE 0xCB6D4D
#define O_SCALE_RED 0xB7354B
#define O_SCALE_LIGHT_TEAL 0xC5E7E7
#define O_SCALE_LIGHT_YELLOW 0xDABC41
#define HEADING_SUBDUED_COLOR 0xADB1A2
#define RESET_COLOR 0x32D642
#define POWER_OFF_COLOR 0xDD4949
#define BATTERY_LEVEL_GREAT 0x32D642
#define BATTERY_LEVEL_FAIR 0xFFFFFF
#define BATTERY_LEVEL_LOW 0xDD4949

/* Font definitions */
#define LV_FONT_MONTSERRAT_44 1
#define FONT_SIZE_WORKS 0

/* Music list and song ID variables */
#define DEVICE_ID 0   // This is temporary until the calendar list dataset is being accessed

/***  Main background and radio controls declared below  ***/
LV_IMG_DECLARE(Background);
LV_IMG_DECLARE(Icon_Back);
LV_IMG_DECLARE(Icon_WiFi_White);
LV_IMG_DECLARE(Icon_Bluetooth_White);
LV_IMG_DECLARE(Icon_NFC_White);
LV_IMG_DECLARE(Icon_Add_Device);

/* Main HEADING iconography */
LV_IMG_DECLARE(O_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);
// LV_FONT_DECLARE(NeueHaasDisplayLight_32);

/* Main device configuration iconography */
LV_IMG_DECLARE(Icon_Device_Configuration);
LV_IMG_DECLARE(Icon_Device_Control_Total);
LV_IMG_DECLARE(Icon_Device_Control_Neutral);
LV_IMG_DECLARE(Icon_Device_Control_Synchronisation);

static int device_list_offset_value = 90;
static int ttl_height = 0;
static int ttl_calc_overlay_height = 0;
static int ttl_calc_overlay_offset = 0;

/* Set total number of pages / screens -- this includes screen #1 which is the main found devices list screen */
#define NUM_SCREENS 5

/* Create elements to support the rolling 2FA 6-digit code screen */
// #define NUM_2FA_DIGITS 6
// #define UPDATE_INTERVAL_2FA 1000
// #define ANIM_DURATION 3500

static lv_style_t roller_style;
static lv_style_t selected_style;
static lv_style_t item_style;

/* Set the array to store the screen reference pointers */
lv_obj_t * o_objects[NUM_SCREENS];

/* Set the BACK-TO-HOME array to use in a custom back button for this app */
static lv_obj_t * back_to_home_screen[NUM_SCREENS];

/* This is the primary "home page" element in this app */
static const int back_to_home = 0;

/* This is the main Device List screen showing all devices and their statuses */
static const int permissions_screen = 1;

/* This is the main iPhone Device Control screen */
static const int iphone_control_screen = 2;

/* This is the main iPhone Device Control screen */
static const int ipad_control_screen = 3;

/* This is the main iPhone Device Control screen */
static const int mac_control_screen = 4;

/* Place all container definitions here to ensure all data can be found throughout */
lv_obj_t * oserver_device_list_container;
lv_obj_t * device_permissions_view_container;
lv_obj_t * iphone_config_container;
lv_obj_t * frenchi_loco_mac_config_container;
lv_obj_t * ipad_config_container;
// lv_obj_t * disabled_pick_list_container;
// lv_obj_t * pairing_container;

/* Counters */
static int ttl_items;
static int ttl_device_pairing_items = 0;
static int ttl_device_control_items = 8; // Fixed list from Guillaume so i am just gonna hard code for now

/* Primary 2FA array to store the labels for each digit */
// static lv_obj_t *digit_labels[NUM_2FA_DIGITS];
// static lv_obj_t *digit_rollers[NUM_2FA_DIGITS];

/* Set variables to determine total number of items per list */
static int device_item;    /* 00.h */
static int device_record;

/* Icon and label objects here */
static lv_obj_t * device_label[];
static lv_obj_t * device_perms[];
static lv_obj_t * device_config_icon[];
static lv_obj_t * device_control_icon[];
static lv_obj_t * device_icon[];
static lv_obj_t * device_status[];
static lv_obj_t * device_add[];
static lv_obj_t * device_item_overlay[];
static lv_obj_t * control_item_name[];
static lv_obj_t * control_list_status[];
static lv_obj_t * control_item_overlay[];

/* Set variables for all the contacts content fields: ID, NAME, EMAIL, PHONE, etc */
static lv_obj_t * list_item_tail[];
static lv_obj_t * list_item_separator[];

/* Set style references */
static lv_style_t back_button_style;
static lv_style_t name_style_20;
// static lv_style_t name_style_24;
static lv_style_t name_style_32;

static lv_style_t label_style;
static lv_style_t italic_style;

// static lv_style_t wrap_content_style;

/***  Init styles specific  ***/
static void init_styles() {
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    lv_style_init(&name_style_20);
    lv_style_set_text_font(&name_style_20, &NeueHaasDisplayLight_20);

    // lv_style_init(&name_style_24);
    // lv_style_set_text_font(&name_style_24, &NeueHaasDisplayLight_24);

    lv_style_init(&name_style_32);
    lv_style_set_text_font(&name_style_32, &NeueHaasDisplayLight_32);

    lv_style_init(&label_style);
    lv_style_init(&italic_style);

    lv_style_set_text_font(&label_style, &NeueHaasDisplayLight_24);
    lv_style_set_text_font(&italic_style, &SaolDisplayRegularItalic_26);

    lv_style_init(&roller_style);
    lv_style_init(&selected_style);
    lv_style_init(&item_style);
}

static screen_scroll_overlay_cb(lv_event_t * e) {
    int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
    printf("EXEC :: screen_scroll_overlay_cb() [%d]\n\n",screen_index);
}

// static __attribute__((unused)) void image_click_event_cb(lv_event_t * e) {
// // static void image_click_event_cb(lv_event_t * e) {

//     // lv_obj_add_event_cb(calendar_1, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_1);  // Use this for debugging
//     int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
//     printf("EXEC :: scroll_to_screen() [%d]\n\n",screen_index);

//     // lv_obj_t * img_to_update = (lv_obj_t *) lv_event_get_user_data(e);

//     // lv_obj_add_event_cb(button_overlay[scr_nbr], scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)scr_nbr);
//     // int list_item_number_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data

//     // int index = (int)(intptr_t) lv_obj_get_user_data(img_to_update);
//     // printf("EXEC :: index [%d]\n\n",index);


//     // const char *screen_index = (const char *)lv_event_get_user_data(e);
//     // device_pairing_item * found_info = find_device_by_id(screen_index);
//     // printf("clicked name: %s   id: %d\n", found_info->device_name, found_info->id);
// }

/* Scroll to the home screen as the final step in the settings app launch */
static void scroll_to_home() {
    printf("EXEC :: scroll_to_home()\n\n");
    lv_obj_scroll_to_view(o_objects[back_to_home], LV_ANIM_OFF);
}

/* Scroll to screen clicked in the clickback call */
static void scroll_to_screen(lv_event_t* e) {
    int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
    printf("EXEC :: scroll_to_screen() [%d]\n\n",screen_index);
    lv_obj_scroll_to_view(o_objects[screen_index], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

static void calc_dataset_items() {
    /* Calculate total list items */
    // printf("\nCalculate records...\n");
    for(ttl_items = 0; !is_end(device_00_list[ttl_items].device_id); ttl_items++) {
        ttl_device_pairing_items = ttl_items+1;
        // printf("Item count: %d -- device_id: %s\n",ttl_device_pairing_items,device_00_list[ttl_items].device_id);
    }
    // printf("\nTotal Records: %d\n\n",ttl_device_pairing_items);

    /* Build the Calendar record list for display */
    for(int j = 0; j < ttl_device_pairing_items; j++) {
        if(is_end(device_00_list[j].device_id)) {
            // printf("item: %d -- device_name: %s\n",j,device_00_list[j].device_name);
            break;
        } else {
            // printf("device_id: %s -- device_name: %s\n",device_00_list[j].device_id,device_00_list[j].device_name);
            int dev = NULL;
        }
    }
}

static int calc_scroll_height(int ttl_rows) {
    // printf("\n\nCalc Scroll Rows: %d\n",ttl_rows);
    ttl_height = ttl_rows * device_list_offset_value;
    // printf("Calc Scroll Height: %d\n",ttl_height);
    return ttl_height;
}

static void populate_device_list_container(void) {
/***  POPULATE :: oserver_00_view_page  ***/

    /* Clear existing rows from the container first */
    if (oserver_device_list_container != NULL) {
        // printf("PICK LIST: is full\n");
        lv_obj_clean(oserver_device_list_container);
    } else {
        // printf("PICK LIST: is empty\n");
    }

    /* Calculate the entire "screen height" and "screen offset" for the scroll-overlay */
    ttl_calc_overlay_height = calc_scroll_height(ttl_device_pairing_items);
    // printf("\n\nCalc Scroll Height: %d\n",ttl_calc_overlay_height);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(oserver_device_list_container, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(oserver_device_list_container, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 0;
    // printf("Device page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    o_objects[scr_nbr] = oserver_device_list_container;
    lv_obj_set_style_bg_img_src(oserver_device_list_container, &Background, 0);

/***  HEADING ELEMENTS  ***/
    render_back_button(oserver_device_list_container, (back_button_cb_t)back_home_button_cb);

    /* Add Device button overlay */
    lv_obj_t * add_device_button_overlay = lv_btn_create(oserver_device_list_container);
    lv_obj_set_size(add_device_button_overlay, 130, 50);
    lv_obj_set_style_opa(add_device_button_overlay, LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(add_device_button_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)permissions_screen);
    lv_obj_align(add_device_button_overlay, LV_ALIGN_TOP_MID, 120, 20);  // This is first object displayed on the screen

    /* Add Device button */
    lv_obj_t * add_device_image = lv_img_create(oserver_device_list_container);
    lv_img_set_src(add_device_image, &Icon_Filter_Button);
    lv_obj_align(add_device_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(oserver_device_list_container);
    lv_img_set_src(page_header, &O_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_obj_t * list_name = lv_label_create(oserver_device_list_container);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 112);
    lv_label_set_text(list_name, "List of devices");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* The WiFi indicator */
    lv_obj_t * wifi_symbol = lv_img_create(oserver_device_list_container);
    lv_img_set_src(wifi_symbol, &Icon_WiFi_White);
    lv_obj_align(wifi_symbol, LV_ALIGN_TOP_LEFT, 280, 112);

    /* The Bluetooth indicator */
    lv_obj_t * bt_symbol = lv_img_create(oserver_device_list_container);
    lv_img_set_src(bt_symbol, &Icon_Bluetooth_White);
    lv_obj_align(bt_symbol, LV_ALIGN_TOP_LEFT, 305, 112);

    /* The NFC indicator */
    lv_obj_t * nfc_symbol = lv_img_create(oserver_device_list_container);
    lv_img_set_src(nfc_symbol, &Icon_NFC_White);
    lv_obj_align(nfc_symbol, LV_ALIGN_TOP_LEFT, 330, 112);
    lv_obj_set_style_opa(nfc_symbol, LV_OPA_40, LV_PART_MAIN);


    /* Full screen overlay to enable scolling the main page vertically */
    lv_obj_t * screen_scroll_overlay = lv_img_create(oserver_device_list_container);
    lv_obj_set_size(screen_scroll_overlay, 350, ttl_calc_overlay_height);
    lv_obj_align(screen_scroll_overlay, LV_ALIGN_TOP_LEFT, 10, 140);
    lv_obj_set_style_opa(screen_scroll_overlay, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_add_flag(screen_scroll_overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(screen_scroll_overlay, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(screen_scroll_overlay, screen_scroll_overlay_cb, LV_EVENT_CLICKED, NULL);

    /* Set the list_item_separator and entry_separator objects here */
    // lv_obj_t * list_item_tail[ttl_device_pairing_items];
    list_item_tail[ttl_device_pairing_items];

    int offset = 0;
    int device_list_item = 0;

    /* Populate the container with current data from device_items_00 struct */
    for(device_list_item = 0; device_list_item < ttl_device_pairing_items; device_list_item++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        offset = device_list_item * 90;

        /* Add a list item separator just beneath the page label item */
        lv_obj_t * list_item_separator = lv_img_create(oserver_device_list_container);
        lv_img_set_src(list_item_separator, &Linez);
        lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 150 + offset);

        /* Set the device_type_icon image */
        device_icon[device_list_item] = lv_img_create(oserver_device_list_container);
        lv_img_set_src(device_icon[device_list_item], device_00_list[device_list_item].device_type_icon);
        if(device_00_list[device_list_item].device_type == "tablet" ) {
            lv_obj_align(device_icon[device_list_item], LV_ALIGN_TOP_LEFT, 42, 176 + offset);
        } else if(device_00_list[device_list_item].device_type == "phone") {
            lv_obj_align(device_icon[device_list_item], LV_ALIGN_TOP_LEFT, 44, 176 + offset);
        } else {
            lv_obj_align(device_icon[device_list_item], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 180 + offset);
        }

        /* Add the device name label */
        device_label[device_list_item] = lv_label_create(oserver_device_list_container);
        lv_label_set_recolor(device_label[device_list_item], true);
        lv_label_set_text(device_label[device_list_item], device_00_list[device_list_item].device_name);
        lv_obj_set_style_text_color(device_label[device_list_item], lv_color_white(), 0);
        lv_obj_set_style_text_font(device_label[device_list_item], &NeueHaasDisplayLight_24, LV_PART_MAIN);
        lv_obj_align(device_label[device_list_item], LV_ALIGN_TOP_LEFT, 102, 172 + offset);

        /* Add the device permissions / owner type label */
        device_perms[device_list_item] = lv_label_create(oserver_device_list_container);
        lv_label_set_recolor(device_perms[device_list_item], true);
        lv_label_set_text(device_perms[device_list_item], device_00_list[device_list_item].device_perms);
        lv_obj_set_style_text_color(device_perms[device_list_item], lv_color_hex(O_GREY_COLOR), 0);
        lv_obj_set_style_text_font(device_perms[device_list_item], &NeueHaasDisplayLight_24, LV_PART_MAIN);
        lv_obj_align(device_perms[device_list_item], LV_ALIGN_TOP_LEFT, 102, 200 + offset);

        /* Set the device_status image */
        device_status[device_list_item] = lv_img_create(oserver_device_list_container);

        /* When creating the list items, use the current status stored within the included device_00_list struct */
        if(!device_00_list[device_list_item].device_state) {
            lv_img_set_src(device_status[device_list_item], device_00_list[device_list_item].device_disabled_icon);
            lv_obj_align(device_status[device_list_item], LV_ALIGN_TOP_RIGHT, NORMAL_PAD_RIGHT, 190 + offset);
            lv_obj_set_style_opa(device_status[device_list_item], LV_OPA_90, LV_PART_MAIN);
        } else {
            lv_img_set_src(device_status[device_list_item], device_00_list[device_list_item].device_enabled_icon);
            lv_obj_align(device_status[device_list_item], LV_ALIGN_TOP_RIGHT, -3, 162 + offset);
        }
    }

    /* Add a list item separator line at the end of the list item */
    list_item_tail[device_list_item] = lv_img_create(oserver_device_list_container);
    lv_img_set_src(list_item_tail[device_list_item], &Linez);
    lv_obj_align(list_item_tail[device_list_item], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 246 + offset);

}

/***  SCREEN 00 - O Server Device List page  ***/
static void oserver_00_view(lv_obj_t * oserver_00_view_page) {
    // printf("Loading oserver_00_view page...\n");

    /* Define the main container to hold all of the devices (enabled and disabled) */
    oserver_device_list_container = lv_img_create(oserver_00_view_page);

    /* Populate the container with the most up to date list of enabled and disabed devices */
    populate_device_list_container();
}

/***  SCREEN 01 - Device permissions view page  ***/
static void oserver_01_view(lv_obj_t * oserver_01_view_page) {
    printf("Loading oserver_01_view page...\n");

    device_permissions_view_container = lv_img_create(oserver_01_view_page);

    /* Calculate the entire "screen height" and "screen offset" for the scroll-overlay */
    ttl_calc_overlay_height = calc_scroll_height(ttl_device_pairing_items);
    // printf("\n\nCalc Scroll Height: %d\n",ttl_calc_overlay_height);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(device_permissions_view_container, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(device_permissions_view_container, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 1;
    // printf("Device page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    o_objects[scr_nbr] = device_permissions_view_container;
    lv_obj_set_style_bg_img_src(device_permissions_view_container, &Background, 0);

/***  HEADING ELEMENTS  ***/
    // render_back_button(device_permissions_view_container, (back_button_cb_t)back_home_button_cb);
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    lv_obj_t * back_to_device_list = lv_btn_create(device_permissions_view_container);
    lv_obj_set_size(back_to_device_list, 130, 50);
    lv_obj_set_style_opa(back_to_device_list, LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_device_list, scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_align(back_to_device_list, LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(device_permissions_view_container);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(device_permissions_view_container);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(device_permissions_view_container);
    lv_img_set_src(page_header, &O_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_obj_t * list_name = lv_label_create(device_permissions_view_container);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 112);
    lv_label_set_text(list_name, "Devices connected");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* The WiFi indicator */
    lv_obj_t * wifi_symbol = lv_img_create(device_permissions_view_container);
    lv_img_set_src(wifi_symbol, &Icon_WiFi_White);
    lv_obj_align(wifi_symbol, LV_ALIGN_TOP_LEFT, 280, 112);

    /* The Bluetooth indicator */
    lv_obj_t * bt_symbol = lv_img_create(device_permissions_view_container);
    lv_img_set_src(bt_symbol, &Icon_Bluetooth_White);
    lv_obj_align(bt_symbol, LV_ALIGN_TOP_LEFT, 305, 112);

    /* The NFC indicator */
    lv_obj_t * nfc_symbol = lv_img_create(device_permissions_view_container);
    lv_img_set_src(nfc_symbol, &Icon_NFC_White);
    lv_obj_align(nfc_symbol, LV_ALIGN_TOP_LEFT, 330, 112);
    lv_obj_set_style_opa(nfc_symbol, LV_OPA_40, LV_PART_MAIN);

    /* Full screen overlay to enable scolling the main page vertically */
    lv_obj_t * screen_scroll_overlay = lv_img_create(device_permissions_view_container);
    lv_obj_set_size(screen_scroll_overlay, 350, ttl_calc_overlay_height);
    lv_obj_align(screen_scroll_overlay, LV_ALIGN_TOP_LEFT, 10, 140);
    lv_obj_set_style_opa(screen_scroll_overlay, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_add_flag(screen_scroll_overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(screen_scroll_overlay, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(screen_scroll_overlay, screen_scroll_overlay_cb, LV_EVENT_CLICKED, NULL);

    /* Set the list_item_separator and entry_separator objects here */
    // lv_obj_t * list_item_tail[ttl_device_pairing_items];
    list_item_tail[ttl_device_pairing_items];

    int offset = 0;
    int device_list_item = 0;

    /* Populate the container with current data from device_items_00 struct */
    for(device_list_item = 0; device_list_item < ttl_device_pairing_items; device_list_item++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        offset = device_list_item * 145;

        /* Add a list item separator just beneath the page label item */
        lv_obj_t * list_item_separator = lv_img_create(device_permissions_view_container);
        lv_img_set_src(list_item_separator, &Linez);
        lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 150 + offset);

        /* View Device Configuration Screen button overlay */
        lv_obj_t * view_device_config_button_overlay = lv_btn_create(device_permissions_view_container);
        lv_obj_set_size(view_device_config_button_overlay, 320, 140);
        lv_obj_set_style_opa(view_device_config_button_overlay, LV_OPA_0, LV_PART_MAIN);
        lv_obj_align(view_device_config_button_overlay, LV_ALIGN_TOP_MID, NARROW_PAD_LEFT, 155 + offset);  // This is first object displayed on the screen

        /* Set the device_type_icon image */
        device_icon[device_list_item] = lv_img_create(device_permissions_view_container);
        lv_img_set_src(device_icon[device_list_item], device_00_list[device_list_item].device_type_icon);
        if(device_00_list[device_list_item].device_type == "tablet" ) {
            lv_obj_align(device_icon[device_list_item], LV_ALIGN_TOP_LEFT, 42, 176 + offset);
            lv_obj_add_event_cb(view_device_config_button_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)ipad_control_screen);
        } else if(device_00_list[device_list_item].device_type == "phone") {
            lv_obj_align(device_icon[device_list_item], LV_ALIGN_TOP_LEFT, 44, 176 + offset);
            lv_obj_add_event_cb(view_device_config_button_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)iphone_control_screen);
        } else {
            lv_obj_align(device_icon[device_list_item], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 180 + offset);
            lv_obj_add_event_cb(view_device_config_button_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)mac_control_screen);
        }

        /* Add the device name label */
        device_label[device_list_item] = lv_label_create(device_permissions_view_container);
        lv_label_set_recolor(device_label[device_list_item], true);
        lv_label_set_text(device_label[device_list_item], device_00_list[device_list_item].device_name);
        lv_obj_set_style_text_color(device_label[device_list_item], lv_color_white(), 0);
        lv_obj_set_style_text_font(device_label[device_list_item], &NeueHaasDisplayLight_24, LV_PART_MAIN);
        lv_obj_align(device_label[device_list_item], LV_ALIGN_TOP_LEFT, 102, 172 + offset);

        /* Add the device permissions / owner type label */
        device_perms[device_list_item] = lv_label_create(device_permissions_view_container);
        lv_label_set_recolor(device_perms[device_list_item], true);
        lv_label_set_text(device_perms[device_list_item], device_00_list[device_list_item].device_perms);
        lv_obj_set_style_text_color(device_perms[device_list_item], lv_color_hex(O_GREY_COLOR), 0);
        lv_obj_set_style_text_font(device_perms[device_list_item], &NeueHaasDisplayLight_24, LV_PART_MAIN);
        lv_obj_align(device_perms[device_list_item], LV_ALIGN_TOP_LEFT, 102, 200 + offset);

        /* Set the device_type_icon image */
        device_config_icon[device_list_item] = lv_img_create(device_permissions_view_container);
        lv_img_set_src(device_config_icon[device_list_item], &Icon_Device_Configuration);
        lv_obj_align(device_config_icon[device_list_item], LV_ALIGN_TOP_RIGHT, -25, 172 + offset);

        /* Set the device_type_icon image */
        device_control_icon[device_list_item] = lv_img_create(device_permissions_view_container);
        if(device_00_list[device_list_item].device_control == "total") {
            lv_img_set_src(device_control_icon[device_list_item], &Icon_Device_Control_Total);
            lv_obj_align(device_control_icon[device_list_item], LV_ALIGN_TOP_RIGHT, -28, 232 + offset);
        } else if(device_00_list[device_list_item].device_control == "neutral") {
            lv_img_set_src(device_control_icon[device_list_item], &Icon_Device_Control_Neutral);
            lv_obj_align(device_control_icon[device_list_item], LV_ALIGN_TOP_RIGHT, -28, 232 + offset);
        } else {
            lv_img_set_src(device_control_icon[device_list_item], &Icon_Device_Control_Synchronisation);
            lv_obj_align(device_control_icon[device_list_item], LV_ALIGN_TOP_RIGHT, -28, 232 + offset);
        }
    }

    /* Add a list item separator line at the end of the list item */
    list_item_tail[device_list_item] = lv_img_create(device_permissions_view_container);
    lv_img_set_src(list_item_tail[device_list_item], &Linez);
    lv_obj_align(list_item_tail[device_list_item], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 246 + offset);
}

/***  SCREEN 02 - iPhone configuration view page  ***/
static void oserver_02_view(lv_obj_t * oserver_02_view_page) {
    printf("Loading oserver_02_view page...\n");

    iphone_config_container = lv_img_create(oserver_02_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(iphone_config_container, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(iphone_config_container, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 2;
    // printf("Device page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    o_objects[scr_nbr] = iphone_config_container;
    lv_obj_set_style_bg_img_src(iphone_config_container, &Background, 0);

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    lv_obj_t * back_to_device_list = lv_btn_create(iphone_config_container);
    lv_obj_set_size(back_to_device_list, 130, 50);
    lv_obj_set_style_opa(back_to_device_list, LV_OPA_0, LV_PART_MAIN);
    // lv_obj_add_event_cb(back_to_device_list, scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(back_to_device_list, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)permissions_screen);
    lv_obj_align(back_to_device_list, LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(iphone_config_container);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(iphone_config_container);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_label_create(iphone_config_container);
    lv_label_set_recolor(page_header, true);
    lv_label_set_text(page_header, "iPhone Demo");
    lv_obj_set_style_text_color(page_header, lv_color_white(), 0);
    lv_obj_set_style_text_font(page_header, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_obj_t * list_name = lv_label_create(iphone_config_container);
    lv_label_set_recolor(list_name, true);
    lv_label_set_text(list_name, "Configuration");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 112);

    /* Set the list_item_separator and entry_separator objects here */
    // lv_obj_t * list_item_tail[ttl_device_control_items];
    // list_item_tail[ttl_device_control_items];

    int offset = 0;
    int device_list_item = 0;

    /* Populate the container with current data from device_items_00 struct */
    for(device_list_item = 0; device_list_item < ttl_device_control_items; device_list_item++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        offset = device_list_item * 70;

        /* Add a list item separator just beneath the page label item */
        lv_obj_t * list_item_separator = lv_img_create(iphone_config_container);
        lv_img_set_src(list_item_separator, &Linez);
        lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 150 + offset);

        /* Device control item overlay */
        control_item_overlay[device_list_item] = lv_btn_create(iphone_config_container);
        lv_obj_set_size(control_item_overlay[device_list_item], 350, 60);
        lv_obj_set_style_opa(control_item_overlay[device_list_item], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(control_item_overlay[device_list_item], screen_scroll_overlay_cb, LV_EVENT_CLICKED, (void*)(size_t)device_list_item);
        lv_obj_align(control_item_overlay[device_list_item], LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 155 + offset);  // This is first object displayed on the screen

        /* Add the device control item label */
        control_item_name[device_list_item] = lv_label_create(iphone_config_container);
        lv_label_set_recolor(control_item_name[device_list_item], true);
        lv_label_set_text(control_item_name[device_list_item], device_01_list[device_list_item].device_name);
        lv_obj_set_style_text_color(control_item_name[device_list_item], lv_color_white(), 0);
        lv_obj_set_style_text_font(control_item_name[device_list_item], &NeueHaasDisplayLight_24, LV_PART_MAIN);
        lv_obj_align(control_item_name[device_list_item], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 175 + offset);

        control_list_status[device_list_item] = lv_img_create(iphone_config_container);
        if(device_01_list[device_list_item].device_name == "Videos" || device_01_list[device_list_item].device_name == "Music" || device_01_list[device_list_item].device_name == "Files") {
            lv_img_set_src(control_list_status[device_list_item], &Icon_Device_Control_Off);
        } else {
            lv_img_set_src(control_list_status[device_list_item], &Icon_Device_Control_On);
        }
        lv_obj_align(control_list_status[device_list_item], LV_ALIGN_TOP_RIGHT, NORMAL_PAD_RIGHT, 170 + offset);
    }

    /* Add a list item separator just beneath the last item in the list */
    lv_obj_t * list_item_separator = lv_img_create(iphone_config_container);
    lv_img_set_src(list_item_separator, &Linez);
    lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 215 + offset);

}

/***  SCREEN 03 - iPad configuration view page  ***/
static void oserver_03_view(lv_obj_t * oserver_03_view_page) {
    printf("Loading oserver_03_view page...\n");

    ipad_config_container = lv_img_create(oserver_03_view_page);

    /* Calculate the entire "screen height" and "screen offset" for the scroll-overlay */
    // ttl_calc_overlay_height = calc_scroll_height(ttl_device_pairing_items);
    // printf("\n\nCalc Scroll Height: %d\n",ttl_calc_overlay_height);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(ipad_config_container, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(ipad_config_container, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 3;
    // printf("Device page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    o_objects[scr_nbr] = ipad_config_container;
    lv_obj_set_style_bg_img_src(ipad_config_container, &Background, 0);

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    lv_obj_t * back_to_device_list = lv_btn_create(ipad_config_container);
    lv_obj_set_size(back_to_device_list, 130, 50);
    lv_obj_set_style_opa(back_to_device_list, LV_OPA_0, LV_PART_MAIN);
    // lv_obj_add_event_cb(back_to_device_list, scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(back_to_device_list, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)permissions_screen);
    lv_obj_align(back_to_device_list, LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(ipad_config_container);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(ipad_config_container);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_label_create(ipad_config_container);
    lv_label_set_recolor(page_header, true);
    lv_label_set_text(page_header, "iPad Demo");
    lv_obj_set_style_text_color(page_header, lv_color_white(), 0);
    lv_obj_set_style_text_font(page_header, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_obj_t * list_name = lv_label_create(ipad_config_container);
    lv_label_set_recolor(list_name, true);
    lv_label_set_text(list_name, "Configuration");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 112);

    int offset = 0;
    int device_list_item = 0;

    /* Populate the container with current data from device_items_00 struct */
    for(device_list_item = 0; device_list_item < ttl_device_control_items; device_list_item++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        offset = device_list_item * 70;

        /* Add a list item separator just beneath the page label item */
        lv_obj_t * list_item_separator = lv_img_create(ipad_config_container);
        lv_img_set_src(list_item_separator, &Linez);
        lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 150 + offset);

        /* Device control item overlay */
        control_item_overlay[device_list_item] = lv_btn_create(ipad_config_container);
        lv_obj_set_size(control_item_overlay[device_list_item], 350, 60);
        lv_obj_set_style_opa(control_item_overlay[device_list_item], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(control_item_overlay[device_list_item], screen_scroll_overlay_cb, LV_EVENT_CLICKED, (void*)(size_t)device_list_item);
        lv_obj_align(control_item_overlay[device_list_item], LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 155 + offset);  // This is first object displayed on the screen

        /* Add the device control item label */
        control_item_name[device_list_item] = lv_label_create(ipad_config_container);
        lv_label_set_recolor(control_item_name[device_list_item], true);
        lv_label_set_text(control_item_name[device_list_item], device_01_list[device_list_item].device_name);
        lv_obj_set_style_text_color(control_item_name[device_list_item], lv_color_white(), 0);
        lv_obj_set_style_text_font(control_item_name[device_list_item], &NeueHaasDisplayLight_24, LV_PART_MAIN);
        lv_obj_align(control_item_name[device_list_item], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 175 + offset);

        control_list_status[device_list_item] = lv_img_create(ipad_config_container);
        lv_img_set_src(control_list_status[device_list_item], &Icon_Device_Control_Off);
        lv_obj_align(control_list_status[device_list_item], LV_ALIGN_TOP_RIGHT, NORMAL_PAD_RIGHT, 170 + offset);
    }

    /* Add a list item separator just beneath the last item in the list */
    lv_obj_t * list_item_separator = lv_img_create(ipad_config_container);
    lv_img_set_src(list_item_separator, &Linez);
    lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 215 + offset);
}

/***  SCREEN 04 - Frenchi Loco Mac configuration view page  ***/
static void oserver_04_view(lv_obj_t * oserver_04_view_page) {
    printf("Loading oserver_04_view page...\n");

    frenchi_loco_mac_config_container = lv_img_create(oserver_04_view_page);

    /* Calculate the entire "screen height" and "screen offset" for the scroll-overlay */
    // ttl_calc_overlay_height = calc_scroll_height(ttl_device_pairing_items);
    // printf("\n\nCalc Scroll Height: %d\n",ttl_calc_overlay_height);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(frenchi_loco_mac_config_container, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(frenchi_loco_mac_config_container, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 4;
    // printf("Device page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    o_objects[scr_nbr] = frenchi_loco_mac_config_container;
    lv_obj_set_style_bg_img_src(frenchi_loco_mac_config_container, &Background, 0);

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    lv_obj_t * back_to_device_list = lv_btn_create(frenchi_loco_mac_config_container);
    lv_obj_set_size(back_to_device_list, 130, 50);
    lv_obj_set_style_opa(back_to_device_list, LV_OPA_0, LV_PART_MAIN);
    // lv_obj_add_event_cb(back_to_device_list, scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(back_to_device_list, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)permissions_screen);
    lv_obj_align(back_to_device_list, LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(frenchi_loco_mac_config_container);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(frenchi_loco_mac_config_container);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_label_create(frenchi_loco_mac_config_container);
    lv_label_set_recolor(page_header, true);
    lv_label_set_text(page_header, "Frenchi Loco Mac");
    lv_obj_set_style_text_color(page_header, lv_color_white(), 0);
    lv_obj_set_style_text_font(page_header, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_obj_t * list_name = lv_label_create(frenchi_loco_mac_config_container);
    lv_label_set_recolor(list_name, true);
    lv_label_set_text(list_name, "Configuration");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 112);

    /* Set the list_item_separator and entry_separator objects here */
    // lv_obj_t * list_item_tail[ttl_device_control_items];
    // list_item_tail[ttl_device_control_items];

    int offset = 0;
    int device_list_item = 0;

    /* Populate the container with current data from device_items_00 struct */
    for(device_list_item = 0; device_list_item < ttl_device_control_items; device_list_item++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        offset = device_list_item * 70;

        /* Add a list item separator just beneath the page label item */
        lv_obj_t * list_item_separator = lv_img_create(frenchi_loco_mac_config_container);
        lv_img_set_src(list_item_separator, &Linez);
        lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 150 + offset);

        /* Device control item overlay */
        control_item_overlay[device_list_item] = lv_btn_create(frenchi_loco_mac_config_container);
        lv_obj_set_size(control_item_overlay[device_list_item], 350, 60);
        lv_obj_set_style_opa(control_item_overlay[device_list_item], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(control_item_overlay[device_list_item], screen_scroll_overlay_cb, LV_EVENT_CLICKED, (void*)(size_t)device_list_item);
        lv_obj_align(control_item_overlay[device_list_item], LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 155 + offset);  // This is first object displayed on the screen

        /* Add the device control item label */
        control_item_name[device_list_item] = lv_label_create(frenchi_loco_mac_config_container);
        lv_label_set_recolor(control_item_name[device_list_item], true);
        lv_label_set_text(control_item_name[device_list_item], device_01_list[device_list_item].device_name);
        lv_obj_set_style_text_color(control_item_name[device_list_item], lv_color_white(), 0);
        lv_obj_set_style_text_font(control_item_name[device_list_item], &NeueHaasDisplayLight_24, LV_PART_MAIN);
        lv_obj_align(control_item_name[device_list_item], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 175 + offset);

        control_list_status[device_list_item] = lv_img_create(frenchi_loco_mac_config_container);
        if(device_01_list[device_list_item].device_name == "Gallery" || device_01_list[device_list_item].device_name == "Videos" || device_01_list[device_list_item].device_name == "Music" || device_01_list[device_list_item].device_name == "Files") {
            lv_img_set_src(control_list_status[device_list_item], &Icon_Device_Control_On);
        } else {
            lv_img_set_src(control_list_status[device_list_item], &Icon_Device_Control_Off);
        }
        lv_obj_align(control_list_status[device_list_item], LV_ALIGN_TOP_RIGHT, NORMAL_PAD_RIGHT, 170 + offset);
    }

    /* Add a list item separator just beneath the last item in the list */
    lv_obj_t * list_item_separator = lv_img_create(frenchi_loco_mac_config_container);
    lv_img_set_src(list_item_separator, &Linez);
    lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 215 + offset);

    /* Populate the container with the 2fa code */
    // create_2fa_display();

    /* Populate the container with the 2fa code */
    // create_2fa_display();

}

void oserver_menu_setup(void) {
    printf("OSERVER MENU setup...\n");

    init_styles();

    /* Set the ttl_items counter to match the number of elements in the struct */
    calc_dataset_items();

    lv_obj_t * oserver_page = lv_obj_create(NULL);
    menu_dispatch_table[OSERVER_VEC] = oserver_page;

    lv_obj_center(oserver_page);
    lv_obj_set_style_bg_color(oserver_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(oserver_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(oserver_page, true, 3);
    lv_obj_set_scroll_dir(oserver_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(oserver_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(oserver_page, LV_OBJ_FLAG_SCROLLABLE | LV_SCROLLBAR_MODE_ON);

    /* DEVICE VIEW: Display the device-specific permissions information for the devices paired with the o mini server */
    printf("\nOSERVER_01_VIEW launch...\n");
    oserver_01_view(oserver_page);

    /* DEVICE VIEW: Display the iPhone Configuration */
    printf("\nOSERVER_02_VIEW launch...\n");
    oserver_02_view(oserver_page);

    /* DEVICE VIEW: Display the Frenchi Loco Mac Configuration screen */
    printf("\nOSERVER_03_VIEW launch...\n");
    oserver_03_view(oserver_page);

    /* DEVICE VIEW: Display the iPad Configuration screen */
    printf("\nOSERVER_04_VIEW launch...\n");
    oserver_04_view(oserver_page);

    /* MAIN O SERVER DEVICE LIST VIEW: Display the Device List with each device loading from the entire device_00_view at the currently loaded state */
    printf("\nOSERVER_00_VIEW launch...\n");
    oserver_00_view(oserver_page);

    // // Assign the callback
    lv_obj_add_event_cb(oserver_page, populate_device_list_container, LV_EVENT_SCREEN_LOADED, NULL);

    scroll_to_home();

}