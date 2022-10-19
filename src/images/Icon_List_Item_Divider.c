#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_ICON_LIST_ITEM_DIVIDER
#define LV_ATTRIBUTE_IMG_ICON_LIST_ITEM_DIVIDER
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_ICON_LIST_ITEM_DIVIDER uint8_t Icon_List_Item_Divider_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0xff, 0x01, 0xda, 0x04, 0xb7, 0x06, 0xb6, 0x09, 0xdb, 0x0b, 0xda, 0x0e, 0xbb, 0x11, 0xd6, 0x13, 0xbb, 0x16, 0xd6, 0x18, 0xbb, 0x1b, 0xd6, 0x1d, 0xbb, 0x20, 0xd6, 0x22, 0xbb, 0x25, 0xd6, 0x28, 0xbb, 0x2a, 0xd6, 0x2d, 0xbb, 0x2f, 0xd6, 0x32, 0xbb, 0x34, 0xd6, 0x37, 0xbb, 0x39, 0xd6, 0x3c, 0xbb, 0x3e, 0xd6, 0x41, 0xbb, 0x44, 0xd6, 0x46, 0xbb, 0x49, 0xd6, 0x4b, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4d, 0xd6, 0x4d, 0xbb, 0x4b, 0xd6, 0x49, 0xbb, 0x46, 0xd6, 0x44, 0xbb, 0x41, 0xd6, 0x3e, 0xbb, 0x3c, 0xd6, 0x39, 0xbb, 0x37, 0xd6, 0x34, 0xbb, 0x32, 0xd6, 0x2f, 0xbb, 0x2d, 0xd6, 0x2a, 0xbb, 0x28, 0xd6, 0x25, 0xbb, 0x22, 0xd6, 0x20, 0xbb, 0x1d, 0xd6, 0x1b, 0xbb, 0x18, 0xd6, 0x16, 0xbb, 0x13, 0xb6, 0x11, 0xdb, 0x0e, 0xda, 0x0b, 0xb7, 0x09, 0xb6, 0x06, 0xda, 0x04, 0xff, 0x01, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0xff, 0xff, 0x01, 0x10, 0xc6, 0x04, 0x75, 0xad, 0x06, 0x55, 0xad, 0x09, 0xf4, 0xbd, 0x0b, 0xb5, 0xbd, 0x0e, 0xb4, 0xad, 0x11, 0x94, 0xb5, 0x13, 0x74, 0xb5, 0x16, 0xb4, 0xad, 0x18, 0xb4, 0xad, 0x1b, 0x95, 0xb5, 0x1d, 0x94, 0xb5, 0x20, 0xb5, 0xb5, 0x22, 0xb4, 0xad, 0x25, 0x74, 0xb5, 0x28, 0x94, 0xb5, 0x2a, 0x94, 0xad, 0x2d, 0xb4, 0xb5, 0x2f, 0xb5, 0xb5, 0x32, 0x94, 0xad, 0x34, 0x94, 0xb5, 0x37, 0xb4, 0xb5, 0x39, 0x94, 0xb5, 0x3c, 0x95, 0xad, 0x3e, 0x94, 0xb5, 0x41, 0x94, 0xad, 0x44, 0xb4, 0xb5, 0x46, 0x74, 0xad, 0x49, 0x94, 0xb5, 0x4b, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x94, 0xad, 0x4d, 0x94, 0xb5, 0x4d, 0x95, 0xad, 0x4b, 0x94, 0xb5, 0x49, 0x94, 0xb5, 0x46, 0x94, 0xad, 0x44, 0x94, 0xb5, 0x41, 0x95, 0xad, 0x3e, 0xb4, 0xb5, 0x3c, 0x94, 0xb5, 0x39, 0x94, 0xad, 0x37, 0x94, 0xb5, 0x34, 0xb4, 0xad, 0x32, 0xb4, 0xb5, 0x2f, 0x94, 0xad, 0x2d, 0x94, 0xb5, 0x2a, 0x74, 0xb5, 0x28, 0xb4, 0xad, 0x25, 0xb5, 0xb5, 0x22, 0x94, 0xb5, 0x20, 0x95, 0xb5, 0x1d, 0xb4, 0xad, 0x1b, 0xb4, 0xad, 0x18, 0x74, 0xb5, 0x16, 0x94, 0xb5, 0x13, 0xb5, 0xad, 0x11, 0xd4, 0xbd, 0x0e, 0xd4, 0xbd, 0x0b, 0x75, 0xad, 0x09, 0x55, 0xad, 0x06, 0x10, 0xc6, 0x04, 0xff, 0xff, 0x01, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0xff, 0xff, 0x01, 0xc6, 0x10, 0x04, 0xad, 0x75, 0x06, 0xad, 0x55, 0x09, 0xbd, 0xf4, 0x0b, 0xbd, 0xb5, 0x0e, 0xad, 0xb4, 0x11, 0xb5, 0x94, 0x13, 0xb5, 0x74, 0x16, 0xad, 0xb4, 0x18, 0xad, 0xb4, 0x1b, 0xb5, 0x95, 0x1d, 0xb5, 0x94, 0x20, 0xb5, 0xb5, 0x22, 0xad, 0xb4, 0x25, 0xb5, 0x74, 0x28, 0xb5, 0x94, 0x2a, 0xad, 0x94, 0x2d, 0xb5, 0xb4, 0x2f, 0xb5, 0xb5, 0x32, 0xad, 0x94, 0x34, 0xb5, 0x94, 0x37, 0xb5, 0xb4, 0x39, 0xb5, 0x94, 0x3c, 0xad, 0x95, 0x3e, 0xb5, 0x94, 0x41, 0xad, 0x94, 0x44, 0xb5, 0xb4, 0x46, 0xad, 0x74, 0x49, 0xb5, 0x94, 0x4b, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x94, 0x4d, 0xb5, 0x94, 0x4d, 0xad, 0x95, 0x4b, 0xb5, 0x94, 0x49, 0xb5, 0x94, 0x46, 0xad, 0x94, 0x44, 0xb5, 0x94, 0x41, 0xad, 0x95, 0x3e, 0xb5, 0xb4, 0x3c, 0xb5, 0x94, 0x39, 0xad, 0x94, 0x37, 0xb5, 0x94, 0x34, 0xad, 0xb4, 0x32, 0xb5, 0xb4, 0x2f, 0xad, 0x94, 0x2d, 0xb5, 0x94, 0x2a, 0xb5, 0x74, 0x28, 0xad, 0xb4, 0x25, 0xb5, 0xb5, 0x22, 0xb5, 0x94, 0x20, 0xb5, 0x95, 0x1d, 0xad, 0xb4, 0x1b, 0xad, 0xb4, 0x18, 0xb5, 0x74, 0x16, 0xb5, 0x94, 0x13, 0xad, 0xb5, 0x11, 0xbd, 0xd4, 0x0e, 0xbd, 0xd4, 0x0b, 0xad, 0x75, 0x09, 0xad, 0x55, 0x06, 0xc6, 0x10, 0x04, 0xff, 0xff, 0x01, 
#endif
#if LV_COLOR_DEPTH == 32
  0xff, 0xff, 0xff, 0x01, 0x7f, 0xbf, 0xbf, 0x04, 0xaa, 0xaa, 0xaa, 0x06, 0xaa, 0xaa, 0xaa, 0x09, 0xa2, 0xb9, 0xb9, 0x0b, 0xa3, 0xb6, 0xb6, 0x0e, 0xa5, 0xb4, 0xa5, 0x11, 0xa1, 0xae, 0xae, 0x13, 0xa2, 0xad, 0xad, 0x16, 0x9f, 0xb4, 0xaa, 0x18, 0xa0, 0xb3, 0xaa, 0x1b, 0xa7, 0xaf, 0xaf, 0x1d, 0x9f, 0xaf, 0xaf, 0x20, 0xa5, 0xb4, 0xac, 0x22, 0x9e, 0xb3, 0xac, 0x25, 0x9f, 0xac, 0xac, 0x28, 0xa3, 0xb0, 0xb0, 0x2a, 0x9e, 0xaf, 0xaa, 0x2d, 0xa2, 0xb3, 0xad, 0x2f, 0xa3, 0xb2, 0xad, 0x32, 0xa1, 0xb0, 0xab, 0x34, 0xa2, 0xb0, 0xab, 0x37, 0xa1, 0xb2, 0xae, 0x39, 0xa1, 0xb2, 0xae, 0x3c, 0xa4, 0xb0, 0xac, 0x3e, 0xa0, 0xb0, 0xac, 0x41, 0xa1, 0xb0, 0xac, 0x44, 0xa3, 0xb2, 0xae, 0x46, 0xa0, 0xae, 0xab, 0x49, 0xa3, 0xb0, 0xad, 0x4b, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa2, 0xaf, 0xac, 0x4d, 0xa3, 0xb0, 0xad, 0x4b, 0xa0, 0xae, 0xab, 0x49, 0xa3, 0xb2, 0xae, 0x46, 0xa1, 0xb0, 0xac, 0x44, 0xa0, 0xb0, 0xac, 0x41, 0xa4, 0xb0, 0xac, 0x3e, 0xa1, 0xb2, 0xae, 0x3c, 0xa1, 0xb2, 0xae, 0x39, 0xa2, 0xb0, 0xab, 0x37, 0xa1, 0xb0, 0xab, 0x34, 0xa3, 0xb2, 0xad, 0x32, 0xa2, 0xb3, 0xad, 0x2f, 0x9e, 0xaf, 0xaa, 0x2d, 0xa3, 0xb0, 0xb0, 0x2a, 0x9f, 0xac, 0xac, 0x28, 0x9e, 0xb3, 0xac, 0x25, 0xa5, 0xb4, 0xac, 0x22, 0x9f, 0xaf, 0xaf, 0x20, 0xa7, 0xaf, 0xaf, 0x1d, 0xa0, 0xb3, 0xaa, 0x1b, 0x9f, 0xb4, 0xaa, 0x18, 0xa2, 0xad, 0xad, 0x16, 0xa1, 0xae, 0xae, 0x13, 0xa5, 0xb4, 0xa5, 0x11, 0xa3, 0xb6, 0xb6, 0x0e, 0xa2, 0xb9, 0xb9, 0x0b, 0xaa, 0xaa, 0xaa, 0x09, 0xaa, 0xaa, 0xaa, 0x06, 0x7f, 0xbf, 0xbf, 0x04, 0xff, 0xff, 0xff, 0x01, 
#endif
};

const lv_img_dsc_t Icon_List_Item_Divider = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 322,
  .header.h = 1,
  .data_size = 322 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = Icon_List_Item_Divider_map,
};
