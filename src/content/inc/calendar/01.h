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


/* Create and initialize the Calendar_01 list */
static calendar_item calendar_01_list[] = {
    {
        .calendar_id = "0001",
        .calendar_title = "Stuart",
        .calendar_time_start = "08:00",
        .calendar_time_end = "09:00",
        .calendar_description = "Hayy Caramba, Banaaaaaa",
        .calendar_type_icon = &Icon_Empty_Dude,
    },
    {
        .calendar_id = "0002",
        .calendar_title = "Kevin meeting",
        .calendar_time_start = "10:00",
        .calendar_time_end = "12:00",
        .calendar_description = "Luca Banonooo, no no. C'est la Bananaaaaaa",
        .calendar_type_icon = &Icon_Phone,
    },
    {
        .calendar_id = "0003",
        .calendar_title = "Mini Boss",
        .calendar_time_start = "12:00",
        .calendar_time_end = "13:00",
        .calendar_description = "Macalo yeahhhhh, planning party",
        .calendar_type_icon = &Icon_Birthday,
    },
    {
        .calendar_id = "0004",
        .calendar_title = "Stuart, Kevin & Bob",
        .calendar_time_start = "15:00",
        .calendar_time_end = "16:00",
        .calendar_description = "Balatopa, okkk. Pancakeeeee",
        .calendar_type_icon = &Icon_Empty_Dude,
    },
    {
        .calendar_id = "0005",
        .calendar_title = "Meeting Gru",
        .calendar_time_start = "16:00",
        .calendar_time_end = "19:00",
        .calendar_description = "Plan to steal the moon",
        .calendar_type_icon = &Icon_Phone,
    },
    {
        .calendar_id = "end",
        .calendar_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};