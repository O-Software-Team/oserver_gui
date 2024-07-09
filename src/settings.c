#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Initialize/populate the Settings list structs */
#include "content/inc/settings/00.h"   /* Main screen - Settings list */
#include "content/inc/settings/01.h"   /* Connections list */
#include "content/test/settings/03.h"   /* Storage list */
#include "content/inc/settings/05.h"   /* System list */

/* List separator line definitions */
#define LIST_SEPARATOR 30

/* Padding definitions */
#define NARROW_PAD_LEFT 5
#define SIMPLE_PAD_LEFT 20
#define NORMAL_PAD_LEFT 30
#define NARROW_PAD_RIGHT -5
#define SIMPLE_PAD_RIGHT -20
#define NORMAL_PAD_RIGHT -30

/* Color definitions */
#define O_YELLOW_COLOR 0xD6B932
#define O_GREY_COLOR 0xAEB2A1
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

/* Contact Card - Contact Initials Background */
LV_IMG_DECLARE(Icon_Contact_Initials_Background);

/* Storage gauge imagery iconography */
LV_IMG_DECLARE(Settings_Storage_1);

/* Battery gauge imagery iconography */
LV_IMG_DECLARE(Settings_Battery_1_2);

/* Main HEADING iconography */
LV_IMG_DECLARE(Contacts_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

/***  Settings Specific Declarations  ***/

/* Set total number of pages / screens -- this includes screen #1 which is the main filesystem screen to screen #7 which is the spreadsheets screen */
#define NUM_SCREENS 5

/* Set the array to store the screen reference pointers */
lv_obj_t * settings_objects[NUM_SCREENS];

/* Set the BACK-TO-HOME array to use in a custom back button for the Settings app */
lv_obj_t * back_to_settings[NUM_SCREENS];

/* This is the primary "home page" element in the Settings app */
static const int back_to_home = 0;

/* Set style references */
static lv_style_t reset_style_img;
static lv_style_t power_off_style_img;
// static lv_style_t settings_feature_bullet;
// static lv_style_t settings_scale_bullet;
static lv_style_t back_button_style;
static lv_style_t name_style_20;
static lv_style_t name_style_24;

static lv_style_t label_style;
static lv_style_t italic_style;


/***  Init styles specific to Settings  ***/
static void init_styles() {
    lv_style_init(&reset_style_img);
    lv_style_set_img_recolor(&reset_style_img, lv_color_hex(RESET_COLOR));
    lv_style_set_img_recolor_opa(&reset_style_img, LV_OPA_COVER);
    lv_style_set_text_font(&reset_style_img, &NeueHaasDisplayLight_24);

    lv_style_init(&power_off_style_img);
    lv_style_set_img_recolor(&power_off_style_img, lv_color_hex(POWER_OFF_COLOR));
    lv_style_set_img_recolor_opa(&power_off_style_img, LV_OPA_COVER);
    lv_style_set_text_font(&power_off_style_img, &NeueHaasDisplayLight_24);

    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    lv_style_init(&name_style_20);
    lv_style_set_text_font(&name_style_20, &NeueHaasDisplayLight_20);

    lv_style_init(&name_style_24);
    lv_style_set_text_font(&name_style_24, &NeueHaasDisplayLight_24);

    lv_style_init(&label_style);
    lv_style_init(&italic_style);

    lv_style_set_text_font(&label_style, &NeueHaasDisplayLight_24);
    lv_style_set_text_font(&italic_style, &SaolDisplayRegularItalic_26);
}

/* Scroll to the Settings home screen as the final step in the settings app launch */
static void scroll_to_home() {
    printf("EXEC :: scroll_to_home()\n\n");
    lv_obj_scroll_to_view(settings_objects[back_to_home], LV_ANIM_OFF);
}

/* Scroll to screen clicked in the clickback call */
static void scroll_to_screen(lv_event_t* e) {
    int screen_index = (int)lv_event_get_user_data(e); // Get the screen index from user data
    printf("EXEC :: scroll_to_screen() [%d]\n\n",screen_index);
    lv_obj_scroll_to_view(settings_objects[screen_index], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

static void quit_application() {
    printf("\n\nEXEC :: exiting()\n\n");
    usleep(2250000);
    exit(0);
}

static __attribute__((unused)) int calc_scroll_height(int ttl_rows, int base_offset) {
    printf("\n\nttl_rows: %d  --  base_offset: %d\n",ttl_rows,base_offset);
    int ttl_height = ttl_rows * base_offset;
    // printf("Calc Scroll Height: %d\n",ttl_height);
    return ttl_height;
}

static __attribute__((unused)) int calc_scroll_offset(int ttl_rows) {
    int ttl_offset = 0;
    if(ttl_rows <= 10) {
        ttl_offset = 90;
    } else {
        ttl_offset = ttl_rows * 22;
    }
    // printf("Calc Scroll Offset: %d\n",ttl_offset);
    return ttl_offset;
}

static __attribute__((unused)) void debug_click(lv_event_t* e) {
    int screen_index = (int)lv_event_get_user_data(e); // Get the screen index from user data
    printf("\nEXEC :: clicked() [%d]\n",screen_index);
}

/***  SCREEN 00 - Main Settings page  ***/
static void settings_00_view(lv_obj_t * settings_00_view_page) {
    lv_obj_t * image = lv_img_create(settings_00_view_page);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 0;
    printf("Settings page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    settings_objects[0] = image;
    lv_img_set_src(image, &Background);

/***  Settings Specific Style Declarations  ***/
    // init_styles();

    /* Calculate total settings_00 -- main list */
    // printf("\nCalculate settings_00 -- main settings list...\n");
    int ttl_settings_items = 0;
    for(int settings_app_item = 0; !is_end(settings_00_list[settings_app_item].settings_id); settings_app_item++) {
        ttl_settings_items++;
        // printf("Item count: %d -- settings_id: %s\n",ttl_settings_items,settings_00_list[settings_app_item].settings_id);
    }
    // printf("\nTotal Records: %d\n\n",ttl_settings_items);

    /* Build the Contact record list for display */
    // printf("Building each settings_00 record for display\n");
    for(int j = 0; j < ttl_settings_items; j++) {
        if(is_end(settings_00_list[j].settings_id)) {
            // printf("item: %d -- settings_name: %s\n",j,settings_00_list[j].settings_name);
            break;
        } else {
            // printf("settings_id: %s -- settings_name: %s\n",settings_00_list[j].settings_id,settings_00_list[j].settings_name);
        }
    }

/***  HEADING ELEMENTS  ***/
    render_back_button(image, (back_button_cb_t)back_home_button_cb);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Settings_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_obj_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 92);
    lv_label_set_text(list_name, "Your settings");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add a list item separator just beneath the page label item */
    lv_obj_t * list_item_separator = lv_img_create(image);
    lv_img_set_src(list_item_separator, &Linez);
    lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 136);

    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_settings_items];

    /* Icon and label objects here */
    lv_obj_t * settings_label[ttl_settings_items];
    lv_obj_t * settings_icon[ttl_settings_items];
    lv_obj_t * settings_item_overlay[ttl_settings_items];

/***  MAIN CLICKABLE LIST ITEMS  ***/
    /* Add settings features as clickable buttons */
    for(int settings_list_counter = 0; settings_list_counter < ttl_settings_items; settings_list_counter++) {
        /* Increment the page reference number for each Settings page */
        scr_nbr++;

        /* A row-by-row offset value to maintain spacing between clickable elements */
        int offset = settings_list_counter * 60;

        /* Settings list item button overlay */
        settings_item_overlay[scr_nbr] = lv_btn_create(image);
        lv_obj_set_size(settings_item_overlay[scr_nbr], 352, 56);
        lv_obj_align(settings_item_overlay[scr_nbr], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 141 + offset);
        lv_obj_set_style_opa(settings_item_overlay[scr_nbr], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(settings_item_overlay[scr_nbr], scroll_to_screen, LV_EVENT_CLICKED, (void*)scr_nbr);

        /* Feature selection label */
        settings_label[scr_nbr] = lv_label_create(image);
        lv_label_set_recolor(settings_label[scr_nbr], true);
        lv_label_set_text(settings_label[scr_nbr], settings_00_list[settings_list_counter].settings_name);
        lv_obj_add_style(settings_label[scr_nbr], &name_style_24, LV_PART_MAIN);
        lv_obj_set_style_text_color(settings_label[scr_nbr], lv_color_white(), 0);
        lv_obj_align(settings_label[scr_nbr], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 157 + offset);

        settings_icon[scr_nbr] = lv_img_create(image);
        lv_img_set_src(settings_icon[scr_nbr], &Icon_Next_White);
        lv_obj_align(settings_icon[scr_nbr], LV_ALIGN_TOP_LEFT, 344, 162 + offset);
        lv_obj_set_style_opa(settings_icon[scr_nbr], LV_OPA_70, LV_PART_MAIN);

        // Add a list item separator line at the end of the list item
        list_item_tail[scr_nbr] = lv_img_create(image);
        lv_img_set_src(list_item_tail[scr_nbr], &Linez);
        lv_obj_align(list_item_tail[scr_nbr], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 199 + offset);
    }
}

/***  SCREEN 01 - Connection page  ***/
static void settings_01_view(lv_obj_t * settings_01_view_page) {
    lv_obj_t * image = lv_img_create(settings_01_view_page);

    /* Set the screen number counter to the first visible sub-screen for the connection app */
    int scr_nbr = 1;
    printf("Settings page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    settings_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

/***  Connection Specific Style Declarations  ***/
    init_styles();

    /* Calculate total settings_01 -- main list */
    printf("\nCalculate settings_01 -- connection list...\n");
    int ttl_connection_app_items = 0;
    for(int connection_app_item = 0; !is_end(settings_01_list[connection_app_item].settings_id); connection_app_item++) {
        ttl_connection_app_items++;
        printf("Item count: %d -- settings_id: %s\n",ttl_connection_app_items,settings_01_list[connection_app_item].settings_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_connection_app_items);

    /* Build the Connection record list for display */
    printf("Building each settings_01 record for display\n");
    for(int j = 0; j < ttl_connection_app_items; j++) {
        if(is_end(settings_01_list[j].settings_id)) {
            printf("item: %d -- settings_name: %s\n",j,settings_01_list[j].settings_name);
            break;
        } else {
            printf("settings_id: %s -- settings_name: %s\n",settings_01_list[j].settings_id,settings_01_list[j].settings_name);
        }
    }

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_settings[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_settings[back_to_home], 130, 50);
    lv_obj_align(back_to_settings[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);
    lv_obj_set_style_opa(back_to_settings[back_to_home], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_settings[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, 25, 45);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Settings_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_obj_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 92);
    lv_label_set_text(list_name, "Your connections");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add a list item separator just beneath the page label item */
    lv_obj_t * list_item_separator = lv_img_create(image);
    lv_img_set_src(list_item_separator, &Linez);
    lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 136);

/***  MAIN LIST ITEMS  ***/
    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_connection_app_items];

    /* Icon and label objects here */
    lv_obj_t * connection_label[ttl_connection_app_items];
    lv_obj_t * connection_icon[ttl_connection_app_items];
    lv_obj_t * connection_item_overlay[ttl_connection_app_items];

    /* Add settings features as clickable buttons */
    for(int connection_list_counter = 0; connection_list_counter < ttl_connection_app_items; connection_list_counter++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        int offset = connection_list_counter * 60;

        /* Settings list item button overlay */
        connection_item_overlay[connection_list_counter] = lv_btn_create(image);
        lv_obj_set_size(connection_item_overlay[connection_list_counter], 352, 56);
        lv_obj_align(connection_item_overlay[connection_list_counter], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 141 + offset);
        lv_obj_set_style_opa(connection_item_overlay[connection_list_counter], LV_OPA_0, LV_PART_MAIN);
        // lv_obj_add_event_cb(connection_item_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)scr_nbr);

        /* Feature selection label */
        connection_label[connection_list_counter] = lv_label_create(image);
        lv_label_set_recolor(connection_label[connection_list_counter], true);
        lv_label_set_text(connection_label[connection_list_counter], settings_01_list[connection_list_counter].settings_name);
        lv_obj_add_style(connection_label[connection_list_counter], &name_style_24, LV_PART_MAIN);
        lv_obj_set_style_text_color(connection_label[connection_list_counter], lv_color_white(), 0);
        lv_obj_align(connection_label[connection_list_counter], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 157 + offset);

        connection_icon[connection_list_counter] = lv_img_create(image);
        lv_img_set_src(connection_icon[connection_list_counter], settings_01_list[connection_list_counter].settings_state ? &Icon_Status_Active: &Icon_Status_Disable);
        lv_obj_align(connection_icon[connection_list_counter], LV_ALIGN_CENTER, 161, -85 + offset);
        lv_obj_set_style_opa(connection_icon[connection_list_counter], LV_OPA_COVER, LV_PART_MAIN);

        // Add a list item separator line at the end of the list item
        list_item_tail[connection_list_counter] = lv_img_create(image);
        lv_img_set_src(list_item_tail[connection_list_counter], &Linez);
        lv_obj_align(list_item_tail[connection_list_counter], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 199 + offset);
    }
}


/***  SCREEN 02 - Display page  ***/
static __attribute__((unused)) void settings_02_view(lv_obj_t * settings_02_view_page) {
    lv_obj_t * image = lv_img_create(settings_02_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));

    /* Set the screen number counter to the first visible sub-screen for the connection app */
    int scr_nbr = 2;
    printf("Settings page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    settings_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

    /* Just set a fake total list items value for now */
    int ttl_display_app_items = 3;  // ????

    /* Calculate total settings_03 -- main list */
    printf("\nCalculate settings_03 -- storage list...\n");
    for(int display_app_item = 0; !is_end(settings_03_list[display_app_item].settings_id); display_app_item++) {
        ttl_display_app_items = display_app_item+1;
        printf("Item count: %d -- settings_id: %s\n",ttl_display_app_items,settings_03_list[display_app_item].settings_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_display_app_items);

    /* Build the Connection record list for display */
    printf("Building each settings_03 record for display\n");
    for(int j = 0; j < ttl_display_app_items; j++) {
        if(is_end(settings_03_list[j].settings_id)) {
            printf("item: %d -- settings_name: %s\n",j,settings_03_list[j].settings_name);
            break;
        } else {
            printf("settings_id: %s -- settings_name: %s\n",settings_03_list[j].settings_id,settings_03_list[j].settings_name);
        }
    }

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_settings[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_settings[back_to_home], 130, 50);
    lv_obj_align(back_to_settings[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);
    lv_obj_set_style_opa(back_to_settings[back_to_home], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_settings[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, 25, 45);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Settings_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

/***  MAIN LIST ITEMS  ***/
}


/***  SCREEN 03 - Storage page  ***/
static void settings_03_view(lv_obj_t * settings_03_view_page) {
    lv_obj_t * image = lv_img_create(settings_03_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));

    /* Set the screen number counter to the first visible sub-screen for the connection app */
    int scr_nbr = 3;
    printf("Settings page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    settings_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

    /* Just set a fake total list items value for now */
    int ttl_storage_app_items = 3;

    /* Calculate total settings_03 -- main list */
    printf("\nCalculate settings_03 -- storage list...\n");
    for(int storage_app_item = 0; !is_end(settings_03_list[storage_app_item].settings_id); storage_app_item++) {
        ttl_storage_app_items = storage_app_item+1;
        printf("Item count: %d -- settings_id: %s\n",ttl_storage_app_items,settings_03_list[storage_app_item].settings_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_storage_app_items);

    /* Build the Connection record list for display */
    printf("Building each settings_03 record for display\n");
    for(int j = 0; j < ttl_storage_app_items; j++) {
        if(is_end(settings_03_list[j].settings_id)) {
            printf("item: %d -- settings_name: %s\n",j,settings_03_list[j].settings_name);
            break;
        } else {
            printf("settings_id: %s -- settings_name: %s\n",settings_03_list[j].settings_id,settings_03_list[j].settings_name);
        }
    }

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_settings[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_settings[back_to_home], 130, 50);
    lv_obj_align(back_to_settings[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);
    lv_obj_set_style_opa(back_to_settings[back_to_home], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_settings[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, 25, 45);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Settings_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

/***  MAIN LIST ITEMS  ***/
    /* Add the storage heading */
    lv_obj_t * storage_name = lv_label_create(image);
    lv_label_set_recolor(storage_name, true);
    lv_obj_align(storage_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 92);
    lv_label_set_text(storage_name, "Your storage");
    lv_obj_set_style_text_color(storage_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(storage_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Storage guage image */
    lv_obj_t * single_storage_gauge = lv_img_create(image);
    lv_img_set_src(single_storage_gauge, &Settings_Storage_1);
    lv_obj_align(single_storage_gauge, LV_ALIGN_TOP_MID, 0, 138);

    /* Add storage utilization label */
    lv_obj_t * storage_used = lv_label_create(image);
    lv_label_set_recolor(storage_used, true);
    lv_obj_align(storage_used, LV_ALIGN_TOP_MID, 0, 198);
    lv_label_set_text(storage_used, "338.7 Gb");
    lv_obj_set_style_text_color(storage_used, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(storage_used, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add storage transition label */
    lv_obj_t * storage_of = lv_label_create(image);
    lv_label_set_recolor(storage_of, true);
    lv_obj_align(storage_of, LV_ALIGN_TOP_MID, 0, 226);
    lv_label_set_text(storage_of, "of");
    lv_obj_set_style_text_color(storage_of, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(storage_of, &SaolDisplayRegularItalic_26, LV_PART_MAIN);

    /* Add storage total label */
    lv_obj_t * storage_amount = lv_label_create(image);
    lv_label_set_recolor(storage_amount, true);
    lv_obj_align(storage_amount, LV_ALIGN_TOP_MID, 0, 266);
    lv_label_set_text(storage_amount, "512 Gb");
    lv_obj_set_style_text_color(storage_amount, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(storage_amount, &NeueHaasDisplayLight_24, LV_PART_MAIN);

/***  MAIN LIST ITEMS  ***/
    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_storage_app_items];

    /* Icon and label objects here */
    lv_obj_t * storage_icon[ttl_storage_app_items];
    lv_obj_t * storage_label[ttl_storage_app_items];
    lv_obj_t * storage_description[ttl_storage_app_items];
    lv_obj_t * storage_item_overlay[ttl_storage_app_items];

    /* Add settings features as clickable buttons */
    for(int storage_list_counter = 0; storage_list_counter < ttl_storage_app_items; storage_list_counter++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        int offset = storage_list_counter * 60;

        /* Settings list item button overlay */
        storage_item_overlay[storage_list_counter] = lv_btn_create(image);
        lv_obj_set_size(storage_item_overlay[storage_list_counter], 342, 56);
        lv_obj_align(storage_item_overlay[storage_list_counter], LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 350 + offset);
        lv_obj_set_style_opa(storage_item_overlay[storage_list_counter], LV_OPA_0, LV_PART_MAIN);
        /* Uncomment this to enable clicking to some other screen */
        // lv_obj_add_event_cb(storage_item_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)storage_list_counter);

        /* Storage Item bullet */
        storage_icon[storage_list_counter] = lv_img_create(image);
        lv_img_set_src(storage_icon[storage_list_counter], settings_03_list[storage_list_counter].settings_icon);

        if(is_eq(settings_03_list[storage_list_counter].settings_type, "O_SCALE_RED")) {
            lv_obj_set_style_img_recolor(storage_icon[storage_list_counter], lv_color_hex(O_SCALE_RED), 0);
        } else if(is_eq(settings_03_list[storage_list_counter].settings_type, "O_SCALE_ORANGE")) {
            lv_obj_set_style_img_recolor(storage_icon[storage_list_counter], lv_color_hex(O_SCALE_ORANGE), 0);
        } else if(is_eq(settings_03_list[storage_list_counter].settings_type, "O_SCALE_CREAM")) {
            lv_obj_set_style_img_recolor(storage_icon[storage_list_counter], lv_color_hex(O_SCALE_CREAM), 0);
        } else {
            lv_obj_set_style_img_recolor(storage_icon[storage_list_counter], lv_color_hex(O_SCALE_GREY), 0);
        }

        lv_obj_set_style_img_recolor_opa(storage_icon[storage_list_counter], LV_OPA_COVER, 0);
        lv_obj_align(storage_icon[storage_list_counter], LV_ALIGN_TOP_LEFT, 28, 372 + offset);

        /* Storage Name label */
        storage_label[storage_list_counter] = lv_label_create(image);
        lv_label_set_recolor(storage_label[storage_list_counter], true);
        lv_label_set_text(storage_label[storage_list_counter], settings_03_list[storage_list_counter].settings_name);
        lv_obj_add_style(storage_label[storage_list_counter], &name_style_24, LV_PART_MAIN);
        lv_obj_set_style_text_color(storage_label[storage_list_counter], lv_color_white(), 0);
        lv_obj_align(storage_label[storage_list_counter], LV_ALIGN_TOP_LEFT, 45, 366 + offset); // add 16

        /* Storage Amount label */
        storage_description[storage_list_counter] = lv_label_create(image);
        lv_label_set_recolor(storage_description[storage_list_counter], true);
        lv_label_set_text(storage_description[storage_list_counter], settings_03_list[storage_list_counter].settings_description);
        lv_obj_add_style(storage_description[storage_list_counter], &name_style_24, LV_PART_MAIN);
        lv_obj_set_style_text_color(storage_description[storage_list_counter], lv_color_hex(HEADING_SUBDUED_COLOR), 0);
        lv_obj_align(storage_description[storage_list_counter], LV_ALIGN_TOP_RIGHT, NORMAL_PAD_RIGHT, 366 + offset); // match previous on left

        /* Add a list item separator line at the end of the list item */
        list_item_tail[storage_list_counter] = lv_img_create(image);
        lv_img_set_src(list_item_tail[storage_list_counter], &Linez);
        lv_obj_align(list_item_tail[storage_list_counter], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 408 + offset); // add 42
    }

}


/***  SCREEN 04 - Battery page  ***/
static void settings_04_view(lv_obj_t * settings_04_view_page) {
    lv_obj_t * image = lv_img_create(settings_04_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));

    /* Set the screen number counter to the first visible sub-screen for the connection app */
    int scr_nbr = 4;
    printf("Settings page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    settings_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_settings[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_settings[back_to_home], 130, 50);
    lv_obj_align(back_to_settings[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);
    lv_obj_set_style_opa(back_to_settings[back_to_home], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_settings[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, 25, 45);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Settings_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

/***  MAIN LIST ITEMS  ***/
    /* Add the Battery Status Info */
    lv_obj_t * battery_status_heading = lv_label_create(image);
    lv_label_set_recolor(battery_status_heading, true);
    lv_label_set_text(battery_status_heading, "Your Battery Levels");
    lv_obj_align(battery_status_heading, LV_ALIGN_TOP_MID, 0, 232); //120
    lv_obj_set_style_text_color(battery_status_heading, lv_color_white(), 0);
    lv_obj_set_style_text_font(battery_status_heading, &NeueHaasDisplayLight_32, LV_PART_MAIN);

    /* Add the Battery 1 - Gauge heading */
    lv_obj_t * battery_1_level = lv_label_create(image);
    lv_label_set_recolor(battery_1_level, true);
    lv_obj_align(battery_1_level, LV_ALIGN_TOP_LEFT, 74, 276); //162
    lv_label_set_text(battery_1_level, "Battery 1");
    lv_obj_set_style_text_color(battery_1_level, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(battery_1_level, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add the Battery 2 - Gauge heading */
    lv_obj_t * battery_2_level = lv_label_create(image);
    lv_label_set_recolor(battery_2_level, true);
    lv_obj_align(battery_2_level, LV_ALIGN_TOP_RIGHT, -58, 276); //162
    lv_label_set_text(battery_2_level, "Battery 2");
    lv_obj_set_style_text_color(battery_2_level, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(battery_2_level, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    lv_obj_t * dual_battery_gauge = lv_img_create(image);
    lv_img_set_src(dual_battery_gauge, &Settings_Battery_1_2);
    lv_obj_align(dual_battery_gauge, LV_ALIGN_CENTER, 0, 125); //208

    /* Add the Battery 1 - Gauge level */
    lv_obj_t * battery_1_value = lv_label_create(image);
    lv_label_set_recolor(battery_1_value, true);
    lv_obj_align(battery_1_value, LV_ALIGN_TOP_LEFT, 84, 368); //232
    lv_label_set_text(battery_1_value, "Good");
    lv_obj_set_style_text_color(battery_1_value, lv_color_hex(BATTERY_LEVEL_FAIR), 0);
    lv_obj_set_style_text_font(battery_1_value, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add the Battery 2 - Gauge level */
    lv_obj_t * battery_2_value = lv_label_create(image);
    lv_label_set_recolor(battery_2_value, true);
    lv_obj_align(battery_2_value, LV_ALIGN_TOP_RIGHT, -82, 368); //232
    lv_label_set_text(battery_2_value, "Low!");
    lv_obj_set_style_text_color(battery_2_value, lv_color_hex(BATTERY_LEVEL_LOW), 0);
    lv_obj_set_style_text_font(battery_2_value, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add a list item separator just beneath the page label item */
    // lv_obj_t * list_item_separator = lv_img_create(image);
    // lv_img_set_src(list_item_separator, &Linez);
    // lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 208);

    /* Add the Battery's Serial Number Info */
    lv_obj_t * battery_ser_num_heading = lv_label_create(image);
    lv_label_set_recolor(battery_ser_num_heading, true);
    lv_label_set_text(battery_ser_num_heading, "Serial Number");
    lv_obj_align(battery_ser_num_heading, LV_ALIGN_TOP_MID, 0, 120); //368
    lv_obj_set_style_text_color(battery_ser_num_heading, lv_color_white(), 0);
    lv_obj_set_style_text_font(battery_ser_num_heading, &NeueHaasDisplayLight_32, LV_PART_MAIN);

    /* Add the file list heading */
    lv_obj_t * battery_serial_number = lv_label_create(image);
    lv_label_set_recolor(battery_serial_number, true);
    lv_obj_align(battery_serial_number, LV_ALIGN_TOP_MID, 0, 162); //408
    lv_label_set_text(battery_serial_number, "SR71_958-MC130_555");
    lv_obj_set_style_text_color(battery_serial_number, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(battery_serial_number, &NeueHaasDisplayLight_24, LV_PART_MAIN);


#if 0
    /* Just set a fake total list items value for now */
    int ttl_battery_app_items = 5;

    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_battery_app_items];

    /* Icon and label objects here */
    lv_obj_t * battery_label[ttl_battery_app_items];
    lv_obj_t * battery_description[ttl_battery_app_items];
    lv_obj_t * battery_item_overlay[ttl_battery_app_items];

    lv_obj_t * dual_battery_gauge;
    lv_obj_t * battery_gauge_overlay;

    battery_gauge_overlay = lv_btn_create(image);
    lv_obj_set_size(battery_gauge_overlay, 342, 56);
    lv_obj_align(battery_gauge_overlay, LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 320);
    lv_obj_set_style_opa(battery_gauge_overlay, LV_OPA_0, LV_PART_MAIN);

    dual_battery_gauge = lv_img_create(image);
    lv_img_set_src(dual_battery_gauge, &Settings_Battery_1_2);
    lv_obj_align(dual_battery_gauge, LV_ALIGN_CENTER, 0, 125);
    lv_img_set_zoom(dual_battery_gauge, 125);
#endif
}


/***  SCREEN 05 - System Info page  ***/
static void settings_05_view(lv_obj_t * settings_05_view_page) {
    lv_obj_t * image = lv_img_create(settings_05_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));

    /* Set the screen number counter to the first visible sub-screen for the connection app */
    int scr_nbr = 5;
    printf("Settings page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    settings_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

/***  System Specific Style Declarations  ***/
    // init_styles();

    /* Calculate total settings_05 -- system list */
    printf("\nCalculate settings_05 -- system list...\n");
    int ttl_system_app_items = 0;
    for(int system_app_item = 0; !is_end(settings_05_list[system_app_item].settings_id); system_app_item++) {
        ttl_system_app_items++;
        printf("Item count: %d -- settings_id: %s\n",ttl_system_app_items,settings_05_list[system_app_item].settings_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_system_app_items);

    /* Build the System record list for display */
    printf("Building each settings_05 record for display\n");
    for(int j = 0; j < ttl_system_app_items; j++) {
        if(is_end(settings_05_list[j].settings_id)) {
            printf("item: %d -- settings_name: %s\n",j,settings_05_list[j].settings_name);
            break;
        } else {
            printf("settings_id: %s -- settings_name: %s\n",settings_05_list[j].settings_id,settings_05_list[j].settings_name);
        }
    }

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_settings[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_settings[back_to_home], 130, 50);
    lv_obj_align(back_to_settings[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);
    lv_obj_set_style_opa(back_to_settings[back_to_home], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_settings[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, 25, 45);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Settings_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_obj_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 92);
    lv_label_set_text(list_name, "Your system");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add a list item separator just beneath the page label item */
    lv_obj_t * list_item_separator = lv_img_create(image);
    lv_img_set_src(list_item_separator, &Linez);
    lv_obj_align(list_item_separator, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 136);

/***  MAIN LIST ITEMS  ***/
    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_system_app_items];

    /* Icon and label objects here */
    lv_obj_t * system_label[ttl_system_app_items];
    lv_obj_t * system_description[ttl_system_app_items];
    lv_obj_t * system_item_overlay[ttl_system_app_items];

    /* Add settings features as clickable buttons */
    int offset; 
    for(int system_list_counter = 0; system_list_counter < ttl_system_app_items; system_list_counter++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        offset = system_list_counter * 60;

        /* Settings list item button overlay */
        system_item_overlay[system_list_counter] = lv_btn_create(image);
        lv_obj_set_size(system_item_overlay[system_list_counter], 342, 56);
        lv_obj_align(system_item_overlay[system_list_counter], LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 141 + offset);
        lv_obj_set_style_opa(system_item_overlay[system_list_counter], LV_OPA_0, LV_PART_MAIN);
        /* Uncomment this to enable clicking to some other screen */
        // lv_obj_add_event_cb(system_item_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)system_list_counter);

        /* Feature selection label */
        system_label[system_list_counter] = lv_label_create(image);
        lv_label_set_recolor(system_label[system_list_counter], true);
        lv_label_set_text(system_label[system_list_counter], settings_05_list[system_list_counter].settings_name);
        lv_obj_add_style(system_label[system_list_counter], &name_style_24, LV_PART_MAIN);
        lv_obj_set_style_text_color(system_label[system_list_counter], lv_color_white(), 0);
        lv_obj_align(system_label[system_list_counter], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 157 + offset);

        /* Feature selection label */
        system_description[system_list_counter] = lv_label_create(image);
        lv_label_set_recolor(system_description[system_list_counter], true);
        lv_label_set_text(system_description[system_list_counter], settings_05_list[system_list_counter].settings_description);
        lv_obj_add_style(system_description[system_list_counter], &name_style_24, LV_PART_MAIN);
        lv_obj_set_style_text_color(system_description[system_list_counter], lv_color_hex(HEADING_SUBDUED_COLOR), 0);
        lv_obj_align(system_description[system_list_counter], LV_ALIGN_TOP_RIGHT, NORMAL_PAD_RIGHT, 157 + offset);

        /* Add a list item separator line at the end of the list item */
        list_item_tail[system_list_counter] = lv_img_create(image);
        lv_img_set_src(list_item_tail[system_list_counter], &Linez);
        lv_obj_align(list_item_tail[system_list_counter], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 199 + offset);
    }

    /* Use the previous last Height [199] + an extra 10 + previous offset [240] of spacing as the firset element to follow the list */
    int first_element_spacing =  199 + 10 + offset;
    // printf("\nOffset: %d  --  first_element_spacing: %d\n",offset,first_element_spacing);

/***   RESET O MINI SERVER   ***/
    /* Reset button overlay */
    lv_obj_t * reset_device_overlay = lv_btn_create(image);
    lv_obj_set_size(reset_device_overlay, 342, 56);
    lv_obj_align(reset_device_overlay, LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, first_element_spacing);
    lv_obj_set_style_opa(reset_device_overlay, LV_OPA_0, LV_PART_MAIN);

    /* Use this function call to reset the device -- for now, this will just quit the app */
    lv_obj_add_event_cb(reset_device_overlay, quit_application, LV_EVENT_CLICKED, NULL);

    /* Reset button icon */
    lv_obj_t * reset_image = lv_img_create(image);
    lv_img_set_src(reset_image, &Icon_Refresh_Single_Yellow);
    lv_obj_align(reset_image, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 12 + first_element_spacing);
    lv_obj_add_style(reset_image, &reset_style_img, 0);

    /* Reset label text */
    lv_obj_t * reset_label = lv_label_create(image);
    lv_label_set_recolor(reset_label, true);
    lv_label_set_text(reset_label, "Device Reset");
    lv_obj_add_style(reset_label, &name_style_24, LV_PART_MAIN);
    lv_obj_set_style_text_color(reset_label, lv_color_hex(RESET_COLOR), 0);
    lv_obj_align(reset_label, LV_ALIGN_TOP_LEFT, 68, 14 + first_element_spacing);

/***   POWER OFF O MINI SERVER   ***/
    /* Power Off button overlay */
    lv_obj_t * quit_device_overlay = lv_btn_create(image);
    lv_obj_set_size(quit_device_overlay, 342, 56);
    lv_obj_align(quit_device_overlay, LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 56 + first_element_spacing);
    lv_obj_set_style_opa(quit_device_overlay, LV_OPA_0, LV_PART_MAIN);

    /* Use this function call to quit the application */
    lv_obj_add_event_cb(quit_device_overlay, quit_application, LV_EVENT_CLICKED, NULL);

    /* Power Off button icon */
    lv_obj_t * quit_image = lv_img_create(image);
    lv_img_set_src(quit_image, &Icon_Power_Button_Yellow);
    lv_obj_align(quit_image, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 70 + first_element_spacing);
    lv_obj_add_style(quit_image, &power_off_style_img, 0);

    /* Power Off label text */
    lv_obj_t * quit_label = lv_label_create(image);
    lv_label_set_recolor(quit_label, true);
    lv_label_set_text(quit_label, "Power Off");
    lv_obj_add_style(quit_label, &name_style_24, LV_PART_MAIN);
    lv_obj_set_style_text_color(quit_label, lv_color_hex(POWER_OFF_COLOR), 0);
    lv_obj_align(quit_label, LV_ALIGN_TOP_LEFT, 68, 72 + first_element_spacing);
}


/***  Settings App Initialization  ***/
void settings_menu_setup(void)
{
    printf("SETTINGS MENU init...\n");

    lv_obj_t * settings_page = lv_obj_create(NULL);
    menu_dispatch_table[SETTINGS_VEC] = settings_page;

    lv_obj_center(settings_page);
    lv_obj_set_style_bg_color(settings_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(settings_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(settings_page, true, 3);
    lv_obj_set_scroll_dir(settings_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(settings_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(settings_page, LV_OBJ_FLAG_SCROLLABLE | LV_SCROLLBAR_MODE_ON);

    /* SETTINGS VIEW: Display the content for settings_01_view -- Connections */
    printf("\nSETTINGS_01_VIEW launch...\n");
    settings_01_view(settings_page);

    /* SETTINGS VIEW: Display the content for settings_03_view -- Storage */
    printf("\nSETTINGS_03_VIEW launch...\n");
    settings_04_view(settings_page);

    /* SETTINGS VIEW: Display the content for settings_04_view -- Battery */
    printf("\nSETTINGS_04_VIEW launch...\n");
    settings_03_view(settings_page);

    /* SETTINGS VIEW: Display the content for settings_05_view -- System */
    printf("\nSETTINGS_05_VIEW launch...\n");
    settings_05_view(settings_page);

    /* SETTINGS VIEW: Display the content for settings_00_view -- Your Settings */
    printf("\nSETTINGS_00_VIEW launch...\n");
    settings_00_view(settings_page);

    scroll_to_home();
}
