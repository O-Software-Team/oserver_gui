/* List based upon the items found in the "files" directory -- from 01.json */

/*
    char * file_id;
    char * file_name;
    char * file_extension;
    char * file_fullname;
    char * file_type;
    char * file_size;
    char * file_location;
    char * file_permissions;
    char * file_created;
    char * file_modified;
    char * file_owner;
    char * file_group;
    char * file_visibility;
    char * file_info;
*/


/* Create and initialize the Filesystem list */
static filesystem_item filesystem_01_list[] = {
    {
        .file_id = "0001",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "category",
        .file_size = "555",
        .file_modified = "May 18 2024",
        .file_fullname = "Autograf_And_Tiina_Image.c"
    },
    {
        .file_id = "0002",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "category",
        .file_size = "555",
        .file_modified = "May 18 2024",
        .file_fullname = "ABBA_SOS.c"
    },
    {
        .file_id = "0003",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "category",
        .file_size = "555",
        .file_modified = "May 18 2024",
        .file_fullname = "ABBA_SOS_LARGE.c"
    },
    {
        .file_id = "0004",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "category",
        .file_size = "555",
        .file_modified = "May 18 2024",
        .file_fullname = "ALICIA_KEYS.c"
    },
    {
        .file_id = "0005",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "category",
        .file_size = "555",
        .file_modified = "May 18 2024",
        .file_fullname = "ALICIA_KEYS_LARGE.c"
    },
    {
        .file_id = "0006",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_size = "555",
        .file_size = "147408",
        .file_modified = "May 18 2024",
        .file_fullname = "AMY_WINEHOUSE.c"
    },
    {
        .file_id = "end",
        .file_info = "TAP HERE\nTo add a new\nFile",
    },
};