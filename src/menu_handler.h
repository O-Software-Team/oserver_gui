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
typedef struct {
    char * menu_pre;
    char * menu_italic;
    int lx_offset;
    int mx_offset;
    int rx_offset;
    int email_id;
    char * email_message;
    char * email_from;
    char * email_subject;
    // void (* page_handler)(lv_obj_t *);
    lv_img_dsc_t * email_status;
    // bool active;
} email_item;

typedef struct {
    char * menu_pre;
    char * menu_italic;
    int lx_offset;
    int mx_offset;
    int rx_offset;
    int txtmsg_id;
    char * txtmsg_message;
    char * txtmsg_from;
    char * txtmsg_subject;
    // void (* page_handler)(lv_obj_t *);
    lv_img_dsc_t * txtmsg_status;
    // bool active;
} txtmsg_item;

enum security {ADMIN = 0, FRIEND};

typedef struct {
    char * menu_pre;
    char * menu_italic;
    int lx_offset;
    int mx_offset;
    int rx_offset;
    char * menu_post;
    void (* page_handler)(lv_obj_t *);
    bool active;
    bool onboard;
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
void oserver_menu_setup(void);
void file_menu_setup(void);
void email_menu_setup(void);
void contacts_menu_setup(void);
void calendar_menu_setup(void);
void txtmsg_menu_setup(void);
void music_menu_setup(void);
void settings_menu_setup(void);

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
