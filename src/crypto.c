#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <monetary.h>

/* Initialize/populate the Crypto list struct */
#include "content/inc/crypto/00.h"   /* Main screen - Crypto key data */

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

/* Contact list and contact ID variables */
#define CRYPTO_ID 0   // This is temporary until the crypto list dataset is being accessed

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

/* Crypto Card - Crypto Company Logos */
LV_IMG_DECLARE(Icon_Crypto_Bitcoin_Yellow);
LV_IMG_DECLARE(Icon_Crypto_Ethereum_Yellow);
LV_IMG_DECLARE(Icon_Crypto_Tether_Yellow);
LV_IMG_DECLARE(Icon_Crypto_Binance_Yellow);
LV_IMG_DECLARE(Icon_Crypto_Binance_Yellow);
LV_IMG_DECLARE(Icon_Crypto_Binance_Yellow);
LV_IMG_DECLARE(Icon_Crypto_Public_Key_Horizontal_Teal);
LV_IMG_DECLARE(Icon_Crypto_Private_Key_Horizontal_Red);

/* Main HEADING iconography */
LV_IMG_DECLARE(Crypto_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

LV_FONT_DECLARE(NeueHaasDisplayLight_32);

/***  Crypto Specific Declarations  ***/

/* Set total number of pages / screens -- this includes screen #0 which is the main crypto screen to screen #?  */
#define NUM_SCREENS 4

/* Set the array to store the screen reference pointers */
lv_obj_t * crypto_objects[NUM_SCREENS];

/* Set the BACK-TO-HOME array to use in a custom back button for the filesystem app */
static lv_obj_t * back_to_home_screen[NUM_SCREENS];

/* This is the primary "home page" element in the Settings app */
static const int back_to_home = 0;

/* Contact Card fields required for population */
lv_obj_t * crypto_company_name;
lv_obj_t * crypto_public_key_hash;
lv_obj_t * crypto_private_key_hash;
lv_obj_t * crypto_balance;
lv_obj_t * crypto_coin_and_initials;
lv_obj_t * crypto_value;
lv_obj_t * crypto_value_and_initials;
lv_obj_t * crypto_price;
lv_obj_t * crypto_icon_logo;

/* Set style references */
static lv_style_t reset_style_img;
static lv_style_t power_off_style_img;
static lv_style_t back_button_style;
static lv_style_t name_style_20;
static lv_style_t name_style_24;
static lv_style_t name_style_32;

static lv_style_t label_style;
static lv_style_t italic_style;

static lv_style_t wrap_content_style;

/***  Init styles specific  ***/

lv_obj_t * label_pre;
lv_obj_t * label;
lv_obj_t * label_post;

static lv_style_t label_style;
static lv_style_t italic_style;

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
    lv_obj_scroll_to_view(crypto_objects[back_to_home], LV_ANIM_OFF);
}

/* Scroll to screen clicked in the clickback call */
static void scroll_to_screen(lv_event_t* e) {
    int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
    // printf("EXEC :: scroll_to_screen() [%d]\n\n",screen_index);
    lv_obj_scroll_to_view(crypto_objects[screen_index], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

/* Function to update the crypto coin data on the Crypto View screen */
static void update_crypto_card(const char * company, const char * initials, const char * public_key, const char * private_key, const double balance, const double value, const double price, const char * icon_logo) {
    // Display the company name, publick key, and private key items
    lv_label_set_text(crypto_company_name, company);
    lv_label_set_text(crypto_public_key_hash, public_key);
    lv_label_set_text(crypto_private_key_hash, private_key);
    lv_img_set_src(crypto_icon_logo, icon_logo);

    // Display the coin balance
    char crypto_balance_buffer[64];
    sprintf(crypto_balance_buffer, "%.8f", balance);
    char crypto_balance_coin[64];
    sprintf(crypto_balance_coin, "%s %s", crypto_balance_buffer, initials);
    lv_label_set_text(crypto_coin_and_initials, crypto_balance_coin);

    // Display the US currency value
    display_us_currency_value(crypto_value_and_initials, value);

    /* Not using this right now -- too much */
    // char crypto_price_buffer[64];
    // sprintf(crypto_price_buffer, "%.8f", price);
    // lv_label_set_text(crypto_balance, crypto_price_buffer);
}

/* Function to find a contact by ID */
static crypto_item * find_crypto_by_id(const char *id_to_find) {
    for (size_t i = 0; i < sizeof(crypto_00_list) / sizeof(crypto_item); ++i) {
        if (strcmp(crypto_00_list[i].crypto_id, id_to_find) == 0) {
            return &crypto_00_list[i];
        }
    }
    return NULL;  // Item not found
}

/* This function wis used to display the appropriate crypto info based upon the line item the user clicks */
static void display_crypto_info_cb(lv_event_t * e) {
    const char *screen_index = (const char *)lv_event_get_user_data(e);
    crypto_item * found_info = find_crypto_by_id(screen_index);
    update_crypto_card(found_info->crypto_company_name, found_info->crypto_company_initials, found_info->crypto_public_key_hash, found_info->crypto_private_key_hash, found_info->crypto_balance, found_info->crypto_value, found_info->crypto_price, found_info->crypto_icon_logo);

    lv_obj_scroll_to_view(crypto_objects[1], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

/* This function will place the word 'Crypto' at the top - with the correct format */
static void display_app_heading_crypto(lv_obj_t * current_screen_number) {
    /* Add Crypto App Heading label  */
    label_pre = lv_label_create(current_screen_number);
    label = lv_label_create(current_screen_number);
    label_post = lv_label_create(current_screen_number);

    /* First part of the label */
    lv_label_set_recolor(label_pre, true);
    lv_obj_add_style(label_pre, &label_style, LV_PART_MAIN);

    lv_label_set_recolor(label, true);
    lv_obj_add_style(label, &italic_style, LV_PART_MAIN);

    lv_label_set_recolor(label_post, true);
    lv_obj_add_style(label_post, &label_style, LV_PART_MAIN);

    /* Middle part of the label */
    lv_label_set_text(label_pre, "Cr");
    lv_obj_set_style_text_color(label_pre, lv_color_white(), 0);

    lv_label_set_text(label, "y");
    lv_obj_set_style_text_color(label, lv_color_white(), 0);

    lv_label_set_text(label_post, "pto");
    lv_obj_set_style_text_color(label_post, lv_color_white(), 0);

    /* Last part of the label */
    lv_label_set_recolor(label_pre, true);
    lv_obj_add_style(label_pre, &label_style, LV_PART_MAIN);

    lv_label_set_recolor(label, true);
    lv_obj_add_style(label, &italic_style, LV_PART_MAIN);

    lv_label_set_recolor(label_post, true);
    lv_obj_add_style(label_post, &label_style, LV_PART_MAIN);
    
    /*
        Stole the following code from 'oserver_gui.c' -- LINES 217-255, roughly -- Dan hooked up the
        manual way of placing the text onto the screen and using LINE 56 as a guide:

        { .menu_pre = "Cr",     .menu_italic = "y",  .lx = -21, .mx = -4, .rx = 21, .menu_post = "pto",  .menu_vec = CRYPTO_VEC,   .active = true },

        We can then place the characters, using the correct font family and size, and then simply
        "adjust kerning" by manually moving each label by the correct pixels on the screen to produce
        the desired look - and spacing - between the characters.
    */

    /* Align all elements on the screen */
    lv_obj_align(label_pre, LV_ALIGN_TOP_MID, -21, 46);
    lv_obj_align(label, LV_ALIGN_TOP_MID, -4, 45);
    lv_obj_align(label_post, LV_ALIGN_TOP_MID, 21, 46);

}

static void insert_commas(char *dest, const char *src) {
    int len = strlen(src);
    int dest_index = 0;
    int comma_count = (len - 1) / 3;

    for (int i = 0; i < len; i++) {
        if (i > 0 && (len - i) % 3 == 0) {
            dest[dest_index++] = ',';
        }
        dest[dest_index++] = src[i];
    }
    dest[dest_index] = '\0';
}

// Function to format a double as US currency with commas
static void format_us_currency(char *buffer, size_t size, double value) {
    char temp[64];
    snprintf(temp, sizeof(temp), "%.2f", value); // Format to 2 decimal places

    char *decimal_point = strchr(temp, '.');
    if (decimal_point != NULL) {
        *decimal_point = '\0'; // Split the string at the decimal point
        decimal_point++; // Move past the null terminator to the decimal part
    }

    char with_commas[64];
    insert_commas(with_commas, temp); // Insert commas in the integer part

    if (decimal_point != NULL) {
        snprintf(buffer, size, "$%s.%s", with_commas, decimal_point); // Combine parts with dollar sign
    } else {
        snprintf(buffer, size, "$%s", with_commas); // No decimal part
    }
}

// Example function to convert a double to a US currency-formatted string and display it on a label
void display_us_currency_value(lv_obj_t *label, double value) {
    char buffer[64]; // Buffer to hold the formatted string
    format_us_currency(buffer, sizeof(buffer), value); // Format the double value as US currency with commas

    char crypto_balance_coin[64];
    sprintf(crypto_balance_coin, "%s USD", buffer);
    printf("crypto_balance_coin: \n", crypto_balance_coin);

    lv_label_set_text(label, crypto_balance_coin); // Set the text of the label to the formatted string
}

// static __attribute__((unused)) void image_click_event_cb(lv_event_t * e) {
static void image_click_event_cb(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    printf("crypto item clicked\n");

    // if(code == LV_EVENT_VALUE_CHANGED) {
    //     lv_calendar_date_t date;
    //     lv_calendar_get_pressed_date(obj, &date);
    //     if(date.year) {
    //         printf("Clicked date: %02d.%02d.%d\n", date.day, date.month, date.year);
    //     }
    // }
}

/* Set variables to determine total number of items per list */
// static int crypto_item;    /* 00.h */
// static int crypto_record;
static int ttl_crypto_items = 1;

/* Set variables to determine total number of Crypto list members */
// static int total_crypto_items = 1;
static int ttl_items;

/* Set variables for all the contacts content fields: ID, NAME, EMAIL, PHONE, etc */
static lv_obj_t * top_of_list_items;
static lv_obj_t * list_item_tail[];
static lv_obj_t * list_item_separator[];

/* Set the BACK-TO-HOME array to use in a custom back button for the Settings app */
lv_obj_t * back_to_crypto[NUM_SCREENS];


/***  SCREEN 00 - Crypto main page  ***/
static void crypto_00_view(lv_obj_t * crypto_00_view_page) {
    lv_obj_t * image = lv_img_create(crypto_00_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 0;
    // printf("Contacts page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    crypto_objects[scr_nbr] = image;
    lv_obj_set_style_bg_img_src(image, &Background, 0);


    /* Calculate total Crypto records */
    // printf("\nCalculate number of crypto providers...\n");
    for(ttl_items = 0; !is_end(crypto_00_list[ttl_items].crypto_id); ttl_items++) {
        ttl_crypto_items = ttl_items+1;
        // printf("Item count: %d -- crypto_id: %s\n",ttl_crypto_items,crypto_00_list[ttl_items].crypto_id);
    }
    // printf("\nTotal Records: %d\n\n",ttl_crypto_items);

    /* Build the Crypto record list for display */
    // printf("Building each Crypto record for display\n");
    for(int j = 0; j < ttl_crypto_items; j++) {
        if(is_end(crypto_00_list[j].crypto_id)) {
            // printf("item: %d -- crypto_notes: %s\n",j,crypto_00_list[j].crypto_notes);
            break;
        } else {
            // printf("crypto_id: %s -- crypto_name: %s\n",crypto_00_list[j].crypto_id,crypto_00_list[j].crypto_name);
        }
    }

/***  HEADING ELEMENTS  ***/
    render_back_button(image, (back_button_cb_t)back_home_button_cb);

    /* 'Filter' button to filter the text messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    display_app_heading_crypto(image);

/***  MAIN LIST ITEMS  ***/
    /* Set the objects for list item separators and overlay elements for each feature here */

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Icon and label objects here */
    lv_obj_t * crypto_label[ttl_crypto_items];
    lv_obj_t * crypto_company_logo[ttl_crypto_items];
    lv_obj_t * crypto_next_icon[ttl_crypto_items];
    lv_obj_t * crypto_item_overlay[ttl_crypto_items];

/***  MAIN CLICKABLE LIST ITEMS  ***/
    /* Add settings features as clickable buttons */
    for(int crypto_list_item = 0; crypto_list_item < ttl_crypto_items; crypto_list_item++) {
        /* Increment the page reference number for each Settings page */
        scr_nbr++;

        /* A row-by-row offset value to maintain spacing between clickable elements */
        int offset = crypto_list_item * 60;

        /* Settings list item button overlay */
        crypto_item_overlay[scr_nbr] = lv_btn_create(image);
        lv_obj_set_size(crypto_item_overlay[scr_nbr], 352, 56);
        lv_obj_align(crypto_item_overlay[scr_nbr], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 141 + offset);
        lv_obj_set_style_opa(crypto_item_overlay[scr_nbr], LV_OPA_0, LV_PART_MAIN);

        /* Get the contact_id for the item being clicked then set the event click */
        char *item_id = crypto_00_list[crypto_list_item].crypto_id;
        lv_obj_add_event_cb(crypto_item_overlay[scr_nbr], display_crypto_info_cb, LV_EVENT_CLICKED, (void *)item_id);  // Use this to select, replace, and then view the content
        // lv_obj_add_event_cb(crypto_item_overlay[scr_nbr], image_click_event_cb, LV_EVENT_CLICKED, (void *)item_id);  // Use this for debugging

        /* Crypto Name and Initials selection label */
        char crypto_name_and_initials[1024];
        sprintf(crypto_name_and_initials, "%s (%s)", crypto_00_list[crypto_list_item].crypto_company_name, crypto_00_list[crypto_list_item].crypto_company_initials);

        crypto_company_logo[scr_nbr] = lv_img_create(image);
        lv_img_set_src(crypto_company_logo[scr_nbr], crypto_00_list[crypto_list_item].crypto_icon_logo);
        lv_obj_align(crypto_company_logo[scr_nbr], LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 152 + offset);
        lv_obj_set_style_opa(crypto_company_logo[scr_nbr], LV_OPA_90, LV_PART_MAIN);

        crypto_label[scr_nbr] = lv_label_create(image);
        lv_label_set_recolor(crypto_label[scr_nbr], true);
        lv_label_set_text(crypto_label[scr_nbr], crypto_name_and_initials);
        lv_obj_add_style(crypto_label[scr_nbr], &name_style_24, LV_PART_MAIN);
        lv_obj_set_style_text_color(crypto_label[scr_nbr], lv_color_white(), 0);
        lv_obj_align(crypto_label[scr_nbr], LV_ALIGN_TOP_LEFT, REGULAR_ICON_PAD_LEFT, 162 + offset);

        crypto_next_icon[scr_nbr] = lv_img_create(image);
        lv_img_set_src(crypto_next_icon[scr_nbr], &Icon_Next_White);
        lv_obj_align(crypto_next_icon[scr_nbr], LV_ALIGN_TOP_LEFT, 344, 162 + offset);
        lv_obj_set_style_opa(crypto_next_icon[scr_nbr], LV_OPA_70, LV_PART_MAIN);

        // Add a list item separator line at the end of the list item
        list_item_tail[scr_nbr] = lv_img_create(image);
        lv_img_set_src(list_item_tail[scr_nbr], &Linez);
        lv_obj_align(list_item_tail[scr_nbr], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 201 + offset);
    }
}


/***  SCREEN 01 - Crypto Account info page  ***/
static void crypto_01_view(lv_obj_t * crypto_01_view_page) {
    lv_obj_t * image = lv_img_create(crypto_01_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 1;
    // printf("Calendar page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    crypto_objects[scr_nbr] = image;
    lv_obj_set_style_bg_img_src(image, &Background, 0);

    /* Calculate total Crypto providers */
    // printf("\nCalculate number of providers...\n");
    for(ttl_items = 0; !is_end(crypto_00_list[ttl_items].crypto_id); ttl_items++) {
        ttl_crypto_items = ttl_items+1;
        // printf("Item count: %d -- crypto_id: %s\n",ttl_crypto_items,crypto_00_list[ttl_items].crypto_company_name);
    }
    // printf("\nTotal Records: %d\n\n",ttl_crypto_items);

    /* Build the Crypto record list for display */
    // printf("Building each Crypto record for display\n");
    for(int j = 0; j < ttl_crypto_items; j++) {
        if(is_end(crypto_00_list[j].crypto_id)) {
            break;
        } else {
            // printf("item: %d -- crypto_public_key_hash: %s\n",j,crypto_00_list[j].crypto_public_key_hash);
        }
    }

/***  Contacts Specific Style Declarations  ***/
    init_styles();

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

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

    // /* 'Filter' button to filter the list */
    // lv_obj_t * filter_image = lv_img_create(image);
    // lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    // display_app_heading_crypto(image);

/***  MAIN LIST ITEMS  ***/
    /* Set the objects for list item separators and overlay elements for each feature here */
    lv_obj_t * list_item_tail[5];
    lv_obj_t * display_feature_overlay;
    int ttl_overlay_width = 360;   // Full screen is about 380, so, width should be 380 less pad left and pad right
    int ttl_overlay_height = 522;  // Set this to the last lv_obj_align() padding height minus 40

    /* Display full screen height overlay to enable scrolling */
    display_feature_overlay = lv_img_create(image);
    lv_obj_set_size(display_feature_overlay, ttl_overlay_width, ttl_overlay_height);
    lv_obj_set_style_opa(display_feature_overlay, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(display_feature_overlay, image_click_event_cb, LV_EVENT_CLICKED, NULL);  // Use this for debugging
    lv_obj_align(display_feature_overlay, LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 54);

    /* Back button overlay */
    back_to_crypto[back_to_home] = lv_btn_create(image);
    lv_obj_set_size(back_to_crypto[back_to_home], 80, 40);
    lv_obj_set_style_opa(back_to_crypto[back_to_home], LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_crypto[back_to_home], scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_align(back_to_crypto[back_to_home], LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

/* MAIN CRYPTO CARD HEADING */
    /* Crypto logo image */
    crypto_icon_logo = lv_img_create(image);
    lv_img_set_src(crypto_icon_logo, crypto_00_list[1].crypto_icon_logo);
    lv_obj_align(crypto_icon_logo, LV_ALIGN_TOP_MID, 0, 32);

/* FULL NAME BANNER HERE */
    /* Crypto Name and Initials selection label */
    char crypto_name_and_initials[1024];
    sprintf(crypto_name_and_initials, "%s (%s)", crypto_00_list[1].crypto_company_name, crypto_00_list[1].crypto_company_initials);

    crypto_company_name = lv_label_create(image);
    lv_label_set_recolor(crypto_company_name, true);
    lv_label_set_text(crypto_company_name, crypto_name_and_initials);
    lv_obj_set_style_text_color(crypto_company_name, lv_color_white(), 0);
    lv_obj_set_style_text_font(crypto_company_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(crypto_company_name, LV_ALIGN_TOP_MID, 0, 92);

/* BALANCE INFO */
    /* Crypto Coin and Initials */
    lv_obj_t * balance_heading = lv_label_create(image);
    lv_label_set_recolor(balance_heading, true);
    lv_label_set_text(balance_heading, "Your balance");
    lv_obj_set_style_text_color(balance_heading, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(balance_heading, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(balance_heading, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 142);

    crypto_coin_and_initials = lv_label_create(image);
    lv_label_set_text(crypto_coin_and_initials, "32569.22179 ETH");
    lv_obj_set_style_text_color(crypto_coin_and_initials, lv_color_white(), 0);
    lv_obj_set_style_text_font(crypto_coin_and_initials, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(crypto_coin_and_initials, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 172);

    /* Crypto Value in USD */
    char crypto_value_balance_buffer[64];
    sprintf(crypto_value_balance_buffer, "%.2f", crypto_00_list[1].crypto_value);

    crypto_value_and_initials = lv_label_create(image);
    lv_label_set_text(crypto_value_and_initials, "$471,239.01 USD");
    lv_obj_set_style_text_color(crypto_value_and_initials, lv_color_white(), 0);
    lv_obj_set_style_text_font(crypto_value_and_initials, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(crypto_value_and_initials, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 202);

    // Add a list item separator line at the end of the list item
    list_item_separator[0] = lv_img_create(image);
    lv_img_set_src(list_item_separator[0], &Linez);
    lv_obj_align(list_item_separator[0], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 246);

/* PUBLIC AND PRIVATE KEYS */
    lv_obj_t * public_key_icon = lv_img_create(image);
    lv_img_set_src(public_key_icon, &Icon_Crypto_Public_Key_Horizontal_Teal);
    lv_obj_align(public_key_icon, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 266);
    lv_obj_set_style_opa(public_key_icon, LV_OPA_COVER, LV_PART_MAIN);

    lv_obj_t * public_key_heading = lv_label_create(image);
    lv_label_set_recolor(public_key_heading, true);
    lv_label_set_text(public_key_heading, "Public key");
    lv_obj_set_style_text_color(public_key_heading, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(public_key_heading, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(public_key_heading, LV_ALIGN_TOP_LEFT, 92, 266);

    crypto_public_key_hash = lv_label_create(image);
    lv_label_set_recolor(crypto_public_key_hash, true);
    lv_label_set_text(crypto_public_key_hash, "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");

    // Enable text wrapping by setting the style
    lv_obj_set_size(crypto_public_key_hash, 300, 160);  // Width and height of the label area
    lv_label_set_long_mode(crypto_public_key_hash, LV_LABEL_LONG_WRAP);

    lv_obj_set_style_text_color(crypto_public_key_hash, lv_color_white(), 0);
    lv_obj_set_style_text_font(crypto_public_key_hash, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(crypto_public_key_hash, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 296);

    // Add a list item separator line at the end of the list item
    list_item_separator[1] = lv_img_create(image);
    lv_img_set_src(list_item_separator[1], &Linez);
    lv_obj_align(list_item_separator[1], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 362);

    lv_obj_t * private_key_icon = lv_img_create(image);
    lv_img_set_src(private_key_icon, &Icon_Crypto_Private_Key_Horizontal_Red);
    lv_obj_align(private_key_icon, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 384);
    lv_obj_set_style_opa(private_key_icon, LV_OPA_COVER, LV_PART_MAIN);

    lv_obj_t * private_key_heading = lv_label_create(image);
    lv_label_set_recolor(private_key_heading, true);
    lv_label_set_text(private_key_heading, "Private key");
    lv_obj_set_style_text_color(private_key_heading, lv_color_hex(HEADING_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(private_key_heading, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(private_key_heading, LV_ALIGN_TOP_LEFT, 92, 384);

    crypto_private_key_hash = lv_label_create(image);
    lv_label_set_recolor(crypto_private_key_hash, true);
    lv_label_set_text(crypto_private_key_hash, "1E99423A4ED27608A15A2616A2B0E9E52CED330AC530EDCC32C8FFC6A526AEDD");

    // Enable text wrapping by setting the style
    lv_obj_set_size(crypto_private_key_hash, 300, 160);  // Width and height of the label area
    lv_label_set_long_mode(crypto_private_key_hash, LV_LABEL_LONG_WRAP);

    lv_obj_set_style_text_color(crypto_private_key_hash, lv_color_white(), 0);
    lv_obj_set_style_text_font(crypto_private_key_hash, &NeueHaasDisplayLight_24, LV_PART_MAIN);
    lv_obj_align(crypto_private_key_hash, LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 416);

    // Add a list item separator line at the end of the list item
    list_item_separator[2] = lv_img_create(image);
    lv_img_set_src(list_item_separator[2], &Linez);
    lv_obj_align(list_item_separator[2], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 510);
}


void crypto_menu_setup(void) {
    printf("CRYPTO MENU init...\n");

    lv_obj_t * crypto_page = lv_obj_create(NULL);
    menu_dispatch_table[CRYPTO_VEC] = crypto_page;

    lv_obj_center(crypto_page);
    lv_obj_set_style_bg_color(crypto_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(crypto_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(crypto_page, true, 3);
    lv_obj_set_scroll_dir(crypto_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(crypto_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(crypto_page, LV_OBJ_FLAG_SCROLLABLE | LV_SCROLLBAR_MODE_ON);

    /* CRYPTO VIEW: Display the content for a specific crypto account */
    printf("\nCRYPTO_01_VIEW launch...\n");
    crypto_01_view(crypto_page);

    /* CRYPTO KEY VIEW: Display the content for crypto_00_view -- Your Crypto */
    printf("\nCRYPTO_00_VIEW launch...\n");
    crypto_00_view(crypto_page);

    scroll_to_home();
}