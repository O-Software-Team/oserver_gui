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
#define MESSAGE_TEXTAREA_HEIGHT 290
#define MESSAGE_TEXTAREA_WIDTH 332
#define MESSAGE_TEXTAREA_MASK_WIDTH 332
#define MESSAGE_TEXTAREA_MASK_HEIGHT 100

#define CONTACT_MESSAGE_PAD_LEFT 30
#define CONTACT_MESSAGE_SUBJECT 120
#define CONTACT_MESSAGE_CONTENT 186
#define CONTACT_SUBJECT_LINE_SPACING 5.5
#define CONTACT_MESSAGE_LINE_SPACING 5.5
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

LV_IMG_DECLARE(Icon_Contact_Filter_White);
LV_IMG_DECLARE(Icon_Contact_Unread_Yellow);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Time);
LV_IMG_DECLARE(Linez);

/* Main HEADING iconography */
LV_IMG_DECLARE(Contact_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

/* global static */
static lv_obj_t * contact_list[CONTACT_LIST_MAX];

// static lv_obj_t * trusted_device_btn_list[CONTACT_PAGE_MAX];
// static lv_obj_t * found_btn[CONTACT_FOUND_MAX];

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
