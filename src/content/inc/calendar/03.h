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
static calendar_item calendar_03_list[] __attribute__((unused)) = {
    {   
        .calendar_id = "0010",
        .calendar_title = "Invade planet Earth",
        .calendar_time_start = "08:00",
        .calendar_time_end = "10:00",
        .calendar_description = "Constructed an escape vessel so the Red Lectroids could return to Planet 10",
        .calendar_type_icon = &Icon_Phone
    },
    {
        .calendar_id = "0011",
        .calendar_title = "Banzai back to Earth ",
        .calendar_time_start = "10:00",
        .calendar_time_end = "11:00",
        .calendar_description = "Destroy Whorfin and the other Red Lectroids",
        .calendar_type_icon = &Icon_Empty_Dude
    },
    {
        .calendar_id = "0012",
        .calendar_title = "Dr. Frederick Frankenstein",
        .calendar_time_start = "11:00",
        .calendar_time_end = "12:00",
        .calendar_description = "Help Igor with that hump.",
        .calendar_type_icon = &Icon_Phone
    },
    {
        .calendar_id = "0013",
        .calendar_title = "Igor",
        .calendar_time_start = "14:00",
        .calendar_time_end = "15:00",
        .calendar_description = "Well, why isn't it Froaderick Fronkensteen?",
        .calendar_type_icon = &Icon_Empty_Dude
    },
    {
        .calendar_id = "end",
        .calendar_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};
