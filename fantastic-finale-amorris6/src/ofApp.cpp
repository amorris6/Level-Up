#include "ofApp.h"

const float ofApp::kInitCritMult = 1.75;
const float ofApp::kInitBattleMult = 0.25;
const float ofApp::kPlayXAdj = 3.0 / 7.0;
const float ofApp::kPlayYAdj = 3.0 / 7.0;
const float ofApp::kPlayWidthAdj = 0.125;
const float ofApp::kPlayHeightAdj = 0.125;
const string ofApp::kPlayLabel = "PLAY";
const float ofApp::kPlayLabelXAdj = 0.01;
const float ofApp::kPlayLabelYAdj = 0.5;
const ofColor ofApp::kWhite = ofColor(255, 255, 255);
const ofColor ofApp::kBlack = ofColor(0, 0, 0);
const ofColor ofApp::kGrayClear = ofColor(150, 150, 150, 125);
const ofColor ofApp::kRed = ofColor(255, 0, 0);
const ofColor ofApp::kGreen = ofColor(0, 255, 0);
const ofColor ofApp::kBlue = ofColor(0, 0, 255);
const ofColor ofApp::kPurple = ofColor(255, 0, 255);
const ofColor ofApp::kYellow = ofColor(255, 255, 0);
const ofColor ofApp::kSkin = ofColor(255, 220, 8);
const string ofApp::kMusicFilePath = "C:\\CS 126\\Vivaldi-Spring.mp3";
const string ofApp::kFontFilePath = "C:\\CS 126\\Fonts\\Roboto-Black.ttf";
const string ofApp::kPlayerSpritePath =
    "C:\\CS 126\\Sprites\\player-sprite.png";
const string ofApp::kSmallFontName = "Roboto-Black-Small";
const string ofApp::kFontName = "Roboto-Black";
list<Resource> ofApp::resources = {};
int ofApp::lvl_num_ = 0;

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
    lvl_num_ = 0;
    battle_start_ = kStartBattle;
    fight_is_init_ = false;
    is_player_atk_turn_ = true;
    turns_fought_ = 0;
    battle_multiplier_ = kInitBattleMult;
    crit_mult_ = 1.0;
    battle_chance_ = kFightInit * 1 / (battle_multiplier_);
    player_is_fighting_ = false;
    enemy_fight_x_ = 0;
    atk_damage_ = 0;
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
    max_health_ = kStartHealth;
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
        battle_chance_ = kFightInit * 1 / (battle_multiplier_);
        battle_start_ = (rand() % 100);
        player_is_fighting_ = true;
    }
    if (player_is_fighting_) {
        battleEnemy();
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
void ofApp::battleEnemy() {
    Sleep(1000);
    if (!fight_is_init_) {
        setupBattle();
        fight_is_init_ = true;
    } else {
        turns_fought_++;
        is_crit_hit_ = false;
        checkBattleEnded(); //called before takeBattleTurn, 
		                    //so battle can be drawn when hp = 0
        takeBattleTurn();
    }
}

//-------------------------------------------------------------
void ofApp::checkBattleEnded() {
    if (enemy.getHealth() <= 0) {
        energy_left_ -= kEnergyBattle;
        player_is_fighting_ = false;
        fight_is_init_ = false;
        player.health = max_health_;
        player.exp += enemy.getExp();
        player.gold += enemy.getGold();
        is_player_atk_turn_ = true;
        turns_fought_ = 0;
    }
    if (player.getHealth() <= 0) {
        energy_left_ -= kEnergyBattle;
        energy_left_ -= kEnergyBattleLost;
        is_player_atk_turn_ = true;
        player_is_fighting_ = false;
        fight_is_init_ = false;
        player.health = max_health_;
        turns_fought_ = 0;
    }
}  
//-------------------------------------------------------------
void ofApp::takeBattleTurn() {
    if (is_player_atk_turn_) {
        int player_atk = player.getAtk();
        if (rand() % 100 <= player.getCrit()) {
            player_atk *= kInitCritMult * crit_mult_;
            is_crit_hit_ = true;
        }
        atk_damage_ = player_atk - enemy.getDef();
        enemy.health -= player.getAtk();
    } else {
        int enemy_atk = enemy.getAtk();
        if (rand() % 100 <= enemy.getCrit()) {
            enemy_atk *= kInitCritMult;
            is_crit_hit_ = true;
        }
        atk_damage_ = enemy_atk - enemy.getDef();
        player.health -= enemy.getAtk();
    }
}

//-------------------------------------------------------------
void ofApp::setupBattle() {
    for (int dir = UP; dir <= RIGHT; dir++) {
        move_key_is_pressed[dir] = false;
    }
	//keeping lvl_num_ inside allows for larger range of rand() % numbers,
	//otherwise numbers would just be divisible by lvl_num_
    int gold = max(rand() % kEnemyMaxGold * lvl_num_, kEnemyMinGold * lvl_num_);
    int exp = max((kEnemyMaxExp * lvl_num_ - gold * lvl_num_), kEnemyMinExp * lvl_num_);
    int atk = max(rand() % kEnemyMaxAtk * lvl_num_, kEnemyMinAtk * lvl_num_);
    int def = max(rand() % kEnemyMaxDef * lvl_num_, kEnemyMinDef * lvl_num_);
    int hp = max(rand() % kEnemyMaxHp * lvl_num_, kEnemyMinHp * lvl_num_);
    int crit = 2 * kStartCrit;
    enemy = Enemy(0, 0, gold, exp, atk, def, hp, crit);
    fight_is_init_ = true;
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
    if (player_is_fighting_) {
        drawBattle();
    } else if (energy_left_ <= 0) {
        drawGameOver();
    } else if (lvl_num_ == 0) {
        drawStartingScreen();
    } else {
        drawWorld();
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
void ofApp::drawWorld() {
    ofBackground(kWhite);
    drawInfo();
    drawPlayer();
    drawResources();
}

//--------------------------------------------------------------
void ofApp::drawBattle() {
    ofBackground(kGrayClear);
    ofSetColor(kSkin);
    player.player_sprite->draw(kPlayerFightX, kPlayerFightY,
                               kPlayerFightX + kPlayerFightWidth,
                               kPlayerFightY + kPlayerFightHeight);
    enemy_fight_x_ = ofGetWindowWidth() - kEnemyAdjX;
    ofDrawRectangle(enemy_fight_x_, kEnemyFightY, kEnemyFightWidth,
                    kEnemyFightHeight);
    ofSetColor(kWhite);
    drawAtk();
    drawBattleInfo();
}

//--------------------------------------------------------------
void ofApp::drawAtk() {
    string crit_message = "";
    if (is_crit_hit_) {
        ofSetColor(kRed);
        crit_message = "CRIT!";
    }
    if (is_player_atk_turn_ && turns_fought_ > 0) {
        ofDrawLine(enemy_fight_x_, kEnemyFightY,
                   enemy_fight_x_ + kEnemyFightWidth,
                   kEnemyFightY + kEnemyFightHeight);
        info_font->draw(crit_message, enemy_fight_x_ + kEnemyFightWidth + 10,
                        kEnemyFightY + kEnemyFightHeight / 2);
        is_player_atk_turn_ = !is_player_atk_turn_;
    } else if (!is_player_atk_turn_ && turns_fought_ > 0) {
        ofDrawLine(kPlayerFightX + 20, kPlayerFightY + 30,
                   kPlayerFightX + kPlayerFightWidth + 20,
                   kPlayerFightY + kPlayerFightHeight + 30);
        info_font->draw(crit_message, kPlayerFightX + kPlayerFightWidth + 10,
                        kEnemyFightY + kEnemyFightHeight / 2);
        is_player_atk_turn_ = !is_player_atk_turn_;
    }
}
//--------------------------------------------------------------
void ofApp::drawBattleInfo() {
    ofSetColor(kWhite);
    string player_hp = to_string(max(player.getHealth(), 0));
    string enemy_hp = to_string(max(enemy.getHealth(), 0));
    string player_hp_message = "HP: " + player_hp;
    string enemy_hp_message = "HP: " + enemy_hp;
    info_font->draw(player_hp_message, kPlayerFightX + 40, kPlayerFightY + 40);
    info_font->draw(enemy_hp_message, enemy_fight_x_ + 10, kEnemyFightY - 20);
    if (enemy.getHealth() <= 0) {
        drawWinBattleInfo();
    }
}

//--------------------------------------------------------------
void ofApp::drawWinBattleInfo() {
    string enemy_gold = to_string(enemy.getGold());
    string enemy_exp = to_string(enemy.getExp());
    string gold_message = "YOU GOT " + enemy_gold + " GOLD!";
    string exp_message = "YOU GOT " + enemy_exp + " EXP!";
    info_font->draw(gold_message, 3.0 * ofGetWindowWidth() / 7.0,
                    ofGetWindowHeight() - 2 * kInfoFontSize);
    info_font->draw(exp_message, 3.0 * ofGetWindowWidth() / 7.0,
                    ofGetWindowHeight() - kInfoFontSize);
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
    string lvl_num = to_string(lvl_num_);
    string lvl_message = "LEVEL: " + lvl_num;
    string battle_chance =
        to_string(max((int)(battle_chance_ * battle_multiplier_), 0));
    string battle_message = "Battle Chance: " + battle_chance + "%";
    info_font->draw(gold_message, 0, kInfoFontSize);
    info_font->draw(exp_message, 0, 2 * kInfoFontSize);
    info_font->draw(lvl_message, 3.0 * ofGetWindowWidth() / 7.0,
                    3.0 * ofGetWindowHeight() / 7.0);
    info_font->draw(battle_message, 3.0 * ofGetWindowWidth() / 7.0,
                    kInfoFontSize);
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
    if (lvl_num_ == 0 || player_is_fighting_) {
        return;
    }
    int upper_key = toupper(key);
    switch (upper_key) {
        case 'W':
            if (!move_key_is_pressed[UP]) {
                move_key_is_pressed[UP] = true;
            }
            break;
        case 'S':
            if (!move_key_is_pressed[DOWN]) {
                move_key_is_pressed[DOWN] = true;
            }
            break;
        case 'A':
            if (!move_key_is_pressed[LEFT]) {
                move_key_is_pressed[LEFT] = true;
            }
            break;
        case 'D':
            if (!move_key_is_pressed[RIGHT]) {
                move_key_is_pressed[RIGHT] = true;
            }
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    if (lvl_num_ == 0 || player_is_fighting_) {
        return;
    }
    int upper_key = toupper(key);
    switch (upper_key) {
        case 'W':
            move_key_is_pressed[UP] = false;
            break;
        case 'S':
            move_key_is_pressed[DOWN] = false;
            break;
        case 'A':
            move_key_is_pressed[LEFT] = false;
            break;
        case 'D':
            move_key_is_pressed[RIGHT] = false;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    if (lvl_num_ == 0 && play_button->mouseIsInside(x, y)) {
        lvl_num_++;
    }
}
