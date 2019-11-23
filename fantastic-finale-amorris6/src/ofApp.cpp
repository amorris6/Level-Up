#include "ofApp.h"

const float ofApp::kPlayXAdj = 3.0 / 7.0;
const float ofApp::kPlayYAdj = 3.0 / 7.0;
const float ofApp::kPlayWidthAdj = 1.0 / 8.0;
const float ofApp::kPlayHeightAdj = 1.0 / 8.0;
const string ofApp::kPlayLabel = "PLAY";
const float ofApp::kPlayLabelXAdj = 1 / 100.0;
const float ofApp::kPlayLabelYAdj = 1 / 2.0;
const ofColor ofApp::kWhite = ofColor(255, 255, 255);
const ofColor ofApp::kBlack = ofColor(0, 0, 0);
const ofColor ofApp::kRed = ofColor(255, 0, 0);
const ofColor ofApp::kGreen = ofColor(0, 255, 0);
const ofColor ofApp::kBlue = ofColor(0, 0, 255);
const ofColor ofApp::kPurple = ofColor(255, 0, 255);

bool ofApp::Button::MouseIsInside(int mouse_x, int mouse_y) {
    if (x <= mouse_x && mouse_x <= x + width && y <= mouse_y &&
        mouse_y <= y + height) {
        return true;
    }
    return false;
}

//--------------------------------------------------------------
void ofApp::Button::draw() {
    ofBackground(kWhite);
    ofSetColor(0, 0, 0);
    ofNoFill();
    ofDrawRectangle(x, y, width, height);
    ofSetColor(kBlack);
    label_font->draw(label, x + kPlayLabelXAdj * ofGetWindowWidth(),
                     y + height * kPlayLabelYAdj);
    ofFill();
}

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("fantastic-finale-amorris6");
    num_of_keys_pressed_ = 0;
    lvl_num_ = 0;
    background_music_enabled_ = true;
    background_music_player_.load("C:\\CS 126\\Vivaldi-Spring.mp3");
    ofxSmartFont::add("C:\\CS 126\\Fonts\\Roboto-Black.ttf", kFontSize,
                      "Roboto-Black");
    myFont = ofxSmartFont::get("Roboto-Black");

    play_button = new Button(
        kPlayXAdj * ofGetWindowWidth(), kPlayYAdj * ofGetWindowHeight(),
        kPlayWidthAdj * ofGetWindowWidth(),
        kPlayHeightAdj * ofGetWindowHeight(), kPlayLabel, myFont);
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int dir = UP; dir <= RIGHT; dir++) {
        if (move_key_is_pressed_[dir]) {
            moveInDirection(player, dir);
        }
    }
    // TODO: Create arrays of string file paths and ofSoundPlayers, creating
    // a looping soundtrack increment a variable to check times songs
    // switched, or just start playing at track1, instead of track0
    if (background_music_enabled_ && !background_music_player_.isPlaying()) {
        background_music_player_.play();
        //  background_music_player_.load("C:\\CS 126\\Vivaldi-Fall.mp3");
    }
    draw();
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(kRed);
    if (lvl_num_ == 0) {
        drawStartingScreen();
    } else {
        drawLvlOne();
    }
}

//--------------------------------------------------------------
void ofApp::drawStartingScreen() { play_button->draw(); }

//--------------------------------------------------------------
void ofApp::drawLvlOne() {
    if (num_of_keys_pressed_ != 0) {
        ofSetColor(kRed);
    } else {
        ofSetColor(kPurple);
    }
    drawPlayer();
}

//--------------------------------------------------------------
void ofApp::drawPlayer() {
    ofDrawRectangle(player.getPos().x, player.getPos().y, Player::kPlayerWidth,
                    Player::kPlayerHeight);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (lvl_num_ == 0) {
        return;
    }
    int upper_key = toupper(key);
    switch (upper_key) {
        case 'W':
            if (!move_key_is_pressed_[UP]) {
                num_of_keys_pressed_++;
                move_key_is_pressed_[UP] = true;
            }
            break;
        case 'S':
            if (!move_key_is_pressed_[DOWN]) {
                num_of_keys_pressed_++;
                move_key_is_pressed_[DOWN] = true;
            }
            break;
        case 'A':
            if (!move_key_is_pressed_[LEFT]) {
                num_of_keys_pressed_++;
                move_key_is_pressed_[LEFT] = true;
            }
            break;
        case 'D':
            if (!move_key_is_pressed_[RIGHT]) {
                num_of_keys_pressed_++;
                move_key_is_pressed_[RIGHT] = true;
            }
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    if (lvl_num_ == 0) {
        return;
    }
    int upper_key = toupper(key);
    switch (upper_key) {
        case 'W':
            num_of_keys_pressed_--;
            move_key_is_pressed_[UP] = false;
            break;
        case 'S':
            num_of_keys_pressed_--;
            move_key_is_pressed_[DOWN] = false;
            break;
        case 'A':
            num_of_keys_pressed_--;
            move_key_is_pressed_[LEFT] = false;
            break;
        case 'D':
            num_of_keys_pressed_--;
            move_key_is_pressed_[RIGHT] = false;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    if (play_button->MouseIsInside(x, y)) {
        lvl_num_++;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
