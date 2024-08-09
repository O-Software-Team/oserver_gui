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
#define OCO_PAGE_MAX 10
#define OCO_CANVAS_WIDTH 385 /* match MONITOR_HOR_RES */
#define OCO_CANVAS_HEIGHT 510 /* match MONITOR_VER_RES */

/* Color Definitions */
#define O_YELLOW_COLOR 0xD6B932
#define O_GREY_COLOR 0xAEB2A1
#define O_TEAL_COLOR 0x0AC1C1
#define O_SCALE_GREY 0xC5C1B7
#define O_SCALE_CREAM 0xD9DFC2
#define O_SCALE_ORANGE 0xCB6D4D
#define O_SCALE_RED 0xB7354B
#define O_SCALE_LIGHT_TEAL 0xC5E7E7
#define O_SCALE_LIGHT_YELLOW 0xDABC41
#define HEADING_SUBDUED_COLOR 0xADB1A2
#define RESET_COLOR 0x32D642
#define POWER_OFF_COLOR 0xDD4949
#define BATTERY_LEVEL_GREAT 0x32D642
#define BATTERY_LEVEL_FAIR 0xFFFFFF
#define BATTERY_LEVEL_LOW 0xDD4949

#define MESSAGE_CONTENT_COLOR 0xADB1A2
#define CONTACT_CONTENT_COLOR 0xADB1A2

/* Include image resources */
LV_IMG_DECLARE(Background);
LV_IMG_DECLARE(Button_Hollow);
LV_IMG_DECLARE(Dot_Enabled);
LV_IMG_DECLARE(Moon_Yellow);
LV_IMG_DECLARE(Sun_Grey);
LV_IMG_DECLARE(Upload_Button);
LV_IMG_DECLARE(Icon_Arrow_White);
LV_IMG_DECLARE(Icon_Audio_Yellow);
LV_IMG_DECLARE(Icon_Birthday);
LV_IMG_DECLARE(Icon_Phone);
LV_IMG_DECLARE(Icon_Empty_Dude);
LV_IMG_DECLARE(Icon_Day_1);
LV_IMG_DECLARE(Icon_Day_9);
LV_IMG_DECLARE(Icon_Day_10);
LV_IMG_DECLARE(Icon_Day_15);
LV_IMG_DECLARE(Icon_Day_16);
LV_IMG_DECLARE(Icon_Day_20);
LV_IMG_DECLARE(Icon_Bluetooth_White);
LV_IMG_DECLARE(Icon_Bullet_Item);
LV_IMG_DECLARE(Icon_Bullet_Yellow);
LV_IMG_DECLARE(Icon_Close_White);
LV_IMG_DECLARE(Icon_Contact_Initials_Background);
LV_IMG_DECLARE(Icon_Documents_Yellow);
LV_IMG_DECLARE(Icon_Email_Unread_Yellow);
LV_IMG_DECLARE(Icon_Excel_Yellow);
LV_IMG_DECLARE(Icon_Filter_Button);
LV_IMG_DECLARE(Icon_Folder_Yellow);
LV_IMG_DECLARE(Icon_Grey_Outline_Button);
LV_IMG_DECLARE(Icon_Image_Yellow);
LV_IMG_DECLARE(Icon_iPad);
LV_IMG_DECLARE(Icon_iPad_Yellow);
LV_IMG_DECLARE(Icon_iPhone);
LV_IMG_DECLARE(Icon_iPhone_Yellow);
LV_IMG_DECLARE(Icon_List_Item_Divider);
LV_IMG_DECLARE(Icon_MacBook);
LV_IMG_DECLARE(Icon_MacBook_Yellow);
LV_IMG_DECLARE(Icon_Menu_Calendar_Yellow);
LV_IMG_DECLARE(Icon_Menu_Contact_Yellow);
LV_IMG_DECLARE(Icon_Menu_Devices_Yellow);
LV_IMG_DECLARE(Icon_Menu_Files_Yellow);
LV_IMG_DECLARE(Icon_Menu_Mail_Yellow);
LV_IMG_DECLARE(Icon_Menu_Music_Yellow);
LV_IMG_DECLARE(Icon_Menu_Settings_Yellow);
LV_IMG_DECLARE(Icon_Menu_Text_Yellow);
LV_IMG_DECLARE(Icon_Bullet_Grey);
LV_IMG_DECLARE(Icon_Bullet_Teal);
LV_IMG_DECLARE(Icon_Hollow_Button_Grey_L);
LV_IMG_DECLARE(Icon_Hollow_Button_Grey_R);
LV_IMG_DECLARE(Icon_Hollow_Button_Teal);
LV_IMG_DECLARE(Icon_Mode_Button_Grey);
LV_IMG_DECLARE(Icon_Mode_Button_Teal);
LV_IMG_DECLARE(Icon_Moon_Yellow);
LV_IMG_DECLARE(Icon_Sun_Grey);
LV_IMG_DECLARE(Icon_Upload_Yellow);
LV_IMG_DECLARE(Icon_More_White);
LV_IMG_DECLARE(Icon_Next_White);
LV_IMG_DECLARE(Icon_NFC_White);
LV_IMG_DECLARE(Icon_O_Device_Toggle_Off);
LV_IMG_DECLARE(Icon_O_Device_Toggle_On);
LV_IMG_DECLARE(Icon_Power_Button_Yellow);
LV_IMG_DECLARE(Icon_Programs_Yellow);
LV_IMG_DECLARE(Icon_Refresh_Single_Yellow);
LV_IMG_DECLARE(Icon_Settings_Toggle_Off);
LV_IMG_DECLARE(Icon_Settings_Toggle_On);
LV_IMG_DECLARE(Icon_Status_Active);
LV_IMG_DECLARE(Icon_Status_Disable);
LV_IMG_DECLARE(Icon_Text_Unread_Yellow);
LV_IMG_DECLARE(Icon_Video_Yellow);
LV_IMG_DECLARE(Icon_WiFi_White);
LV_IMG_DECLARE(Icon_Crypto_Bitcoin_Yellow);
LV_IMG_DECLARE(Icon_Crypto_Ethereum_Yellow);
LV_IMG_DECLARE(Icon_Crypto_Tether_Yellow);
LV_IMG_DECLARE(Icon_Crypto_Binance_Yellow);
LV_IMG_DECLARE(Icon_Crypto_Public_Key_Horizontal_Teal);
LV_IMG_DECLARE(Icon_Crypto_Private_Key_Horizontal_Red);
LV_IMG_DECLARE(Time);
LV_IMG_DECLARE(Linez);
LV_IMG_DECLARE(GreyHalo);
LV_IMG_DECLARE(Progress);
LV_IMG_DECLARE(Music_Player_White);
LV_IMG_DECLARE(Music_Player_Play);
LV_IMG_DECLARE(Music_Player_Pause);
LV_IMG_DECLARE(Music_App_Heading_Playlists);
LV_IMG_DECLARE(Music_App_Heading_Title);
LV_IMG_DECLARE(Email_App_Heading_Title);
LV_IMG_DECLARE(Files_App_Heading_Title);
LV_IMG_DECLARE(Devices_App_Heading_Title);
LV_IMG_DECLARE(Text_App_Heading_Title);
LV_IMG_DECLARE(Calendar_App_Heading_Title);
LV_IMG_DECLARE(Calendar_4_Up);
LV_IMG_DECLARE(Calendar_1_June_2024);
LV_IMG_DECLARE(Calendar_2_July_2024);
LV_IMG_DECLARE(Calendar_3_August_2024);
LV_IMG_DECLARE(Calendar_4_September_2024);
LV_IMG_DECLARE(Contacts_App_Heading_Title);
LV_IMG_DECLARE(O_App_Heading_Title);
LV_IMG_DECLARE(Page_Dot);
LV_IMG_DECLARE(Settings_App_Heading_Title);
LV_IMG_DECLARE(Logo); // Metalic boot screen logo
LV_IMG_DECLARE(teal_circle_selector);
LV_IMG_DECLARE(B12230x385x510); // boot screen with winding road background

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
LV_IMG_DECLARE(Album_Dio_Holy_Diver);

LV_IMG_DECLARE(Pause);
LV_IMG_DECLARE(Play);
LV_IMG_DECLARE(FFWD);
LV_IMG_DECLARE(RWND);

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
