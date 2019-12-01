**11/16/2019**
Got the repository open using openframework project generator 
and made a commit to check that it updates the correct repository.

**11/17/2019**
Created a player class. Implemented a movement function and made
player change color when moving. Can't decide whether to keep
feature or not.

**11/18/2019**
Added Vivaldi for background music. Worked on implementing
external library. It won't work. :( Apparently, ofBaseSoundPlayer
doesn't exist. That's fine. This is fine. Download for next
attempt will take an hour. It's 4am. Will try tomorrow.

**11/19/2019**
No commits today. Only one type of commit I'm thinking about.
External libraries are a sham. ofxlibraries are old and 
outdated. Had the perfect library, but creator didn't test
in x64, only win32. Added looping to soundtrack, so I got
that going for me.

**11/20/2019**
:) Using ofxSmartFont. Isn't necessary, but should streamline
the process if I want to use different fonts. Working on creating
different levels. ofxButtons are useless, will make my own, hopefully
tonight or tomorrow.

**11/21/2019**
Got a button class up and running. Might use a function pointer so 
I can interate through them using a for loop, but not sure. 
Used Button class to create a Play Button. 

**11/22/2019**
HEAP CORRUPTION! This is fine. Commented everything out except 
ofSoundPlayer player declaration and player.load(). Still heap corruption.
Sometimes there isn't though. If I access my_font, but never use the accessed
thing, it's all ok.

**11/23/2019**
Spent the day getting rid of the magic numbers. No idea what to call some
of them though. I mean, they legit are magic numbers. Trial and Error to get
my UI looking nice (well, sort of, it's a piece of shit, but it's a nice piece
of shit).

**11/24/2019**
No work. Visited family.

**11/25/2019**
No work. Hung out with nuclear family

**11/26/2019**
No work. Enjoyed a break, watched Superstore Seasons 2-4.

**11/27/2019**
HEAP CORRUPTION! Let's Go!!! Commented everything out except
ofSoundPlayer declaration, #include ofMain.h and ofSoundPlayer.load().
Still there. 

**11/28/2019**
Started getting read access violation with ofSoundPlayer.load(). Decided to make 
the sound player into a pointer to an ofSoundPlayer. Works, but program is angry I'm
not deleting it. Will try to figure out when to delete music tomorrow. Changed the Player
class to Character class because I realized I wanted the player and enemies to share
many similar characteristics. Created a list of enemies. This gave me trouble. Realized
I have to initialize the list in the source file. Strongly considered making a 
pointer to a list, just so you know where my heads at in terms of memory management.
The enemies disappear when player.rect intersects. Had to override == and !=.

**11/29/2019**
Created a game over screen that is reached once player fights so many battles.
Created separateplayer and enemy classes that extended Character. Player has to override
getGold() since player.gold is public because I have to change it after battles. Need to
figure out way to make it private, but mutable inside fights. Could make fight function
a friend, but fight() needs to access private things in ofApp and ofApp isn't a valid class(?)
Work-around right now is making ofApp (the class?!?) a friend, but I'm not a fan.
Hopefully can find something better soon. Added stock rpg stats in like atk, def, crit_chance, health.
Also created player sprite. First off, it's an abomination. Secondly, had to add a ton of magic numbers
in so that it fits the whole player.rect. Need to add explanatory comments. Also added total exp and
increased exp during "battles"

**11/30/2019**
Made it so an enemy can't both have high gold and high exp. Made enemies a special color
if they had a gave a large amound of exp or gold. Logic got a little ugly for the exp, since
background being white could mess with that, with nested loops. Will fix if given the time.
Removed all the file names and important strings and pulled them into constants. 
Added functionality to setupEnemies() so that, enemies couldn't be intersecting each other. 
Spent an hour or two dealing with annoying bug where enemies was cleared, but
I had a for loop trying to access its previous elements.
Finally added unit tests. Have no idea what type of file tests.runsettings should be, so
I made my own setup. Also tried downloading other packages, but gave up. While, I'm
sure my way is definitely not the cleanest, I'm quite happy with it, and it gets the job done.
Will (maybe) change if I have the time. The testing is not my largest priority. Still
have to implement, basically, the core mechanics of the game. Have to actually do my job
tomorrow, so hopefully can really work on this on Monday.
