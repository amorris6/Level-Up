#pragma once

#include "Enemy.h"
#include "Player.h"
#include "Resource.h"
#include "ofMain.h"
#include "ofxSmartFont.h"

class ofApp : public ofBaseApp {
   private:
    friend class Player;
    const static int kInitialEnergy = 25;
    const static int kEnergyBattle = 2;
    const static int kEnergyBattleLost = 3;
    const static int kLoseChance = 40;
    const static int kStartBattle = 68;
    const static int kFightInit = -20;
    const static int kStartX = 0;
    const static int kStartY = 0;
    const static int kStartGold = 50;
    const static int kEnemyMaxGold = 100;
    const static int kResourceMaxGold = 100;
    const static int kGoldShinyLim = 85;
    const static int kExpShinyLim = 85;
    const static int kStartExp = 0;
    const static int kEnemyMaxExp = 100;
    const static int kResourceMaxExp = 100;
    const static int kStartAtk = 20;
    const static int kStartDef = 10;
    const static int kStartHealth = 100;
    const static float kStartCrit;
    const static int kButtonFontSize = 28;
    const static int kInfoFontSize = 16;
    const static int kMaxResourceNum = 67;  //get weird malloc error if larger
    const static float kPlayXAdj;
    const static float kPlayYAdj;
    const static float kPlayWidthAdj;
    const static float kPlayHeightAdj;
    const static string kPlayLabel;
    const static float ofApp::kPlayLabelXAdj;
    const static float ofApp::kPlayLabelYAdj;
    const static ofColor kWhite;
    const static ofColor kBlack;
    const static ofColor kRed;
    const static ofColor kBlue;
    const static ofColor kGreen;
    const static ofColor kPurple;
    const static ofColor kYellow;
    const static ofColor kSkin;
    const static string kMusicFilePath;
    const static string kFontFilePath;
    const static string kPlayerSpritePath;
    const static string kSmallFontName;
    const static string kFontName;

	int battle_chance_;
    int battle_start_;
    bool player_fighting_;
    float battle_multiplier_;
    int energy_left_;
    bool move_key_is_pressed[4];
    int num_of_keys_pressed_;
    static int lvl_num_;
    bool background_music_enabled_;
    ofSoundPlayer* background_music_player;
    shared_ptr<ofxSmartFont> button_font;
    shared_ptr<ofxSmartFont> info_font;
    Player player;
    static list<Resource> resources;
    void drawPlayer();
    void drawStartingScreen();
    void drawGameOver();
    void drawWorld();
    void drawInfo();
    static void setupResources();
    void drawResources();
    void mineResources();
    void updatePlayerPos();
    void fightEnemy();
    void drawFight();
    class Button {
       private:
        float x;
        float y;
        float width;
        float height;
        std::string label;
        ofxSmartFont label_font;

       public:
        Button(float x, float y, float width, float height, std::string label,
               ofxSmartFont label_font)
            : x(x),
              y(y),
              width(width),
              height(height),
              label(label),
              label_font(label_font) {}
        bool mouseIsInside(int mouse_x, int mouse_y);
        void draw();
    };
    Button* play_button;

   public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
};