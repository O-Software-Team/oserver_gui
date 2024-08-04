/* List based upon the items created for use in an active Calendar App on a person's device -- from 01.json */

/*
    char * calendar_id;
    char * calendar_title;
    char * calendar_year;
    char * calendar_month;
    char * calendar_day;
    char * calendar_time_start;
    char * calendar_time_end;
    char * calendar_time_duration;
    char * calendar_time_period;
    char * calendar_time_zone;
    char * calendar_description;
    char * calendar_repeat;
    char * calendar_alert;
    char * calendar_show_as;
    char * calendar_notes;
    const lv_img_dsc_t * calendar_event_icon;
    const lv_img_dsc_t * calendar_type_icon;
*/


/* Create and initialize the Calendar_00 list */
static calendar_item calendar_06_list[] = {
    {
        .calendar_id = "0022",
        .calendar_title = "Discussion with Bart & Jim",
        .calendar_time_start = "09:00",
        .calendar_time_end = "10:00",
        .calendar_description = "Why, Rhett! How many times have I told you to wash up after weekly cross burning?",
        .calendar_type_icon = &Icon_Phone
    },
    {
        .calendar_id = "0023",
        .calendar_title = "Caslte taken by who?",
        .calendar_time_start = "10:00",
        .calendar_time_end = "11:00",
        .calendar_description = "Blinkin, listen to me. They've taken the castle!",
        .calendar_type_icon = &Icon_Empty_Dude
    },
    {
        .calendar_id = "0024",
        .calendar_title = "Meeting Malory Archer",
        .calendar_time_start = "11:00",
        .calendar_time_end = "12:00",
        .calendar_description = "The classic Irishman’s dilemma: Do I eat the potato or do I let it ferment so I can drink it later?",
        .calendar_type_icon = &Icon_Phone
    },
    {
        .calendar_id = "0025",
        .calendar_title = "Birthday Doctor Krieger",
        .calendar_time_start = "14:00",
        .calendar_time_end = "15:00",
        .calendar_description = "Yep Yep Yep",
        .calendar_type_icon = &Icon_Birthday
    },
    {
        .calendar_id = "0026",
        .calendar_title = "Chat with Pam Poovey",
        .calendar_time_start = "15:00",
        .calendar_time_end = "16:00",
        .calendar_description = "Why on Earth do you feel you're qualified to be an ISIS field agent",
        .calendar_type_icon = &Icon_Empty_Dude
    },
    {
        .calendar_id = "end",
        .calendar_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};