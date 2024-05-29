/* List from Files spec */

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
        .file_fullname = "Folders",
        .file_icon = &Icon_Folder_Yellow
    },
    {
        .file_id = "0002",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "category",
        .file_size = "555",
        .file_modified = "May 18 2024",
        .file_fullname = "Movies"
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0003",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "category",
        .file_size = "555",
        .file_modified = "May 18 2024",
        .file_fullname = "Images"
        .file_icon = &Icon_Image_Yellow
    },
    {
        .file_id = "0004",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "category",
        .file_size = "555",
        .file_modified = "May 18 2024",
        .file_fullname = "Applications"
        .file_icon = &Icon_Programs_Yellow
    },
    {
        .file_id = "0005",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "category",
        .file_size = "555",
        .file_modified = "May 18 2024",
        .file_fullname = "Excel"
        .file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0006",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_size = "555",
        .file_size = "147408",
        .file_modified = "May 18 2024",
        .file_fullname = "Documents"
        .file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "end",
        .file_info = "TAP HERE\nTo add a new\nFile",
    },
};