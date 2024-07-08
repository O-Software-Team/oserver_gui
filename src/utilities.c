#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"

#include <stdio.h>

/*
 * Generic routine to render a pixel wide horizontal line between two porints.
 * Caller responsible for proper coordinate position of points on the parent.
 */
void add_separator_line(lv_point_t *a, lv_point_t *b, lv_obj_t * parent)
{
    const lv_point_t lv_line_points[] = {
        *a,
        *b
    };

    int size = sizeof(lv_line_points) / (sizeof(lv_point_t));

    /*Create style*/
    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 1);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_line_rounded(&style_line, true);

    /*Create a line and apply the new style*/
    lv_obj_t * line1;
    line1 = lv_line_create(parent);
    lv_line_set_points(line1, lv_line_points, size);     /*Set end points*/
    lv_obj_add_style(line1, &style_line, 0);
    lv_obj_set_style_opa(line1, LV_OPA_40, 0);
}
