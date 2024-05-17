#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

/* Contact list and contact ID variables */
#define CONTACT_LIST_MAX 3
// #define CONTACT_FOUND_MAX 0
#define CONTACT_ID 0

/* Contact screen alignment for Name, Phone, SMS, and Email separator lines */
#define CONTACT_HEIGHT 290
#define CONTACT_WIDTH 332
#define CONTACT_MASK_WIDTH 332
#define CONTACT_MASK_HEIGHT 100

#define CONTACT_PAD_LEFT 30
#define CONTACT_NOTES 120
#define CONTACT_CONTENT 186
#define CONTACT_LINE_SPACING 5.5

#define LIST_LEFT_ALIGNED 25
#define LIST_SEPARATOR 30
#define LIST_CONTENT_ITEM 50

/* Contact content attributes */
#define CONTACT_CONTENT_COLOR 0xADB1A2

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

LV_IMG_DECLARE(Icon_Filter_White);
LV_IMG_DECLARE(Icon_Unread_Yellow);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Time);
LV_IMG_DECLARE(Linez);

/* Main HEADING iconography */
LV_IMG_DECLARE(Contacts_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

/* global static */
// static lv_obj_t * contact_list[CONTACT_LIST_MAX];

// static lv_obj_t * trusted_device_btn_list[CONTACT_PAGE_MAX];
// static lv_obj_t * found_btn[CONTACT_FOUND_MAX];

/* Create and initialize the Contacts list */
static contacts_item contacts_list[] = {
    {
        .contact_id = "0001",
        .contact_name = "Buckaroo Banzai",
        .contact_fname = "Buckaroo",
        .contact_lname = "Banzai",
        .contact_p_email = "Buckaroo+Banzai@gmail.com",
        .contact_m_phone = "650.555.0201",
        .contact_w_address = "757 Kingman Ave, Santa Monica, CA 90402",
        .contact_notes = "Organization Name, Banzai Institute, Organization Title, CEO, Organization Department, "
    },
    {
        .contact_id = "0002",
        .contact_name = "Dr Emilio Lizardo",
        .contact_fname = "Emilio",
        .contact_lname = "Lizardo",
        .contact_p_email = "Emilio+Lizardo@gmail.com",
        .contact_m_phone = "650.555.1212",
        .contact_w_address = "8900 De Soto Ave, Canoga Park, CA 91304",
        .contact_notes = "Organization Name, Yoyodyne Propulsion Systems, Organization Title, Doctor, Organization Department, Overthruster Design",
    },
    {
        .contact_id = "0003",
        .contact_name = "Professor Toichi Hikita",
        .contact_fname = "Toichi",
        .contact_lname = "Hikita",
        .contact_p_email = "Toichi+Hikita@gmail.com",
        .contact_m_phone = "650.555.0202",
        .contact_w_address = "757 Kingman Ave, Santa Monica, CA 90402",
        .contact_notes = "Organization Name, Banzai Institute, Organization Title, Chairman, Organization Department, Research and Development",
    },
    {
        .contact_id = "0004",
        .contact_name = "Penny Priddy",
        .contact_fname = "Penny",
        .contact_lname = "Priddy",
        .contact_p_email = "Penny+Priddy@gmail.com",
        .contact_m_phone = "650.555.0203",
        .contact_w_address = "757 Kingman Ave, Santa Monica, CA 90402",
        .contact_notes = "Organization Name, Banzai Institute, Organization Title, Theoretical Assistant, Organization Department, Asset Mgmt"
    },
    {
        .contact_id = "0005",
        .contact_name = "Rawhide",
        .contact_fname = "Rawhide",
        .contact_lname = "",
        .contact_p_email = "Rawhide@gmail.com",
        .contact_m_phone = "650.555.0204",
        .contact_w_address = "367 George St, New Brunswick, NJ 08901",
        .contact_notes = "Organization Name, Hong Kong Cavaliers, Organization Title, Musician, Organization Department, "
    },
    {
        .contact_id = "0006",
        .contact_name = "Perfect Tommy",
        .contact_fname = "Perfect",
        .contact_lname = "Tommy",
        .contact_p_email = "Perfect+Tommy@gmail.com",
        .contact_m_phone = "650.555.0205",
        .contact_w_address = "367 George St, New Brunswick, NJ 08901",
        .contact_notes = "Organization Name, Hong Kong Cavaliers, Organization Title, Musician, Organization Department, "
    },
    {
        .contact_id = "0007",
        .contact_name = "New Jersey",
        .contact_fname = "New",
        .contact_lname = "Jersey",
        .contact_p_email = "New+Jersey@gmail.com",
        .contact_m_phone = "650.555.0206",
        .contact_w_address = "367 George St, New Brunswick, NJ 08901",
        .contact_notes = "Organization Name, Hong Kong Cavaliers, Organization Title, Musician, Organization Department, "
    },
    {
        .contact_id = "0008",
        .contact_name = "Reno Nevada",
        .contact_fname = "Reno",
        .contact_lname = "Nevada",
        .contact_p_email = "Reno+Nevada@gmail.com",
        .contact_m_phone = "650.555.0207",
        .contact_w_address = "367 George St, New Brunswick, NJ 08901",
        .contact_notes = "Organization Name, Hong Kong Cavaliers, Organization Title, Musician, Organization Department, "
    },
    {
        .contact_id = "0009",
        .contact_name = "The Swede",
        .contact_fname = "Swede",
        .contact_lname = "",
        .contact_p_email = "Swede@gmail.com",
        .contact_m_phone = "650.555.0214",
        .contact_w_address = "367 George St, New Brunswick, NJ 08901",
        .contact_notes = "Organization Name, Hong Kong Cavaliers, Organization Title, Musician, Organization Department, "
    },
    {
        .contact_id = "0010",
        .contact_name = "Scooter Lindley",
        .contact_fname = "Scooter",
        .contact_lname = "Lindley",
        .contact_p_email = "Scooter+Lindley@gmail.com",
        .contact_m_phone = "650.555.0209",
        .contact_w_address = "2010 El Camino Real, San Mateo, CA 94403",
        .contact_notes = "Organization Name, Blue Blaze Irregulars, Organization Title, Team Member, Organization Department, "
    },
    {
        .contact_id = "0011",
        .contact_name = "Pinky Carruthers",
        .contact_fname = "Pinky",
        .contact_lname = "Carruthers",
        .contact_p_email = "Pinky+Carruthers@gmail.com",
        .contact_m_phone = "650.555.0210",
        .contact_w_address = "2010 El Camino Real, San Mateo, CA 94403",
        .contact_notes = "Organization Name, Blue Blaze Irregulars, Organization Title, Team Member, Organization Department, "
    },
    {
        .contact_id = "0012",
        .contact_name = "Billy Travers",
        .contact_fname = "Billy",
        .contact_lname = "Travers",
        .contact_p_email = "Billy+Travers@gmail.com",
        .contact_m_phone = "650.555.0211",
        .contact_w_address = "2010 El Camino Real, San Mateo, CA 94403",
        .contact_notes = "Organization Name, Blue Blaze Irregulars, Organization Title, Team Member, Organization Department, "
    },
    {
        .contact_id = "0013",
        .contact_name = "Dr Masado Banzai",
        .contact_fname = "Masado",
        .contact_lname = "Banzai",
        .contact_p_email = "Masado+Banzai@gmail.com",
        .contact_m_phone = "650.555.0212",
        .contact_w_address = "500 W University Ave, El Paso, TX 79968",
        .contact_notes = "Organization Name, UT El Paso, Organization Title, Scientist, Organization Department, "
    },
    {
        .contact_id = "0014",
        .contact_name = "Dr Sandra Banzai",
        .contact_fname = "Sandra",
        .contact_lname = "Banzai",
        .contact_p_email = "Sandra+Banzai@gmail.com",
        .contact_m_phone = "650.555.0213",
        .contact_w_address = "500 W University Ave, El Paso, TX 79968",
        .contact_notes = "Organization Name, UT El Paso, Organization Title, Scientist, Organization Department, "
    },
    {
        .contact_id = "0015",
        .contact_name = "Lord John Whorfin",
        .contact_fname = "John",
        .contact_lname = "Whorfin",
        .contact_p_email = "John+Whorfin@gmail.com",
        .contact_m_phone = "650.555.1212",
        .contact_w_address = "8900 De Soto Ave, Canoga Park, CA 91304",
        .contact_notes = "Organization Name, Yoyodyne Propulsion Systems, Organization Title, , Organization Department, "
    },
    {
        .contact_id = "0016",
        .contact_name = "John Parker",
        .contact_fname = "John",
        .contact_lname = "Parker",
        .contact_p_email = "John+Parker@gmail.com",
        .contact_m_phone = "650.555.0208",
        .contact_w_address = "Planet 10, Redwood City, CA 94063",
        .contact_notes = "Organization Name, Planet 10, Organization Title, Pilot, Organization Department, Lectroid Flight Team"
    },
    {
        .contact_id = "0017",
        .contact_name = "John O'Connor",
        .contact_fname = "John",
        .contact_lname = "O'Connor",
        .contact_p_email = "John+O'Connor@gmail.com",
        .contact_m_phone = "650.555.1212",
        .contact_w_address = "8900 De Soto Ave, Canoga Park, CA 91304",
        .contact_notes = "Organization Name, Yoyodyne Propulsion Systems, Organization Title, Lord, Organization Department, Lectroid Commander"
    },
    {
        .contact_id = "0018",
        .contact_name = "John Emdall",
        .contact_fname = "John",
        .contact_lname = "Emdall",
        .contact_p_email = "John+Emdall@gmail.com",
        .contact_m_phone = "650.555.0208",
        .contact_w_address = "Planet 10, Redwood City, CA 94063",
        .contact_notes = "Organization Name, Planet 10, Organization Title, Chief, Organization Department, Black Lectroids"
    },
    {
        .contact_id = "0019",
        .contact_name = "John Bigboote",
        .contact_fname = "John",
        .contact_lname = "Bigboote",
        .contact_p_email = "John+Bigboote@gmail.com",
        .contact_m_phone = "650.555.1212",
        .contact_w_address = "8900 De Soto Ave, Canoga Park, CA 91304",
        .contact_notes = "Organization Name, Yoyodyne Propulsion Systems, Organization Title, , Organization Department, "
    },
    {
        .contact_id = "0020",
        .contact_name = "John Wright",
        .contact_fname = "John",
        .contact_lname = "Wright",
        .contact_p_email = "John+Wright@gmail.com",
        .contact_m_phone = "650.555.1212",
        .contact_w_address = "8900 De Soto Ave, Canoga Park, CA 91304",
        .contact_notes = "Organization Name, Yoyodyne Propulsion Systems, Organization Title, , Organization Department, "
    },
    {
        .contact_id = "end",
        .contact_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};

/* Set variables to determine total number of Contacts list members */
static int total_contact_items = 1;
static int ttl_items;

/* Set variables to calculate and then truncate strings too wide for the viewport -- insert an ellipsis in place of the long string */
static const char * name_string;
static int name_count;
static const char * email_string;
static int email_count;
static const char * phone_string;
static int phone_count;
static const char * address_string;
static int address_count;
static const char * notes_string;
static int notes_count;

/* Set variables for all the contacts content fields: ID, NAME, EMAIL, PHONE, etc */
lv_label_t * contact_id;
lv_label_t * contact_name;
lv_label_t * contact_p_email;
lv_label_t * contact_m_phone;
lv_label_t * contact_w_address;
lv_label_t * contact_status;
lv_label_t * contact_notes;
lv_label_t * contact_detail_from;
static lv_obj_t * top_of_list_items;
// static lv_obj_t * spacer;
// lv_obj_t * text_detail_message;

/* The following function populates the main screen with full list of contacts */
void contacts_list_init(lv_obj_t * contacts_page) {
    lv_obj_t * image = lv_img_create(contacts_page);
    lv_img_set_src(image, &Background);

    render_back_button(image, back_home_button_cb);

    /* 'Filter' button to filter the text messages */
    lv_obj_t * filter_image = lv_img_create(image);
    lv_img_set_src(filter_image, &Icon_Filter_Button);
    lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Contacts_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

    // Add a list item separator line above the list item text
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 147);

    lv_point_t left = { LIST_LEFT_ALIGNED, -220};
    lv_point_t right = { 290, -220};
    lv_coord_t offset = 0;
    lv_obj_t * list_item_separator[CONTACT_LIST_MAX];

    printf("\nCalculate contact records...\n");
    for(ttl_items = 0; contacts_list[ttl_items].contact_id != "end"; ttl_items++) {
        total_contact_items = ttl_items+1;
        printf("Item count: %d -- contact_id: %s\n",total_contact_items,contacts_list[ttl_items].contact_id);
    }
    printf("\nTotal Records: %d\n\n",total_contact_items);

    printf("Building each Contact record for display\n");
    for(int j = 0; j < total_contact_items; j++) {
        if(contacts_list[j].contact_id == "end") {
            printf("item: %d -- contact_notes: %s\n",j,contacts_list[j].contact_notes);
            break;
        } else {
            printf("contact_id: %s -- contact_name: %s\n",contacts_list[j].contact_id,contacts_list[j].contact_name);
        }
    }

    /* Add (simulated) contacts as clickable buttons*/
    for (int i = 0; i < total_contact_items; i++) {

        left.y = left.y + offset;
        right.y = right.y + offset;

        offset =  -64 + (92 * i);

        /* Get the total count of records in the contacts_list struct */

        /* Calculate if the FROM field is greater than or equal to 25 characters */
        name_string = contacts_list[i].contact_name;
        name_count = strlen(name_string);

        /* Calculate if the NOTES field is greater than or equal to 37 characters */
        // notes_string = contacts_list[i].contact_notes;
        // notes_count = strlen(notes_string);

        /* Contact FAV/NOT_FAV icon on the left */
        // lv_obj_t * txtmsg_icon = lv_img_create(image);
        // lv_img_set_src(txtmsg_icon, contacts_list[i].ctcitem_status);
        // lv_obj_align(txtmsg_icon, LV_ALIGN_LEFT_MID, LIST_LEFT_ALIGNED, offset);

        /* Contact NAME field */
        contact_name = lv_label_create(image);
        lv_label_set_recolor(contact_name, true);

        /* Calculate and then truncate if the FROM field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
        if(name_count >= 25) {
            lv_label_set_text(contact_name, contacts_list[i].contact_name);
            lv_label_cut_text(contact_name,23,name_count);
            lv_label_ins_text(contact_name,25,"...");
        } else {
            lv_label_set_text(contact_name, contacts_list[i].contact_name);
        }

        lv_obj_align(contact_name, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset - 15);
        lv_obj_set_style_text_color(contact_name, lv_color_white(), 0);
        lv_obj_set_style_text_font(contact_name, &NeueHaasDisplayLight_24, LV_PART_MAIN);

        /* Text message SUMMARY field */
        contact_name = lv_label_create(image);
        lv_label_set_recolor(contact_name, true);

        /* Calculate and then truncate if the SUMMARY field is greater than or equal to 37 characters; then insert an ellipsis in place of the long string */
        // if(summary_count >= 37) {
            // lv_label_set_text(contact_name, contacts_list[i].contact_name);
            // lv_label_cut_text(contact_name,35,summary_count);
            // lv_label_ins_text(contact_name,37,"...");
        // } else {
            // lv_label_set_text(contact_name, contacts_list[i].contact_name);
        // }

        lv_obj_align(contact_name, LV_ALIGN_LEFT_MID, LIST_CONTENT_ITEM, offset + 15);
        lv_obj_set_style_text_color(contact_name, lv_color_hex(CONTACT_CONTENT_COLOR), 0);
        lv_obj_set_style_text_line_space(contact_name, CONTACT_LINE_SPACING, LV_PART_MAIN);
        lv_obj_set_style_text_font(contact_name, &NeueHaasDisplayLight_20, LV_PART_MAIN);

        // Add a list item separator line above the list item text
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

void contacts_view(lv_obj_t * contacts_page) {
    /* Main page definition */
    lv_obj_t * image = lv_img_create(contacts_page);
    lv_img_set_src(image, &Background);

    /* Back button */
    render_back_button(image, back_home_button_cb);

    /* Calculate if the FROM field is greater than or equal to 25 characters */
    name_string = contacts_list[CONTACT_ID].contact_name;
    name_count = strlen(name_string);

    /* Text FROM field */
    contact_name = lv_label_create(image);
    lv_label_set_recolor(contact_name, true);

    /* Calculate and then truncate if the FROM field is greater than or equal to 25 characters; then insert an ellipsis in place of the long string */
    if(name_count >= 25) {
        lv_label_set_text(contact_name, contacts_list[CONTACT_ID].contact_name);
        lv_label_cut_text(contact_name,23,name_count);
        lv_label_ins_text(contact_name,25,"...");
    } else {
        lv_label_set_text(contact_name, contacts_list[CONTACT_ID].contact_name);
    }

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
    lv_obj_set_scrollbar_mode(contacts_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_ON);

    /* MAIN-SCREEN: Display the list of text messages: unread and read comingled together */
    printf("CONTACTS LIST init...\n");
    contacts_list_init(contacts_page);

    /* MESSAGE VIEW: Display the text message FROM and MESSAGE */
    printf("CONTACTS VIEW launch...\n");
    contacts_view(contacts_page);

}
