/**
 * @file menu_handler.h
 *
 */

#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/

#define DEVICE_MENU_VEC_MAX 6

/**********************
 *      TYPEDEFS
 **********************/
enum security {ADMIN = 0, FRIEND};

typedef struct {
    char * menu_name;
    void (* page_handler)(lv_obj_t *);
    bool active;
    enum security security_status;
    lv_img_dsc_t * icon;
} menu_item;

enum device_index {
    MAIN_MENU_VEC = 0,
    DEVICE_HANDLER_VEC, // First Device menu 
    DEVICE_FOUND_VEC,
    DEVICE_CODE_VEC,
    DEVICE_CONNECTED_VEC,
};

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void device_handler(lv_event_t *);
void oserver_handler(lv_event_t *);
void files_handler(lv_event_t *);
void email_handler(lv_event_t *);
void contacts_handler(lv_event_t *);
void calendar_handler(lv_event_t *);
void text_handler(lv_event_t *);
void music_handler(lv_event_t *);
void settings_handler(lv_event_t *);

void render_back_button(lv_obj_t *, void (*)(lv_obj_t *));
void back_button_cb(lv_event_t * e);

extern lv_obj_t * menu_dispatch_table[];

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*OSERVER_GUI_H*/
