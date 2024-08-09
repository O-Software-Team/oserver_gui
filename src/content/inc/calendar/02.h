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
static calendar_item calendar_02_list[] __attribute__((unused)) = {
    {
        .calendar_id = "0006",
        .calendar_title = "Talk with Dark Vader",
        .calendar_time_start = "08:00",
        .calendar_time_end = "10:00",
        .calendar_description = "Finishing the Death Star",
        .calendar_type_icon = &Icon_Phone,
    },
    {
        .calendar_id = "0007",
        .calendar_title = "Talk with Obi-Wan Kenobi",
        .calendar_time_start = "10:00",
        .calendar_time_end = "12:00",
        .calendar_description = "Planning to party with the Force and Dark side people",
        .calendar_type_icon = &Icon_Phone,
    },
    {
        .calendar_id = "0008",
        .calendar_title = "Dr. Emilio Lizardo joining",
        .calendar_time_start = "12:00",
        .calendar_time_end = "14:00",
        .calendar_description = "Talk about the party organized by the dark force",
        .calendar_type_icon = &Icon_Empty_Dude,
    },
    {
        .calendar_id = "0009",
        .calendar_title = "Lone Starr joining",
        .calendar_time_start = "16:00",
        .calendar_time_end = "18:00",
        .calendar_description = "Talk about the party organized by the dark force",
        .calendar_type_icon = &Icon_Empty_Dude,
    },
    {
        .calendar_id = "end",
        .calendar_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};
