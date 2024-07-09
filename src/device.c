#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>
#include <stdlib.h>

/* Main HEADING iconography */
LV_IMG_DECLARE(Devices_App_Heading_Title);

/* forward */
static void add_device_cb(lv_event_t *);
static void my_timer(lv_timer_t *);
static void pin_timer(lv_timer_t *);

/* global static */
static lv_timer_t * pause_before_onboard;
static lv_timer_t * pause_before_set_pins;

static lv_obj_t * roller_digits[5];  // GLOBAL alert

static menu_item devices_active_info[] = {
    {.menu_pre = "Kevin's iPhone",   .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_iPhone},
    {.menu_pre = "Mark's iPad",      .active = true,  .onboard = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_pre = "Alice's Macbook",  .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_MacBook},
    {.menu_pre = "Ted's iPad",       .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_iPad},
    {.menu_pre = "Office iPad",      .active = true,  .onboard = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_pre = "Mary's iPhone",    .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_iPhone},
};
static const int DEVICE_PAGE_MAX = sizeof(devices_active_info) / sizeof(menu_item);

static menu_item devices_found_info[] = {
    {.menu_pre = "Bob's iPhone",   .active = false, .security_status = FRIEND, .icon = &Icon_iPhone},
    {.menu_pre = "Bob's iPad",     .active = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_pre = "Bob's Macbook",  .active = false, .security_status = FRIEND, .icon = &Icon_MacBook},
    {.menu_pre = "Orna's iPad",    .active = false, .security_status = FRIEND, .icon = &Icon_iPad},
};
static const int DEVICE_FOUND_MAX = sizeof(devices_found_info) / sizeof(menu_item);

static void add_device_cb(lv_event_t * e) {

    printf("Adding device...\n");
    /*
     * Scroll to the page with the devices seen in the local area
     * This is where we add "Bob's Macbook" as "Friend".
     */
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * device_page = lv_obj_get_user_data(target);
    lv_obj_scroll_to_view(lv_obj_get_child(device_page, 1), LV_ANIM_ON);
}

static void enter_code_handler(lv_event_t * e) {
    /*
     * Scroll to the page with the 'code' to enter on the candidate device (Bob's MacBook).
     */
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * device_page = lv_obj_get_user_data(target);
    lv_obj_scroll_to_view(lv_obj_get_child(device_page, 2), LV_ANIM_ON);

    /*
     * Short delay and fill in a set of PIN numbers
     */
    pause_before_set_pins = lv_timer_create(pin_timer, 1000, roller_digits);
    lv_timer_set_repeat_count(pause_before_set_pins, 1);

    /*
     * After an amount of time to simulate entering the code on
     * candidate device - scroll to or display the device
     */
    pause_before_onboard = lv_timer_create(my_timer, 7000, device_page);
    lv_timer_set_repeat_count(pause_before_onboard, 1);
}

static void device_selected_cb(lv_event_t * e __attribute__((unused))) { printf("Selected device...\n"); }

static void display_connected_device(lv_obj_t * cont __attribute__((unused)), int which_device) {
	printf ("devices %d connected\n", which_device);
}

static void display_new_pin(lv_obj_t * array_of_rollers[]) {
    // NOTE: digits is a five (5) digit array of numbers going to display '94689'
     lv_roller_set_selected(array_of_rollers[0], 8, LV_ANIM_ON);
     lv_roller_set_selected(array_of_rollers[1], 3, LV_ANIM_ON);
     lv_roller_set_selected(array_of_rollers[2], 5, LV_ANIM_ON);
     lv_roller_set_selected(array_of_rollers[3], 7, LV_ANIM_ON);
     lv_roller_set_selected(array_of_rollers[4], 9, LV_ANIM_ON);
}

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        LV_LOG_USER("Selected value: %s", buf);
    }
}

/* Set up the screen that shows the new trusted device connected */
void device_connected_init(lv_obj_t * device_page) {

    int which_device = 2; // Meanwhile, for the show, magic
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
    lv_obj_t * image = lv_img_create(device_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(device_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);

#endif // ALL_SCROLL
    render_back_button(image, (back_button_cb_t)back_button_cb);

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

    lv_obj_t * device_icon = lv_img_create(image);
    lv_img_set_src(device_icon, devices_found_info[which_device].icon);
    lv_obj_set_style_opa(device_icon, LV_OPA_80, LV_PART_MAIN);
    lv_obj_align(device_icon, LV_ALIGN_TOP_MID, 0, 70);

    lv_obj_t * device_found = lv_label_create(image);
    lv_label_set_recolor(device_found, true);
    lv_label_set_text(device_found, devices_found_info[which_device].menu_pre);
    lv_obj_set_style_text_color(device_found, lv_color_white(), 0);
    lv_obj_align(device_found, LV_ALIGN_TOP_MID, 0, 120);
    lv_obj_add_style(device_found, &header_style, LV_PART_MAIN);

    lv_obj_t * connected_label = lv_label_create(image);
    lv_label_set_recolor(connected_label, true);
    lv_label_set_text(connected_label, "Connected");
    lv_obj_set_style_text_color(connected_label, lv_color_white(), 0);
    lv_obj_align(connected_label, LV_ALIGN_TOP_MID, 0, 140);
    lv_obj_add_style(connected_label, &header_style, LV_PART_MAIN);

    entry_separator[0] = lv_img_create(image);
    lv_img_set_src(entry_separator[0], &Linez);
    lv_obj_align(entry_separator[0], LV_ALIGN_DEFAULT, 25, 180);

    lv_obj_t * admin_label = lv_label_create(image);
    lv_label_set_recolor(admin_label, true);
    lv_label_set_text(admin_label, "Administrator");
    lv_obj_set_style_text_color(admin_label, lv_color_white(), 0);

    lv_obj_add_style(admin_label, &security_selection_style, LV_PART_MAIN);
    lv_obj_align(admin_label, LV_ALIGN_LEFT_MID, 50, -40);

    lv_obj_t * next_icon_admin = lv_img_create(image);
    lv_img_set_src(next_icon_admin, &Icon_Next_White);
    lv_obj_align(next_icon_admin, LV_ALIGN_CENTER, 130, -35);
    lv_obj_set_style_opa(next_icon_admin, LV_OPA_70, LV_PART_MAIN);

    entry_separator[1] = lv_img_create(image);
    lv_img_set_src(entry_separator[1], &Linez);
    lv_obj_align(entry_separator[1], LV_ALIGN_DEFAULT, 25, 255);

    lv_obj_t * friend_label = lv_label_create(image);
    lv_label_set_recolor(friend_label, true);
    lv_label_set_text(friend_label, "Friend");
    lv_obj_set_style_text_color(friend_label, lv_color_white(), 0);
    lv_obj_add_style(friend_label, &security_selection_style, LV_PART_MAIN);
    lv_obj_align(friend_label, LV_ALIGN_LEFT_MID, 50, 40);

    lv_obj_t * next_icon_friend = lv_img_create(image);
    lv_img_set_src(next_icon_friend, &Icon_Next_White);
    lv_obj_align(next_icon_friend, LV_ALIGN_CENTER, 130, 35);
    lv_obj_set_style_opa(next_icon_friend, LV_OPA_70, LV_PART_MAIN);

    entry_separator[2] = lv_img_create(image);
    lv_img_set_src(entry_separator[2], &Linez);
    lv_obj_align(entry_separator[2], LV_ALIGN_DEFAULT, 25, 330);

    lv_obj_t * invite_label = lv_label_create(image);
    lv_label_set_recolor(invite_label, true);
    lv_label_set_text(invite_label, "Invite");
    lv_obj_set_style_text_color(invite_label, lv_color_white(), 0);
    lv_obj_add_style(invite_label, &security_selection_style, LV_PART_MAIN);
    lv_obj_align(invite_label, LV_ALIGN_LEFT_MID, 50, 120);

    lv_obj_t * next_icon_invite = lv_img_create(image);
    lv_img_set_src(next_icon_invite, &Icon_Next_White);
    lv_obj_align(next_icon_invite, LV_ALIGN_CENTER, 130, 110);
    lv_obj_set_style_opa(next_icon_invite, LV_OPA_70, LV_PART_MAIN);

    entry_separator[3] = lv_img_create(image);
    lv_img_set_src(entry_separator[3], &Linez);
    lv_obj_align(entry_separator[3], LV_ALIGN_DEFAULT, 25, 410);
}

// Simulate person entering the code on candidate device - gives a delay
static void my_timer(lv_timer_t * timer) {
    /* User data is the previous event that got the code here */
    lv_obj_t * device_page = timer->user_data;
    lv_obj_scroll_to_view(lv_obj_get_child(device_page, 3), LV_ANIM_ON);
    display_connected_device(device_page, 2);
}

// Simulate person entering the code on candidate device - gives a delay
static void pin_timer(lv_timer_t * timer) {
    /* User data is the previous event that got the code here */
    lv_obj_t ** roller_array = timer->user_data;
    display_new_pin(roller_array);
}

/* When a device is selected to be enquire about a trust relationship, this code page displays */
void device_code_init(lv_obj_t * device_page)
{
    static lv_style_t cancel_style;
    lv_style_init(&cancel_style);
    lv_style_set_text_font(&cancel_style, &NeueHaasDisplayLight_16);

#if ALL_SCROLL
    lv_obj_t * image = lv_img_create(device_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(device_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);

#endif // ALL_SCROLL
    render_back_button(image, (back_button_cb_t)back_button_cb);

    /* 'Cancel' button to cancel the security challenge process*/
    lv_obj_t * cancel = lv_label_create(image);
    lv_label_set_recolor(cancel, true);
    lv_label_set_text(cancel, "Cancel");
    lv_obj_set_style_text_color(cancel, lv_color_white(), 0);
    lv_obj_align(cancel, LV_ALIGN_DEFAULT, 300, 25);
    lv_obj_add_style(cancel, &cancel_style, LV_PART_MAIN);

    /* 'Return' (back) button to previous button */
    lv_obj_t * cancel_button = lv_btn_create(image);
    lv_obj_set_size(cancel_button, 70, 30);
    lv_obj_align(cancel_button, LV_ALIGN_DEFAULT, 290, 20);
    lv_obj_add_event_cb(cancel_button, back_home_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(cancel_button, lv_obj_get_parent(image));
    lv_obj_set_style_opa(cancel_button, LV_OPA_0, LV_PART_MAIN);

    /* Display the code */

    /*A style to make the selected option larger*/
    static lv_style_t style_sel;
    lv_style_init(&style_sel);
    lv_style_set_text_font(&style_sel, &NeueHaasDisplayXXThin_100);
    lv_style_set_anim_time(&style_sel, 1000);

    lv_style_set_bg_opa(&style_sel, LV_OPA_TRANSP);

    const char * opts = "1\n2\n3\n4\n5\n6\n7\n8\n9\n0";

    // NOTE: roller[1-5] are global values in this source module
    roller_digits[0] = lv_roller_create(image);
    lv_obj_set_style_bg_opa(roller_digits[0], LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(roller_digits[0], 0, 0);
    lv_obj_set_style_text_color(roller_digits[0], lv_color_white(), 0);
    lv_obj_set_size(roller_digits[0], lv_pct(18), LV_SIZE_CONTENT);

    lv_roller_set_options(roller_digits[0], opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller_digits[0], 3);
    lv_obj_add_style(roller_digits[0], &style_sel, LV_PART_MAIN);
    lv_obj_align(roller_digits[0], LV_ALIGN_CENTER, -110, 0);
    lv_obj_add_event_cb(roller_digits[0], event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(roller_digits[0], 9, LV_ANIM_ON);

    /*A roller on the left with left aligned text, and custom width*/
    roller_digits[1] = lv_roller_create(image);
    lv_obj_set_style_bg_opa(roller_digits[1], LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(roller_digits[1], 0, 0);
    lv_obj_set_style_text_color(roller_digits[1], lv_color_white(), 0);
    lv_obj_set_size(roller_digits[1], lv_pct(18), LV_SIZE_CONTENT);

    lv_roller_set_options(roller_digits[1], opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller_digits[1], 3);
    lv_obj_add_style(roller_digits[1], &style_sel, LV_PART_MAIN);
    lv_obj_align(roller_digits[1], LV_ALIGN_CENTER, -55, 0);
    lv_obj_add_event_cb(roller_digits[1], event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(roller_digits[1], 9, LV_ANIM_ON);

    /*A roller on the middle with center aligned text, and auto (default) width*/
    roller_digits[2] = lv_roller_create(image);
    lv_obj_set_style_bg_opa(roller_digits[2], LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(roller_digits[2], 0, 0);
    lv_obj_set_style_text_color(roller_digits[2], lv_color_white(), 0);
    lv_obj_set_size(roller_digits[2], lv_pct(18), LV_SIZE_CONTENT);

    lv_roller_set_options(roller_digits[2], opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller_digits[2], 3);
    lv_obj_add_style(roller_digits[2], &style_sel, LV_PART_MAIN);
    lv_obj_align(roller_digits[2], LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(roller_digits[2], event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(roller_digits[2], 9, LV_ANIM_ON);

    /*A roller on the right with right aligned text, and custom width*/
    roller_digits[3] = lv_roller_create(image);
    lv_obj_set_style_bg_opa(roller_digits[3], LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(roller_digits[3], 0, 0);
    lv_obj_set_style_text_color(roller_digits[3], lv_color_white(), 0);
    lv_obj_set_size(roller_digits[3], lv_pct(18), LV_SIZE_CONTENT);

    lv_roller_set_options(roller_digits[3], opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller_digits[3], 3);
    lv_obj_add_style(roller_digits[3], &style_sel, LV_PART_MAIN);
    lv_obj_align(roller_digits[3], LV_ALIGN_CENTER, 55, 0);
    lv_obj_add_event_cb(roller_digits[3], event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(roller_digits[3], 9, LV_ANIM_ON);

    roller_digits[4] = lv_roller_create(image);
    lv_obj_set_style_bg_opa(roller_digits[4], LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_border_width(roller_digits[4], 0, 0);
    lv_obj_set_style_text_color(roller_digits[4], lv_color_white(), 0);
    lv_obj_set_size(roller_digits[4], lv_pct(18), LV_SIZE_CONTENT);

    lv_roller_set_options(roller_digits[4], opts, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller_digits[4], 3);
    lv_obj_add_style(roller_digits[4], &style_sel, LV_PART_MAIN);
    lv_obj_align(roller_digits[4], LV_ALIGN_CENTER, 110, 0);
    lv_obj_add_event_cb(roller_digits[4], event_handler, LV_EVENT_ALL, NULL);
    lv_roller_set_selected(roller_digits[4], 9, LV_ANIM_ON);

    /* Tell them what to do with the displayed code */
    lv_obj_t * instructions = lv_label_create(image);
    lv_label_set_recolor(instructions, true);
    lv_label_set_text(instructions, "Enter this code\n on your device");
    lv_obj_set_style_text_color(instructions, lv_palette_main(LV_PALETTE_GREY), 0);
    lv_obj_align(instructions, LV_ALIGN_DEFAULT, 140, 300);

    render_back_button(image, (back_button_cb_t)back_button_cb);
}

/* After selecting the '+' (add device) button on the devices page list more devices in the area */
void devices_found_init(lv_obj_t * device_page) {

#if ALL_SCROLL
    lv_obj_t * image = lv_img_create(device_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(device_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);

#endif // ALL_SCROLL
    render_back_button(image, (back_button_cb_t)back_button_cb);

    static lv_style_t page_header_style;
    lv_style_init(&page_header_style);
    lv_style_set_text_font(&page_header_style, &NeueHaasDisplayLight_18);

    /* Add the Page header at the top*/
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Devices_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the item List heading*/
    lv_obj_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_DEFAULT, 25, 85);
    lv_label_set_text(list_name, "List of devices found");
    lv_obj_set_style_text_color(list_name, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);

    lv_coord_t offset = 0;
    lv_obj_t * entry_separator[DEVICE_PAGE_MAX];
    lv_obj_t * device_icon[DEVICE_FOUND_MAX];
    lv_obj_t * found_btn[DEVICE_FOUND_MAX];
    lv_obj_t * found_label[DEVICE_FOUND_MAX];
    lv_obj_t * next_icon[DEVICE_FOUND_MAX];

    static lv_style_t name_style;
    lv_style_init(&name_style);
    /* Add devices entries as clickable buttons*/
    for (int i = 0; i < DEVICE_FOUND_MAX; i++)
    {
        offset =  121 + (60 * i);
        entry_separator[i] = lv_img_create(image);
        lv_img_set_src(entry_separator[i], &Linez);
        lv_obj_align(entry_separator[i], LV_ALIGN_DEFAULT, 25, offset);

        /* Device icon image on the left */
        device_icon[i] = lv_img_create(image);
        lv_img_set_src(device_icon[i], devices_found_info[i].icon);
        lv_obj_align(device_icon[i], LV_ALIGN_CENTER, -130, offset - 225);
        lv_obj_set_style_opa(device_icon[i], LV_OPA_70, LV_PART_MAIN);

        /*this is the opaque button overlay of the device entry graphic*/
        found_btn[i] = lv_btn_create(image);
        lv_obj_set_size(found_btn[i], 330, 50);
        lv_obj_align(found_btn[i], LV_ALIGN_CENTER, 0, offset - 225);
        lv_obj_set_style_opa(found_btn[i], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(found_btn[i], enter_code_handler, LV_EVENT_CLICKED, 0);
        lv_obj_set_user_data(found_btn[i], device_page);

        /* The label text with the device name */
        found_label[i] = lv_label_create(image);
        lv_label_set_recolor(found_label[i], true);
        lv_obj_align(found_label[i], LV_ALIGN_LEFT_MID, 125, offset - 225);
        lv_label_set_text(found_label[i], devices_found_info[i].menu_pre);
        lv_style_set_text_font(&name_style, &NeueHaasDisplayRoman_16);
        lv_obj_add_style(found_label[i], &name_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(found_label[i], lv_color_white(), 0);

        next_icon[i] = lv_img_create(image);
        lv_img_set_src(next_icon[i], &Icon_Next_White);
        lv_obj_align(next_icon[i], LV_ALIGN_CENTER, 130, offset - 225);
        lv_obj_set_style_opa(next_icon[i], LV_OPA_70, LV_PART_MAIN);
    }
}

void device_trusted_init(lv_obj_t * device_page) {

#if ALL_SCROLL
    lv_obj_t * image = lv_img_create(device_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(device_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);

#endif // ALL_SCROLL
    render_back_button(image, (back_button_cb_t)back_home_button_cb);

    static lv_style_t page_header_style;
    lv_style_init(&page_header_style);
    lv_style_set_text_font(&page_header_style, &NeueHaasDisplayRoman_20);

    lv_obj_t * grey_halo = lv_img_create(image);
    lv_img_set_src(grey_halo, &GreyHalo);
    lv_img_set_zoom(grey_halo, 200);
    lv_obj_align(grey_halo, LV_ALIGN_TOP_MID, 130, 9);

    lv_obj_t * add = lv_btn_create(image);
    lv_obj_set_size(add, 50, 50);
    lv_obj_align(add, LV_ALIGN_TOP_MID, 140, 15);
    lv_obj_add_event_cb(add, add_device_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(add, device_page);
    lv_obj_set_style_opa(add, LV_OPA_0, LV_PART_MAIN);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Devices_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the item List heading */
    lv_obj_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, 25, 85);
    lv_label_set_text(list_name, "List of devices");
    lv_obj_set_style_text_color(list_name, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);

    /* The WiFi indicator */
    lv_obj_t * wifi_symbol = lv_img_create(image);
    lv_img_set_src(wifi_symbol, &Icon_WiFi_White);
    lv_obj_align(wifi_symbol, LV_ALIGN_DEFAULT, 290, 64);

    /* The Bluetooth indicator */
    lv_obj_t * bt_symbol = lv_img_create(image);
    lv_img_set_src(bt_symbol, &Icon_Bluetooth_White);
    lv_obj_align(bt_symbol, LV_ALIGN_DEFAULT, 310, 64);

    /* The NFC indicator */
    lv_obj_t * nfc_symbol = lv_img_create(image);
    lv_img_set_src(nfc_symbol, &Icon_NFC_White);
    lv_obj_align(nfc_symbol, LV_ALIGN_DEFAULT, 330, 64);
    lv_obj_set_style_opa(nfc_symbol, LV_OPA_40, LV_PART_MAIN);

    lv_coord_t offset = 0;
    lv_obj_t * entry_separator[DEVICE_PAGE_MAX];
    lv_obj_t * page_icon_list[DEVICE_PAGE_MAX];
    lv_obj_t * label_name[DEVICE_PAGE_MAX];
    lv_obj_t * security_status[DEVICE_PAGE_MAX];
    lv_obj_t * status_active_icon[DEVICE_PAGE_MAX];
    // int page_index = 0;
    static lv_style_t status_style;
    lv_style_init(&status_style);
    static lv_style_t name_style;
    lv_style_init(&name_style);

    lv_obj_t **trusted_device_btn_list = calloc(DEVICE_PAGE_MAX, sizeof(lv_obj_t *));

    /* Add (simulated) devices entries as clickable buttons*/
    for (int i = 0; i < DEVICE_PAGE_MAX; i++)
    {
            offset =  121 + (60 * i);

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
    }
}

/* The init routine for` the 'root' page and it's children pages */
void device_menu_setup(void)
{
    printf("DEVICE MENU setup...\n");
#if ALL_SCROLL
    lv_obj_t * device_page = lv_obj_create(NULL);
    menu_dispatch_table[DEVICE_VEC] = device_page;

    lv_obj_center(device_page);
    lv_obj_set_style_bg_color(device_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(device_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(device_page, true, 3);
    lv_obj_set_scroll_dir(device_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(device_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(device_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* Store the content of this page for later display */

    /* SUB-SCREEN 0: Create already connected (trusted) devices page add it to parent */
    device_trusted_init(device_page);

    /* SUB-SCREEN 1: Devices found in the area listed here */
    devices_found_init(device_page);

    /* SUB-SCREEN 2: Display code for connection to selected device */
    device_code_init(device_page);

    /* SUB_SCREEN 3: Setup display for the new 'trusted' device */
    device_connected_init(device_page);
#else
    lv_obj_t * lotus_root_page = lv_img_create(NULL);
    menu_dispatch_table[DEVICE_VEC] = lotus_root_page;

    lv_obj_set_size(lotus_root_page, 385, 510); // Same as the simulator dislay
    lv_obj_set_style_bg_color(lotus_root_page, lv_color_lighten(lv_color_black(), 50), 0);
    lv_img_set_src(lotus_root_page, &Background);
    lv_obj_set_flex_flow(lotus_root_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_scroll_dir(lotus_root_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(lotus_root_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(lotus_root_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* Store the content of this page for later display */

    /* SUB-SCREEN 1: Create already connected (trusted) devices page add it to parent */
    device_trusted_init(lotus_root_page);

    /* SUB-SCREEN 2: Devices found in the area listed here */
    devices_found_init(lotus_root_page);

    /* SUB-SCREEN 3: Display code for connection to selected device */
    device_code_init(lotus_root_page);

    /* SUB_SCREEN 4: Setup display for the new 'trusted' device */
    device_connected_init(lotus_root_page);
#endif // ALL_SCROLL
}
