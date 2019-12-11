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
in so that it fits the whole player.rect. Third, memory problem is gone. Made the sprite an ofImage*.
Don't delete it despite making a new ofImage. I'm not saying that two wrongs make a right, I'm
just saying that the evidence is pointing towards that conclusion.
Need to add explanatory comments. Also added total exp and
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

**12/1/2019**
Changed enemies into resources. Increment the chance of a battle occuring everytime the player moves.
When a rand() is smaller than this chance, a battle starts. Got rid of enemies list, so only have
to keep track of the one enemy I am fighting. Implemented fight function "husks". 
They get called but nothing happens inside them. Will implement fight mechanics tomorrow.

**12/2/2019**
Implemented fight mechanics. Used a sleep function, so each attack could be seen. Split my larger
functions into several helper functions. Need to implement a levelling up system and a store
to do something with the gold. Also need to implement a save function. Will most likely just
save after each run, so not to much data to hold. Also need to implement a reset button in the game over screen.

**12/3/2019**
Implemented Restart button, inventory, and store buttons. Inventory and store share a back button. 
Might have to change that if I end up using function pointers. Implemented battle music and an
attack sound. Need to actually implement store and inventory. Right now, just empty tan screens.

**12/4/2019**
Took the day off, had other hw.

**12/5/2019**
Made an Item class. Also made Weapon and Armor that extends Item. Just husks of classes right now.
Main achievement of the day was refactoring my Button usage. The mousePressed() function was
getting a little crowded so, I put the function I wanted called when the button was pressed
inside the button. Had a bit of an issue with static, top of source file is quite ugly, but it works.
I then made a list of buttons that will contain all the buttons able to be pressed at a given scene.
Then I don't have to keep track of these booleans in mousePressed. If the button is in buttons, it
is able to be pressed/ drawn on the screen. The booleans will now tell me when to push and pop each button.
Will have to remember to keep track of this. My Button == and !=can't compare the function ptrs or the
ofxSmartFont, so the two back buttons have to differ by 1 for something (x, y , width, or height).
Will hopefully implement item buying, selling, and equipping over the weekend.

**12/6/2019**
Created a rough outline of an item class. Gave it member variables and constructor.

**12/7/2019**
Found out openframeworks does have a function that can be called on close, exit. Used this to 
clean up all the pointers I hadn't deleted before. Added two new buttons, prev and next to store 
and inventory. They allow me to go through multiple pages. Expands item capacity, not that I need it
right now. Decided to rely completely on buttons[] to draw my buttons. Also added another item
constructor to not need ofVec2f because I don't know how to instantiate one without declaring and
then using .set(). Added ability to buy items. Will implement sell relatively easily, not sure about equip.

**12/8/2019**
This was annoying. Had to change all my Item stuff into Item* because dynamic casting. This was what
I was using to decide what to do when equipping an item, since it depends on whether it's an item, armor, or
weapon. Added an item constructor that takes in a function, since there isn't a clear cut thing for equipping
an item. Also added to my tests file tests for getters of Item, Armor, and Weapon.

**12/9/2019**
Added an unequip button since it seems like a nice feature. This means I had to make my items take in 
two functions, the second being the reverse of the first. This makes it so item effects can't
just be stacked by equipping and unequipping multiple times. Also had to deal with a bug where
items weren't unequipped when sold. Added a new settings button. This allows the player to 
turn all the sounds of the game on or off, like background music, battle music, or attack sounds.
Included nice visual cue of x on a box :). Spent the last 5 hours removing magic numbers. I regret
all the choices I made previously, but it's done now. I tried to refactor my code and line up
things like the parameters inside my longer constructors, but I think openframeworks disapproves.
It reverts those changes as soon as I leave the page and come back, even when saving. Will have to look
into that tomorrow. Also need to add trailing underscores to basically goddamn everything, so that's a fun project.

**12/10/2019**
Changing variable names wasn't the worst, once I remember about Crtl-F that is. Still, there is nothing like
the fear of seeing the entire document covered in read underlines and knowing that you are actually going
to have to fix each one, instead of just fixing one typo at the start and resolving them all. I added the ability
to manually choose where the level points go. You know, finally actually fulfiling the RPG in rouguelike RPG.
Still need to add a README and better documentation comments. Have met most of my goals. I decided to use a
randomly generated level instead of working on levels. I do not think I will have time to create a soundtrack,
instead the song will just loop when finished.

**12/11/2019**
Added boss battle, who gives you energy back if you beat them. Also enabled window resizing and buttons look
semi-decent. You can tell it was made for the smaller size, but not the worst. Hell of a lot better than before.
Will hopefully add more comments in, but README is first. Still not entirely sure what goes in one. Hope I
figure it out. Update: Added README.md and comments. Was also able to implement background music soundtrack.
Wasn't too bad. Should have done it earlier.
