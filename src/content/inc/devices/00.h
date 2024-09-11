/* Devices - Pairing State Machine -and- Device Profile Info */
#ifndef _00_H
#define _00_H

#include "../../../menu_handler.h"

/*
    char * device_id;
    char * device_name;
    char * device_perms;
    char * device_type;
    const lv_img_dsc_t * device_type_icon;
    const lv_img_dsc_t * device_enabled_icon;
    const lv_img_dsc_t * device_disabled_icon;
    char * device_baseline;
    bool   device_state;
    #define PAIRING_STATE_ENABLED  true
    #define false false
*/

/* Declare local function prototypes */
static void populate_device_list_container(void);
static void device_pick_list_container(void);
static void enable_selected_device_from_list(lv_event_t * e);
static void start_heartbeat_animation(lv_obj_t * parent);

/***  Devices Specific Declarations  ***/
LV_IMG_DECLARE(Icon_Status_Active);
LV_IMG_DECLARE(Icon_Status_Disable);
LV_IMG_DECLARE(Icon_Add_Device);
LV_IMG_DECLARE(Icon_Choose_Device);

LV_IMG_DECLARE(Icon_iPhone_Yellow);
LV_IMG_DECLARE(Icon_iPad_Yellow);
LV_IMG_DECLARE(Icon_MacBook_Yellow);

#ifdef DEFINE_DEVICE_LIST

device_pairing_item device_00_list[] = {
    {
        .device_id = "0001",
        .device_name = "iPhone Demo",
        .device_perms = "Admin",
        .device_control = "total",
        .device_type = "phone",
        .device_type_icon = &Icon_iPhone_Yellow,
        .device_enabled_icon = &Icon_Status_Active,
        .device_disabled_icon = &Icon_Status_Disable,
        .device_state = false,
        .device_baseline = false
    },
    {
        .device_id = "0002",
        .device_name = "Frenchi Loco Mac",
        .device_perms = "Admin",
        .device_control = "sync",
        .device_type = "computer",
        .device_type_icon = &Icon_MacBook_Yellow,
        .device_enabled_icon = &Icon_Status_Active,
        .device_disabled_icon = &Icon_Status_Disable,
        .device_state = false,
        .device_baseline = false
    },
    {
        .device_id = "0003",
        .device_name = "iPad Demo",
        .device_perms = "Admin",
        .device_control = "neutral",
        .device_type = "tablet",
        .device_type_icon = &Icon_iPad_Yellow,
        .device_enabled_icon = &Icon_Status_Active,
        .device_disabled_icon = &Icon_Status_Disable,
        .device_state = false,
        .device_baseline = false
    },
    {
        .device_id = "0004",
        .device_name = "Frenchi Loco iPad",
        .device_perms = "Friend",
        .device_control = "neutral",
        .device_type = "tablet",
        .device_type_icon = &Icon_iPad_Yellow,
        .device_enabled_icon = &Icon_Status_Active,
        .device_disabled_icon = &Icon_Status_Disable,
        .device_state = false,
        .device_baseline = false
    },
    {
        .device_id = "0005",
        .device_name = "Galaxy S24 Ultra",
        .device_perms = "Friend",
        .device_control = "neutral",
        .device_type = "phone",
        .device_type_icon = &Icon_iPhone_Yellow,
        .device_enabled_icon = &Icon_Status_Active,
        .device_disabled_icon = &Icon_Status_Disable,
        .device_state = false,
        .device_baseline = false
    },
    {
        .device_id = "0006",
        .device_name = "iPhone 16",
        .device_perms = "Friend",
        .device_control = "neutral",
        .device_type = "phone",
        .device_type_icon = &Icon_iPhone_Yellow,
        .device_enabled_icon = &Icon_Status_Active,
        .device_disabled_icon = &Icon_Status_Disable,
        .device_state = false,
        .device_baseline = false
    },
    {
        .device_id = "0007",
        .device_name = "Frenchi Loco Note",
        .device_perms = "Friend",
        .device_control = "neutral",
        .device_type = "tablet",
        .device_type_icon = &Icon_iPad_Yellow,
        .device_enabled_icon = &Icon_Status_Active,
        .device_disabled_icon = &Icon_Status_Disable,
        .device_state = false,
        .device_baseline = false
    },
    {
        .device_id = "end",
        .device_type = "DEVICE\nplace\nholder",
    },
};
#else
extern device_pairing_item device_00_list[];
#endif

#endif  // _00_H