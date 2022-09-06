#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"

#include <stdio.h>

LV_IMG_DECLARE(Background);

static void click_return_cb(lv_event_t * e)
{
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * cont = lv_obj_get_user_data(target);
    lv_obj_del(cont);
}

void music_handler(lv_event_t * e)
{
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * cont = lv_obj_create(lv_obj_get_user_data(target));
    lv_obj_t * image = lv_img_create(cont);
    lv_obj_set_size(cont, OCO_CANVAS_WIDTH, OCO_CANVAS_HEIGHT);
    lv_obj_center(cont);
    lv_obj_set_scroll_dir(cont, LV_DIR_NONE);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_align(image, LV_ALIGN_CENTER, 0, 0);

    lv_img_set_src(image, &Background);

    /* Add return to previous button */
    lv_obj_t * btn = lv_btn_create(image);
    lv_obj_set_size(btn, 50, 50);
    lv_obj_align(btn, LV_ALIGN_DEFAULT, 30, 40);
    lv_obj_add_event_cb(btn, click_return_cb, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(btn, cont);
}