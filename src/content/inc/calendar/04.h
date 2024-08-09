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
static calendar_item calendar_04_list[] __attribute__((unused)) = {
    {
        .calendar_id = "0014",
        .calendar_title = "Louis XIV",
        .calendar_time_start = "10:00",
        .calendar_time_end = "11:00",
        .calendar_description = "It's good to be the king",
        .calendar_type_icon = &Icon_Birthday
    },
    {
        .calendar_id = "0015",
        .calendar_title = "Napoléon Bonaparte",
        .calendar_time_start = "11:00",
        .calendar_time_end = "12:00",
        .calendar_description = "In politics, stupidity is not a handicap",
        .calendar_type_icon = &Icon_Birthday
    },
    {
        .calendar_id = "0016",
        .calendar_title = "Buckaroo Banzai",
        .calendar_time_start = "14:00",
        .calendar_time_end = "16:00",
        .calendar_description = "Across the 8th Dimension experiment",
        .calendar_type_icon = &Icon_Phone
    },
    {
        .calendar_id = "0017",
        .calendar_title = "Jim 'Wash Out' Pfaffenbach Job",
        .calendar_time_start = "10:00",
        .calendar_time_end = "11:00",
        .calendar_description = "They put me in charge of radar! From now on, I'll be your eyes on the ground!",
        .calendar_type_icon = &Icon_Birthday
    },
    {
        .calendar_id = "end",
        .calendar_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};
