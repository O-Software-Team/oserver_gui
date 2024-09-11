#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/* Initialize/populate the Calendar list struct */
#include "content/inc/calendar/00.h"   /* Month-based List - Specific appointments for each month (August / September / October / November) data */

/***  This test_button provides the maximum width for a graphic to be included into the UI
 * 
 * Dimensions should be:   |- 20px_left -|- 345px_object -|- 20px_right -|
 * 
***/

    // lv_obj_t * test_overlay = lv_btn_create(iphone_config_container);
    // lv_obj_set_size(test_overlay, 345, 60);
    // lv_obj_set_style_bg_color(test_overlay, lv_color_white(), 0);
    // lv_obj_set_style_opa(test_overlay, LV_OPA_90, LV_PART_MAIN);
    // lv_obj_align(test_overlay, LV_ALIGN_TOP_LEFT, 20, 60);  // This is first object displayed on the screen

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
LV_IMG_DECLARE(Calendar_4_Up);
LV_IMG_DECLARE(Calendar_August);
LV_IMG_DECLARE(Calendar_September);
LV_IMG_DECLARE(Calendar_October);
LV_IMG_DECLARE(Calendar_November);
LV_IMG_DECLARE(Icon_Calendar_Initials_Background);
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
LV_FONT_DECLARE(NeueHaasDisplayThin_80);

/***  Calendar Specific Declarations  ***/

/*  Create the Calendar Event struct to update data in SCREEN 05 (line item index, month, and day */
    // item_data->cal_view = calendar_event_1;
    // item_data->back_btn = scr_nbr;
    // item_data->month = "September";
    // item_data->day = "15";

typedef struct {
    int cal_view;
    int back_btn;
    char * month;
    char * day;
} calendar_item_data;

int prev_scr = 0;

/* Set total number of pages / screens -- this includes screen #1 which is the main contacts screen to screen #4 which is the spreadsheets screen */
#define NUM_SCREENS 10

/* Set the array to store the screen reference pointers */
lv_obj_t * calendar_objects[NUM_SCREENS];

/* Set the BACK-TO-HOME array to use in a custom back button for the filesystem app */
static lv_obj_t * back_to_home_screen[NUM_SCREENS] __attribute__((unused));

/* This is the primary "home page" element in the Settings app */
static const int back_to_home = 0;

/* Place all container definitions here to ensure all data can be found throughout */
lv_obj_t * calendar_event_container;
// lv_obj_t * calendar_events_list_container;
// lv_obj_t * disabled_pick_list_container;
// lv_obj_t * pairing_container;

/* Counters */
static int ttl_items;
static int ttl_calendar_items = 0;
static int cal_ttl;

lv_obj_t * cal_event_number;
static char * calendar_event_01 = "cal_01";
static char * calendar_event_02 = "cal_02";
static char * calendar_event_03 = "cal_03";
static char * calendar_event_04 = "cal_04";
static char * calendar_event_05 = "cal_05";
static char * calendar_event_06 = "cal_06";
static char * calendar_event_07 = "cal_07";
static char * calendar_event_08 = "cal_08";


static int cal_1 = 1;
static int cal_2 = 2;
static int cal_3 = 3;
static int cal_4 = 4;
static int cal_event_viewer = 5;
// static int cal_october = 6;
// static int cal_november = 7;
// static int cal_event_viewer = 8;

/* Calendar Card fields required for population */

static lv_obj_t * calendar_event_item_overlay[];
static lv_obj_t * calendar_event_icon[];
static lv_obj_t * calendar_event_label[];
static lv_obj_t * calendar_event_start[];
static lv_obj_t * list_item_tail[];


lv_obj_t * month_name_heading;
lv_obj_t * day_number_heading;
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
// lv_obj_t * calendar_event_icon;
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

/* Function to find a calendar item information in the 'calendar_notes' element */
static calendar_item * find_calendar_by_id(const char * id_to_find) {
    for (size_t i = 0; i < sizeof(calendar_00_list) / sizeof(calendar_item); ++i) {
        if (strcmp(calendar_00_list[i].calendar_notes, id_to_find) == 0) {
            return &calendar_00_list[i];
        }
    }
    return NULL;  // Calendar item not found
}

static void populate_calendar_event_container(lv_event_t * e) {
/***  POPULATE :: calendar_05_view_page  ***/
    /* Extract the calendar event data from calendar_00_list[] */
    char * cal_event = (char *)lv_event_get_user_data(e);
    calendar_item * found_event = find_calendar_by_id(cal_event);

    /* Set the previous screen viewed */
    if(found_event->calendar_notes == "cal_01" || found_event->calendar_notes == "cal_02" || found_event->calendar_notes == "cal_03" || found_event->calendar_notes == "cal_04" || found_event->calendar_notes == "cal_05" || found_event->calendar_notes == "cal_06" || found_event->calendar_notes == "cal_07" || found_event->calendar_notes == "cal_08") {
        prev_scr = 2;
    } else if(found_event->calendar_notes == "cal_09" || found_event->calendar_notes == "cal_10") {
        prev_scr = 3;
    } else if(found_event->calendar_notes == "cal_11" || found_event->calendar_notes == "cal_12") {
        prev_scr = 4;
    } else {
        prev_scr = 1;
    }

    /* Clear existing rows from the container first */
    lv_obj_clean(calendar_event_container);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(calendar_event_container, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(calendar_event_container, LV_DIR_VER);

    /* Set the calendar event viewer screen */
    int scr_nbr = cal_event_viewer;

    /* Store the pointer to the current screen being viewed */
    calendar_objects[scr_nbr] = calendar_event_container;
    lv_obj_set_style_bg_img_src(calendar_event_container, &Background, 0);

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    lv_obj_t * back_to_previous_calendar = lv_btn_create(calendar_event_container);
    lv_obj_set_size(back_to_previous_calendar, 130, 50);
    lv_obj_set_style_opa(back_to_previous_calendar, LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_previous_calendar, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)prev_scr);
    lv_obj_align(back_to_previous_calendar, LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(calendar_event_container);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(calendar_event_container);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(calendar_event_container);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Scroll to the Calendar Event Viewer screen -- calendar_05_view_page */
    lv_obj_scroll_to_view(calendar_objects[cal_event_viewer], LV_ANIM_OFF);

    month_name_heading = lv_label_create(calendar_event_container);
    lv_label_set_recolor(month_name_heading, true);
    lv_label_set_text(month_name_heading, found_event->calendar_month);
    lv_obj_set_style_text_color(month_name_heading, lv_color_hex(O_YELLOW_COLOR), 0);
    lv_obj_set_style_text_font(month_name_heading, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(month_name_heading, LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 102);

    day_number_heading = lv_label_create(calendar_event_container);
    lv_label_set_recolor(day_number_heading, true);
    lv_label_set_text(day_number_heading, found_event->calendar_day);
    lv_obj_set_style_text_color(day_number_heading, lv_color_white(), 0);
    lv_obj_set_style_opa(day_number_heading, LV_OPA_80, LV_PART_MAIN);
    lv_obj_set_style_text_font(day_number_heading, &NeueHaasDisplayThin_80, LV_PART_MAIN);
    lv_obj_align(day_number_heading, LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 138);

    /* Add a list item separator line below the list item header */
    lv_obj_t * top_of_list_items = lv_img_create(calendar_event_container);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 222);

    int offset = 0;
    int offset_counter = 0;

    /* Populate screen with Calendar 01.h (09 July 2024) event items */
    for(int calendar_items_01 = 0; !is_end(calendar_00_list[calendar_items_01].calendar_id); calendar_items_01++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        offset = offset_counter * 90;

        if(calendar_00_list[calendar_items_01].calendar_notes == cal_event) {
            /* Calender event list item button overlay */
            calendar_event_item_overlay[calendar_items_01] = lv_btn_create(calendar_event_container);
            lv_obj_set_size(calendar_event_item_overlay[calendar_items_01], 352, 80);
            lv_obj_set_style_opa(calendar_event_item_overlay[calendar_items_01], LV_OPA_TRANSP, LV_PART_MAIN);
            lv_obj_align(calendar_event_item_overlay[calendar_items_01], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 236 + offset);

            calendar_event_icon[calendar_items_01] = lv_img_create(calendar_event_container);
            lv_img_set_src(calendar_event_icon[calendar_items_01], calendar_00_list[calendar_items_01].calendar_type_icon);
            lv_obj_set_style_opa(calendar_event_icon[calendar_items_01], LV_OPA_COVER, LV_PART_MAIN);
            lv_obj_align(calendar_event_icon[calendar_items_01], LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 252 + offset);

            calendar_event_label[calendar_items_01] = lv_label_create(calendar_event_container);
            lv_label_set_recolor(calendar_event_label[calendar_items_01], true);
            lv_label_set_text(calendar_event_label[calendar_items_01], calendar_00_list[calendar_items_01].calendar_title);
            lv_obj_set_style_text_font(calendar_event_label[calendar_items_01], &NeueHaasDisplayLight_24, LV_PART_MAIN);
            lv_obj_set_style_text_color(calendar_event_label[calendar_items_01], lv_color_white(), 0);
            lv_obj_align(calendar_event_label[calendar_items_01], LV_ALIGN_TOP_LEFT, REGULAR_ICON_PAD_LEFT, 246 + offset);

            calendar_event_start[calendar_items_01] = lv_label_create(calendar_event_container);
            lv_label_set_recolor(calendar_event_start[calendar_items_01], true);
            lv_label_set_text(calendar_event_start[calendar_items_01], calendar_00_list[calendar_items_01].calendar_time_start);
            lv_obj_set_style_text_font(calendar_event_start[calendar_items_01], &NeueHaasDisplayLight_20, LV_PART_MAIN);
            lv_obj_set_style_text_color(calendar_event_start[calendar_items_01], lv_color_hex(O_GREY_COLOR), 0);
            lv_obj_align(calendar_event_start[calendar_items_01], LV_ALIGN_TOP_LEFT, REGULAR_ICON_PAD_LEFT, 274 + offset);

            // Add a list item separator line at the end of the list item
            list_item_tail[calendar_items_01] = lv_img_create(calendar_event_container);
            lv_img_set_src(list_item_tail[calendar_items_01], &Linez);
            lv_obj_align(list_item_tail[calendar_items_01], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 312 + offset);

            offset_counter++;
        }
    }
}

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

    // printf("func -- ttl_calendar_items: %d\n", ttl_calendar_items);
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

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

/***  CALENDAR ELEMENTS  ***/
    int calendar_item_overlay_width = 150;
    int calendar_5_row_overlay_height = 155;
    int calendar_6_row_overlay_height = 175;

    /* Overlay elements to provide clickable area to advance to the appropriate calendar month */
    lv_obj_t * calendar_1 = lv_img_create(image);
    lv_obj_set_size(calendar_1, calendar_item_overlay_width, calendar_5_row_overlay_height);
    lv_obj_add_flag(calendar_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(calendar_1, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_1);  // Use this for debugging
    lv_obj_align(calendar_1, LV_ALIGN_TOP_LEFT, 40, 92);

    lv_obj_t * calendar_2 = lv_img_create(image);
    lv_obj_set_size(calendar_2, calendar_item_overlay_width, calendar_6_row_overlay_height);
    lv_obj_add_flag(calendar_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(calendar_2, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_2);  // Use this for debugging
    lv_obj_align(calendar_2, LV_ALIGN_TOP_LEFT, 205, 92);

    lv_obj_t * calendar_3 = lv_img_create(image);
    lv_obj_set_size(calendar_3, calendar_item_overlay_width, calendar_5_row_overlay_height);
    lv_obj_add_flag(calendar_3, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(calendar_3, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_3);  // Use this for debugging
    lv_obj_align(calendar_3, LV_ALIGN_TOP_LEFT, 40, 285);

    lv_obj_t * calendar_4 = lv_img_create(image);
    lv_obj_set_size(calendar_4, calendar_item_overlay_width, calendar_5_row_overlay_height);
    lv_obj_add_flag(calendar_4, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(calendar_4, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_4);  // Use this for debugging
    lv_obj_align(calendar_4, LV_ALIGN_TOP_LEFT, 205, 285);

    /* 4-Up Calendar */
    lv_obj_t * calendar_4_up = lv_img_create(image);
    lv_img_set_src(calendar_4_up, &Calendar_4_Up);
    lv_obj_align(calendar_4_up, LV_ALIGN_TOP_MID, 0, 80);

}

/***  SCREEN 01 - Calendar page  ***/
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

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the rule across the screen dividing the heading from the calendar */
    lv_obj_t * calendar_heading_rule = lv_img_create(image);
    lv_img_set_src(calendar_heading_rule, &Linez);
    lv_obj_align(calendar_heading_rule, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 138);

    // 6-ROW CALENDAR VERTICAL ALIGNMENT TABLE
    // H: 136 + 46 = 182  (ROW: 1)
    // H: 182 + 46 = 228  (ROW: 2)
    // H: 228 + 46 = 274  (ROW: 3)
    // H: 274 + 46 = 320  (ROW: 4)
    // H: 320 + 46 = 366  (ROW: 5)
    // H: 366 + 46 = 412  (ROW: 6)

    /* August Calendar */
    lv_obj_t * calendar_august = lv_img_create(image);
    lv_img_set_src(calendar_august, &Calendar_August);
    lv_obj_align(calendar_august, LV_ALIGN_TOP_MID, 0, 80);

}

/***  SCREEN 02 - Calendar page  ***/
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

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the rule across the screen dividing the heading from the calendar */
    lv_obj_t * calendar_heading_rule = lv_img_create(image);
    lv_img_set_src(calendar_heading_rule, &Linez);
    lv_obj_align(calendar_heading_rule, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 138);

    // 6-ROW CALENDAR VERTICAL ALIGNMENT TABLE
    // H: 136 + 46 = 182  (ROW: 1)
    // H: 182 + 46 = 228  (ROW: 2)
    // H: 228 + 46 = 274  (ROW: 3)
    // H: 274 + 46 = 320  (ROW: 4)
    // H: 320 + 46 = 366  (ROW: 5)
    // H: 366 + 46 = 412  (ROW: 6)

/***  CALENDAR ELEMENTS  ***/
    /* This is first event 9 Sep displayed on the calendar month screen */
    lv_obj_t * september_event_1 = lv_btn_create(image);
    lv_obj_set_size(september_event_1, 40, 40);
    lv_obj_set_style_radius(september_event_1, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(september_event_1, lv_color_hex(O_TEAL_COLOR), 0);
    lv_obj_set_style_opa(september_event_1, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(september_event_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(september_event_1, populate_calendar_event_container, LV_EVENT_CLICKED, calendar_event_01);
    lv_obj_align(september_event_1, LV_ALIGN_TOP_LEFT, 36, 274);

    /* This is second event 13 Sep displayed on the calendar month screen */
    lv_obj_t * september_event_2 = lv_btn_create(image);
    lv_obj_set_size(september_event_2, 40, 40);
    lv_obj_set_style_radius(september_event_2, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(september_event_2, lv_color_hex(O_TEAL_COLOR), 0);
    lv_obj_set_style_opa(september_event_2, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(september_event_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(september_event_2, populate_calendar_event_container, LV_EVENT_CLICKED, calendar_event_02);
    lv_obj_align(september_event_2, LV_ALIGN_TOP_LEFT, 226, 274);

    /* This is second event 16 Sep displayed on the calendar month screen */
    lv_obj_t * september_event_3 = lv_btn_create(image);
    lv_obj_set_size(september_event_3, 40, 40);
    lv_obj_set_style_radius(september_event_3, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(september_event_3, lv_color_hex(O_TEAL_COLOR), 0);
    lv_obj_set_style_opa(september_event_3, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(september_event_3, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(september_event_3, populate_calendar_event_container, LV_EVENT_CLICKED, calendar_event_03);
    lv_obj_align(september_event_3, LV_ALIGN_TOP_LEFT, 41, 320);

    /* This is second event 20 Sep displayed on the calendar month screen */
    lv_obj_t * september_event_4 = lv_btn_create(image);
    lv_obj_set_size(september_event_4, 40, 40);
    lv_obj_set_style_radius(september_event_4, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(september_event_4, lv_color_hex(O_TEAL_COLOR), 0);
    lv_obj_set_style_opa(september_event_4, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(september_event_4, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(september_event_4, populate_calendar_event_container, LV_EVENT_CLICKED, calendar_event_04);
    lv_obj_align(september_event_4, LV_ALIGN_TOP_LEFT, 222, 320);

    /* This is second event 23 Sep displayed on the calendar month screen */
    lv_obj_t * september_event_5 = lv_btn_create(image);
    lv_obj_set_size(september_event_5, 40, 40);
    lv_obj_set_style_radius(september_event_5, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(september_event_5, lv_color_hex(O_TEAL_COLOR), 0);
    lv_obj_set_style_opa(september_event_5, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(september_event_5, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(september_event_5, populate_calendar_event_container, LV_EVENT_CLICKED, calendar_event_05);
    lv_obj_align(september_event_5, LV_ALIGN_TOP_LEFT, 38, 366);

    /* This is second event 24 Sep displayed on the calendar month screen */
    lv_obj_t * september_event_6 = lv_btn_create(image);
    lv_obj_set_size(september_event_6, 40, 40);
    lv_obj_set_style_radius(september_event_6, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(september_event_6, lv_color_hex(O_TEAL_COLOR), 0);
    lv_obj_set_style_opa(september_event_6, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(september_event_6, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(september_event_6, populate_calendar_event_container, LV_EVENT_CLICKED, calendar_event_06);
    lv_obj_align(september_event_6, LV_ALIGN_TOP_LEFT, 84, 366);

    /* This is second event 26 Sep displayed on the calendar month screen */
    lv_obj_t * september_event_7 = lv_btn_create(image);
    lv_obj_set_size(september_event_7, 40, 40);
    lv_obj_set_style_radius(september_event_7, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(september_event_7, lv_color_hex(O_TEAL_COLOR), 0);
    lv_obj_set_style_opa(september_event_7, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(september_event_7, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(september_event_7, populate_calendar_event_container, LV_EVENT_CLICKED, calendar_event_07);
    lv_obj_align(september_event_7, LV_ALIGN_TOP_LEFT, 177, 366);

    /* This is second event 30 Sep displayed on the calendar month screen */
    lv_obj_t * september_event_8 = lv_btn_create(image);
    lv_obj_set_size(september_event_8, 40, 40);
    lv_obj_set_style_radius(september_event_8, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(september_event_8, lv_color_hex(O_TEAL_COLOR), 0);
    lv_obj_set_style_opa(september_event_8, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(september_event_8, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(september_event_8, populate_calendar_event_container, LV_EVENT_CLICKED, calendar_event_08);
    lv_obj_align(september_event_8, LV_ALIGN_TOP_LEFT, 37, 412);

    /* September Calendar */
    lv_obj_t * calendar_september = lv_img_create(image);
    lv_img_set_src(calendar_september, &Calendar_September);
    lv_obj_align(calendar_september, LV_ALIGN_TOP_MID, 0, 80);
}

/***  SCREEN 03 - Calendar page  ***/
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

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the rule across the screen dividing the heading from the calendar */
    lv_obj_t * calendar_heading_rule = lv_img_create(image);
    lv_img_set_src(calendar_heading_rule, &Linez);
    lv_obj_align(calendar_heading_rule, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 138);

/***  CALENDAR ELEMENTS  ***/
    lv_obj_t * october_event_1 = lv_btn_create(image);
    lv_obj_set_size(october_event_1, 40, 40);
    lv_obj_set_style_radius(october_event_1, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(october_event_1, lv_color_hex(O_TEAL_COLOR), 0);
    lv_obj_set_style_opa(october_event_1, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(october_event_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(october_event_1, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_1);  // Send user to the Event screen with the appropriate data
    // lv_obj_align(october_event_1, LV_ALIGN_TOP_LEFT, 135, 274);  
    lv_obj_align(october_event_1, LV_ALIGN_TOP_LEFT, 273, 228);  

    // 6-ROW CALENDAR VERTICAL ALIGNMENT TABLE
    // H: 136 + 46 = 182  (ROW: 1)
    // H: 182 + 46 = 228  (ROW: 2)
    // H: 228 + 46 = 274  (ROW: 3)
    // H: 274 + 46 = 320  (ROW: 4)
    // H: 320 + 46 = 366  (ROW: 5)
    // H: 366 + 46 = 412  (ROW: 6)

    /* October Calendar */
    lv_obj_t * calendar_october = lv_img_create(image);
    lv_img_set_src(calendar_october, &Calendar_October);
    lv_obj_align(calendar_october, LV_ALIGN_TOP_MID, 0, 80);

}

/***  SCREEN 04 - Calendar page  ***/
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

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Calendar_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the rule across the screen dividing the heading from the calendar */
    lv_obj_t * calendar_heading_rule = lv_img_create(image);
    lv_img_set_src(calendar_heading_rule, &Linez);
    lv_obj_align(calendar_heading_rule, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 138);

/***  CALENDAR ELEMENTS  ***/
    lv_obj_t * november_event_1 = lv_btn_create(image);
    lv_obj_set_size(november_event_1, 40, 40);
    lv_obj_set_style_radius(november_event_1, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_bg_color(november_event_1, lv_color_hex(O_TEAL_COLOR), 0);
    lv_obj_set_style_opa(november_event_1, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(november_event_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(november_event_1, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_1);  // Send user to the Event screen with the appropriate data
    lv_obj_align(november_event_1, LV_ALIGN_TOP_LEFT, 175, 228);  

    // 6-ROW CALENDAR VERTICAL ALIGNMENT TABLE
    // H: 136 + 46 = 182  (ROW: 1)
    // H: 182 + 46 = 228  (ROW: 2)
    // H: 228 + 46 = 274  (ROW: 3)
    // H: 274 + 46 = 320  (ROW: 4)
    // H: 320 + 46 = 366  (ROW: 5)
    // H: 366 + 46 = 412  (ROW: 6)

    /* November Calendar */
    lv_obj_t * calendar_november = lv_img_create(image);
    lv_img_set_src(calendar_november, &Calendar_November);
    lv_obj_align(calendar_november, LV_ALIGN_TOP_MID, 0, 80);

}

/***  SCREEN 05 - Calendar - Events List screen  ***/
static void calendar_05_view(lv_obj_t * calendar_05_view_page) {
    /* Define the main container to hold all of the devices (enabled and disabled) */
    calendar_event_container = lv_img_create(calendar_05_view_page);
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

    calc_dataset_items();

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

    /* CONTACTS VIEW: Display the content for calendar_00_view -- Your Calendar */
    printf("\nCALENDAR_00_VIEW launch...\n");
    calendar_00_view(calendar_page);

    scroll_to_home();
}
