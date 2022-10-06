/**
 * @file menu_handler.h
 *
 */

#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

#ifdef __cplusplus
extern "C" {
#endif

//  +--------------------+
//  |                    |
//  |                    |
//  |                    |
//  |                    |
//  |                    |
//  |                    |
//  +--------------------+

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/

#define DEVICE_MENU_VEC_MAX 10

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

enum menu_vector_index {
    MAIN_MENU_VEC = 0,
    DEVICE_VEC, // First Device menu
    OSERVER_VEC,
    FILES_VEC,
    EMAIL_VEC,
    CONTACTS_VEC,
    CALENDAR_VEC,
    TEXT_VEC,
    MUSIC_VEC,
    SETTINGS_VEC,
};

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void device_menu_setup(void);

void menu_dispatch(lv_event_t *);

void render_back_button(lv_obj_t *, void (*)(lv_obj_t *));
void back_home_button_cb(lv_event_t * e);
void back_button_cb(lv_event_t * e);

extern lv_obj_t * menu_dispatch_table[];

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*OSERVER_GUI_H*/
