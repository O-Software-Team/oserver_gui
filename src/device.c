#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"

#include <stdio.h>

#define DEVICE_PAGE_MAX 6
#define DEVICE_FOUND_MAX 4

#define LV_FONT_MONTSERRAT_44 1

#define FONT_SIZE_WORKS 0 // Until it's figured out

/* Include image resources */
LV_IMG_DECLARE(Background);
LV_IMG_DECLARE(Icon_Status_Active);
LV_IMG_DECLARE(Icon_Status_Disable);
LV_IMG_DECLARE(Icon_iPad);
LV_IMG_DECLARE(Icon_MacBook);
LV_IMG_DECLARE(Icon_iPhone);
LV_IMG_DECLARE(Icon_WiFi_White);
LV_IMG_DECLARE(Icon_Bluetooth_White);
LV_IMG_DECLARE(Icon_NFC_White);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Time);

LV_FONT_DECLARE(lv_font_montserrat_44);

/*forward*/
static void add_device_cb(lv_event_t *);
void add_separator_line(lv_point_t, lv_point_t, lv_obj_t *);

/* global static */
static lv_obj_t * device_index[DEVICE_PAGE_MAX];
static lv_obj_t * device_found[DEVICE_FOUND_MAX];

static lv_obj_t * device_btn[DEVICE_PAGE_MAX];
static lv_obj_t * found_btn[DEVICE_FOUND_MAX];

static menu_item devices_active_info[DEVICE_PAGE_MAX] = {
    {.menu_name = "Kevin's iPhone",   .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPhone},
    {.menu_name = "Mark's iPad",      .page_handler = &add_device_cb,  .active = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_name = "Alice's Macbook",  .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_MacBook},
    {.menu_name = "Ted's iPad",       .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPad},
    {.menu_name = "Office iPad",      .page_handler = &add_device_cb,  .active = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_name = "Mary's iPhone",    .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPhone},
};

static menu_item devices_found_info[DEVICE_FOUND_MAX] = {
    {.menu_name = "Bob's iPhone",   .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPhone},
    {.menu_name = "Bob's iPad",     .page_handler = &add_device_cb,  .active = true,  .security_status = ADMIN,  .icon = &Icon_iPad},
    {.menu_name = "Bob's Macbook",  .page_handler = &add_device_cb, .active = false, .security_status = FRIEND,  .icon = &Icon_MacBook},
    {.menu_name = "Orna's iPad",    .page_handler = &add_device_cb,  .active = false, .security_status = FRIEND, .icon = &Icon_iPad},
};

lv_label_t * label;
lv_label_t * security_status;
lv_label_t * label_index;

extern enum device_menu_vector_index;
extern lv_obj_t * device_menu_vectors[];

static void add_device_cb(lv_event_t * e) { printf("Adding device...\n"); }

static void device_selected_cb(lv_event_t * e) { printf("Selected device...\n"); }

/* Generic routine to render a pixel wide horizontal line between two porint */
void add_separator_line(lv_point_t beginning, lv_point_t end, lv_obj_t * parent)
{
    static lv_point_t line_points[2];

    /*Create an array for the points of the line*/
    line_points[0] = beginning;
    line_points[1] = end;

    /*Create style*/
    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 1);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_line_rounded(&style_line, true);

    /*Create a line and apply the new style*/
    lv_obj_t * line1;
    line1 = lv_line_create(parent);
    /* These magic numbers add lines on each device entry in the 'right' place */
    //static lv_point_t line_points[] = { {-30, 25}, {280, 25}};
    lv_line_set_points(line1, line_points, 2);     /*Set the points*/
    lv_obj_add_style(line1, &style_line, 0);
    lv_obj_set_style_opa(line1, LV_OPA_40, 0);
    lv_obj_align(line1, LV_ALIGN_TOP_LEFT, 0, 0);
}

/* After entering the code into the device this page displays */
static void device_connected(lv_obj_t * cont, int which_device)
{
    printf ("Device connected...\n");
    // lv_obj_t * target = lv_event_get_target(e);
    // lv_obj_t * cont = lv_obj_create(lv_obj_get_user_data(target));
    lv_obj_t * image = lv_img_create(cont);

    lv_obj_set_size(image, OCO_CANVAS_WIDTH, OCO_CANVAS_HEIGHT);
    lv_obj_center(image);
    lv_obj_set_scroll_dir(image, LV_DIR_VER);
    lv_obj_set_scrollbar_mode(image, LV_SCROLLBAR_MODE_OFF);
    lv_obj_align(image, LV_ALIGN_DEFAULT, 0, 0);

    lv_img_set_src(image, &Background);
    lv_obj_fade_in(image, 1000, 0);

    /* 'Cancel' button to cancel the security challenge process*/
    lv_obj_t * cancel = lv_label_create(image);
    lv_label_set_recolor(cancel, true);
    lv_label_set_text(cancel, "Cancel");
    lv_obj_set_style_text_color(cancel, lv_color_white(), 0);
    lv_obj_align(cancel, LV_ALIGN_DEFAULT, 230, -4);

    /* 'Return' (back) button to previous button */
    lv_obj_t * cancel_button = lv_btn_create(image);
    lv_obj_set_size(cancel_button, 50, 50);
    lv_obj_align(cancel_button, LV_ALIGN_DEFAULT, 230, -4);
    lv_obj_add_event_cb(cancel_button, back_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(cancel_button, image);
    lv_obj_set_style_opa(cancel_button, LV_OPA_0, LV_PART_MAIN);

    render_back_button(image, back_button_cb);

    lv_obj_t * device_icon = lv_img_create(image);
    lv_img_set_src(device_icon, devices_found_info[which_device].icon);
    lv_obj_set_style_opa(device_icon, LV_OPA_70, LV_PART_MAIN);
    lv_obj_align(device_icon, LV_ALIGN_DEFAULT, 135, 30);

    lv_obj_t * device_found = lv_label_create(image);
    lv_label_set_recolor(device_found, true);
    lv_label_set_text(device_found, devices_found_info[which_device].menu_name);
    lv_obj_set_style_text_color(device_found, lv_color_white(), 0);
    lv_obj_align(device_found, LV_ALIGN_DEFAULT, 110, 90);

    lv_obj_t * connected_label = lv_label_create(image);
    lv_label_set_recolor(connected_label, true);
    lv_label_set_text(connected_label, "Connected");
    lv_obj_set_style_text_color(connected_label, lv_color_white(), 0);
    lv_obj_align(connected_label, LV_ALIGN_DEFAULT, 110, 110);

    lv_obj_t * admin_label = lv_label_create(image);
    lv_label_set_recolor(admin_label, true);
    lv_label_set_text(admin_label, "Administrator");
    lv_obj_set_style_text_color(admin_label, lv_color_white(), 0);
    lv_obj_align(admin_label, LV_ALIGN_DEFAULT, 10, 180);

    lv_obj_t * friend_label = lv_label_create(image);
    lv_label_set_recolor(friend_label, true);
    lv_label_set_text(friend_label, "Friend");
    lv_obj_set_style_text_color(friend_label, lv_color_white(), 0);
    lv_obj_align(friend_label, LV_ALIGN_DEFAULT, 10, 250);

    lv_obj_t * invite_label = lv_label_create(image);
    lv_label_set_recolor(invite_label, true);
    lv_label_set_text(invite_label, "Invite");
    lv_obj_set_style_text_color(invite_label, lv_color_white(), 0);
    lv_obj_align(invite_label, LV_ALIGN_DEFAULT, 10, 320);
}

static void my_timer(lv_timer_t * timer) {
    /* User data is the previous event that got the code here */
    lv_obj_t * user_data = timer->user_data;

    device_connected(user_data, 2);

}
/* When a device is selected to be enquire about a trust relationship, this code page displays */
void enter_code_handler(lv_event_t * e)
{
    printf ("Enter code ..\n");

    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * cont = lv_obj_create(lv_obj_get_user_data(target));
    lv_obj_t * image = lv_img_create(cont);
    lv_style_t code_style;

    lv_obj_set_size(cont, OCO_CANVAS_WIDTH, OCO_CANVAS_HEIGHT);
    lv_obj_center(cont);
    lv_obj_set_scroll_dir(cont, LV_DIR_VER);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_align(image, LV_ALIGN_CENTER, 0, 0);

    lv_img_set_src(image, &Background);
    lv_obj_fade_in(image, 1000, 0);

    /* 'Cancel' button to cancel the security challenge process*/
    lv_obj_t * cancel = lv_label_create(cont);
    lv_label_set_recolor(cancel, true);
    lv_label_set_text(cancel, "Cancel");
    lv_obj_set_style_text_color(cancel, lv_color_white(), 0);
    lv_obj_align(cancel, LV_ALIGN_DEFAULT, 230, -4);

    /* 'Return' (back) button to previous button */
    lv_obj_t * cancel_button = lv_btn_create(cont);
    lv_obj_set_size(cancel_button, 50, 50);
    lv_obj_align(cancel_button, LV_ALIGN_DEFAULT, 230, -4);
    lv_obj_add_event_cb(cancel_button, back_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(cancel_button, cont);
    lv_obj_set_style_opa(cancel_button, LV_OPA_0, LV_PART_MAIN);


    /* Display the code */

    // Conditional code below to display number as text.  Some issue with font size,
    // No time to figure out ATM.
#if FONT_SIZE_WORKS
    lv_style_init(&code_style);
    lv_obj_t * code = lv_label_create(cont);
    lv_label_set_recolor(code, true);
    lv_style_set_text_font(&code_style, &lv_font_montserrat_48);
    lv_label_set_text(code, "626920");
    lv_obj_set_style_text_color(code, lv_palette_main(LV_PALETTE_GREY), 0);
    lv_obj_add_style(code, &code_style, LV_PART_MAIN);
    lv_obj_align(code, LV_ALIGN_DEFAULT, 120, 200);
#else
    // For now display a static image of the code numbers
    lv_obj_t * code = lv_img_create(image);
    lv_img_set_src(code, &Time);
    lv_obj_align(code, LV_ALIGN_DEFAULT, 40, 200);
 #endif //FONT_SIZE_WORKS
    
    /* Tell them what to do with the displayed code */
    lv_obj_t * instructions = lv_label_create(cont);
    lv_label_set_recolor(instructions, true);
    lv_label_set_text(instructions, "Enter this code\n on your device");
    lv_obj_set_style_text_color(instructions, lv_palette_main(LV_PALETTE_GREY), 0);
    lv_obj_align(instructions, LV_ALIGN_DEFAULT, 100, 350);

    render_back_button(image, back_button_cb);

    /* After an amount of time to simulate entering the code on candidate device - display the device */
    lv_timer_t* sleeptimer = lv_timer_create(my_timer, 5000, cont);
    lv_timer_set_repeat_count(sleeptimer, 1);

    printf ("waiting for user to enter code\n");
}

/* After selecting the '+' (add device) button on the devices page list more devices in the area */
void found_devices_handler(lv_event_t * e)
{
    printf ("to found devices..\n");

    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * cont = lv_obj_create(lv_obj_get_user_data(target));
    /* Store the content of this page for later display */

    device_menu_vectors[DEVICE_FOUND_VEC] = cont;

    lv_obj_t * image = lv_img_create(cont);

    lv_obj_set_size(cont, OCO_CANVAS_WIDTH, OCO_CANVAS_HEIGHT);
    lv_obj_center(cont);
    lv_obj_set_scroll_dir(cont, LV_DIR_VER);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_align(image, LV_ALIGN_CENTER, 0, 0);

    lv_img_set_src(image, &Background);
    lv_obj_fade_in(image, 1000, 0);

    render_back_button(image, back_button_cb);

        /* Add the Page header at the top*/
    lv_label_t * page_header = lv_label_create(image);
    lv_label_set_recolor(page_header, true);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 45);
    lv_label_set_text(page_header, "Devices");
    lv_obj_set_style_text_color(page_header, lv_palette_main(LV_PALETTE_GREY), 0);

    /* Add the item List heading*/
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_DEFAULT, 40, 90);
    lv_label_set_text(list_name, "List of devices found");
    lv_obj_set_style_text_color(list_name, lv_palette_main(LV_PALETTE_GREY), 0);

    lv_point_t left = {-30, 9};
    lv_point_t right = {280, 9};

    //static lv_point_t line_points[] = { {-30, 10}, {280, 10}};
    /* Add devices entries as clickable buttons*/
    for (int i = 0; i < DEVICE_FOUND_MAX; i++)
    {
        device_found[i] = lv_img_create(cont);
        //lv_obj_set_size(device_found[i], 330, 0);
        lv_obj_align(device_found[i], LV_ALIGN_TOP_LEFT, -10, 60 + (55 * i));

        add_separator_line(left, right, device_found[i]);

        /* Device icon image on the left */
        lv_obj_t * device_icon = lv_img_create(device_found[i]);
        lv_img_set_src(device_icon, devices_found_info[i].icon);
        lv_obj_align(device_icon, LV_ALIGN_DEFAULT, 35, 10);
        lv_obj_set_style_opa(device_icon, LV_OPA_70, LV_PART_MAIN);

        /*this is the opaque button overlay of the device entry graphic*/
        found_btn[i] = lv_btn_create(device_found[i]);
        lv_obj_set_size(found_btn[i], 330, 50);
        lv_obj_align(found_btn[i], LV_ALIGN_DEFAULT, 0, 0);
        lv_obj_set_style_opa(found_btn[i], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(found_btn[i], enter_code_handler, LV_EVENT_CLICKED, 0);
        lv_obj_set_user_data(found_btn[i], cont);

        /* The label text with the device name */
        label = lv_label_create(device_found[i]);
        lv_label_set_recolor(label, true);
        lv_obj_align(label, LV_ALIGN_DEFAULT, 100, 10);
        lv_label_set_text(label, devices_found_info[i].menu_name);
        lv_obj_set_style_text_color(label, lv_color_white(), 0);

        lv_obj_t * next_icon = lv_img_create(device_found[i]);
        lv_img_set_src(next_icon, &Icon_Next_White);
        lv_obj_align(next_icon, LV_ALIGN_CENTER, 130, -15);
        lv_obj_set_style_opa(next_icon, LV_OPA_70, LV_PART_MAIN);   
    }
}

/* This is the 'root' page for handling devices */
void device_handler(lv_event_t * e)
{
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * cont = lv_obj_create(lv_obj_get_user_data(target));
    
    /* Store the content of this page for later display */
    device_menu_vectors[DEVICE_HANDLER_VEC] = cont;

    lv_obj_t * image = lv_img_create(cont);

    lv_obj_set_size(cont, OCO_CANVAS_WIDTH, OCO_CANVAS_HEIGHT);
    lv_obj_center(cont);
    lv_obj_set_scroll_dir(cont, LV_DIR_VER);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_align(image, LV_ALIGN_CENTER, 0, 0);

    lv_img_set_src(image, &Background);
    lv_obj_fade_in(image, 1000, 0);

    render_back_button(image, back_button_cb);

    /* 'Add' button to add selected device */
    lv_obj_t * add_image = lv_img_create(image);
    lv_img_set_src(add_image, &Icon_More_White);
    lv_obj_align(add_image, LV_ALIGN_DEFAULT, 310, 40);

    lv_obj_t * add = lv_btn_create(image);
    lv_obj_set_size(add, 50, 50);
    lv_obj_align(add, LV_ALIGN_DEFAULT, 290, 40);
    lv_obj_add_event_cb(add, found_devices_handler, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(add, cont);
    lv_obj_set_style_opa(add, LV_OPA_0, LV_PART_MAIN);

        /* Add the Page header at the top*/
    lv_label_t * page_header = lv_label_create(image);
    lv_label_set_recolor(page_header, true);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 45);
    lv_label_set_text(page_header, "Devices");
    lv_obj_set_style_text_color(page_header, lv_palette_main(LV_PALETTE_GREY), 0);

    /* Add the item List heading*/
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_DEFAULT, 40, 90);
    lv_label_set_text(list_name, "List of devices");
    lv_obj_set_style_text_color(list_name, lv_palette_main(LV_PALETTE_GREY), 0);

    /* The WiFi indicator */
    lv_obj_t * wifi_symbol = lv_img_create(image);
    lv_img_set_src(wifi_symbol, &Icon_WiFi_White);
    lv_obj_align(wifi_symbol, LV_ALIGN_DEFAULT, 270, 90);

    /* The Bluetooth indicator */
    lv_obj_t * bt_symbol = lv_img_create(image);
    lv_img_set_src(bt_symbol, &Icon_Bluetooth_White);
    lv_obj_align(bt_symbol, LV_ALIGN_DEFAULT, 290, 90);

    /* The NFC indicator */
    lv_obj_t * nfc_symbol = lv_img_create(image);
    lv_img_set_src(nfc_symbol, &Icon_NFC_White);
    lv_obj_align(nfc_symbol, LV_ALIGN_DEFAULT, 310, 90);
    lv_obj_set_style_opa(nfc_symbol, LV_OPA_40, LV_PART_MAIN);

    lv_point_t left = { -20, 0};
    lv_point_t right = { 290, 0};

    //static lv_point_t line_points[] = { {-30, 10}, {280, 10}};
    /* Add devices entries as clickable buttons*/
    for (int i = 0; i < DEVICE_PAGE_MAX; i++)
    {
        device_index[i] = lv_img_create(cont);
        lv_obj_set_size(device_index[i], 330, 80);
        lv_obj_set_style_opa(device_index[i], LV_OPA_60, LV_PART_MAIN);
        lv_obj_align(device_index[i], LV_ALIGN_TOP_LEFT, -10, 66 + (54 * i));

        add_separator_line(left, right, device_index[i]);

        /* Device icon image on the left */
        lv_obj_t * device_icon = lv_img_create(device_index[i]);
        lv_img_set_src(device_icon, devices_active_info[i].icon);
        lv_obj_align(device_icon, LV_ALIGN_CENTER, -130, -15);
        lv_obj_set_style_opa(device_icon, LV_OPA_70, LV_PART_MAIN);

        /*this is the opaque button overlay of the device entry graphic*/
        device_btn[i] = lv_btn_create(device_index[i]);
        lv_obj_set_size(device_btn[i], 330, 50);
        lv_obj_align(device_btn[i], LV_ALIGN_DEFAULT, 0, 0);
        lv_obj_set_style_opa(device_btn[i], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(device_btn[i], device_selected_cb, LV_EVENT_CLICKED, 0);

        /* The label text with the device name */
        label = lv_label_create(device_index[i]);
        lv_label_set_recolor(label, true);
        lv_obj_align(label, LV_ALIGN_DEFAULT, 100, 10);
        lv_label_set_text(label, devices_active_info[i].menu_name);
        lv_obj_set_style_text_color(label, lv_color_white(), 0);

        security_status = lv_label_create(device_index[i]);
        lv_label_set_recolor(security_status, true);
        lv_obj_align(security_status, LV_ALIGN_DEFAULT, 100, 30);
        lv_label_set_text(security_status, devices_active_info[i].security_status == ADMIN ? "Admin":"Friend");
        lv_obj_set_style_text_color(security_status, lv_palette_main(LV_PALETTE_GREY), 0);

        lv_obj_t * status_active_icon = lv_img_create(device_index[i]);
        lv_img_set_src(status_active_icon, devices_active_info[i].active ? &Icon_Status_Active: &Icon_Status_Disable);
        lv_obj_align(status_active_icon, LV_ALIGN_CENTER, 130, -15);
        
    }
}
