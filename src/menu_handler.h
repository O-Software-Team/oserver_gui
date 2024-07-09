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
// enum security {ADMIN = 0, FRIEND,};
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
    const lv_img_dsc_t * email_status;
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
    char * txtmsg_summary;
    // void (* page_handler)(lv_obj_t *);
    const lv_img_dsc_t * txtmsg_status;
    // bool active;
} txtmsg_item;

typedef struct {
    char * menu_pre;
    char * menu_italic;
    int lx_offset;
    int mx_offset;
    int rx_offset;
    char * contact_id;
    char * contact_fname;
    char * contact_lname;
    char * contact_name;
    char * contact_initials;
    char * contact_p_phone;
    char * contact_m_phone;
    char * contact_w_phone;
    char * contact_p_email;
    char * contact_w_email;
    char * contact_p_address;
    char * contact_w_address;
    char * contact_company_name;
    char * contact_notes;
    // char * contact_status;
    const lv_img_dsc_t * contact_status;
    void (* page_handler)(lv_obj_t *);
    // bool active;
} contacts_item;

typedef struct {
    char * menu_pre;
    char * menu_italic;
    int lx_offset;
    int mx_offset;
    int rx_offset;
    char * file_id;
    char * file_name;
    char * file_extension;
    char * file_fullname;
    char * file_type;
    char * file_size;
    char * file_location;
    char * file_permissions;
    char * file_created;
    char * file_modified;
    char * file_owner;
    char * file_group;
    char * file_visibility;
    char * file_info;
    const lv_img_dsc_t * file_icon;
    void (* page_handler)(lv_obj_t *);
    // bool active;
} filesystem_item;

typedef struct {
    char * menu_pre;
    char * menu_italic;
    int lx_offset;
    int mx_offset;
    int rx_offset;
    char * settings_id;
    char * settings_name;
    char * settings_admin;
    char * settings_group;
    char * settings_permissions;
    char * settings_type;
    bool   settings_state;
#define SETTINGS_STATE_ACTIVE   true
#define SETTINGS_STATE_DISABLED false
    char * settings_description;
    char * settings_summary;
    char * settings_info;
    const lv_img_dsc_t * settings_icon;
    lv_font_t * settings_font;
    // lv_color_t * settings_color;
    void (* page_handler)(lv_obj_t *);
    // lv_img_dsc_t * txtmsg_status;
    // bool active;
} settings_item;

enum security {ADMIN = 0, FRIEND};

// typedef struct {
//     char * menu_pre;
//     char * menu_italic;
//     int lx_offset;
//     int mx_offset;
//     int rx_offset;
//     char * menu_post;
//     void (* page_handler)(lv_obj_t *);
//     bool active;
//     bool onboard;
//     enum security security_status;
//     lv_img_dsc_t * icon;
// } menu_item;

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

typedef struct {
    char * menu_pre;
    char * menu_italic;
    int menu_vec;
    int lx;
    int mx;
    int rx;
    char * menu_post;
    void (* page_handler)(lv_obj_t *);
    bool active;
    bool onboard;
    enum security security_status;
    const lv_img_dsc_t * icon;
} menu_item;

// casting convenience typedef for use w/render_back_button()
typedef void (*back_button_cb_t)(lv_obj_t *);

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void home_screen_setup(void);

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
