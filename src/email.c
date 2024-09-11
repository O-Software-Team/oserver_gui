#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Initialize/populate the Song list struct */
#include "content/inc/messages/email/00.h"   /* Full Device List -and- State Machine Baseline */

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

/* Email Message alignment for From, Subject, Full Message, and Item separator lines */
#define MESSAGE_TEXTAREA_HEIGHT 290
#define MESSAGE_TEXTAREA_WIDTH 332
#define MESSAGE_TEXTAREA_MASK_WIDTH 332
#define MESSAGE_TEXTAREA_MASK_HEIGHT 100

#define EMAIL_MESSAGE_PAD_LEFT 30
#define EMAIL_MESSAGE_SUBJECT 120
#define EMAIL_MESSAGE_CONTENT 184
#define EMAIL_SUBJECT_LINE_SPACING 5.5
#define EMAIL_MESSAGE_LINE_SPACING 5.5
#define LIST_LEFT_ALIGNED 25
#define LIST_CONTENT_ITEM 50

/* Message content attributes */
#define MESSAGE_CONTENT_COLOR 0xADB1A2

/* Bottom of viewport attributes */
#define OVERLAY_WIDTH 345
#define OVERLAY_HEIGHT 70
#define OVERLAY_POS_LEFT 20
#define OVERLAY_POS_FROM_TOP 440
#define OVERLAY_COLOR 0x0F0F0F

/* Font definitions */
#define LV_FONT_MONTSERRAT_44 1
#define FONT_SIZE_WORKS 0

/***  Main background and radio controls declared below  ***/
LV_IMG_DECLARE(Background);
LV_IMG_DECLARE(Icon_Back);
LV_IMG_DECLARE(Icon_WiFi_White);
LV_IMG_DECLARE(Icon_Bluetooth_White);
LV_IMG_DECLARE(Icon_NFC_White);

/* Main HEADING iconography */
LV_IMG_DECLARE(Email_App_Heading_Title);

/* Visual queue iconagraphy like status dots declared below */
LV_IMG_DECLARE(Icon_Status_Active);
LV_IMG_DECLARE(Icon_Status_Disable);

/* Standard list control iconography declared below */
LV_IMG_DECLARE(Icon_Filter_Button);
LV_IMG_DECLARE(Icon_List_Item_Divider);

LV_IMG_DECLARE(Icon_Email_Unread_Yellow);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Time);
LV_IMG_DECLARE(Linez);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);
// LV_FONT_DECLARE(NeueHaasDisplayLight_32);


static int email_list_offset_value = 90;
static int ttl_height = 0;
static int ttl_calc_overlay_height = 0;
static int ttl_calc_overlay_offset = 0;

/* Set total number of pages / screens -- this includes screen #1 which is the main found devices list screen */
#define NUM_SCREENS 5

/* Create elements to support the rolling 2FA 6-digit code screen */
#define NUM_2FA_DIGITS 6
#define UPDATE_INTERVAL_2FA 1000
#define ANIM_DURATION 3500

static lv_style_t roller_style;
static lv_style_t selected_style;
static lv_style_t item_style;

/* Set the array to store the screen reference pointers */
lv_obj_t * email_objects[NUM_SCREENS];

/* Set the BACK-TO-HOME array to use in a custom back button for this app */
static lv_obj_t * back_to_home_screen[NUM_SCREENS];

/* This is the primary "home page" element in this app */
static const int back_to_home = 2;

/* This is the main Device List screen showing all devices and their statuses */
static const int email_detail_screen = 1;

/* This is the main Add Device screen with the pairing code function */
static int prev_scr = 0;

/* Place all container definitions here to ensure all data can be found throughout */
// lv_obj_t * email_list_container;
// lv_obj_t * email_detail_container;
// lv_obj_t * email_list_item_01;

// lv_obj_t * disabled_pick_list_container;
// lv_obj_t * pairing_container;

/* Counters */
static int ttl_items;
static int ttl_email_items = 0;

/* Set variables for all the contacts content fields: ID, NAME, EMAIL, PHONE, etc */
static lv_obj_t * email_view_subject;
static lv_obj_t * email_view_message;


static lv_obj_t * list_item_tail[];
static lv_obj_t * list_item_separator[];

/* Set variables to calculate and then truncate strings too wide for the viewport -- insert an ellipsis in place of the long string */
const char * from_string;
int from_count;
const char * subject_string;
int subject_count;
const char * message_string;
int message_count;

/* Set variables for all the message content fields: ID, FROM, SUBJECT, MESSAGE */
lv_obj_t * email_id;
lv_obj_t * email_from;
lv_obj_t * email_subject;
lv_obj_t * email_status;
lv_obj_t * email_message;
lv_obj_t * top_of_list_items;
lv_obj_t * spacer;
static lv_obj_t * email_item_overlay[];

/* Set style references */
static lv_style_t back_button_style;
static lv_style_t name_style_20;
static lv_style_t name_style_24;
static lv_style_t name_style_32;

static lv_style_t label_style;
static lv_style_t italic_style;

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

static screen_scroll_overlay_cb(lv_event_t * e) {
    int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
    printf("EXEC :: screen_scroll_overlay_cb() [%d]\n\n",screen_index);
}

/* Scroll to the home screen as the final step in the settings app launch */
static void scroll_to_home(void) {
    // printf("EXEC :: scroll_to_home()\n\n");
    lv_obj_scroll_to_view(email_objects[back_to_home], LV_ANIM_OFF);
}

/* Scroll to screen clicked in the clickback call */
static void scroll_to_screen(lv_event_t* e) {
    int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
    // printf("EXEC :: scroll_to_screen() [%d]\n\n",screen_index);
    lv_obj_scroll_to_view(email_objects[screen_index], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

/* Function to update data on the Email View screen */
static void update_email_viewer(const char * subject, const char * message) {
    /* Calculate if the SUBJECT field is greater than or equal to 37 characters */
    subject_string = subject;
    subject_count = strlen(subject_string);
    if(subject_count > 24) {
        lv_obj_align(email_view_message, LV_ALIGN_TOP_LEFT, EMAIL_MESSAGE_PAD_LEFT, 206);
    } else {
        lv_obj_align(email_view_message, LV_ALIGN_TOP_LEFT, EMAIL_MESSAGE_PAD_LEFT, 184);
    }

    lv_label_set_text(email_view_subject, subject);
    lv_textarea_set_text(email_view_message, message);
}

/* Function to find a calendar item information in the 'calendar_notes' element */
static email_item * find_email_by_id(const char * id_to_find) {
    for (size_t i = 0; i < sizeof(email_00_list) / sizeof(email_item); ++i) {
        if (strcmp(email_00_list[i].email_id, id_to_find) == 0) {
            return &email_00_list[i];
        }
    }
    return NULL;  // Email item not found
}

/* This function is used to display the appropriate crypto info based upon the line item the user clicks */
static void display_email_info_cb(lv_event_t * e) {
    const char *screen_index = (const char *)lv_event_get_user_data(e);
    email_item * found_info = find_email_by_id(screen_index);
    update_email_viewer(found_info->email_subject, found_info->email_message);

    lv_obj_scroll_to_view(email_objects[1], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

static void calc_dataset_items() {
    /* Calculate total Email records */
    // printf("\nCalculate contact records...\n");
    for(ttl_items = 0; !is_end(email_00_list[ttl_items].email_id); ttl_items++) {
        ttl_email_items = ttl_items+1;
        // printf("Item count: %d -- email_id: %s\n",ttl_email_items,email_00_list[ttl_items].email_id);
    }
    // printf("\nTotal Records: %d\n\n",ttl_email_items);

    /* Build the Email record list for display */
    // printf("Building each Email record for display\n");
    for(int j = 0; j < ttl_email_items; j++) {
        if(is_end(email_00_list[j].email_id)) {
            // printf("item: %d -- calendar_notes: %s\n",j,email_00_list[j].calendar_notes);
            break;
        } else {
            // printf("email_id: %s -- calendar_name: %s\n",email_00_list[j].email_id,email_00_list[j].calendar_name);
        }
    }
    // printf("func -- ttl_email_items: %d\n", ttl_email_items);
}

// static const int EMAIL_LIST_MAX = sizeof(email_list) / sizeof(email_item);

/* Set variables to calculate and then truncate strings too wide for the viewport -- insert an ellipsis in place of the long string */
const char * from_string;
int from_count;
const char * subject_string;
int subject_count;
const char * message_string;
int message_count;

/* Set variables for all the message content fields: ID, FROM, SUBJECT, MESSAGE */
lv_obj_t * email_id;
lv_obj_t * email_from;
lv_obj_t * email_subject;
lv_obj_t * email_status;
lv_obj_t * email_message;
lv_obj_t * top_of_list_items;
lv_obj_t * spacer;

/* The following function populates the main screen with read and unread emails */
void email_list_init(lv_obj_t * email_page) {
    lv_obj_t * image = lv_img_create(email_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the email detail viewer screen */
    int scr_nbr = 2;

    /* Store the pointer to the current screen being viewed */
    email_objects[scr_nbr] = image;
    lv_obj_set_style_bg_img_src(image, &Background, 0);

/***  HEADING ELEMENTS  ***/
    render_back_button(image, (back_button_cb_t)back_home_button_cb);

    /* 'Filter' button to filter the email messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header using iconography at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Email_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the email list heading */
    lv_obj_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, 30, 112);
    lv_label_set_text(list_name, "All emails");
    lv_obj_set_style_text_color(list_name, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line above the list item set
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 154);

    int email_row_counter = 0;
    int offset = 0;
    int email_list_item = 0;
    int email_view_scr = 1;

    /* Add (simulated) email messages as clickable buttons*/
    for (email_list_item = 0; email_list_item < ttl_email_items; email_list_item++) {
        // offset =  -64 + (92 * email_list_item);
        offset = email_list_item * 90;

        /* Calculate if the FROM field is greater than or equal to 25 characters */
        from_string = email_00_list[email_list_item].email_from;
        from_count = strlen(from_string);

        /* Calculate if the SUBJECT field is greater than or equal to 37 characters */
        subject_string = email_00_list[email_list_item].email_subject;
        subject_count = strlen(subject_string);

        /* Calculate if the MESSAGE field is greater than or equal to 37 characters */
        message_string = email_00_list[email_list_item].email_message;
        message_count = strlen(message_string);

        /* Get the contact_id for the item being clicked then set the event click */
        char * item_id = email_00_list[email_list_item].email_id;

        // lv_obj_t * email_clicked_id = email_00_list[email_list_item].email_id;

        /* Settings list item button overlay */
        email_item_overlay[email_list_item] = lv_btn_create(image);
        lv_obj_set_size(email_item_overlay[email_list_item], 352, 80);
        lv_obj_set_style_opa(email_item_overlay[email_list_item], LV_OPA_0, LV_PART_MAIN);
        // lv_obj_add_event_cb(email_item_overlay[email_list_item], scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)email_view_scr);
        lv_obj_add_event_cb(email_item_overlay[email_list_item], display_email_info_cb, LV_EVENT_CLICKED, (void *)item_id);
        lv_obj_align(email_item_overlay[email_list_item], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 162 + offset);

        /* Email message READ/UNREAD icon on the left */
        lv_obj_t * email_icon = lv_img_create(image);
        if(email_00_list[email_list_item].email_status == 0) {
            lv_img_set_src(email_icon, &Icon_Status_Disable);
        } else {
            lv_img_set_src(email_icon, &Icon_Email_Unread_Yellow);
        }
        lv_obj_align(email_icon, LV_ALIGN_TOP_LEFT, 25, 182 + offset);

        /* Email message FROM field */
        email_from = lv_label_create(image);
        lv_label_set_recolor(email_from, true);

        /* Calculate and then truncate if the FROM field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
        if(from_count >= 25) {
            lv_label_set_text(email_from, email_00_list[email_list_item].email_from);
            lv_label_cut_text(email_from,23,from_count);
            lv_label_ins_text(email_from,25,"...");
        } else {
            lv_label_set_text(email_from, email_00_list[email_list_item].email_from);
        }
        lv_obj_set_style_text_color(email_from, lv_color_white(), 0);
        lv_obj_set_style_text_font(email_from, &NeueHaasDisplayLight_24, LV_PART_MAIN);
        lv_obj_align(email_from, LV_ALIGN_TOP_LEFT, 55, 176 + offset);

        /* Email message SUBJECT field */
        email_subject = lv_label_create(image);
        lv_label_set_recolor(email_subject, true);

        /* Calculate and then truncate if the SUBJECT field is greater than or equal to 37 characters; then insert an ellipsis in place of the long string */
        if(subject_count >= 37) {
            lv_label_set_text(email_subject, email_00_list[email_list_item].email_subject);
            lv_label_cut_text(email_subject, 35, subject_count);
            lv_label_ins_text(email_subject, 37, "...");
        } else {
            lv_label_set_text(email_subject, email_00_list[email_list_item].email_subject);
        }
        lv_obj_set_style_text_color(email_subject, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
        lv_obj_set_style_text_line_space(email_subject, EMAIL_MESSAGE_LINE_SPACING, LV_PART_MAIN);
        lv_obj_set_style_text_font(email_subject, &NeueHaasDisplayLight_20, LV_PART_MAIN);
        lv_obj_align(email_subject, LV_ALIGN_TOP_LEFT, 55, 210 + offset);

        /* Read email message */
        lv_obj_t * email_next = lv_img_create(image);
        lv_img_set_src(email_next, &Icon_Next_White);
        lv_obj_align(email_next, LV_ALIGN_TOP_RIGHT, -25, 194 + offset);

        /* Add a list item separator line at the end of the list item */
        list_item_tail[email_list_item] = lv_img_create(image);
        lv_img_set_src(list_item_tail[email_list_item], &Linez);
        lv_obj_align(list_item_tail[email_list_item], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 246 + offset);
    }
}

void email_message_view(lv_obj_t * email_message_page) {
    lv_obj_t * image = lv_img_create(email_message_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the email detail viewer screen */
    int scr_nbr = 1;

    /* Store the pointer to the current screen being viewed */
    email_objects[scr_nbr] = image;
    lv_obj_set_style_bg_img_src(image, &Background, 0);

    static const int EMAIL_MESSAGE_ID = 0;

    /* Back button */
    // render_back_button(image, (back_button_cb_t)back_home_button_cb);

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button overlay */
    lv_obj_t * back_to_device_list = lv_btn_create(image);
    lv_obj_set_size(back_to_device_list, 130, 50);
    lv_obj_set_style_opa(back_to_device_list, LV_OPA_90, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_device_list, scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_align(back_to_device_list, LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    // lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_font(back_label, &NeueHaasDisplayLight_20, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

    /* Calculate if the SUBJECT field is greater than or equal to 37 characters */
    subject_string = email_00_list[EMAIL_MESSAGE_ID].email_subject;
    subject_count = strlen(subject_string);

    /* Email SUBJECT field */
    email_view_subject = lv_label_create(image);
    lv_label_set_recolor(email_view_subject, true);

    /* Calculate and then truncate if the SUBJECT field is greater than or equal to 37 characters; then insert an ellipsis in place of the long string */
    if(subject_count >= 37) {
        lv_label_set_text(email_view_subject, email_00_list[EMAIL_MESSAGE_ID].email_subject);
        lv_label_cut_text(email_view_subject,35,subject_count);
        lv_label_ins_text(email_view_subject,37,"...");
    } else {
        lv_label_set_text(email_view_subject, email_00_list[EMAIL_MESSAGE_ID].email_subject);
    }
    lv_obj_set_style_width(email_view_subject, MESSAGE_TEXTAREA_WIDTH, LV_PART_MAIN);
    lv_obj_set_style_text_color(email_view_subject, lv_color_white(), 0);
    lv_obj_set_style_text_font(email_view_subject, &NeueHaasDisplayLight_32, LV_PART_MAIN);
    lv_obj_align(email_view_subject, LV_ALIGN_TOP_LEFT, EMAIL_MESSAGE_PAD_LEFT, EMAIL_MESSAGE_SUBJECT);

    /* Email MESSAGE field */
    email_view_message = lv_textarea_create(image);
    lv_obj_set_scrollbar_mode(email_view_message, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_height(email_view_message, MESSAGE_TEXTAREA_HEIGHT, LV_PART_MAIN);
    lv_obj_set_style_width(email_view_message, MESSAGE_TEXTAREA_WIDTH, LV_PART_MAIN);
    lv_obj_set_style_border_width(email_view_message, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(email_view_message, 0, LV_PART_MAIN);
    lv_textarea_add_text(email_view_message, email_00_list[EMAIL_MESSAGE_ID].email_message);
    lv_obj_set_style_text_color(email_view_message, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_set_style_text_line_space(email_view_message, EMAIL_MESSAGE_LINE_SPACING, LV_PART_MAIN);
    lv_obj_set_style_text_font(email_view_message, &NeueHaasDisplayLight_22, LV_PART_MAIN);
    lv_obj_set_style_pad_all(email_view_message, 0, LV_PART_MAIN);
    lv_obj_align(email_view_message, LV_ALIGN_TOP_LEFT, EMAIL_MESSAGE_PAD_LEFT, EMAIL_MESSAGE_CONTENT);
}

void email_menu_setup(void) {
    printf("EMAIL MENU init...\n");

    calc_dataset_items();

    lv_obj_t * email_page = lv_obj_create(NULL);
    menu_dispatch_table[EMAIL_VEC] = email_page;

    lv_obj_center(email_page);
    lv_obj_set_style_bg_color(email_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(email_page, LV_FLEX_FLOW_ROW);
    //lv_obj_add_event_cb(email_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(email_page, true, 3);
    lv_obj_set_scroll_dir(email_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(email_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(email_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* MESSAGE VIEW: Display the email message SUBJECT and MESSAGE */
    email_message_view(email_page);

    /* MAIN-SCREEN: Display the list of emails: unread and read comingled together */
    email_list_init(email_page);

    scroll_to_home();
}