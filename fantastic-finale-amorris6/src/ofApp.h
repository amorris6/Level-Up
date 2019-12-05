#pragma once

#include <stdlib.h>
#include "Enemy.h"
#include "Player.h"
#include "Resource.h"
#include "Button.h"
#include "ofMain.h"
#include "ofxSmartFont.h"

class ofApp : public ofBaseApp {
   private:
    friend void Player::moveInDirection(int direction_index);
    const static int kInitialEnergy = 15;
    const static int kEnergyBattle = 2;
    const static int kEnergyBattleLost = 3;
    const static int kLoseChance = 40;
    const static int kStartBattle = 69;
    const static int kFightInit = -20;
    const static int kPlayerFightX = 50;
    const static int kPlayerFightY = 50;
    const static int kPlayerFightWidth = Character::kCharWidth + 100;
    const static int kPlayerFightHeight = Character::kCharHeight + 100;
    const static int kEnemyFightY = 100;
    const static int kEnemyFightWidth = 100;
    const static int kEnemyFightHeight = 100;
    const static int kEnemyAdjX = 300;
    const static float kInitBattleMult;
    const static float kInitCritMult;
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
    const static int kInfoFontSize = 16;
    const static int kMaxResourceNum = 67;  // get weird malloc error if larger
    const static int kLvlUpGain = 100;
    const static int kExpLimit = 100;
    const static float kPlayXAdj;
    const static float kPlayYAdj;
    const static float kPlayWidthAdj;
    const static float kPlayHeightAdj;
    const static string kPlayLabel;
    const static string kRestartLabel;
    const static string kStoreLabel;
    const static string kBackLabel;
    const static string kInventoryLabel;
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
    const static string kBkgrndMusicFilePath;
    const static string kAtkSoundFilePath;
    const static string kBattleMusicFilePath;
    const static string kFontFilePath;
    const static string kPlayerSpritePath;
    const static string kSmallFontName;
    const static string kFontName;

    int battle_chance_;
    bool fight_is_init_;
    int battle_start_;
    bool player_is_fighting_;
    bool is_player_atk_turn_;
    int turns_fought_;
    int atk_damage_;
    bool is_crit_hit_;
    float crit_mult_;
    float battle_multiplier_;
    int enemy_fight_x_;
    int energy_left_;
    int max_health_;
    bool store_is_open_;
    bool inventory_is_open_;
    int lvls_inc_; 
    bool move_key_is_pressed[4];
    static int stage_num_;
    bool background_music_enabled_;
    ofSoundPlayer* background_music_player;
    ofSoundPlayer* atk_sound_player;
    ofSoundPlayer* battle_music_player;
    shared_ptr<ofxSmartFont> button_font;
    shared_ptr<ofxSmartFont> info_font;
    Player player;
    Enemy enemy;
    static list<Resource> resources;
    void setupButtons();
    void drawPlayer();
    void drawStartingScreen();
    void drawGameOver();
    void openStore();
    void drawStore();
    void openInventory();
    void drawInventory();
    void drawWorld();
    void drawLvlUp();
    void drawInfo();
    static void setupResources();
    void drawResources();
    void mineResources();
    void updatePlayerPos();
    void battleEnemy();
    void takeBattleTurn();
    void checkBattleEnded();
    void setupBattle();
    void drawBattle();
    void drawAtk();
    void drawBattleInfo();
    void drawWinBattleInfo();
    void lvlUp();
    Button* play_button;
    Button* restart_button;
    Button* store_button;
    Button* inventory_button;
    Button* back_button;

   public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mousePressed(int x, int y, int button);
};