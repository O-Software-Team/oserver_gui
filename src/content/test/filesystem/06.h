/* List to provide a sample of documents found on the device */

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
static filesystem_item filesystem_06_list[] = {
    {
        .file_id = "0001",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Olympics Game security plan.pdf",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "0002",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The Tiananmen Papers",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "0003",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Rosenholz files.pdf",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "0004",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Luxembourg Leaks",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0005",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Swiss Leaks.pdf",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "0001",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Downing Street memo.pdf",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "0006",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Pentagon Papers.pdf",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0007",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Afghan War documents leak",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0008",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Iraq War documents leak.pdf",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0009",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "United States diplomatic cables leak.pdf",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0010",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Vault 7",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0011",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The Hutchinson Letters.pdf",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0012",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The Treaty of Guadalupe Hidalgo.docx",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "0013",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The Watergate.docx",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0014",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The Plame Affair.docx",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0015",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The Panama Papers",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0016",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The Paradise Papers",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0017",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Dreyfus affair.docx",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0018",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "French President Francois Hollande affair",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0019",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "JFK investigation",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0020",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Edward Snowden and the PRISM leak.docx",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "0021",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The Drone Papers.pdf",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0022",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The Area 51 File",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0023",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The X-Files.pdf",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0024",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "The Big Bertha",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0025",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Operation Neptune Spear",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "0026",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Reconnaissance missions: Black Shield",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0027",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Picture of the Operation Soft Touch.pdf",
		.file_icon = &Icon_Documents_Yellow
    },	
    {
        .file_id = "0028",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Death Stars design",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "0029",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Operation Sleepy Weasel.",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "0030",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "Starship Enterprise R/C Plans.pdf",
		.file_icon = &Icon_Documents_Yellow
    },
    {
        .file_id = "end",
        .file_info = "TAP HERE\nTo add a new\nFile",
    },
};