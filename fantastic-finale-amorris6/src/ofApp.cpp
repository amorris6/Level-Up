#include "ofApp.h"

const float ofApp::kStartCrit = 0.1;
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
const ofColor ofApp::kYellow = ofColor(255, 255, 0);
const ofColor ofApp::kSkin = ofColor(255, 220, 178);
const string ofApp::kMusicFilePath = "C:\\CS 126\\Vivaldi-Spring.mp3";
const string ofApp::kFontFilePath = "C:\\CS 126\\Fonts\\Roboto-Black.ttf";
const string ofApp::kPlayerSpritePath =
    "C:\\CS 126\\Sprites\\player-sprite.png";
const string ofApp::kSmallFontName = "Roboto-Black-Small";
const string ofApp::kFontName = "Roboto-Black";
list<Resource> ofApp::resources = {};

bool ofApp::Button::mouseIsInside(int mouse_x, int mouse_y) {
    if (x <= mouse_x && mouse_x <= x + width && y <= mouse_y &&
        mouse_y <= y + height) {
        return true;
    }
    return false;
}

//--------------------------------------------------------------
void ofApp::Button::draw() {
    ofBackground(kWhite);
    ofSetColor(kBlack);
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
    battle_start_ = kStartBattle;
    battle_chance_ = kFightInit;
    battle_multiplier_ = 1;
    energy_left_ = kInitialEnergy;
    background_music_enabled_ = true;
    background_music_player = new ofSoundPlayer();
    background_music_player->load(kMusicFilePath);
    ofxSmartFont::add(kFontFilePath, kButtonFontSize, kFontName);
    ofxSmartFont::add(kFontFilePath, kInfoFontSize, kSmallFontName);
    button_font = ofxSmartFont::get(kFontName);
    info_font = ofxSmartFont::get(kSmallFontName);
    play_button = new Button(
        kPlayXAdj * ofGetWindowWidth(), kPlayYAdj * ofGetWindowHeight(),
        kPlayWidthAdj * ofGetWindowWidth(),
        kPlayHeightAdj * ofGetWindowHeight(), kPlayLabel, *button_font);
    player = Player(kStartX, kStartY, kStartGold, kStartExp, kStartAtk,
                    kStartDef, kStartHealth, kStartCrit);
    player.player_sprite->load(kPlayerSpritePath);
    setupResources();
}

//--------------------------------------------------------------
void ofApp::setupResources() {
    resources.clear();
    // creates 1 to kMaxresources resources
    int num_resources = (rand() % kMaxResourceNum) + 1;
    // randomly places the resources, but makes sure they don't intersect player
    // at start
    for (int i = 0; i < num_resources; ++i) {
        int x = (rand() % (ofGetWindowWidth() - 3 * Character::kCharWidth)) +
                Character::kCharWidth;
        int y = (rand() % (ofGetWindowHeight() - 3 * Character::kCharHeight)) +
                Character::kCharHeight;
        int gold = rand() % kResourceMaxGold + 1;
        int exp = kResourceMaxExp - gold;
        resources.push_back(Resource(x, y, gold, exp));
    }
    // makes sure resources aren't intersecting each other
    for (auto& resource1 : resources) {
        bool is_reordered = false;
        for (auto& resource2 : resources) {
            if (resource1.getRect().intersects(resource2.getRect()) &&
                resource1 != resource2) {
                setupResources();
                is_reordered = true;
                break;
            }
        }
        if (is_reordered) {
            break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    if (battle_start_ < battle_chance_ * battle_multiplier_) {
        battle_chance_ = kFightInit;
        battle_start_ = (rand() % 100);
    }
    if (resources.empty()) {
        setupResources();
    }
    updatePlayerPos();
    mineResources();
    // TODO: Create arrays of string file paths and ofSoundPlayers, creating
    // a looping soundtrack increment a variable to check times songs
    // switched, or just start playing at track1, instead of track0
    if (background_music_enabled_ && !background_music_player->isPlaying() &&
        energy_left_ > 0) {
        background_music_player->play();
    }
    draw();
}

//--------------------------------------------------------------
void ofApp::updatePlayerPos() {
    bool player_is_moving = false;
    bool battle_chance_inc = false;
    for (int dir = UP; dir <= RIGHT; dir++) {
        if (move_key_is_pressed[dir]) {
            player_is_moving = true;
            player.moveInDirection(dir);
        }
        if (player_is_moving && !battle_chance_inc) {
            battle_chance_inc = true;
            battle_chance_++;
        }
    }
}
//--------------------------------------------------------------
void ofApp::mineResources() {
    for (auto& resource : resources) {
        if (player.getRect().intersects(resource.getRect())) {
            energy_left_--;
            player.gold += resource.getGold();
            player.exp += resource.getExp();
            resources.remove(resource);
            break;
        }
    }
}
//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(kRed);
    if (energy_left_ <= 0) {
        drawGameOver();
    } else if (lvl_num_ == 0) {
        drawStartingScreen();
    } else {
        drawLvlOne();
    }
}

//--------------------------------------------------------------
void ofApp::drawGameOver() {
    ofBackground(kBlack);
    ofSetColor(kWhite);
    string game_over_msg = "GAME OVER!";
    ofSetWindowTitle(game_over_msg);
    button_font->draw(game_over_msg, kPlayXAdj * ofGetWindowWidth(),
                      kPlayYAdj * ofGetWindowHeight());
}

//--------------------------------------------------------------
void ofApp::drawStartingScreen() { play_button->draw(); }

//--------------------------------------------------------------
void ofApp::drawLvlOne() {
    drawInfo();
    if (num_of_keys_pressed_ != 0) {
        ofSetColor(kRed);
    } else {
        ofSetColor(kPurple);
    }
    drawPlayer();
    drawResources();
}

//--------------------------------------------------------------
void ofApp::drawInfo() {
    ofSetColor(0, 0, 0);
    string gold_gathered = to_string(player.getGold());
    string gold_message = "Gold: " + gold_gathered;
    string exp_gathered = to_string(player.getExp());
    string exp_message = "EXP: " + exp_gathered;
    string energy_left = to_string(energy_left_);
    string energy_message = "Energy Left: " + energy_left;
    string battle_chance = to_string(battle_chance_);
    if (battle_chance_ < 0) {
        battle_chance = to_string(0);
	}
    string battle_message = "Battle Chance: " + battle_chance + "%";
    info_font->draw(gold_message, 0, kInfoFontSize);
    info_font->draw(exp_message, 0, 2 * kInfoFontSize);
    info_font->draw(battle_message, 3.0 * ofGetWindowWidth()/ 7.0, kInfoFontSize);
    // puts energy_message in top right corner
    info_font->draw(energy_message, ofGetWindowWidth() - 10 * kInfoFontSize,
                    kInfoFontSize);
}
//--------------------------------------------------------------
void ofApp::drawPlayer() {
    ofSetColor(kSkin);
    // makes the boundaries of the sprite line up with the hitbox
    // discovered through trial and error
    player.player_sprite->draw(player.getPos().x - 15, player.getPos().y - 15,
                               Character::kCharWidth + 20,
                               Character::kCharHeight + 20);
}

//--------------------------------------------------------------
void ofApp::drawResources() {
    for (auto& resource : resources) {
        ofSetColor(kBlack);
        if (resource.getGold() >= kGoldShinyLim) {
            ofSetColor(kYellow);
        } else if (resource.getExp() >= kExpShinyLim) {
            if (ofGetBackgroundColor() == kWhite) {
                ofSetColor(kBlack);
                ofNoFill();
            } else {
                ofSetColor(kWhite);
            }
        }
        ofDrawRectangle(resource.getRect());
        ofFill();
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
    if (lvl_num_ == 0 && play_button->mouseIsInside(x, y)) {
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
