#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/* Initialize/populate the Calendar list struct */
#include "content/inc/calendar/00.h"   /* Month-based List - Specific appointments for each month (July / August / September ) data */
#include "content/inc/calendar/01.h"   /* Month List - Specific appointments for July 9th */
#include "content/inc/calendar/02.h"   /* Month List - Specific appointments for July 16th */
#include "content/inc/calendar/03.h"   /* Month List - Specific appointments for August 1st */
#include "content/inc/calendar/04.h"   /* Month List - Specific appointments for August 15th */
#include "content/inc/calendar/05.h"   /* Month List - Specific appointments for September 10th */
#include "content/inc/calendar/06.h"   /* Month List - Specific appointments for September 20th */

/*** TODO
 * 
 * Fix the 'Back' button in the August and September calendars
 * 
***/

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

/* Calendar list and contact ID variables */
#define CALENDAR_ID 0   // This is temporary until the calendar list dataset is being accessed

/* Main background and radio controls declared below */
LV_IMG_DECLARE(Background);
LV_IMG_DECLARE(Icon_Back);
LV_IMG_DECLARE(Icon_WiFi_White);
LV_IMG_DECLARE(Icon_Bluetooth_White);
LV_IMG_DECLARE(Icon_NFC_White);

/* Visual queue iconagraphy like status dots declared below */
LV_IMG_DECLARE(Icon_Settings_Toggle_Off);
LV_IMG_DECLARE(Icon_Settings_Toggle_On);
LV_IMG_DECLARE(Icon_Status_Active);
LV_IMG_DECLARE(Icon_Status_Disable);
LV_IMG_DECLARE(Icon_Power_Button_Yellow);
LV_IMG_DECLARE(Icon_Refresh_Single_Yellow);
LV_IMG_DECLARE(Icon_Bullet_Item);

/* Standard list control iconography declared below */
LV_IMG_DECLARE(Icon_Filter_Button);
LV_IMG_DECLARE(Icon_List_Item_Divider);

LV_IMG_DECLARE(Icon_Filter_White);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Icon_Close_White);
LV_IMG_DECLARE(Time);
LV_IMG_DECLARE(Linez);

/* Calendar Card - Calendar Initials Background */
LV_IMG_DECLARE(Icon_Calendar_Initials_Background);
LV_IMG_DECLARE(Calendar_4_Up);
LV_IMG_DECLARE(Calendar_1_June_2024);
LV_IMG_DECLARE(Calendar_2_July_2024);
LV_IMG_DECLARE(Calendar_3_August_2024);
LV_IMG_DECLARE(Calendar_4_September_2024);
LV_IMG_DECLARE(Icon_Day_1);
LV_IMG_DECLARE(Icon_Day_9);
LV_IMG_DECLARE(Icon_Day_10);
LV_IMG_DECLARE(Icon_Day_15);
LV_IMG_DECLARE(Icon_Day_16);
LV_IMG_DECLARE(Icon_Day_20);
LV_IMG_DECLARE(Icon_Birthday);
LV_IMG_DECLARE(Icon_Phone);
LV_IMG_DECLARE(Icon_Empty_Dude);

/* Main HEADING iconography */
LV_IMG_DECLARE(Calendar_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

LV_FONT_DECLARE(NeueHaasDisplayLight_32);

/***  Calendar Specific Declarations  ***/

/* Set total number of pages / screens -- this includes screen #1 which is the main contacts screen to screen #4 which is the spreadsheets screen */
#define NUM_SCREENS 4

/* Set the array to store the screen reference pointers */
lv_obj_t * calendar_objects[NUM_SCREENS];

/* Set the BACK-TO-HOME array to use in a custom back button for the filesystem app */
static lv_obj_t * back_to_home_screen[NUM_SCREENS] __attribute__((unused));

/* This is the primary "home page" element in the Settings app */
static const int back_to_home = 0;

/* Counters */
static int ttl_items;
static int ttl_calendar_items = 0;
static int cal_ttl;

static int calendar_items_01;
static int calendar_items_02 __attribute__((unused));
static int calendar_items_03 __attribute__((unused));
static int calendar_items_04 __attribute__((unused));
static int calendar_items_05 __attribute__((unused));
static int calendar_items_06 __attribute__((unused));


static int cal_1 = 1;
static int cal_2 = 2;
static int cal_3 = 3;
static int cal_4 = 4;
static int cal_july = 5;
static int cal_august = 6;
static int cal_september = 7;

/* Calendar Card fields required for population */
lv_obj_t * calendar_id;
lv_obj_t * calendar_title;
lv_obj_t * calendar_time_start;
lv_obj_t * calendar_time_end;
lv_obj_t * calendar_time_month;
lv_obj_t * calendar_time_day;
lv_obj_t * calendar_time_year;
lv_obj_t * calendar_description;
lv_obj_t * calendar_repeat;
lv_obj_t * calendar_alert;
lv_obj_t * calendar_show_as;
lv_obj_t * calendar_notes;
lv_obj_t * calendar_event_icon;
lv_obj_t * calendar_type_icon;

/* Set style references */
static lv_style_t back_button_style;
static lv_style_t name_style_20;
static lv_style_t name_style_24;
static lv_style_t name_style_32;

static lv_style_t label_style;
static lv_style_t italic_style;

static lv_style_t wrap_content_style __attribute__((unused));

/***  Init styles specific  ***/
static void init_styles() {
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    lv_style_init(&name_style_20);
    lv_style_set_text_font(&name_style_20, &NeueHaasDisplayLight_20);

    lv_style_init(&name_style_24);
    lv_style_set_text_font(&name_style_24, &NeueHaasDisplayLight_24);

    lv_style_init(&name_style_32);
    lv_style_set_text_font(&name_style_32, &NeueHaasDisplayLight_32);

    lv_style_init(&label_style);
    lv_style_init(&italic_style);

    lv_style_set_text_font(&label_style, &NeueHaasDisplayLight_24);
    lv_style_set_text_font(&italic_style, &SaolDisplayRegularItalic_26);
}

/* Scroll to the home screen as the final step in the settings app launch */
static void scroll_to_home() {
    // printf("EXEC :: scroll_to_home()\n\n");
    lv_obj_scroll_to_view(calendar_objects[back_to_home], LV_ANIM_OFF);
}

/* Scroll to screen clicked in the clickback call */
static void scroll_to_screen(lv_event_t* e) {
    int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
    // printf("EXEC :: scroll_to_screen() [%d]\n\n",screen_index);
    lv_obj_scroll_to_view(calendar_objects[screen_index], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

/* Function to update calendar data on the appointment card screen */
static void update_calendar_card(const char *title, const char *description, const char *time_start, const char *time_end, const char *time_month, const char *time_day, const char *time_year, const char *repeat, const char *alert, const char *event_icon) {
    lv_label_set_text(calendar_title, title);
    lv_label_set_text(calendar_description, description);
    lv_label_set_text(calendar_time_start, time_start);
    lv_label_set_text(calendar_time_end, time_end);
    lv_label_set_text(calendar_time_month, time_month);
    lv_label_set_text(calendar_time_day, time_day);
    lv_label_set_text(calendar_time_year, time_year);
    lv_label_set_text(calendar_repeat, repeat);
    lv_label_set_text(calendar_alert, alert);
    lv_label_set_text(calendar_event_icon, event_icon);
}

/* Function to find a contact by ID */
static calendar_item * find_calendar_by_id(const char *id_to_find) {
    for (size_t i = 0; i < sizeof(calendar_00_list) / sizeof(calendar_item); ++i) {
        if (strcmp(calendar_00_list[i].calendar_id, id_to_find) == 0) {
            return &calendar_00_list[i];
        }
    }
    return NULL;  // Calendar item not found
}

static __attribute__((unused)) void display_appointment_event_cb(lv_event_t * e) {
    const char *screen_index = (const char *)lv_event_get_user_data(e);

    calendar_item *found_appointment = find_calendar_by_id(screen_index);
    update_calendar_card(found_appointment->calendar_title, found_appointment->calendar_description, found_appointment->calendar_time_start, found_appointment->calendar_time_end, found_appointment->calendar_month, found_appointment->calendar_day, found_appointment->calendar_year, found_appointment->calendar_repeat, found_appointment->calendar_alert, found_appointment->calendar_event_icon);

    lv_obj_scroll_to_view(calendar_objects[1], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

// static void calc_dataset_items(lv_event_t * e) {
static void calc_dataset_items() {

    /* Calculate total Calendar records */
    // printf("\nCalculate contact records...\n");
    for(ttl_items = 0; !is_end(calendar_00_list[ttl_items].calendar_id); ttl_items++) {
        ttl_calendar_items = ttl_items+1;
        // printf("Item count: %d -- calendar_id: %s\n",ttl_calendar_items,calendar_00_list[ttl_items].calendar_id);
    }
    // printf("\nTotal Records: %d\n\n",ttl_calendar_items);

    /* Build the Calendar record list for display */
    // printf("Building each Calendar record for display\n");
    for(int j = 0; j < ttl_calendar_items; j++) {
        if(is_end(calendar_00_list[j].calendar_id)) {
            // printf("item: %d -- calendar_notes: %s\n",j,calendar_00_list[j].calendar_notes);
            break;
        } else {
            // printf("calendar_id: %s -- calendar_name: %s\n",calendar_00_list[j].calendar_id,calendar_00_list[j].calendar_name);
        }
    }

    printf("func -- ttl_calendar_items: %d\n", ttl_calendar_items);
}


static void image_click_event_cb(lv_event_t * e) {
    int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
    printf("EXEC :: image_click_event_cb() [%d]\n\n",screen_index);
    // lv_obj_scroll_to_view(crypto_objects[screen_index], LV_ANIM_OFF);
    // lv_event_stop_bubbling(e); // Stop event bubbling

    // lv_event_code_t code = lv_event_get_code(e);
    // lv_obj_t * obj = lv_event_get_target(e);
    // printf("crypto item clicked\n");
}

static __attribute__((unused)) void event_handler(lv_event_t * e) {
    lv_event_code_t code __attribute__((unused)) = lv_event_get_code(e);
    lv_obj_t * obj __attribute__((unused)) = lv_event_get_target(e);
    printf("calendar item clicked\n");

    // if(code == LV_EVENT_VALUE_CHANGED) {
    //     lv_calendar_date_t date;
    //     lv_calendar_get_pressed_date(obj, &date);
    //     if(date.year) {
    //         printf("Clicked date: %02d.%02d.%d\n", date.day, date.month, date.year);
    //     }
    // }
}

static __attribute__((unused)) int calc_scroll_height(int ttl_rows) {
    // printf("\n\nCalc Scroll Rows: %d\n",ttl_rows);
    int ttl_height = ttl_rows * 52;
    // printf("Calc Scroll Height: %d\n",ttl_height);
    return ttl_height;
}

static __attribute__((unused)) int calc_scroll_offset(int ttl_rows) {
    int ttl_offset;
    if(ttl_rows <= 10) {
        ttl_offset = 90;
    } else {
        ttl_offset = ttl_rows * 22;
    }
    // printf("Calc Scroll Offset: %d\n",ttl_offset);
    return ttl_offset;
}

static lv_obj_t * top_of_list_items;

/* Set the BACK-TO-HOME array to use in a custom back button for the Settings app */
lv_obj_t * back_to_calendar[NUM_SCREENS];


/***  SCREEN 00 - Calendar page  ***/
static void calendar_00_view(lv_obj_t * calendar_00_view_page) {
    lv_obj_t * image = lv_img_create(calendar_00_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 0;
    // printf("Calendar page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = image;
    // lv_img_set_src(image, &Background);
    lv_obj_set_style_bg_img_src(image, &Background, 0);

/***  HEADING ELEMENTS  ***/
    render_back_button(image, (back_button_cb_t)back_home_button_cb);


    /* 'Filter' button to filter the text messages */
    // lv_obj_t * filter_image = lv_img_create(image);
    // lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

/***  MAIN LIST ITEMS  ***/
    /* Set the objects for list item separators and overlay elements for each feature here */
    lv_obj_t * list_item_tail[5] __attribute__((unused));
    lv_obj_t * display_feature_overlay __attribute__((unused));

    int calendar_item_overlay_width = 145;
    int calendar_item_overlay_height = 135;

    lv_obj_t * calendar_1 = lv_img_create(image);
    lv_obj_set_size(calendar_1, calendar_item_overlay_width, calendar_item_overlay_height);
    lv_obj_set_style_bg_color(calendar_1, lv_color_hex(0x01a2b1), LV_PART_MAIN);
    lv_obj_set_style_opa(calendar_1, LV_OPA_90, LV_PART_MAIN);
    lv_obj_add_flag(calendar_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(calendar_1, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_1);  // Use this for debugging
    lv_obj_align(calendar_1, LV_ALIGN_TOP_LEFT, 40, 120);

    lv_obj_t * calendar_2 = lv_img_create(image);
    lv_obj_set_size(calendar_2, calendar_item_overlay_width, calendar_item_overlay_height);
    lv_obj_set_style_bg_color(calendar_2, lv_color_hex(0x01a2b1), LV_PART_MAIN);
    lv_obj_set_style_opa(calendar_2, LV_OPA_90, LV_PART_MAIN);
    lv_obj_add_flag(calendar_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(calendar_2, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_2);  // Use this for debugging
    lv_obj_align(calendar_2, LV_ALIGN_TOP_LEFT, 205, 120);

    lv_obj_t * calendar_3 = lv_img_create(image);
    lv_obj_set_size(calendar_3, calendar_item_overlay_width, calendar_item_overlay_height);
    lv_obj_set_style_opa(calendar_3, LV_OPA_90, LV_PART_MAIN);
    lv_obj_add_flag(calendar_3, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(calendar_3, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_3);  // Use this for debugging
    lv_obj_align(calendar_3, LV_ALIGN_TOP_LEFT, 40, 285);

    lv_obj_t * calendar_4 = lv_img_create(image);
    lv_obj_set_size(calendar_4, calendar_item_overlay_width, calendar_item_overlay_height);
    lv_obj_set_style_opa(calendar_4, LV_OPA_90, LV_PART_MAIN);
    lv_obj_add_flag(calendar_4, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(calendar_4, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_4);  // Use this for debugging
    lv_obj_align(calendar_4, LV_ALIGN_TOP_LEFT, 205, 285);

    /* Define the size (width and height) of the clickable area above each month of the 4-up screen */
    lv_obj_t * calendar_4_up = lv_img_create(image);
    lv_img_set_src(calendar_4_up, &Calendar_4_Up);
    lv_obj_align(calendar_4_up, LV_ALIGN_TOP_MID, 0, 120);
}


/***  SCREEN 01 - Calendar MONTH (1) page  ***/
static void calendar_01_view(lv_obj_t * calendar_01_view_page) {
    lv_obj_t * image = lv_img_create(calendar_01_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 1;
    // printf("Calendar page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = image;
    // lv_img_set_src(image, &Background);
    lv_obj_set_style_bg_img_src(image, &Background, 0);

    /* Calculate the total list items and set the variable */
    calc_dataset_items();

/***  Contacts Specific Style Declarations  ***/
    init_styles();

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_calendar[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_calendar[back_to_home], 130, 50);
    lv_obj_set_style_opa(back_to_calendar[back_to_home], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_calendar[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_align(back_to_calendar[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* 'Filter' button to filter the list */
    // lv_obj_t * filter_image = lv_img_create(image);
    // lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

/***  MAIN LIST ITEMS  ***/
    /* Set the objects for list item separators and overlay elements for each feature here */
    lv_obj_t * list_item_tail[5] __attribute__((unused));
    lv_obj_t * display_feature_overlay;
    int ttl_overlay_width = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height = 602;  // Set this to the last lv_obj_align() padding height minus 40

    /* Display full screen height overlay to enable scrolling */
    display_feature_overlay = lv_img_create(image);
    lv_obj_set_size(display_feature_overlay, ttl_overlay_width, ttl_overlay_height);
    lv_obj_set_style_opa(display_feature_overlay, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(display_feature_overlay, image_click_event_cb, LV_EVENT_CLICKED, NULL);  // Use this for debugging
    lv_obj_align(display_feature_overlay, LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 94);

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_calendar_items] __attribute__((unused));

    lv_obj_t * calendar_1 = lv_img_create(image);
    lv_img_set_src(calendar_1, &Calendar_1_June_2024);
    lv_obj_align(calendar_1, LV_ALIGN_TOP_MID, 0, 60);
}

/***  SCREEN 02 - Calendar MONTH (2) page  ***/
static void calendar_02_view(lv_obj_t * calendar_02_view_page) {
    lv_obj_t * image = lv_img_create(calendar_02_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 2;
    // printf("Calendar page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = image;
    // lv_img_set_src(image, &Background);
    lv_obj_set_style_bg_img_src(image, &Background, 0);

/***  Contacts Specific Style Declarations  ***/
    init_styles();

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_calendar[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_calendar[back_to_home], 130, 50);
    lv_obj_set_style_opa(back_to_calendar[back_to_home], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_calendar[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_align(back_to_calendar[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* 'Filter' button to filter the list */
    // lv_obj_t * filter_image = lv_img_create(image);
    // lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

/***  MAIN LIST ITEMS  ***/
    /* Set the objects for list item separators and overlay elements for each feature here */
    lv_obj_t * list_item_tail[5] __attribute__((unused));
    lv_obj_t * display_feature_overlay;
    int ttl_overlay_width = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height = 602;  // Set this to the last lv_obj_align() padding height minus 40

    /* Display full screen height overlay to enable scrolling */
    display_feature_overlay = lv_img_create(image);
    lv_obj_set_size(display_feature_overlay, ttl_overlay_width, ttl_overlay_height);
    lv_obj_set_style_opa(display_feature_overlay, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(display_feature_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_july);  // Use this for debugging
    lv_obj_align(display_feature_overlay, LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 94);

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_calendar_items] __attribute__((unused));

    lv_obj_t * calendar_2 = lv_img_create(image);
    lv_img_set_src(calendar_2, &Calendar_2_July_2024);
    lv_obj_align(calendar_2, LV_ALIGN_TOP_MID, 0, 60);
}

/***  SCREEN 03 - Calendar MONTH (3) page  ***/
static void calendar_03_view(lv_obj_t * calendar_03_view_page) {
    lv_obj_t * image = lv_img_create(calendar_03_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 3;
    // printf("Calendar page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = image;
    // lv_img_set_src(image, &Background);
    lv_obj_set_style_bg_img_src(image, &Background, 0);

/***  Contacts Specific Style Declarations  ***/
    init_styles();

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_calendar[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_calendar[back_to_home], 130, 50);
    lv_obj_set_style_opa(back_to_calendar[back_to_home], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_calendar[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_align(back_to_calendar[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* 'Filter' button to filter the list */
    // lv_obj_t * filter_image = lv_img_create(image);
    // lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

/***  MAIN LIST ITEMS  ***/
    /* Set the objects for list item separators and overlay elements for each feature here */
    lv_obj_t * list_item_tail[5] __attribute__((unused));
    lv_obj_t * display_feature_overlay;
    int ttl_overlay_width = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height = 602;  // Set this to the last lv_obj_align() padding height minus 40

    /* Display full screen height overlay to enable scrolling */
    display_feature_overlay = lv_img_create(image);
    lv_obj_set_size(display_feature_overlay, ttl_overlay_width, ttl_overlay_height);
    lv_obj_set_style_opa(display_feature_overlay, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(display_feature_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_august);
    // lv_obj_add_event_cb(display_feature_overlay, image_click_event_cb, LV_EVENT_CLICKED, NULL);  // Use this for debugging
    lv_obj_align(display_feature_overlay, LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 94);

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_calendar_items] __attribute__((unused));

    lv_obj_t * calendar_3 = lv_img_create(image);
    lv_img_set_src(calendar_3, &Calendar_3_August_2024);
    lv_obj_align(calendar_3, LV_ALIGN_TOP_MID, 0, 60);
}

/***  SCREEN 04 - Calendar MONTH (4) page  ***/
static void calendar_04_view(lv_obj_t * calendar_04_view_page) {
    lv_obj_t * image = lv_img_create(calendar_04_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 4;
    // printf("Calendar page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = image;
    // lv_img_set_src(image, &Background);
    lv_obj_set_style_bg_img_src(image, &Background, 0);

/***  Contacts Specific Style Declarations  ***/
    init_styles();

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_calendar[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_calendar[back_to_home], 130, 50);
    lv_obj_set_style_opa(back_to_calendar[back_to_home], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_calendar[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_align(back_to_calendar[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* 'Filter' button to filter the list */
    // lv_obj_t * filter_image = lv_img_create(image);
    // lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

/***  MAIN LIST ITEMS  ***/
    /* Set the objects for list item separators and overlay elements for each feature here */
    lv_obj_t * list_item_tail[5] __attribute__((unused));
    lv_obj_t * display_feature_overlay;
    int ttl_overlay_width = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height = 602;  // Set this to the last lv_obj_align() padding height minus 40

    /* Display full screen height overlay to enable scrolling */
    display_feature_overlay = lv_img_create(image);
    lv_obj_set_size(display_feature_overlay, ttl_overlay_width, ttl_overlay_height);
    lv_obj_set_style_opa(display_feature_overlay, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(display_feature_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_september);
    // lv_obj_add_event_cb(display_feature_overlay, image_click_event_cb, LV_EVENT_CLICKED, NULL);  // Use this for debugging
    lv_obj_align(display_feature_overlay, LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 94);

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_calendar_items] __attribute__((unused));

    lv_obj_t * calendar_4 = lv_img_create(image);
    lv_img_set_src(calendar_4, &Calendar_4_September_2024);
    lv_obj_align(calendar_4, LV_ALIGN_TOP_MID, 0, 60);
}

/***  SCREEN 05 - Calendar - July Events List page  ***/
static void calendar_05_view(lv_obj_t * calendar_05_view_page) {
    lv_obj_t * image = lv_img_create(calendar_05_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 5;
    // printf("Contacts page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_calendar[2] = lv_btn_create(image);
    lv_obj_set_size(back_to_calendar[2], 130, 50);
    lv_obj_set_style_opa(back_to_calendar[2], LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_calendar[2], scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_2);
    lv_obj_align(back_to_calendar[2], LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    // /* 'Filter' button to filter the text messages */
    // lv_obj_t * filter_image = lv_img_create(image);
    // lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    lv_coord_t offset __attribute__((unused)) = 0;

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_calendar_items];
    lv_obj_t * display_feature_overlay __attribute__((unused));
    int ttl_overlay_width __attribute__((unused)) = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height __attribute__((unused)) = 662;  // Set this to the last lv_obj_align() padding height minus 40

    /* Icon and label objects here */
    lv_obj_t * calendar_event_label[ttl_calendar_items];
    lv_obj_t * calendar_event_start[ttl_calendar_items];
    lv_obj_t * calendar_event_icon[ttl_calendar_items];
    lv_obj_t * calendar_event_next_icon[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * calendar_event_item_overlay[ttl_calendar_items];

/***  JULY CALENDAR ITEM LIST  ***/
    cal_ttl = 0;

    lv_obj_t * month_name_heading = lv_label_create(image);
    lv_label_set_recolor(month_name_heading, true);
    lv_label_set_text(month_name_heading, calendar_00_list[cal_ttl].calendar_month);
    lv_obj_set_style_text_color(month_name_heading, lv_color_hex(O_YELLOW_COLOR), 0);
    lv_obj_set_style_text_font(month_name_heading, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(month_name_heading, LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 102);

    lv_obj_t * day_number_heading = lv_img_create(image);
    // lv_label_set_recolor(day_number_heading, true);
    lv_img_set_src(day_number_heading, &Icon_Day_9);
    lv_obj_align(day_number_heading, LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 138);


    // Add a list item separator line below the list item header
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 212);

    /* Populate screen with Calendar 01.h (09 July 2024) event items */
    for(calendar_items_01 = 0; !is_end(calendar_01_list[calendar_items_01].calendar_id); calendar_items_01++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        int offset = calendar_items_01 * 90;

        /* Calender event list item button overlay */
        calendar_event_item_overlay[calendar_items_01] = lv_btn_create(image);
        lv_obj_set_size(calendar_event_item_overlay[calendar_items_01], 352, 80);
        lv_obj_set_style_opa(calendar_event_item_overlay[calendar_items_01], LV_OPA_TRANSP, LV_PART_MAIN);
        lv_obj_align(calendar_event_item_overlay[calendar_items_01], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 220 + offset);

        // /* Get the contact_id for the item being clicked then set the event click */
        // char * item_id = calendar_01_list[calendar_items_01].calendar_id;
        // lv_obj_add_event_cb(calendar_event_item_overlay[calendar_items_01], display_appointment_event_cb, LV_EVENT_CLICKED, (void *)item_id);  // Use this to select, replace, and then view the content


        calendar_event_icon[calendar_items_01] = lv_img_create(image);
        lv_img_set_src(calendar_event_icon[calendar_items_01], calendar_01_list[calendar_items_01].calendar_type_icon);
        lv_obj_set_style_opa(calendar_event_icon[calendar_items_01], LV_OPA_COVER, LV_PART_MAIN);
        lv_obj_align(calendar_event_icon[calendar_items_01], LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 238 + offset);

        calendar_event_label[calendar_items_01] = lv_label_create(image);
        lv_label_set_recolor(calendar_event_label[calendar_items_01], true);
        lv_label_set_text(calendar_event_label[calendar_items_01], calendar_01_list[calendar_items_01].calendar_title);
        lv_obj_add_style(calendar_event_label[calendar_items_01], &name_style_24, LV_PART_MAIN);
        lv_obj_set_style_text_color(calendar_event_label[calendar_items_01], lv_color_white(), 0);
        lv_obj_align(calendar_event_label[calendar_items_01], LV_ALIGN_TOP_LEFT, REGULAR_ICON_PAD_LEFT, 232 + offset);

        calendar_event_start[calendar_items_01] = lv_label_create(image);
        lv_label_set_recolor(calendar_event_start[calendar_items_01], true);
        lv_label_set_text(calendar_event_start[calendar_items_01], calendar_01_list[calendar_items_01].calendar_time_start);
        lv_obj_add_style(calendar_event_start[calendar_items_01], &name_style_20, LV_PART_MAIN);
        lv_obj_set_style_text_color(calendar_event_start[calendar_items_01], lv_color_hex(O_GREY_COLOR), 0);
        lv_obj_align(calendar_event_start[calendar_items_01], LV_ALIGN_TOP_LEFT, REGULAR_ICON_PAD_LEFT, 263 + offset);

        // Add a list item separator line at the end of the list item
        list_item_tail[calendar_items_01] = lv_img_create(image);
        lv_img_set_src(list_item_tail[calendar_items_01], &Linez);
        lv_obj_align(list_item_tail[calendar_items_01], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 302 + offset);
    }
}


/***  SCREEN 06 - Calendar - August Events List page  ***/
static void calendar_06_view(lv_obj_t * calendar_06_view_page) {
    lv_obj_t * image = lv_img_create(calendar_06_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 6;
    // printf("Contacts page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

/***  HEADING ELEMENTS  ***/
    render_back_button(image, (back_button_cb_t)back_home_button_cb);

    // /* 'Filter' button to filter the text messages */
    // lv_obj_t * filter_image = lv_img_create(image);
    // lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the contacts list heading */
    lv_obj_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 92);
    lv_label_set_text(list_name, "August events");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line below the list item header
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 136);

    /* These keep the alignment settings evenly spaced when in a for loop */
    // lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    // lv_point_t right = { 290, -220};
    lv_coord_t offset __attribute__((unused)) = 0;

    /* Set the list_item_separator object here */
    // lv_obj_t * list_item_separator[ttl_calendar_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * display_feature_overlay __attribute__((unused));
    int ttl_overlay_width __attribute__((unused)) = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height __attribute__((unused)) = 662;  // Set this to the last lv_obj_align() padding height minus 40

    /* Icon and label objects here */
    lv_obj_t * calendar_label[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * calendar_icon[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * calendar_item_overlay[ttl_calendar_items] __attribute__((unused));

    // lv_obj_t * month_name_heading = lv_label_create(image);
    // lv_label_set_recolor(month_name_heading, true);
    // lv_label_set_text(month_name_heading, calendar_00_list[cal_ttl].calendar_month);
    // lv_obj_set_style_text_color(month_name_heading, lv_color_hex(O_YELLOW_COLOR), 0);
    // lv_obj_set_style_text_font(month_name_heading, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    // lv_obj_align(month_name_heading, LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 112);

    lv_obj_t * day_number_heading = lv_img_create(image);
    // lv_label_set_recolor(day_number_heading, true);
    lv_img_set_src(day_number_heading, &Icon_Day_9);
    lv_obj_align(day_number_heading, LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 200);


    // // Add a list item separator line below the list item header
    // top_of_list_items = lv_img_create(image);
    // lv_img_set_src(top_of_list_items, &Linez);
    // lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 196);


/***  AUGUST CALENDAR ITEM LIST  ***/
    // cal_ttl += calendar_items_02;
    // printf("\n%s %s %s Calendar Items\n",calendar_00_list[cal_ttl].calendar_day, calendar_00_list[cal_ttl].calendar_month, calendar_00_list[cal_ttl].calendar_year);

    // /* Populate screen with Calendar 03.h (01 August 2024) event items */
    // for(calendar_items_03 = 0; !is_end(calendar_03_list[calendar_items_03].calendar_id); calendar_items_03++) {
    //     printf("calendar_id: %s\n",calendar_03_list[calendar_items_03].calendar_id);
    //     printf("calendar_title: %s\n",calendar_03_list[calendar_items_03].calendar_title);
    //     printf("calendar_time_start: %s\n",calendar_03_list[calendar_items_03].calendar_time_start);
    //     printf("calendar_time_end: %s\n",calendar_03_list[calendar_items_03].calendar_time_end);
    //     printf("calendar_description: %s\n\n",calendar_03_list[calendar_items_03].calendar_description);
    //     // printf("calendar_type_icon: %s\n\n",calendar_03_list[calendar_items_03].calendar_type_icon);

    // }

    // cal_ttl += calendar_items_03;
    // printf("\n%s %s %s Calendar Items\n",calendar_00_list[cal_ttl].calendar_day, calendar_00_list[cal_ttl].calendar_month, calendar_00_list[cal_ttl].calendar_year);

    // /* Populate screen with Calendar 04.h (15 August 2024) event items */
    // for(calendar_items_04 = 0; !is_end(calendar_04_list[calendar_items_04].calendar_id); calendar_items_04++) {
    //     printf("calendar_id: %s\n",calendar_04_list[calendar_items_04].calendar_id);
    //     printf("calendar_title: %s\n",calendar_04_list[calendar_items_04].calendar_title);
    //     printf("calendar_time_start: %s\n",calendar_04_list[calendar_items_04].calendar_time_start);
    //     printf("calendar_time_end: %s\n",calendar_04_list[calendar_items_04].calendar_time_end);
    //     printf("calendar_description: %s\n\n",calendar_04_list[calendar_items_04].calendar_description);
    //     // printf("calendar_type_icon: %s\n\n",calendar_04_list[calendar_items_04].calendar_type_icon);

    // }
}


/***  SCREEN 07 - Calendar - September Events List page  ***/
static void calendar_07_view(lv_obj_t * calendar_07_view_page) {
    lv_obj_t * image = lv_img_create(calendar_07_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 7;
    // printf("Contacts page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

/***  HEADING ELEMENTS  ***/
    render_back_button(image, (back_button_cb_t)back_home_button_cb);

    // /* 'Filter' button to filter the text messages */
    // lv_obj_t * filter_image = lv_img_create(image);
    // lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the contacts list heading */
    lv_obj_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 92);
    lv_label_set_text(list_name, "September events");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line below the list item header
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 136);

    /* These keep the alignment settings evenly spaced when in a for loop */
    // lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    // lv_point_t right = { 290, -220};
    lv_coord_t offset __attribute__((unused)) = 0;

    /* Set the list_item_separator object here */
    // lv_obj_t * list_item_separator[ttl_calendar_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * display_feature_overlay __attribute__((unused));
    int ttl_overlay_width __attribute__((unused)) = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height __attribute__((unused)) = 662;  // Set this to the last lv_obj_align() padding height minus 40

    /* Icon and label objects here */
    lv_obj_t * calendar_label[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * calendar_icon[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * calendar_item_overlay[ttl_calendar_items] __attribute__((unused));

/***  SPETEMBER CALENDAR ITEM LIST  ***/
    // cal_ttl += calendar_items_04;
    // printf("\n%s %s %s Calendar Items\n",calendar_00_list[cal_ttl].calendar_day, calendar_00_list[cal_ttl].calendar_month, calendar_00_list[cal_ttl].calendar_year);

    // /* Populate screen with Calendar 05.h (10 September 2024) event items */
    // for(calendar_items_05 = 0; !is_end(calendar_05_list[calendar_items_05].calendar_id); calendar_items_05++) {
    //     printf("calendar_id: %s\n",calendar_05_list[calendar_items_05].calendar_id);
    //     printf("calendar_title: %s\n",calendar_05_list[calendar_items_05].calendar_title);
    //     printf("calendar_time_start: %s\n",calendar_05_list[calendar_items_05].calendar_time_start);
    //     printf("calendar_time_end: %s\n",calendar_05_list[calendar_items_05].calendar_time_end);
    //     printf("calendar_description: %s\n\n",calendar_05_list[calendar_items_05].calendar_description);
    //     // printf("calendar_type_icon: %s\n\n",calendar_05_list[calendar_items_05].calendar_type_icon);

    // }

    // cal_ttl += calendar_items_05;
    // printf("\n%s %s %s Calendar Items\n",calendar_00_list[cal_ttl].calendar_day, calendar_00_list[cal_ttl].calendar_month, calendar_00_list[cal_ttl].calendar_year);

    // /* Populate screen with Calendar 06.h (20 September 2024) event items */
    // for(calendar_items_06 = 0; !is_end(calendar_06_list[calendar_items_06].calendar_id); calendar_items_06++) {
    //     printf("calendar_id: %s\n",calendar_06_list[calendar_items_06].calendar_id);
    //     printf("calendar_title: %s\n",calendar_06_list[calendar_items_06].calendar_title);
    //     printf("calendar_time_start: %s\n",calendar_06_list[calendar_items_06].calendar_time_start);
    //     printf("calendar_time_end: %s\n",calendar_06_list[calendar_items_06].calendar_time_end);
    //     printf("calendar_description: %s\n\n",calendar_06_list[calendar_items_06].calendar_description);
    //     // printf("calendar_type_icon: %s\n\n",calendar_06_list[calendar_items_06].calendar_type_icon);

    // }
}


/***  SCREEN 08 - Calendar - Events List page  ***/
static __attribute__((unused)) void calendar_08_view(lv_obj_t * calendar_08_view_page){
    lv_obj_t * image = lv_img_create(calendar_08_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 8;
    // printf("Contacts page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

/***  HEADING ELEMENTS  ***/
    render_back_button(image, (back_button_cb_t)back_home_button_cb);

    /* 'Filter' button to filter the text messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Contacts_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the contacts list heading */
    lv_obj_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 92);
    lv_label_set_text(list_name, "July events");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line below the list item header
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 136);

    /* These keep the alignment settings evenly spaced when in a for loop */
    // lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    // lv_point_t right = { 290, -220};
    lv_coord_t offset __attribute__((unused)) = 0;

    /* Set the list_item_separator object here */
    // lv_obj_t * list_item_separator[ttl_calendar_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * display_feature_overlay __attribute__((unused));
    int ttl_overlay_width __attribute__((unused)) = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height __attribute__((unused)) = 662;  // Set this to the last lv_obj_align() padding height minus 40

    /* Icon and label objects here */
    lv_obj_t * calendar_label[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * calendar_icon[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * calendar_item_overlay[ttl_calendar_items] __attribute__((unused));
}


/***  SCREEN 09 - Calendar - Events List page  ***/
static __attribute__((unused)) void calendar_09_view(lv_obj_t * calendar_09_view_page) {
    lv_obj_t * image = lv_img_create(calendar_09_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 9;
    // printf("Contacts page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

/***  HEADING ELEMENTS  ***/
    render_back_button(image, (back_button_cb_t)back_home_button_cb);

    /* 'Filter' button to filter the text messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Contacts_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the contacts list heading */
    lv_obj_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 92);
    lv_label_set_text(list_name, "July events");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line below the list item header
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 136);

    /* These keep the alignment settings evenly spaced when in a for loop */
    // lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    // lv_point_t right = { 290, -220};
    lv_coord_t offset __attribute__((unused)) = 0;

    /* Set the list_item_separator object here */
    // lv_obj_t * list_item_separator[ttl_calendar_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * display_feature_overlay __attribute__((unused));
    int ttl_overlay_width __attribute__((unused)) = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height __attribute__((unused)) = 662;  // Set this to the last lv_obj_align() padding height minus 40

    /* Icon and label objects here */
    lv_obj_t * calendar_label[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * calendar_icon[ttl_calendar_items] __attribute__((unused));
    lv_obj_t * calendar_item_overlay[ttl_calendar_items] __attribute__((unused));
}


void calendar_menu_setup(void) {
    printf("CALENDAR MENU init...\n");

    lv_obj_t * calendar_page = lv_obj_create(NULL);
    menu_dispatch_table[CALENDAR_VEC] = calendar_page;

    lv_obj_center(calendar_page);
    lv_obj_set_style_bg_color(calendar_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(calendar_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(calendar_page, true, 3);
    lv_obj_set_scroll_dir(calendar_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(calendar_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(calendar_page, LV_OBJ_FLAG_SCROLLABLE | LV_SCROLLBAR_MODE_ON);

    /* CALENDAR VIEW: Display the content for a specific calendar item */
    printf("\nCALENDAR_01_VIEW launch...\n");
    calendar_01_view(calendar_page);

    /* CALENDAR VIEW: Display the content for a specific calendar item */
    printf("\nCALENDAR_02_VIEW launch...\n");
    calendar_02_view(calendar_page);

    /* CALENDAR VIEW: Display the content for a specific calendar item */
    printf("\nCALENDAR_03_VIEW launch...\n");
    calendar_03_view(calendar_page);

    /* CALENDAR VIEW: Display the content for a specific calendar item */
    printf("\nCALENDAR_04_VIEW launch...\n");
    calendar_04_view(calendar_page);

    /* CALENDAR VIEW: Display the content for a specific calendar item */
    printf("\nCALENDAR_05_VIEW launch...\n");
    calendar_05_view(calendar_page);

    /* CALENDAR VIEW: Display the content for a specific calendar item */
    printf("\nCALENDAR_06_VIEW launch...\n");
    calendar_06_view(calendar_page);

    /* CALENDAR VIEW: Display the content for a specific calendar item */
    printf("\nCALENDAR_07_VIEW launch...\n");
    calendar_07_view(calendar_page);

    /* CONTACTS VIEW: Display the content for calendar_00_view -- Your Calendar */
    printf("\nCALENDAR_00_VIEW launch...\n");
    calendar_00_view(calendar_page);

    scroll_to_home();
}
