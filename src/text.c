#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

#define TXTMSG_LIST_MAX 5
#define TXTMSG_FOUND_MAX 5

#define LV_FONT_MONTSERRAT_44 1

/* Main screen alignment settings to ensure consistency across app screens */
#define LIST_LEFT_ALIGNED 25
#define LIST_CONTENT_ITEM 50

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
LV_IMG_DECLARE(Icon_Text_Filter_White);
LV_IMG_DECLARE(Icon_Text_Unread_Yellow);
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
// static lv_obj_t * trusted_device_list[TXTMSG_PAGE_MAX];
static lv_obj_t * txtmsg_messages[TXTMSG_LIST_MAX];

// static lv_obj_t * trusted_device_btn_list[TXTMSG_PAGE_MAX];
// static lv_obj_t * found_btn[TXTMSG_FOUND_MAX];

// static menu_item devices_active_info[TXTMSG_PAGE_MAX] = {
//     {.menu_name = "Kevin's iPhone",   .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPhone},
//     {.menu_name = "Mark's iPad",      .page_handler = &add_device_cb,  .active = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
//     {.menu_name = "Alice's Macbook",  .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_MacBook},
//     {.menu_name = "Ted's iPad",       .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPad},
//     {.menu_name = "Office iPad",      .page_handler = &add_device_cb,  .active = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
//     {.menu_name = "Mary's iPhone",    .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPhone},
// };

static txtmsg_item txtmsg_list[TXTMSG_LIST_MAX] = {
    {
        .txtmsg_id = 0,
        .txtmsg_from = "+33 764 281599",
        .txtmsg_subject = "Bonjour Ricardo! Vous ettes ...",
        .txtmsg_status = &Icon_Text_Unread_Yellow,
        .txtmsg_message = "Bonjour Ricardo! Vous ettes in the main part of the city. Maybe we need to check on some sort of blah-blah-blah...",
    },
    {
        .txtmsg_id = 1,
        .txtmsg_from = "Lord John Whorfin",
        .txtmsg_subject = "The overthruster has been on...",
        .txtmsg_status = &Icon_Text_Unread_Yellow,
        .txtmsg_message = "The overthruster has been on the main stage for more than 10 minutes - John Bigboote, you must get it! Blah-blah-blah... BANANA!",
    },

    {
        .txtmsg_id = 2,
        .txtmsg_from = "+1 732-555-1212",
        .txtmsg_subject = "Burgers? I'm ready to chow d...",
        .txtmsg_status = &Icon_Status_Disable,
        .txtmsg_message = "Burgers? I'm ready to chow down -- Blah-blah-blah... BANANA!",
    },
    {
        .txtmsg_id = 3,
        .txtmsg_from = "+1 650-767-3287",
        .txtmsg_subject = "Join the Site Inspire team t...",
        .txtmsg_status = &Icon_Status_Disable,
        .txtmsg_message = "Join the Site Inspire team tomorrow at Booth #148-A for the free give-away! We've got you all suckered in! Blah-blah-blah... BANANA!",
    },
    {
        .txtmsg_id = 4,
        .txtmsg_from = "John Bigboote",
        .txtmsg_subject = "John Whorfin I have the over...",
        .txtmsg_status = &Icon_Status_Disable,
        .txtmsg_message = "John Whorfin I have the overthruster! You must meet me in the lab immediately! Blah-blah-blah... BANANA!",
    },
};

lv_label_t * txtmsg_id;
lv_label_t * txtmsg_from;
lv_label_t * txtmsg_subject;
lv_label_t * txtmsg_status;
// lv_label_t * label_index;

/* The following function populates the main screen with read and unread text messages */
void txtmsg_list_init(lv_obj_t * txtmsg_page) {

    lv_obj_t * image = lv_img_create(txtmsg_page);
    lv_img_set_src(image, &Background);

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the email messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_img_set_zoom(filter_image, 160);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 110, 18);

    // Use the following to create a button -- save for later
    // lv_obj_t * add = lv_btn_create(image);
    // lv_obj_set_size(add, 50, 50);
    // lv_obj_align(add, LV_ALIGN_TOP_MID, 140, 15);
    // //lv_obj_add_event_cb(add, found_devices_handler, LV_EVENT_CLICKED, 0);
    // //lv_obj_set_user_data(add, device_page);
    // lv_obj_set_style_opa(add, LV_OPA_0, LV_PART_MAIN);

    /* Add the Page header at the top */
    lv_label_t * page_header = lv_label_create(image);
    lv_label_set_recolor(page_header, true);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 23);
    lv_label_set_text(page_header, "Text");
    lv_obj_set_style_text_color(page_header, lv_color_white(), 0);

    /* Add the email list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, LIST_LEFT_ALIGNED, 60);
    lv_label_set_text(list_name, "All messages");
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
    for (int i = 0; i < TXTMSG_LIST_MAX; i++)
    {

        left.y = left.y + offset;
        right.y = right.y + offset;
        // add_separator_line(left, right, image);

        offset =  -135 + (60 * i);

        /* This is the opaque button overlay so you can Click-To-View the drill-down view of the item */
        // trusted_txtmsg_btn_list[i] = lv_btn_create(image);
        // lv_obj_set_size(trusted_txtmsg_btn_list[i], 330, 50);
        // lv_obj_align(trusted_txtmsg_btn_list[i], LV_ALIGN_CENTER, 0, offset);
        // lv_obj_set_style_opa(trusted_txtmsg_btn_list[i], LV_OPA_0, LV_PART_MAIN);
        // lv_obj_add_event_cb(trusted_txtmsg_btn_list[i], txtmsg_selected_cb, LV_EVENT_CLICKED, 0);

        /* Email message READ/UNREAD icon on the left */
        lv_obj_t * txtmsg_icon = lv_img_create(image);
        lv_img_set_src(txtmsg_icon, txtmsg_list[i].txtmsg_status);
        lv_obj_align(txtmsg_icon, LV_ALIGN_LEFT_MID, LIST_LEFT_ALIGNED, offset);
        lv_obj_set_style_opa(txtmsg_icon, LV_OPA_70, LV_PART_MAIN);

        /* Email message FROM field */
        txtmsg_from = lv_label_create(image);
        lv_label_set_recolor(txtmsg_from, true);
        lv_obj_align(txtmsg_from, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset - 10);
        lv_label_set_text(txtmsg_from, txtmsg_list[i].txtmsg_from);
        lv_obj_set_style_text_color(txtmsg_from, lv_color_white(), 0);

        /* Email message SUBJECT field */
        txtmsg_subject = lv_label_create(image);
        lv_label_set_recolor(txtmsg_subject, true);
        lv_obj_align(txtmsg_subject, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset + 10);
        lv_label_set_text(txtmsg_subject, txtmsg_list[i].txtmsg_subject);
        lv_obj_set_style_text_color(txtmsg_subject, lv_palette_main(LV_PALETTE_GREY), 0);
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