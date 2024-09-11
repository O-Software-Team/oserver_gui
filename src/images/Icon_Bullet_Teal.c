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

#ifndef LV_ATTRIBUTE_IMG_ICON_BULLET_TEAL
#define LV_ATTRIBUTE_IMG_ICON_BULLET_TEAL
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_ICON_BULLET_TEAL uint8_t Icon_Bullet_Teal_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x04, 0x29, 0x10, 0x2d, 0x1f, 0x2d, 0x2c, 0x2d, 0x35, 0x2d, 0x35, 0x2d, 0x2f, 0x2d, 0x23, 0x29, 0x14, 0x49, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x03, 0x2d, 0x18, 0x2d, 0x33, 0x2d, 0x41, 0x2d, 0x49, 0x2d, 0x50, 0x2d, 0x54, 0x2d, 0x56, 0x2d, 0x54, 0x2d, 0x4d, 0x2d, 0x45, 0x2d, 0x39, 0x2d, 0x1b, 0x0d, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2d, 0x0b, 0x2d, 0x28, 0x2d, 0x43, 0x2d, 0x53, 0x2d, 0x5f, 0x2d, 0x6a, 0x2d, 0x72, 0x2d, 0x78, 0x2d, 0x78, 0x2d, 0x73, 0x2d, 0x6e, 0x2d, 0x63, 0x2d, 0x56, 0x2d, 0x48, 0x2d, 0x2c, 0x2d, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x2d, 0x0b, 0x2d, 0x2d, 0x2d, 0x4b, 0x2d, 0x5d, 0x2d, 0x6d, 0x2d, 0x7b, 0x2d, 0x88, 0x2d, 0x91, 0x2d, 0x95, 0x2d, 0x94, 0x2d, 0x91, 0x2d, 0x87, 0x2d, 0x7c, 0x2d, 0x6e, 0x2d, 0x5f, 0x2d, 0x4f, 0x29, 0x31, 0x2d, 0x0c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x49, 0x04, 0x2d, 0x29, 0x2d, 0x4b, 0x2d, 0x5e, 0x2d, 0x72, 0x2d, 0x87, 0x2d, 0x96, 0x2d, 0xa3, 0x2d, 0xaa, 0x2d, 0xad, 0x2d, 0xab, 0x2d, 0xa4, 0x2d, 0x9b, 0x2d, 0x90, 0x2d, 0x83, 0x2d, 0x73, 0x2d, 0x62, 0x29, 0x51, 0x29, 0x2f, 0x09, 0x04, 0x00, 0x00, 
  0x00, 0x00, 0x2d, 0x1a, 0x2d, 0x45, 0x2d, 0x5a, 0x2d, 0x6f, 0x2d, 0x85, 0x2d, 0x99, 0x2d, 0xaa, 0x2d, 0xb8, 0x2d, 0xbe, 0x2d, 0xc1, 0x2d, 0xbd, 0x2d, 0xb6, 0x2d, 0xab, 0x2d, 0x9e, 0x2d, 0x8f, 0x2d, 0x81, 0x2d, 0x70, 0x29, 0x5e, 0x29, 0x4d, 0x29, 0x20, 0x00, 0x00, 
  0x4e, 0x05, 0x2d, 0x37, 0x2d, 0x50, 0x2d, 0x66, 0x2d, 0x7c, 0x2d, 0x93, 0x2d, 0xa8, 0x2d, 0xbb, 0x2d, 0xc9, 0x2d, 0xd0, 0x2d, 0xd2, 0x2d, 0xcd, 0x2d, 0xc6, 0x2d, 0xb9, 0x2d, 0xaa, 0x2d, 0x9a, 0x2d, 0x8a, 0x2d, 0x7a, 0x2d, 0x69, 0x2d, 0x59, 0x29, 0x43, 0x2d, 0x06, 
  0x2d, 0x15, 0x2d, 0x42, 0x2d, 0x58, 0x2d, 0x6e, 0x2d, 0x85, 0x2d, 0x9d, 0x2d, 0xb5, 0x2d, 0xc9, 0x2e, 0xd7, 0x37, 0xdf, 0x1b, 0xe1, 0x1b, 0xdb, 0x16, 0xd2, 0x2e, 0xc5, 0x2d, 0xb6, 0x2d, 0xa5, 0x2d, 0x92, 0x2d, 0x81, 0x29, 0x70, 0x29, 0x5e, 0x29, 0x4f, 0x29, 0x1c, 
  0x2d, 0x23, 0x2d, 0x47, 0x2d, 0x5c, 0x2d, 0x75, 0x2d, 0x8c, 0x2d, 0xa5, 0x2d, 0xbd, 0x2e, 0xd2, 0x1b, 0xe2, 0x1b, 0xeb, 0x1b, 0xec, 0x1b, 0xe7, 0x1b, 0xdd, 0x1b, 0xcf, 0x2e, 0xc0, 0x2d, 0xae, 0x2d, 0x9a, 0x2d, 0x86, 0x2d, 0x74, 0x2d, 0x62, 0x29, 0x52, 0x29, 0x2f, 
  0x2d, 0x31, 0x2d, 0x4a, 0x2d, 0x61, 0x2d, 0x79, 0x2d, 0x92, 0x2d, 0xaa, 0x2d, 0xc3, 0x36, 0xd8, 0x1b, 0xe7, 0x1b, 0xf1, 0x1b, 0xf4, 0x1b, 0xef, 0x1b, 0xe5, 0x1b, 0xd8, 0x17, 0xc7, 0x2d, 0xb4, 0x2d, 0xa0, 0x2d, 0x8b, 0x2d, 0x77, 0x2d, 0x65, 0x29, 0x54, 0x29, 0x3d, 
  0x2d, 0x38, 0x2d, 0x4c, 0x2d, 0x63, 0x2d, 0x7c, 0x2d, 0x95, 0x2d, 0xaf, 0x2d, 0xc6, 0x1b, 0xdb, 0x1b, 0xeb, 0x1b, 0xf5, 0x1b, 0xf8, 0x1b, 0xf4, 0x1b, 0xeb, 0x1b, 0xdd, 0x1b, 0xcc, 0x2d, 0xb8, 0x2d, 0xa3, 0x2d, 0x8e, 0x2d, 0x78, 0x2d, 0x65, 0x29, 0x55, 0x29, 0x43, 
  0x2d, 0x37, 0x2d, 0x4e, 0x2d, 0x65, 0x2d, 0x7e, 0x2d, 0x97, 0x2d, 0xb1, 0x2d, 0xc8, 0x1b, 0xdc, 0x1b, 0xec, 0x1b, 0xf6, 0x1b, 0xfa, 0x1b, 0xf7, 0x1b, 0xee, 0x1b, 0xe0, 0x1b, 0xce, 0x2d, 0xba, 0x2d, 0xa4, 0x2d, 0x8d, 0x2d, 0x78, 0x29, 0x65, 0x29, 0x53, 0x29, 0x42, 
  0x2d, 0x33, 0x2d, 0x4e, 0x2d, 0x66, 0x2d, 0x7f, 0x2d, 0x98, 0x2d, 0xb1, 0x2d, 0xc7, 0x37, 0xdd, 0x1b, 0xec, 0x1b, 0xf6, 0x1b, 0xf9, 0x1b, 0xf8, 0x1b, 0xef, 0x1b, 0xe0, 0x36, 0xcd, 0x2d, 0xb8, 0x2d, 0xa2, 0x2d, 0x8b, 0x2d, 0x75, 0x29, 0x61, 0x29, 0x50, 0x29, 0x39, 
  0x2d, 0x27, 0x2d, 0x4b, 0x2d, 0x63, 0x2d, 0x7d, 0x2d, 0x97, 0x2d, 0xb0, 0x2d, 0xc7, 0x2e, 0xda, 0x1b, 0xe9, 0x1b, 0xf3, 0x1b, 0xf7, 0x1b, 0xf4, 0x1b, 0xeb, 0x1b, 0xdc, 0x2e, 0xc9, 0x2d, 0xb3, 0x2d, 0x9d, 0x2d, 0x85, 0x2d, 0x70, 0x29, 0x5c, 0x29, 0x4b, 0x29, 0x2b, 
  0x29, 0x17, 0x2d, 0x47, 0x2d, 0x5f, 0x2d, 0x78, 0x2d, 0x92, 0x2d, 0xab, 0x2d, 0xc1, 0x2d, 0xd4, 0x2e, 0xe2, 0x36, 0xec, 0x1b, 0xef, 0x1b, 0xec, 0x17, 0xe2, 0x2d, 0xd2, 0x2d, 0xc0, 0x2d, 0xab, 0x2d, 0x94, 0x2d, 0x7e, 0x2d, 0x69, 0x29, 0x56, 0x29, 0x45, 0x29, 0x18, 
  0x2d, 0x06, 0x2d, 0x3f, 0x2d, 0x59, 0x2d, 0x72, 0x2d, 0x8a, 0x2d, 0xa1, 0x2d, 0xb7, 0x2d, 0xc9, 0x2d, 0xd6, 0x2d, 0xdf, 0x2d, 0xe1, 0x2d, 0xdc, 0x2d, 0xd3, 0x2d, 0xc4, 0x2d, 0xb2, 0x2d, 0x9e, 0x2d, 0x88, 0x29, 0x73, 0x29, 0x5f, 0x29, 0x4e, 0x29, 0x3b, 0x49, 0x05, 
  0x00, 0x00, 0x29, 0x20, 0x2d, 0x51, 0x2d, 0x66, 0x2d, 0x7e, 0x2d, 0x93, 0x2d, 0xa7, 0x2d, 0xb9, 0x2d, 0xc4, 0x2d, 0xcc, 0x2d, 0xcc, 0x2d, 0xc7, 0x2d, 0xbd, 0x2d, 0xb0, 0x2d, 0x9f, 0x2d, 0x8d, 0x2d, 0x79, 0x29, 0x67, 0x29, 0x55, 0x29, 0x45, 0x29, 0x1c, 0x00, 0x00, 
  0x00, 0x00, 0x4e, 0x05, 0x2d, 0x35, 0x2d, 0x5a, 0x2d, 0x6e, 0x2d, 0x82, 0x2d, 0x93, 0x2d, 0xa2, 0x2d, 0xac, 0x2d, 0xb3, 0x2d, 0xb2, 0x2d, 0xae, 0x2d, 0xa5, 0x2d, 0x99, 0x2d, 0x8a, 0x2d, 0x79, 0x2d, 0x69, 0x29, 0x58, 0x29, 0x48, 0x29, 0x2b, 0x0d, 0x03, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x2d, 0x0f, 0x29, 0x3a, 0x2d, 0x5c, 0x2d, 0x6c, 0x2d, 0x7b, 0x2d, 0x88, 0x2d, 0x90, 0x2d, 0x95, 0x2d, 0x95, 0x2d, 0x92, 0x2d, 0x8a, 0x2d, 0x7f, 0x2d, 0x72, 0x2d, 0x65, 0x29, 0x58, 0x29, 0x49, 0x29, 0x2e, 0x2d, 0x0c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0x0e, 0x2d, 0x35, 0x2d, 0x55, 0x2d, 0x61, 0x2d, 0x6c, 0x2d, 0x74, 0x2d, 0x78, 0x29, 0x77, 0x2d, 0x74, 0x2d, 0x6e, 0x2d, 0x65, 0x2d, 0x5b, 0x29, 0x50, 0x29, 0x44, 0x29, 0x29, 0x29, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x03, 0x2d, 0x1f, 0x29, 0x40, 0x29, 0x4d, 0x29, 0x54, 0x2d, 0x56, 0x2d, 0x58, 0x2d, 0x56, 0x29, 0x51, 0x29, 0x4b, 0x29, 0x44, 0x29, 0x37, 0x29, 0x1a, 0x0d, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x04, 0x2d, 0x16, 0x29, 0x25, 0x29, 0x32, 0x29, 0x38, 0x29, 0x37, 0x29, 0x30, 0x2d, 0x23, 0x29, 0x14, 0x09, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x42, 0x04, 0x8a, 0x22, 0x10, 0xaa, 0x22, 0x1f, 0x8a, 0x22, 0x2c, 0x8a, 0x22, 0x35, 0x8a, 0x22, 0x35, 0x8a, 0x22, 0x2f, 0x8a, 0x2a, 0x23, 0x6a, 0x2a, 0x14, 0x08, 0x42, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0x02, 0x03, 0xab, 0x22, 0x18, 0xaa, 0x22, 0x33, 0xca, 0x22, 0x41, 0xaa, 0x22, 0x49, 0xaa, 0x22, 0x50, 0x8a, 0x22, 0x54, 0xaa, 0x22, 0x56, 0x8a, 0x22, 0x54, 0xaa, 0x22, 0x4d, 0x8a, 0x22, 0x45, 0x8a, 0x22, 0x39, 0xa9, 0x22, 0x1b, 0xab, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe9, 0x32, 0x0b, 0xaa, 0x2a, 0x28, 0xaa, 0x22, 0x43, 0xca, 0x22, 0x53, 0xaa, 0x22, 0x5f, 0xaa, 0x22, 0x6a, 0xaa, 0x22, 0x72, 0xaa, 0x22, 0x78, 0xaa, 0x22, 0x78, 0xaa, 0x22, 0x73, 0xaa, 0x22, 0x6e, 0xaa, 0x22, 0x63, 0xaa, 0x22, 0x56, 0x8a, 0x22, 0x48, 0x89, 0x22, 0x2c, 0xab, 0x1a, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xec, 0x32, 0x0b, 0xaa, 0x2a, 0x2d, 0xaa, 0x2a, 0x4b, 0xaa, 0x22, 0x5d, 0xca, 0x22, 0x6d, 0xab, 0x22, 0x7b, 0xcb, 0x22, 0x88, 0xaa, 0x22, 0x91, 0xaa, 0x22, 0x95, 0xaa, 0x22, 0x94, 0xaa, 0x22, 0x91, 0xaa, 0x22, 0x87, 0xaa, 0x22, 0x7c, 0xaa, 0x22, 0x6e, 0xaa, 0x22, 0x5f, 0x8a, 0x22, 0x4f, 0x8a, 0x22, 0x31, 0xa8, 0x1a, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x08, 0x42, 0x04, 0xca, 0x2a, 0x29, 0xaa, 0x2a, 0x4b, 0xcb, 0x22, 0x5e, 0xaa, 0x22, 0x72, 0xca, 0x22, 0x87, 0xca, 0x22, 0x96, 0xca, 0x22, 0xa3, 0xcb, 0x22, 0xaa, 0xaa, 0x22, 0xad, 0xca, 0x22, 0xab, 0xaa, 0x22, 0xa4, 0xaa, 0x22, 0x9b, 0xaa, 0x22, 0x90, 0x8a, 0x22, 0x83, 0xaa, 0x22, 0x73, 0x8a, 0x22, 0x62, 0x89, 0x22, 0x51, 0x69, 0x1a, 0x2f, 0x08, 0x02, 0x04, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xca, 0x2a, 0x1a, 0xaa, 0x22, 0x45, 0xcb, 0x2a, 0x5a, 0xaa, 0x22, 0x6f, 0xcb, 0x22, 0x85, 0xca, 0x22, 0x99, 0xcb, 0x22, 0xaa, 0xab, 0x22, 0xb8, 0xcb, 0x22, 0xbe, 0xcb, 0x22, 0xc1, 0xca, 0x22, 0xbd, 0xaa, 0x22, 0xb6, 0xca, 0x22, 0xab, 0xaa, 0x22, 0x9e, 0xaa, 0x22, 0x8f, 0x8a, 0x22, 0x81, 0x8a, 0x22, 0x70, 0x8a, 0x22, 0x5e, 0x8a, 0x22, 0x4d, 0x89, 0x22, 0x20, 0x00, 0x00, 0x00, 
  0x4d, 0x33, 0x05, 0xaa, 0x2a, 0x37, 0xca, 0x2a, 0x50, 0xaa, 0x22, 0x66, 0xcb, 0x22, 0x7c, 0xcb, 0x22, 0x93, 0xcb, 0x22, 0xa8, 0xab, 0x22, 0xbb, 0xca, 0x22, 0xc9, 0xcb, 0x22, 0xd0, 0xcb, 0x22, 0xd2, 0xcb, 0x22, 0xcd, 0xcb, 0x22, 0xc6, 0xab, 0x22, 0xb9, 0xaa, 0x22, 0xaa, 0xaa, 0x22, 0x9a, 0x8a, 0x1a, 0x8a, 0x8a, 0x22, 0x7a, 0x8a, 0x22, 0x69, 0x8a, 0x22, 0x59, 0x6a, 0x1a, 0x43, 0xab, 0x2a, 0x06, 
  0xab, 0x2a, 0x15, 0xaa, 0x22, 0x42, 0xcb, 0x22, 0x58, 0xca, 0x22, 0x6e, 0xcb, 0x22, 0x85, 0xcb, 0x22, 0x9d, 0xcb, 0x22, 0xb5, 0xcb, 0x22, 0xc9, 0x2c, 0x23, 0xd7, 0x14, 0x15, 0xdf, 0xb7, 0x15, 0xe1, 0x18, 0x0e, 0xdb, 0x14, 0x15, 0xd2, 0x8e, 0x23, 0xc5, 0xeb, 0x22, 0xb6, 0xcb, 0x22, 0xa5, 0xaa, 0x22, 0x92, 0x8a, 0x22, 0x81, 0x8a, 0x1a, 0x70, 0x8a, 0x22, 0x5e, 0x6a, 0x22, 0x4f, 0x49, 0x1a, 0x1c, 
  0xca, 0x2a, 0x23, 0xca, 0x22, 0x47, 0xaa, 0x2a, 0x5c, 0xaa, 0x22, 0x75, 0xca, 0x22, 0x8c, 0xcb, 0x22, 0xa5, 0xcb, 0x22, 0xbd, 0x2c, 0x23, 0xd2, 0xf7, 0x15, 0xe2, 0x18, 0x0e, 0xeb, 0x18, 0x0e, 0xec, 0x18, 0x0e, 0xe7, 0x18, 0x0e, 0xdd, 0xf7, 0x0d, 0xcf, 0x4d, 0x1b, 0xc0, 0xcb, 0x22, 0xae, 0xaa, 0x22, 0x9a, 0x8a, 0x22, 0x86, 0x8a, 0x22, 0x74, 0x8a, 0x22, 0x62, 0x69, 0x1a, 0x52, 0x69, 0x1a, 0x2f, 
  0xaa, 0x2a, 0x31, 0xca, 0x22, 0x4a, 0xcb, 0x22, 0x61, 0xcb, 0x22, 0x79, 0xcb, 0x22, 0x92, 0xcb, 0x22, 0xaa, 0xca, 0x22, 0xc3, 0x14, 0x15, 0xd8, 0x18, 0x0e, 0xe7, 0x18, 0x0e, 0xf1, 0x18, 0x0e, 0xf4, 0x18, 0x0e, 0xef, 0x18, 0x0e, 0xe5, 0x18, 0x0e, 0xd8, 0x55, 0x15, 0xc7, 0xca, 0x22, 0xb4, 0xaa, 0x22, 0xa0, 0xaa, 0x1a, 0x8b, 0x8a, 0x22, 0x77, 0x8a, 0x1a, 0x65, 0x69, 0x1a, 0x54, 0x69, 0x22, 0x3d, 
  0xca, 0x2a, 0x38, 0xca, 0x2a, 0x4c, 0xab, 0x22, 0x63, 0xcb, 0x22, 0x7c, 0xcb, 0x22, 0x95, 0xcb, 0x22, 0xaf, 0xca, 0x22, 0xc6, 0x18, 0x0e, 0xdb, 0x18, 0x0e, 0xeb, 0x18, 0x0e, 0xf5, 0x18, 0x0e, 0xf8, 0x18, 0x0e, 0xf4, 0x18, 0x0e, 0xeb, 0x18, 0x0e, 0xdd, 0xf7, 0x0d, 0xcc, 0xaa, 0x22, 0xb8, 0xaa, 0x22, 0xa3, 0x8a, 0x22, 0x8e, 0x8a, 0x22, 0x78, 0x8a, 0x1a, 0x65, 0x89, 0x1a, 0x55, 0x69, 0x1a, 0x43, 
  0xaa, 0x2a, 0x37, 0xaa, 0x22, 0x4e, 0xaa, 0x22, 0x65, 0xcb, 0x22, 0x7e, 0xcb, 0x22, 0x97, 0xca, 0x22, 0xb1, 0xcb, 0x22, 0xc8, 0xd7, 0x0d, 0xdc, 0x18, 0x0e, 0xec, 0x18, 0x0e, 0xf6, 0x18, 0x0e, 0xfa, 0x18, 0x0e, 0xf7, 0x18, 0x0e, 0xee, 0x18, 0x0e, 0xe0, 0x18, 0x0e, 0xce, 0xaa, 0x22, 0xba, 0xaa, 0x1a, 0xa4, 0x8a, 0x1a, 0x8d, 0x8a, 0x1a, 0x78, 0x89, 0x1a, 0x65, 0x69, 0x1a, 0x53, 0x69, 0x1a, 0x42, 
  0xaa, 0x22, 0x33, 0xaa, 0x22, 0x4e, 0xcb, 0x22, 0x66, 0xcb, 0x22, 0x7f, 0xca, 0x22, 0x98, 0xca, 0x22, 0xb1, 0xab, 0x22, 0xc7, 0x55, 0x15, 0xdd, 0x18, 0x0e, 0xec, 0x18, 0x0e, 0xf6, 0x18, 0x0e, 0xf9, 0x18, 0x0e, 0xf8, 0x18, 0x0e, 0xef, 0x18, 0x0e, 0xe0, 0x14, 0x15, 0xcd, 0xaa, 0x22, 0xb8, 0x8a, 0x22, 0xa2, 0x8a, 0x1a, 0x8b, 0x8a, 0x22, 0x75, 0x8a, 0x1a, 0x61, 0x8a, 0x22, 0x50, 0x6a, 0x1a, 0x39, 
  0xaa, 0x2a, 0x27, 0xaa, 0x22, 0x4b, 0xaa, 0x22, 0x63, 0xaa, 0x22, 0x7d, 0xcb, 0x22, 0x97, 0xab, 0x22, 0xb0, 0xab, 0x22, 0xc7, 0x2c, 0x23, 0xda, 0xf7, 0x15, 0xe9, 0x18, 0x0e, 0xf3, 0x18, 0x0e, 0xf7, 0x18, 0x0e, 0xf4, 0x18, 0x0e, 0xeb, 0xd7, 0x0d, 0xdc, 0x0c, 0x1b, 0xc9, 0xaa, 0x22, 0xb3, 0x8a, 0x1a, 0x9d, 0x8a, 0x22, 0x85, 0x8a, 0x1a, 0x70, 0x69, 0x1a, 0x5c, 0x89, 0x1a, 0x4b, 0x69, 0x22, 0x2b, 
  0x6a, 0x22, 0x17, 0xaa, 0x22, 0x47, 0xaa, 0x22, 0x5f, 0xaa, 0x22, 0x78, 0xaa, 0x22, 0x92, 0xca, 0x22, 0xab, 0xab, 0x22, 0xc1, 0xcb, 0x22, 0xd4, 0x2c, 0x23, 0xe2, 0xf4, 0x14, 0xec, 0x18, 0x0e, 0xef, 0xd7, 0x0d, 0xec, 0x35, 0x15, 0xe2, 0x2c, 0x1b, 0xd2, 0xaa, 0x1a, 0xc0, 0xaa, 0x22, 0xab, 0x8a, 0x1a, 0x94, 0x8a, 0x22, 0x7e, 0x8a, 0x22, 0x69, 0x6a, 0x1a, 0x56, 0x69, 0x22, 0x45, 0x69, 0x22, 0x18, 
  0xab, 0x2a, 0x06, 0xaa, 0x22, 0x3f, 0xaa, 0x22, 0x59, 0xaa, 0x22, 0x72, 0xaa, 0x22, 0x8a, 0xaa, 0x22, 0xa1, 0xca, 0x22, 0xb7, 0xaa, 0x22, 0xc9, 0xaa, 0x22, 0xd6, 0xaa, 0x22, 0xdf, 0xaa, 0x22, 0xe1, 0xaa, 0x22, 0xdc, 0xaa, 0x22, 0xd3, 0xaa, 0x22, 0xc4, 0x8a, 0x22, 0xb2, 0xaa, 0x22, 0x9e, 0x8a, 0x22, 0x88, 0x8a, 0x22, 0x73, 0x6a, 0x1a, 0x5f, 0x89, 0x22, 0x4e, 0x69, 0x1a, 0x3b, 0xa6, 0x31, 0x05, 
  0x00, 0x00, 0x00, 0x8a, 0x22, 0x20, 0x8a, 0x22, 0x51, 0xaa, 0x22, 0x66, 0xaa, 0x22, 0x7e, 0xaa, 0x22, 0x93, 0xaa, 0x22, 0xa7, 0xaa, 0x22, 0xb9, 0xaa, 0x22, 0xc4, 0xaa, 0x22, 0xcc, 0xaa, 0x22, 0xcc, 0xaa, 0x22, 0xc7, 0xaa, 0x22, 0xbd, 0xaa, 0x22, 0xb0, 0x8a, 0x1a, 0x9f, 0x8a, 0x1a, 0x8d, 0x8a, 0x1a, 0x79, 0x8a, 0x1a, 0x67, 0x89, 0x1a, 0x55, 0x69, 0x1a, 0x45, 0x49, 0x1a, 0x1c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x4d, 0x33, 0x05, 0x8a, 0x22, 0x35, 0xaa, 0x22, 0x5a, 0xaa, 0x22, 0x6e, 0xaa, 0x22, 0x82, 0xaa, 0x22, 0x93, 0xaa, 0x22, 0xa2, 0xaa, 0x22, 0xac, 0xaa, 0x22, 0xb3, 0xaa, 0x22, 0xb2, 0xaa, 0x22, 0xae, 0x8a, 0x22, 0xa5, 0xaa, 0x22, 0x99, 0x8a, 0x22, 0x8a, 0x8a, 0x1a, 0x79, 0x8a, 0x22, 0x69, 0x89, 0x1a, 0x58, 0x69, 0x22, 0x48, 0x69, 0x22, 0x2b, 0xab, 0x02, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0x22, 0x0f, 0x8a, 0x22, 0x3a, 0xaa, 0x22, 0x5c, 0xaa, 0x22, 0x6c, 0xaa, 0x22, 0x7b, 0xaa, 0x22, 0x88, 0xaa, 0x22, 0x90, 0xaa, 0x22, 0x95, 0xaa, 0x22, 0x95, 0xaa, 0x22, 0x92, 0x8a, 0x22, 0x8a, 0x8a, 0x22, 0x7f, 0x8a, 0x22, 0x72, 0x8a, 0x1a, 0x65, 0x8a, 0x22, 0x58, 0x69, 0x1a, 0x49, 0x69, 0x1a, 0x2e, 0xa8, 0x1a, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x2a, 0x0e, 0x8a, 0x22, 0x35, 0x8a, 0x22, 0x55, 0x8a, 0x22, 0x61, 0xaa, 0x22, 0x6c, 0x8a, 0x22, 0x74, 0x8a, 0x22, 0x78, 0x8a, 0x22, 0x77, 0x8a, 0x22, 0x74, 0x8a, 0x22, 0x6e, 0x89, 0x1a, 0x65, 0x89, 0x22, 0x5b, 0x8a, 0x22, 0x50, 0x89, 0x1a, 0x44, 0x69, 0x22, 0x29, 0x29, 0x1a, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0x02, 0x03, 0xa9, 0x22, 0x1f, 0x8a, 0x22, 0x40, 0x8a, 0x22, 0x4d, 0x8a, 0x22, 0x54, 0x8a, 0x22, 0x56, 0x8a, 0x22, 0x58, 0x8a, 0x22, 0x56, 0x89, 0x22, 0x51, 0x8a, 0x22, 0x4b, 0x89, 0x22, 0x44, 0x89, 0x1a, 0x37, 0x8a, 0x22, 0x1a, 0xab, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x42, 0x04, 0x8a, 0x22, 0x16, 0x69, 0x1a, 0x25, 0x6a, 0x22, 0x32, 0x69, 0x1a, 0x38, 0x89, 0x1a, 0x37, 0x89, 0x22, 0x30, 0x89, 0x22, 0x23, 0x6a, 0x1a, 0x14, 0x08, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x08, 0x04, 0x22, 0x8a, 0x10, 0x22, 0xaa, 0x1f, 0x22, 0x8a, 0x2c, 0x22, 0x8a, 0x35, 0x22, 0x8a, 0x35, 0x22, 0x8a, 0x2f, 0x2a, 0x8a, 0x23, 0x2a, 0x6a, 0x14, 0x42, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xab, 0x03, 0x22, 0xab, 0x18, 0x22, 0xaa, 0x33, 0x22, 0xca, 0x41, 0x22, 0xaa, 0x49, 0x22, 0xaa, 0x50, 0x22, 0x8a, 0x54, 0x22, 0xaa, 0x56, 0x22, 0x8a, 0x54, 0x22, 0xaa, 0x4d, 0x22, 0x8a, 0x45, 0x22, 0x8a, 0x39, 0x22, 0xa9, 0x1b, 0x02, 0xab, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0xe9, 0x0b, 0x2a, 0xaa, 0x28, 0x22, 0xaa, 0x43, 0x22, 0xca, 0x53, 0x22, 0xaa, 0x5f, 0x22, 0xaa, 0x6a, 0x22, 0xaa, 0x72, 0x22, 0xaa, 0x78, 0x22, 0xaa, 0x78, 0x22, 0xaa, 0x73, 0x22, 0xaa, 0x6e, 0x22, 0xaa, 0x63, 0x22, 0xaa, 0x56, 0x22, 0x8a, 0x48, 0x22, 0x89, 0x2c, 0x1a, 0xab, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0xec, 0x0b, 0x2a, 0xaa, 0x2d, 0x2a, 0xaa, 0x4b, 0x22, 0xaa, 0x5d, 0x22, 0xca, 0x6d, 0x22, 0xab, 0x7b, 0x22, 0xcb, 0x88, 0x22, 0xaa, 0x91, 0x22, 0xaa, 0x95, 0x22, 0xaa, 0x94, 0x22, 0xaa, 0x91, 0x22, 0xaa, 0x87, 0x22, 0xaa, 0x7c, 0x22, 0xaa, 0x6e, 0x22, 0xaa, 0x5f, 0x22, 0x8a, 0x4f, 0x22, 0x8a, 0x31, 0x1a, 0xa8, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x42, 0x08, 0x04, 0x2a, 0xca, 0x29, 0x2a, 0xaa, 0x4b, 0x22, 0xcb, 0x5e, 0x22, 0xaa, 0x72, 0x22, 0xca, 0x87, 0x22, 0xca, 0x96, 0x22, 0xca, 0xa3, 0x22, 0xcb, 0xaa, 0x22, 0xaa, 0xad, 0x22, 0xca, 0xab, 0x22, 0xaa, 0xa4, 0x22, 0xaa, 0x9b, 0x22, 0xaa, 0x90, 0x22, 0x8a, 0x83, 0x22, 0xaa, 0x73, 0x22, 0x8a, 0x62, 0x22, 0x89, 0x51, 0x1a, 0x69, 0x2f, 0x02, 0x08, 0x04, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x2a, 0xca, 0x1a, 0x22, 0xaa, 0x45, 0x2a, 0xcb, 0x5a, 0x22, 0xaa, 0x6f, 0x22, 0xcb, 0x85, 0x22, 0xca, 0x99, 0x22, 0xcb, 0xaa, 0x22, 0xab, 0xb8, 0x22, 0xcb, 0xbe, 0x22, 0xcb, 0xc1, 0x22, 0xca, 0xbd, 0x22, 0xaa, 0xb6, 0x22, 0xca, 0xab, 0x22, 0xaa, 0x9e, 0x22, 0xaa, 0x8f, 0x22, 0x8a, 0x81, 0x22, 0x8a, 0x70, 0x22, 0x8a, 0x5e, 0x22, 0x8a, 0x4d, 0x22, 0x89, 0x20, 0x00, 0x00, 0x00, 
  0x33, 0x4d, 0x05, 0x2a, 0xaa, 0x37, 0x2a, 0xca, 0x50, 0x22, 0xaa, 0x66, 0x22, 0xcb, 0x7c, 0x22, 0xcb, 0x93, 0x22, 0xcb, 0xa8, 0x22, 0xab, 0xbb, 0x22, 0xca, 0xc9, 0x22, 0xcb, 0xd0, 0x22, 0xcb, 0xd2, 0x22, 0xcb, 0xcd, 0x22, 0xcb, 0xc6, 0x22, 0xab, 0xb9, 0x22, 0xaa, 0xaa, 0x22, 0xaa, 0x9a, 0x1a, 0x8a, 0x8a, 0x22, 0x8a, 0x7a, 0x22, 0x8a, 0x69, 0x22, 0x8a, 0x59, 0x1a, 0x6a, 0x43, 0x2a, 0xab, 0x06, 
  0x2a, 0xab, 0x15, 0x22, 0xaa, 0x42, 0x22, 0xcb, 0x58, 0x22, 0xca, 0x6e, 0x22, 0xcb, 0x85, 0x22, 0xcb, 0x9d, 0x22, 0xcb, 0xb5, 0x22, 0xcb, 0xc9, 0x23, 0x2c, 0xd7, 0x15, 0x14, 0xdf, 0x15, 0xb7, 0xe1, 0x0e, 0x18, 0xdb, 0x15, 0x14, 0xd2, 0x23, 0x8e, 0xc5, 0x22, 0xeb, 0xb6, 0x22, 0xcb, 0xa5, 0x22, 0xaa, 0x92, 0x22, 0x8a, 0x81, 0x1a, 0x8a, 0x70, 0x22, 0x8a, 0x5e, 0x22, 0x6a, 0x4f, 0x1a, 0x49, 0x1c, 
  0x2a, 0xca, 0x23, 0x22, 0xca, 0x47, 0x2a, 0xaa, 0x5c, 0x22, 0xaa, 0x75, 0x22, 0xca, 0x8c, 0x22, 0xcb, 0xa5, 0x22, 0xcb, 0xbd, 0x23, 0x2c, 0xd2, 0x15, 0xf7, 0xe2, 0x0e, 0x18, 0xeb, 0x0e, 0x18, 0xec, 0x0e, 0x18, 0xe7, 0x0e, 0x18, 0xdd, 0x0d, 0xf7, 0xcf, 0x1b, 0x4d, 0xc0, 0x22, 0xcb, 0xae, 0x22, 0xaa, 0x9a, 0x22, 0x8a, 0x86, 0x22, 0x8a, 0x74, 0x22, 0x8a, 0x62, 0x1a, 0x69, 0x52, 0x1a, 0x69, 0x2f, 
  0x2a, 0xaa, 0x31, 0x22, 0xca, 0x4a, 0x22, 0xcb, 0x61, 0x22, 0xcb, 0x79, 0x22, 0xcb, 0x92, 0x22, 0xcb, 0xaa, 0x22, 0xca, 0xc3, 0x15, 0x14, 0xd8, 0x0e, 0x18, 0xe7, 0x0e, 0x18, 0xf1, 0x0e, 0x18, 0xf4, 0x0e, 0x18, 0xef, 0x0e, 0x18, 0xe5, 0x0e, 0x18, 0xd8, 0x15, 0x55, 0xc7, 0x22, 0xca, 0xb4, 0x22, 0xaa, 0xa0, 0x1a, 0xaa, 0x8b, 0x22, 0x8a, 0x77, 0x1a, 0x8a, 0x65, 0x1a, 0x69, 0x54, 0x22, 0x69, 0x3d, 
  0x2a, 0xca, 0x38, 0x2a, 0xca, 0x4c, 0x22, 0xab, 0x63, 0x22, 0xcb, 0x7c, 0x22, 0xcb, 0x95, 0x22, 0xcb, 0xaf, 0x22, 0xca, 0xc6, 0x0e, 0x18, 0xdb, 0x0e, 0x18, 0xeb, 0x0e, 0x18, 0xf5, 0x0e, 0x18, 0xf8, 0x0e, 0x18, 0xf4, 0x0e, 0x18, 0xeb, 0x0e, 0x18, 0xdd, 0x0d, 0xf7, 0xcc, 0x22, 0xaa, 0xb8, 0x22, 0xaa, 0xa3, 0x22, 0x8a, 0x8e, 0x22, 0x8a, 0x78, 0x1a, 0x8a, 0x65, 0x1a, 0x89, 0x55, 0x1a, 0x69, 0x43, 
  0x2a, 0xaa, 0x37, 0x22, 0xaa, 0x4e, 0x22, 0xaa, 0x65, 0x22, 0xcb, 0x7e, 0x22, 0xcb, 0x97, 0x22, 0xca, 0xb1, 0x22, 0xcb, 0xc8, 0x0d, 0xd7, 0xdc, 0x0e, 0x18, 0xec, 0x0e, 0x18, 0xf6, 0x0e, 0x18, 0xfa, 0x0e, 0x18, 0xf7, 0x0e, 0x18, 0xee, 0x0e, 0x18, 0xe0, 0x0e, 0x18, 0xce, 0x22, 0xaa, 0xba, 0x1a, 0xaa, 0xa4, 0x1a, 0x8a, 0x8d, 0x1a, 0x8a, 0x78, 0x1a, 0x89, 0x65, 0x1a, 0x69, 0x53, 0x1a, 0x69, 0x42, 
  0x22, 0xaa, 0x33, 0x22, 0xaa, 0x4e, 0x22, 0xcb, 0x66, 0x22, 0xcb, 0x7f, 0x22, 0xca, 0x98, 0x22, 0xca, 0xb1, 0x22, 0xab, 0xc7, 0x15, 0x55, 0xdd, 0x0e, 0x18, 0xec, 0x0e, 0x18, 0xf6, 0x0e, 0x18, 0xf9, 0x0e, 0x18, 0xf8, 0x0e, 0x18, 0xef, 0x0e, 0x18, 0xe0, 0x15, 0x14, 0xcd, 0x22, 0xaa, 0xb8, 0x22, 0x8a, 0xa2, 0x1a, 0x8a, 0x8b, 0x22, 0x8a, 0x75, 0x1a, 0x8a, 0x61, 0x22, 0x8a, 0x50, 0x1a, 0x6a, 0x39, 
  0x2a, 0xaa, 0x27, 0x22, 0xaa, 0x4b, 0x22, 0xaa, 0x63, 0x22, 0xaa, 0x7d, 0x22, 0xcb, 0x97, 0x22, 0xab, 0xb0, 0x22, 0xab, 0xc7, 0x23, 0x2c, 0xda, 0x15, 0xf7, 0xe9, 0x0e, 0x18, 0xf3, 0x0e, 0x18, 0xf7, 0x0e, 0x18, 0xf4, 0x0e, 0x18, 0xeb, 0x0d, 0xd7, 0xdc, 0x1b, 0x0c, 0xc9, 0x22, 0xaa, 0xb3, 0x1a, 0x8a, 0x9d, 0x22, 0x8a, 0x85, 0x1a, 0x8a, 0x70, 0x1a, 0x69, 0x5c, 0x1a, 0x89, 0x4b, 0x22, 0x69, 0x2b, 
  0x22, 0x6a, 0x17, 0x22, 0xaa, 0x47, 0x22, 0xaa, 0x5f, 0x22, 0xaa, 0x78, 0x22, 0xaa, 0x92, 0x22, 0xca, 0xab, 0x22, 0xab, 0xc1, 0x22, 0xcb, 0xd4, 0x23, 0x2c, 0xe2, 0x14, 0xf4, 0xec, 0x0e, 0x18, 0xef, 0x0d, 0xd7, 0xec, 0x15, 0x35, 0xe2, 0x1b, 0x2c, 0xd2, 0x1a, 0xaa, 0xc0, 0x22, 0xaa, 0xab, 0x1a, 0x8a, 0x94, 0x22, 0x8a, 0x7e, 0x22, 0x8a, 0x69, 0x1a, 0x6a, 0x56, 0x22, 0x69, 0x45, 0x22, 0x69, 0x18, 
  0x2a, 0xab, 0x06, 0x22, 0xaa, 0x3f, 0x22, 0xaa, 0x59, 0x22, 0xaa, 0x72, 0x22, 0xaa, 0x8a, 0x22, 0xaa, 0xa1, 0x22, 0xca, 0xb7, 0x22, 0xaa, 0xc9, 0x22, 0xaa, 0xd6, 0x22, 0xaa, 0xdf, 0x22, 0xaa, 0xe1, 0x22, 0xaa, 0xdc, 0x22, 0xaa, 0xd3, 0x22, 0xaa, 0xc4, 0x22, 0x8a, 0xb2, 0x22, 0xaa, 0x9e, 0x22, 0x8a, 0x88, 0x22, 0x8a, 0x73, 0x1a, 0x6a, 0x5f, 0x22, 0x89, 0x4e, 0x1a, 0x69, 0x3b, 0x31, 0xa6, 0x05, 
  0x00, 0x00, 0x00, 0x22, 0x8a, 0x20, 0x22, 0x8a, 0x51, 0x22, 0xaa, 0x66, 0x22, 0xaa, 0x7e, 0x22, 0xaa, 0x93, 0x22, 0xaa, 0xa7, 0x22, 0xaa, 0xb9, 0x22, 0xaa, 0xc4, 0x22, 0xaa, 0xcc, 0x22, 0xaa, 0xcc, 0x22, 0xaa, 0xc7, 0x22, 0xaa, 0xbd, 0x22, 0xaa, 0xb0, 0x1a, 0x8a, 0x9f, 0x1a, 0x8a, 0x8d, 0x1a, 0x8a, 0x79, 0x1a, 0x8a, 0x67, 0x1a, 0x89, 0x55, 0x1a, 0x69, 0x45, 0x1a, 0x49, 0x1c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x33, 0x4d, 0x05, 0x22, 0x8a, 0x35, 0x22, 0xaa, 0x5a, 0x22, 0xaa, 0x6e, 0x22, 0xaa, 0x82, 0x22, 0xaa, 0x93, 0x22, 0xaa, 0xa2, 0x22, 0xaa, 0xac, 0x22, 0xaa, 0xb3, 0x22, 0xaa, 0xb2, 0x22, 0xaa, 0xae, 0x22, 0x8a, 0xa5, 0x22, 0xaa, 0x99, 0x22, 0x8a, 0x8a, 0x1a, 0x8a, 0x79, 0x22, 0x8a, 0x69, 0x1a, 0x89, 0x58, 0x22, 0x69, 0x48, 0x22, 0x69, 0x2b, 0x02, 0xab, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0xab, 0x0f, 0x22, 0x8a, 0x3a, 0x22, 0xaa, 0x5c, 0x22, 0xaa, 0x6c, 0x22, 0xaa, 0x7b, 0x22, 0xaa, 0x88, 0x22, 0xaa, 0x90, 0x22, 0xaa, 0x95, 0x22, 0xaa, 0x95, 0x22, 0xaa, 0x92, 0x22, 0x8a, 0x8a, 0x22, 0x8a, 0x7f, 0x22, 0x8a, 0x72, 0x1a, 0x8a, 0x65, 0x22, 0x8a, 0x58, 0x1a, 0x69, 0x49, 0x1a, 0x69, 0x2e, 0x1a, 0xa8, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0x49, 0x0e, 0x22, 0x8a, 0x35, 0x22, 0x8a, 0x55, 0x22, 0x8a, 0x61, 0x22, 0xaa, 0x6c, 0x22, 0x8a, 0x74, 0x22, 0x8a, 0x78, 0x22, 0x8a, 0x77, 0x22, 0x8a, 0x74, 0x22, 0x8a, 0x6e, 0x1a, 0x89, 0x65, 0x22, 0x89, 0x5b, 0x22, 0x8a, 0x50, 0x1a, 0x89, 0x44, 0x22, 0x69, 0x29, 0x1a, 0x29, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xab, 0x03, 0x22, 0xa9, 0x1f, 0x22, 0x8a, 0x40, 0x22, 0x8a, 0x4d, 0x22, 0x8a, 0x54, 0x22, 0x8a, 0x56, 0x22, 0x8a, 0x58, 0x22, 0x8a, 0x56, 0x22, 0x89, 0x51, 0x22, 0x8a, 0x4b, 0x22, 0x89, 0x44, 0x1a, 0x89, 0x37, 0x22, 0x8a, 0x1a, 0x02, 0xab, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x08, 0x04, 0x22, 0x8a, 0x16, 0x1a, 0x69, 0x25, 0x22, 0x6a, 0x32, 0x1a, 0x69, 0x38, 0x1a, 0x89, 0x37, 0x22, 0x89, 0x30, 0x22, 0x89, 0x23, 0x1a, 0x6a, 0x14, 0x02, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x04, 0x4f, 0x4f, 0x1f, 0x10, 0x52, 0x52, 0x20, 0x1f, 0x51, 0x51, 0x22, 0x2c, 0x51, 0x51, 0x21, 0x35, 0x51, 0x51, 0x21, 0x35, 0x51, 0x51, 0x20, 0x2f, 0x50, 0x50, 0x24, 0x23, 0x4c, 0x4c, 0x26, 0x14, 0x3f, 0x3f, 0x3f, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x00, 0x03, 0x55, 0x55, 0x1f, 0x18, 0x50, 0x55, 0x23, 0x33, 0x52, 0x56, 0x23, 0x41, 0x50, 0x53, 0x22, 0x49, 0x4f, 0x52, 0x1f, 0x50, 0x51, 0x51, 0x21, 0x54, 0x50, 0x53, 0x20, 0x56, 0x4e, 0x51, 0x21, 0x54, 0x4f, 0x52, 0x21, 0x4d, 0x51, 0x51, 0x21, 0x45, 0x50, 0x50, 0x1f, 0x39, 0x4b, 0x55, 0x1c, 0x1b, 0x55, 0x55, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x5c, 0x2e, 0x0b, 0x52, 0x52, 0x26, 0x28, 0x4f, 0x53, 0x22, 0x43, 0x52, 0x56, 0x21, 0x53, 0x53, 0x55, 0x20, 0x5f, 0x51, 0x54, 0x21, 0x6a, 0x52, 0x55, 0x21, 0x72, 0x52, 0x55, 0x1f, 0x78, 0x52, 0x55, 0x22, 0x78, 0x52, 0x54, 0x1f, 0x73, 0x51, 0x53, 0x20, 0x6e, 0x4f, 0x52, 0x1e, 0x63, 0x50, 0x53, 0x1d, 0x56, 0x4d, 0x51, 0x1f, 0x48, 0x4b, 0x51, 0x1c, 0x2c, 0x55, 0x55, 0x15, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x5c, 0x2e, 0x0b, 0x4f, 0x55, 0x27, 0x2d, 0x51, 0x55, 0x25, 0x4b, 0x52, 0x55, 0x20, 0x5d, 0x51, 0x56, 0x23, 0x6d, 0x55, 0x55, 0x21, 0x7b, 0x54, 0x56, 0x21, 0x88, 0x52, 0x54, 0x1f, 0x91, 0x53, 0x55, 0x20, 0x95, 0x52, 0x54, 0x20, 0x94, 0x52, 0x54, 0x1f, 0x91, 0x51, 0x53, 0x1e, 0x87, 0x50, 0x54, 0x20, 0x7c, 0x51, 0x53, 0x20, 0x6e, 0x4d, 0x53, 0x1d, 0x5f, 0x4d, 0x50, 0x1d, 0x4f, 0x4e, 0x4e, 0x1f, 0x31, 0x3f, 0x55, 0x15, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x04, 0x50, 0x57, 0x25, 0x29, 0x51, 0x55, 0x25, 0x4b, 0x54, 0x56, 0x23, 0x5e, 0x52, 0x55, 0x21, 0x72, 0x53, 0x56, 0x20, 0x87, 0x53, 0x56, 0x20, 0x96, 0x52, 0x56, 0x1f, 0xa3, 0x54, 0x57, 0x1f, 0xaa, 0x52, 0x55, 0x20, 0xad, 0x53, 0x56, 0x1f, 0xab, 0x52, 0x55, 0x20, 0xa4, 0x52, 0x53, 0x1f, 0x9b, 0x51, 0x53, 0x1f, 0x90, 0x4f, 0x51, 0x1d, 0x83, 0x4f, 0x52, 0x1f, 0x73, 0x4e, 0x50, 0x1f, 0x62, 0x4b, 0x4e, 0x1f, 0x51, 0x4b, 0x4b, 0x1b, 0x2f, 0x3f, 0x3f, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x4e, 0x58, 0x27, 0x1a, 0x51, 0x55, 0x21, 0x45, 0x55, 0x57, 0x24, 0x5a, 0x52, 0x55, 0x20, 0x6f, 0x54, 0x56, 0x22, 0x85, 0x53, 0x56, 0x21, 0x99, 0x54, 0x57, 0x21, 0xaa, 0x54, 0x55, 0x1f, 0xb8, 0x54, 0x58, 0x21, 0xbe, 0x54, 0x57, 0x1f, 0xc1, 0x53, 0x56, 0x20, 0xbd, 0x51, 0x54, 0x1d, 0xb6, 0x53, 0x56, 0x1f, 0xab, 0x52, 0x55, 0x1e, 0x9e, 0x50, 0x53, 0x1c, 0x8f, 0x4f, 0x51, 0x1d, 0x81, 0x4f, 0x51, 0x1d, 0x70, 0x4e, 0x4e, 0x1d, 0x5e, 0x4c, 0x4f, 0x1d, 0x4d, 0x47, 0x4f, 0x1f, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x66, 0x66, 0x33, 0x05, 0x53, 0x53, 0x25, 0x37, 0x52, 0x56, 0x26, 0x50, 0x52, 0x55, 0x23, 0x66, 0x54, 0x56, 0x22, 0x7c, 0x55, 0x58, 0x22, 0x93, 0x55, 0x58, 0x21, 0xa8, 0x54, 0x55, 0x1f, 0xbb, 0x53, 0x56, 0x1f, 0xc9, 0x55, 0x59, 0x1e, 0xd0, 0x57, 0x59, 0x1f, 0xd2, 0x57, 0x59, 0x20, 0xcd, 0x56, 0x57, 0x1e, 0xc6, 0x54, 0x55, 0x1f, 0xb9, 0x4f, 0x52, 0x1c, 0xaa, 0x51, 0x52, 0x1d, 0x9a, 0x4f, 0x51, 0x1b, 0x8a, 0x4f, 0x51, 0x1d, 0x7a, 0x50, 0x50, 0x1d, 0x69, 0x4d, 0x50, 0x1c, 0x59, 0x4c, 0x4c, 0x1a, 0x43, 0x55, 0x55, 0x2a, 0x06, 
  0x55, 0x55, 0x24, 0x15, 0x51, 0x55, 0x22, 0x42, 0x54, 0x56, 0x22, 0x58, 0x53, 0x58, 0x22, 0x6e, 0x54, 0x56, 0x22, 0x85, 0x54, 0x57, 0x20, 0x9d, 0x54, 0x57, 0x20, 0xb5, 0x55, 0x58, 0x20, 0xc9, 0x62, 0x64, 0x1c, 0xd7, 0xa1, 0xa1, 0x10, 0xdf, 0xb5, 0xb5, 0x0c, 0xe1, 0xc0, 0xc0, 0x0a, 0xdb, 0x9d, 0x9f, 0x0f, 0xd2, 0x6e, 0x6f, 0x1c, 0xc5, 0x59, 0x5b, 0x1d, 0xb6, 0x56, 0x59, 0x1d, 0xa5, 0x53, 0x55, 0x1d, 0x92, 0x4f, 0x51, 0x1d, 0x81, 0x4d, 0x4f, 0x1b, 0x70, 0x4e, 0x4e, 0x1d, 0x5e, 0x4d, 0x4d, 0x1d, 0x4f, 0x48, 0x48, 0x1b, 0x1c, 
  0x50, 0x57, 0x24, 0x23, 0x52, 0x56, 0x23, 0x47, 0x53, 0x55, 0x24, 0x5c, 0x52, 0x55, 0x22, 0x75, 0x53, 0x57, 0x22, 0x8c, 0x55, 0x56, 0x20, 0xa5, 0x55, 0x56, 0x20, 0xbd, 0x63, 0x64, 0x1e, 0xd2, 0xba, 0xba, 0x0c, 0xe2, 0xc0, 0xc0, 0x09, 0xeb, 0xc1, 0xc1, 0x09, 0xec, 0xc1, 0xc1, 0x09, 0xe7, 0xc0, 0xc0, 0x0a, 0xdd, 0xba, 0xba, 0x0b, 0xcf, 0x67, 0x68, 0x1b, 0xc0, 0x55, 0x57, 0x1d, 0xae, 0x52, 0x54, 0x1d, 0x9a, 0x4f, 0x51, 0x1c, 0x86, 0x4f, 0x51, 0x1c, 0x74, 0x4e, 0x50, 0x1c, 0x62, 0x4a, 0x4d, 0x1b, 0x52, 0x4b, 0x4b, 0x1b, 0x2f, 
  0x53, 0x53, 0x24, 0x31, 0x52, 0x56, 0x22, 0x4a, 0x54, 0x56, 0x22, 0x61, 0x54, 0x56, 0x21, 0x79, 0x55, 0x57, 0x21, 0x92, 0x54, 0x57, 0x21, 0xaa, 0x53, 0x57, 0x1f, 0xc3, 0x9f, 0xa0, 0x10, 0xd8, 0xc0, 0xc0, 0x09, 0xe7, 0xbf, 0xbf, 0x09, 0xf1, 0xc1, 0xc1, 0x0a, 0xf4, 0xc0, 0xc0, 0x09, 0xef, 0xc0, 0xc0, 0x0a, 0xe5, 0xc0, 0xc0, 0x09, 0xd8, 0xa5, 0xa6, 0x0f, 0xc7, 0x53, 0x56, 0x1c, 0xb4, 0x51, 0x54, 0x1c, 0xa0, 0x50, 0x52, 0x1b, 0x8b, 0x4f, 0x51, 0x1e, 0x77, 0x4e, 0x50, 0x1b, 0x65, 0x4b, 0x4b, 0x1b, 0x54, 0x4b, 0x4b, 0x1d, 0x3d, 
  0x51, 0x56, 0x24, 0x38, 0x53, 0x57, 0x24, 0x4c, 0x55, 0x55, 0x21, 0x63, 0x54, 0x56, 0x22, 0x7c, 0x55, 0x58, 0x22, 0x95, 0x54, 0x57, 0x21, 0xaf, 0x53, 0x56, 0x20, 0xc6, 0xc1, 0xc1, 0x0a, 0xdb, 0xc1, 0xc1, 0x09, 0xeb, 0xc0, 0xc0, 0x0a, 0xf5, 0xc1, 0xc1, 0x0a, 0xf8, 0xc0, 0xc0, 0x0a, 0xf4, 0xc1, 0xc1, 0x09, 0xeb, 0xc0, 0xc0, 0x0a, 0xdd, 0xba, 0xba, 0x0b, 0xcc, 0x53, 0x54, 0x1e, 0xb8, 0x51, 0x52, 0x1c, 0xa3, 0x4f, 0x50, 0x1c, 0x8e, 0x4e, 0x50, 0x1d, 0x78, 0x4e, 0x50, 0x1b, 0x65, 0x4b, 0x4e, 0x1b, 0x55, 0x48, 0x4c, 0x1a, 0x43, 
  0x53, 0x53, 0x25, 0x37, 0x51, 0x55, 0x23, 0x4e, 0x53, 0x55, 0x23, 0x65, 0x55, 0x57, 0x20, 0x7e, 0x54, 0x57, 0x21, 0x97, 0x53, 0x56, 0x1f, 0xb1, 0x55, 0x56, 0x1f, 0xc8, 0xb9, 0xb9, 0x0b, 0xdc, 0xc1, 0xc1, 0x09, 0xec, 0xbf, 0xbf, 0x0a, 0xf6, 0xc0, 0xc0, 0x0a, 0xfa, 0xc1, 0xc1, 0x0a, 0xf7, 0xc0, 0xc0, 0x09, 0xee, 0xc1, 0xc1, 0x0a, 0xe0, 0xc1, 0xc1, 0x09, 0xce, 0x50, 0x53, 0x1c, 0xba, 0x4f, 0x52, 0x1b, 0xa4, 0x4f, 0x51, 0x1b, 0x8d, 0x4e, 0x50, 0x1b, 0x78, 0x4b, 0x4e, 0x1b, 0x65, 0x49, 0x4c, 0x1b, 0x53, 0x49, 0x4d, 0x1b, 0x42, 
  0x50, 0x55, 0x23, 0x33, 0x51, 0x55, 0x23, 0x4e, 0x55, 0x57, 0x23, 0x66, 0x54, 0x56, 0x22, 0x7f, 0x53, 0x57, 0x21, 0x98, 0x53, 0x56, 0x1f, 0xb1, 0x54, 0x55, 0x1e, 0xc7, 0xa6, 0xa7, 0x10, 0xdd, 0xc1, 0xc1, 0x09, 0xec, 0xc0, 0xc0, 0x0a, 0xf6, 0xc0, 0xc0, 0x0a, 0xf9, 0xc1, 0xc1, 0x0a, 0xf8, 0xc1, 0xc1, 0x09, 0xef, 0xc0, 0xc0, 0x0a, 0xe0, 0x9d, 0x9f, 0x10, 0xcd, 0x50, 0x53, 0x1d, 0xb8, 0x50, 0x51, 0x1c, 0xa2, 0x4e, 0x50, 0x1b, 0x8b, 0x4e, 0x50, 0x1c, 0x75, 0x4c, 0x4e, 0x1a, 0x61, 0x4c, 0x4f, 0x1c, 0x50, 0x4c, 0x4c, 0x1a, 0x39, 
  0x4e, 0x55, 0x27, 0x27, 0x51, 0x55, 0x22, 0x4b, 0x52, 0x55, 0x21, 0x63, 0x53, 0x55, 0x22, 0x7d, 0x54, 0x57, 0x21, 0x97, 0x54, 0x55, 0x1f, 0xb0, 0x54, 0x55, 0x20, 0xc7, 0x61, 0x63, 0x1c, 0xda, 0xba, 0xba, 0x0c, 0xe9, 0xc0, 0xc0, 0x0a, 0xf3, 0xc1, 0xc1, 0x0a, 0xf7, 0xc1, 0xc1, 0x0a, 0xf4, 0xc1, 0xc1, 0x09, 0xeb, 0xb9, 0xb9, 0x0a, 0xdc, 0x60, 0x61, 0x1a, 0xc9, 0x51, 0x52, 0x1c, 0xb3, 0x4f, 0x51, 0x1b, 0x9d, 0x4e, 0x50, 0x1c, 0x85, 0x4f, 0x51, 0x1b, 0x70, 0x4a, 0x4d, 0x1b, 0x5c, 0x4a, 0x4e, 0x1b, 0x4b, 0x47, 0x4d, 0x1d, 0x2b, 
  0x4d, 0x4d, 0x21, 0x17, 0x52, 0x52, 0x20, 0x47, 0x53, 0x55, 0x22, 0x5f, 0x52, 0x55, 0x22, 0x78, 0x53, 0x55, 0x21, 0x92, 0x53, 0x56, 0x20, 0xab, 0x54, 0x55, 0x1f, 0xc1, 0x55, 0x56, 0x20, 0xd4, 0x62, 0x64, 0x1d, 0xe2, 0x9d, 0x9d, 0x10, 0xec, 0xc0, 0xc0, 0x09, 0xef, 0xb9, 0xb9, 0x0a, 0xec, 0xa4, 0xa4, 0x0e, 0xe2, 0x5f, 0x62, 0x1a, 0xd2, 0x51, 0x52, 0x1b, 0xc0, 0x50, 0x52, 0x1c, 0xab, 0x4f, 0x50, 0x1b, 0x94, 0x4e, 0x50, 0x1c, 0x7e, 0x4d, 0x50, 0x1d, 0x69, 0x4d, 0x4d, 0x1a, 0x56, 0x49, 0x4d, 0x1d, 0x45, 0x4a, 0x4a, 0x1f, 0x18, 
  0x55, 0x55, 0x2a, 0x06, 0x50, 0x55, 0x20, 0x3f, 0x50, 0x53, 0x22, 0x59, 0x52, 0x55, 0x21, 0x72, 0x53, 0x55, 0x1f, 0x8a, 0x52, 0x55, 0x1f, 0xa1, 0x53, 0x56, 0x1e, 0xb7, 0x52, 0x55, 0x1e, 0xc9, 0x53, 0x54, 0x1e, 0xd6, 0x51, 0x53, 0x1d, 0xdf, 0x51, 0x55, 0x1d, 0xe1, 0x52, 0x54, 0x1e, 0xdc, 0x50, 0x53, 0x1d, 0xd3, 0x50, 0x54, 0x1c, 0xc4, 0x50, 0x51, 0x1c, 0xb2, 0x50, 0x52, 0x1d, 0x9e, 0x4e, 0x50, 0x1c, 0x88, 0x4d, 0x4f, 0x1c, 0x73, 0x4d, 0x4d, 0x1a, 0x5f, 0x4b, 0x4e, 0x1d, 0x4e, 0x49, 0x4d, 0x19, 0x3b, 0x33, 0x33, 0x33, 0x05, 
  0x00, 0x00, 0x00, 0x00, 0x4f, 0x4f, 0x1f, 0x20, 0x4e, 0x51, 0x1f, 0x51, 0x50, 0x55, 0x20, 0x66, 0x52, 0x55, 0x20, 0x7e, 0x53, 0x55, 0x1f, 0x93, 0x52, 0x55, 0x1e, 0xa7, 0x51, 0x54, 0x1e, 0xb9, 0x51, 0x54, 0x1f, 0xc4, 0x52, 0x55, 0x1f, 0xcc, 0x52, 0x53, 0x1f, 0xcc, 0x50, 0x53, 0x1c, 0xc7, 0x52, 0x53, 0x1d, 0xbd, 0x51, 0x52, 0x1c, 0xb0, 0x50, 0x51, 0x1b, 0x9f, 0x4f, 0x51, 0x1b, 0x8d, 0x4d, 0x50, 0x1b, 0x79, 0x4c, 0x4f, 0x1b, 0x67, 0x4b, 0x4e, 0x1b, 0x55, 0x49, 0x4d, 0x19, 0x45, 0x48, 0x48, 0x1b, 0x1c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x66, 0x66, 0x33, 0x05, 0x4c, 0x51, 0x21, 0x35, 0x4f, 0x52, 0x1f, 0x5a, 0x51, 0x53, 0x20, 0x6e, 0x52, 0x54, 0x1f, 0x82, 0x51, 0x53, 0x1f, 0x93, 0x51, 0x53, 0x1f, 0xa2, 0x51, 0x53, 0x1d, 0xac, 0x51, 0x52, 0x1d, 0xb3, 0x50, 0x53, 0x1c, 0xb2, 0x50, 0x53, 0x1d, 0xae, 0x50, 0x51, 0x1d, 0xa5, 0x51, 0x53, 0x1c, 0x99, 0x4f, 0x51, 0x1d, 0x8a, 0x4d, 0x50, 0x1b, 0x79, 0x4d, 0x50, 0x1d, 0x69, 0x4b, 0x4e, 0x1a, 0x58, 0x4a, 0x4d, 0x1c, 0x48, 0x47, 0x4d, 0x1d, 0x2b, 0x55, 0x55, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x22, 0x0f, 0x4f, 0x4f, 0x1e, 0x3a, 0x50, 0x53, 0x21, 0x5c, 0x50, 0x52, 0x21, 0x6c, 0x50, 0x52, 0x1f, 0x7b, 0x50, 0x52, 0x1f, 0x88, 0x51, 0x53, 0x1f, 0x90, 0x50, 0x52, 0x1e, 0x95, 0x50, 0x52, 0x1d, 0x95, 0x50, 0x53, 0x1d, 0x92, 0x4f, 0x51, 0x1d, 0x8a, 0x4e, 0x50, 0x1c, 0x7f, 0x4e, 0x50, 0x1d, 0x72, 0x4e, 0x50, 0x1b, 0x65, 0x4e, 0x4e, 0x1c, 0x58, 0x49, 0x4c, 0x1b, 0x49, 0x48, 0x4d, 0x1b, 0x2e, 0x3f, 0x55, 0x15, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x48, 0x24, 0x0e, 0x4c, 0x51, 0x21, 0x35, 0x4e, 0x51, 0x21, 0x55, 0x4e, 0x51, 0x1f, 0x61, 0x50, 0x52, 0x21, 0x6c, 0x4f, 0x51, 0x1e, 0x74, 0x4e, 0x50, 0x1d, 0x78, 0x4d, 0x4f, 0x1e, 0x77, 0x4f, 0x51, 0x1c, 0x74, 0x4e, 0x51, 0x1e, 0x6e, 0x4b, 0x50, 0x1b, 0x65, 0x4b, 0x51, 0x1c, 0x5b, 0x4c, 0x4f, 0x1c, 0x50, 0x4b, 0x4e, 0x1a, 0x44, 0x4a, 0x4a, 0x1f, 0x29, 0x45, 0x45, 0x17, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x00, 0x03, 0x4a, 0x52, 0x20, 0x1f, 0x4f, 0x4f, 0x1f, 0x40, 0x4c, 0x4f, 0x1d, 0x4d, 0x4e, 0x4e, 0x1e, 0x54, 0x4d, 0x50, 0x1d, 0x56, 0x4e, 0x51, 0x1c, 0x58, 0x4d, 0x50, 0x1d, 0x56, 0x4b, 0x4e, 0x1c, 0x51, 0x4e, 0x4e, 0x1e, 0x4b, 0x4b, 0x4e, 0x1e, 0x44, 0x4a, 0x4e, 0x1b, 0x37, 0x4e, 0x4e, 0x1d, 0x1a, 0x55, 0x55, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x04, 0x51, 0x51, 0x22, 0x16, 0x4b, 0x4b, 0x1b, 0x25, 0x4c, 0x4c, 0x1e, 0x32, 0x48, 0x4d, 0x1b, 0x38, 0x4a, 0x4e, 0x1b, 0x37, 0x4a, 0x4f, 0x1f, 0x30, 0x48, 0x50, 0x1d, 0x23, 0x4c, 0x4c, 0x19, 0x14, 0x3f, 0x3f, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t Icon_Bullet_Teal = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 22,
  .header.h = 22,
  .data_size = 484 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = Icon_Bullet_Teal_map,
};