/*********************
 *      INCLUDES
 *********************/
//#include "../../lv_demo.h"
#include "../oserver_gui_demo.h"
#include "../../lvgl/src/misc/lv_color.h"
#include "../../lvgl/src/font/lv_font.h"
#include <inttypes.h>
#include <stdio.h>

#if LV_BUILD_EXAMPLES && LV_USE_FLEX
/* platform-specific printf format for int32_t, usually "d" or "ld" */
#define LV_PRId32 PRId32
#define LV_PRIu32 PRIu32

/* Product specific definitions */
#define OCO_PAGE_MAX 9
#define OCO_CANVAS_WIDTH 350
#define OCO_CANVAS_HEIGHT 450

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

char * menu_names[OCO_PAGE_MAX] = {
    "Devices",
    "O",
    "Files",
    "Email",
    "Contacts",
    "Calendar",
    "Text",
    "Music",
    "Settings",
};

uint16_t index_offset [OCO_PAGE_MAX] = {
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
 * Oserver base menu definitions
 */
void oserver_gui(void)
{
    lv_obj_t * cont = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cont, OCO_CANVAS_WIDTH - 50, OCO_CANVAS_HEIGHT - 60);
    lv_obj_center(cont);

    lv_obj_set_style_bg_color(cont, lv_color_lighten(lv_color_black(), 42), 0);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW);
    lv_obj_add_event_cb(cont, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(cont, true, 0);
    lv_obj_set_scroll_dir(cont, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(cont, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);

    /* Create the main page base images */
    uint32_t i;

    lv_obj_t * image;
    lv_obj_t * icon;

    lv_style_t image_style;
    lv_label_t * label;
    lv_label_t * label_index;
    lv_style_t label_style;
    lv_style_t btn_style;
    lv_style_init(&label_style);
    lv_style_init(&label_style);
    lv_style_init(&btn_style);

    for(i = 0; i < OCO_PAGE_MAX; i++) {
        image = lv_img_create(cont);
        lv_img_set_src(image, &Background_Menu_Yellow);
        lv_obj_set_style_bg_img_opa(image, 0, &image_style);

        /* Add page icon */
        icon = lv_img_create(image);
        lv_obj_center(icon);
        lv_img_set_src(icon, icon_images[i]);
        lv_obj_align(icon, LV_ALIGN_CENTER, 0, -40);

        label = lv_label_create(image);
        label_index = lv_label_create(image);
        lv_label_set_recolor(label_index, true);
        lv_label_set_recolor(label, true);

        /* Add the label name - can be localized */
        lv_label_set_text(label, menu_names[i]);
        lv_obj_set_style_text_color(label, lv_color_white(), 0);

        /* Add the page index number */
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
    lv_event_send(cont, LV_EVENT_SCROLL, NULL);

    /*Be sure the fist button is in the middle*/
    lv_obj_scroll_to_view(lv_obj_get_child(cont, 0), LV_ANIM_OFF);
}

#endif
