#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

/* Email list and message ID variables */
#define EMAIL_LIST_MAX 5
#define EMAIL_FOUND_MAX 7
#define EMAIL_MESSAGE_ID 0

/* Email Message alignment for Subject and Message fields */
#define MESSAGE_TEXTAREA_HEIGHT 290
#define MESSAGE_TEXTAREA_WIDTH 332
#define EMAIL_MESSAGE_PAD_LEFT 30
#define EMAIL_MESSAGE_SUBJECT 120
#define EMAIL_MESSAGE_CONTENT 186
#define EMAIL_SUBJECT_LINE_SPACING 5.5
#define EMAIL_MESSAGE_LINE_SPACING 5.5

/* Message content attributes */
#define MESSAGE_CONTENT_COLOR 0xADB1A2

/*** BEG -- Font definitions from Figma ***/
/* EMAIL LIST - FROM :: styleName: P2 - Neue - 24px;
font-family: Neue Haas Grotesk Display Pro;
font-size: 24px;
font-weight: 400;
line-height: 24px;
letter-spacing: 0em;
text-align: center;
*/

/* EMAIL LIST - SUBJECT :: styleName: P3 - Neue - 20px;
font-family: Neue Haas Grotesk Display Pro;
font-size: 20px;
font-weight: 400;
line-height: 20px;
letter-spacing: 0em;
text-align: left;
*/

/* EMAIL VIEW - SUBJECT :: styleName: P1 - Neue - 32 px;
font-family: Neue Haas Grotesk Display Pro;
font-size: 32px;
font-weight: 400;
line-height: 32px;
letter-spacing: 0em;
text-align: left;
*/

/* EMAIL VIEW - MESSAGE :: styleName: P2 - Neue - 24px;
font-family: Neue Haas Grotesk Display Pro;
font-size: 24px;
font-weight: 400;
line-height: 24px;
letter-spacing: 0em;
text-align: left;
*/
/*** END ***/

#define LV_FONT_MONTSERRAT_44 1

#define FONT_SIZE_WORKS 0 // Until it's figured out

/* Main screen alignment settings to ensure consistency across app screens */
#define LIST_LEFT_ALIGNED 25
#define LIST_CONTENT_ITEM 50

/* Main HEADING iconography */
LV_IMG_DECLARE(Email_App_Heading_Title);

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

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

static lv_obj_t * email_messages[EMAIL_LIST_MAX];

static email_item email_list[EMAIL_LIST_MAX] = {
    {
        .email_id = 0,
        .email_from = "Guillaume Jaulerry",
        .email_subject = "Call: O Team Meeting",
        .email_status = &Icon_Email_Unread_Yellow,
        .email_message = "Some string of senseless content here...\n\nWe will need to create some sort of latin gobbledeegook here...\n\nBlah-blah-blah... BANANA!",
    },
    {
        .email_id = 1,
        .email_from = "O Company",
        .email_subject = "RE: Call: O Team Meeting",
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
        .email_message = "Some giant string of text here. Will need to post some sort of Some giant string of text HERE.\n\nWill need to post some sort of Some giant string of text here. Will need to post some SORT OF\n\nlatin/gobbledeegook here... blah-blah-blah... Some giant string of text here. Will need to post some sort of latin/gobbledeegook here... blah-blah-blah... Some giant string of text HERE.\n\nWill need to post some sort of latin/gobbledeegook here... blah-blah-blah... BANANA!",
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
    // lv_label_set_recolor(page_header, true);
    lv_img_set_src(page_header, &Email_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 23);
    // lv_label_set_text(page_header, "Email");
    // lv_obj_set_style_text_color(page_header, lv_color_white(), 0);

    /* Add the email list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, LIST_LEFT_ALIGNED, 60);
    lv_label_set_text(list_name, "All emails");
    lv_obj_set_style_text_color(list_name, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset;

    /* Add (simulated) devices entries as clickable buttons*/
    for (int i = 0; i < EMAIL_LIST_MAX; i++)
    {

        left.y = left.y + offset;
        right.y = right.y + offset;
        // add_separator_line(left, right, image);

        offset =  -125 + (70 * i);

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
        lv_obj_align(email_from, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset - 15);
        lv_label_set_text(email_from, email_list[i].email_from);

        lv_obj_set_style_text_color(email_from, lv_color_white(), 0);
        lv_obj_set_style_text_font(email_from, &NeueHaasDisplayLight_24, LV_PART_MAIN);

        /* Email message SUBJECT field */
        email_subject = lv_label_create(image);
        lv_label_set_recolor(email_subject, true);
        lv_obj_align(email_subject, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset + 15);
        lv_label_set_text(email_subject, email_list[i].email_subject);
        lv_obj_set_style_text_color(email_subject, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
        lv_obj_set_style_text_line_space(email_subject, EMAIL_MESSAGE_LINE_SPACING, LV_PART_MAIN);
        lv_obj_set_style_text_font(email_subject, &NeueHaasDisplayLight_20, LV_PART_MAIN);

    }
}

void email_message_view(lv_obj_t * email_message_page) {
    /* Main page definition */
    lv_obj_t * image = lv_img_create(email_message_page);
    lv_img_set_src(image, &Background);

    /* Back button */
    render_back_button(image, back_home_button_cb);

    /* Email SUBJECT field */
    email_subject = lv_label_create(image);
    lv_label_set_recolor(email_subject, true);
    lv_obj_align(email_subject, LV_ALIGN_TOP_LEFT, EMAIL_MESSAGE_PAD_LEFT, EMAIL_MESSAGE_SUBJECT);
    lv_obj_set_style_width(email_subject, MESSAGE_TEXTAREA_WIDTH, LV_PART_MAIN);
    lv_label_set_text(email_subject, email_list[EMAIL_MESSAGE_ID].email_subject);
    lv_obj_set_style_text_color(email_subject, lv_color_white(), 0);
    lv_obj_set_style_text_font(email_subject, &NeueHaasDisplayLight_32, LV_PART_MAIN);

    /* Email MESSAGE field */
    email_message = lv_textarea_create(image);
    lv_obj_set_scrollbar_mode(email_message, LV_SCROLLBAR_MODE_OFF);
    lv_obj_align(email_message, LV_ALIGN_TOP_LEFT, EMAIL_MESSAGE_PAD_LEFT, EMAIL_MESSAGE_CONTENT);
    lv_obj_set_style_height(email_message, MESSAGE_TEXTAREA_HEIGHT, LV_PART_MAIN);
    lv_obj_set_style_width(email_message, MESSAGE_TEXTAREA_WIDTH, LV_PART_MAIN);
    lv_obj_set_style_border_width(email_message, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(email_message, 0, LV_PART_MAIN);

    lv_textarea_add_text(email_message, email_list[EMAIL_MESSAGE_ID].email_message);
    lv_obj_set_style_text_color(email_message, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_set_style_text_line_space(email_message, EMAIL_MESSAGE_LINE_SPACING, LV_PART_MAIN);
    lv_obj_set_style_text_font(email_message, &NeueHaasDisplayLight_22, LV_PART_MAIN);

    lv_obj_set_style_pad_all(email_message, 0, LV_PART_MAIN);

    /* Message TEXTAREA opacity gradation overlay */

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
