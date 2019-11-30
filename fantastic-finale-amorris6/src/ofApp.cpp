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
list<Enemy> ofApp::enemies = {};

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
    battles_left_ = kInitialBattles;
    background_music_enabled_ = true;
    background_music_player = new ofSoundPlayer();
    background_music_player->load(kMusicFilePath);
    ofxSmartFont::add(kFontFilePath, kButtonFontSize, "Roboto-Black");
    ofxSmartFont::add(kFontFilePath, kInfoFontSize, "Roboto-Black-Small");
    button_font = ofxSmartFont::get("Roboto-Black");
    info_font = ofxSmartFont::get("Roboto-Black-Small");
    play_button = new Button(
        kPlayXAdj * ofGetWindowWidth(), kPlayYAdj * ofGetWindowHeight(),
        kPlayWidthAdj * ofGetWindowWidth(),
        kPlayHeightAdj * ofGetWindowHeight(), kPlayLabel, *button_font);
    player = Player(kStartX, kStartY, kStartGold, kStartExp, kStartAtk,
                    kStartDef, kStartHealth, kStartCrit);
    player.player_sprite->load(kPlayerSpritePath);
    setupEnemies();
}

//--------------------------------------------------------------
void ofApp::setupEnemies() {
    // randomly places the enemies, but makes sure they don't intersect player
    // at start
    enemies.clear();
    for (int i = 0; i < kMaxEnemyNum; ++i) {
        int x = (rand() % (ofGetWindowWidth() - 2 * Character::kCharWidth)) +
                Character::kCharWidth;
        int y = (rand() % (ofGetWindowHeight() - 2 * Character::kCharHeight)) +
                Character::kCharHeight;
        int gold = rand() % kEnemyMaxGold + 1;
        int exp = kEnemyMaxExp - gold;
        enemies.push_back(Enemy(x, y, gold, exp, 0, 0, 0, 0));
    }
    // makes sure enemies aren't intersecting each other
    for (auto& enemy1 : enemies) {
        for (auto& enemy2 : enemies) {
            if (enemy1.getRect().intersects(enemy2.getRect()) &&
                enemy1 != enemy2) {
                setupEnemies();
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int dir = UP; dir <= RIGHT; dir++) {
        if (move_key_is_pressed[dir]) {
            moveInDirection(player, dir);
        }
    }
    if (enemies.empty()) {
        setupEnemies();
    }
    fightEnemies();
    // TODO: Create arrays of string file paths and ofSoundPlayers, creating
    // a looping soundtrack increment a variable to check times songs
    // switched, or just start playing at track1, instead of track0
    if (background_music_enabled_ && !background_music_player->isPlaying() &&
        battles_left_ > 0) {
        background_music_player->play();
    }
    draw();
}
//--------------------------------------------------------------
void ofApp::fightEnemies() {
    for (auto& enemy : enemies) {
        if (player.getRect().intersects(enemy.getRect())) {
            battles_left_--;
            lvl_num_ = 2;
            player.gold += enemy.getGold();
            player.exp += enemy.getExp();
            num_of_keys_pressed_ = 0;
            for (int dir = UP; dir <= RIGHT; dir++) {
                move_key_is_pressed[dir] = false;
            }
            enemies.remove(enemy);
            break;
        }
    }
}
//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(kRed);
    if (battles_left_ <= 0) {
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
    drawEnemies();
}

//--------------------------------------------------------------
void ofApp::drawInfo() {
    ofSetColor(0, 0, 0);
    string gold_gathered = to_string(player.getGold());
    string gold_message = "Gold Gathered: " + gold_gathered;
    string battles_left = to_string(battles_left_);
    string battle_message = "Battles Left: " + battles_left;
    string exp_gathered = to_string(player.getExp());
    string exp_message = "EXP: " + exp_gathered;
    info_font->draw(battle_message, ofGetWindowWidth() - 10 * kInfoFontSize,
                    kInfoFontSize);
    info_font->draw(gold_message, 0, kInfoFontSize);
    info_font->draw(exp_message, kPlayXAdj * ofGetWindowWidth(), kInfoFontSize);
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
void ofApp::drawEnemies() {
    for (auto& enemy : enemies) {
        ofSetColor(kBlack);
        if (enemy.getGold() >= kGoldShinyLim) {
            ofSetColor(kYellow);
        } else if (enemy.getExp() >= kExpShinyLim) {
            if (ofGetBackgroundColor() == kWhite) {
                ofSetColor(kBlack);
                ofNoFill();
            } else {
                ofSetColor(kWhite);
			}
        }
        ofDrawRectangle(enemy.getRect());
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
