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

/* Include image resources */
LV_IMG_DECLARE(Background);
LV_IMG_DECLARE(Icon_Status_Active);
LV_IMG_DECLARE(Icon_Status_Disable);
LV_IMG_DECLARE(Icon_iPad);
LV_IMG_DECLARE(Icon_MacBook);
LV_IMG_DECLARE(Icon_iPhone);
LV_IMG_DECLARE(Icon_WiFi_White);
LV_IMG_DECLARE(Icon_Bluetooth_White);
LV_IMG_DECLARE(Icon_NFC_White);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Icon_List_Item_Divider);
LV_IMG_DECLARE(Time);
LV_IMG_DECLARE(Linez);
LV_IMG_DECLARE(GreyHalo);
LV_IMG_DECLARE(Icon_Filter_Button);
LV_IMG_DECLARE(Progress);
LV_IMG_DECLARE(Icon_Grey_Outline_Button);
LV_IMG_DECLARE(Icon_Close_White);
LV_IMG_DECLARE(Music_Player_White);
LV_IMG_DECLARE(Music_Player_Play);
LV_IMG_DECLARE(Music_Player_Pause);
LV_IMG_DECLARE(Music_App_Heading_Playlists);
LV_IMG_DECLARE(Music_App_Heading_Title);
LV_IMG_DECLARE(Email_App_Heading_Title);
LV_IMG_DECLARE(Files_App_Heading_Title);
LV_IMG_DECLARE(Devices_App_Heading_Title);
LV_IMG_DECLARE(Text_App_Heading_Title);

/*
 * Album covers for the 'Music' player
 */
LV_IMG_DECLARE(Background);
LV_IMG_DECLARE(ABBA_SOS);
LV_IMG_DECLARE(ABBA_SOS_LARGE);

LV_IMG_DECLARE(BACK_IN_BLACK);
LV_IMG_DECLARE(BACK_IN_BLACK_LARGE);

LV_IMG_DECLARE(ALICIA_KEYS);
LV_IMG_DECLARE(ALICIA_KEYS_LARGE);

LV_IMG_DECLARE(AMY_WINEHOUSE);
LV_IMG_DECLARE(AMY_WINEHOUSE_LARGE);

/* Include font resources */
LV_FONT_DECLARE(SaolDisplayRegularItalic_22);
LV_FONT_DECLARE(NeueHaasDisplayLight_22);

LV_FONT_DECLARE(SaolDisplayRegularItalic_24);
LV_FONT_DECLARE(SaolDisplayRegularItalic_26);
LV_FONT_DECLARE(NeueHaasDisplayLight_24);

LV_FONT_DECLARE(SaolDisplayRegularItalic_32);
LV_FONT_DECLARE(NeueHaasDisplayLight_32);

LV_FONT_DECLARE(SaolDisplayRegularItalic_20);
LV_FONT_DECLARE(NeueHaasDisplayLight_20);
LV_FONT_DECLARE(NeueHaasDisplayRoman_20);

LV_FONT_DECLARE(SaolDisplayRegularItalic_48);
LV_FONT_DECLARE(NeueHaasDisplayLight_48);

LV_FONT_DECLARE(NeueHaasDisplayXThin_50); // For the 'security pin code'
LV_FONT_DECLARE(NeueHaasDisplayXThin_52);
LV_FONT_DECLARE(NeueHaasDisplayXThin_58);
LV_FONT_DECLARE(NeueHaasDisplayXThin_80);
LV_FONT_DECLARE(NeueHaasDisplayXThin_100);
LV_FONT_DECLARE(NeueHaasDisplayXThin_150); // Percent transfer screen
LV_FONT_DECLARE(NeueHaasDisplayXXThin_100); // Percent transfer screen
LV_FONT_DECLARE(NeueHaasDisplayXXThin_150); // Percent transfer screen
LV_FONT_DECLARE(NeueHaasDisplayXXThin_170); // Percent transfer screen
LV_FONT_DECLARE(NeueHaasDisplayXXThin_200); // Percent transfer screen

LV_FONT_DECLARE(NeueHaasDisplayLight_18);
LV_FONT_DECLARE(NeueHaasDisplayRoman_18);

LV_FONT_DECLARE(NeueHaasDisplayLight_16);

LV_FONT_DECLARE(NeueHaasDisplayBold_16);
LV_FONT_DECLARE(NeueHaasDisplayMediu_16);
LV_FONT_DECLARE(NeueHaasDisplayRoman_16); // For the 'bold' device names

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
