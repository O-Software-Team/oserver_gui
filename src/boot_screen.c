#include <stdio.h>

#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

extern lv_obj_t * boot_screen;
extern void load_home_screen_cb(lv_event_t *);

/*
 * Display boot screen symbol
 */
void display_boot_screen(void)
{
    printf("BOOT SCREEN ...\n");

    LV_ASSERT(boot_screen == NULL);

    // Immediately turn off the page index circles.
    lv_obj_fade_out(lv_layer_top(), 0, 0);

    /*
     * B12230x385x510 is the 'O' metalic symbol on winding road background
     */
    lv_obj_t * boot_screen = lv_img_create(NULL);
    lv_img_set_src(boot_screen, &B12230x385x510);
    lv_obj_align(boot_screen, LV_ALIGN_TOP_MID, 0, 190);
    lv_obj_add_event_cb(boot_screen, load_home_screen_cb, LV_EVENT_SCREEN_LOADED, NULL);

    lv_scr_load_anim(boot_screen, LV_SCR_LOAD_ANIM_FADE_IN, 10000, 0, true);

}
