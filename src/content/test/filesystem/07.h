/* List to provide a sample of spreadsheets found on the device */

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
static filesystem_item filesystem_07_list[] = {
    {
        .file_id = "0001",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "13829",
        .file_modified = "May 18 2023",
        .file_fullname = "CPA Account firm.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0002",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "150630",
        .file_modified = "May 18 2023",
        .file_fullname = "Agency contact.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0003",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "578874",
        .file_modified = "May 18 2023",
        .file_fullname = "Statement of Qualifications.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0004",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "147396",
        .file_modified = "May 18 2023",
        .file_fullname = "Resolutions for Corporation.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0005",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Annual Information Sheet.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0006",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Partner list.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0007",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Product technical spec.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0008",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Connected Industries.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0009",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Sponsorship Branding Opportunities.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0011",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Team Member.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0012",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Electronic Components Distributor.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0013",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "PROTOTYPE INVENTORY.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0014",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Annual Information Sheet.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0015",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "401K & Benefits.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0016",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Candidate list.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0017",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Machine in the lab.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0018",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Office amenities.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0019",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Fortune 500 target.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0020",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Cloud system.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0021",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Human resources.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0022",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Number of UFO.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0023",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Customer List.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0024",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Playtopoi.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0025",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Chest combination.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0026",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Shark Island competition.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0027",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "El Fronton.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0028",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Matrix.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0029",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Twister.xlsx",
		.file_icon = &Icon_Excel_Yellow
    },
    {
        .file_id = "0030",
        .file_permissions = "-rw-r--r--@",
        .file_owner = "steveglaiser",
        .file_group = "staff",
        .file_type = "file",
        .file_size = "572472",
        .file_modified = "May 18 2023",
        .file_fullname = "Official Invited List.xlsx",
		.file_icon = &Icon_Excel_Yellow
    }, 
    {
        .file_id = "end",
        .file_info = "TAP HERE\nTo add a new\nFile",
    },
};