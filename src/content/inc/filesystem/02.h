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
static filesystem_item filesystem_02_list[] = {
    {
        .file_id = "0001",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "folder",
        .file_size = "41379012823870",
        .file_modified = "May 21  2024",
        .file_fullname = "Applications"
    },
    {
        .file_id = "0002",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "folder",
        .file_size = "2713829",
        .file_modified = "June 18  2023",
        .file_fullname = "Desktop"
    },
    {
        .file_id = "0003",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "folder",
        .file_size = "33957732829",
        .file_modified = "January 31  2024",
        .file_fullname = "Documents"
    },
    {
        .file_id = "0004",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "folder",
        .file_size = "9274142837753",
        .file_modified = "May 4  2024",
        .file_fullname = "Downloads"
    },
    {
        .file_id = "0004",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "folder",
        .file_size = "27261338255971",
        .file_modified = "July 9 2022",
        .file_fullname = "Movies"
    },
    {
        .file_id = "0005",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "folder",
        .file_size = "5530961843092",
        .file_modified = "July 9 2022",
        .file_fullname = "Music"
    },
    {
        .file_id = "0002",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "folder",
        .file_size = "490123753",
        .file_modified = "August 4  2023",
        .file_fullname = "Pictures"
    },
    {
        .file_id = "0006",
        .file_permissions = "drwxr-xr-x@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "folder",
        .file_size = "8430247019388290",
        .file_modified = "June 18  2023",
        .file_fullname = "Storage"
    },
    {
        .file_id = "end",
        .file_info = "TAP HERE\nTo add a new\nFile",
    },
};