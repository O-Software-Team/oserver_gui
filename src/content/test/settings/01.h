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
        .settings_name = "Applications",
        .settings_admin = "steveglaiser",
        .settings_group = "staff",
        .settings_permissions = "drwxr-xr-x@",
        .settings_type = "folder",
        .settings_state = "41379012823870",
        .settings_description = "May 21 2024",
        .settings_summary = "Bah-naa-naahhh!",
        .settings_icon = &Icon_Folder_Yellow
    },
    {
        .settings_id = "0002",
        .settings_name = "Desktop",
        .settings_admin = "steveglaiser",
        .settings_group = "staff",
        .settings_permissions = "drwxr-xr-x@",
        .settings_type = "folder",
        .settings_state = "2713829",
        .settings_description = "June 18 2023",
        .settings_summary = "Bah-naa-naahhh!",
        .settings_icon = &Icon_Folder_Yellow
    },
    {
        .settings_id = "0003",
        .settings_name = "Documents",
        .settings_admin = "steveglaiser",
        .settings_group = "staff",
        .settings_permissions = "drwxr-xr-x@",
        .settings_type = "folder",
        .settings_state = "33957732829",
        .settings_description = "January 31 2024",
        .settings_summary = "Bah-naa-naahhh!",
        .settings_icon = &Icon_Folder_Yellow
    },
    {
        .settings_id = "0004",
        .settings_name = "Downloads",
        .settings_admin = "steveglaiser",
        .settings_group = "staff",
        .settings_permissions = "drwxr-xr-x@",
        .settings_type = "folder",
        .settings_state = "9274142837753",
        .settings_description = "May 4 2024",
        .settings_summary = "Bah-naa-naahhh!",
        .settings_icon = &Icon_Folder_Yellow
    },
    {
        .settings_id = "0005",
        .settings_name = "Movies",
        .settings_admin = "steveglaiser",
        .settings_group = "staff",
        .settings_permissions = "drwxr-xr-x@",
        .settings_type = "folder",
        .settings_state = "27261338255971",
        .settings_description = "July 9 2022",
        .settings_summary = "Bah-naa-naahhh!",
        .settings_icon = &Icon_Folder_Yellow
    },
    {
        .settings_id = "0006",
        .settings_name = "Music",
        .settings_admin = "steveglaiser",
        .settings_group = "staff",
        .settings_permissions = "drwxr-xr-x@",
        .settings_type = "folder",
        .settings_state = "5530961843092",
        .settings_description = "July 9 2022",
        .settings_summary = "Bah-naa-naahhh!",
        .settings_icon = &Icon_Folder_Yellow
    },
    {
        .settings_id = "0007",
        .settings_name = "Pictures",
        .settings_admin = "steveglaiser",
        .settings_group = "staff",
        .settings_permissions = "drwxr-xr-x@",
        .settings_type = "folder",
        .settings_state = "490123753",
        .settings_description = "August 4 2023",
        .settings_summary = "Bah-naa-naahhh!",
        .settings_icon = &Icon_Folder_Yellow
    },
    {
        .settings_id = "0008",
        .settings_name = "Storage",
        .settings_admin = "steveglaiser",
        .settings_group = "staff",
        .settings_permissions = "drwxr-xr-x@",
        .settings_type = "folder",
        .settings_state = "8430247019388290",
        .settings_description = "June 18 2023",
        .settings_summary = "Bah-naa-naahhh!",
        .settings_icon = &Icon_Folder_Yellow
    },
    {
        .settings_id = "end",
        .settings_info = "TAP HERE\nTo add a new\nFile",
    },
};