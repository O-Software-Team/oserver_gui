#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

#define EMAIL_LIST_MAX 7
#define EMAIL_FOUND_MAX 7
#define EMAIL_MESSAGE_ID 4;

#define LV_FONT_MONTSERRAT_44 1

#define FONT_SIZE_WORKS 0 // Until it's figured out

/* Email Message alignment for Subject and Message fields */
#define EMAIL_MESSAGE_SUBJECT 120
#define EMAIL_MESSAGE_CONTENT 180

/* Main screen alignment settings to ensure consistency across app screens */
#define LIST_LEFT_ALIGNED 25
#define LIST_CONTENT_ITEM 50

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

LV_IMG_DECLARE(Icon_Email_Unread_Yellow);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Time);

/* Physical component iconography like computer, phone, or tablet declared here */
// LV_IMG_DECLARE(Icon_iPad);
// LV_IMG_DECLARE(Icon_MacBook);
// LV_IMG_DECLARE(Icon_iPhone);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

/* global static */
// static lv_obj_t * trusted_device_list[EMAIL_PAGE_MAX];
static lv_obj_t * email_messages[EMAIL_LIST_MAX];

// static lv_obj_t * trusted_device_btn_list[EMAIL_PAGE_MAX];
// static lv_obj_t * found_btn[EMAIL_FOUND_MAX];

// static menu_item devices_active_info[EMAIL_PAGE_MAX] = {
//     {.menu_name = "Kevin's iPhone",   .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPhone},
//     {.menu_name = "Mark's iPad",      .page_handler = &add_device_cb,  .active = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
//     {.menu_name = "Alice's Macbook",  .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_MacBook},
//     {.menu_name = "Ted's iPad",       .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPad},
//     {.menu_name = "Office iPad",      .page_handler = &add_device_cb,  .active = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
//     {.menu_name = "Mary's iPhone",    .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPhone},
// };

static email_item email_list[EMAIL_LIST_MAX] = {
    {
        .email_id = 0,
        .email_from = "Guillaume Jaulerry",
        .email_subject = "Call: O Team Meeting",
        .email_status = &Icon_Email_Unread_Yellow,
        .email_message = "Some giant string of text here. Will need to post some sort of latin/gobbledeegook here...",
    },
    {
        .email_id = 1,
        .email_from = "O Company",
        .email_subject = "Call: O Team Meeting",
        .email_status = &Icon_Email_Unread_Yellow,
        .email_message = "Blah-blah-blah... BANANA!",
    },
    {
        .email_id = 2,
        .email_from = "Yoyodyne Propulsion",
        .email_subject = "Oscillation overthruster designs",
        .email_status = &Icon_Email_Unread_Yellow,
        .email_message = "Blah-blah-blah... BANANA!",
    },
    {
        .email_id = 3,
        .email_from = "Bob's Big Boy",
        .email_subject = "Burgers? You bet!",
        .email_status = &Icon_Status_Disable,
        .email_message = "Blah-blah-blah... BANANA!",
    },
    {
        .email_id = 4,
        .email_from = "Dr Emilio Lizardo",
        .email_subject = "RE: Get the oscillation overthruster!",
        .email_status = &Icon_Status_Disable,
        .email_message = "Some giant string of text here. Will need to post some sort of latin/gobbledeegook here... blah-blah-blah... BANANA!",
    },
    {
        .email_id = 5,
        .email_from = "Site Inspire",
        .email_subject = "Site Inspire x Week 16",
        .email_status = &Icon_Status_Disable,
        .email_message = "Blah-blah-blah... BANANA!",
    },
    {
        .email_id = 6,
        .email_from = "John Ya Ya",
        .email_subject = "Where is Professor Hikita?",
        .email_status = &Icon_Status_Disable,
        .email_message = "Blah-blah-blah... BANANA!",
    },
};

lv_label_t * email_id;
lv_label_t * email_from;
lv_label_t * email_subject;
lv_label_t * email_status;
lv_label_t * email_message;
// lv_label_t * label_index;

/* The following function populates the main screen with read and unread emails */
void email_list_init(lv_obj_t * email_page) {

    lv_obj_t * image = lv_img_create(email_page);
    lv_img_set_src(image, &Background);

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the email messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_img_set_zoom(filter_image, 160);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 110, 18);

    // Use the following to create a button -- save for later
    // lv_obj_t * filter_image = lv_btn_create(image);
    // lv_obj_set_size(filter_image, 50, 50);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 140, 15);
    // //lv_obj_add_event_cb(filter_image, found_devices_handler, LV_EVENT_CLICKED, 0);
    // //lv_obj_set_user_data(filter_image, device_page);
    // lv_obj_set_style_opa(filter_image, LV_OPA_0, LV_PART_MAIN);

//{ .menu_pre = "De",       .menu_italic = "v",  .lx_offset = -20, .mx_offset = 0, .rx_offset = 26, .menu_post = "ices", .active = true },

    /* Add the Page header at the top */
    lv_label_t * page_header = lv_label_create(image);
    lv_label_set_recolor(page_header, true);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 23);
    lv_label_set_text(page_header, "Email");
    lv_obj_set_style_text_color(page_header, lv_color_white(), 0);

    /* Add the email list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, LIST_LEFT_ALIGNED, 60);
    lv_label_set_text(list_name, "All emails");
    lv_obj_set_style_text_color(list_name, lv_palette_main(LV_PALETTE_GREY), 0);

    /* The WiFi indicator */
    lv_obj_t * wifi_symbol = lv_img_create(image);
    lv_img_set_src(wifi_symbol, &Icon_WiFi_White);
    lv_obj_align(wifi_symbol, LV_ALIGN_DEFAULT, 275, 60);

    /* The Bluetooth indicator */
    lv_obj_t * bt_symbol = lv_img_create(image);
    lv_img_set_src(bt_symbol, &Icon_Bluetooth_White);
    lv_obj_align(bt_symbol, LV_ALIGN_DEFAULT, 295, 60);

    /* The NFC indicator */
    lv_obj_t * nfc_symbol = lv_img_create(image);
    lv_img_set_src(nfc_symbol, &Icon_NFC_White);
    lv_obj_align(nfc_symbol, LV_ALIGN_DEFAULT, 315, 60);
    lv_obj_set_style_opa(nfc_symbol, LV_OPA_40, LV_PART_MAIN);

    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset;

    /* Add (simulated) devices entries as clickable buttons*/
    for (int i = 0; i < EMAIL_LIST_MAX; i++)
    {

        left.y = left.y + offset;
        right.y = right.y + offset;
        // add_separator_line(left, right, image);

        offset =  -135 + (60 * i);

        /* This is the opaque button overlay so you can Click-To-View the drill-down view of the item */
        // trusted_email_btn_list[i] = lv_btn_create(image);
        // lv_obj_set_size(trusted_email_btn_list[i], 330, 50);
        // lv_obj_align(trusted_email_btn_list[i], LV_ALIGN_CENTER, 0, offset);
        // lv_obj_set_style_opa(trusted_email_btn_list[i], LV_OPA_0, LV_PART_MAIN);
        // lv_obj_add_event_cb(trusted_email_btn_list[i], email_selected_cb, LV_EVENT_CLICKED, 0);

        /* Email message READ/UNREAD icon on the left */
        lv_obj_t * email_icon = lv_img_create(image);
        lv_img_set_src(email_icon, email_list[i].email_status);
        lv_obj_align(email_icon, LV_ALIGN_LEFT_MID, LIST_LEFT_ALIGNED, offset);
        lv_obj_set_style_opa(email_icon, LV_OPA_70, LV_PART_MAIN);

        /* Email message FROM field */
        email_from = lv_label_create(image);
        lv_label_set_recolor(email_from, true);
        lv_obj_align(email_from, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset - 10);
        lv_label_set_text(email_from, email_list[i].email_from);
        lv_obj_set_style_text_color(email_from, lv_color_white(), 0);

        /* Email message SUBJECT field */
        email_subject = lv_label_create(image);
        lv_label_set_recolor(email_subject, true);
        lv_obj_align(email_subject, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset + 10);
        lv_label_set_text(email_subject, email_list[i].email_subject);
        lv_obj_set_style_text_color(email_subject, lv_palette_main(LV_PALETTE_GREY), 0);
    }
}

void email_message_view(lv_obj_t * email_message_page) {
    lv_obj_t * image = lv_img_create(email_message_page);
    lv_img_set_src(image, &Background);

    render_back_button(image, back_home_button_cb);

    /* Email message SUBJECT field */
    email_subject = lv_label_create(image);
    lv_label_set_recolor(email_subject, true);
    lv_obj_align(email_subject, LV_ALIGN_TOP_LEFT, LIST_CONTENT_ITEM, EMAIL_MESSAGE_SUBJECT);
    lv_label_set_text(email_subject, email_list[4].email_subject);
    lv_obj_set_style_text_color(email_subject, lv_color_white(), 0);

    /* Email message MESSAGE field */
    email_message = lv_textarea_create(image);
    // lv_label_set_recolor(email_subject, true);
    lv_obj_align(email_message, LV_ALIGN_TOP_LEFT, LIST_CONTENT_ITEM, EMAIL_MESSAGE_CONTENT);
    lv_textarea_add_text(email_message, email_list[4].email_message);
    // lv_label_set_text(email_message, email_list[4].email_message);

    // lv_style_set_outline_width(email_message, 0);
    // lv_style_set_outline_color(email_message, lv_palette_main(LV_PALETTE_BLUE));
    // lv_style_set_outline_pad(email_message, 0);
    // lv_obj_set_style_outline_width(email_message, 0, LV_PART_MAIN);
    lv_obj_set_style_outline_color(email_message, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);

    lv_obj_set_style_text_color(email_message, lv_palette_main(LV_PALETTE_GREY), 0);
    lv_obj_set_style_bg_opa(email_message, 0, LV_PART_MAIN);
}

void email_menu_setup(void)
{

    printf("EMAIL MENU init...\n");

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

    /* MAIN-SCREEN: Display the list of emails: unread and read comingled together */
    email_list_init(email_page);

    /* MESSAGE VIEW: Display the email message SUBJECT and MESSAGE */
    email_message_view(email_page);

}
