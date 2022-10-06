#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"

LV_IMG_DECLARE(Icon_Back);

void back_home_button_cb(lv_event_t * e)
{
    printf("Back to main - clearing present\n");
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * parent = lv_obj_get_user_data(target);
    lv_obj_fade_in(lv_layer_top(), 0, 0);
    lv_obj_scroll_to_view(lv_obj_get_child(parent, 0), LV_ANIM_OFF);
    lv_disp_load_scr(menu_dispatch_table[MAIN_MENU_VEC]);
}

void back_button_cb(lv_event_t * e)
{
    printf("Back to main - sending SCROLL\n");
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * cont = lv_obj_get_user_data(target);

//    lv_event_send(cont, LV_EVENT_SCROLL, NULL);
}

/* 
 * Render back '<' with the text 'Back' - specific magic numbers to align
 * in the same place on each menu display
 */
void render_back_button(lv_obj_t * parent, void (* page_handler)(lv_obj_t *))
{
    /* 'Back' button onscreen image */
    lv_obj_t * back_image = lv_imgbtn_create(parent);
    lv_imgbtn_set_src(back_image, LV_IMGBTN_STATE_RELEASED, &Icon_Back, NULL, NULL);
    lv_obj_align(back_image, LV_ALIGN_TOP_LEFT, 25, 20);

    /* The 'Back' text */
    lv_obj_t * back_label = lv_label_create(parent);
    lv_label_set_recolor(back_label, true);
    lv_label_set_text(back_label, "Back");
    lv_obj_set_style_text_color(back_label, lv_color_white(), 0);
    lv_obj_align(back_label, LV_ALIGN_DEFAULT, 45, 23);

    /* 'Return' (back) button to previous button */
    lv_obj_t * back = lv_btn_create(parent);
    lv_obj_set_size(back, 50, 50);
    lv_obj_align(back, LV_ALIGN_DEFAULT, 30, 10);
    lv_obj_add_event_cb(back, page_handler, LV_EVENT_CLICKED, 0);
    lv_obj_set_user_data(back, lv_obj_get_parent(parent));
    lv_obj_set_style_opa(back, LV_OPA_0, LV_PART_MAIN);
}
