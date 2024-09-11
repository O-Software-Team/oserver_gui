/* List from Files spec */

/*
    char * email_id;
    char * email_message;
    char * email_from;
    char * email_subject;
    const lv_img_dsc_t * email_status;
*/


/* Create and initialize the Filesystem list */
static email_item email_00_list[] = {
	{
		.email_id = "0001",
		.email_from = "Guillaume Jaulerry",
		.email_subject = "Call: O Team Meeting",
		.email_status = 0,
		.email_message = "People are no longer productized. Personal data is not available to the highest bidder. Humanity says no to invasive advertising. To us, independence means liberation from a transactional existence. And when we venture beyond the cloud, technology starts preserving who we are rather than exploiting us."
	},
	{
		.email_id = "0002",
		.email_from = "Stuart",
		.email_subject = "Bananaaaaaa",
		.email_status = 0,
		.email_message = "Kevin, espeta. Macareno, no ? Nu le pupa spaghetti. Pape pulemoca tule. Patato? Pitopey pote. JAJAJA... Pala pala, andi banana. Oulala, ocanana. Potachupa lapula beee pulaa. Putsi ponla rela picole. Hee, potala tu et potala tu. Bob, lachele bidon. Maquelu la cota, baka bananaaaa. Stopaa bob. Ha otolando papagena, tu le bela con la papayaaaa. Bananaaaaaaa"
	},
	{
		.email_id = "0003",
		.email_from = "Yoyodyne Propulsion Systems Inc.",
		.email_subject = "Oscillation overthruster designs",
		.email_status = 0,
		.email_message = "Miniature colliding beam accelerator which creates intermediate vector bosons from the annihilation of electrons and their antimatter counterparts, positrons that allows an object to pass through solid matter. Banzai tests it by driving his Jet Car through a mountain. While in transit, he finds himself in another dimension"
	},
	{
		.email_id = "0004",
		.email_from = "Dr Emilio Lizardo",
		.email_subject = "RE: Get the oscillation overthruster!",
		.email_status = 1,
		.email_message = "Maybe you can come in her place, huh?  Yoyodyne, Banzai.You know the address.  Come alone.  And bring your overthruster! He'll come.  I know his-a type.  TAKE HER TO THE PIT!  Go, Bigbooty!"
	},
	{
		.email_id = "0005",
		.email_from = "Kevin",
		.email_subject = "RE: Escape from jail",
		.email_status = 1,
		.email_message = "Gru lemola, gru lecola, c'est par là. Cliposut para la nutella. Lacamanger lachich kebab, larisotto, laqua puse locolatina. Econe la matina, Gogogo, banananaaaaaaaa"	
	},
	{
		.email_id = "0006",
		.email_from = "Bob's Big Boy",
		.email_subject = "Burgers? You bet!",
		.email_status = 1,
		.email_message = "We'll get Professor Hikita to cough up the crucial missing circuit, and then we'll finally get our butts off this rock!"
	},
	{
		.email_id = "0007",
		.email_from = "Tug Benson",
		.email_subject = "Here's the target area",
		.email_status = 1,
		.email_message = "Damn it, man, that's the genius of my plan. Why go over there to fight? We can do it right here at home, and get in some good fishing while we're at it. Then we'll fly them over here. Their families too. We'll teach them to skate... Do I have to think of everything?"
	},
	{
		.email_id = "0008",
		.email_from = "John Ya Ya",
		.email_subject = "Where is Professor Hikita?",
		.email_status = 1,
		.email_message = "Multistage axial compressors... latched. Fuel pressure eighteen hundred pounds. Inertial control positive.  T minus five four five.  Resume counting, Five, four, three, two, one. Speed steady at C one seven nautical. Four hundred and accelerating! Almost ready, Dr. Lizardo. Almost"
	},
	{
		.email_id = "0009",
		.email_from = "Dark Helmet",
		.email_subject = "Lone starr son",
		.email_status = 1,
		.email_message = "I Am Your Father's Brother's Nephew's Cousin's Former Roommate"
	},
	{
		.email_id = "0010",
		.email_from = "Loc Rhod",
		.email_subject = "Fhloston Paradise",
		.email_status = 1,
		.email_message = "We have just walked into what is probably the most beautiful concert hall in the universe. Totally awesome! Magnificent paintings on the ceiling. I don't know who painted them, but he must have busted his balls! I see a row of former ministers, more sinister than minister! A few generals	practicing how to sleep. And there's Baby Ray, star of stage and screen, drowning in a sea of nymphets.	He's not gonna get much out of this concert, he's stone-deaf!"
	},
	{
		.email_id = "0011",
		.email_from = "Jean-Baptiste Emanuel Zorg",
		.email_subject = "Federal Army",
		.email_status = 1,
		.email_message = "Voila... the ZF1. It's light... the handle's easy carrying... good for righties and lefties. Breaks down into four parts, undetectable by X-rays. It's the ideal weapon for quick, discreet interventions. A word on fire power: Titaniumrecharger. 3000 round clip with bursts of 3 to 300. With the replay button, another Zorg innovation, it's even easier... one shot. And replay sends every following shot to the same location. And for the grand finale, the all-new ice-cube system!"
	},
	{
		.email_id = "0012",
		.email_from = "Capitain Over",
		.email_subject = "Welcome aboard",
		.email_status = 1,
		.email_message = "Your navigator, Mr. Unger, and your first officer Mr. Dunn. Unger, didn't you serve Oveur in the Air Force? Not directly. Technically, Dunn was under Oveur and I was under Dunn. So, Dunn you were under Oveur and over Unger. That's right. Dunn was over Unger, and I was over Dunn. So you see, both Dunn and I were under Oveur, even though I was under Dunn."
	},		
    {
		.email_id = "0013",
		.email_from = "Moses",
		.email_subject = "I went to the mountain and God spoke to me",
		.email_status = 1,
		.email_message = " Lord, I shall give these laws unto thy people. Do you hear me?! Do you hear me?! All pay head! The Lord! The lord Jehovah has given unto you these fifteen... Oy. Ten! Ten commandments for all to obey!"
	},
	{
		.email_id = "0014",
		.email_from = "Ron Burgundy",
		.email_subject = "It's smells like pure gasoline",
		.email_status = 1,
		.email_message = "It's called the octagon, but I also nickname my testes. My left one is James Westfall, and my right one is doctor Kenneth Noisewater. Well, I'll give this little cookie an hour before we're doing the no pants dance. It's called Sex Panther by Odeon. It's illegal in 9 countries."
	},
	{
		.email_id = "0015",
		.email_from = "Basil Tower",
		.email_subject = "Answer to Sybil",
		.email_status = 1,
		.email_message = "Yes I was doing it! I just put it down to come here to be reminded to do what I’m already bloody doing I mean what’s the point, why are you calling me to see if I’m doing it, what’s the bloody point, I’m bloody doing it aren’t I !!"
	},
	{
		.email_id = "0016",
		.email_from = "Robin Hood",
		.email_subject = "Did I loose?",
		.email_status = 1,
		.email_message = " I lost. I lost? Wait a second, I'm not supposed to lose. Let me see the script."
	},
	{
		.email_id = "0017",
		.email_from = "Prince John",
		.email_subject = "What are the news?",
		.email_status = 1,
		.email_message = "Maybe if you tell me the bad news in a good way, it wouldn't sound so bad"
	},
	{
		.email_id = "0018",
		.email_from = "Waco Kid",
		.email_subject = "To Sheriff Bart",
		.email_status = 1,
		.email_message = "My Name Is Jim. But Most People Call Me… Jim"
	},
	{
		.email_id = "0019",
		.email_from = "Jim",
		.email_subject = "To Bart, attempts to be cordial with the citizens of Rock Ridge",
		.email_status = 1,
		.email_message = "What did you expect? Welcome Sonny? Make yourself at home? Marry my daughter? You've got to remember that these are just simple farmers. These are people of the land. The common clay of the new West. You know... morons!"
	},
	{
		.email_id = "0020",
		.email_from = "Frank Drebin",
		.email_subject = "To Jane",
		.email_status = 1,
		.email_message = "It's the same old story. Boy finds girl, boy loses girl, girl finds boy, boy forgets girl, boy remembers girl, girls dies in a tragic blimp accident over the Orange Bowl on New Year's Day."
	},
	{
		.email_id = "0021",
		.email_from = "Ed Hocken Capt.",
		.email_subject = "He Was Innocent",
		.email_status = 1,
		.email_message = "It's disgusting the way they splash this stuff all over the newspapers! What is journalism coming to? You're laying on top of the queen with her legs wrapped around you. And they call that news. They can't kick you off the force, Frank! It's just not fair!"
	},
	{
		.email_id = "0022",
		.email_from = "Dr. Rumack",
		.email_subject = "A hospital? What is it?",
		.email_status = 1,
		.email_message = "You'd better tell the Captain we've got to land as soon as we can. This woman has to be gotten to a hospital. It's a big building with patients, but that's not important right now."
	},
	{
		.email_id = "0023",
		.email_from = "Steve McCroskey",
		.email_subject = "The Wrong Week",
		.email_status = 1,
		.email_message = "Looks like I picked the wrong week to quit sniffing glue, amphetamines, smoking and drinking"
	},
	{
		.email_id = "0024",
		.email_from = "Otis B. Driftwood",
		.email_subject = "The Contract",
		.email_status = 1,
		.email_message = " I can read but I can't see it. Don't seem to have it in focus here. If my arms were a little longer I could read it...You haven't got a baboon in your pocket have you? Ah. Now I've got it. Now pay particular attention to this first section because it's most important. It says, The party of the first part shall be known in this contract as the party of the first part."
	},
	{
		.email_id = "0025",
		.email_from = "Otis B. Driftwood",
		.email_subject = "Well, you see those first three beds",
		.email_status = 1,
		.email_message = "Last night, I counted five thousand sheep in those three beds, so I had to have another bed to sleep in. You wouldn't want me to sleep with the sheep, would you?"
	},
	{
		.email_id = "0026",
		.email_from = "Rufus T. Firefly",
		.email_subject = "About Chicolini",
		.email_status = 1,
		.email_message = "Gentlemen, Chicolini here may talk like an idiot, and look like an idiot, but don't let that fool you: he really is an idiot. I implore you, send him back to his father and brothers, who are waiting for him with open arms in the penitentiary. I suggest that we give him ten years in Leavenworth, or eleven years in Twelveworth."
	},
	{
		.email_id = "0027",
		.email_from = "Admiral Benson",
		.email_subject = "The briefing room",
		.email_status = 1,
		.email_message = "Be seated! Ah... Many of you are wondering what's wrong with my pants, well they started running short on materials right before they got to the knees so don't give me any shit. Ah. I look out there on all you wonderful guys and I say to myself, What I wouldn't give to be 20 years younger... and a woman. You know, I've personally flown over 194 missions and I was shot down on every one. Come to think of it, I've never landed a plane in my life"
	},
	{
		.email_id = "0028",
		.email_from = "Ferris Bueller's",
		.email_subject = "Day off",
		.email_status = 1,
		.email_message = "Pardon My French, But Cameron Is So Tight That If You Stuck A Lump Of Coal Up His Ass, In Two Weeks, You'd Have A Diamond"
	},
	{
		.email_id = "0029",
		.email_from = "Sterling Archer",
		.email_subject = "Yep Yep Yep",
		.email_status = 1,
		.email_message = "For I am a sinner in the hands of an angry god; Bloody Mary full of vodka, blessed are you among cocktails; pray for me now, that the hour of my death, which I hope is soon. Amen."
	},
	{
		.email_id = "0030",
		.email_from = "Buckaroo Banzai",
		.email_subject = "Red Lectroids",
		.email_status = 1,
		.email_message = "Hey, hey, hey, hey-now. Don't be mean; we don't have to be mean, cuz, remember, no matter where you go, there you are."
	},
	{
		.email_id = "0031",
		.email_from = "Admiral Benson",
		.email_subject = "Crab spy",
		.email_status = 1,
		.email_message = "I slipped on a crab. Don't tell me. There were two crabs. They work in pairs. I went to Annapolis for chrissakes! Who put that crab there?"
	},
	{
		.email_id = "0032",
		.email_from = "Frank Drebin",
		.email_subject = "Atari Punk console",
		.email_status = 1,
		.email_message = "Originally created by Forrest Mims III as the Stepped Tone Generator, it's become one of the most iconic Lo-Fi synth circuits out there. With just a single 556 dual timer chip and few other parts, the Atari Punk Console can crank out some seriously wild square wave sounds. This circuit has stood the test of time as a go-to for raw, stripped-down noise making. "
	},
	{
		.email_id = "0033",
		.email_from = "Ricky Bobby",
		.email_subject = "Proposal Speed",
		.email_status = 1,
		.email_message = "Ricky is a leading manufacturer of ruggedized plastic electronic enclosures for demanding environments. They focus on waterproof and durable designs for enclosures suited to indoor and outdoor applications. Ideal for portable or desktop-mounted electronics including sensors, transmitters, test instruments, and more."
	},
	{
		.email_id = "0034",
		.email_from = "Elaine Dickinson",
		.email_subject = "E.T. is coming to town",
		.email_status = 1,
		.email_message = "We will present concrete examples that show his process for auditing products, evaluating potential savings, and integrating 3D printing into existing systems. Take the chance to learn from Labconco’s success, and bring your questions! There will be a live Q+A at the end with Brent to follow up on specifics. Register now for the live webinar on June 18th at 11am EST/5pm CET."
	},
	{
		.email_id = "0035",
		.email_from = "Count de Monet",
		.email_subject = "Don't get saucy",
		.email_status = 1,
		.email_message = "BEARNAISE, the Company, has developed a disruptive virtual reality and business intelligence (VR as a Service, or VRaaS) product that addresses serious and huge pain points in a massive market: crisis risk prevention and mitigation in both private and public markets. The Company's platform helps crisis managers anticipate risks while determining optimum mitigation strategies via the use of AI and patent pending multi-sensory simulation technology."
	},
    {
        .email_id = "end",
        .email_message = "TAP HERE\nTo add a new\nFile",
    },
};