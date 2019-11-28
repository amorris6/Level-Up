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
const string ofApp::kMusicFilePath = "C:\\CS 126\\Vivaldi-Spring.mp3";
const string ofApp::kFontFilePath = "C:\\CS 126\\Fonts\\Roboto-Black.ttf";
list<Character> ofApp::enemies = {};

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
    label_font.draw(label, x + kPlayLabelXAdj * ofGetWindowWidth(),
                    y + height * kPlayLabelYAdj);
    ofFill();
}

//--------------------------------------------------------------
void ofApp::setup() {
    srand(time(NULL));
    ofSetWindowTitle("fantastic-finale-amorris6");
    num_of_keys_pressed_ = 0;
    lvl_num_ = 0;
    background_music_enabled_ = true;
    background_music_player = new ofSoundPlayer();
    background_music_player->load(kMusicFilePath);
    ofxSmartFont::add(kFontFilePath, kFontSize, "Roboto-Black");
    my_font = ofxSmartFont::get("Roboto-Black");
    play_button = new Button(
        kPlayXAdj * ofGetWindowWidth(), kPlayYAdj * ofGetWindowHeight(),
        kPlayWidthAdj * ofGetWindowWidth(),
        kPlayHeightAdj * ofGetWindowHeight(), kPlayLabel, *my_font);
    player = Character();
    setupEnemies();
}

//--------------------------------------------------------------
void ofApp::setupEnemies() {
    // randomly places the enemies, but makes sure they don't intersect player
    // at start
    for (int i = 0; i < kMaxEnemyNum; ++i) {
        int x = (rand() % (int) (ofGetWindowWidth() - Character::kPlayerWidth)) +
                Character::kPlayerWidth;
        int y = (rand() % (int) (ofGetWindowHeight() - Character::kPlayerHeight)) +
                Character::kPlayerHeight;
        enemies.push_back(Character(x, y));
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int dir = UP; dir <= RIGHT; dir++) {
        if (move_key_is_pressed[dir]) {
            moveInDirection(player, dir);
        }
    }
    for (auto& enemy : enemies) {
        if (player.getRect().intersects(enemy.getRect())) {
            enemies.remove(enemy);
            ofSetBackgroundColor(0, 0, 0);
            lvl_num_ = 0;
            num_of_keys_pressed_ = 0;
            for (int dir = UP; dir <= RIGHT; dir++) {
                move_key_is_pressed[dir] = false;
            }
        }
        break;
    }
    // TODO: Create arrays of string file paths and ofSoundPlayers, creating
    // a looping soundtrack increment a variable to check times songs
    // switched, or just start playing at track1, instead of track0
    if (background_music_enabled_ && !background_music_player->isPlaying()) {
        background_music_player->play();
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
    drawEnemies();
}

//--------------------------------------------------------------
void ofApp::drawPlayer() { ofDrawRectangle(player.getRect()); }

//--------------------------------------------------------------
void ofApp::drawEnemies() {
    for (auto& enemy : enemies) {
        ofDrawRectangle(enemy.getRect());
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (lvl_num_ == 0) {
        return;
    }
    int upper_key = toupper(key);
    switch (upper_key) {
        case 'W':
            if (!move_key_is_pressed[UP]) {
                num_of_keys_pressed_++;
                move_key_is_pressed[UP] = true;
            }
            break;
        case 'S':
            if (!move_key_is_pressed[DOWN]) {
                num_of_keys_pressed_++;
                move_key_is_pressed[DOWN] = true;
            }
            break;
        case 'A':
            if (!move_key_is_pressed[LEFT]) {
                num_of_keys_pressed_++;
                move_key_is_pressed[LEFT] = true;
            }
            break;
        case 'D':
            if (!move_key_is_pressed[RIGHT]) {
                num_of_keys_pressed_++;
                move_key_is_pressed[RIGHT] = true;
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
            move_key_is_pressed[UP] = false;
            break;
        case 'S':
            num_of_keys_pressed_--;
            move_key_is_pressed[DOWN] = false;
            break;
        case 'A':
            num_of_keys_pressed_--;
            move_key_is_pressed[LEFT] = false;
            break;
        case 'D':
            num_of_keys_pressed_--;
            move_key_is_pressed[RIGHT] = false;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    if (lvl_num_ == 0 && play_button->MouseIsInside(x, y)) {
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
