#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_ICON_BULLET_ITEM
#define LV_ATTRIBUTE_IMG_ICON_BULLET_ITEM
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_ICON_BULLET_ITEM uint8_t Icon_Bullet_Item_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0xf9, 0x1d, 0xf9, 0xac, 0xf9, 0xf2, 0xf9, 0xf2, 0xf9, 0xaf, 0xf9, 0x27, 0x00, 0x00, 
  0xf9, 0x1d, 0xf9, 0xed, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xee, 0xf9, 0x1d, 
  0xf9, 0xac, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xaa, 
  0xf9, 0xf2, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xf1, 
  0xf9, 0xf2, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xf0, 
  0xf9, 0xaf, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xa9, 
  0xf9, 0x27, 0xf9, 0xee, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xf9, 0xec, 0xf9, 0x1c, 
  0x00, 0x00, 0xf9, 0x1d, 0xf9, 0xaa, 0xf9, 0xf1, 0xf9, 0xf1, 0xf9, 0xa9, 0xf9, 0x1c, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0xc7, 0xdd, 0x1d, 0xc7, 0xdd, 0xac, 0xc7, 0xdd, 0xf2, 0xc7, 0xdd, 0xf2, 0xc7, 0xdd, 0xaf, 0xc7, 0xdd, 0x27, 0x00, 0x00, 0x00, 
  0xc7, 0xdd, 0x1d, 0xc7, 0xdd, 0xed, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xee, 0xc7, 0xdd, 0x1d, 
  0xc7, 0xdd, 0xac, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xaa, 
  0xc7, 0xdd, 0xf2, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xf1, 
  0xc7, 0xdd, 0xf2, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xf0, 
  0xc7, 0xdd, 0xaf, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xa9, 
  0xc7, 0xdd, 0x27, 0xc7, 0xdd, 0xee, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xff, 0xc7, 0xdd, 0xec, 0xc7, 0xdd, 0x1c, 
  0x00, 0x00, 0x00, 0xc7, 0xdd, 0x1d, 0xc7, 0xdd, 0xaa, 0xc7, 0xdd, 0xf1, 0xc7, 0xdd, 0xf1, 0xc7, 0xdd, 0xa9, 0xc7, 0xdd, 0x1c, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x00, 0xdd, 0xc7, 0x1d, 0xdd, 0xc7, 0xac, 0xdd, 0xc7, 0xf2, 0xdd, 0xc7, 0xf2, 0xdd, 0xc7, 0xaf, 0xdd, 0xc7, 0x27, 0x00, 0x00, 0x00, 
  0xdd, 0xc7, 0x1d, 0xdd, 0xc7, 0xed, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xee, 0xdd, 0xc7, 0x1d, 
  0xdd, 0xc7, 0xac, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xaa, 
  0xdd, 0xc7, 0xf2, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xf1, 
  0xdd, 0xc7, 0xf2, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xf0, 
  0xdd, 0xc7, 0xaf, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xa9, 
  0xdd, 0xc7, 0x27, 0xdd, 0xc7, 0xee, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xff, 0xdd, 0xc7, 0xec, 0xdd, 0xc7, 0x1c, 
  0x00, 0x00, 0x00, 0xdd, 0xc7, 0x1d, 0xdd, 0xc7, 0xaa, 0xdd, 0xc7, 0xf1, 0xdd, 0xc7, 0xf1, 0xdd, 0xc7, 0xa9, 0xdd, 0xc7, 0x1c, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  0x00, 0x00, 0x00, 0x00, 0x34, 0xb8, 0xdb, 0x1d, 0x35, 0xb9, 0xd8, 0xac, 0x34, 0xb9, 0xd8, 0xf2, 0x34, 0xb9, 0xd8, 0xf2, 0x34, 0xb9, 0xd7, 0xaf, 0x34, 0xb7, 0xd7, 0x27, 0x00, 0x00, 0x00, 0x00, 
  0x34, 0xb8, 0xdb, 0x1d, 0x34, 0xb9, 0xd8, 0xed, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x34, 0xb9, 0xd8, 0xee, 0x34, 0xb8, 0xdb, 0x1d, 
  0x35, 0xb9, 0xd8, 0xac, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x34, 0xb8, 0xd8, 0xaa, 
  0x34, 0xb9, 0xd8, 0xf2, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x34, 0xb9, 0xd7, 0xf1, 
  0x34, 0xb9, 0xd8, 0xf2, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb8, 0xd7, 0xf0, 
  0x34, 0xb9, 0xd7, 0xaf, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x34, 0xb9, 0xd7, 0xa9, 
  0x34, 0xb7, 0xd7, 0x27, 0x34, 0xb9, 0xd8, 0xee, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x35, 0xb9, 0xd8, 0xff, 0x34, 0xb8, 0xd8, 0xec, 0x36, 0xb6, 0xda, 0x1c, 
  0x00, 0x00, 0x00, 0x00, 0x34, 0xb8, 0xdb, 0x1d, 0x34, 0xb8, 0xd8, 0xaa, 0x34, 0xb9, 0xd7, 0xf1, 0x34, 0xb9, 0xd7, 0xf1, 0x34, 0xb9, 0xd7, 0xa9, 0x36, 0xb6, 0xda, 0x1c, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t Icon_Bullet_Item = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 8,
  .header.h = 8,
  .data_size = 64 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = Icon_Bullet_Item_map,
};
