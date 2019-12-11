#pragma once

#include <stdlib.h>
#include "Armor.h"
#include "Button.h"
#include "Enemy.h"
#include "Player.h"
#include "Resource.h"
#include "Weapon.h"
#include "ofMain.h"
#include "ofxSmartFont.h"

class ofApp : public ofBaseApp {
   private:
    friend class Item;
    friend void Player::moveInDirection(int direction_index);
    // Anything with "Mult" is for game balancing
    // Anything with "Factor" is multiplied against something
    // Anything with "Adj" is added with something
    //"Factor" and "Adj" numbers determined experimentally
    // May have to change them based on monitor size

    const static float kCenterXFactor;
    const static float kCenterYFactor;
    const static float kPlayWidthAdj;
    const static float kPlayHeightAdj;
    const static float kInitBattleMult;
    const static float kBattleMultFactor;
    const static float kInitCritMult;
    const static float kBossMult;
    const static float kGoldMultFactor;
    const static float kExpMultFactor;
    const static float kCritChanceMultFactor;
    const static float kCritDmgMultFactor;
    const static float kSettingsWidthAdj;
    const static float kToggleMsgYFactor;
    const static float kStatSpaceYFactor;
    const static float kCritMsgYAdjFactor;
    const static float kPriceYFactor;
    const static float kStoreGoldXFactor;
    const static float kEquippedYFactor;
    const static float kResaleFactor;
    // Checked by measuring ofGetWindowWidth and
    // ofGetWindowHeight at max window size
    const static int kMaxScreenWidth = 1366;
    const static int kMaxScreenHeight = 726;
    const static int kNumOfTracks = 4;
    const static int kNumOfStats = 3;
    const static int kMaxPageNum = 3;
    const static int kMaxItemsOnPage = 32;
    const static int kItemButtonsOnScreen = 2;
    const static int kStorePosXStart = 100;
    const static int kStorePosYStart = 100;
    const static int kStorePosXInc = 150;
    const static int kStorePosYInc = 150;
    const static int kStorePosXEndAdj = 150;
    const static int kStorePosYEndAdj = 150;
    const static int kInitialEnergy = 15;
    const static int kEnergyBattle = 2;
    const static int kEnergyBattleLost = 3;
    const static int kEnergyBossBattleWon = 10;
    const static float kBossPosFactor;
    const static int kStartBattle = 69;
    const static int kFightInit = -20;
    const static int kAtkDelay = 1000;
    const static int kMessageDelay = 700;
    const static int kPlayerFightX = 50;
    const static int kPlayerFightY = 50;
    const static int kPlayerFightWidth = Character::kCharWidth + 100;
    const static int kPlayerFightHeight = Character::kCharHeight + 100;
    const static int kEnemyFightY = 100;
    const static int kEnemyFightWidth = 100;
    const static int kEnemyFightHeight = 100;
    const static int kEnemyAdjX = 300;
    const static int kStageNumChangeRight = 7;
    const static int kStageNumChangeUp = 11;
    const static int kStartX = 0;
    const static int kStartY = 0;
    const static int kStartGold = 50;
    const static int kEnemyMaxGold = 20;
    const static int kEnemyMinGold = 10;
    const static int kEnemyMaxExp = 20;
    const static int kEnemyMinExp = 10;
    const static int kEnemyMaxAtk = 60;
    const static int kEnemyMinAtk = 40;
    const static int kEnemyMaxDef = 50;
    const static int kEnemyMinDef = 30;
    const static int kEnemyMaxHp = 200;
    const static int kEnemyMinHp = 130;
    const static int kResourceMaxExp = 50;
    const static int kResourceMaxGold = 50;
    const static int kGoldShinyLim = 40;
    const static int kExpShinyLim = 40;
    const static int kStartExp = 0;
    const static int kStartAtk = 90;
    const static int kStartDef = 50;
    const static int kStartHealth = 400;
    const static int kStartCrit = 10;
    const static int kSwordPageNum = 0;
    const static int kSwordPosIndex = 0;
    const static int kSwordPrice = 300;
    const static int kSwordAtkBoost = 4000;
    const static int kHelmetPageNum = 0;
    const static int kHelmetPosIndex = 1;
    const static int kHelmetPrice = 300;
    const static int kHelmetDefBoost = 2000;
    const static int kHelmetHpBoost = 3000;
    const static int kFastBattleGemPageNum = 0;
    const static int kFastBattleGemPosIndex = 2;
    const static int kFastBattleGemPrice = 300;
    const static int kSlowBattleGemPageNum = 0;
    const static int kSlowBattleGemPosIndex = 3;
    const static int kSlowBattleGemPrice = 300;
    const static int kMoreExpGemPageNum = 0;
    const static int kMoreExpGemPosIndex = 4;
    const static int kMoreExpGemPrice = 300;
    const static int kMoreGoldGemPageNum = 0;
    const static int kMoreGoldGemPosIndex = 5;
    const static int kMoreGoldGemPrice = 300;
    const static int kMoreCritChanceGemPageNum = 0;
    const static int kMoreCritChanceGemPosIndex = 6;
    const static int kMoreCritChanceGemPrice = 300;
    const static int kMoreCritDmgGemPageNum = 0;
    const static int kMoreCritDmgGemPosIndex = 7;
    const static int kMoreCritDmgGemPrice = 300;
    const static int kInfoFontSize = 16;
    const static int kStoreFontSize = 14;
    // get weird malloc error if larger
    const static int kMaxResourceNum = 67;
    const static int kLvlUpGain = 100;
    const static int kExpLimit = 100;
    const static int kSettingsXAdj = 40;
    const static int kSettingsYAdj = -40;
    const static int kToggleXAdj = -40;
    const static int kToggleSpaceAdj = 50;
    const static int kToggleWidth = 40;
    const static int kToggleHeight = 40;
    const static int kToggleMsgXAdj = 10;
    const static int kToggleMsgYAdj = 5;
    const static int kStatSpaceYAdj = 25;
    const static int kRestartXAdj = 25;
    const static int kRestartYAdj = 50;
    const static int kRestartWidthAdj = 60;
    const static int kStoreXAdj = 25;
    const static int kStoreYAdj = 100;
    const static int kStoreWidthAdj = 60;
    const static int kInventoryWidthAdj = 100;
    const static int kLvlUpWidthAdj = 70;
    const static int kBackWidthAdj = -40;
    const static int kBackHeightAdj = 15;
    const static int kNextXAdj = -40;
    const static int kNextYAdj = 15;
    const static int kNextWidthAdj = -40;
    const static int kNextHeightAdj = 15;
    const static int kPrevYAdj = 15;
    const static int kPrevWidthAdj = -40;
    const static int kPrevHeightAdj = 15;
    const static int kResourcePosAdj = 3;
    const static int kLvlUpYAdj = -65;
    const static int kStatUpXAdj = 180;
    const static int kStatDownXAdj = -30;
    const static int kStatButtonWidth = 20;
    const static int kStatButtonHeight = 20;
    const static int kCritMsgXAdj = 10;
    const static int kEnemyAtkXAdj = 20;
    const static int kEnemyAtkYAdj = 30;
    const static int kPlayerHpMsgXAdj = 40;
    const static int kPlayerHpMsgYAdj = 40;
    const static int kEnemyHpMsgXAdj = 10;
    const static int kEnemyHpMsgYAdj = -20;
    const static int kGoldMsgYAdjFactor = 2;
    const static int kEnemyCritFactor = 2;
    const static int kExpMsgYFactor = 2;
    const static int kLvlMsgYFactor = 3;
    const static int kLvlUpYFactor = -2;
    const static int kEnergyMsgXFactor = 11;
    const static int kPlayerSpritePosAdj = -15;
    const static int kPlayerSpriteWidth = Character::kCharWidth + 20;
    const static int kPlayerSpriteHeight = Character::kCharHeight + 20;
    const static int kItemNameYFactor = 2;
    const static int kEquippedXAdj = -30;
    const static int kPriceXAdj = -30;
    const static int kLvlPointsMsgX = 200;
    const static int kToggleAutoLvlX = 150;
    const static int kNameXAdj = -15;
    const static int kInitBossChance = 15;
    const static string kPlayLabel;
    const static string kRestartLabel;
    const static string kStoreLabel;
    const static string kInventoryLabel;
    const static string kSettingsLabel;
    const static string kBackLabel;
    const static string kNextLabel;
    const static string kPrevLabel;
    const static string kLvlUpLabel;
    const static string kHelmetName;
    const static string kSwordName;
    const static string kFastBattleGemName;
    const static string kSlowBattleGemName;
    const static string kMoreExpGemName;
    const static string kMoreGoldGemName;
    const static string kMoreCritChanceGemName;
    const static string kMoreCritDmgGemName;
    const static string kToggleLabel;
    const static string kGameOverMessage;
    const static string kCritMessage;
    const static string kWorldTitle;
    const static string kBkgrdMusicFilePathOne;
    const static string kBkgrdMusicFilePathTwo;
    const static string kBkgrdMusicFilePathThree;
    const static string kBkgrdMusicFilePathFour;
    const static string kAtkSoundFilePath;
    const static string kBattleMusicFilePath;
    const static string kFontFilePath;
    const static string kPlayerSpritePath;
    const static string kSmallFontName;
    const static string kStoreFontName;
    const static string kFontName;
    const static string kUnequippedMsg;
    const static string kEquippedMsg;
    const static string kEquipSuccessMsg;
    const static string kAlreadyEquippedMsg;
    const static string kNoOwnMsg;
    const static string kSaleMadeMsg;
    const static string kPurchaseMadeMsg;
    const static string kNotEnoughGoldMsg;
    const static string kAlreadyOwnedMsg;
    const static string kHpLabel;
    const static string kAtkLabel;
    const static string kDefLabel;
    const static string kGoldLabel;
    const static string kPriceLabel;
    const static string kExpLabel;
    const static string kEnergyLabel;
    const static string kStageLabel;
    const static string kLvlLabel;
    const static string kGetRewardMsg;
    const static string kGetExpMsg;
    const static string kGetGoldMsg;
    const static string kBattleChanceLabel;
    const static string kLvlPointsLabel;
    const static string kPercentString;
    const static string kExclamationPoint;
    const static string kBkgrdMusicEnabledMsg;
    const static string kBattleMusicEnabledMsg;
    const static string kAtkSoundEnabledMsg;
    const static string kAutoLvlEnabledMsg;

    bool setup_is_completed_;
    bool should_delay_;
    static int page_num_;
    static int battle_chance_;
    static int boss_chance_;
    bool fight_is_init_;
    static int battle_start_;
    bool player_is_fighting_;
    bool is_player_atk_turn_;
    bool battle_ended_;
    bool player_won_;
    int turns_fought_;
    int atk_damage_;
    bool is_crit_hit_;
    static float crit_dmg_mult_;
    static float battle_multiplier_;
    int enemy_fight_x_;
    static int energy_left_;
    int max_health_;
    static float gold_mult_;
    static float exp_mult_;
    static bool store_is_open_;
    static bool settings_is_open_;
    bool purchase_made_;
    bool sale_made_;
    bool tried_equip_not_own_;
    bool equip_success_;
    bool already_equipped_;
    static bool item_already_owned_;
    static bool not_enough_gold_;
    static bool inventory_is_open_;
    static bool game_over_is_set_up_;
    static int lvls_inc_;
    static bool move_key_is_pressed[4];
    static int stage_num_;
    static bool background_music_enabled_;
    static bool atk_sound_enabled_;
    static bool battle_music_enabled_;
    int track_num_;
    static bool auto_lvling_enabled_;
    static bool lvl_up_is_open_;
    static int lvl_up_points_;
    static int num_hp_lvl_up_;
    static int num_atk_lvl_up_;
    static int num_def_lvl_up_;
    ofSoundPlayer* background_music_player_;
    ofSoundPlayer track_one_player_;
    ofSoundPlayer track_two_player_;
    ofSoundPlayer track_three_player_;
    ofSoundPlayer track_four_player_;
    ofSoundPlayer track_players_[kNumOfTracks];
    ofSoundPlayer* atk_sound_player_;
    ofSoundPlayer* battle_music_player_;
    static shared_ptr<ofxSmartFont> button_font_;
    static shared_ptr<ofxSmartFont> info_font_;
    static shared_ptr<ofxSmartFont> store_font_;
    static Player player_;
    Enemy enemy_;
    static Enemy boss_;
    static list<Resource> resources_;
    static list<Button*> buttons_;
    list<Item*> items_;
    static Button* play_button_;
    static Button* restart_button_;
    static Button* store_button_;
    static Button* inventory_button_;
    static Button* settings_button_;
    static Button* toggle_bkgrd_music_button_;
    static Button* toggle_atk_sound_button_;
    static Button* toggle_battle_music_button_;
    static Button* toggle_auto_lvling_button_;
    static Button* back_button_;
    static Button* next_button_;
    static Button* prev_button_;
    static Button* lvl_up_button_;
    static Button* hp_up_button_;
    static Button* hp_down_button_;
    static Button* atk_up_button_;
    static Button* atk_down_button_;
    static Button* def_up_button_;
    static Button* def_down_button_;

    void setupItems();
    void deleteItems();
    void setupButtons();
    // helper function of setupButtons
    void setupStartScreenButtons();
    // helper function of setupButtons
    void setupSettingsButtons();
    // helper function of setupButtons
    void setupGameOverButtons();
    // helper function of setupButtons
    void setupWorldButtons();
    // helper function of setupButtons
    void setupLvlUpButtons();
    // helper function of windowResized
    void addLvlUpButtons();
    // helper function of setupButtons
    void setupStatUpButtons();
    // helper function of setupButtons
    void setupStatDownButtons();
    // helper function of setupButtons
    void setupStoreButtons();
    void drawButtons();
    void deleteButtons();
    void drawPlayer();
    void drawBoss();
    void drawStartingScreen();
    void setupGameOver();
    void drawGameOver();
    // called when store button pressed
    // adds back and next buttons and items
    static void openStore();
    // checks if player has enough gold
    // if so, item is added to player.inventory
    void buyItem(Item* item);
    // removes item from inventory
    // and refunds player slightly
    void sellItem(Item* item);
    // checks if player owns item
    // then equips item in correct spot
    void equipItem(Item* item);
    bool checkIfItemEquipped(Item* item);
    bool checkIfItemInInventory(Item* item);
    // battleEnemy or battleBoss
    // is called depending on scenario
    void battleOpponent();
    // performs correct unequip function
    void unequipItem(Item* item);
    // removes store buttons and
    // adds game over buttons
    static void closeStore();
    // calls different close functions
    // based on context
    static void closePage();
    void drawStore();
    // draws the store notices like
    // Purchase Successful, or not enough gold
    void drawStoreNotices();
    // draws specific equip notices like
    // item not owned or Equipped
    void drawEquipNotices();
    static void openSettings();
    static void toggleBkgrdMusic();
    static void toggleAtkSound();
    static void toggleBattleMusic();
    // removes settings buttons and
    // adds start screen buttons
    static void closeSettings();
    void drawSettings();
    void drawXOnButton(Button* button);
    void drawPlusOnButton(Button* button);
    void drawMinusOnButton(Button* button);
    void drawStatButtons();
    void drawToggleMessage(Button* button, string message);
    // adds inventory buttons
    // gets rid of world buttons
    static void openInventory();
    // reverse of openInventory
    static void closeInventory();
    void drawInventory();
    // draws specific inventory notices
    // like Sale Successful
    void drawInventoryNotices();
    // increases page num if less than max
    static void increasePage();
    // decreases page num, if greater than 0
    static void decreasePage();
    // adds lvlUpButtons
    // removes world buttons
    static void openLvlUp();
    // next six functions are called by
    // lvlUpButtons to manually change stats
    static void lvlUpHp();
    static void lvlDownHp();
    static void lvlUpAtk();
    static void lvlDownAtk();
    static void lvlUpDef();
    static void lvlDownDef();
    // toggles ability to automatically
    // spend lvl points after lvling up
    static void toggleAutoLvling();
    // opposite of openLvlUp
    static void closeLvlUp();
    void drawLvlUpScreen();
    // adds world buttons and
    // removes start screen buttons
    static void setupWorld();
    void drawWorld();
    void drawLvlUp();
    void drawInfo();
    // puts resources in a smaller square than window
    // not intersecting player
    static void setupResources();
    void drawResources();
    // gives player resources if intersecting
    // at cost of an energy
    void mineResources();
    // sets up boss inside window if on main diagonal
    // or at a kBossChance rate
    static void setupBoss();
    // same as setUpBattle, but boss has lvl multiplier
    void setupBossBattle();
    /// same as battleEnemy, but with setupBoss
    void battleBoss();
    // moves player based on if a WASD key is pressed
    void updatePlayerPos();
    // next static void functions
    // used by gems
    static void slowBattleChance();
    static void speedBattleChance();
    static void increaseExpGain();
    static void decreaseExpGain();
    static void increaseGoldGain();
    static void decreaseGoldGain();
    static void increaseCritChance();
    static void decreaseCritChance();
    static void increaseCritDmg();
    static void decreaseCritDmg();
    // uses setUpBattle, takeBattleTurn, and checkBattleEnded
    void battleEnemy();
    // takes either player or enemy turn
    void takeBattleTurn();
    // checks if player hp <= 0 ot
    // enemy hp <= 0, then performs end battle cleanup, accordingly
    void checkBattleEnded();
    // sets up enemy to have stats based on stage num
    void setupBattle();
    // waits a turn so it draws initial stats
    // and waits at end to draw when hp <= 0
    void drawBattle();
    void drawAtk();
    void drawBattleInfo();
    void drawWinBattleInfo();
    // either increases lvl up points
    // or stats, depending on auto_lvling_enabled
    void lvlUp();
    // sets up the game for next run
    static void restartGame();
    // sets up player for next run
    static void resetPlayer();

   public:
    const static ofColor kWhite;
    const static ofColor kBlack;
    const static ofColor kGrayClear;
    const static ofColor kRed;
    const static ofColor kBlue;
    const static ofColor kGreen;
    const static ofColor kPurple;
    const static ofColor kYellow;
    const static ofColor kSkin;
    const static ofColor kTan;

    void setup();
    void update();
    void draw();
    void exit();

    // clears buttons and the pushes appropriate buttons inside based on current
    // scene
    void windowResized(int w, int h);
    void keyPressed(int key);
    void keyReleased(int key);
    void mousePressed(int x, int y, int button);
};