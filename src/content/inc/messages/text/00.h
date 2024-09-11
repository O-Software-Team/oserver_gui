/* List from Files spec */

/*
    char * txtmsg_id;
    char * txtmsg_message;
    char * txtmsg_from;
    char * txtmsg_summary;
    int txtmsg_status;
*/

/* Create and initialize the Filesystem list */
static txtmsg_item txtmsg_00_list[] = {
    {
		.txtmsg_id = "0001",
		.txtmsg_from = "+33 764 281599",
		.txtmsg_summary = "Mini boss",
		.txtmsg_status = 0,
		.txtmsg_message = "Luca, bueno, pignouf! Bueno, pignouf! Bueno, pignouf!"
	},
	{
		.txtmsg_id = "0002",
		.txtmsg_from = "John Whorfin Lord",
		.txtmsg_summary = "The overthruster has been on",
		.txtmsg_status = 0,
		.txtmsg_message = "The overthruster has been on the main stage for more than 10 minutes - John Bigboote, you must get it"
	},
	{
		.txtmsg_id = "0003",
		.txtmsg_from = "+1 732-555-1212",
		.txtmsg_summary = "Mission Control",
		.txtmsg_status = 1,
		.txtmsg_message = "Buckaroo, The White House wants to know is everything ok with the alien space craft from Planet 10 or should we just go ahead and destroy Russia?"
	},
	{
		.txtmsg_id = "0004",
		.txtmsg_from = "Inigo Montoya",
		.txtmsg_summary = "To the six-fingered man",
		.txtmsg_status = 1,
		.txtmsg_message = "Hello. My name is Inigo Montoya. You killed my father. Prepare to die."
	},
	{
		.txtmsg_id = "0005",
		.txtmsg_from = "Emilio Lizardo Dr",
		.txtmsg_summary = "Buckaroo Banzai",
		.txtmsg_status = 1,
		.txtmsg_message = "Operator! I wanna make a call to Mr. John Bigbooty, at-a Yoyodyne Propulsions-a Systems, over in Grover's Mill. That's W-H-O-R-F-I-N, and you tell him that it's John Whorfin calling.you got that, honey? John! J-O-H-N!"
	},
	{
		.txtmsg_id = "0006",
		.txtmsg_from = "+1 336-235-6952",
		.txtmsg_summary = "He didn't fall? Inconceivable!",
		.txtmsg_status = 1,
		.txtmsg_message = "You keep using that word. I do not think it means what you think it means."
	},
	{
		.txtmsg_id = "0007",
		.txtmsg_from = "John Bigboote",
		.txtmsg_summary = "John Whorfin I have the over",
		.txtmsg_status = 1,
		.txtmsg_message = "I have the overthruster! You must meet me in the lab immediately! If there's one thing I hate, it's to be istaken for-a somebody else"
	},
	{
		.txtmsg_id = "0008",
		.txtmsg_from = "Blackadder",
		.txtmsg_summary = "Captain Cook",
        .txtmsg_status = 1,
		.txtmsg_message = "Your brain is so minute Baldrick, that if a hungry cannibal cracked your head open, there wouldn't be enough to cover a small water biscuit."
	},
	{
		.txtmsg_id = "0009",
		.txtmsg_from = "Prince Ludwig",
		.txtmsg_summary = "Goodbyeeeeee",
		.txtmsg_status = 1,
		.txtmsg_message = "We have met many times, although you knew me by another name. Do you recall a mysterious black marketeer and smuggler called Otto with whom you used to dine and plot and play the biscuit game at the old pizzel in Dover?"
	},
	{
		.txtmsg_id = "0010",
		.txtmsg_from = "+1 216-2Banana",
		.txtmsg_summary = "Big boss",
		.txtmsg_status = 1,
		.txtmsg_message = "Hey hey, takalani katalono big boss, caramba"
	},
	{
		.txtmsg_id = "0011",
		.txtmsg_from = "Prince George",
		.txtmsg_summary = "Nob and Nobility",
		.txtmsg_status = 1,
		.txtmsg_message = "Someone said I had the wit and intellect of a donkey."
	},
	{
		.txtmsg_id = "0012",
		.txtmsg_from = "Blackadder",
		.txtmsg_summary = "Cunning plan",
		.txtmsg_status = 1,
		.txtmsg_message = "Oh, an absurd suggestion sir. Unless it was a particularly stupid donkey."
	},
	{
		.txtmsg_id = "0013",
		.txtmsg_from = "Lady Whiteadder",
		.txtmsg_summary = "Potato",
		.txtmsg_status = 1,
		.txtmsg_message = "Wicked Child! Chairs are the work of Belezabub! At our house Nathaneal sits on a spike. And I sit on Nathaneal. Two spikes would be an extravagance..."
	},
	{
		.txtmsg_id = "0014",
		.txtmsg_from = "Holy Grail",
		.txtmsg_summary = "The Employment Turnover of the Credits",
		.txtmsg_status = 1,
		.txtmsg_message = "We apologize again for the fault in the subtitles. Those responsible for sacking the people who have just been sacked have been sacked."
	},
	{
		.txtmsg_id = "0015",
		.txtmsg_from = "Graham Chapman",
		.txtmsg_summary = "Soldier",
		.txtmsg_status = 1,
		.txtmsg_message = "I don't want to talk to you no more, you empty headed animal food trough wiper. I fart in your general direction. Your mother was a hamster and your father smelt of elderberries."
	},
	{
		.txtmsg_id = "0016",
		.txtmsg_from = "Black Knight",
		.txtmsg_summary = "Just a flesh wound.",
		.txtmsg_status = 1,
		.txtmsg_message = "Tis but a scratch! - A scratch? Your arm's off - No it isn't - Then what's that - Oh come on, pansy!"
	},
	{
		.txtmsg_id = "0017",
		.txtmsg_from = "The Knights",
		.txtmsg_summary = "The Need For a Shrubbery",
		.txtmsg_status = 1,
		.txtmsg_message = "Ni! Ni! Ni!"
	},
	{
		.txtmsg_id = "0018",
		.txtmsg_from = "King Arthur",
		.txtmsg_summary = "To the Peasant",
		.txtmsg_status = 1,
		.txtmsg_message = "Come see the violence inherent in the system! Help! Help! I'm being repressed!"
	},
	{
		.txtmsg_id = "0019",
		.txtmsg_from = "French Knight",
		.txtmsg_summary = "Pretty Much Anything",
		.txtmsg_status = 1,
		.txtmsg_message = "I don't want to talk to you no more, you empty-headed animal food trough wiper. I fart in your general direction. Your mother was a hamster and your father smelt of elderberries."
	},
	{
		.txtmsg_id = "0020",
		.txtmsg_from = "Brian Life",
		.txtmsg_summary = "Always Look On The Bright Side of Life",
		.txtmsg_status = 1,
		.txtmsg_message = "Cheer up, Brian. You know what they say: some things in life are bad. They can really make you mad. Other things just make you swear and curse. When you're chewing on life's gristle, don't grumble; give a whistle, and this'll help things turn out for the best. And... always look on the bright side of life..."
	},
    {
		.txtmsg_id = "0021",
		.txtmsg_from = "Basil Tower",
		.txtmsg_summary = "Is there anywhere they do French food?",
		.txtmsg_status = 1,
		.txtmsg_message = "Yes, France, I believe. They seem to like it there. And the swim would certainly sharpen your appetite. You'd better hurry, the tide leaves in six minutes."
	},
    {
		.txtmsg_id = "0022",
		.txtmsg_from = "+44 020 5034 7239",
		.txtmsg_summary = "Castle Guard",
		.txtmsg_status = 1,
		.txtmsg_message = "Are You Suggesting That Coconuts Migrate?"
	},
	{
		.txtmsg_id = "0023",
		.txtmsg_from = "Dark Helmet",
		.txtmsg_summary = "Combination please?",
		.txtmsg_status = 1,
		.txtmsg_message = "So The Combination Is 1, 2, 3, 4, 5? That's The Stupidest Combination I Ever Heard In My Life!"
	},
	{
		.txtmsg_id = "0024",
		.txtmsg_from = "+1 235 457 0809",
		.txtmsg_summary = "Null Contract",
		.txtmsg_status = 1,
		.txtmsg_message = "Oh that. Oh that's the usual clause...that's in every contract. That just says If any of the parties participating in this contract are shown not to be in their right mind, the entire agreement is automatically nullified."
	},
	{
		.txtmsg_id = "0025",
		.txtmsg_from = "Fiorello Gepeto",
		.txtmsg_summary = "I forgot to tell you. I can't write",
		.txtmsg_status = 1,
		.txtmsg_message = "It's alright, that's in every contract! That's what they call a sanity clause!"
	},
	{
		.txtmsg_id = "0026",
		.txtmsg_from = "Groucho Marx",
		.txtmsg_summary = "My principles",
		.txtmsg_status = 1,
		.txtmsg_message = "Those are my principles, and if you don't like them... well, I have others"
	},
	{
		.txtmsg_id = "0027",
		.txtmsg_from = "+1 137 235 6457",
		.txtmsg_summary = "A Night at the opera",
		.txtmsg_status = 1,
		.txtmsg_message = "I never forget a face, but in your case I'll be glad to make an exception."
	},
	{
		.txtmsg_id = "0028",
		.txtmsg_from = "Wolf J. Flywheel",
		.txtmsg_summary = "Mistaken the Hastings brothers for the killers and handcuffed them",
		.txtmsg_status = 1,
		.txtmsg_message = "Gentlemen, I'm terribly sorry, but it's really not my fault. You certainly do look like crooks"
	},
	{
		.txtmsg_id = "0029",
		.txtmsg_from = "Sterling Archer",
		.txtmsg_summary = "Good drinks",
		.txtmsg_status = 1,
		.txtmsg_message = "I'm Scared If I Stop Drinking All At Once, The Cumulative Hangover Will Literally Kill Me."
	},
	{
		.txtmsg_id = "0030",
		.txtmsg_from = "Count de Monet",
		.txtmsg_summary = "Delicioud raisins",
		.txtmsg_status = 1,
		.txtmsg_message = "Don't get saucy with me, Bearnaise!"
	},
	{
		.txtmsg_id = "0031",
		.txtmsg_from = "Austin Powers",
		.txtmsg_summary = "Laser Sharks",
		.txtmsg_status = 1,
		.txtmsg_message = "You mean I actually have frickin' sharks with frickin' laser beams attached to their frickin' heads?"
	},
	{
		.txtmsg_id = "0032",
		.txtmsg_from = "Blackadder",
		.txtmsg_summary = "Pegasus mission",
		.txtmsg_status = 1,
		.txtmsg_message = "The word mistake, Sir, is not one that appears in my dictionary"
	},
	{
		.txtmsg_id = "0033",
		.txtmsg_from = "Yonda Udonta",
		.txtmsg_summary = "Wild Horses",
		.txtmsg_status = 1,
		.txtmsg_message = "Whatever Happens, Happens"
	},
	{
		.txtmsg_id = "0034",
		.txtmsg_from = "Spike Spiegel",
		.txtmsg_summary = "The Real Folk Blues",
		.txtmsg_status = 1,
		.txtmsg_message = "You're Gonna Carry That Weight"
	},
	{
		.txtmsg_id = "0035",
		.txtmsg_from = "President Skroob",
		.txtmsg_summary = "What face?",
		.txtmsg_status = 1,
		.txtmsg_message = "Never have that damn thing down in front of me. How I do I know you're not making faces at me under that thing?"
	},
    {
        .txtmsg_id = "end",
        .txtmsg_message = "TAP HERE\nTo add a new\nFile",
    },
};