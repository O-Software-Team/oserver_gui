
/* List based upon the items created for use in an active Contacts App on a person's mobile fone -- from 01.json */

/*
    char * contact_id;
    char * contact_fname;
    char * contact_lname;
    char * contact_name;
    char * contact_initials;
    char * contact_p_phone;
    char * contact_m_phone;
    char * contact_w_phone;
    char * contact_p_email;
    char * contact_w_email;
    char * contact_p_address;
    char * contact_w_address;
    char * contact_company_name;
    char * contact_notes;
    // char * contact_status;
    // void (* page_handler)(lv_obj_t *);
    lv_img_dsc_t * contact_status;
    // bool active;
*/

/* Create and initialize the Contacts list */
static contacts_item contacts_list[] = {
    {
        .contact_id = "0001",
        .contact_name = "Buckaroo Banzai",
        .contact_fname = "Buckaroo",
        .contact_lname = "Banzai",
        .contact_initials = "BB",
        .contact_p_email = "Buckaroo+Banzai@gmail.com",
        .contact_m_phone = "650.555.0201",
        .contact_w_address = "757 Kingman Ave, Santa Monica, CA 90402",
        .contact_company_name = "Banzai Institute",
        .contact_notes = "Organization Name, Banzai Institute, Organization Title, CEO, Organization Department, "
    },
    {
        .contact_id = "0002",
        .contact_name = "Dr Emilio Lizardo",
        .contact_fname = "Emilio",
        .contact_lname = "Lizardo",
        .contact_initials = "EL",
        .contact_p_email = "Emilio+Lizardo@gmail.com",
        .contact_m_phone = "650.555.1212",
        .contact_w_address = "8900 De Soto Ave, Canoga Park, CA 91304",
        .contact_company_name = "Yoyodyne Propulsion Systems",
        .contact_notes = "Organization Name, Yoyodyne Propulsion Systems, Organization Title, Doctor, Organization Department, Overthruster Design",
    },
    {
        .contact_id = "0003",
        .contact_name = "Professor Toichi Hikita",
        .contact_fname = "Toichi",
        .contact_lname = "Hikita",
        .contact_initials = "TH",
        .contact_p_email = "Toichi+Hikita@gmail.com",
        .contact_m_phone = "650.555.0202",
        .contact_w_address = "757 Kingman Ave, Santa Monica, CA 90402",
        .contact_company_name = "Banzai Institute",
        .contact_notes = "Organization Name, Banzai Institute, Organization Title, Chairman, Organization Department, Research and Development",
    },
    {
        .contact_id = "0004",
        .contact_name = "Penny Priddy",
        .contact_fname = "Penny",
        .contact_lname = "Priddy",
        .contact_initials = "PP",
        .contact_p_email = "Penny+Priddy@gmail.com",
        .contact_m_phone = "650.555.0203",
        .contact_w_address = "757 Kingman Ave, Santa Monica, CA 90402",
        .contact_company_name = "Banzai Institute",
        .contact_notes = "Organization Name, Banzai Institute, Organization Title, Theoretical Assistant, Organization Department, Asset Mgmt"
    },
    {
        .contact_id = "0005",
        .contact_name = "Rawhide",
        .contact_fname = "Rawhide",
        .contact_lname = "",
        .contact_initials = "RA",
        .contact_p_email = "Rawhide@gmail.com",
        .contact_m_phone = "650.555.0204",
        .contact_w_address = "367 George St, New Brunswick, NJ 08901",
        .contact_company_name = "Hong Kong Cavaliers",
        .contact_notes = "Organization Name, Hong Kong Cavaliers, Organization Title, Musician, Organization Department, "
    },
    {
        .contact_id = "0006",
        .contact_name = "Perfect Tommy",
        .contact_fname = "Perfect",
        .contact_lname = "Tommy",
        .contact_initials = "PT",
        .contact_p_email = "Perfect+Tommy@gmail.com",
        .contact_m_phone = "650.555.0205",
        .contact_w_address = "367 George St, New Brunswick, NJ 08901",
        .contact_company_name = "Hong Kong Cavaliers",
        .contact_notes = "Organization Name, Hong Kong Cavaliers, Organization Title, Musician, Organization Department, "
    },
    {
        .contact_id = "0007",
        .contact_name = "New Jersey",
        .contact_fname = "New",
        .contact_lname = "Jersey",
        .contact_initials = "NJ",
        .contact_p_email = "New+Jersey@gmail.com",
        .contact_m_phone = "650.555.0206",
        .contact_w_address = "367 George St, New Brunswick, NJ 08901",
        .contact_company_name = "Hong Kong Cavaliers",
        .contact_notes = "Organization Name, Hong Kong Cavaliers, Organization Title, Musician, Organization Department, "
    },
    {
        .contact_id = "0008",
        .contact_name = "Reno Nevada",
        .contact_fname = "Reno",
        .contact_lname = "Nevada",
        .contact_initials = "RN",
        .contact_p_email = "Reno+Nevada@gmail.com",
        .contact_m_phone = "650.555.0207",
        .contact_w_address = "367 George St, New Brunswick, NJ 08901",
        .contact_company_name = "Hong Kong Cavaliers",
        .contact_notes = "Organization Name, Hong Kong Cavaliers, Organization Title, Musician, Organization Department, "
    },
    {
        .contact_id = "0009",
        .contact_name = "The Swede",
        .contact_fname = "Swede",
        .contact_lname = "",
        .contact_initials = "TS",
        .contact_p_email = "Swede@gmail.com",
        .contact_m_phone = "650.555.0214",
        .contact_w_address = "367 George St, New Brunswick, NJ 08901",
        .contact_company_name = "Hong Kong Cavaliers",
        .contact_notes = "Organization Name, Hong Kong Cavaliers, Organization Title, Musician, Organization Department, "
    },
    {
        .contact_id = "0010",
        .contact_name = "Scooter Lindley",
        .contact_fname = "Scooter",
        .contact_lname = "Lindley",
        .contact_initials = "SL",
        .contact_p_email = "Scooter+Lindley@gmail.com",
        .contact_m_phone = "650.555.0209",
        .contact_w_address = "2010 El Camino Real, San Mateo, CA 94403",
        .contact_company_name = "Blue Blaze Irregulars",
        .contact_notes = "Organization Name, Blue Blaze Irregulars, Organization Title, Team Member, Organization Department, "
    },
    {
        .contact_id = "0011",
        .contact_name = "Pinky Carruthers",
        .contact_fname = "Pinky",
        .contact_lname = "Carruthers",
        .contact_initials = "PC",
        .contact_p_email = "Pinky+Carruthers@gmail.com",
        .contact_m_phone = "650.555.0210",
        .contact_w_address = "2010 El Camino Real, San Mateo, CA 94403",
        .contact_company_name = "Blue Blaze Irregulars",
        .contact_notes = "Organization Name, Blue Blaze Irregulars, Organization Title, Team Member, Organization Department, "
    },
    {
        .contact_id = "0012",
        .contact_name = "Billy Travers",
        .contact_fname = "Billy",
        .contact_lname = "Travers",
        .contact_initials = "BT",
        .contact_p_email = "Billy+Travers@gmail.com",
        .contact_m_phone = "650.555.0211",
        .contact_w_address = "2010 El Camino Real, San Mateo, CA 94403",
        .contact_company_name = "Blue Blaze Irregulars",
        .contact_notes = "Organization Name, Blue Blaze Irregulars, Organization Title, Team Member, Organization Department, "
    },
    {
        .contact_id = "0013",
        .contact_name = "Dr Masado Banzai",
        .contact_fname = "Masado",
        .contact_lname = "Banzai",
        .contact_initials = "MB",
        .contact_p_email = "Masado+Banzai@gmail.com",
        .contact_m_phone = "650.555.0212",
        .contact_w_address = "500 W University Ave, El Paso, TX 79968",
        .contact_company_name = "UT El Paso",
        .contact_notes = "Organization Name, UT El Paso, Organization Title, Scientist, Organization Department, "
    },
    {
        .contact_id = "0014",
        .contact_name = "Dr Sandra Banzai",
        .contact_fname = "Sandra",
        .contact_lname = "Banzai",
        .contact_initials = "SB",
        .contact_p_email = "Sandra+Banzai@gmail.com",
        .contact_m_phone = "650.555.0213",
        .contact_w_address = "500 W University Ave, El Paso, TX 79968",
        .contact_company_name = "UT El Paso",
        .contact_notes = "Organization Name, UT El Paso, Organization Title, Scientist, Organization Department, "
    },
    {
        .contact_id = "0015",
        .contact_name = "Lord John Whorfin",
        .contact_fname = "John",
        .contact_lname = "Whorfin",
        .contact_initials = "JW",
        .contact_p_email = "John+Whorfin@gmail.com",
        .contact_m_phone = "650.555.1212",
        .contact_w_address = "8900 De Soto Ave, Canoga Park, CA 91304",
        .contact_company_name = "Yoyodyne Propulsion Systems",
        .contact_notes = "Organization Name, Yoyodyne Propulsion Systems, Organization Title, , Organization Department, "
    },
    {
        .contact_id = "0016",
        .contact_name = "John Parker",
        .contact_fname = "John",
        .contact_lname = "Parker",
        .contact_initials = "JP",
        .contact_p_email = "John+Parker@gmail.com",
        .contact_m_phone = "650.555.0208",
        .contact_w_address = "Planet 10, Redwood City, CA 94063",
        .contact_company_name = "Planet 10",
        .contact_notes = "Organization Name, Planet 10, Organization Title, Pilot, Organization Department, Lectroid Flight Team"
    },
    {
        .contact_id = "0017",
        .contact_name = "John O'Connor",
        .contact_fname = "John",
        .contact_lname = "O'Connor",
        .contact_initials = "JO",
        .contact_p_email = "John+O'Connor@gmail.com",
        .contact_m_phone = "650.555.1212",
        .contact_w_address = "8900 De Soto Ave, Canoga Park, CA 91304",
        .contact_company_name = "Yoyodyne Propulsion Systems",
        .contact_notes = "Organization Name, Yoyodyne Propulsion Systems, Organization Title, Lord, Organization Department, Lectroid Commander"
    },
    {
        .contact_id = "0018",
        .contact_name = "John Emdall",
        .contact_fname = "John",
        .contact_lname = "Emdall",
        .contact_initials = "JE",
        .contact_p_email = "John+Emdall@gmail.com",
        .contact_m_phone = "650.555.0208",
        .contact_w_address = "Planet 10, Redwood City, CA 94063",
        .contact_company_name = "Planet 10",
        .contact_notes = "Organization Name, Planet 10, Organization Title, Chief, Organization Department, Black Lectroids"
    },
    {
        .contact_id = "0019",
        .contact_name = "John Bigboote",
        .contact_fname = "John",
        .contact_lname = "Bigboote",
        .contact_initials = "JB",
        .contact_p_email = "John+Bigboote@gmail.com",
        .contact_m_phone = "650.555.1212",
        .contact_w_address = "8900 De Soto Ave, Canoga Park, CA 91304",
        .contact_company_name = "Yoyodyne Propulsion Systems",
        .contact_notes = "Organization Name, Yoyodyne Propulsion Systems, Organization Title, , Organization Department, "
    },
    {
        .contact_id = "0020",
        .contact_name = "John Wright",
        .contact_fname = "John",
        .contact_lname = "Wright",
        .contact_initials = "JW",
        .contact_p_email = "John+Wright@gmail.com",
        .contact_m_phone = "650.555.1212",
        .contact_w_address = "8900 De Soto Ave, Canoga Park, CA 91304",
        .contact_company_name = "Yoyodyne Propulsion Systems",
        .contact_notes = "Organization Name, Yoyodyne Propulsion Systems, Organization Title, , Organization Department, "
    },
    {
        .contact_id = "end",
        .contact_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};