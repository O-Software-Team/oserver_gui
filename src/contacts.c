#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"

#include <stdio.h>

LV_IMG_DECLARE(Background);

void contacts_menu_setup(void)
{
    lv_obj_t * contacts_page = lv_obj_create(NULL);
    lv_obj_t * background = lv_img_create(contacts_page);
    lv_img_set_src(background, &Background);

    printf("CONTACTS MENU init...\n");

    menu_dispatch_table[CONTACTS_VEC] = contacts_page;

    render_back_button(background, back_home_button_cb);
    lv_obj_center(contacts_page);
    lv_obj_set_style_bg_color(contacts_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(contacts_page, LV_FLEX_FLOW_ROW);
    //lv_obj_add_event_cb(contacts_page, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    lv_obj_set_style_clip_corner(contacts_page, true, 3);
    lv_obj_set_scroll_dir(contacts_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(contacts_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(contacts_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);
}
