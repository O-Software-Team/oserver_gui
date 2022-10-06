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
#define OCO_CANVAS_WIDTH 385 /* match MONITOR_HOR_RES */
#define OCO_CANVAS_HEIGHT 510 /* match MONITOR_VER_RES */

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void oserver_gui(void);
void oserver_init(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*OSERVER_GUI_H*/
