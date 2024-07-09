/* List to provide a sample of storage utilization on the device */

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


/* Create and initialize the Storage list */
static settings_item settings_03_list[] = {
    {
        .settings_id = "0001",
        .settings_name = "Images",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "O_SCALE_RED",
        .settings_state = SETTINGS_STATE_ACTIVE,
        .settings_description = "137.4 Gb",
        .settings_summary = "This feature displays the total amount of storage images use on your O Mini Server",
        .settings_icon = &Icon_Bullet_Item
    },
    {
        .settings_id = "0002",
        .settings_name = "Documents",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "O_SCALE_ORANGE",
        .settings_state = SETTINGS_STATE_ACTIVE,
        .settings_description = "103.8 Gb",
        .settings_summary = "This feature displays the total amount of storage documents use on your O Mini Server",
        .settings_icon = &Icon_Bullet_Item
    },
    {
        .settings_id = "0003",
        .settings_name = "Movies",
        .settings_admin = "root",
        .settings_group = "wheel",
        .settings_permissions = "-rwxr-xr-x",
        .settings_type = "O_SCALE_CREAM",
        .settings_state = SETTINGS_STATE_ACTIVE,
        .settings_description = "97.5 Gb",
        .settings_summary = "This feature displays the total amount of storage movies use on your O Mini Server",
        .settings_icon = &Icon_Bullet_Item
    },
    {
        .settings_id = "end",
        .settings_info = "TAP HERE\nTo add a new\nFile",
    },
};