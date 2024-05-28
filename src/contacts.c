#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>

/* Initialize/populate the Contacts list struct */
#include "content/inc/contacts/01.h"

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

/* Set variables to determine total number of Contacts list members */
static int total_contact_items = 1;
static int ttl_items;

/* Set variables to calculate and then truncate strings too wide for the viewport -- insert an ellipsis in place of the long string */
static const char * name_string;
static int name_count;
static const char * email_string;
static int email_count;
static const char * company_string;
static int company_count;
static const char * notes_string;
static int notes_count;

/* Set variables for all the contacts content fields: ID, NAME, EMAIL, PHONE, etc */
lv_label_t * contact_name;
lv_label_t * contact_p_email;
lv_label_t * contact_m_phone;
lv_label_t * contact_company_name;
lv_label_t * contact_notes;

lv_obj_t * contact_initials_bg;
lv_label_t * contact_initials;

lv_label_t * heading_mobile;
lv_label_t * heading_email;
lv_label_t * heading_company;
lv_label_t * heading_notes;

// lv_label_t * contact_detail_from;
static lv_obj_t * top_of_list_items;

/* The following function populates the main screen with full list of contacts */
void contacts_list_init(lv_obj_t * contacts_page) {
    lv_obj_t * image = lv_img_create(contacts_page);
    lv_img_set_src(image, &Background);

    /* Calculate total Contact records */
    printf("\nCalculate contact records...\n");
    for(ttl_items = 0; contacts_01_list[ttl_items].contact_id != "end"; ttl_items++) {
        total_contact_items = ttl_items+1;
        printf("Item count: %d -- contact_id: %s\n",total_contact_items,contacts_01_list[ttl_items].contact_id);
    }
    printf("\nTotal Records: %d\n\n",total_contact_items);

    /* Build the Contact record list for display */
    printf("Building each Contact record for display\n");
    for(int j = 0; j < total_contact_items; j++) {
        if(contacts_01_list[j].contact_id == "end") {
            printf("item: %d -- contact_notes: %s\n",j,contacts_01_list[j].contact_notes);
            break;
        } else {
            printf("contact_id: %s -- contact_name: %s\n",contacts_01_list[j].contact_id,contacts_01_list[j].contact_name);
        }
    }

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the text messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Contacts_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    /* Add the text message list heading - NOT NEEDED FOR THIS APP */
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_TOP_LEFT, CONTACT_PAD_LEFT, 112);
    lv_label_set_text(list_name, "Favorites");
    lv_obj_set_style_text_color(list_name, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(list_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    // Add a list item separator line below the list item header
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_LEFT_MID, LIST_SEPARATOR, -97);

    /* These keep the alignment settings evenly spaced when in a for loop */
    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[total_contact_items];

    /* Add (simulated) contacts as clickable buttons*/
    for (int i = 0; i < total_contact_items; i++) {

        left.y = left.y + offset;
        right.y = right.y + offset;

        offset =  -48 + (62 * i);

        /* Calculate if the NAME field is greater than or equal to 25 characters */
        name_string = contacts_01_list[i].contact_name;
        name_count = strlen(name_string);

        /* Contact NAME field */
        contact_name = lv_label_create(image);
        lv_label_set_recolor(contact_name, true);

        /* Calculate and then truncate if the NAME field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
        if(name_count >= 37) {
            lv_label_set_text(contact_name, contacts_01_list[i].contact_name);
            lv_label_cut_text(contact_name,35,name_count);
            lv_label_ins_text(contact_name,37,"...");
        } else {
            lv_label_set_text(contact_name, contacts_01_list[i].contact_name);
        }

        /* Contact Name field */
        lv_obj_align(contact_name, LV_ALIGN_LEFT_MID, CONTACT_PAD_LEFT, offset - 16);
        lv_obj_set_style_text_color(contact_name, lv_color_white(), 0);
        lv_obj_set_style_text_font(contact_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

        /* Add a list item separator line below the list item text */
        list_item_separator[i] = lv_img_create(image);
        lv_img_set_src(list_item_separator[i], &Linez);
        lv_obj_align(list_item_separator[i], LV_ALIGN_LEFT_MID, LIST_SEPARATOR, offset + 12);
    }

    /* Bottom of the viewport overlay to obscure the list to lead the user to scroll up */
    // lv_obj_t * bottom_viewport_overlay = lv_obj_create(image);
    // lv_obj_set_size(bottom_viewport_overlay, OVERLAY_WIDTH, OVERLAY_HEIGHT);
    // lv_obj_set_pos(bottom_viewport_overlay, OVERLAY_POS_LEFT, OVERLAY_POS_FROM_TOP);
    // lv_obj_set_style_border_width(bottom_viewport_overlay, 0, LV_PART_MAIN);
    // lv_obj_set_style_bg_grad_dir(bottom_viewport_overlay, LV_GRAD_DIR_VER, 0);
    // lv_obj_set_style_bg_grad_color(bottom_viewport_overlay, lv_color_hex(OVERLAY_COLOR), 0);
    // lv_obj_set_style_bg_color(bottom_viewport_overlay, lv_color_hex(OVERLAY_COLOR), 0);
    // lv_obj_set_style_bg_opa(bottom_viewport_overlay, 164, 0);
    // lv_obj_set_style_bg_grad_stop(bottom_viewport_overlay, 255, LV_PART_MAIN);
}

void contacts_view(lv_obj_t * contacts_view_page) {
    /* Main page definition */
    lv_obj_t * image = lv_img_create(contacts_view_page);
    lv_img_set_src(image, &Background);

    /* Back button */
    render_back_button(image, back_home_button_cb);

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[total_contact_items];

/* INITIALS-OVER-IMAGE ELEMENT HERE */
    /* Contact Initials Background image */
    contact_initials_bg = lv_img_create(image);
    lv_img_set_src(contact_initials_bg, &Icon_Contact_Initials_Background);
    lv_obj_align(contact_initials_bg, LV_ALIGN_TOP_MID, 0, 24);

    /* Contact Initials text */
    contact_initials = lv_label_create(image);
    lv_label_set_text(contact_initials, contacts_01_list[CONTACT_ID].contact_initials);
    lv_label_set_recolor(contact_initials, true);
    lv_obj_align(contact_initials, LV_ALIGN_TOP_MID, 0, 42);
    lv_obj_set_style_text_color(contact_initials, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_initials, &NeueHaasDisplayLight_32, LV_PART_MAIN);

/* FULL NAME BANNER HERE */
    /* Calculate if the NAME field is greater than or equal to 25 characters */
    name_string = contacts_01_list[CONTACT_ID].contact_name;
    name_count = strlen(name_string);

    /* Contact NAME field */
    contact_name = lv_label_create(image);
    lv_label_set_recolor(contact_name, true);

    /* Calculate and then truncate if the NAME field is greater than or equal to 27 characters; then insert an ellipsis in place of the long string */
    if(name_count >= 27) {
        lv_label_set_text(contact_name, contacts_01_list[CONTACT_ID].contact_name);
        lv_label_cut_text(contact_name,25,name_count);
        lv_label_ins_text(contact_name,27,"...");
    } else {
        lv_label_set_text(contact_name, contacts_01_list[CONTACT_ID].contact_name);
    }

    /* Contact Name field */
    lv_obj_align(contact_name, LV_ALIGN_TOP_MID, 0, 120);
    lv_obj_set_style_text_color(contact_name, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_name, &NeueHaasDisplayLight_32, LV_PART_MAIN);

/* MOBILE NUMBER FIELD HERE */
    /* Contact Mobile heading */
    heading_mobile = lv_label_create(image);
    lv_label_set_recolor(heading_mobile, true);
    lv_label_set_text(heading_mobile, "Mobile");
    lv_obj_align(heading_mobile, LV_ALIGN_LEFT_MID, CONTACT_PAD_LEFT, -50);
    lv_obj_set_style_text_color(heading_mobile, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(heading_mobile, &NeueHaasDisplayLight_20, LV_PART_MAIN);

    /* Contact Mobile Number field */
    contact_m_phone = lv_label_create(image);
    lv_label_set_recolor(contact_m_phone, true);

    lv_label_set_text(contact_m_phone, contacts_01_list[CONTACT_ID].contact_m_phone);

    lv_obj_align(contact_m_phone, LV_ALIGN_LEFT_MID, CONTACT_PAD_LEFT, -20);
    lv_obj_set_style_text_color(contact_m_phone, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_m_phone, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add a list item separator line below the list item text */
    list_item_separator[CONTACT_ID] = lv_img_create(image);
    lv_img_set_src(list_item_separator[CONTACT_ID], &Linez);
    lv_obj_align(list_item_separator[CONTACT_ID], LV_ALIGN_LEFT_MID, LIST_SEPARATOR, 14);

/* EMAIL FIELD HERE */
    /* Contact Email heading */
    heading_email = lv_label_create(image);
    lv_label_set_recolor(heading_email, true);
    lv_label_set_text(heading_email, "Email");
    lv_obj_align(heading_email, LV_ALIGN_LEFT_MID, CONTACT_PAD_LEFT, 50);
    lv_obj_set_style_text_color(heading_email, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(heading_email, &NeueHaasDisplayLight_20, LV_PART_MAIN);

    /* Calculate if the EMAIL field is greater than or equal to 27 characters */
    email_string = contacts_01_list[CONTACT_ID].contact_p_email;
    email_count = strlen(email_string);

    /* Contact Email field */
    contact_p_email = lv_label_create(image);
    lv_label_set_recolor(contact_p_email, true);

    /* Calculate and then truncate if the EMAIL field is greater than or equal to 27 characters; then insert an ellipsis in place of the long string */
    if(email_count >= 27) {
        lv_label_set_text(contact_p_email, contacts_01_list[CONTACT_ID].contact_p_email);
        lv_label_cut_text(contact_p_email,25,email_count);
        lv_label_ins_text(contact_p_email,27,"...");
    } else {
        lv_label_set_text(contact_p_email, contacts_01_list[CONTACT_ID].contact_p_email);
    }

    /* Contact Email field */
    lv_obj_align(contact_p_email, LV_ALIGN_LEFT_MID, CONTACT_PAD_LEFT, 80);
    lv_obj_set_style_text_color(contact_p_email, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_p_email, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add a list item separator line below the list item text */
    list_item_separator[CONTACT_ID] = lv_img_create(image);
    lv_img_set_src(list_item_separator[CONTACT_ID], &Linez);
    lv_obj_align(list_item_separator[CONTACT_ID], LV_ALIGN_LEFT_MID, LIST_SEPARATOR, 114);

/* COMPANY NAME FIELD HERE */
    /* Contact Company heading */
    heading_company = lv_label_create(image);
    lv_label_set_recolor(heading_company, true);
    lv_label_set_text(heading_company, "Company");
    lv_obj_align(heading_company, LV_ALIGN_LEFT_MID, CONTACT_PAD_LEFT, 150);
    lv_obj_set_style_text_color(heading_company, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(heading_company, &NeueHaasDisplayLight_20, LV_PART_MAIN);

    /* Calculate if the COMPANY field is greater than or equal to 27 characters */
    company_string = contacts_01_list[CONTACT_ID].contact_company_name;
    company_count = strlen(company_string);

    /* Contact NAME field */
    contact_company_name = lv_label_create(image);
    lv_label_set_recolor(contact_company_name, true);

    /* Calculate and then truncate if the NAME field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
    if(company_count >= 27) {
        lv_label_set_text(contact_company_name, contacts_01_list[CONTACT_ID].contact_company_name);
        lv_label_cut_text(contact_company_name,25,company_count);
        lv_label_ins_text(contact_company_name,27,"...");
    } else {
        lv_label_set_text(contact_company_name, contacts_01_list[CONTACT_ID].contact_company_name);
    }

    /* Contact Name field */
    lv_obj_align(contact_company_name, LV_ALIGN_LEFT_MID, CONTACT_PAD_LEFT, 184);
    lv_obj_set_style_text_color(contact_company_name, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_company_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add a list item separator line below the list item text */
    list_item_separator[CONTACT_ID] = lv_img_create(image);
    lv_img_set_src(list_item_separator[CONTACT_ID], &Linez);
    lv_obj_align(list_item_separator[CONTACT_ID], LV_ALIGN_LEFT_MID, LIST_SEPARATOR, 220);

/* NOTES FIELD HERE */
    /* Contact Notes heading */
    heading_notes = lv_label_create(image);
    lv_label_set_recolor(heading_notes, true);
    lv_label_set_text(heading_notes, "Notes");
    lv_obj_align(heading_notes, LV_ALIGN_LEFT_MID, CONTACT_PAD_LEFT, 256);
    lv_obj_set_style_text_color(heading_notes, lv_color_hex(CONTACT_SUBDUED_COLOR), 0);
    lv_obj_set_style_text_font(heading_notes, &NeueHaasDisplayLight_20, LV_PART_MAIN);

    /* Calculate if the NOTES field is greater than or equal to 27 characters */
    notes_string = contacts_01_list[CONTACT_ID].contact_notes;
    notes_count = strlen(notes_string);

    /* Contact NAME field */
    contact_notes = lv_label_create(image);
    lv_label_set_recolor(contact_notes, true);

    /* Calculate and then truncate if the NAME field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
    if(notes_count >= 27) {
        lv_label_set_text(contact_notes, contacts_01_list[CONTACT_ID].contact_notes);
        lv_label_cut_text(contact_notes,25,notes_count);
        lv_label_ins_text(contact_notes,27,"...");
    } else {
        lv_label_set_text(contact_notes, contacts_01_list[CONTACT_ID].contact_notes);
    }

    /* Contact Name field */
    lv_obj_align(contact_notes, LV_ALIGN_LEFT_MID, CONTACT_PAD_LEFT, 290);
    lv_obj_set_style_text_color(contact_notes, lv_color_white(), 0);
    lv_obj_set_style_text_font(contact_notes, &NeueHaasDisplayLight_24, LV_PART_MAIN);

    /* Add a list item separator line below the list item text */
    list_item_separator[CONTACT_ID] = lv_img_create(image);
    lv_img_set_src(list_item_separator[CONTACT_ID], &Linez);
    lv_obj_align(list_item_separator[CONTACT_ID], LV_ALIGN_LEFT_MID, LIST_SEPARATOR, 326);

/* Contact Detail Card elements complete -- add final line below last item */

    /* Add a list item separator line below the list item text */
    list_item_separator[CONTACT_ID] = lv_img_create(image);
    lv_img_set_src(list_item_separator[CONTACT_ID], &Linez);
    lv_obj_align(list_item_separator[CONTACT_ID], LV_ALIGN_LEFT_MID, LIST_SEPARATOR, 300);

}

void contacts_menu_setup(void)
{
    printf("CONTACTS MENU init...\n");

    lv_obj_t * contacts_page = lv_obj_create(NULL);
    menu_dispatch_table[CONTACTS_VEC] = contacts_page;

    lv_obj_center(contacts_page);
    lv_obj_set_style_bg_color(contacts_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(contacts_page, LV_FLEX_FLOW_ROW);
    //lv_obj_add_event_cb(contacts_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(contacts_page, true, 3);
    lv_obj_set_scroll_dir(contacts_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(contacts_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(contacts_page, LV_OBJ_FLAG_SCROLLABLE | LV_SCROLLBAR_MODE_ON);

    /* MAIN-SCREEN: Display the list of text messages: unread and read comingled together */
    printf("CONTACTS LIST init...\n");
    contacts_01_list_init(contacts_page);

    /* MESSAGE VIEW: Display the text message FROM and MESSAGE */
    printf("CONTACTS VIEW launch...\n");
    contacts_view(contacts_page);

}
