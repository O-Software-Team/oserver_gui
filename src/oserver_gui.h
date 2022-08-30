/**
 * @file oserver_gui.h
 *
 */

#ifndef OSERVER_GUI_H
#define OSERVER_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/
/* platform-specific printf format for int32_t, usually "d" or "ld" */
#define LV_PRId32 PRId32
#define LV_PRIu32 PRIu32

/* Product specific definitions */
#define OCO_PAGE_MAX 9
#define OCO_CANVAS_WIDTH 350
#define OCO_CANVAS_HEIGHT 450

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void oserver_gui(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*OSERVER_GUI_H*/
