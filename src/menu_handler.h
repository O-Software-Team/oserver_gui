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

enum security {ADMIN = 0, FRIEND};

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    char * menu_name;
    void (* page_handler)(lv_obj_t *);
    bool active;
    enum security security_status;
    lv_img_dsc_t * icon;
} menu_item;

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

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*OSERVER_GUI_H*/
