#include "../oserver_gui_demo.h"
#include "oserver_gui.h"
#include "menu_handler.h"

#include <stdio.h>
#include <time.h>

// Forward

static void event_handler(lv_event_t *);
void calendar_init(lv_obj_t *);

LV_IMG_DECLARE(Background);

/* The init routine for` the 'root' page and it's children pages */
void calendar_menu_setup(void)
{
    printf("CALENDAR MENU setup...\n");
#if ALL_SCROLL
    lv_obj_t * calendar_page = lv_obj_create(NULL);
    menu_dispatch_table[DEVICE_VEC] = calendar_page;

    lv_obj_center(calendar_page);
    lv_obj_set_style_bg_color(calendar_page, lv_color_lighten(lv_color_black(), 60), 0);
    lv_obj_set_flex_flow(calendar_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_clip_corner(calendar_page, true, 3);
    lv_obj_set_scroll_dir(calendar_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(calendar_page, LV_SCROLL_SNAP_CENTER)
    lv_obj_set_scrollbar_mode(calendar_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* Store the content of this page for later display */

    /* SUB-SCREEN 0: Create already connected (trusted) devices page add it to parent */
    calendar_init(lotus_root_page);
#else
    lv_obj_t * lotus_root_page = lv_img_create(NULL);
    menu_dispatch_table[CALENDAR_VEC] = lotus_root_page;

    lv_obj_set_size(lotus_root_page, 385, 510); // Same as the simulator dislay
    lv_obj_set_style_bg_color(lotus_root_page, lv_color_lighten(lv_color_black(), 50), 0);
    lv_img_set_src(lotus_root_page, &Background);
    lv_obj_set_flex_flow(lotus_root_page, LV_FLEX_FLOW_ROW);
    lv_obj_set_scroll_dir(lotus_root_page, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(lotus_root_page, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(lotus_root_page, LV_OBJ_FLAG_SCROLL_ONE | LV_SCROLLBAR_MODE_OFF);

    /* Store the content of this page for later display */

    /* SUB-SCREEN 0: Create already connected (trusted) devices page add it to parent */
    calendar_init(lotus_root_page);
#endif // ALL_SCROLL
}

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_current_target(e);

    if(code == LV_EVENT_VALUE_CHANGED) {
        lv_calendar_date_t date;
        if(lv_calendar_get_pressed_date(obj, &date)) {
            LV_LOG_USER("Clicked date: %02d.%02d.%d", date.day, date.month, date.year);
        }
    }
}

void calendar_init(lv_obj_t * calendar_page) {

#if ALL_SCROLL
    lv_obj_t * image = lv_img_create(calendar_page);
    lv_img_set_src(image, &Background);
#else
    lv_obj_t * image = lv_img_create(calendar_page);
    lv_obj_set_size(image, 385, 510); // Same as the simulator dislay
    lv_obj_center(image);

#endif // ALL_SCROLL
    render_back_button(image, (back_button_cb_t)back_home_button_cb);

    time_t T;
    struct tm *t;
    T = time(NULL);
    t = localtime(&T);

    lv_obj_t  * calendar = lv_calendar_create(image);
    lv_obj_set_style_bg_opa(calendar, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_text_color(calendar, lv_color_white(), 0);
    lv_obj_set_style_border_width(calendar, 0, 0);

    lv_obj_set_size(calendar, 300, 420);
    lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 10);
    lv_obj_add_event_cb(calendar, event_handler, LV_EVENT_ALL, NULL);

    lv_calendar_set_today_date(calendar, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
    lv_calendar_set_showed_date(calendar, t->tm_year + 1900, t->tm_mday);

    /*
     * Highlight a few days
     */
    static lv_calendar_date_t highlighted_days[3];       /*Only its pointer will be saved so should be static*/
    highlighted_days[0].year = 2022;
    highlighted_days[0].month = 12;
    highlighted_days[0].day = 1;

    highlighted_days[1].year = 2022;
    highlighted_days[1].month = 11;
    highlighted_days[1].day = 11;

    highlighted_days[2].year = 2022;
    highlighted_days[2].month = 11;
    highlighted_days[2].day = 24;

    lv_calendar_set_highlighted_dates(calendar, highlighted_days, 3);
    // DAF lv_calendar_header_arrow_create(calendar);
    lv_calendar_set_showed_date(calendar, t->tm_year + 1900, t->tm_mon + 1);
}
