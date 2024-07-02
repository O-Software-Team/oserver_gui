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


/* Create and initialize the Main Settings list screen */
static settings_item settings_00_list[] = {
    {
        .settings_id = "0001",
        .settings_name = "Connection",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = "passive",
        .settings_description = "Connection status",
        .settings_summary = "This feature displays the status of all of your O Mini Server connections via WiFi, Bluetooth, and NFC radios",
        .settings_icon = NULL
    },
    {
        .settings_id = "0002",
        .settings_name = "Display",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = "active",
        .settings_description = "Display mode choices",
        .settings_summary = "Use this feature to change the theme to one of the many O Mini Server themes we provide",
        .settings_icon = NULL
    },
    {
        .settings_id = "0003",
        .settings_name = "Storage",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = "passive",
        .settings_description = "Storage levels",
        .settings_summary = "This feature displays the memory storage level(s) of your O Mini Server",
        .settings_icon = NULL
    },
    {
        .settings_id = "0004",
        .settings_name = "Battery",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = "passive",
        .settings_description = "Battery status",
        .settings_summary = "This feature displays the battery level(s) of your O Mini Server",
        .settings_icon = NULL
    },
    {
        .settings_id = "0005",
        .settings_name = "System",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = "passive",
        .settings_description = "System info",
        .settings_summary = "This feature displays the system information specific to your O Mini Server",
        .settings_icon = NULL
    },
    {
        .settings_id = "end",
        .settings_info = "TAP HERE\nTo add a new\nFile",
    },
};