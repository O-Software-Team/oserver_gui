#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>

/* Initialize/populate the Filesystem list struct */
#include "content/inc/filesystem/01.h"

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


/* USE THIS FOR THE LIST -- NEXT BUTTON */
    // next_icon[i] = lv_img_create(image);
    // lv_img_set_src(next_icon[i], &Icon_Next_White);
    // lv_obj_align(next_icon[i], LV_ALIGN_CENTER, 130, offset - 225);
    // lv_obj_set_style_opa(next_icon[i], LV_OPA_70, LV_PART_MAIN);

/* Set variables to determine total number of Contacts list members */
static int total_filesystem_items = 1;
static int ttl_items;

static lv_obj_t * top_of_list_items;

void filesystem_list_init(lv_obj_t * filesystem_page) {
    lv_obj_t * image = lv_img_create(filesystem_page);
    lv_img_set_src(image, &Background);

    /* Calculate total Filesystem_01 records */
    printf("\nCalculate filesystem_01 records...\n");
    for(ttl_items = 0; filesystem_01_list[ttl_items].file_id != "end"; ttl_items++) {
        total_filesystem_items = ttl_items+1;
        printf("Item count: %d -- file_id: %s\n",total_filesystem_items,filesystem_01_list[ttl_items].file_id);
    }
    printf("\nTotal Records: %d\n\n",total_filesystem_items);

    /* Build the Contact record list for display */
    printf("Building each Filesystem_01 record for display\n");
    for(int j = 0; j < total_filesystem_items; j++) {
        if(filesystem_01_list[j].file_id == "end") {
            printf("item: %d -- file_fullname: %s\n",j,filesystem_01_list[j].file_fullname);
            break;
        } else {
            printf("file_id: %s -- file_fullname: %s\n",filesystem_01_list[j].file_id,filesystem_01_list[j].file_fullname);
        }
    }

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the text messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Files_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the text message list heading - NOT NEEDED FOR THIS APP */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, CONTACT_PAD_LEFT, 112);
    lv_label_set_text(list_name, "List of files");
    lv_obj_set_style_text_color(list_name, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line below the list item header
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_LEFT_MID, LIST_SEPARATOR, -97);

    /* These keep the alignment settings evenly spaced when in a for loop */
    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[total_filesystem_items];
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
    lv_obj_set_scrollbar_mode(filesystem_page, LV_OBJ_FLAG_SCROLLABLE | LV_SCROLLBAR_MODE_ON);

    /* MAIN-SCREEN: Display the list of text messages: unread and read comingled together */
    printf("FILESYSTEM LIST init...\n");
    filesystem_list_init(filesystem_page);

    /* MESSAGE VIEW: Display the text message FROM and MESSAGE */
    printf("FILESYSTEM VIEW launch...\n");
    // contacts_view(filesystem_view_page);



    // lv_obj_t * files_page = lv_obj_create(NULL);
    // lv_obj_t * background = lv_img_create(files_page);
    // lv_img_set_src(background, &Background);

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
