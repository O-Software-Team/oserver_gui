/* List based upon the items created for use in an active Calendar App on a person's device -- from 01.json */

/*
    char * album_id;
    char * album_name;
    char * album_artist;
    char * album_song_title;
    char * album_song_length;
    char * album_date;
    char * album_genre;
    char * album_era;
    const lv_img_dsc_t * album_cover_icon;
    const lv_img_dsc_t * album_song_icon;
*/

/* Music Player Iconography */
LV_IMG_DECLARE(Music_Player_Controls_Play);

/* Music Album Cover declarations -- All images are set to 60x60 px */
LV_IMG_DECLARE(Album_10cc_Wall_Street_Shuffle);
LV_IMG_DECLARE(Album_A_Tribe_Called_Quest_Luck_Of_Lucien);
LV_IMG_DECLARE(Album_Bob_Marley_And_The_Wailers_Sun_Is_Shining);
LV_IMG_DECLARE(Album_Brick_Dazz);
LV_IMG_DECLARE(Album_Chemlab_Suicide_Jag);
LV_IMG_DECLARE(Album_David_Bowie_Fame);
LV_IMG_DECLARE(Album_Deep_Purple_Smoke_On_The_Water);
LV_IMG_DECLARE(Album_Dio_Holy_Diver);
LV_IMG_DECLARE(Album_DJ_Premier_Classic);
LV_IMG_DECLARE(Album_Gang_Starr_Mass_Appeal);
LV_IMG_DECLARE(Album_Grateful_Dead_Fire_On_The_Mountain);
LV_IMG_DECLARE(Album_Iggy_Pop_The_Passenger);
LV_IMG_DECLARE(Album_Machines_Of_Loving_Grace_Butterfly_Wings);
LV_IMG_DECLARE(Album_Metallica_Fade_To_Black);
LV_IMG_DECLARE(Album_Nirvana_Lithium);
LV_IMG_DECLARE(Album_Norman_Greenbaum_Spirit_In_The_Sky);
LV_IMG_DECLARE(Album_Phil_Collins_Youll_Be_In_My_Heart);
LV_IMG_DECLARE(Album_Pink_Floyd_Another_Brick_In_The_Wall);
LV_IMG_DECLARE(Album_Rage_Against_The_Machine_Killing_In_The_Name);
LV_IMG_DECLARE(Album_Rammstein_Du_Hast);
LV_IMG_DECLARE(Album_Reo_Speedwagon_Roll_With_The_Changes);
LV_IMG_DECLARE(Album_Steely_Dan_Do_It_Again);
LV_IMG_DECLARE(Album_Stevie_Wonder_Hey_Love);
LV_IMG_DECLARE(Album_Sweet_Fox_On_The_Run);
LV_IMG_DECLARE(Album_Telephone_Hygiaphone);
LV_IMG_DECLARE(Album_The_Clash_The_Magnificent_Seven);
LV_IMG_DECLARE(Album_The_Kinks_You_Really_Got_Me);
LV_IMG_DECLARE(Album_The_Rolling_Stones_Gimme_Shelter);
LV_IMG_DECLARE(Album_U2_The_Unforgettable_Fire);
LV_IMG_DECLARE(Album_War_Low_Rider);

/* Music Album Cover Song declarations -- All images are set to 210x210 px */
LV_IMG_DECLARE(Song_10cc_Wall_Street_Shuffle);
LV_IMG_DECLARE(Song_A_Tribe_Called_Quest_Luck_Of_Lucien);
LV_IMG_DECLARE(Song_Bob_Marley_And_The_Wailers_Sun_Is_Shining);
LV_IMG_DECLARE(Song_Brick_Dazz);
LV_IMG_DECLARE(Song_Chemlab_Suicide_Jag);
LV_IMG_DECLARE(Song_David_Bowie_Fame);
LV_IMG_DECLARE(Song_Deep_Purple_Smoke_On_The_Water);
LV_IMG_DECLARE(Song_Dio_Holy_Diver);
LV_IMG_DECLARE(Song_DJ_Premier_Classic);
LV_IMG_DECLARE(Song_Gang_Starr_Mass_Appeal);
LV_IMG_DECLARE(Song_Grateful_Dead_Fire_On_The_Mountain);
LV_IMG_DECLARE(Song_Iggy_Pop_The_Passenger);
LV_IMG_DECLARE(Song_Machines_Of_Loving_Grace_Butterfly_Wings);
LV_IMG_DECLARE(Song_Metallica_Fade_To_Black);
LV_IMG_DECLARE(Song_Nirvana_Lithium);
LV_IMG_DECLARE(Song_Norman_Greenbaum_Spirit_In_The_Sky);
LV_IMG_DECLARE(Song_Phil_Collins_Youll_Be_In_My_Heart);
LV_IMG_DECLARE(Song_Pink_Floyd_Another_Brick_In_The_Wall);
LV_IMG_DECLARE(Song_Rage_Against_The_Machine_Killing_In_The_Name);
LV_IMG_DECLARE(Song_Rammstein_Du_Hast);
LV_IMG_DECLARE(Song_Reo_Speedwagon_Roll_With_The_Changes);
LV_IMG_DECLARE(Song_Steely_Dan_Do_It_Again);
LV_IMG_DECLARE(Song_Stevie_Wonder_Hey_Love);
LV_IMG_DECLARE(Song_Sweet_Fox_On_The_Run);
LV_IMG_DECLARE(Song_Telephone_Hygiaphone);
LV_IMG_DECLARE(Song_The_Clash_The_Magnificent_Seven);
LV_IMG_DECLARE(Song_The_Kinks_You_Really_Got_Me);
LV_IMG_DECLARE(Song_The_Rolling_Stones_Gimme_Shelter);
LV_IMG_DECLARE(Song_U2_The_Unforgettable_Fire);
LV_IMG_DECLARE(Song_War_Low_Rider);

/* Create and initialize the Calendar_00 list */
static music_item music_00_list[] = {
    {
        .album_id = "0001",
        .album_artist = "10cc",
        .album_song_title = "Wall Street Shuffle",
        .album_name = "Sheet Music",
        .album_cover_icon = &Album_10cc_Wall_Street_Shuffle,
        .album_song_icon = &Song_10cc_Wall_Street_Shuffle
    },
    {
        .album_id = "0002",
        .album_artist = "A Tribe Called Quest",
        .album_song_title = "Luck of Lucien",
        .album_name = "The Anthology",
        .album_cover_icon = &Album_A_Tribe_Called_Quest_Luck_Of_Lucien,
        .album_song_icon = &Song_A_Tribe_Called_Quest_Luck_Of_Lucien
    },
    {
        .album_id = "0003",
        .album_artist = "Bob Marley & The Wailers",
        .album_song_title = "Sun Is Shining",
        .album_name = "Soul Revolution",
        .album_cover_icon = &Album_Bob_Marley_And_The_Wailers_Sun_Is_Shining,
        .album_song_icon = &Song_Bob_Marley_And_The_Wailers_Sun_Is_Shining
    },
    {
        .album_id = "0004",
        .album_artist = "Brick",
        .album_song_title = "Dazz",
        .album_name = "Good High",
        .album_cover_icon = &Album_Brick_Dazz,
        .album_song_icon = &Song_Brick_Dazz
    },
    {
        .album_id = "0005",
        .album_artist = "Chemlab",
        .album_song_title = "Suicide Jag",
        .album_name = "Burn Out at the Hydrogen Bar",
        .album_cover_icon = &Album_Chemlab_Suicide_Jag,
        .album_song_icon = &Song_Chemlab_Suicide_Jag
    },
    {
        .album_id = "0006",
        .album_artist = "David Bowie",
        .album_song_title = "Fame",
        .album_name = "Young Americans",
        .album_cover_icon = &Album_David_Bowie_Fame,
        .album_song_icon = &Song_David_Bowie_Fame
    },
    {
        .album_id = "0007",
        .album_artist = "Deep Purple",
        .album_song_title = "Smoke On The Water",
        .album_name = "Machine Head",
        .album_cover_icon = &Album_Deep_Purple_Smoke_On_The_Water,
        .album_song_icon = &Song_Deep_Purple_Smoke_On_The_Water
    },
    {
        .album_id = "0008",
        .album_artist = "Dio",
        .album_song_title = "Holy Diver",
        .album_name = "Holy Diver",
        .album_cover_icon = &Album_Dio_Holy_Diver,
        .album_song_icon = &Song_Dio_Holy_Diver
    },
    {
        .album_id = "0009",
        .album_artist = "Dj Premier",
        .album_song_title = "Classic",
        .album_name = "Calssic",
        .album_cover_icon = &Album_DJ_Premier_Classic,
        .album_song_icon = &Song_DJ_Premier_Classic
    },
    {
        .album_id = "0010",
        .album_artist = "Gang Starr",
        .album_song_title = "Mass Appeal",
        .album_name = "Hard to Earn",
        .album_cover_icon = &Album_Gang_Starr_Mass_Appeal,
        .album_song_icon = &Song_Gang_Starr_Mass_Appeal
    },
    {
        .album_id = "0011",
        .album_artist = "Grateful Dead",
        .album_song_title = "Fire on the Mountain",
        .album_name = "Shakedown Street",
        .album_cover_icon = &Album_Grateful_Dead_Fire_On_The_Mountain,
        .album_song_icon = &Song_Grateful_Dead_Fire_On_The_Mountain
    },
    {
        .album_id = "0012",
        .album_artist = "Iggy Pop",
        .album_song_title = "The Passenger",
        .album_name = "Lust for Life",
        .album_cover_icon = &Album_Iggy_Pop_The_Passenger,
        .album_song_icon = &Song_Iggy_Pop_The_Passenger
    },
    {
        .album_id = "0013",
        .album_artist = "Machines of Loving Grace",
        .album_song_title = "Butterfly Wings",
        .album_name = "Concentration",
        .album_cover_icon = &Album_Machines_Of_Loving_Grace_Butterfly_Wings,
        .album_song_icon = &Song_Machines_Of_Loving_Grace_Butterfly_Wings
    },
    {
        .album_id = "0014",
        .album_artist = "Metallica",
        .album_song_title = "Fade to Black",
        .album_name = "Ride the Lightning",
        .album_cover_icon = &Album_Metallica_Fade_To_Black,
        .album_song_icon = &Song_Metallica_Fade_To_Black
    },
    {
        .album_id = "0015",
        .album_artist = "Nirvana",
        .album_song_title = "Lithium",
        .album_name = "Nevermind",
        .album_cover_icon = &Album_Nirvana_Lithium,
        .album_song_icon = &Song_Nirvana_Lithium
    },
    {
        .album_id = "0016",
        .album_artist = "Norman Greenbaum",
        .album_song_title = "Spirit In The Sky",
        .album_name = "Spirit In The Sky",
        .album_cover_icon = &Album_Norman_Greenbaum_Spirit_In_The_Sky,
        .album_song_icon = &Song_Norman_Greenbaum_Spirit_In_The_Sky
    },
    {
        .album_id = "0017",
        .album_artist = "Phil Collins",
        .album_song_title = "You'll Be In My Heart",
        .album_name = "Tarzan Soundtrack",
        .album_cover_icon = &Album_Phil_Collins_Youll_Be_In_My_Heart,
        .album_song_icon = &Song_Phil_Collins_Youll_Be_In_My_Heart
    },
    {
        .album_id = "0018",
        .album_artist = "Pink Floyd",
        .album_song_title = "Another brick in the wall",
        .album_name = "The Wall",
        .album_cover_icon = &Album_Pink_Floyd_Another_Brick_In_The_Wall,
        .album_song_icon = &Song_Pink_Floyd_Another_Brick_In_The_Wall
    },
    {
        .album_id = "0019",
        .album_artist = "Rage Against The Machine",
        .album_song_title = "Killing In the Name",
        .album_name = "Rage Against The Machine",
        .album_cover_icon = &Album_Rage_Against_The_Machine_Killing_In_The_Name,
        .album_song_icon = &Song_Rage_Against_The_Machine_Killing_In_The_Name
    },
    {
        .album_id = "0020",
        .album_artist = "Rammstein",
        .album_song_title = "Du Hast",
        .album_name = "Sehnsucht",
        .album_cover_icon = &Album_Rammstein_Du_Hast,
        .album_song_icon = &Song_Rammstein_Du_Hast
    },
    {
        .album_id = "0021",
        .album_artist = "Reo Speedwagon",
        .album_song_title = "Roll With The Changes",
        .album_name = "You Can Tune a Piano, but You Can't Tuna Fish",
        .album_cover_icon = &Album_Reo_Speedwagon_Roll_With_The_Changes,
        .album_song_icon = &Song_Reo_Speedwagon_Roll_With_The_Changes
    },
    {
        .album_id = "0022",
        .album_artist = "Steely Dan",
        .album_song_title = "Do it again",
        .album_name = "Can't Buy a Thrill",
        .album_cover_icon = &Album_Steely_Dan_Do_It_Again,
        .album_song_icon = &Song_Steely_Dan_Do_It_Again
    },
    {
        .album_id = "0023",
        .album_artist = "Stevie Wonder",
        .album_song_title = "Hey Love",
        .album_name = "Down to Earth",
        .album_cover_icon = &Album_Stevie_Wonder_Hey_Love,
        .album_song_icon = &Song_Stevie_Wonder_Hey_Love
    },
    {
        .album_id = "0024",
        .album_artist = "Sweet",
        .album_song_title = "Fox On The Run",
        .album_name = "Desolation Boulevard",
        .album_cover_icon = &Album_Sweet_Fox_On_The_Run,
        .album_song_icon = &Song_Sweet_Fox_On_The_Run
    },
    {
        .album_id = "0025",
        .album_artist = "Telephone",
        .album_song_title = "Hygiaphone",
        .album_name = "Telephone",
        .album_cover_icon = &Album_Telephone_Hygiaphone,
        .album_song_icon = &Song_Telephone_Hygiaphone
    },
    {
        .album_id = "0026",
        .album_artist = "The Clash",
        .album_song_title = "The Magnificent Seven",
        .album_name = "Sandinista!",
        .album_cover_icon = &Album_The_Clash_The_Magnificent_Seven,
        .album_song_icon = &Song_The_Clash_The_Magnificent_Seven
    },
    {
        .album_id = "0027",
        .album_artist = "The Kinks",
        .album_song_title = "You Really Got Me",
        .album_name = "You Really Got Me",
        .album_cover_icon = &Album_The_Kinks_You_Really_Got_Me,
        .album_song_icon = &Song_The_Kinks_You_Really_Got_Me
    },
    {
        .album_id = "0028",
        .album_artist = "The Rolling Stones",
        .album_song_title = "Gimme Shelter",
        .album_name = "Let It Bleed",
        .album_cover_icon = &Album_The_Rolling_Stones_Gimme_Shelter,
        .album_song_icon = &Song_The_Rolling_Stones_Gimme_Shelter
    },
    {
        .album_id = "0029",
        .album_artist = "U2",
        .album_song_title = "The Unforgettable Fire",
        .album_name = "The Unforgettable Fire",
        .album_cover_icon = &Album_U2_The_Unforgettable_Fire,
        .album_song_icon = &Song_U2_The_Unforgettable_Fire
    },
    {
        .album_id = "0030",
        .album_artist = "War",
        .album_song_title = "Low Rider",
        .album_name = "Why Can't We Be Friends?",
        .album_cover_icon = &Album_War_Low_Rider,
        .album_song_icon = &Song_War_Low_Rider
    },
    {
        .album_id = "end",
        .album_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};