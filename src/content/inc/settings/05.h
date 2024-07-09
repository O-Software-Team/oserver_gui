/* List to provide a sample of folders found on the device */

/*
    char * settings_id;
    char * settings_name;
    char * settings_admin;
    char * settings_group;
    char * settings_permissions;
    char * settings_type;
    boolt  settings_state;
    char * settings_description;
    char * settings_summary;
    lv_img_dsc_t * settings_icon;
*/


/* Create and initialize the Settings list */
static settings_item settings_05_list[] = {
    {
        .settings_id = "0001",
        .settings_name = "OS Version",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = SETTINGS_STATE_ACTIVE,
        .settings_description = "v1.0.4",
        .settings_summary = "Use this feature to synchronize all of your paired devices with your O Mini Server",
        .settings_icon = NULL
    },
    {
        .settings_id = "0002",
        .settings_name = "Hardware Version",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = SETTINGS_STATE_ACTIVE,
        .settings_description = "v1",
        .settings_summary = "Use this feature to ensure all of your data is synchronized, cleanse any devices you either did not pair with or have unpaired with recently, remove any unused or deleted items from the memory on your O Mini Server",
        .settings_icon = NULL
    },
    {
        .settings_id = "0003",
        .settings_name = "Security Version",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = SETTINGS_STATE_ACTIVE,
        .settings_description = "v1.0.6",
        .settings_summary = "Use this feature to change your theme to one of the many O Mini Server themes we provide",
        .settings_icon = NULL
    },
    {
        .settings_id = "0004",
        .settings_name = "Device Class",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = SETTINGS_STATE_ACTIVE,
        .settings_description = "Storage",
        .settings_summary = "Use this feature to see the steps you need to follow to place your O Mini Server into stealth mode",
        .settings_icon = NULL
    },
    {
        .settings_id = "0005",
        .settings_name = "Device Generation",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "func",
        .settings_state = SETTINGS_STATE_ACTIVE,
        .settings_description = "Gen_1_0_0",
        .settings_summary = "Use this feature to see the steps you need to follow to disable stealth mode on your O Mini Server",
        .settings_icon = NULL
    },
    {
        .settings_id = "end",
        .settings_info = "TAP HERE\nTo add a new\nFile",
    },
};
