/*********************
 *      INCLUDES
 *********************/
//#include "../../lv_demo.h"
#include "../oserver_gui_demo.h"
#include "../../lvgl/src/misc/lv_color.h"
#include "../../lvgl/src/font/lv_font.h"

#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <inttypes.h>
#include <stdio.h>

#if LV_BUILD_EXAMPLES && LV_USE_FLEX

LV_IMG_DECLARE(Background_Menu_Yellow);
LV_IMG_DECLARE(Icon_Menu_Devices_Yellow);
LV_IMG_DECLARE(Icon_Menu_O_Yellow);
LV_IMG_DECLARE(Icon_Menu_Files_Yellow);
LV_IMG_DECLARE(Icon_Menu_Mail_Yellow);
LV_IMG_DECLARE(Icon_Menu_Contact_Yellow);
LV_IMG_DECLARE(Icon_Menu_Calendar_Yellow);
LV_IMG_DECLARE(Icon_Menu_Text_Yellow);
LV_IMG_DECLARE(Icon_Menu_Music_Yellow);
LV_IMG_DECLARE(Icon_Menu_Settings_Yellow);
LV_IMG_DECLARE(grey_dot_alt);
LV_IMG_DECLARE(teal_circle_selector);
LV_IMG_DECLARE(Background);

LV_FONT_DECLARE(lv_font_montserrat_20);
LV_FONT_DECLARE(lv_font_montserrat_48);

const lv_img_dsc_t * icon_images[OCO_PAGE_MAX] = {
    & Icon_Menu_Devices_Yellow,
    & Icon_Menu_O_Yellow,
    & Icon_Menu_Files_Yellow,
    & Icon_Menu_Mail_Yellow,
    & Icon_Menu_Contact_Yellow,
    & Icon_Menu_Calendar_Yellow,
    & Icon_Menu_Text_Yellow,
    & Icon_Menu_Music_Yellow,
    & Icon_Menu_Settings_Yellow,
};

static lv_obj_t * page_index[OCO_PAGE_MAX];

menu_item main_menu_dispatch[OCO_PAGE_MAX] = {
    { .menu_pre = "De",     .menu_italic = "v",  .lx = -20, .mx = 0,  .rx = 26, .menu_post = "ices", .menu_vec = DEVICE_VEC,   .active = true },
    { .menu_pre = "O",      .menu_italic = "\0", .lx = 0,   .mx = 0,  .rx = 20, .menu_post = "\0",   .menu_vec = OSERVER_VEC,  .active = true },
    { .menu_pre = "Fil",    .menu_italic = "e",  .lx = -15, .mx = 2,  .rx = 13, .menu_post = "s",    .menu_vec = FILES_VEC,    .active = true },
    { .menu_pre = "E",      .menu_italic = "m",  .lx = -17, .mx = 0,  .rx = 21, .menu_post = "ail",  .menu_vec = EMAIL_VEC,    .active = true },
    { .menu_pre = "Conta",  .menu_italic = "c",  .lx = -21, .mx = 15, .rx = 30, .menu_post = "ts",   .menu_vec = CONTACTS_VEC, .active = true },
    { .menu_pre = "Cal",    .menu_italic = "e",  .lx = -26, .mx = -5, .rx = 23, .menu_post = "ndar", .menu_vec = CALENDAR_VEC, .active = true },
    { .menu_pre = "Te",     .menu_italic = "x",  .lx = -16, .mx = 3,  .rx = 14, .menu_post = "t",    .menu_vec = TEXT_VEC,     .active = true },
    { .menu_pre = "M",      .menu_italic = "u",  .lx = -16, .mx = 0,  .rx = 20, .menu_post = "sic",  .menu_vec = MUSIC_VEC,    .active = true },
    { .menu_pre = "Settin", .menu_italic = "g",  .lx = -21, .mx = 13, .rx = 25, .menu_post = "s",    .menu_vec = SETTINGS_VEC, .active = true },
};

static uint16_t index_offset [OCO_PAGE_MAX] = {
    40, 24, 10, 5, 2, 5, 10, 24, 40,
};

static void main_scroll_event_cb(lv_event_t * e) {

    /*
     * If any one of the main pages get the scroll event
     * run through all of them to move them in the lotus arc.
     */
    lv_obj_t * cont = lv_event_get_target(e);
    lv_area_t cont_a;
    uint32_t child_cnt;

    lv_obj_get_coords(cont, &cont_a);
    lv_coord_t cont_x_center = cont_a.x1 + lv_area_get_width(&cont_a) / 2;
    lv_coord_t cont_y_center = cont_a.y1 + lv_area_get_height(&cont_a) / 2;
    lv_coord_t r = lv_obj_get_height(cont) * 7 / 10;

    /*
     * For each child page - translate and rotate to simulate lotus
     */
    child_cnt = lv_obj_get_child_cnt(cont);
    for(uint32_t i = 0; i < child_cnt; i++) {
        lv_obj_t * child = lv_obj_get_child(cont, i);
        lv_area_t child_a;
        lv_obj_get_coords(child, &child_a);
        lv_coord_t child_x_center = child_a.x1 + lv_area_get_width(&child_a) / 2;
        lv_coord_t diff_x = child_x_center - cont_x_center;
        lv_coord_t child_y_center = child_a.y1 + lv_area_get_height(&child_a) / 2;
        lv_coord_t diff_y = child_y_center - cont_y_center;
        lv_coord_t x_track = diff_x;
        lv_coord_t angle = 0;
        /*Get the y of diff_x on a circle.*/
        lv_coord_t y;
        diff_x = LV_ABS(diff_x);

        /* If diff_x is out of the circle use the last point of the circle (the radius) */
        if(diff_x >= r) {
            y = r;
        }
        else {
            /*Use Pythagoras theorem to get y from radius and x*/
            uint32_t x_sqr = r * r - diff_x * diff_x; /* PEMDAS */
            lv_sqrt_res_t res;
            lv_sqrt(x_sqr, &res, 0x8000);   /* Use lvgl's sqrt root function */
            y = r - res.i;
        }
        angle = lv_atan2(diff_x, r - diff_y);
        x_track < 0 ? angle = -angle: angle;

        /*Translate the item by the calculated Y coordinate*/
        lv_obj_set_style_translate_y(child, y * 0.5, 0);
        lv_obj_set_style_transform_angle(child, angle * 3, 0);
        if (angle == 0) {
            lv_event_send(page_index[i], LV_EVENT_RELEASED, NULL);
        } else {
            lv_event_send(page_index[i], LV_EVENT_PRESSED, NULL);
        }
        /* Use some opacity with larger translations */
        lv_opa_t opa = lv_map(y, 0, r, LV_OPA_TRANSP, LV_OPA_50);
        lv_obj_set_style_opa(child, LV_OPA_COVER - opa, 0);
    }
}

void oserver_gui(void) {

    lv_disp_load_scr(menu_dispatch_table[MAIN_MENU_VEC]); // The top main menu
}

/**
 * @brief Initialize menus
 *
 */
void main_menu_init(void) {

    lv_obj_t * main_page;
    lv_obj_t * lotus_page;

    uint32_t i;
    lv_obj_t * image_cover;
    lv_obj_t * icon;
    lv_obj_t * btn;

    lv_label_t * label_pre;
    lv_label_t * label;
    lv_label_t * label_post;

    lv_label_t * label_index;

    static lv_style_t label_style;
    static lv_style_t italic_style;
    static lv_style_t label_index_style;

    lv_style_init(&label_style);
    lv_style_init(&italic_style);
    lv_style_init(&label_index_style);

    lv_style_set_text_font(&label_style, &NeueHaasDisplayLight_24);
    lv_style_set_text_font(&italic_style, &SaolDisplayRegularItalic_26);

    lv_style_set_text_font(&label_index_style, &NeueHaasDisplayRoman_16);

    /*
     * On the main page, create the individual pages which will be lotus scrolled
     */
    lotus_page = lv_img_create(NULL);
    menu_dispatch_table[MAIN_MENU_VEC] = lotus_page;
    lv_obj_set_size(lotus_page, 385, 510); // Same as the simulator dislay

    lv_obj_set_style_bg_color(lotus_page, lv_color_lighten(lv_color_black(), 50), 0);
    lv_img_set_src(lotus_page, &Background);

    lv_obj_add_event_cb(lotus_page, main_scroll_event_cb, LV_EVENT_SCROLL, NULL);

    lv_obj_set_flex_flow(lotus_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_column(lotus_page, 80, 0);


    lv_obj_set_scroll_dir(lotus_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(lotus_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(lotus_page, LV_SCROLLBAR_MODE_OFF);
    lv_obj_align(lotus_page, LV_ALIGN_CENTER, 60, -150);

    for(i = 0; i < OCO_PAGE_MAX; i++) {

        image_cover = lv_img_create(lotus_page);
        lv_img_set_src(image_cover, &Background_Menu_Yellow);
        lv_obj_set_style_opa(image_cover, LV_OPA_0, 0);
        //lv_obj_align(image_cover, LV_ALIGN_CENTER, 60, -150);
        lv_obj_set_style_pad_top(image_cover, 70, 0);

        /* Add opaque button used to click and select menu item */
        btn = lv_btn_create(image_cover);
        lv_obj_set_size(btn, 230, 280);
        lv_obj_set_style_opa(btn, LV_OPA_0, 0);
        lv_obj_add_event_cb(btn, &menu_dispatch, LV_EVENT_LONG_PRESSED, NULL);
        lv_obj_set_user_data(btn, main_menu_dispatch[i].menu_vec);

        /* Add page icon */
        icon = lv_img_create(image_cover);
        lv_img_set_src(icon, icon_images[i]);
        lv_obj_align(icon, LV_ALIGN_CENTER, 0, -40);

        /* Add menu label name and its sequence number */
        label_pre = lv_label_create(image_cover);
        label = lv_label_create(image_cover);
        label_post = lv_label_create(image_cover);

        label_index = lv_label_create(image_cover);
        lv_label_set_recolor(label_index, true);
        lv_obj_add_style(label_index, &label_index_style, LV_PART_MAIN);

        /* Allow recoloring and add the font style to each part of the label */
        lv_label_set_recolor(label_pre, true);
        lv_obj_add_style(label_pre, &label_style, LV_PART_MAIN);

        lv_label_set_recolor(label, true);
        lv_obj_add_style(label, &italic_style, LV_PART_MAIN);

        lv_label_set_recolor(label_post, true);
        lv_obj_add_style(label_post, &label_style, LV_PART_MAIN);
        
        /* Add the text and color to the label */
        lv_label_set_text(label_pre, main_menu_dispatch[i].menu_pre);
        lv_obj_set_style_text_color(label_pre, lv_color_white(), 0);

        lv_label_set_text(label, main_menu_dispatch[i].menu_italic);
        lv_obj_set_style_text_color(label, lv_color_white(), 0);

        lv_label_set_text(label_post, main_menu_dispatch[i].menu_post);
        lv_obj_set_style_text_color(label_post, lv_color_white(), 0);

        /* Adjust color and format of the page index */
        lv_label_set_text_fmt(label_index, "0%d", i + 1);
        lv_obj_set_style_text_color(label_index, lv_palette_main(LV_PALETTE_GREY), 0);

        /* Align texts on the screen as needed */
        lv_obj_align(label_pre, LV_ALIGN_CENTER, main_menu_dispatch[i].lx, 25);
        lv_obj_align(label, LV_ALIGN_CENTER, main_menu_dispatch[i].mx, 24);
        lv_obj_align(label_post, LV_ALIGN_CENTER, main_menu_dispatch[i].rx, 25);

        lv_obj_align(label_index, LV_ALIGN_CENTER, 0, 50);

        /* Add page index indicator and intialize pages to the first one in the sequence */
        page_index[i] = lv_imgbtn_create(lv_layer_top());
        lv_obj_clear_flag(page_index[i], LV_OBJ_FLAG_CLICKABLE);

        /* Set up images for page index indicators */
        lv_imgbtn_set_src(page_index[i], LV_IMGBTN_STATE_RELEASED, &teal_circle_selector, NULL, NULL);
        lv_imgbtn_set_src(page_index[i], LV_IMGBTN_STATE_PRESSED, &grey_dot_alt, NULL, NULL);

        lv_obj_align(page_index[i], LV_ALIGN_CENTER, (i * 20) - 20, 245 - index_offset[i] * 0.6);
        lv_event_send(page_index[i], LV_EVENT_PRESSED, NULL);
        /* Initial state is first page activated */
        if (i == 0) {
            lv_event_send(page_index[i], LV_EVENT_RELEASED, NULL);
        }
    }
    /* Update the canvas position manually for first */
    lv_obj_scroll_to_view(lv_obj_get_child(lotus_page, 0), LV_ANIM_OFF);

    device_menu_setup();
    oserver_menu_setup();
    file_menu_setup();
    email_menu_setup();
    contacts_menu_setup();
    calendar_menu_setup();
    text_menu_setup();
    music_menu_setup();
    settings_menu_setup();
}

#endif
