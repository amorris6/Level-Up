#pragma once

#include "Character.h"
#include "ofMain.h"
#include "ofxSmartFont.h"

class ofApp : public ofBaseApp {
   private:
    const static int kInitialBattles = 5;
    const static int kButtonFontSize = 28;
    const static int kInfoFontSize = 16;
    constexpr static int kMaxEnemyNum = 5;
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
    const static string kMusicFilePath;
    const static string kFontFilePath;

	int battles_left_;
    bool move_key_is_pressed[4];
    int num_of_keys_pressed_;
    int lvl_num_;
    static list<int> test_list;
    bool background_music_enabled_;
    ofSoundPlayer* background_music_player;
    shared_ptr<ofxSmartFont> button_font;
    shared_ptr<ofxSmartFont> info_font;
    Character player;
    static list<Character> enemies;
    void drawPlayer();
    void drawStartingScreen();
    void drawGameOver();
    void drawLvlOne();
    void drawInfo();
    void setupEnemies();
    void drawEnemies();
    void fightEnemies();
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

   public:
    Button* play_button;
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