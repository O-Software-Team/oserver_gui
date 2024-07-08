/**
 * @file utilities.h
 *
 */

#ifndef UTILITIES_H
#define UTILITIES_H

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

/**********************
 *      INLINES
 **********************/
/* Boolean check if a string is equal to "end" */
static inline int is_end(const char *str) {
    if (str && *str && !strcmp(str, "end")) {
        return 1;
    }
    return 0;
}

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void add_separator_line(lv_point_t *a, lv_point_t *b, lv_obj_t *parent );


/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*UTILITIES_H*/
