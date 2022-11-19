#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

/* Email list and message ID variables */
#define EMAIL_LIST_MAX 4
#define EMAIL_FOUND_MAX 7
#define EMAIL_MESSAGE_ID 0

/* Email Message alignment for From, Subject, Full Message, and Item separator lines */
#define MESSAGE_TEXTAREA_HEIGHT 290
#define MESSAGE_TEXTAREA_WIDTH 332
#define MESSAGE_TEXTAREA_MASK_WIDTH 332
#define MESSAGE_TEXTAREA_MASK_HEIGHT 100

#define EMAIL_MESSAGE_PAD_LEFT 30
#define EMAIL_MESSAGE_SUBJECT 120
#define EMAIL_MESSAGE_CONTENT 186
#define EMAIL_SUBJECT_LINE_SPACING 5.5
#define EMAIL_MESSAGE_LINE_SPACING 5.5
#define LIST_LEFT_ALIGNED 25
#define LIST_SEPARATOR 30
#define LIST_CONTENT_ITEM 50

/* Message content attributes */
#define MESSAGE_CONTENT_COLOR 0xADB1A2

/* Bottom of viewport attributes */
#define OVERLAY_WIDTH 345
#define OVERLAY_HEIGHT 70
#define OVERLAY_POS_LEFT 20
#define OVERLAY_POS_FROM_TOP 440
#define OVERLAY_COLOR 0x0F0F0F

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
LV_IMG_DECLARE(Linez);

/* Main HEADING iconography */
LV_IMG_DECLARE(Email_App_Heading_Title);

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
        .email_from = "Yoyodyne Propulsion Systems Inc.",
        .email_subject = "Oscillation overthruster designs",
        .email_status = &Icon_Email_Unread_Yellow,
        .email_message = "Blah-blah-blah... BANANA!",
    },
    {
        .email_id = 3,
        .email_from = "Dr Emilio Lizardo",
        .email_subject = "RE: Get the oscillation overthruster!",
        .email_status = &Icon_Status_Disable,
        .email_message = "Some giant string of text here. Will need to post some sort of Some giant string of text HERE.\n\nWill need to post some sort of Some giant string of text here. Will need to post some SORT OF\n\nlatin/gobbledeegook here... blah-blah-blah... Some giant string of text here. Will need to post some sort of latin/gobbledeegook here... blah-blah-blah... Some giant string of text HERE.\n\nWill need to post some sort of latin/gobbledeegook here... blah-blah-blah... BANANA!",
    },
    {
        .email_id = 4,
        .email_from = "Bob's Big Boy",
        .email_subject = "Burgers? You bet!",
        .email_status = &Icon_Status_Disable,
        .email_message = "Blah-blah-blah... BANANA!",
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

/* Set variables to calculate and then truncate strings too wide for the viewport -- insert an ellipsis in place of the long string */
const char * from_string;
int from_count;
const char * subject_string;
int subject_count;
const char * message_string;
int message_count;

/* Set variables for all the message content fields: ID, FROM, SUBJECT, MESSAGE */
lv_label_t * email_id;
lv_label_t * email_from;
lv_label_t * email_subject;
lv_label_t * email_status;
lv_label_t * email_message;
lv_obj_t * top_of_list_items;
lv_obj_t * spacer;

/* The following function populates the main screen with read and unread emails */
void email_list_init(lv_obj_t * email_page) {
    lv_obj_t * image = lv_img_create(email_page);
    lv_img_set_src(image, &Background);

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the email messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header using iconography at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Email_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the email list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, LIST_LEFT_ALIGNED, 108);
    lv_label_set_text(list_name, "All emails");
    lv_obj_set_style_text_color(list_name, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line above the list item set
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 147);

    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;
    lv_obj_t * list_item_separator[EMAIL_LIST_MAX];

    /* Add (simulated) email messages as clickable buttons*/
    for (int i = 0; i < EMAIL_LIST_MAX; i++) {

        left.y = left.y + offset;
        right.y = right.y + offset;

        offset =  -64 + (92 * i);

        /* Calculate if the FROM field is greater than or equal to 25 characters */
        from_string = email_list[i].email_from;
        from_count = strlen(from_string);

        /* Calculate if the SUBJECT field is greater than or equal to 37 characters */
        subject_string = email_list[i].email_subject;
        subject_count = strlen(subject_string);

        /* Calculate if the MESSAGE field is greater than or equal to 37 characters */
        message_string = email_list[i].email_message;
        message_count = strlen(message_string);

        /* Email message READ/UNREAD icon on the left */
        lv_obj_t * email_icon = lv_img_create(image);
        lv_img_set_src(email_icon, email_list[i].email_status);
        lv_obj_align(email_icon, LV_ALIGN_LEFT_MID, LIST_LEFT_ALIGNED, offset);

        /* Email message FROM field */
        email_from = lv_label_create(image);
        lv_label_set_recolor(email_from, true);

        /* Calculate and then truncate if the FROM field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
        if(from_count >= 25) {
            lv_label_set_text(email_from, email_list[i].email_from);
            lv_label_cut_text(email_from,23,from_count);
            lv_label_ins_text(email_from,25,"...");
        } else {
            lv_label_set_text(email_from, email_list[i].email_from);
        }

        lv_obj_align(email_from, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset - 15);
        lv_obj_set_style_text_color(email_from, lv_color_white(), 0);
        lv_obj_set_style_text_font(email_from, &NeueHaasDisplayLight_24, LV_PART_MAIN);

        /* Email message SUBJECT field */
        email_subject = lv_label_create(image);
        lv_label_set_recolor(email_subject, true);

        /* Calculate and then truncate if the SUBJECT field is greater than or equal to 37 characters; then insert an ellipsis in place of the long string */
        if(subject_count >= 37) {
            lv_label_set_text(email_subject, email_list[i].email_subject);
            lv_label_cut_text(email_subject, 35, subject_count);
            lv_label_ins_text(email_subject, 37, "...");
        } else {
            lv_label_set_text(email_subject, email_list[i].email_subject);
        }

        lv_obj_align(email_subject, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset + 15);
        lv_obj_set_style_text_color(email_subject, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
        lv_obj_set_style_text_line_space(email_subject, EMAIL_MESSAGE_LINE_SPACING, LV_PART_MAIN);
        lv_obj_set_style_text_font(email_subject, &NeueHaasDisplayLight_20, LV_PART_MAIN);

        // Add a list item separator line at the end of the list item
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

void email_message_view(lv_obj_t * email_message_page) {
    /* Main page definition */
    lv_obj_t * image = lv_img_create(email_message_page);
    lv_img_set_src(image, &Background);

    /* Back button */
    render_back_button(image, back_home_button_cb);

    /* Calculate if the SUBJECT field is greater than or equal to 37 characters */
    subject_string = email_list[EMAIL_MESSAGE_ID].email_subject;
    subject_count = strlen(subject_string);

    /* Email SUBJECT field */
    email_subject = lv_label_create(image);
    lv_label_set_recolor(email_subject, true);

    /* Calculate and then truncate if the SUBJECT field is greater than or equal to 37 characters; then insert an ellipsis in place of the long string */
    if(subject_count >= 37) {
        lv_label_set_text(email_subject, email_list[EMAIL_MESSAGE_ID].email_subject);
        lv_label_cut_text(email_subject,35,subject_count);
        lv_label_ins_text(email_subject,37,"...");
    } else {
        lv_label_set_text(email_subject, email_list[EMAIL_MESSAGE_ID].email_subject);
    }

    lv_obj_align(email_subject, LV_ALIGN_TOP_LEFT, EMAIL_MESSAGE_PAD_LEFT, EMAIL_MESSAGE_SUBJECT);
    lv_obj_set_style_width(email_subject, MESSAGE_TEXTAREA_WIDTH, LV_PART_MAIN);
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
