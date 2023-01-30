#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"
#include "utilities.h"

#include <stdio.h>

extern lv_obj_t * boot_screen;

/*
 * Display boot screen symbol
 */
void display_boot_screen(void)
{
    printf("BOOT SCREEN ...\n");

    LV_ASSERT(boot_screen == NULL);
    boot_screen = lv_img_create(NULL);  // Assigned to GLOBAL

    lv_obj_set_size(boot_screen, 385, 510); // Same as the simulator dislay
    lv_img_set_src(boot_screen, &Background);

    // Immediately turn off the page index circles.
    lv_obj_fade_out(lv_layer_top(), 0, 0);
    /*
     * The 'O' metalic symbol
     */
    lv_obj_t * boot_screen_symbol = lv_img_create(boot_screen);
    lv_img_set_src(boot_screen_symbol, &Logo);
    lv_obj_align(boot_screen_symbol, LV_ALIGN_TOP_MID, 0, 190);

    lv_scr_load_anim(boot_screen, LV_SCR_LOAD_ANIM_FADE_IN, 500, 0, false);
    lv_obj_fade_out(boot_screen, 700, 3000);
}