#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"

#include <stdio.h>

LV_IMG_DECLARE(Background);

void calendar_menu_setup(void)
{
    lv_obj_t * calendar_page = lv_obj_create(NULL);
    lv_obj_t * background = lv_img_create(calendar_page);
    lv_img_set_src(background, &Background);

    printf("CALENDAR MENU init...\n");

    menu_dispatch_table[CALENDAR_VEC] = calendar_page;

    render_back_button(background, back_home_button_cb);
    lv_obj_center(calendar_page);
    lv_obj_set_style_bg_color(calendar_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(calendar_page, LV_FLEX_FLOW_ROW);
    //lv_obj_add_event_cb(calendar_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(calendar_page, true, 3);
    lv_obj_set_scroll_dir(calendar_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(calendar_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(calendar_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);
}
