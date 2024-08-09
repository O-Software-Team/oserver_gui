#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Initialize/populate the Contacts list struct */
#include "content/inc/contacts/00.h"   /* Main screen - Favorite Contacts list */
#include "content/inc/contacts/01.h"   /* Full Contacts list */

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

/* Contact list and contact ID variables */
#define CONTACT_ID 0   // This is temporary until the second contacts list dataset is being accessed
#define CONTACT_LIST_MAX 20
// #define CONTACT_FOUND_MAX 0
#define CONTACT_ID 0

/* Contact screen alignment for Name, Phone, SMS, and Email separator lines */
#define CONTACT_HEIGHT 290
#define CONTACT_WIDTH 332
#define CONTACT_MASK_WIDTH 332
#define CONTACT_MASK_HEIGHT 100

#define CONTACT_PAD_LEFT 30
#define CONTACT_NOTES 120
#define CONTACT_CONTENT 186
#define CONTACT_LINE_SPACING 5.5

#define LIST_LEFT_ALIGNED 25
#define LIST_SEPARATOR 30
#define LIST_CONTENT_ITEM 50

/* Contact content attributes */
#define CONTACT_CONTENT_COLOR 0xADB1A2

/* Bottom of viewport attributes */
#define OVERLAY_WIDTH 345
#define OVERLAY_HEIGHT 70
#define OVERLAY_POS_LEFT 20
#define OVERLAY_POS_FROM_TOP 440
#define OVERLAY_COLOR 0x0F0F0F

#define LV_FONT_MONTSERRAT_44 1

#define FONT_SIZE_WORKS 0 // Until it's figured out

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

/* Main HEADING iconography */
LV_IMG_DECLARE(Contacts_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

/***  Contacts Specific Declarations  ***/

/* Set total number of pages / screens -- this includes screen #1 which is the main contacts screen to screen #4 which is the spreadsheets screen */
#define NUM_SCREENS 4

/* Set the array to store the screen reference pointers */
lv_obj_t * contact_objects[NUM_SCREENS];

/* Set the BACK-TO-HOME array to use in a custom back button for the filesystem app */
static lv_obj_t * back_to_home_screen[NUM_SCREENS];

/* This is the primary "home page" element in the Settings app */
static const int back_to_home = 0;

/* Contact Card fields required for population */
lv_obj_t * contact_initials;
lv_obj_t * contact_name;
lv_obj_t * contact_m_phone;
lv_obj_t * contact_p_email;
lv_obj_t * contact_company_name;
lv_obj_t * contact_notes;

/* Set style references */
static lv_style_t reset_style_img;
static lv_style_t power_off_style_img;
static lv_style_t back_button_style;
static lv_style_t name_style_20;
static lv_style_t name_style_24;

static lv_style_t label_style;
static lv_style_t italic_style;

static lv_style_t wrap_content_style;

/***  Init styles specific to Settings  ***/
static void init_styles() {
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
    // printf("EXEC :: scroll_to_home()\n\n");
    lv_obj_scroll_to_view(contact_objects[back_to_home], LV_ANIM_OFF);
}

/* Scroll to screen clicked in the clickback call */
static void scroll_to_screen(lv_event_t* e) {
    int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
    // printf("EXEC :: scroll_to_screen() [%d]\n\n",screen_index);
    lv_obj_scroll_to_view(contact_objects[screen_index], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

/* Function to update contact data on the contact card screen */
static void update_contact_card(const char *initials, const char *name, const char *phone, const char *email, const char *company_name, const char *notes) {
    lv_label_set_text(contact_initials, initials);
    lv_label_set_text(contact_name, name);
    lv_label_set_text(contact_m_phone, phone);
    lv_label_set_text(contact_p_email, email);
    lv_label_set_text(contact_company_name, company_name);
    lv_label_set_text(contact_notes, notes);
}

/* Function to find a contact by ID */
static contacts_item *find_contact_by_id(const char *id_to_find) {
    for (size_t i = 0; i < sizeof(contacts_00_list) / sizeof(contacts_item); ++i) {
        if (strcmp(contacts_00_list[i].contact_id, id_to_find) == 0) {
            return &contacts_00_list[i];
        }
    }
    return NULL;  // Contact not found
}

static void display_card_event_cb(lv_event_t * e) {
    const char *screen_index = (const char *)lv_event_get_user_data(e);

    contacts_item *found_contact = find_contact_by_id(screen_index);
    update_contact_card(found_contact->contact_initials, found_contact->contact_name, found_contact->contact_m_phone, found_contact->contact_p_email, found_contact->contact_company_name, found_contact->contact_notes);

    lv_obj_scroll_to_view(contact_objects[1], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
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


/***** TODO

  3) Bring both the Favorites contacts list and the Full contacts list into the app

*****/


/* Set variables to determine total number of items per list */
// static int favorites_menu_item;    /* 01.h */
static int favorites_menu_record;
static int ttl_favorites_menu_items = 1;

// static int folder_item;        /* 02.h */
// static int folder_record;
// static int ttl_folder_items = 1;

// static int movie_item;         /* 03.h */
// static int movie_record;
// static int ttl_movie_items = 1;

/* Set variables to determine total number of Contacts list members */
// static int total_contact_items = 1;
static int ttl_items;

/* Set variables to calculate and then truncate strings too wide for the viewport -- insert an ellipsis in place of the long string */
static const char * name_string;
static int name_count;
static const char * email_string;
static int email_count;
static const char * company_string;
static int company_count;
static const char * notes_string;
static int notes_count;

/* Set variables for all the contacts content fields: ID, NAME, EMAIL, PHONE, etc */
lv_obj_t * contact_name;
lv_obj_t * contact_p_email;
lv_obj_t * contact_m_phone;
lv_obj_t * contact_company_name;
lv_obj_t * contact_notes;

lv_obj_t * contact_initials_bg;
lv_obj_t * contact_initials;

lv_obj_t * heading_mobile;
lv_obj_t * heading_email;
lv_obj_t * heading_company;
lv_obj_t * heading_notes;

// lv_label_t * contact_detail_from;
static lv_obj_t * top_of_list_items;

/* Set the BACK-TO-HOME array to use in a custom back button for the Settings app */
lv_obj_t * back_to_contacts[NUM_SCREENS];

/***  SCREEN 00 - Contacts List page  ***/
static void contacts_00_view(lv_obj_t * contacts_00_view_page) {
    lv_obj_t * image = lv_img_create(contacts_00_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 0;
    // printf("Contacts page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    contact_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

    /* Calculate total Contact records */
    // printf("\nCalculate contact records...\n");
    for(ttl_items = 0; !is_end(contacts_00_list[ttl_items].contact_id); ttl_items++) {
        ttl_favorites_menu_items = ttl_items+1;
        // printf("Item count: %d -- contact_id: %s\n",ttl_favorites_menu_items,contacts_00_list[ttl_items].contact_id);
    }
    // printf("\nTotal Records: %d\n\n",ttl_favorites_menu_items);

    /* Build the Contact record list for display */
    // printf("Building each Contact record for display\n");
    for(int j = 0; j < ttl_favorites_menu_items; j++) {
        if(is_end(contacts_00_list[j].contact_id)) {
            // printf("item: %d -- contact_notes: %s\n",j,contacts_00_list[j].contact_notes);
            break;
        } else {
            // printf("contact_id: %s -- contact_name: %s\n",contacts_00_list[j].contact_id,contacts_00_list[j].contact_name);
        }
    }

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
    lv_label_set_text(list_name, "Favorites");
    lv_obj_set_style_text_color(list_name, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line below the list item header
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 136);

    /* These keep the alignment settings evenly spaced when in a for loop */
    // lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    // lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_favorites_menu_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_tail[ttl_favorites_menu_items];
    lv_obj_t * display_feature_overlay;
    int ttl_overlay_width = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height = 662;  // Set this to the last lv_obj_align() padding height minus 40

    /* Icon and label objects here */
    lv_obj_t * contacts_label[ttl_favorites_menu_items];
    lv_obj_t * contacts_icon[ttl_favorites_menu_items];
    lv_obj_t * contacts_item_overlay[ttl_favorites_menu_items];

/***  MAIN CLICKABLE LIST ITEMS  ***/
    /* Add settings features as clickable buttons */
    for(int favorites_menu_record = 0; favorites_menu_record < ttl_favorites_menu_items; favorites_menu_record++) {
        /* Increment the page reference number for each Settings page */
        scr_nbr++;

        /* A row-by-row offset value to maintain spacing between clickable elements */
        int offset = favorites_menu_record * 60;

        /* Settings list item button overlay */
        contacts_item_overlay[scr_nbr] = lv_btn_create(image);
        lv_obj_set_size(contacts_item_overlay[scr_nbr], 352, 56);
        lv_obj_align(contacts_item_overlay[scr_nbr], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 141 + offset);
        lv_obj_set_style_opa(contacts_item_overlay[scr_nbr], LV_OPA_0, LV_PART_MAIN);

        /* Get the contact_id for the item being clicked then set the event click */
        char *item_id = contacts_00_list[favorites_menu_record].contact_id;
        lv_obj_add_event_cb(contacts_item_overlay[scr_nbr], display_card_event_cb, LV_EVENT_CLICKED, (void *)item_id);  // Use this for debugging

        /* Feature selection label */
        contacts_label[scr_nbr] = lv_label_create(image);
        lv_label_set_recolor(contacts_label[scr_nbr], true);
        lv_label_set_text(contacts_label[scr_nbr], contacts_00_list[favorites_menu_record].contact_name);
        lv_obj_add_style(contacts_label[scr_nbr], &name_style_24, LV_PART_MAIN);
        lv_obj_set_style_text_color(contacts_label[scr_nbr], lv_color_white(), 0);
        // lv_obj_set_style_text_font(contacts_label[scr_nbr], &NeueHaasDisplayLight_24, LV_PART_MAIN);
        lv_obj_align(contacts_label[scr_nbr], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 157 + offset);

        contacts_icon[scr_nbr] = lv_img_create(image);
        lv_img_set_src(contacts_icon[scr_nbr], &Icon_Next_White);
        lv_obj_align(contacts_icon[scr_nbr], LV_ALIGN_TOP_LEFT, 344, 162 + offset);
        lv_obj_set_style_opa(contacts_icon[scr_nbr], LV_OPA_70, LV_PART_MAIN);

        // Add a list item separator line at the end of the list item
        list_item_tail[scr_nbr] = lv_img_create(image);
        lv_img_set_src(list_item_tail[scr_nbr], &Linez);
        lv_obj_align(list_item_tail[scr_nbr], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 199 + offset);
    }

}

/***  SCREEN 01 - Contact Card page  ***/
// void contacts_view(lv_obj_t * contacts_01_view_page) {
static void contacts_01_view(lv_obj_t * contacts_01_view_page) {
    lv_obj_t * image = lv_img_create(contacts_01_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 1;
    // printf("Contacts page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    contact_objects[scr_nbr] = image;
    lv_img_set_src(image, &Background);

/***  Contacts Specific Style Declarations  ***/
    init_styles();

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    back_to_contacts[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_contacts[back_to_home], 130, 50);
    lv_obj_set_style_opa(back_to_contacts[back_to_home], LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_contacts[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_align(back_to_contacts[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

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
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

/***  MAIN LIST ITEMS  ***/
    /* Set the objects for list item separators and overlay elements for each feature here */
    lv_obj_t * list_item_tail[5];
    lv_obj_t * display_feature_overlay;
    int ttl_overlay_width = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height = 602;  // Set this to the last lv_obj_align() padding height minus 40

    /* Display full screen height overlay to enable scrolling */
    display_feature_overlay = lv_img_create(image);
    lv_obj_set_size(display_feature_overlay, ttl_overlay_width, ttl_overlay_height);
    lv_obj_set_style_opa(display_feature_overlay, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(display_feature_overlay, image_click_event_cb, LV_EVENT_CLICKED, NULL);  // Use this for debugging
    lv_obj_align(display_feature_overlay, LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 94);

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_favorites_menu_items];

/* INITIALS-OVER-IMAGE ELEMENT HERE */
    /* Contact Initials Background image */
    contact_initials_bg = lv_img_create(image);
    lv_img_set_src(contact_initials_bg, &Icon_Contact_Initials_Background);
    lv_obj_align(contact_initials_bg, LV_ALIGN_TOP_MID, 0, 24);

    /* Contact Initials text */
    contact_initials = lv_label_create(image);
    lv_label_set_text(contact_initials, contacts_01_list[CONTACT_ID].contact_initials);
    lv_label_set_recolor(contact_initials, true);
    lv_obj_align(contact_initials, LV_ALIGN_TOP_MID, 0, 42);
    lv_obj_set_style_text_color(contact_initials, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_initials, &NeueHaasDisplayLight_32, LV_PART_MAIN);

/* FULL NAME BANNER HERE */
    /* Calculate if the NAME field is greater than or equal to 25 characters */
    name_string = contacts_01_list[CONTACT_ID].contact_name;
    name_count = strlen(name_string);

    /* Contact NAME field */
    contact_name = lv_label_create(image);
    lv_label_set_recolor(contact_name, true);

    /* Calculate and then truncate if the NAME field is greater than or equal to 27 characters; then insert an ellipsis in place of the long string */
    if(name_count >= 27) {
        lv_label_set_text(contact_name, contacts_01_list[CONTACT_ID].contact_name);
        lv_label_cut_text(contact_name,25,name_count);
        lv_label_ins_text(contact_name,27,"...");
    } else {
        lv_label_set_text(contact_name, contacts_01_list[CONTACT_ID].contact_name);
    }

    /* Contact Name field */
    lv_obj_set_style_text_color(contact_name, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_name, &NeueHaasDisplayLight_32, LV_PART_MAIN);
    lv_obj_align(contact_name, LV_ALIGN_TOP_MID, 0, 120);

/* MOBILE NUMBER FIELD HERE */
    /* Contact Mobile heading */
    heading_mobile = lv_label_create(image);
    lv_label_set_recolor(heading_mobile, true);
    lv_label_set_text(heading_mobile, "Mobile");
    lv_obj_set_style_text_color(heading_mobile, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(heading_mobile, &NeueHaasDisplayLight_20, LV_PART_MAIN);
    lv_obj_align(heading_mobile, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 180);

    /* Contact Mobile Number field */
    contact_m_phone = lv_label_create(image);
    lv_label_set_recolor(contact_m_phone, true);
    lv_label_set_text(contact_m_phone, contacts_01_list[CONTACT_ID].contact_m_phone);
    lv_obj_set_style_text_color(contact_m_phone, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_m_phone, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(contact_m_phone, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 212);

    /* Add a list item separator line below the list item text */
    list_item_separator[CONTACT_ID] = lv_img_create(image);
    lv_img_set_src(list_item_separator[CONTACT_ID], &Linez);
    lv_obj_align(list_item_separator[CONTACT_ID], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 252);

/* EMAIL FIELD HERE */
    /* Contact Email heading */
    heading_email = lv_label_create(image);
    lv_label_set_recolor(heading_email, true);
    lv_label_set_text(heading_email, "Email");
    lv_obj_set_style_text_color(heading_email, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(heading_email, &NeueHaasDisplayLight_20, LV_PART_MAIN);
    lv_obj_align(heading_email, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 272);

    /* Calculate if the EMAIL field is greater than or equal to 27 characters */
    email_string = contacts_01_list[CONTACT_ID].contact_p_email;
    email_count = strlen(email_string);

    /* Contact Email field */
    contact_p_email = lv_label_create(image);
    lv_label_set_recolor(contact_p_email, true);

    /* Calculate and then truncate if the EMAIL field is greater than or equal to 27 characters; then insert an ellipsis in place of the long string */
    if(email_count >= 27) {
        lv_label_set_text(contact_p_email, contacts_01_list[CONTACT_ID].contact_p_email);
        lv_label_cut_text(contact_p_email,25,email_count);
        lv_label_ins_text(contact_p_email,27,"...");
    } else {
        lv_label_set_text(contact_p_email, contacts_01_list[CONTACT_ID].contact_p_email);
    }

    /* Contact Email field */
    lv_obj_set_style_text_color(contact_p_email, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_p_email, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(contact_p_email, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 304);

    /* Add a list item separator line below the list item text */
    list_item_separator[CONTACT_ID] = lv_img_create(image);
    lv_img_set_src(list_item_separator[CONTACT_ID], &Linez);
    lv_obj_align(list_item_separator[CONTACT_ID], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 344);

/* COMPANY NAME FIELD HERE */
    /* Contact Company heading */
    heading_company = lv_label_create(image);
    lv_label_set_recolor(heading_company, true);
    lv_label_set_text(heading_company, "Company");
    lv_obj_set_style_text_color(heading_company, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(heading_company, &NeueHaasDisplayLight_20, LV_PART_MAIN);
    lv_obj_align(heading_company, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 364);

    /* Calculate if the COMPANY field is greater than or equal to 27 characters */
    company_string = contacts_01_list[CONTACT_ID].contact_company_name;
    company_count = strlen(company_string);

    /* Contact NAME field */
    contact_company_name = lv_label_create(image);
    lv_label_set_recolor(contact_company_name, true);

    /* Calculate and then truncate if the NAME field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
    if(company_count >= 27) {
        lv_label_set_text(contact_company_name, contacts_01_list[CONTACT_ID].contact_company_name);
        lv_label_cut_text(contact_company_name,25,company_count);
        lv_label_ins_text(contact_company_name,27,"...");
    } else {
        lv_label_set_text(contact_company_name, contacts_01_list[CONTACT_ID].contact_company_name);
    }

    /* Contact Name field */
    lv_obj_set_style_text_color(contact_company_name, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_company_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(contact_company_name, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 396);

    /* Add a list item separator line below the list item text */
    list_item_separator[CONTACT_ID] = lv_img_create(image);
    lv_img_set_src(list_item_separator[CONTACT_ID], &Linez);
    lv_obj_align(list_item_separator[CONTACT_ID], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 436);

/* NOTES FIELD HERE */
    /* Contact Notes heading */
    heading_notes = lv_label_create(image);
    lv_label_set_recolor(heading_notes, true);
    lv_label_set_text(heading_notes, "Notes");
    lv_obj_set_style_text_color(heading_notes, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(heading_notes, &NeueHaasDisplayLight_20, LV_PART_MAIN);
    lv_obj_align(heading_notes, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 456);

    /* Contact NOTES section */
    contact_notes = lv_label_create(image);
    lv_label_set_recolor(contact_notes, true);

    // Set the text of the label
    lv_label_set_text(contact_notes, "This is a long text string that will be wrapped within the defined area of the label.");

    // Set the size of the label to fit within a specific area
    lv_obj_set_size(contact_notes, 300, 160);  // Width and height of the label area

    // Enable text wrapping by setting the style
    lv_label_set_long_mode(contact_notes, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(contact_notes, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_notes, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(contact_notes, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 488);

    // /* Add a list item separator line below the list item text */
    // list_item_separator[CONTACT_ID] = lv_img_create(image);
    // lv_img_set_src(list_item_separator[CONTACT_ID], &Linez);
    // lv_obj_align(list_item_separator[CONTACT_ID], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 528);
}

void contacts_menu_setup(void) {
    printf("CONTACTS MENU init...\n");

    lv_obj_t * contacts_page = lv_obj_create(NULL);
    menu_dispatch_table[CONTACTS_VEC] = contacts_page;

    lv_obj_center(contacts_page);
    lv_obj_set_style_bg_color(contacts_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(contacts_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(contacts_page, true, 3);
    lv_obj_set_scroll_dir(contacts_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(contacts_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(contacts_page, LV_OBJ_FLAG_SCROLLABLE | LV_SCROLLBAR_MODE_ON);

    /* CONTACTS VIEW: Display the content for a specific contact */
    printf("\nCONTACTS_01_VIEW launch...\n");
    contacts_01_view(contacts_page);

    /* CONTACTS VIEW: Display the content for contacts_00_view -- Your Contacts */
    printf("\nCONTACTS_00_VIEW launch...\n");
    contacts_00_view(contacts_page);

    scroll_to_home();
}
