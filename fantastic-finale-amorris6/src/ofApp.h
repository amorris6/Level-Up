#pragma once

#include "Player.h"
#include "ofMain.h"
#include "ofxSmartFont.h"

class ofApp : public ofBaseApp {
   private:
    const static int kNumOfLvls = 10;
    const static int kFontSize = 28;
    bool move_key_is_pressed_[4] = {};
    int num_of_keys_pressed_ = 0;
    int lvl_num_ = 0;
    list<std::function<void()>> lvls;
    bool background_music_enabled_;
    ofSoundPlayer background_music_player_;
    shared_ptr<ofxSmartFont> myFont;
    Player player;
    void drawPlayer();
    void drawStartingScreen();
    void drawLvlOne();

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
