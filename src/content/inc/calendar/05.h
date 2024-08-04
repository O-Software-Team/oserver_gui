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
static calendar_item calendar_05_list[] = {
    {
        .calendar_id = "0018",
        .calendar_title = "Capitaine Ed Hocken meeting",
        .calendar_time_start = "10:00",
        .calendar_time_end = "11:00",
        .calendar_description = "Who is the auditor?",
        .calendar_type_icon = &Icon_Empty_Dude
    },
    {
        .calendar_id = "0019",
        .calendar_title = "Frank Drebbin Birthday",
        .calendar_time_start = "11:00",
        .calendar_time_end = "12:00",
        .calendar_description = "Okay, than after he shot the teller, who shot him twice?",
        .calendar_type_icon = &Icon_Birthday
    },
    {
        .calendar_id = "0020",
        .calendar_title = "Meeting Mr. Unger & Mr. Dunn",
        .calendar_time_start = "13:00",
        .calendar_time_end = "14:00",
        .calendar_description = "Presentation navigator, Mr. Unger, and your first officer Mr. Dunn",
        .calendar_type_icon = &Icon_Empty_Dude
    },
    {
        .calendar_id = "0021",
        .calendar_title = "Sell my plan",
        .calendar_time_start = "15:00",
        .calendar_time_end = "16:00",
        .calendar_description = "Convince Cameron to come pick me up",
        .calendar_type_icon = &Icon_Phone
    },
    {
        .calendar_id = "end",
        .calendar_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};