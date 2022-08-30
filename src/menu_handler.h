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

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    char * menu_name;
    void (* page_handler)(lv_obj_t *);
} menu_dispatch;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void device_handler(lv_obj_t *);
void oserver_handler(lv_obj_t *);
void files_handler(lv_obj_t *);
void email_handler(lv_obj_t *);
void contacts_handler(lv_obj_t *);
void calendar_handler(lv_obj_t *);
void text_handler(lv_obj_t *);
void music_handler(lv_obj_t *);
void settings_handler(lv_obj_t *);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*OSERVER_GUI_H*/