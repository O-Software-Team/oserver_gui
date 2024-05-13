#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

/* Contact list and contact ID variables */
#define CONTACT_LIST_MAX 25
#define CONTACT_FOUND_MAX 25
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

/* Message content attributes */
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

/* Main HEADING iconography */
LV_IMG_DECLARE(Contacts_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

/* global static */
static lv_obj_t * contact_list[CONTACT_LIST_MAX];

// static lv_obj_t * trusted_device_btn_list[CONTACT_PAGE_MAX];
// static lv_obj_t * found_btn[CONTACT_FOUND_MAX];

static contacts_item contacts_list[CONTACT_LIST_MAX] = {
    {
        .contact_id = 0,
        .contact_fname = "Guillaume",
        .contact_lname = "Jaulerry",
        .contact_name = "Guillaume Jaulerry",
        .contact_p_phone = "+33 764 281599",
        .contact_m_phone = "",
        .contact_w_phone = "+1 732-555-1212",
        .contact_p_email = "gjaulerry@ominiserver.com",
        .contact_w_email = "gjaulerry@yoyodyne.ai",
        .contact_p_address = "",
        .contact_w_address = "",
        .contact_notes = "Some string of senseless content here...\n\nWe will need to create some sort of latin gobbledeegook here...\n\nBlah-blah-blah... BANANA!",
        .contact_status = &Icon_Unread_Yellow,
    },
    {
        .contact_id = 1,
        .contact_fname = "Guillaume",
        .contact_lname = "Jaulerry",
        .contact_name = "Guillaume Jaulerry",
        .contact_p_phone = "+33 764 281599",
        .contact_m_phone = "",
        .contact_w_phone = "+1 732-555-1212",
        .contact_p_email = "gjaulerry@ominiserver.com",
        .contact_w_email = "gjaulerry@yoyodyne.ai",
        .contact_p_address = "",
        .contact_w_address = "",
        .contact_notes = "Some string of senseless content here...\n\nWe will need to create some sort of latin gobbledeegook here...\n\nBlah-blah-blah... BANANA!",
        .contact_status = &Icon_Unread_Yellow,
    },
};

/* Set variables to calculate and then truncate strings too wide for the viewport -- insert an ellipsis in place of the long string */
static const char * from_string;
static int from_count;
// const char * summary_string;
int summary_count;
static const char * notes_string;
static int notes_count;

/* Set variables for all the message content fields: ID, FROM, SUBJECT, MESSAGE */
lv_label_t * ctcitem_id;
lv_label_t * ctcitem_name;
lv_label_t * ctcitem_notes;
lv_label_t * ctcitem_status;
// lv_label_t * txtmsg_message;
lv_label_t * contact_detail_from;
// lv_obj_t * text_detail_message;
static lv_obj_t * top_of_list_items;
static lv_obj_t * spacer;

/* The following function populates the main screen with read and unread text messages */
void contacts_list_init(lv_obj_t * ctcitem_page) {
    lv_obj_t * image = lv_img_create(ctcitem_page);
    lv_img_set_src(image, &Background);

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the text messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Contacts_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the text message list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, LIST_LEFT_ALIGNED, 108);
    lv_label_set_text(list_name, "On Bob's MacBook");
    lv_obj_set_style_text_color(list_name, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line above the list item text
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 147);

    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;
    lv_obj_t * list_item_separator[CONTACT_LIST_MAX];

    /* Add (simulated) text messages as clickable buttons*/
    for (int i = 0; i < CONTACT_LIST_MAX; i++) {

        left.y = left.y + offset;
        right.y = right.y + offset;

        offset =  -64 + (92 * i);

        /* Calculate if the FROM field is greater than or equal to 25 characters */
        from_string = contacts_list[i].contact_name;
        from_count = strlen(from_string);

        /* Calculate if the SUMMARY field is greater than or equal to 37 characters */
        // summary_string = contacts_list[i].contact_name;
        // summary_count = strlen(summary_string);

        /* Calculate if the NOTES field is greater than or equal to 37 characters */
        notes_string = contacts_list[i].contact_notes;
        notes_count = strlen(notes_string);

        /* Contact FAV/NOT_FAV icon on the left */
        // lv_obj_t * txtmsg_icon = lv_img_create(image);
        // lv_img_set_src(txtmsg_icon, contacts_list[i].ctcitem_status);
        // lv_obj_align(txtmsg_icon, LV_ALIGN_LEFT_MID, LIST_LEFT_ALIGNED, offset);

        /* Contact NAME field */
        ctcitem_name = lv_label_create(image);
        lv_label_set_recolor(ctcitem_name, true);

        /* Calculate and then truncate if the FROM field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
        if(from_count >= 25) {
            lv_label_set_text(ctcitem_name, contacts_list[i].contact_name);
            lv_label_cut_text(ctcitem_name,23,from_count);
            lv_label_ins_text(ctcitem_name,25,"...");
        } else {
            lv_label_set_text(ctcitem_name, contacts_list[i].contact_name);
        }

        lv_obj_align(ctcitem_name, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset - 15);
        lv_obj_set_style_text_color(ctcitem_name, lv_color_white(), 0);
        lv_obj_set_style_text_font(ctcitem_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

        /* Text message SUMMARY field */
        ctcitem_name = lv_label_create(image);
        lv_label_set_recolor(ctcitem_name, true);

        /* Calculate and then truncate if the SUMMARY field is greater than or equal to 37 characters; then insert an ellipsis in place of the long string */
        if(summary_count >= 37) {
            lv_label_set_text(ctcitem_name, contacts_list[i].contact_name);
            lv_label_cut_text(ctcitem_name,35,summary_count);
            lv_label_ins_text(ctcitem_name,37,"...");
        } else {
            lv_label_set_text(ctcitem_name, contacts_list[i].contact_name);
        }

        lv_obj_align(ctcitem_name, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset + 15);
        lv_obj_set_style_text_color(ctcitem_name, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
        lv_obj_set_style_text_line_space(ctcitem_name, CONTACT_LINE_SPACING, LV_PART_MAIN);
        lv_obj_set_style_text_font(ctcitem_name, &NeueHaasDisplayLight_20, LV_PART_MAIN);

        // Add a list item separator line above the list item text
        list_item_separator[i] = lv_img_create(image);
        lv_img_set_src(list_item_separator[i], &Linez);
        lv_obj_align(list_item_separator[i], LV_ALIGN_LEFT_MID, LIST_SEPARATOR, offset + 44);
    }

    /* Bottom of the viewport overlay to obscure the list to lead the user to scroll up */
    lv_obj_t * bottom_viewport_overlay = lv_obj_create(image);
    lv_obj_set_size(bottom_viewport_overlay, OVERLAY_WIDTH, OVERLAY_HEIGHT);
    lv_obj_set_pos(bottom_viewport_overlay, OVERLAY_POS_LEFT, OVERLAY_POS_FROM_TOP);
    lv_obj_set_style_border_width(bottom_viewport_overlay, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_grad_dir(bottom_viewport_overlay, LV_GRAD_DIR_VER, 0);
    lv_obj_set_style_bg_grad_color(bottom_viewport_overlay, lv_color_hex(OVERLAY_COLOR), 0);
    lv_obj_set_style_bg_color(bottom_viewport_overlay, lv_color_hex(OVERLAY_COLOR), 0);
    lv_obj_set_style_bg_opa(bottom_viewport_overlay, 164, 0);
    lv_obj_set_style_bg_grad_stop(bottom_viewport_overlay, 255, LV_PART_MAIN);
}

void contacts_view(lv_obj_t * contacts_page) {
    /* Main page definition */
    lv_obj_t * image = lv_img_create(contacts_page);
    lv_img_set_src(image, &Background);

    /* Back button */
    render_back_button(image, back_home_button_cb);

    /* Calculate if the FROM field is greater than or equal to 25 characters */
    from_string = contacts_list[CONTACT_ID].contact_name;
    from_count = strlen(from_string);

    /* Text FROM field */
    contact_detail_from = lv_label_create(image);
    lv_label_set_recolor(contact_detail_from, true);

    /* Calculate and then truncate if the FROM field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
    if(from_count >= 25) {
        lv_label_set_text(contact_detail_from, contacts_list[CONTACT_ID].contact_name);
        lv_label_cut_text(ctcitem_name,23,from_count);
        lv_label_ins_text(ctcitem_name,25,"...");
    } else {
        lv_label_set_text(contact_detail_from, contacts_list[CONTACT_ID].contact_name);
    }

}

void contacts_menu_setup(void)
{
    lv_obj_t * contacts_page = lv_obj_create(NULL);
    lv_obj_t * background = lv_img_create(contacts_page);
    lv_img_set_src(background, &Background);

    printf("CONTACTS MENU init...\n");

    menu_dispatch_table[CONTACTS_VEC] = contacts_page;

    render_back_button(background, back_home_button_cb);
    lv_obj_center(contacts_page);
    lv_obj_set_style_bg_color(contacts_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(contacts_page, LV_FLEX_FLOW_ROW);
    //lv_obj_add_event_cb(contacts_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(contacts_page, true, 3);
    lv_obj_set_scroll_dir(contacts_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(contacts_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(contacts_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);
}
