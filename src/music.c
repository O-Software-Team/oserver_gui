#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"

#include <stdio.h>

#define MUSIC_ALBUMS_MAX 4

static menu_item music_album_list[MUSIC_ALBUMS_MAX] = {
    {.menu_pre = "ABBA SoS",      .active = false, .security_status = FRIEND, .icon = &ABBA_SOS},
    {.menu_pre = "AC / DC",       .active = false, .security_status = ADMIN,  .icon = &BACK_IN_BLACK},
    {.menu_pre = "Alicia Keys",   .active = false, .security_status = FRIEND, .icon = &ALICIA_KEYS},
    {.menu_pre = "Amy Winehouse", .active = false, .security_status = FRIEND, .icon = &AMY_WINEHOUSE},
};

static void select_album_handler(lv_event_t * e) {
    /*
     * Scroll to the page to 'play the album' - For presentation, an in-progress song will play.
     */
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * music_page = lv_obj_get_user_data(target);
    lv_img_set_src(music_page, &Music_Player_White);
    lv_obj_scroll_to_view(lv_obj_get_child(music_page, 1), LV_ANIM_ON);
}

/* After selecting the '+' (add device) button on the devices page list more devices in the area */
void music_list_init(lv_obj_t * music_page) {

    static lv_style_t label_style;
    static lv_style_t italic_style;

    lv_style_init(&label_style);
    lv_style_init(&italic_style);

    lv_style_set_text_font(&label_style, &NeueHaasDisplayLight_24);
    lv_style_set_text_font(&italic_style, &SaolDisplayRegularItalic_22);

#if ALL_SCROLL
    lv_obj_t * image = lv_img_create(music_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(music_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);

#endif // ALL_SCROLL
    render_back_button(image, back_home_button_cb);

    static lv_style_t page_header_style;
    lv_style_init(&page_header_style);
    lv_style_set_text_font(&page_header_style, &NeueHaasDisplayLight_18);

    /* Add the Page header at the top*/
    lv_label_t * pre_header = lv_label_create(image);
    lv_label_set_recolor(pre_header, true);
    lv_obj_align(pre_header, LV_ALIGN_TOP_MID, -20, 24);
    lv_obj_add_style(pre_header, &page_header_style, LV_PART_MAIN);
    lv_label_set_text(pre_header, "A");
    lv_obj_set_style_text_color(pre_header, lv_color_white(), 0);

    lv_label_t * header = lv_label_create(image);
    lv_label_set_recolor(header, true);
    lv_obj_align(header, LV_ALIGN_TOP_MID, -8, 21);
    lv_obj_add_style(header, &italic_style, LV_PART_MAIN);
    lv_label_set_text(header, "r");
    lv_obj_set_style_text_color(header, lv_color_white(), 0);

    lv_label_t * post_header = lv_label_create(image);
    lv_label_set_recolor(post_header, true);
    lv_obj_align(post_header, LV_ALIGN_TOP_MID, 12, 24);
    lv_obj_add_style(post_header, &page_header_style, LV_PART_MAIN);
    lv_label_set_text(post_header, "tists");
    lv_obj_set_style_text_color(post_header, lv_color_white(), 0);

    /* Add the item List heading*/
    lv_label_t * list_name = lv_label_create(image);
    lv_label_set_recolor(list_name, true);
    lv_obj_align(list_name, LV_ALIGN_DEFAULT, 25, 85);
    lv_label_set_text(list_name, "Alphabetical Order");
    lv_obj_set_style_text_color(list_name, lv_palette_main(LV_PALETTE_GREY), 0);

    lv_coord_t offset = 0;
    lv_obj_t * entry_separator[MUSIC_ALBUMS_MAX];
    lv_obj_t * album_icon[MUSIC_ALBUMS_MAX];
    lv_obj_t * album_btn[MUSIC_ALBUMS_MAX];
    lv_obj_t * album_label[MUSIC_ALBUMS_MAX];
    lv_obj_t * next_icon[MUSIC_ALBUMS_MAX];

    static lv_style_t name_style;
    lv_style_init(&name_style);

    /* Add devices entries as clickable buttons*/
    for (int i = 0; i < MUSIC_ALBUMS_MAX; i++)
    {
        offset =  121 + (60 * i);
        entry_separator[i] = lv_img_create(image);
        lv_img_set_src(entry_separator[i], &Linez);
        lv_obj_align(entry_separator[i], LV_ALIGN_DEFAULT, 25, offset);

        /* Album cover image on the left */
        album_icon[i] = lv_img_create(image);
        lv_img_set_src(album_icon[i], music_album_list[i].icon);
        lv_obj_align(album_icon[i], LV_ALIGN_CENTER, -130, offset - 225);
        lv_obj_set_style_opa(album_icon[i], LV_OPA_70, LV_PART_MAIN);

        /*this is the opaque button overlay of the album entry */
        album_btn[i] = lv_btn_create(image);
        lv_obj_set_size(album_btn[i], 330, 50);
        lv_obj_align(album_btn[i], LV_ALIGN_CENTER, 0, offset - 225);
        lv_obj_set_style_opa(album_btn[i], LV_OPA_0, LV_PART_MAIN);
        lv_obj_add_event_cb(album_btn[i], select_album_handler, LV_EVENT_CLICKED, 0);
        lv_obj_set_user_data(album_btn[i], music_page);

        /* The label text with the device name */
        album_label[i] = lv_label_create(image);
        lv_label_set_recolor(album_label[i], true);
        lv_obj_align(album_label[i], LV_ALIGN_LEFT_MID, 125, offset - 225);
        lv_label_set_text(album_label[i], music_album_list[i].menu_pre);
        lv_style_set_text_font(&name_style, &NeueHaasDisplayRoman_16);
        lv_obj_add_style(album_label[i], &name_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(album_label[i], lv_color_white(), 0);

        next_icon[i] = lv_img_create(image);
        lv_img_set_src(next_icon[i], &Icon_Next_White);
        lv_obj_align(next_icon[i], LV_ALIGN_CENTER, 130, offset - 225);
        lv_obj_set_style_opa(next_icon[i], LV_OPA_70, LV_PART_MAIN);
    }
}

void music_player_init(lv_obj_t * music_page) {

    #if ALL_SCROLL
    lv_obj_t * image = lv_img_create(music_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(music_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);

#endif // ALL_SCROLL
    static lv_style_t name_style;
    lv_style_init(&name_style);

        static lv_style_t current_song_style;
    lv_style_init(&current_song_style);

    lv_obj_t * album_icon = lv_img_create(image);
    lv_img_set_src(album_icon, &ALICIA_KEYS_LARGE/*music_album_list[2].icon*/); // Alicia Keys
    lv_obj_align(album_icon, LV_ALIGN_TOP_MID, 0, 100);

    lv_obj_set_style_opa(album_icon, LV_OPA_COVER, LV_PART_MAIN);

    lv_obj_t * progress = lv_img_create(image);
    lv_img_set_src(progress, &Progress);
    lv_obj_align(progress, LV_ALIGN_TOP_MID, 0, 10);

    lv_obj_t * pause = lv_img_create(image);
    lv_img_set_src(pause, &Pause);
    lv_obj_align(pause, LV_ALIGN_TOP_MID, 0, 300);

        lv_obj_t * rwnd = lv_img_create(image);
    lv_img_set_src(rwnd, &RWND);
    lv_obj_align(rwnd, LV_ALIGN_TOP_MID, -85, 325);

        lv_obj_t * ffwd = lv_img_create(image);
    lv_img_set_src(ffwd, &FFWD);
    lv_obj_align(ffwd, LV_ALIGN_TOP_MID, 85, 325);

        lv_obj_t * current_song = lv_label_create(image);
    lv_label_set_long_mode(current_song, LV_LABEL_LONG_SCROLL_CIRCULAR);     /*Circular scroll*/
    lv_obj_set_width(current_song, 200);
    lv_label_set_text(current_song, "How Come You Don't Call Me");
    lv_obj_align(current_song, LV_ALIGN_TOP_MID, 0, 240);
    lv_style_set_text_font(&current_song_style, &NeueHaasDisplayRoman_18
    );
    lv_obj_add_style(current_song, &current_song_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(current_song, lv_color_lighten(lv_color_black(), 80), 0);

    /* The label text with the album name */
    lv_obj_t * album_label = lv_label_create(image);
    lv_obj_align(album_label, LV_FLEX_ALIGN_CENTER, 0, 210);
    lv_label_set_text(album_label, music_album_list[2].menu_pre);
    lv_style_set_text_font(&name_style, &NeueHaasDisplayLight_22);
    lv_obj_add_style(album_label, &name_style, LV_PART_MAIN);
    lv_obj_set_style_text_color(album_label, lv_color_black(), 0);

    static lv_style_t min_remain_style;
    lv_style_init(&min_remain_style);
    lv_style_set_text_font(&min_remain_style, &NeueHaasDisplayRoman_18);

    /* Click herer to go back to Album list */
    lv_obj_t * background = lv_label_create(image);
    lv_label_set_recolor(background, true);
    lv_label_set_text(background, "      Back\n to playlist");
    lv_obj_set_style_text_color(background, lv_color_darken(lv_color_black(), 50), 0);
    lv_obj_add_style(background, &min_remain_style, LV_PART_MAIN);
    lv_obj_align(background, LV_ALIGN_BOTTOM_MID, 5, -50);

    /* Click here to run the transfer in background */
    lv_obj_t * background_button = lv_btn_create(image);
    lv_obj_set_size(background_button, 110, 60);
    lv_obj_align(background_button, LV_ALIGN_BOTTOM_MID, 10, -40);
    lv_obj_add_event_cb(background_button, back_button_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(background_button, image);
    lv_obj_set_style_opa(background_button, LV_OPA_0, LV_PART_MAIN);
}
void music_menu_setup(void)
{
    printf("MUSIC MENU setup...\n");
#if ALL_SCROLL
    lv_obj_t * music_page = lv_obj_create(NULL);
    menu_dispatch_table[DEVICE_VEC] = music_page;

    lv_obj_center(music_page);
    lv_obj_set_style_bg_color(music_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(music_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(music_page, true, 3);
    lv_obj_set_scroll_dir(music_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(music_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(music_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* Store the content of this page for later display */

    /* SUB-SCREEN 0: Create already connected (trusted) devices page add it to parent */
    music_list_init(music_page);
#else
    lv_obj_t * lotus_root_page = lv_img_create(NULL);
    menu_dispatch_table[MUSIC_VEC] = lotus_root_page;

    lv_obj_set_size(lotus_root_page, 385, 510); // Same as the simulator dislay
    lv_obj_set_style_bg_color(lotus_root_page, lv_color_lighten(lv_color_black(), 50), 0);
    lv_img_set_src(lotus_root_page, &Background);
    lv_obj_set_flex_flow(lotus_root_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_scroll_dir(lotus_root_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(lotus_root_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(lotus_root_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* Store the content of this page for later display */

    /* SUB-SCREEN 0: List of albums to play */
    music_list_init(lotus_root_page);

    /* SUB-SCREEN 1: The music play screen - playing album in progress */
    music_player_init(lotus_root_page);

#endif // ALL_SCROLL
}
