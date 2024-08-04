/* List based upon the items created for use in an active Calendar App on a person's device -- from 01.json */

/*
    char * calendar_id;
    char * calendar_title;
    char * calendar_time_start;
    char * calendar_time_end;
    char * calendar_description;
    char * calendar_repeat;
    char * calendar_alert;
    char * calendar_show_as;
    char * calendar_notes;
    char * calendar_event_icon;
    char * calendar_type_icon;
*/


/* Create and initialize the Calendar_00 list */
static calendar_item calendar_00_list[] = {
    {
        .calendar_id = "0001",
        .calendar_title = "Buckaroo",
        .calendar_time_start = "Buckaroo",
        .calendar_time_end = "Keys",
        .calendar_description = "BK",
        .calendar_repeat = "Buckaroo+Banzai@gmail.com",
        .calendar_alert = "650.555.0201",
        .calendar_show_as = "757 Kingman Ave, Santa Monica, CA 90402",
        .calendar_notes = "Organization Name, Banzai Institute, Organization Title, CEO, Organization Department, ",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0002",
        .calendar_title = "Dr Emilio Lizardo",
        .calendar_time_start = "Emilio",
        .calendar_time_end = "Lizardo",
        .calendar_description = "EL",
        .calendar_repeat = "Emilio+Lizardo@gmail.com",
        .calendar_alert = "650.555.1212",
        .calendar_show_as = "8900 De Soto Ave, Canoga Park, CA 91304",
        .calendar_notes = "Yoyodyne Propulsion Systems",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0003",
        .calendar_title = "Professor Toichi Hikita",
        .calendar_time_start = "Toichi",
        .calendar_time_end = "Hikita",
        .calendar_description = "TH",
        .calendar_repeat = "Toichi+Hikita@gmail.com",
        .calendar_alert = "650.555.0202",
        .calendar_show_as = "757 Kingman Ave, Santa Monica, CA 90402",
        .calendar_notes = "Banzai Institute",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0004",
        .calendar_title = "Penny Priddy",
        .calendar_time_start = "Penny",
        .calendar_time_end = "Priddy",
        .calendar_description = "PP",
        .calendar_repeat = "Penny+Priddy@gmail.com",
        .calendar_alert = "650.555.0203",
        .calendar_show_as = "757 Kingman Ave, Santa Monica, CA 90402",
        .calendar_notes = "Banzai Institute",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0005",
        .calendar_title = "Rawhide",
        .calendar_time_start = "Rawhide",
        .calendar_time_end = "",
        .calendar_description = "RA",
        .calendar_repeat = "Rawhide@gmail.com",
        .calendar_alert = "650.555.0204",
        .calendar_show_as = "367 George St, New Brunswick, NJ 08901",
        .calendar_notes = "Hong Kong Cavaliers",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0006",
        .calendar_title = "Perfect Tommy",
        .calendar_time_start = "Perfect",
        .calendar_time_end = "Tommy",
        .calendar_description = "PT",
        .calendar_repeat = "Perfect+Tommy@gmail.com",
        .calendar_alert = "650.555.0205",
        .calendar_show_as = "367 George St, New Brunswick, NJ 08901",
        .calendar_notes = "Hong Kong Cavaliers",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0007",
        .calendar_title = "New Jersey",
        .calendar_time_start = "New",
        .calendar_time_end = "Jersey",
        .calendar_description = "NJ",
        .calendar_repeat = "New+Jersey@gmail.com",
        .calendar_alert = "650.555.0206",
        .calendar_show_as = "367 George St, New Brunswick, NJ 08901",
        .calendar_notes = "Hong Kong Cavaliers",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0008",
        .calendar_title = "Reno Nevada",
        .calendar_time_start = "Reno",
        .calendar_time_end = "Nevada",
        .calendar_description = "RN",
        .calendar_repeat = "Reno+Nevada@gmail.com",
        .calendar_alert = "650.555.0207",
        .calendar_show_as = "367 George St, New Brunswick, NJ 08901",
        .calendar_notes = "Hong Kong Cavaliers",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0009",
        .calendar_title = "The Swede",
        .calendar_time_start = "Swede",
        .calendar_time_end = "",
        .calendar_description = "TS",
        .calendar_repeat = "Swede@gmail.com",
        .calendar_alert = "650.555.0214",
        .calendar_show_as = "367 George St, New Brunswick, NJ 08901",
        .calendar_notes = "Hong Kong Cavaliers",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0010",
        .calendar_title = "Scooter Lindley",
        .calendar_time_start = "Scooter",
        .calendar_time_end = "Lindley",
        .calendar_description = "SL",
        .calendar_repeat = "Scooter+Lindley@gmail.com",
        .calendar_alert = "650.555.0209",
        .calendar_show_as = "2010 El Camino Real, San Mateo, CA 94403",
        .calendar_notes = "Blue Blaze Irregulars",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0011",
        .calendar_title = "Pinky Carruthers",
        .calendar_time_start = "Pinky",
        .calendar_time_end = "Carruthers",
        .calendar_description = "PC",
        .calendar_repeat = "Pinky+Carruthers@gmail.com",
        .calendar_alert = "650.555.0210",
        .calendar_show_as = "2010 El Camino Real, San Mateo, CA 94403",
        .calendar_notes = "Blue Blaze Irregulars",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "0012",
        .calendar_title = "Billy Travers",
        .calendar_time_start = "Billy",
        .calendar_time_end = "Travers",
        .calendar_description = "BT",
        .calendar_repeat = "Billy+Travers@gmail.com",
        .calendar_alert = "650.555.0211",
        .calendar_show_as = "2010 El Camino Real, San Mateo, CA 94403",
        .calendar_notes = "Blue Blaze Irregulars",
        .calendar_event_icon = "Birthday",
        .calendar_type_icon = "Meeting"
    },
    {
        .calendar_id = "end",
        .calendar_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};