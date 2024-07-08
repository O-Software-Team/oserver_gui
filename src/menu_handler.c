#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"

#include <stdio.h>

lv_obj_t * menu_dispatch_table[DEVICE_MENU_VEC_MAX];

void menu_dispatch(lv_event_t * e) {
    lv_obj_t * target = lv_event_get_target(e);
    int menu_vec = (int)lv_obj_get_user_data(target);
    printf("Select submenu [%d]\n", menu_vec);
    lv_obj_fade_out(lv_layer_top(), 30, 0);
    lv_disp_load_scr(menu_dispatch_table[menu_vec]);
}
