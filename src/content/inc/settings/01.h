/* List to provide a sample of folders found on the device */

/*
    char * settings_id;
    char * settings_name;
    char * settings_admin;
    char * settings_group;
    char * settings_permissions;
    char * settings_type;
    char * settings_state;
    char * settings_description;
    char * settings_summary;
    lv_img_dsc_t * settings_icon;
*/


/* Create and initialize the Settings list */
static settings_item settings_01_list[] = {
    {
        .settings_id = "0001",
        .settings_name = "WiFi",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = true,
        .settings_description = "WiFi radio setting",
        .settings_summary = "This feature displays the status of your O Mini Server WiFi radio",
        .settings_icon = &Icon_Settings_Toggle_On
    },
    {
        .settings_id = "0002",
        .settings_name = "Bluetooth",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = false,
        .settings_description = "Bluetooth radio setting",
        .settings_summary = "This feature displays the status of your O Mini Server Bluetooth radio",
        .settings_icon = &Icon_Settings_Toggle_Off
    },
    {
        .settings_id = "0003",
        .settings_name = "NFC",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = false,
        .settings_description = "NFC radio setting",
        .settings_summary = "This feature displays the status of your O Mini Server NFC radio",
        .settings_icon = &Icon_Settings_Toggle_On
    },
    {
        .settings_id = "end",
        .settings_info = "TAP HERE\nTo add a new\nFile",
    },
};