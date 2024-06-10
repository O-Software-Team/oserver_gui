#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>

/* Initialize/populate the Filesystem list structs */
#include "content/inc/filesystem/01.h"   /* Main screen - Filesystem list */
#include "content/inc/filesystem/02.h"   /* Filesystem  - Folders list */
#include "content/inc/filesystem/03.h"   /* Filesystem  - Movies list */
#include "content/inc/filesystem/04.h"   /* Filesystem  - Images list */
#include "content/inc/filesystem/05.h"   /* Filesystem  - Applications list */
#include "content/inc/filesystem/06.h"   /* Filesystem  - Documents list */
#include "content/inc/filesystem/07.h"   /* Filesystem  - Excel list */

/* Contact list and contact ID variables */
#define CONTACT_ID 0

/* Contact screen alignment for Name, Phone, SMS, and Email separator lines */
#define CONTACT_PAD_LEFT 30
#define CONTACT_NAME_WIDTH 332
#define CONTACT_NAME 120
#define LIST_LEFT_ALIGNED 25
#define LIST_SEPARATOR 30
#define LIST_CONTENT_ITEM 50

/* Contact content attributes */
#define CONTACT_SUBDUED_COLOR 0xADB1A2

/* Bottom of viewport attributes */
#define OVERLAY_WIDTH 345
#define OVERLAY_HEIGHT 35
#define OVERLAY_POS_LEFT 20
#define OVERLAY_POS_FROM_TOP 440
#define OVERLAY_COLOR 0x0F0F0F

#define LV_FONT_MONTSERRAT_44 1

#define FONT_SIZE_WORKS 0 // Until it's figured out

/* Main background and radio controls declared below */
LV_IMG_DECLARE(Background);
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

/* Set variables to determine total number of Contacts list members */
static int main_menu_item;    /* 01.h */
static int main_menu_record;
static int ttl_main_menu_items = 1;

static int folder_item;        /* 02.h */
static int folder_record;
static int ttl_folder_items = 1;

static int movie_item;         /* 03.h */
static int movie_record;
static int ttl_movie_items = 1;

static int image_item;         /* 04.h */
static int image_record;
static int ttl_image_items = 1;

static int application_item;   /* 05.h */
static int application_record;
static int ttl_application_items = 1;

static int document_item;      /* 06.h */
static int document_record;
static int ttl_document_items = 1;

static int spreadsheet_item;   /* 07.h */
static int spreadsheet_record;
static int ttl_spreadsheet_items = 1;

static lv_obj_t * top_of_list_items;

/* Set variables to calculate and then truncate strings too wide for the viewport -- insert an ellipsis in place of the long string */
static const char * fs_fullname_string;
static int fs_fullname_count;


static void select_screen_handler(lv_event_t * e) {
    /*
     * Scroll to the page to 'play the album' - For presentation, an in-progress song will play.
     */
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * music_page = lv_obj_get_user_data(target);
    printf("\nTarget: %s  --  Page: %s\n");

    // lv_img_set_src(music_page, &Music_Player_White);
    // lv_obj_scroll_to_view(lv_obj_get_child(music_page, 1), LV_ANIM_ON);
}


/* Your Filesystem */
void filesystem_list_init(lv_obj_t * filesystem_page) {
    lv_obj_t * image = lv_img_create(filesystem_page);
    lv_img_set_src(image, &Background);

    /* Calculate total Filesystem_01 records */
    printf("\nCalculate filesystem_01 -- your filesystem...\n");
    for(main_menu_item = 0; filesystem_01_list[main_menu_item].file_id != "end"; main_menu_item++) {
        ttl_main_menu_items = main_menu_item+1;
        printf("Item count: %d -- file_id: %s\n",ttl_main_menu_items,filesystem_01_list[main_menu_item].file_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_main_menu_items);

    /* Build the Contact record list for display */
    printf("Building each Filesystem_01 record for display\n");
    for(int e = 0; e < ttl_main_menu_items; e++) {
        if(filesystem_01_list[e].file_id == "end") {
            printf("item: %d -- file_fullname: %s\n",e,filesystem_01_list[e].file_fullname);
            break;
        } else {
            printf("file_id: %s -- file_fullname: %s\n",filesystem_01_list[e].file_id,filesystem_01_list[e].file_fullname);
        }
    }

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Files_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, CONTACT_PAD_LEFT, 112);
    lv_label_set_text(list_name, "Your filesystem");
    lv_obj_set_style_text_color(list_name, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* These keep the alignment settings evenly spaced when in a for loop */
    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;

    /* Set the list_item_separator and entry_separator objects here */
    lv_obj_t * list_item_separator[ttl_main_menu_items];
    lv_obj_t * entry_separator[ttl_main_menu_items];

    /* Icon and label objects here */
    lv_obj_t * file_icon[ttl_main_menu_items];
    lv_obj_t * file_label[ttl_main_menu_items];
    lv_obj_t * next_icon[ttl_main_menu_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    lv_obj_t * file_btn_list[];

    /* Add (simulated) devices entries as clickable buttons*/
    for(main_menu_record = 0; main_menu_record < ttl_main_menu_items; main_menu_record++) {
        offset = 151 + (60 * main_menu_record);
        entry_separator[main_menu_record] = lv_img_create(image);
        lv_img_set_src(entry_separator[main_menu_record], &Linez);
        lv_obj_align(entry_separator[main_menu_record], LV_ALIGN_DEFAULT, 25, offset);

        /* Device icon image on the left */
        file_icon[main_menu_record] = lv_img_create(image);
        lv_img_set_src(file_icon[main_menu_record], filesystem_01_list[main_menu_record].file_icon);
        lv_obj_align(file_icon[main_menu_record], LV_ALIGN_CENTER, -130, offset - 223);

        /*this is the opaque button overlay of the album entry */
        file_btn_list[folder_record] = lv_btn_create(image);
        lv_obj_set_size(file_btn_list[folder_record], 330, 50);
        lv_obj_align(file_btn_list[folder_record], LV_ALIGN_CENTER, 0, offset - 225);
        lv_obj_set_style_opa(file_btn_list[folder_record], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(file_btn_list[folder_record], select_screen_handler, LV_EVENT_CLICKED, 0);
        lv_obj_set_user_data(file_btn_list[folder_record], filesystem_page);

        /* The label text with the device name */
        file_label[main_menu_record] = lv_label_create(image);
        lv_label_set_recolor(file_label[main_menu_record], true);
        lv_obj_align(file_label[main_menu_record], LV_ALIGN_LEFT_MID, 125, offset - 223);
        lv_label_set_text(file_label[main_menu_record], filesystem_01_list[main_menu_record].file_fullname);
        lv_style_set_text_font(&name_style, &NeueHaasDisplayLight_24);
        lv_obj_add_style(file_label[main_menu_record], &name_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(file_label[main_menu_record], lv_color_white(), 0);

        next_icon[main_menu_record] = lv_img_create(image);
        lv_img_set_src(next_icon[main_menu_record], &Icon_Next_White);
        lv_obj_align(next_icon[main_menu_record], LV_ALIGN_CENTER, 130, offset - 223);
        lv_obj_set_style_opa(next_icon[main_menu_record], LV_OPA_70, LV_PART_MAIN);

        // Add a list item separator line at the end of the list item
        list_item_separator[main_menu_record] = lv_img_create(image);
        lv_img_set_src(list_item_separator[main_menu_record], &Linez);
        lv_obj_align(list_item_separator[main_menu_record], LV_ALIGN_LEFT_MID, LIST_SEPARATOR, offset + 44);
    }

}


/* Your Folders */
void filesystem_02_view(lv_obj_t * filesystem_02_view_page) {
    lv_obj_t * image = lv_img_create(filesystem_02_view_page);
    lv_img_set_src(image, &Background);

    /* Calculate total Filesystem_02 -- your folders */
    printf("\nCalculate filesystem_02 -- your folders...\n");
    for(folder_item = 0; filesystem_02_list[folder_item].file_id != "end"; folder_item++) {
        ttl_folder_items = folder_item+1;
        printf("Item count: %d -- file_id: %s\n",ttl_folder_items,filesystem_02_list[folder_item].file_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_folder_items);

    /* Build the Contact record list for display */
    printf("Building each Filesystem_02 record for display\n");
    for(int j = 0; j < ttl_folder_items; j++) {
        if(filesystem_02_list[j].file_id == "end") {
            printf("item: %d -- file_fullname: %s\n",j,filesystem_02_list[j].file_fullname);
            break;
        } else {
            printf("file_id: %s -- file_fullname: %s\n",filesystem_02_list[j].file_id,filesystem_02_list[j].file_fullname);
        }
    }

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Files_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, CONTACT_PAD_LEFT, 112);
    lv_label_set_text(list_name, "Your folders");
    lv_obj_set_style_text_color(list_name, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* These keep the alignment settings evenly spaced when in a for loop */
    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_folder_items];
    lv_obj_t * entry_separator[ttl_folder_items];

    /* Icon and label objects here */
    lv_obj_t * file_icon[ttl_folder_items];
    lv_obj_t * file_label[ttl_folder_items];
    lv_obj_t * next_icon[ttl_folder_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Add (simulated) devices entries as clickable buttons*/
    for(folder_record = 0; folder_record < ttl_folder_items; folder_record++) {
        offset =  131 + (60 * folder_record);
        entry_separator[folder_record] = lv_img_create(image);
        lv_img_set_src(entry_separator[folder_record], &Linez);
        lv_obj_align(entry_separator[folder_record], LV_ALIGN_DEFAULT, 25, offset +22);

        /* Device icon image on the left */
        file_icon[folder_record] = lv_img_create(image);
        lv_img_set_src(file_icon[folder_record], filesystem_02_list[folder_record].file_icon);
        lv_obj_align(file_icon[folder_record], LV_ALIGN_CENTER, -130, offset - 231);

        /* The label text with the device name */
        file_label[folder_record] = lv_label_create(image);
        lv_label_set_recolor(file_label[folder_record], true);
        lv_obj_align(file_label[folder_record], LV_ALIGN_LEFT_MID, 125, offset - 231);
        lv_label_set_text(file_label[folder_record], filesystem_02_list[folder_record].file_fullname);
        lv_style_set_text_font(&name_style, &NeueHaasDisplayLight_24);
        lv_obj_add_style(file_label[folder_record], &name_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(file_label[folder_record], lv_color_white(), 0);

        next_icon[folder_record] = lv_img_create(image);
        lv_img_set_src(next_icon[folder_record], &Icon_Next_White);
        lv_obj_align(next_icon[folder_record], LV_ALIGN_CENTER, 130, offset - 231);
        lv_obj_set_style_opa(next_icon[folder_record], LV_OPA_70, LV_PART_MAIN);

        // Add a list item separator line at the end of the list item
        list_item_separator[folder_record] = lv_img_create(image);
        lv_img_set_src(list_item_separator[folder_record], &Linez);
        lv_obj_align(list_item_separator[folder_record], LV_ALIGN_LEFT_MID, LIST_SEPARATOR, offset + 44);
    }
}


/* Your Movies */
void filesystem_03_view(lv_obj_t * filesystem_03_view_page) {
    lv_obj_t * image = lv_img_create(filesystem_03_view_page);
    lv_img_set_src(image, &Background);

    /* Calculate total filesystem_03 -- your movies */
    printf("\nCalculate filesystem_03 -- your movies...\n");
    for(movie_item = 0; filesystem_03_list[movie_item].file_id != "end"; movie_item++) {
        ttl_movie_items = movie_item+1;
        printf("Item count: %d -- file_id: %s\n",ttl_movie_items,filesystem_03_list[movie_item].file_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_movie_items);

    /* Build the Contact record list for display */
    printf("Building each filesystem_03 record for display\n");
    for(int k = 0; k < ttl_movie_items; k++) {
        if(filesystem_03_list[k].file_id == "end") {
            printf("item: %d -- file_fullname: %s\n",k,filesystem_03_list[k].file_fullname);
            break;
        } else {
            printf("file_id: %s -- file_fullname: %s\n",filesystem_03_list[k].file_id,filesystem_03_list[k].file_fullname);
        }
    }

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Files_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, CONTACT_PAD_LEFT, 112);
    lv_label_set_text(list_name, "Your movies");
    lv_obj_set_style_text_color(list_name, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* These keep the alignment settings evenly spaced when in a for loop */
    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_movie_items];
    lv_obj_t * entry_separator[ttl_movie_items];

    /* Icon and label objects here */
    lv_obj_t * file_icon[ttl_movie_items];
    lv_obj_t * file_label[ttl_movie_items];
    lv_obj_t * next_icon[ttl_movie_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Provide a single rule under the heading */
    entry_separator[0] = lv_img_create(image);
    lv_img_set_src(entry_separator[0], &Linez);
    lv_obj_align(entry_separator[0], LV_ALIGN_TOP_LEFT, 28, 152);

    /* Add (simulated) devices entries as clickable buttons */
    for(movie_record = 0; movie_record < ttl_movie_items; movie_record++) {
        offset = 130 + (52 * movie_record);

        /* Device icon image on the left */
        file_icon[movie_record] = lv_img_create(image);
        lv_img_set_src(file_icon[movie_record], filesystem_03_list[movie_record].file_icon);
        lv_obj_align(file_icon[movie_record], LV_ALIGN_LEFT_MID, 28, offset - 199);

        /* Calculate if the file_fullname field is greater than or equal to 25 characters */
        fs_fullname_string = filesystem_03_list[movie_record].file_fullname;
        fs_fullname_count = strlen(fs_fullname_string);

        /* The label text with the device name */
        file_label[movie_record] = lv_label_create(image);
        lv_label_set_recolor(file_label[movie_record], true);
        lv_obj_align(file_label[movie_record], LV_ALIGN_LEFT_MID, 78, offset - 199);

        /* Calculate and then truncate if the NAME field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
        if(fs_fullname_count >= 19) {
            lv_label_set_text(file_label[movie_record], filesystem_03_list[movie_record].file_fullname);
            lv_label_cut_text(file_label[movie_record],17,fs_fullname_count);
            lv_label_ins_text(file_label[movie_record],19,"...");
        } else {
            lv_label_set_text(file_label[movie_record], filesystem_03_list[movie_record].file_fullname);
        }

        lv_style_set_text_font(&name_style, &NeueHaasDisplayLight_24);
        lv_obj_add_style(file_label[movie_record], &name_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(file_label[movie_record], lv_color_white(), 0);

        next_icon[movie_record] = lv_img_create(image);
        lv_img_set_src(next_icon[movie_record], &Icon_Next_White);
        lv_obj_align(next_icon[movie_record], LV_ALIGN_LEFT_MID, 348, offset - 199);
        lv_obj_set_style_opa(next_icon[movie_record], LV_OPA_70, LV_PART_MAIN);
    }
}

/* Your Images */
void filesystem_04_view(lv_obj_t * filesystem_04_view_page) {
    lv_obj_t * image = lv_img_create(filesystem_04_view_page);
    lv_img_set_src(image, &Background);

    /* Calculate total filesystem_04 -- your images */
    printf("\nCalculate filesystem_04 -- your images...\n");
    for(image_item = 0; filesystem_04_list[image_item].file_id != "end"; image_item++) {
        ttl_image_items = image_item+1;
        printf("Item count: %d -- file_id: %s\n",ttl_image_items,filesystem_04_list[image_item].file_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_image_items);

    /* Build the Contact record list for display */
    printf("Building each filesystem_04 record for display\n");
    for(int k = 0; k < ttl_image_items; k++) {
        if(filesystem_04_list[k].file_id == "end") {
            printf("item: %d -- file_fullname: %s\n",k,filesystem_04_list[k].file_fullname);
            break;
        } else {
            printf("file_id: %s -- file_fullname: %s\n",filesystem_04_list[k].file_id,filesystem_04_list[k].file_fullname);
        }
    }

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Files_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, CONTACT_PAD_LEFT, 112);
    lv_label_set_text(list_name, "Your images");
    lv_obj_set_style_text_color(list_name, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* These keep the alignment settings evenly spaced when in a for loop */
    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_image_items];
    lv_obj_t * entry_separator[ttl_image_items];

    /* Icon and label objects here */
    lv_obj_t * file_icon[ttl_image_items];
    lv_obj_t * file_label[ttl_image_items];
    lv_obj_t * next_icon[ttl_image_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Provide a single rule under the heading */
    entry_separator[0] = lv_img_create(image);
    lv_img_set_src(entry_separator[0], &Linez);
    lv_obj_align(entry_separator[0], LV_ALIGN_TOP_LEFT, 28, 152);

    /* Add (simulated) devices entries as clickable buttons */
    for(image_record = 0; image_record < ttl_image_items; image_record++) {
        offset = 130 + (52 * image_record);

        /* Device icon image on the left */
        file_icon[image_record] = lv_img_create(image);
        lv_img_set_src(file_icon[image_record], filesystem_04_list[image_record].file_icon);
        lv_obj_align(file_icon[image_record], LV_ALIGN_LEFT_MID, 28, offset - 199);

        /* Calculate if the file_fullname field is greater than or equal to 25 characters */
        fs_fullname_string = filesystem_04_list[image_record].file_fullname;
        fs_fullname_count = strlen(fs_fullname_string);

        /* The label text with the device name */
        file_label[image_record] = lv_label_create(image);
        lv_label_set_recolor(file_label[image_record], true);
        lv_obj_align(file_label[image_record], LV_ALIGN_LEFT_MID, 78, offset - 199);

        /* Calculate and then truncate if the NAME field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
        if(fs_fullname_count >= 19) {
            lv_label_set_text(file_label[image_record], filesystem_04_list[image_record].file_fullname);
            lv_label_cut_text(file_label[image_record],17,fs_fullname_count);
            lv_label_ins_text(file_label[image_record],19,"...");
        } else {
            lv_label_set_text(file_label[image_record], filesystem_04_list[image_record].file_fullname);
        }

        lv_style_set_text_font(&name_style, &NeueHaasDisplayLight_24);
        lv_obj_add_style(file_label[image_record], &name_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(file_label[image_record], lv_color_white(), 0);

        next_icon[image_record] = lv_img_create(image);
        lv_img_set_src(next_icon[image_record], &Icon_Next_White);
        lv_obj_align(next_icon[image_record], LV_ALIGN_LEFT_MID, 348, offset - 199);
        lv_obj_set_style_opa(next_icon[image_record], LV_OPA_70, LV_PART_MAIN);
    }
}

/* Your Applications */
void filesystem_05_view(lv_obj_t * filesystem_05_view_page) {
    lv_obj_t * image = lv_img_create(filesystem_05_view_page);
    lv_img_set_src(image, &Background);

    /* Calculate total filesystem_05 -- your applications */
    printf("\nCalculate filesystem_05 -- your applications...\n");
    for(application_item = 0; filesystem_05_list[application_item].file_id != "end"; application_item++) {
        ttl_application_items = application_item+1;
        printf("Item count: %d -- file_id: %s\n",ttl_application_items,filesystem_05_list[application_item].file_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_application_items);

    /* Build the Contact record list for display */
    printf("Building each filesystem_05 record for display\n");
    for(int k = 0; k < ttl_application_items; k++) {
        if(filesystem_05_list[k].file_id == "end") {
            printf("item: %d -- file_fullname: %s\n",k,filesystem_05_list[k].file_fullname);
            break;
        } else {
            printf("file_id: %s -- file_fullname: %s\n",filesystem_05_list[k].file_id,filesystem_05_list[k].file_fullname);
        }
    }

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Files_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, CONTACT_PAD_LEFT, 112);
    lv_label_set_text(list_name, "Your applications");
    lv_obj_set_style_text_color(list_name, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* These keep the alignment settings evenly spaced when in a for loop */
    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_application_items];
    lv_obj_t * entry_separator[ttl_application_items];

    /* Icon and label objects here */
    lv_obj_t * file_icon[ttl_application_items];
    lv_obj_t * file_label[ttl_application_items];
    lv_obj_t * next_icon[ttl_application_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Provide a single rule under the heading */
    entry_separator[0] = lv_img_create(image);
    lv_img_set_src(entry_separator[0], &Linez);
    lv_obj_align(entry_separator[0], LV_ALIGN_TOP_LEFT, 28, 152);

    /* Add (simulated) devices entries as clickable buttons */
    for(application_record = 0; application_record < ttl_application_items; application_record++) {
        offset = 130 + (52 * application_record);

        /* Device icon image on the left */
        file_icon[application_record] = lv_img_create(image);
        lv_img_set_src(file_icon[application_record], filesystem_05_list[application_record].file_icon);
        lv_obj_align(file_icon[application_record], LV_ALIGN_LEFT_MID, 28, offset - 199);

        /* Calculate if the file_fullname field is greater than or equal to 25 characters */
        fs_fullname_string = filesystem_05_list[application_record].file_fullname;
        fs_fullname_count = strlen(fs_fullname_string);

        /* The label text with the device name */
        file_label[application_record] = lv_label_create(image);
        lv_label_set_recolor(file_label[application_record], true);
        lv_obj_align(file_label[application_record], LV_ALIGN_LEFT_MID, 78, offset - 199);

        /* Calculate and then truncate if the NAME field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
        if(fs_fullname_count >= 19) {
            lv_label_set_text(file_label[application_record], filesystem_05_list[application_record].file_fullname);
            lv_label_cut_text(file_label[application_record],17,fs_fullname_count);
            lv_label_ins_text(file_label[application_record],19,"...");
        } else {
            lv_label_set_text(file_label[application_record], filesystem_05_list[application_record].file_fullname);
        }

        lv_style_set_text_font(&name_style, &NeueHaasDisplayLight_24);
        lv_obj_add_style(file_label[application_record], &name_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(file_label[application_record], lv_color_white(), 0);

        next_icon[application_record] = lv_img_create(image);
        lv_img_set_src(next_icon[application_record], &Icon_Next_White);
        lv_obj_align(next_icon[application_record], LV_ALIGN_LEFT_MID, 348, offset - 199);
        lv_obj_set_style_opa(next_icon[application_record], LV_OPA_70, LV_PART_MAIN);
    }
}

/* Your Documents */
void filesystem_06_view(lv_obj_t * filesystem_06_view_page) {
    lv_obj_t * image = lv_img_create(filesystem_06_view_page);
    lv_img_set_src(image, &Background);

    /* Calculate total filesystem_06 -- your documents */
    printf("\nCalculate filesystem_06 -- your documents...\n");
    for(document_item = 0; filesystem_06_list[document_item].file_id != "end"; document_item++) {
        ttl_document_items = document_item+1;
        printf("Item count: %d -- file_id: %s\n",ttl_document_items,filesystem_06_list[document_item].file_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_document_items);

    /* Build the Contact record list for display */
    printf("Building each filesystem_06 record for display\n");
    for(int k = 0; k < ttl_document_items; k++) {
        if(filesystem_06_list[k].file_id == "end") {
            printf("item: %d -- file_fullname: %s\n",k,filesystem_06_list[k].file_fullname);
            break;
        } else {
            printf("file_id: %s -- file_fullname: %s\n",filesystem_06_list[k].file_id,filesystem_06_list[k].file_fullname);
        }
    }

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Files_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, CONTACT_PAD_LEFT, 112);
    lv_label_set_text(list_name, "Your documents");
    lv_obj_set_style_text_color(list_name, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* These keep the alignment settings evenly spaced when in a for loop */
    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_document_items];
    lv_obj_t * entry_separator[ttl_document_items];

    /* Icon and label objects here */
    lv_obj_t * file_icon[ttl_document_items];
    lv_obj_t * file_label[ttl_document_items];
    lv_obj_t * next_icon[ttl_document_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Provide a single rule under the heading */
    entry_separator[0] = lv_img_create(image);
    lv_img_set_src(entry_separator[0], &Linez);
    lv_obj_align(entry_separator[0], LV_ALIGN_TOP_LEFT, 28, 152);

    /* Add (simulated) devices entries as clickable buttons */
    for(document_record = 0; document_record < ttl_document_items; document_record++) {
        offset = 130 + (52 * document_record);

        /* Device icon image on the left */
        file_icon[document_record] = lv_img_create(image);
        lv_img_set_src(file_icon[document_record], filesystem_06_list[document_record].file_icon);
        lv_obj_align(file_icon[document_record], LV_ALIGN_LEFT_MID, 28, offset - 199);

        /* Calculate if the file_fullname field is greater than or equal to 25 characters */
        fs_fullname_string = filesystem_06_list[document_record].file_fullname;
        fs_fullname_count = strlen(fs_fullname_string);

        /* The label text with the device name */
        file_label[document_record] = lv_label_create(image);
        lv_label_set_recolor(file_label[document_record], true);
        lv_obj_align(file_label[document_record], LV_ALIGN_LEFT_MID, 78, offset - 199);

        /* Calculate and then truncate if the NAME field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
        if(fs_fullname_count >= 19) {
            lv_label_set_text(file_label[document_record], filesystem_06_list[document_record].file_fullname);
            lv_label_cut_text(file_label[document_record],17,fs_fullname_count);
            lv_label_ins_text(file_label[document_record],19,"...");
        } else {
            lv_label_set_text(file_label[document_record], filesystem_06_list[document_record].file_fullname);
        }

        lv_style_set_text_font(&name_style, &NeueHaasDisplayLight_24);
        lv_obj_add_style(file_label[document_record], &name_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(file_label[document_record], lv_color_white(), 0);

        next_icon[document_record] = lv_img_create(image);
        lv_img_set_src(next_icon[document_record], &Icon_Next_White);
        lv_obj_align(next_icon[document_record], LV_ALIGN_LEFT_MID, 348, offset - 199);
        lv_obj_set_style_opa(next_icon[document_record], LV_OPA_70, LV_PART_MAIN);
    }
}

/* Your Spreadsheets */
void filesystem_07_view(lv_obj_t * filesystem_07_view_page) {
    lv_obj_t * image = lv_img_create(filesystem_07_view_page);
    lv_img_set_src(image, &Background);

    /* Calculate total filesystem_07 -- your documents */
    printf("\nCalculate filesystem_07 -- your documents...\n");
    for(spreadsheet_item = 0; filesystem_07_list[spreadsheet_item].file_id != "end"; spreadsheet_item++) {
        ttl_spreadsheet_items = spreadsheet_item+1;
        printf("Item count: %d -- file_id: %s\n",ttl_spreadsheet_items,filesystem_07_list[spreadsheet_item].file_id);
    }
    printf("\nTotal Records: %d\n\n",ttl_spreadsheet_items);

    /* Build the Contact record list for display */
    printf("Building each filesystem_07 record for display\n");
    for(int k = 0; k < ttl_spreadsheet_items; k++) {
        if(filesystem_07_list[k].file_id == "end") {
            printf("item: %d -- file_fullname: %s\n",k,filesystem_07_list[k].file_fullname);
            break;
        } else {
            printf("file_id: %s -- file_fullname: %s\n",filesystem_07_list[k].file_id,filesystem_07_list[k].file_fullname);
        }
    }

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the list */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Files_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the file list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, CONTACT_PAD_LEFT, 112);
    lv_label_set_text(list_name, "Your spreadsheets");
    lv_obj_set_style_text_color(list_name, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* These keep the alignment settings evenly spaced when in a for loop */
    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_spreadsheet_items];
    lv_obj_t * entry_separator[ttl_spreadsheet_items];

    /* Icon and label objects here */
    lv_obj_t * file_icon[ttl_spreadsheet_items];
    lv_obj_t * file_label[ttl_spreadsheet_items];
    lv_obj_t * next_icon[ttl_spreadsheet_items];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Provide a single rule under the heading */
    entry_separator[0] = lv_img_create(image);
    lv_img_set_src(entry_separator[0], &Linez);
    lv_obj_align(entry_separator[0], LV_ALIGN_TOP_LEFT, 28, 152);

    /* Add (simulated) devices entries as clickable buttons */
    for(spreadsheet_record = 0; spreadsheet_record < ttl_spreadsheet_items; spreadsheet_record++) {
        offset = 130 + (52 * spreadsheet_record);

        /* Device icon image on the left */
        file_icon[spreadsheet_record] = lv_img_create(image);
        lv_img_set_src(file_icon[spreadsheet_record], filesystem_07_list[spreadsheet_record].file_icon);
        lv_obj_align(file_icon[spreadsheet_record], LV_ALIGN_LEFT_MID, 28, offset - 199);

        /* Calculate if the file_fullname field is greater than or equal to 25 characters */
        fs_fullname_string = filesystem_07_list[spreadsheet_record].file_fullname;
        fs_fullname_count = strlen(fs_fullname_string);

        /* The label text with the device name */
        file_label[spreadsheet_record] = lv_label_create(image);
        lv_label_set_recolor(file_label[spreadsheet_record], true);
        lv_obj_align(file_label[spreadsheet_record], LV_ALIGN_LEFT_MID, 78, offset - 199);

        /* Calculate and then truncate if the NAME field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
        if(fs_fullname_count >= 19) {
            lv_label_set_text(file_label[spreadsheet_record], filesystem_07_list[spreadsheet_record].file_fullname);
            lv_label_cut_text(file_label[spreadsheet_record],17,fs_fullname_count);
            lv_label_ins_text(file_label[spreadsheet_record],19,"...");
        } else {
            lv_label_set_text(file_label[spreadsheet_record], filesystem_07_list[spreadsheet_record].file_fullname);
        }

        lv_style_set_text_font(&name_style, &NeueHaasDisplayLight_24);
        lv_obj_add_style(file_label[spreadsheet_record], &name_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(file_label[spreadsheet_record], lv_color_white(), 0);

        next_icon[spreadsheet_record] = lv_img_create(image);
        lv_img_set_src(next_icon[spreadsheet_record], &Icon_Next_White);
        lv_obj_align(next_icon[spreadsheet_record], LV_ALIGN_LEFT_MID, 348, offset - 199);
        lv_obj_set_style_opa(next_icon[spreadsheet_record], LV_OPA_70, LV_PART_MAIN);
    }
}

void file_menu_setup(void)
{
    printf("FILES MENU init...\n");
    lv_obj_t * filesystem_page = lv_obj_create(NULL);
    menu_dispatch_table[FILES_VEC] = filesystem_page;

    lv_obj_center(filesystem_page);
    lv_obj_set_style_bg_color(filesystem_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(filesystem_page, LV_FLEX_FLOW_ROW);
    //lv_obj_add_event_cb(filesystem_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(filesystem_page, true, 3);
    lv_obj_set_scroll_dir(filesystem_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(filesystem_page, LV_SCROLL_SNAP_CENTER);
    // lv_obj_set_scrollbar_mode(filesystem_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scrollbar_mode(filesystem_page, LV_OBJ_FLAG_SCROLLABLE | LV_SCROLLBAR_MODE_ON);

    /* MAIN-SCREEN: Display the list items from filesystem_01 -- this is what the user will see to allow drilldown into the local filesystem */
    printf("FILESYSTEM_01 -- PRIMARY LIST init...\n");
    filesystem_list_init(filesystem_page);

    /* FILESYSTEM VIEW: Display the content for filesystem_02 -- Your Folders */
    printf("\nFILESYSTEM_02 VIEW launch...\n");
    filesystem_02_view(filesystem_page);

    /* FILESYSTEM VIEW: Display the content for filesystem_03 -- Your Movies */
    printf("\nFILESYSTEM_03 VIEW launch...\n");
    filesystem_03_view(filesystem_page);

    /* FILESYSTEM VIEW: Display the content for filesystem_04 -- Your Images */
    printf("\nFILESYSTEM_04 VIEW launch...\n");
    filesystem_04_view(filesystem_page);

    /* FILESYSTEM VIEW: Display the content for filesystem_05 -- Your Applications */
    printf("FILESYSTEM_05 VIEW launch...\n");
    filesystem_05_view(filesystem_page);

    /* FILESYSTEM VIEW: Display the content for filesystem_06 -- Your Documents */
    printf("FILESYSTEM_06 VIEW launch...\n");
    filesystem_06_view(filesystem_page);

    /* FILESYSTEM VIEW: Display the content for filesystem_07 -- Your Spreadsheet Files */
    printf("FILESYSTEM_07 VIEW launch...\n");
    filesystem_07_view(filesystem_page);

    /* FILESYSTEM VIEW: Display the content for filesystem_08 -- Your ??? Files */
    // printf("FILESYSTEM_08 VIEW launch...\n");
    // filesystem_02_view(filesystem_02_view_page);
    // filesystem_08_view(filesystem_page);

    // lv_obj_t * files_page = lv_obj_create(NULL);
    // lv_obj_t * background = lv_img_create(files_page);
    // lv_img_set_src(background, &Background);

    // int child_window_count = lv_obj_get_child_count(filesystem_page);
    // printf("TTL Child Windows = %d", child_window_count);

    // printf("FILES MENU init...\n");

    // menu_dispatch_table[FILES_VEC] = files_page;

    // render_back_button(background, back_home_button_cb);
    // lv_obj_center(files_page);
    // lv_obj_set_style_bg_color(files_page, lv_color_lighten(lv_color_black(), 60), 0);
    // lv_obj_set_flex_flow(files_page, LV_FLEX_FLOW_ROW);
    // //lv_obj_add_event_cb(files_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    // lv_obj_set_style_clip_corner(files_page, true, 3);
    // lv_obj_set_scroll_dir(files_page, LV_DIR_HOR);
    // lv_obj_set_scroll_snap_x(files_page, LV_SCROLL_SNAP_CENTER);
    // lv_obj_set_scrollbar_mode(files_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);
}
