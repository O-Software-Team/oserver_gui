#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Initialize/populate the Song list struct */
#include "content/inc/music/00.h"   /* Full Music List */

/* List separator line definitions */
#define LIST_SEPARATOR 30

/* Padding definitions */
#define BACK_BUTTON_PAD 25
#define NARROW_PAD_LEFT 5
#define SIMPLE_PAD_LEFT 20
#define NORMAL_PAD_LEFT 30
#define NARROW_PAD_RIGHT -5
#define SIMPLE_PAD_RIGHT -20
#define NORMAL_PAD_RIGHT -30
#define REGULAR_ICON_PAD_LEFT 85

/* Color definitions */
#define O_YELLOW_COLOR 0xD6B932
#define O_GREY_COLOR 0xAEB2A1
#define O_TEAL_COLOR 0x0AC1C1
#define O_SCALE_GREY 0xC5C1B7
#define O_SCALE_CREAM 0xD9DFC2
#define O_SCALE_ORANGE 0xCB6D4D
#define O_SCALE_RED 0xB7354B
#define O_SCALE_LIGHT_TEAL 0xC5E7E7
#define O_SCALE_LIGHT_YELLOW 0xDABC41
#define HEADING_SUBDUED_COLOR 0xADB1A2
#define RESET_COLOR 0x32D642
#define POWER_OFF_COLOR 0xDD4949
#define BATTERY_LEVEL_GREAT 0x32D642
#define BATTERY_LEVEL_FAIR 0xFFFFFF
#define BATTERY_LEVEL_LOW 0xDD4949

/* Font definitions */
#define LV_FONT_MONTSERRAT_44 1
#define FONT_SIZE_WORKS 0

/* Music list and song ID variables */
#define MUSIC_ID 0   // This is temporary until the calendar list dataset is being accessed

/* Main background and radio controls declared below */
LV_IMG_DECLARE(Background);
LV_IMG_DECLARE(Icon_Back);
LV_IMG_DECLARE(Icon_WiFi_White);
LV_IMG_DECLARE(Icon_Bluetooth_White);
LV_IMG_DECLARE(Icon_NFC_White);

/* Main HEADING iconography */
LV_IMG_DECLARE(Music_App_Heading_Title);

/* Declare the primary font here */
LV_FONT_DECLARE(lv_font_montserrat_44);

LV_FONT_DECLARE(NeueHaasDisplayLight_32);

/***  Music Specific Declarations  ***/

/* Set total number of pages / screens -- this includes screen #1 which is the main music player screen */
#define NUM_SCREENS 2

#define MUSIC_ALBUMS_MAX 18

/* Set the array to store the screen reference pointers */
lv_obj_t * music_objects[NUM_SCREENS];

/* Set the BACK-TO-HOME array to use in a custom back button for the filesystem app */
static lv_obj_t * back_to_home_screen[NUM_SCREENS];

/* This is the primary "home page" element in the Settings app */
static const int back_to_home = 0;

/* Counters */
static int ttl_items;
static int ttl_music_items = 0;
static int music_ttl;
static int music_items_00;

static lv_obj_t * top_of_list_items;

/* Set style references */
static lv_style_t back_button_style;
static lv_style_t name_style_20;
static lv_style_t name_style_24;
static lv_style_t name_style_32;

static lv_style_t label_style;
static lv_style_t italic_style;

static lv_style_t wrap_content_style;

/* Music Player View fields required for population */
lv_obj_t * song_title;
lv_obj_t * song_artist;
lv_obj_t * song_cover_art;

/***  Init styles specific  ***/
static void init_styles() {
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    lv_style_init(&name_style_20);
    lv_style_set_text_font(&name_style_20, &NeueHaasDisplayLight_20);

    lv_style_init(&name_style_24);
    lv_style_set_text_font(&name_style_24, &NeueHaasDisplayLight_24);

    lv_style_init(&name_style_32);
    lv_style_set_text_font(&name_style_32, &NeueHaasDisplayLight_32);

    lv_style_init(&label_style);
    lv_style_init(&italic_style);

    lv_style_set_text_font(&label_style, &NeueHaasDisplayLight_24);
    lv_style_set_text_font(&italic_style, &SaolDisplayRegularItalic_26);
}

/* Function to update the song data on the Music Player screen */
static void update_song_card(const char * artist, const char * song, const char * cover) {
    lv_label_set_text(song_artist, artist);
    lv_label_set_text(song_title, song);
    lv_img_set_src(song_cover_art, cover);
}

/* Function to find a song by ID */
static music_item *find_song_by_id(const char *id_to_find) {
    for (size_t i = 0; i < sizeof(music_00_list) / sizeof(music_item); ++i) {
        if (strcmp(music_00_list[i].album_id, id_to_find) == 0) {
            return &music_00_list[i];
        }
    }
    return NULL;  // Item not found
}

/* This function wis used to display the appropriate crypto info based upon the line item the user clicks */
static void display_song_info_cb(lv_event_t * e) {
    const char *screen_index = (const char *)lv_event_get_user_data(e);
    music_item * found_info = find_song_by_id(screen_index);

    update_song_card(found_info->album_song_title, found_info->album_artist, found_info->album_song_icon);

    lv_obj_scroll_to_view(music_objects[1], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

/* Scroll to the home screen as the final step in the settings app launch */
static void scroll_to_home() {
    // printf("EXEC :: scroll_to_home()\n\n");
    lv_obj_scroll_to_view(music_objects[back_to_home], LV_ANIM_OFF);
}

/* Scroll to screen clicked in the clickback call */
static void scroll_to_screen(lv_event_t* e) {
    int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
    // printf("EXEC :: scroll_to_screen() [%d]\n\n",screen_index);
    lv_obj_scroll_to_view(music_objects[screen_index], LV_ANIM_OFF);
    lv_event_stop_bubbling(e); // Stop event bubbling
}

static __attribute__((unused)) void image_click_event_cb(lv_event_t * e) {
// static void image_click_event_cb(lv_event_t * e) {
    int screen_index = (int)(size_t)lv_event_get_user_data(e); // Get the screen index from user data
    printf("EXEC :: image_click_event_cb() [%d]\n\n",screen_index);
    // lv_obj_scroll_to_view(crypto_objects[screen_index], LV_ANIM_OFF);
    // lv_event_stop_bubbling(e); // Stop event bubbling

    // lv_event_code_t code = lv_event_get_code(e);
    // lv_obj_t * obj = lv_event_get_target(e);
    // printf("crypto item clicked\n");
}

// static void calc_dataset_items(lv_event_t * e) {
static void calc_dataset_items() {
    /* Calculate total list items */
    // printf("\nCalculate records...\n");
    for(ttl_items = 0; !is_end(music_00_list[ttl_items].album_id); ttl_items++) {
        ttl_music_items = ttl_items+1;
        // printf("Item count: %d -- calendar_id: %s\n",ttl_music_items,calendar_00_list[ttl_items].calendar_id);
    }
    // printf("\nTotal Records: %d\n\n",ttl_music_items);

    /* Build the Calendar record list for display */
    for(int j = 0; j < ttl_music_items; j++) {
        if(is_end(music_00_list[j].album_id)) {
            printf("item: %d -- album_title: %s\n",j,music_00_list[j].album_song_title);
            break;
        } else {
            // printf("calendar_id: %s -- calendar_name: %s\n",calendar_00_list[j].calendar_id,calendar_00_list[j].calendar_name);
        }
    }
}


/***  SCREEN 00 - Music page  ***/
static void music_00_view(lv_obj_t * music_00_view_page) {
    lv_obj_t * image = lv_img_create(music_00_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 0;
    // printf("Music page number: %d\n", scr_nbr);

    /* Store the pointer to the current screen being viewed */
    music_objects[scr_nbr] = image;
    // lv_img_set_src(image, &Background);
    lv_obj_set_style_bg_img_src(image, &Background, 0);

/***  HEADING ELEMENTS  ***/
    render_back_button(image, (back_button_cb_t)back_home_button_cb);

    /* 'Filter' button to filter the text messages */
    // lv_obj_t * filter_image = lv_img_create(image);
    // lv_img_set_src(filter_image, &Icon_Filter_Button);
    // lv_obj_align(filter_image, LV_ALIGN_TOP_MID, 125, 30);

    /* Add the Page header at the top */
    lv_obj_t * page_header = lv_img_create(image);
    lv_img_set_src(page_header, &Music_App_Heading_Title);
    lv_obj_align(page_header, LV_ALIGN_TOP_MID, 0, 46);

/***  MAIN LIST ITEMS  ***/
    /* Set the objects for list item separators and overlay elements for each feature here */
    lv_obj_t * list_item_tail[ttl_music_items];
    lv_obj_t * display_feature_overlay;

    int music_item_overlay_width = 145;
    int music_item_overlay_height = 135;

    /* Icon and label objects here */
    lv_obj_t * music_album_song_title[ttl_music_items];
    lv_obj_t * music_album_artist[ttl_music_items];
    lv_obj_t * music_item_icon[ttl_music_items];
    lv_obj_t * music_album_next_icon[ttl_music_items];
    lv_obj_t * music_item_overlay[ttl_music_items];

    /* Display full screen height overlay to enable scrolling */
    display_feature_overlay = lv_img_create(image);
    lv_obj_set_size(display_feature_overlay, music_item_overlay_width, music_item_overlay_height);
    lv_obj_set_style_opa(display_feature_overlay, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(display_feature_overlay, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(display_feature_overlay, scroll_to_screen, LV_EVENT_CLICKED, (void*)(size_t)cal_august);
    // lv_obj_add_event_cb(display_feature_overlay, image_click_event_cb, LV_EVENT_CLICKED, NULL);  // Use this for debugging
    lv_obj_align(display_feature_overlay, LV_ALIGN_TOP_LEFT, NARROW_PAD_LEFT, 94);

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_music_items];

/***  MUSIC ITEM LIST  ***/
    // Add a list item separator line below the list item header
    top_of_list_items = lv_img_create(image);
    lv_img_set_src(top_of_list_items, &Linez);
    lv_obj_align(top_of_list_items, LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 94);

    /* Populate screen with Music 00.h song items */
    for(music_items_00 = 0; !is_end(music_00_list[music_items_00].album_id); music_items_00++) {
        /* A row-by-row offset value to maintain spacing between clickable elements */
        int offset = music_items_00 * 90;

        /* Get the album_id for the item being clicked then set the event click */
        char * item_id = music_00_list[music_items_00].album_id;

        /* Song specific list item button overlay */
        music_item_overlay[music_items_00] = lv_btn_create(image);
        lv_obj_set_size(music_item_overlay[music_items_00], 352, 80);
        lv_obj_set_style_opa(music_item_overlay[music_items_00], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(music_item_overlay[music_items_00], display_song_info_cb, LV_EVENT_CLICKED, (void *)item_id);  // Use this to select, replace, and then view the content
        lv_obj_align(music_item_overlay[music_items_00], LV_ALIGN_TOP_LEFT, NORMAL_PAD_LEFT, 104 + offset);

        music_item_icon[music_items_00] = lv_img_create(image);
        lv_img_set_src(music_item_icon[music_items_00], music_00_list[music_items_00].album_cover_icon);
        lv_obj_set_style_opa(music_item_icon[music_items_00], LV_OPA_COVER, LV_PART_MAIN);
        lv_obj_center(music_item_icon[music_items_00]);
        lv_obj_align(music_item_icon[music_items_00], LV_ALIGN_TOP_LEFT, SIMPLE_PAD_LEFT, 112 + offset);

        music_album_song_title[music_items_00] = lv_label_create(image);
        lv_label_set_recolor(music_album_song_title[music_items_00], true);
        lv_label_set_text(music_album_song_title[music_items_00], music_00_list[music_items_00].album_song_title);
        lv_obj_add_style(music_album_song_title[music_items_00], &name_style_24, LV_PART_MAIN);
        lv_obj_set_style_text_color(music_album_song_title[music_items_00], lv_color_white(), 0);
        lv_obj_align(music_album_song_title[music_items_00], LV_ALIGN_TOP_LEFT, 89, 116 + offset);

        music_album_artist[music_items_00] = lv_label_create(image);
        lv_label_set_recolor(music_album_artist[music_items_00], true);
        lv_label_set_text(music_album_artist[music_items_00], music_00_list[music_items_00].album_artist);
        lv_obj_add_style(music_album_artist[music_items_00], &name_style_20, LV_PART_MAIN);
        lv_obj_set_style_text_color(music_album_artist[music_items_00], lv_color_hex(O_GREY_COLOR), 0);
        lv_obj_align(music_album_artist[music_items_00], LV_ALIGN_TOP_LEFT, 89, 152 + offset);

        music_album_next_icon[music_items_00] = lv_img_create(image);
        lv_img_set_src(music_album_next_icon[music_items_00], &Icon_Next_White);
        lv_obj_set_style_opa(music_album_next_icon[music_items_00], LV_OPA_70, LV_PART_MAIN);
        lv_obj_align(music_album_next_icon[music_items_00], LV_ALIGN_TOP_LEFT, 344, 138 + offset);

        /* Add a list item separator line at the end of the list item */
        list_item_tail[music_items_00] = lv_img_create(image);
        lv_img_set_src(list_item_tail[music_items_00], &Linez);
        lv_obj_align(list_item_tail[music_items_00], LV_ALIGN_TOP_LEFT, LIST_SEPARATOR, 186 + offset);
    }
}

/***  SCREEN 01 - Music Player screen  ***/
static void music_01_view(lv_obj_t * music_01_view_page) {
    lv_obj_t * image = lv_img_create(music_01_view_page);

    /* Use this to ensure the screen is in "full size" which then enables full-screen scrolling */
    lv_obj_set_size(image, lv_pct(100), lv_pct(100));
    lv_obj_set_scroll_dir(image, LV_DIR_VER);

    /* Set the screen number counter to the first visible sub-screen for the settings app */
    int scr_nbr = 1;

    /* Store the pointer to the current screen being viewed */
    music_objects[scr_nbr] = image;
    lv_obj_set_style_bg_img_src(image, &Background, 0);

    calc_dataset_items();

/***  Music Specific Style Declarations  ***/
    init_styles();

/***  HEADING ELEMENTS  ***/
    static lv_style_t back_button_style;
    lv_style_init(&back_button_style);
    lv_style_set_text_font(&back_button_style, &NeueHaasDisplayLight_20);

    /* Back button icon */
    lv_obj_t * back_image = lv_img_create(image);
    lv_img_set_src(back_image, &Icon_Back);
    lv_obj_set_style_text_color(back_image, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, BACK_BUTTON_PAD, 45);

    /* Back button label text */
    lv_obj_t * back_label = lv_label_create(image);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_add_style(back_label, &back_button_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(back_label, lv_color_hex(MESSAGE_CONTENT_COLOR), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 43, 48);

/***  MAIN LIST ITEMS  ***/
    /* Set the objects for list item separators and overlay elements for each feature here */

    /* Back button overlay */
    lv_obj_t * back_to_music = lv_btn_create(image);
    lv_obj_set_size(back_to_music, 130, 50);
    lv_obj_set_style_opa(back_to_music, LV_OPA_0, LV_PART_MAIN);
    lv_obj_add_event_cb(back_to_music, scroll_to_home, LV_EVENT_CLICKED, NULL);
    lv_obj_align(back_to_music, LV_ALIGN_TOP_LEFT, 20, 31);  // This is first object displayed on the screen

    /* Set the list_item_separator object here */
    lv_obj_t * list_item_separator[ttl_music_items];

    song_cover_art = lv_img_create(image);
    lv_img_set_src(song_cover_art, music_00_list[23].album_song_icon);
    lv_obj_align(song_cover_art, LV_ALIGN_TOP_MID, 0, 100);

    song_title = lv_label_create(image);
    lv_label_set_text(song_title, music_00_list[23].album_song_title);
    lv_obj_add_style(song_title, &name_style_24, LV_PART_MAIN);
    lv_obj_set_style_text_color(song_title, lv_color_white(), 0);
    lv_obj_align(song_title, LV_ALIGN_TOP_MID, 0, 338);

    song_artist = lv_label_create(image);
    lv_label_set_recolor(song_artist, true);
    lv_label_set_text(song_artist, music_00_list[23].album_artist);
    lv_obj_add_style(song_artist, &name_style_20, LV_PART_MAIN);
    lv_obj_set_style_text_color(song_artist, lv_color_hex(O_GREY_COLOR), 0);
    lv_obj_align(song_artist, LV_ALIGN_TOP_MID, 0, 374);

    lv_obj_t * player_controls = lv_img_create(image);
    lv_img_set_src(player_controls, &Music_Player_Controls_Play);
    lv_obj_align(player_controls, LV_ALIGN_TOP_MID, 0, 415);
}

void music_menu_setup(void) {
    printf("MUSIC MENU init...\n");

    lv_obj_t * music_page = lv_obj_create(NULL);
    menu_dispatch_table[MUSIC_VEC] = music_page;

    lv_obj_center(music_page);
    lv_obj_set_style_bg_color(music_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(music_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(music_page, true, 3);
    lv_obj_set_scroll_dir(music_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(music_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(music_page, LV_OBJ_FLAG_SCROLLABLE | LV_SCROLLBAR_MODE_ON);

    /* MUSIC VIEW: Display the content for a specific song item */
    printf("\nMUSIC_01_VIEW launch...\n");
    music_01_view(music_page);

    /* ALBUM / SONG VIEW: Display the content for music_00_view -- Song Detail */
    printf("\nMUSIC_00_VIEW launch...\n");
    music_00_view(music_page);

    scroll_to_home();
}
