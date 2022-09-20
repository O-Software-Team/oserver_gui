/*********************
 *      INCLUDES
 *********************/
//#include "../../lv_demo.h"
#include "../oserver_gui_demo.h"
#include "../../lvgl/src/misc/lv_color.h"
#include "../../lvgl/src/font/lv_font.h"

#include "oserver_gui.h"
#include "menu_handler.h"

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
    { .menu_name = "Devices",  .page_handler = &device_handler,   .active = true },
    { .menu_name = "O",        .page_handler = &oserver_handler,  .active = true },
    { .menu_name = "Files",    .page_handler = &files_handler,    .active = true },
    { .menu_name = "Email",    .page_handler = &email_handler,    .active = true },
    { .menu_name = "Contacts", .page_handler = &contacts_handler, .active = true },
    { .menu_name = "Calendar", .page_handler = &calendar_handler, .active = true },
    { .menu_name = "Text",     .page_handler = &text_handler,     .active = true },
    { .menu_name = "Music",    .page_handler = &music_handler,    .active = true },
    { .menu_name = "Settings", .page_handler = &settings_handler, .active = true },
};

static uint16_t index_offset [OCO_PAGE_MAX] = {
    40, 24, 10, 5, 2, 5, 10, 24, 40,
};

static void scroll_event_cb(lv_event_t * e)
{
    lv_obj_t * cont = lv_event_get_target(e);
    lv_area_t cont_a;

    lv_obj_get_coords(cont, &cont_a);
    lv_coord_t cont_x_center = cont_a.x1 + lv_area_get_width(&cont_a) / 2;
    lv_coord_t cont_y_center = cont_a.y1 + lv_area_get_height(&cont_a) / 2;
    lv_coord_t r = lv_obj_get_height(cont) * 7 / 10;
    uint32_t i;
    uint32_t child_cnt = lv_obj_get_child_cnt(cont);
    for(i = 0; i < child_cnt; i++) {
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
        /*If diff_x is out of the circle use the last point of the circle (the radius)*/
        if(diff_x >= r) {
            y = r;
        }
        else {
            /*Use Pythagoras theorem to get y from radius and x*/
            uint32_t x_sqr = r * r - diff_x * diff_x;
            lv_sqrt_res_t res;
            lv_sqrt(x_sqr, &res, 0x8000);   /*Use lvgl's built in sqrt root function*/
            y = r - res.i;
        }
        if (r > 0)
            angle = lv_atan2(diff_x, r - diff_y) * 2;
        x_track < 0 ? angle = -angle: angle;
        /*Translate the item by the calculated Y coordinate*/
        lv_obj_set_style_translate_y(child, y/2, 0);
        lv_obj_set_style_transform_angle(child, angle, 0);
        if (angle == 0) {
            lv_event_send(page_index[i], LV_EVENT_RELEASED, NULL);
        } else {
            lv_event_send(page_index[i], LV_EVENT_PRESSED, NULL);
        }
        /*Use some opacity with larger translations*/
        lv_opa_t opa = lv_map(y, 0, r, LV_OPA_TRANSP, LV_OPA_COVER);
        lv_obj_set_style_opa(child, LV_OPA_COVER - opa, 0);
    }
}

/**
 * @brief Initialize menus
 * 
 */
void oserver_init(void)
{
    printf ("Initialize ...\n");
}

/**
 * Oserver base menu definitions
 */
void oserver_gui(void)
{
    lv_obj_t * image;
    lv_style_t image_style;

    lv_obj_t * cont = lv_obj_create(lv_scr_act());
    device_menu_vectors[MAIN_MENU_VEC] = cont;
    lv_obj_set_size(cont, OCO_CANVAS_WIDTH, OCO_CANVAS_HEIGHT);
    lv_obj_center(cont);

    lv_obj_set_style_bg_color(cont, lv_color_lighten(lv_color_black(), 0), 0);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW);
    lv_obj_add_event_cb(cont, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(cont, true, 0);
    lv_obj_set_scroll_dir(cont, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(cont, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);

    /* Create the main page base images */
    uint32_t i;
    lv_obj_t * image_cover;
    lv_obj_t * icon;
    lv_obj_t * btn;


    lv_label_t * label;
    lv_label_t * label_index;
    lv_style_t label_style;
    lv_style_t btn_style;
    lv_style_init(&label_style);
    lv_style_init(&label_style);
    lv_style_init(&btn_style);

    for(i = 0; i < OCO_PAGE_MAX; i++) {
        /* This is the grey oval background */
        image = lv_img_create(cont);
        lv_img_set_src(image, &Background);
        lv_obj_align(image, LV_ALIGN_TOP_MID, 0, 30);
        lv_obj_set_style_opa(image, LV_OPA_0, 0);

        image_cover = lv_img_create(image);
        lv_img_set_src(image_cover, &Background_Menu_Yellow);
        lv_obj_align(image_cover, LV_ALIGN_TOP_MID, 0, 30);
        lv_obj_set_style_opa(image, LV_OPA_100, 0);

        /* Add opaque button used to click and select menu item */
        btn = lv_btn_create(image_cover);
        lv_obj_set_size(btn, 150, 200);
        lv_obj_align(btn, LV_ALIGN_DEFAULT, 60, 50);
        lv_obj_set_style_opa(btn, LV_OPA_0, 0);
        lv_obj_add_event_cb(btn, main_menu_dispatch[i].page_handler, LV_EVENT_LONG_PRESSED, NULL);
        lv_obj_set_user_data(btn, lv_scr_act());

        /* Add page icon */
        icon = lv_img_create(image_cover);
        lv_img_set_src(icon, icon_images[i]);
        lv_obj_align(icon, LV_ALIGN_CENTER, 0, -40);

        /* Add menu label name and its sequence number */
        label = lv_label_create(image_cover);
        label_index = lv_label_create(image_cover);
        lv_label_set_recolor(label_index, true);
        lv_label_set_recolor(label, true);

        /* Adjust color of the label name - can be localized */
        lv_label_set_text(label, main_menu_dispatch[i].menu_name);
        lv_obj_set_style_text_color(label, lv_color_white(), 0);

        /* Adjust color and format of the page index */
        lv_label_set_text_fmt(label_index, "0%d", i + 1);
        lv_obj_set_style_text_color(label_index, lv_palette_main(LV_PALETTE_GREY), 0);

        /* Align texts on the screen as needed */
        lv_obj_align(label, LV_ALIGN_CENTER, 0, 25);
        lv_obj_align(label_index, LV_ALIGN_CENTER, 0, 50);

        /* Add page index indicator and intialize pages to the first one in the sequence */
        page_index[i] = lv_imgbtn_create(lv_scr_act());

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
    /*Update the canvas position manually for first*/
    lv_obj_scroll_to_view(lv_obj_get_child(cont, 0), LV_ANIM_OFF);
}

#endif
