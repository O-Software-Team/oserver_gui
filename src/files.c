#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include "content/inc/filesystem/01.h"
#include <stdio.h>

/* Contact list and contact ID variables */
#define CONTACT_ID 0

/* Contact screen alignment for Name, Phone, SMS, and Email separator lines */
#define CONTACT_PAD_LEFT 30
#define CONTACT_NAME_WIDTH 332
#define CONTACT_NAME 120
#define LIST_LEFT_ALIGNED 25
#define LIST_SEPARATOR 30
#define LIST_CONTENT_ITEM 50

/* Contact content attributes */
#define CONTACT_SUBDUED_COLOR 0xADB1A2

/* Bottom of viewport attributes */
#define OVERLAY_WIDTH 345
#define OVERLAY_HEIGHT 35
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

LV_IMG_DECLARE(Icon_Filter_White);
LV_IMG_DECLARE(Icon_Unread_Yellow);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Time);
LV_IMG_DECLARE(Linez);

/* Contact Card - Contact Initials Background */
LV_IMG_DECLARE(Icon_Contact_Initials_Background);

/* Main HEADING iconography */
LV_IMG_DECLARE(Contacts_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);


/* USE THIS FOR THE LIST -- NEXT BUTTON */
    // next_icon[i] = lv_img_create(image);
    // lv_img_set_src(next_icon[i], &Icon_Next_White);
    // lv_obj_align(next_icon[i], LV_ALIGN_CENTER, 130, offset - 225);
    // lv_obj_set_style_opa(next_icon[i], LV_OPA_70, LV_PART_MAIN);



void file_menu_setup(void)
{
    lv_obj_t * files_page = lv_obj_create(NULL);
    lv_obj_t * background = lv_img_create(files_page);
    lv_img_set_src(background, &Background);

    printf("FILES MENU init...\n");

    menu_dispatch_table[FILES_VEC] = files_page;

    render_back_button(background, back_home_button_cb);
    lv_obj_center(files_page);
    lv_obj_set_style_bg_color(files_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(files_page, LV_FLEX_FLOW_ROW);
    //lv_obj_add_event_cb(files_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(files_page, true, 3);
    lv_obj_set_scroll_dir(files_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(files_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(files_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);
}
