#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

/* O App list and item ID variables */
#define DEVICE_PAGE_MAX 4
#define DEVICE_FOUND_MAX 4

/* O App alignment for elements and Item separator lines */
#define LIST_ITEM_TEXTAREA_HEIGHT 290
#define LIST_ITEM_TEXTAREA_WIDTH 332
#define LIST_ITEM_TEXTAREA_MASK_WIDTH 332
#define LIST_ITEM_TEXTAREA_MASK_HEIGHT 100

#define LIST_ITEM_PAD_LEFT 30
#define LIST_ITEM_SUBJECT 120
#define LIST_ITEM_CONTENT 186
#define LIST_ITEM_LINE_SPACING 14.5
#define LIST_LEFT_ALIGNED 25
#define LIST_SEPARATOR 30
#define LIST_CONTENT_ITEM 90

/* Element content attributes */
#define MAIN_CONTENT_COLOR 0xADB1A2

/* Bottom of viewport attributes */
#define OVERLAY_WIDTH 345
#define OVERLAY_HEIGHT 70
#define OVERLAY_POS_LEFT 20
#define OVERLAY_POS_FROM_TOP 440
#define OVERLAY_COLOR 0x0F0F0F

LV_IMG_DECLARE(Background);

/* Main HEADING iconography */
LV_IMG_DECLARE(O_App_Heading_Title);

#undef DAN_CODE

/* Set variables to calculate and then truncate strings too wide for the viewport -- insert an ellipsis in place of the long string */
const char * device_name_string;
int device_name_count;
static lv_obj_t * top_of_list_items;

static lv_obj_t * trusted_device_btn_list[DEVICE_PAGE_MAX];
static lv_timer_t * sleeptimer;

static menu_item devices_active_info[DEVICE_PAGE_MAX] = {
    {.menu_pre = "Kevin's Work iPhone",   .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_iPhone},
    {.menu_pre = "Mark's iPad",      .active = true,  .onboard = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_pre = "Alice's Macbook: Personal",  .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_MacBook},
    {.menu_pre = "Ted's iPad",       .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_iPad},
    {.menu_pre = "Office iPad",      .active = true,  .onboard = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_pre = "Mary's iPhone",    .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_iPhone},
};

static menu_item devices_found_info[DEVICE_FOUND_MAX] = {
    {.menu_pre = "Bob's iPhone",   .active = false, .security_status = FRIEND, .icon = &Icon_iPhone},
    {.menu_pre = "Marks iPad",     .active = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_pre = "Bob's Macbook",  .active = false, .security_status = FRIEND, .icon = &Icon_MacBook},
    {.menu_pre = "Orna's iPad",    .active = false, .security_status = FRIEND, .icon = &Icon_iPad},
};

static void device_selected_cb(lv_event_t * e) { printf("Selected device for total control...\n"); }

static void total_control_cb(lv_event_t * e) {

    printf("Enabling total control on device...\n");
    /*
     * Scroll to the page with the devices seen in the local area
     * This is where we add "Bob's Macbook" as "Friend".
     */
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * oserver_page = lv_obj_get_user_data(target);
    lv_obj_scroll_to_view(lv_obj_get_child(oserver_page, 1), LV_ANIM_ON);
}

/*
 * Used on the total transfer percent complete screen
 */
static lv_obj_t * percent;

static void update_percent(lv_timer_t * percent_timer) {
    static int percent_done = 0;
    lv_obj_t * oserver_page = percent_timer->user_data;
    if(percent_done++ < 100) {
        lv_label_set_text_fmt(percent, "%i", percent_done);
    }
}

static void switch_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("State: %s\n", lv_obj_has_state(obj, LV_STATE_CHECKED) ? "On" : "Off");
        if(lv_obj_has_state(obj, LV_STATE_CHECKED)) {
            lv_obj_t * oserver_page = lv_obj_get_user_data(obj);
            lv_obj_scroll_to_view(lv_obj_get_child(oserver_page, 2), LV_ANIM_ON);

            sleeptimer = lv_timer_create(update_percent, 700, oserver_page);
            lv_timer_set_repeat_count(sleeptimer, 100);
        }
    }
}

/* When a device is selected to be enquire about a trust relationship, this code page displays */
void transfer_progress_init(lv_obj_t * oserver_page)
{
    int percent_done = 0;
    int time_remaining = 12;

    static lv_style_t heading_style;
    lv_style_init(&heading_style);
    lv_style_set_text_font(&heading_style, &NeueHaasDisplayRoman_20);

    static lv_style_t min_remain_style;
    lv_style_init(&min_remain_style);
    lv_style_set_text_font(&min_remain_style, &NeueHaasDisplayRoman_20);

#if ALL_SCROLL
    lv_obj_t * image = lv_img_create(oserver_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(oserver_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);
#endif // ALL_SCROLL

    /*
     * The top middle grey circled cancel button with 'X'
     */
    lv_obj_t * grey_outline = lv_img_create(image);
    lv_img_set_src(grey_outline, &Icon_Grey_Outline_Button);
    lv_obj_align(grey_outline, LV_ALIGN_TOP_MID, 0, 30);

    lv_obj_t * cancel = lv_img_create(image);
    lv_img_set_src(cancel, &Icon_Close_White);
    lv_obj_align(cancel, LV_ALIGN_TOP_MID, 0, 40);

    /* The 'Cancel' button */
    lv_obj_t * cancel_button = lv_btn_create(image);
    lv_obj_set_size(cancel_button, 70, 50);
    lv_obj_align(cancel_button, LV_ALIGN_TOP_MID, 0, 30);
    lv_obj_add_event_cb(cancel_button, back_home_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(cancel_button, lv_obj_get_parent(image));
    lv_obj_set_style_opa(cancel_button, LV_OPA_0, LV_PART_MAIN);

    /*
     * The yellow progress page accent
     */
    lv_obj_t * progress = lv_img_create(image);
    lv_img_set_src(progress, &Progress);
    lv_obj_center(progress);

    lv_obj_t * total_transfer = lv_label_create(image);
    lv_label_set_text(total_transfer, "Total Transfer");
    lv_label_set_recolor(total_transfer, true);
    lv_obj_set_style_text_color(total_transfer, lv_color_lighten(lv_color_black(), 99), 0);
    lv_obj_add_style(total_transfer, &heading_style, LV_PART_MAIN);
    lv_obj_align(total_transfer, LV_ALIGN_DEFAULT, 140, 140);

    lv_obj_t * percent_container = lv_img_create(image);
    lv_obj_align(percent_container, LV_ALIGN_CENTER, 10, 0);
    lv_obj_set_flex_flow(percent_container, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_column(percent_container, 10, 0);

    /* The percent progress */
    static lv_style_t percent_style;
    lv_style_init(&percent_style);
    // persent is a global for now
    percent = lv_label_create(percent_container);
    lv_style_set_text_font(&percent_style, &NeueHaasDisplayXXThin_100);

    lv_label_set_text_fmt(percent, "%d", percent_done);
    lv_obj_set_style_text_color(percent, lv_color_lighten(lv_color_black(), 98), 0);
    lv_obj_add_style(percent, &percent_style, LV_PART_MAIN);
    lv_obj_align(percent, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_color(percent, lv_color_white(), 0);

    /* The smaller font percent symbol */
    static lv_style_t percent_symbol_style;
    lv_style_init(&percent_symbol_style);
    lv_obj_t * percent_symbol = lv_label_create(percent_container);
    lv_style_set_text_font(&percent_symbol_style, &NeueHaasDisplayXThin_58);

    lv_label_set_text(percent_symbol, "%");
    lv_obj_set_style_text_color(percent_symbol, lv_palette_main(LV_PALETTE_GREY), 0);
    lv_obj_add_style(percent_symbol, &percent_symbol_style, LV_PART_MAIN);
    lv_obj_align(percent_symbol, LV_ALIGN_DEFAULT, 0, 50);
    
    /* Tell them what to do with the displayed code */
    lv_obj_t * remaining = lv_label_create(image);
    lv_label_set_recolor(remaining, true);
    lv_label_set_text_fmt(remaining, "%d  min remaining", time_remaining);
    lv_obj_set_style_text_color(remaining, lv_color_lighten(lv_color_black(), 99), 0);
    lv_obj_add_style(remaining, &min_remain_style, LV_PART_MAIN);
    lv_obj_align(remaining, LV_ALIGN_DEFAULT, 130, 330);

    /* Click herer to 'run in background' text */
    lv_obj_t * background = lv_label_create(image);
    lv_label_set_recolor(background, true);
    lv_label_set_text(background, "        Run in\nBackground");
    lv_obj_set_style_text_color(background, lv_color_darken(lv_color_white(), 80), 0);
    lv_obj_add_style(background, &min_remain_style, LV_PART_MAIN);
    lv_obj_align(background, LV_ALIGN_BOTTOM_MID, 10, -50);

    /* Click here to run the transfer in background */
    lv_obj_t * background_button = lv_btn_create(image);
    lv_obj_set_size(background_button, 110, 60);
    lv_obj_align(background_button, LV_ALIGN_BOTTOM_MID, 10, -40);
    lv_obj_add_event_cb(background_button, back_home_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(background_button, lv_obj_get_parent(image));
    lv_obj_set_style_opa(background_button, LV_OPA_0, LV_PART_MAIN);
}

/* Set up the screen that selectes what data to be transfered; Email, Contact, Calendar, etc. */
void total_control_item_init(lv_obj_t * oserver_page) {

    int which_device = 1; // Meanwhile, for the show, magic
    lv_obj_t * entry_separator[4];

    static lv_style_t security_selection_style;
    lv_style_init(&security_selection_style);

    static lv_style_t header_style;
    lv_style_init(&header_style);

    static lv_style_t cancel_style;
    lv_style_init(&cancel_style);

    lv_style_set_text_font(&security_selection_style, &NeueHaasDisplayLight_18);
    lv_style_set_text_font(&header_style, &NeueHaasDisplayLight_22);
    lv_style_set_text_font(&cancel_style, &NeueHaasDisplayLight_16);

#if ALL_SCROLL
    lv_obj_t * image = lv_img_create(oserver_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(oserver_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);
#endif // ALL_SCROLL

    render_back_button(image, back_button_cb);

    /* The 'Cancel' button graphic */
    lv_obj_t * cancel = lv_label_create(image);
    lv_label_set_recolor(cancel, true);
    lv_label_set_text(cancel, "Cancel");
    lv_obj_set_style_text_color(cancel, lv_color_white(), 0);
    lv_obj_align(cancel, LV_ALIGN_DEFAULT, 300, 25);
    lv_obj_add_style(cancel, &cancel_style, LV_PART_MAIN);

    /* The 'Cancel' button */
    lv_obj_t * cancel_button = lv_btn_create(image);
    lv_obj_set_size(cancel_button, 70, 30);
    lv_obj_align(cancel_button, LV_ALIGN_DEFAULT, 290, 20);
    lv_obj_add_event_cb(cancel_button, back_home_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(cancel_button, lv_obj_get_parent(image));
    lv_obj_set_style_opa(cancel_button, LV_OPA_0, LV_PART_MAIN);

    lv_obj_t * device_found = lv_label_create(image);
    lv_label_set_recolor(device_found, true);
    lv_label_set_text(device_found, devices_found_info[which_device].menu_pre);
    lv_obj_set_style_text_color(device_found, lv_color_white(), 0);
    lv_obj_align(device_found, LV_ALIGN_TOP_MID, 0, 20);
    lv_obj_add_style(device_found, &header_style, LV_PART_MAIN);

        /* Add the item List heading*/
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_DEFAULT, 25, 85);
    lv_label_set_text(list_name, "Configuration");
    lv_obj_add_style(list_name, &header_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(list_name, lv_palette_main(LV_PALETTE_GREY), 0);

    entry_separator[0] = lv_img_create(image);
    lv_img_set_src(entry_separator[0], &Linez);
    lv_obj_align(entry_separator[0], LV_ALIGN_DEFAULT, 25, 130);

    lv_obj_t * email_label = lv_label_create(image);
    lv_label_set_recolor(email_label, true);
    lv_label_set_text(email_label, "Emails");
    lv_obj_set_style_text_color(email_label, lv_color_white(), 0);

    lv_obj_add_style(email_label, &security_selection_style, LV_PART_MAIN);
    lv_obj_align(email_label, LV_ALIGN_LEFT_MID, 50, -90);

    /*Create a switch to add 'Emails' to list of total-control */
    lv_obj_t * sw1 = lv_switch_create(image);
    lv_obj_align(sw1, LV_ALIGN_CENTER, 120, -90);
    lv_obj_set_size(sw1, 45, 25);
    lv_obj_set_style_opa(sw1, LV_OPA_20, 0);
    lv_obj_set_style_bg_color(sw1, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_style_border_color(sw1, lv_color_white(), 0);
    lv_obj_set_style_border_width(sw1, 1, 0);
    lv_obj_set_user_data(sw1, oserver_page);
    lv_obj_add_event_cb(sw1, switch_event_handler, LV_EVENT_ALL, NULL);

    entry_separator[1] = lv_img_create(image);
    lv_img_set_src(entry_separator[1], &Linez);
    lv_obj_align(entry_separator[1], LV_ALIGN_DEFAULT, 25, 205);

    lv_obj_t * contacts_label = lv_label_create(image);
    lv_label_set_recolor(contacts_label, true);
    lv_label_set_text(contacts_label, "Contacts");
    lv_obj_set_style_text_color(contacts_label, lv_color_white(), 0);
    lv_obj_add_style(contacts_label, &security_selection_style, LV_PART_MAIN);
    lv_obj_align(contacts_label, LV_ALIGN_LEFT_MID, 50, -10);

    /*Create a switch to add 'Contacts' to list of total-control */
    lv_obj_t * sw2 = lv_switch_create(image);
    lv_obj_align(sw2, LV_ALIGN_CENTER, 120, -15);
    lv_obj_set_size(sw2, 45, 25);
    lv_obj_set_style_opa(sw2, LV_OPA_20, 0);
    lv_obj_set_style_bg_color(sw2, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_style_bg_color(sw2, lv_color_lighten(lv_color_black(), 0), LV_PART_INDICATOR);
    
    lv_obj_set_style_border_color(sw2, lv_color_white(), 0);
    lv_obj_set_style_border_width(sw2, 1, 0);
    lv_obj_set_user_data(sw2, oserver_page);
    lv_obj_add_event_cb(sw2, switch_event_handler, LV_EVENT_ALL, NULL);

    entry_separator[2] = lv_img_create(image);
    lv_img_set_src(entry_separator[2], &Linez);
    lv_obj_align(entry_separator[2], LV_ALIGN_DEFAULT, 25, 280);

    lv_obj_t * text_label = lv_label_create(image);
    lv_label_set_recolor(text_label, true);
    lv_label_set_text(text_label, "Text");
    lv_obj_set_style_text_color(text_label, lv_color_white(), 0);
    lv_obj_add_style(text_label, &security_selection_style, LV_PART_MAIN);
    lv_obj_align(text_label, LV_ALIGN_LEFT_MID, 50, 70);

    /*Create a switch to add 'Text' to list of total-control */
    lv_obj_t * sw3 = lv_switch_create(image);
    lv_obj_align(sw3, LV_ALIGN_CENTER, 120, 66);
    lv_obj_set_size(sw3, 45, 25);
    lv_obj_set_style_opa(sw3, LV_OPA_20, 0);
    lv_obj_set_style_border_color(sw3, lv_color_lighten(lv_color_white(), 30), 0);
    lv_obj_set_style_border_width(sw3, 1, 0);
    lv_obj_set_user_data(sw3, oserver_page);
    lv_obj_add_event_cb(sw3, switch_event_handler, LV_EVENT_ALL, NULL);

    entry_separator[3] = lv_img_create(image);
    lv_img_set_src(entry_separator[3], &Linez);
    lv_obj_align(entry_separator[3], LV_ALIGN_DEFAULT, 25, 360);

    lv_obj_t * calendar_label = lv_label_create(image);
    lv_label_set_recolor(calendar_label, true);
    lv_label_set_text(calendar_label, "Calendar");
    lv_obj_set_style_text_color(calendar_label, lv_color_white(), 0);
    lv_obj_add_style(calendar_label, &security_selection_style, LV_PART_MAIN);
    lv_obj_align(calendar_label, LV_ALIGN_LEFT_MID, 50, 155);

    /*Create a switch to add 'Calendar' to list of total-control */
    lv_obj_t * sw4 = lv_switch_create(image);
    lv_obj_align(sw4, LV_ALIGN_CENTER, 120, 155);
    lv_obj_set_size(sw4, 45, 25);
    lv_obj_set_style_opa(sw4, LV_OPA_20, 0);
    lv_obj_set_style_border_color(sw4, lv_color_lighten(lv_color_white(), 90), LV_PART_KNOB);
    lv_obj_set_style_border_color(sw4, lv_color_lighten(lv_color_white(), 35), 0);
    lv_obj_set_style_border_width(sw4, 1, 0);
    lv_obj_set_user_data(sw4, oserver_page);
    lv_obj_add_event_cb(sw4, NULL, LV_EVENT_ALL, NULL);
}

void devices_connected_init(lv_obj_t * device_page) {

#if ALL_SCROLL
    lv_obj_t * image = lv_img_create(device_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(device_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);
#endif // ALL_SCROLL

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the Device items */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header using iconography at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &O_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the devices connected list heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, LIST_LEFT_ALIGNED, 108);
    lv_label_set_text(list_name, "Devices connected");
    lv_obj_set_style_text_color(list_name, lv_color_hex(MAIN_CONTENT_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line above the list item set
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 147);

    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;
    lv_obj_t * list_item_separator[DEVICE_PAGE_MAX];

    // Dan's items for list separator, etc
    lv_obj_t * entry_separator[DEVICE_PAGE_MAX];
    lv_obj_t * page_icon_list[DEVICE_PAGE_MAX];
    lv_obj_t * label_name[DEVICE_PAGE_MAX];
    lv_obj_t * security_status[DEVICE_PAGE_MAX];
    lv_obj_t * status_active_icon[DEVICE_PAGE_MAX];

    int page_index = 0;

#ifdef DAN_CODE
    static lv_style_t status_style;
    lv_style_init(&status_style);
    static lv_style_t name_style;
    lv_style_init(&name_style);
#endif // DAN_CODE

    /* Add (simulated) devices entries as clickable buttons*/
    for (int i = 0; i < DEVICE_PAGE_MAX; i++)
    {
        left.y = left.y + offset;
        right.y = right.y + offset;

        offset =  -64 + (92 * i);

        /* Using this to calculate if the DEVICE NAME field is greater than or equal to 23 characters */
        device_name_string = devices_active_info[i].menu_pre;
        device_name_count = strlen(device_name_string);

        /* Device icon image on the left */
        page_icon_list[i] = lv_img_create(image);
        lv_img_set_src(page_icon_list[i], devices_active_info[i].icon);
        lv_obj_align(page_icon_list[i], LV_ALIGN_CENTER, -140, offset);
#ifndef DAN_CODE
        /* Opaque button overlay of the device entry graphic */
        trusted_device_btn_list[i] = lv_btn_create(image);
        lv_obj_set_size(trusted_device_btn_list[i], 330, 70);
        lv_obj_align(trusted_device_btn_list[i], LV_ALIGN_CENTER, 0, offset);
        lv_obj_set_style_opa(trusted_device_btn_list[i], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(trusted_device_btn_list[i], device_selected_cb, LV_EVENT_CLICKED, 0);
#endif // DAN_CODE

        /* The label text with the device name */
        label_name[i] = lv_label_create(image);
        lv_label_set_recolor(label_name[i], true);

        /* Calculate and then truncate if the DEVICE NAME field is greater than or equal to 23 characters; then insert an ellipsis in place of the long string */
        if(device_name_count >= 23) {
            lv_label_set_text(label_name[i], devices_active_info[i].menu_pre);
            lv_label_cut_text(label_name[i],21,device_name_count);
            lv_label_ins_text(label_name[i],23,"...");
        } else {
            lv_label_set_text(label_name[i], devices_active_info[i].menu_pre);
        }

        lv_obj_align(label_name[i], LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset - LIST_ITEM_LINE_SPACING);
        lv_obj_set_style_text_color(label_name[i], lv_color_white(), 0);
        lv_obj_set_style_text_font(label_name[i], &NeueHaasDisplayLight_24, LV_PART_MAIN);

        /* The SECURITY STATUS text string */
        security_status[i] = lv_label_create(image);
        lv_label_set_recolor(security_status[i], true);
        lv_obj_align(security_status[i], LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset + LIST_ITEM_LINE_SPACING);
        lv_label_set_text(security_status[i], devices_active_info[i].security_status == ADMIN ? "Admin":"Friend");
        lv_obj_set_style_text_color(security_status[i], lv_color_hex(MAIN_CONTENT_COLOR), 0);
        lv_obj_set_style_text_font(security_status[i], &NeueHaasDisplayLight_24, LV_PART_MAIN);

        /* The DEVICE CONNECTION STATUS iconography */
        status_active_icon[i] = lv_img_create(image);
        lv_img_set_src(status_active_icon[i], devices_active_info[i].active ? &Icon_Status_Active: &Icon_Status_Disable);
        lv_obj_align(status_active_icon[i], LV_ALIGN_CENTER, 155, offset);

#ifdef DAN_CODE

        entry_separator[i] = lv_img_create(image);
        lv_img_set_src(entry_separator[i], &Linez);
        lv_obj_align(entry_separator[i], LV_ALIGN_DEFAULT, 25, offset);

        /* Device icon image on the left */
        page_icon_list[i] = lv_img_create(image);
        lv_img_set_src(page_icon_list[i], devices_active_info[i].icon);
        lv_obj_align(page_icon_list[i], LV_ALIGN_CENTER, -130, offset - 225);
        lv_obj_set_style_opa(page_icon_list[i], LV_OPA_70, LV_PART_MAIN);

        /*this is the opaque button overlay of the device entry graphic*/
        trusted_device_btn_list[i] = lv_btn_create(image);
        lv_obj_set_size(trusted_device_btn_list[i], 330, 50);
        lv_obj_align(trusted_device_btn_list[i], LV_ALIGN_CENTER, 0, offset - 225);
        lv_obj_set_style_opa(trusted_device_btn_list[i], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(trusted_device_btn_list[i], device_selected_cb, LV_EVENT_CLICKED, 0);

        /* The label text with the device name */
        label_name[i] = lv_label_create(image);
        lv_label_set_recolor(label_name[i], true);
        lv_obj_align(label_name[i], LV_ALIGN_DEFAULT, 120, offset - 10 + 25);
        lv_label_set_text(label_name[i], devices_active_info[i].menu_pre);
        lv_style_set_text_font(&name_style, &NeueHaasDisplayRoman_16);
        lv_obj_add_style(label_name[i], &name_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(label_name[i], lv_color_white(), 0);

        security_status[i] = lv_label_create(image);
        lv_label_set_recolor(security_status[i], true);
        lv_obj_align(security_status[i], LV_ALIGN_DEFAULT, 120, offset + 10 + 25);
        lv_label_set_text(security_status[i], devices_active_info[i].security_status == ADMIN ? "Admin":"Friend");
        lv_style_set_text_font(&status_style, &NeueHaasDisplayLight_16);
        lv_obj_add_style(security_status[i], &status_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(security_status[i], lv_palette_main(LV_PALETTE_GREY), 0);

        status_active_icon[i] = lv_img_create(image);
        lv_img_set_src(status_active_icon[i], devices_active_info[i].active ? &Icon_Status_Active: &Icon_Status_Disable);
        lv_obj_align(status_active_icon[i], LV_ALIGN_CENTER, 130, offset - 225);

#endif // DAN_CODE

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

void oserver_menu_setup(void) {

    printf("OSERVER MENU setup...\n");

#if ALL_SCROLL
    lv_obj_t * oserver_page = lv_obj_create(NULL);
    menu_dispatch_table[OSERVER_VEC] = oserver_page;

    lv_obj_center(oserver_page);
    lv_obj_set_style_bg_color(oserver_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(oserver_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(oserver_page, true, 3);
    lv_obj_set_scroll_dir(oserver_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(oserver_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(oserver_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* Store the content of this page for later display */

    /* SUB-SCREEN 0: Create already connected (trusted) devices page add it to parent */
    devices_connected_init(oserver_page);

    /* SUB-SCREEN 1: The items from the selected device to be transferred and secured with total-control */
    total_control_item_init(oserver_page);

    /* SUB-SCREEN 2: Once selected and started the total-control transfer progress is displayed by percent. */
    transfer_progress_init(oserver_page);
#else
    lv_obj_t * lotus_root_page = lv_img_create(NULL);
    menu_dispatch_table[OSERVER_VEC] = lotus_root_page;

    lv_obj_set_size(lotus_root_page, 385, 510); // Same as the simulator dislay
    lv_obj_set_style_bg_color(lotus_root_page, lv_color_lighten(lv_color_black(), 50), 0);
    lv_img_set_src(lotus_root_page, &Background);
    lv_obj_set_flex_flow(lotus_root_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_scroll_dir(lotus_root_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(lotus_root_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(lotus_root_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* Store the content of this page for later display */

    /* SUB-SCREEN 0: Create already connected (trusted) devices page add it to parent */
    devices_connected_init(lotus_root_page);

    /* SUB-SCREEN 1: The items from the selected device to be transferred and secured with total-control */
    total_control_item_init(lotus_root_page);

    /* SUB-SCREEN 2: Once selected and started the total-control transfer progress is displayed by percent. */
    transfer_progress_init(lotus_root_page);
#endif // ALL_SCROLL
    
}
