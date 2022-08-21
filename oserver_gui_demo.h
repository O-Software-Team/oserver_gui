/**
 * @file oserver_gui_demo.h
 *
 */

#ifndef OSERVER_GUI_DEMO_H
#define OSERVER_GUI_DEMO_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif

#if defined(LV_DEMO_CONF_PATH)
#define __LV_TO_STR_AUX(x) #x
#define __LV_TO_STR(x) __LV_TO_STR_AUX(x)
#include __LV_TO_STR(LV_DEMO_CONF_PATH)
#undef __LV_TO_STR_AUX
#undef __LV_TO_STR
#elif defined(LV_DEMO_CONF_INCLUDE_SIMPLE)
#include "lv_demo_conf.h"
#else
#include "../lv_demo_conf.h"
#endif

/*********************
 *      DEFINES
 *********************/
/*Test  lvgl version*/
#if LV_VERSION_CHECK(8, 0, 0) == 0
#error "oserver GUI demo: Wrong lvgl version"
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*OSERVER_GUI_DEMO_H*/
