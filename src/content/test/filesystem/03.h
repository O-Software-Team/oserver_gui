/* List to provide a sample of movies found on the device */

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
static filesystem_item filesystem_03_list[] = {
    {
        .file_id = "0001",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Airplane",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0002",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "150630",
        .file_modified = "May 18 2023",
        .file_fullname = "Airplane 2",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0003",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "578874",
        .file_modified = "May 18 2023",
        .file_fullname = "Hot Shots",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0004",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "147396",
        .file_modified = "May 18 2023",
        .file_fullname = "Hot Shots - Part Deux",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0005",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Spaceballs",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0006",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "147408",
        .file_modified = "May 18 2023",
        .file_fullname = "History of the World Part 1",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0007",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572484",
        .file_modified = "May 18 2023",
        .file_fullname = "Blazing Saddles",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0008",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "147408",
        .file_modified = "May 18 2023",
        .file_fullname = "Men in Tights",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0009",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572484",
        .file_modified = "May 18 2023",
        .file_fullname = "Young Frankenstein",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0010",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "14181094",
        .file_modified = "May 18 2023",
        .file_fullname = "The Naked Gun",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0011",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "5859621",
        .file_modified = "May 18 2023",
        .file_fullname = "Police Squad",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0012",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "119022",
        .file_modified = "May 18 2023",
        .file_fullname = "Monty Python's Life of Brian",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0013",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "105342",
        .file_modified = "May 18 2023",
        .file_fullname = "Monty Python's The Holy Grail",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0014",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "106704",
        .file_modified = "May 18 2023",
        .file_fullname = "The Adventures of Buckaroo Banzai Across the Eighth Dimension",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0015",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "72491",
        .file_modified = "May 18 2023",
        .file_fullname = "Big Trouble in Little China",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0016",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "55313",
        .file_modified = "May 18 2023",
        .file_fullname = "Police Academy",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0017",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "57443",
        .file_modified = "May 18 2023",
        .file_fullname = "Ferris Bueller's Day Off",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0018",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "222798",
        .file_modified = "May 18 2023",
        .file_fullname = "The Fifth Element",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0019",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "16882",
        .file_modified = "May 18 2023",
        .file_fullname = "Fawlty Towers",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0020",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "42869",
        .file_modified = "May 18 2023",
        .file_fullname = "Blackadder",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0021",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "42845",
        .file_modified = "May 18 2023",
        .file_fullname = "I, Robot",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0022",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "42887",
        .file_modified = "May 18 2023",
        .file_fullname = "Minority Report",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0023",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "5834",
        .file_modified = "May 18 2023",
        .file_fullname = "Oblivion",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0024",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "16954",
        .file_modified = "May 18 2023",
        .file_fullname = "The Big Lebowski",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0025",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "222858",
        .file_modified = "May 18 2023",
        .file_fullname = "Apocalypse Now",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0026",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "222858",
        .file_modified = "May 18 2023",
        .file_fullname = "Blade Runner",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0027",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "222858",
        .file_modified = "May 18 2023",
        .file_fullname = "Total Recall",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0028",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "222858",
        .file_modified = "May 18 2023",
        .file_fullname = "Mars Attacks!",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0029",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "222858",
        .file_modified = "May 18 2023",
        .file_fullname = "The Final Countdown",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "0030",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "222858",
        .file_modified = "May 18 2023",
        .file_fullname = "Minions",
        .file_icon = &Icon_Video_Yellow
    },
    {
        .file_id = "end",
        .file_info = "TAP HERE\nTo add a new\nFile",
    },
};