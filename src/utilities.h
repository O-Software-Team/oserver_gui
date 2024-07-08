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

/* Boolean check for string equality: null pointer(s) are taken to be inequality
 * conditios (for now) 
 */
static inline int is_eq(const char *s1, const char *s2) {
    if (s1 && s2 && !strcmp(s1, s2)) {
        return 1;
    }
    return 0;
}

/* Boolean check if a string is equal to "end" */
static inline int is_end(const char *str) {
    return is_eq(str, "end");
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
