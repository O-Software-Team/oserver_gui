#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

/* Text Message list and message ID variables */
#define TXTMSG_LIST_MAX 5
#define TXTMSG_FOUND_MAX 5
#define TXTMSG_MESSAGE_ID 0

/* Text Message alignment for From, Truncated Message, Full Message, and Item separator lines */
#define MESSAGE_TEXTAREA_HEIGHT 290
#define MESSAGE_TEXTAREA_WIDTH 332
#define TEXT_MESSAGE_PAD_LEFT 30
#define TEXT_MESSAGE_SUBJECT 120
#define TEXT_MESSAGE_CONTENT 186
#define TEXT_SUBJECT_LINE_SPACING 5.5
#define TEXT_MESSAGE_LINE_SPACING 5.5
#define LIST_LEFT_ALIGNED 25
#define LIST_SEPARATOR 30
#define LIST_CONTENT_ITEM 50

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

LV_IMG_DECLARE(Icon_Text_Filter_White);
LV_IMG_DECLARE(Icon_Text_Unread_Yellow);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Time);
LV_IMG_DECLARE(Linez);

/* Main HEADING iconography */
LV_IMG_DECLARE(Text_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

/* global static */
static lv_obj_t * txtmsg_messages[TXTMSG_LIST_MAX];

// static lv_obj_t * trusted_device_btn_list[TXTMSG_PAGE_MAX];
// static lv_obj_t * found_btn[TXTMSG_FOUND_MAX];

static txtmsg_item txtmsg_list[TXTMSG_LIST_MAX] = {
    {
        .txtmsg_id = 0,
        .txtmsg_from = "+33 764 281599",
        .txtmsg_summary = "Bonjour Ricardo! Vous ettes ...",
        .txtmsg_status = &Icon_Text_Unread_Yellow,
        .txtmsg_message = "Bonjour Ricardo! Vous ettes in the main part of the city. Maybe we need to check on some sort of blah-blah-blah...",
    },
    {
        .txtmsg_id = 1,
        .txtmsg_from = "Lord John Whorfin",
        .txtmsg_summary = "The overthruster has been on...",
        .txtmsg_status = &Icon_Text_Unread_Yellow,
        .txtmsg_message = "The overthruster has been on the main stage for more than 10 minutes - John Bigboote, you must get it! Blah-blah-blah... BANANA!",
    },

    {
        .txtmsg_id = 2,
        .txtmsg_from = "+1 732-555-1212",
        .txtmsg_summary = "Burgers? I'm ready to chow d...",
        .txtmsg_status = &Icon_Status_Disable,
        .txtmsg_message = "Burgers? I'm ready to chow down -- Blah-blah-blah... BANANA!",
    },
    {
        .txtmsg_id = 3,
        .txtmsg_from = "+1 650-767-3287",
        .txtmsg_summary = "Join the Site Inspire team t...",
        .txtmsg_status = &Icon_Status_Disable,
        .txtmsg_message = "Join the Site Inspire team tomorrow at Booth #148-A for the free give-away! We've got you all suckered in! Blah-blah-blah... BANANA!",
    },
    {
        .txtmsg_id = 4,
        .txtmsg_from = "John Bigboote",
        .txtmsg_summary = "John Whorfin I have the over...",
        .txtmsg_status = &Icon_Status_Disable,
        .txtmsg_message = "John Whorfin I have the overthruster! You must meet me in the lab immediately! Blah-blah-blah... BANANA!",
    },
};

lv_label_t * txtmsg_id;
lv_label_t * txtmsg_from;
lv_label_t * txtmsg_summary;
lv_label_t * txtmsg_status;
lv_label_t * txtmsg_message;
lv_obj_t * top_of_list_items;
lv_obj_t * spacer;
// lv_label_t * label_index;

/* The following function populates the main screen with read and unread text messages */
void txtmsg_list_init(lv_obj_t * txtmsg_page) {

    lv_obj_t * image = lv_img_create(txtmsg_page);
    lv_img_set_src(image, &Background);

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the email messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_img_set_zoom(filter_image, 160);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 32);

    // Use the following to create a button -- save for later
    // lv_obj_t * add = lv_btn_create(image);
    // lv_obj_set_size(add, 50, 50);
    // lv_obj_align(add, LV_ALIGN_TOP_MID, 140, 15);
    // //lv_obj_add_event_cb(add, found_devices_handler, LV_EVENT_CLICKED, 0);
    // //lv_obj_set_user_data(add, device_page);
    // lv_obj_set_style_opa(add, LV_OPA_0, LV_PART_MAIN);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Text_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 50);

    /* Add the email list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, LIST_LEFT_ALIGNED, 114);
    lv_label_set_text(list_name, "On Bob's MacBook");
    lv_obj_set_style_text_color(list_name, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line above the list item text
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 147);


    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    // lv_coord_t offset;
    lv_coord_t offset = 0;
    lv_obj_t * list_item_separator[TXTMSG_LIST_MAX];

    /* Add (simulated) devices entries as clickable buttons*/
    for (int i = 0; i < TXTMSG_LIST_MAX; i++)
    {

        left.y = left.y + offset;
        right.y = right.y + offset;

        offset =  -64 + (92 * i);
        // offset =  -135 + (60 * i);

        /* This is the opaque button overlay so you can Click-To-View the drill-down view of the item */
        // trusted_txtmsg_btn_list[i] = lv_btn_create(image);
        // lv_obj_set_size(trusted_txtmsg_btn_list[i], 330, 50);
        // lv_obj_align(trusted_txtmsg_btn_list[i], LV_ALIGN_CENTER, 0, offset);
        // lv_obj_set_style_opa(trusted_txtmsg_btn_list[i], LV_OPA_0, LV_PART_MAIN);
        // lv_obj_add_event_cb(trusted_txtmsg_btn_list[i], txtmsg_selected_cb, LV_EVENT_CLICKED, 0);

        /* Text message READ/UNREAD icon on the left */
        lv_obj_t * txtmsg_icon = lv_img_create(image);
        lv_img_set_src(txtmsg_icon, txtmsg_list[i].txtmsg_status);
        lv_obj_align(txtmsg_icon, LV_ALIGN_LEFT_MID, LIST_LEFT_ALIGNED, offset);

        /* Text message FROM field */
        txtmsg_from = lv_label_create(image);
        lv_label_set_recolor(txtmsg_from, true);
        lv_obj_align(txtmsg_from, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset - 15);
        lv_label_set_text(txtmsg_from, txtmsg_list[i].txtmsg_from);
        lv_obj_set_style_text_color(txtmsg_from, lv_color_white(), 0);
        lv_obj_set_style_text_font(txtmsg_from, &NeueHaasDisplayLight_24, LV_PART_MAIN);

        /* Text message SUMMARY field */
        txtmsg_summary = lv_label_create(image);
        lv_label_set_recolor(txtmsg_summary, true);
        lv_obj_align(txtmsg_summary, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset + 15);
        lv_label_set_text(txtmsg_summary, txtmsg_list[i].txtmsg_summary);
        lv_obj_set_style_text_color(txtmsg_summary, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
        lv_obj_set_style_text_line_space(txtmsg_summary, TEXT_MESSAGE_LINE_SPACING, LV_PART_MAIN);
        lv_obj_set_style_text_font(txtmsg_summary, &NeueHaasDisplayLight_20, LV_PART_MAIN);

        // Add a list item separator line above the list item text
        list_item_separator[i] = lv_img_create(image);
        lv_img_set_src(list_item_separator[i], &Linez);
        lv_obj_align(list_item_separator[i], LV_ALIGN_LEFT_MID, LIST_SEPARATOR, offset + 44);
    }
}

void txtmsg_menu_setup(void)
{

    printf("TEXT MESSAGE MENU init...\n");

    lv_obj_t * txtmsg_page = lv_obj_create(NULL);
    menu_dispatch_table[TEXT_VEC] = txtmsg_page;

    lv_obj_center(txtmsg_page);
    lv_obj_set_style_bg_color(txtmsg_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(txtmsg_page, LV_FLEX_FLOW_ROW);
    //lv_obj_add_event_cb(txtmsg_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(txtmsg_page, true, 3);
    lv_obj_set_scroll_dir(txtmsg_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(txtmsg_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(txtmsg_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* MAIN-SCREEN: Display the list of text messages: unread and read comingled together */
    txtmsg_list_init(txtmsg_page);

}