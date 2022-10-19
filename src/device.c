#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

#define DEVICE_PAGE_MAX 6
#define DEVICE_FOUND_MAX 4

/*forward*/
static void add_device_cb(lv_event_t *);
static void my_timer(lv_timer_t *);

/* global static */
static lv_obj_t * trusted_device_list[DEVICE_PAGE_MAX];
static lv_obj_t * device_found[DEVICE_FOUND_MAX];
static lv_obj_t * trusted_device_btn_list[DEVICE_PAGE_MAX];
static lv_timer_t * sleeptimer;

static menu_item devices_active_info[DEVICE_PAGE_MAX] = {
    {.menu_pre = "Kevin's iPhone",   .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_iPhone},
    {.menu_pre = "Mark's iPad",      .active = true,  .onboard = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_pre = "Alice's Macbook",  .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_MacBook},
    {.menu_pre = "Ted's iPad",       .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_iPad},
    {.menu_pre = "Office iPad",      .active = true,  .onboard = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_pre = "Mary's iPhone",    .active = false, .onboard = true,  .security_status = FRIEND, .icon = &Icon_iPhone},
};

static menu_item devices_found_info[DEVICE_FOUND_MAX] = {
    {.menu_pre = "Bob's iPhone",   .active = false, .security_status = FRIEND, .icon = &Icon_iPhone},
    {.menu_pre = "Bob's iPad",     .active = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_pre = "Bob's Macbook",  .active = false, .security_status = FRIEND, .icon = &Icon_MacBook},
    {.menu_pre = "Orna's iPad",    .active = false, .security_status = FRIEND, .icon = &Icon_iPad},
};

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

    /* After an amount of time to simulate entering the code on
     * candidate device - scroll to or display the device
     */
    sleeptimer = lv_timer_create(my_timer, 3500, device_page);
    lv_timer_set_repeat_count(sleeptimer, 1);
}

static void device_selected_cb(lv_event_t * e) { printf("Selected device...\n"); }

static void display_connected_device(lv_obj_t * cont, int which_device) {
	printf ("devices %d connected\n", which_device);
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
    /*
     * This adds the 'connected device' screen to the devices scroll list
     */
    lv_obj_t * image = lv_img_create(device_page);
    lv_img_set_src(image, &Background);

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

/* When a device is selected to be enquire about a trust relationship, this code page displays */
void device_code_init(lv_obj_t * device_page)
{
    static lv_style_t cancel_style;
    lv_style_init(&cancel_style);
    lv_style_set_text_font(&cancel_style, &NeueHaasDisplayLight_16);

    /*
     * This adds the 'devices found' screen to the devices scroll list
     */
    lv_obj_t * image = lv_img_create(device_page);
    lv_img_set_src(image, &Background);

    render_back_button(image, back_button_cb);

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
    static lv_style_t code_style;
    lv_style_init(&code_style);
    lv_obj_t * code = lv_label_create(image);
    lv_label_set_recolor(code, true);
    lv_style_set_text_font(&code_style, &NeueHaasDisplayXThin_100);
    lv_label_set_text(code, "603537");
    lv_obj_set_style_text_color(code, lv_palette_main(LV_PALETTE_GREY), 0);
    lv_obj_add_style(code, &code_style, LV_PART_MAIN);
    lv_obj_align(code, LV_ALIGN_DEFAULT, 100, 200);
    
    /* Tell them what to do with the displayed code */
    lv_obj_t * instructions = lv_label_create(image);
    lv_label_set_recolor(instructions, true);
    lv_label_set_text(instructions, "Enter this code\n on your device");
    lv_obj_set_style_text_color(instructions, lv_palette_main(LV_PALETTE_GREY), 0);
    lv_obj_align(instructions, LV_ALIGN_DEFAULT, 140, 290);

    render_back_button(image, back_button_cb);
}

/* After selecting the '+' (add device) button on the devices page list more devices in the area */
void devices_found_init(lv_obj_t * device_page) {

    /*
     * This adds the 'devices found' screen to the devices scroll list
     */
    lv_obj_t * image = lv_img_create(device_page);
    lv_img_set_src(image, &Background);

    render_back_button(image, back_button_cb);

    static lv_style_t page_header_style;
    lv_style_init(&page_header_style);
    lv_style_set_text_font(&page_header_style, &NeueHaasDisplayLight_18);

    /* Add the Page header at the top*/
    lv_label_t * page_header = lv_label_create(image);
    lv_label_set_recolor(page_header, true);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 24);
    lv_obj_add_style(page_header, &page_header_style, LV_PART_MAIN);
    lv_label_set_text(page_header, "Devices");
    lv_obj_set_style_text_color(page_header, lv_color_white(), 0);

    /* Add the item List heading*/
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_DEFAULT, 25, 85);
    lv_label_set_text(list_name, "List of devices found");
    lv_obj_set_style_text_color(list_name, lv_palette_main(LV_PALETTE_GREY), 0);

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

    lv_obj_t * image = lv_img_create(device_page);
    lv_img_set_src(image, &Background);

    render_back_button(image, back_home_button_cb);

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
    lv_label_t * page_header = lv_label_create(image);
    lv_label_set_recolor(page_header, true);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 23);
    lv_obj_add_style(page_header, &page_header_style, LV_PART_MAIN);
    lv_label_set_text(page_header, "Devices");
    lv_obj_set_style_text_color(page_header, lv_color_white(), 0);

    /* Add the item List heading */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, 25, 85);
    lv_label_set_text(list_name, "List of devices");
    lv_obj_set_style_text_color(list_name, lv_palette_main(LV_PALETTE_GREY), 0);

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
    int page_index = 0;
    static lv_style_t status_style;
    lv_style_init(&status_style);
    static lv_style_t name_style;
    lv_style_init(&name_style);

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
    printf("DEVICE MENU init...\n");

    lv_obj_t * device_page = lv_obj_create(NULL);
    menu_dispatch_table[DEVICE_VEC] = device_page;

    lv_obj_center(device_page);
    lv_obj_set_style_bg_color(device_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(device_page, LV_FLEX_FLOW_ROW);
    //lv_obj_add_event_cb(device_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
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
}
