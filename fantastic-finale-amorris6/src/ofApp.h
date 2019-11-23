#pragma once

#include "Player.h"
#include "ofMain.h"
#include "ofxSmartFont.h"

class ofApp : public ofBaseApp {
   private:
    const static int kNumOfLvls = 10;
    const static int kFontSize = 28;
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

    bool move_key_is_pressed_[4] = {};
    int num_of_keys_pressed_;
    int lvl_num_;
    list<std::function<void()>> lvls;
    bool background_music_enabled_;
    ofSoundPlayer background_music_player_;
    shared_ptr<ofxSmartFont> myFont = nullptr;
    Player player;
    void drawPlayer();
    void drawStartingScreen();
    void drawLvlOne();
    class Button {
       public:
        float x;
        float y;
        float width;
        float height;
        std::string label;
        shared_ptr<ofxSmartFont> label_font;
        bool MouseIsInside(int mouse_x, int mouse_y);
        void draw();
        Button(float x, float y, float width, float height, std::string label,
               shared_ptr<ofxSmartFont> label_font)
            : x(x),
              y(y),
              width(width),
              height(height),
              label(label),
              label_font(label_font) {}
    };

   ofxSmartFont play_button_font = *myFont;  // idk why but stops heap corruption

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