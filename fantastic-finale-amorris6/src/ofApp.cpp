#include "ofApp.h"

const float ofApp::kInitCritMult = 1.75;
const float ofApp::kInitBattleMult = 0.25;
const float ofApp::kPlayXAdj = 3.0 / 7.0;
const float ofApp::kPlayYAdj = 3.0 / 7.0;
const float ofApp::kPlayWidthAdj = 0.1;
const float ofApp::kPlayHeightAdj = 0.125;
const string ofApp::kPlayLabel = "PLAY";
const string ofApp::kRestartLabel = "RESTART";
const string ofApp::kStoreLabel = "STORE";
const string ofApp::kInventoryLabel = "INVENTORY";
const string ofApp::kBackLabel = "BACK";
const string ofApp::kNextLabel = "NEXT";
const string ofApp::kPrevLabel = "PREV";
const ofColor ofApp::kWhite = ofColor(255, 255, 255);
const ofColor ofApp::kBlack = ofColor(0, 0, 0);
const ofColor ofApp::kGrayClear = ofColor(150, 150, 150, 125);
const ofColor ofApp::kRed = ofColor(255, 0, 0);
const ofColor ofApp::kGreen = ofColor(0, 255, 0);
const ofColor ofApp::kBlue = ofColor(0, 0, 255);
const ofColor ofApp::kPurple = ofColor(255, 0, 255);
const ofColor ofApp::kYellow = ofColor(255, 255, 0);
const ofColor ofApp::kSkin = ofColor(255, 220, 8);
const ofColor ofApp::kTan = ofColor(210, 180, 140);
const string ofApp::kBkgrndMusicFilePath = "C:\\CS 126\\Vivaldi-Spring.mp3";
const string ofApp::kAtkSoundFilePath = "C:\\CS 126\\Wilhelm-Scream.mp3";
const string ofApp::kBattleMusicFilePath = "C:\\CS 126\\BattleMusic.mp3";
const string ofApp::kFontFilePath = "C:\\CS 126\\Fonts\\Roboto-Black.ttf";
const string ofApp::kPlayerSpritePath =
    "C:\\CS 126\\Sprites\\player-sprite.png";
const string ofApp::kSmallFontName = "Roboto-Black-Small";
const string ofApp::kFontName = "Roboto-Black";
list<Resource> ofApp::resources = {};
int ofApp::page_num_ = 0;
int ofApp::stage_num_ = 0;
int ofApp::lvls_inc_ = 0;
int ofApp::energy_left_ = kInitialEnergy;
int ofApp::battle_start_ = kStartBattle;
bool ofApp::store_is_open_ = false;
bool ofApp::inventory_is_open_ = false;
bool ofApp::game_over_is_set_up_ = false;
bool ofApp::move_key_is_pressed[4] = {};
Player ofApp::player = Player(kStartX, kStartY, kStartGold, kStartExp,
                              kStartAtk, kStartDef, kStartHealth, kStartCrit);
Button* ofApp::play_button = nullptr;
Button* ofApp::restart_button = nullptr;
Button* ofApp::store_button = nullptr;
Button* ofApp::inventory_button = nullptr;
Button* ofApp::back_store_button = nullptr;
Button* ofApp::back_inventory_button = nullptr;
Button* ofApp::next_store_button = nullptr;
Button* ofApp::next_inv_button = nullptr;
Button* ofApp::prev_store_button = nullptr;
Button* ofApp::prev_inv_button = nullptr;
shared_ptr<ofxSmartFont> ofApp::button_font = nullptr;
shared_ptr<ofxSmartFont> ofApp::info_font = nullptr;
list<Button*> ofApp::buttons = {};

void ofApp::setup() {
    srand(time(NULL));
    ofSetWindowTitle("fantastic-finale-amorris6");
    fight_is_init_ = false;
    is_player_atk_turn_ = true;
    turns_fought_ = 0;
    battle_multiplier_ = kInitBattleMult;
    crit_mult_ = 1.0;
    battle_chance_ = kFightInit * 1 / (battle_multiplier_);
    player_is_fighting_ = false;
    enemy_fight_x_ = 0;
    atk_damage_ = 0;
    background_music_enabled_ = true;
    background_music_player = new ofSoundPlayer();
    atk_sound_player = new ofSoundPlayer();
    battle_music_player = new ofSoundPlayer();
    background_music_player->load(kBkgrndMusicFilePath);
    atk_sound_player->load(kAtkSoundFilePath);
    atk_sound_player->setVolume(0.2);
    battle_music_player->load(kBattleMusicFilePath);
    ofxSmartFont::add(kFontFilePath, Button::kButtonFontSize, kFontName);
    ofxSmartFont::add(kFontFilePath, kInfoFontSize, kSmallFontName);
    button_font = ofxSmartFont::get(kFontName);
    info_font = ofxSmartFont::get(kSmallFontName);
    setupButtons();
    setupItems();
    max_health_ = kStartHealth;
    player.player_sprite->load(kPlayerSpritePath);
    setupResources();
}

//--------------------------------------------------------------
void ofApp::setupItems() {
    Item sword =
        Item("sword", 800, (ofVec2f)(50, 50), (ofVec2f)(50, 50), *info_font);
    Item helmet =
        Item("helmet", 800, (ofVec2f)(50, 50), (ofVec2f)(50, 50), *info_font);
    Item gem =
        Item("gem", 800, (ofVec2f)(50, 50), (ofVec2f)(50, 50), *info_font);
    items.push_back(sword);
    items.push_back(helmet);
    items.push_back(gem);
}

//--------------------------------------------------------------
void ofApp::setupButtons() {
    deleteButtons();
    play_button = new Button(
        kPlayXAdj * ofGetWindowWidth(), kPlayYAdj * ofGetWindowHeight(),
        kPlayWidthAdj * ofGetWindowWidth(), Button::kButtonFontSize, kPlayLabel,
        *button_font, setupWorld);
    restart_button = new Button(kPlayXAdj * ofGetWindowWidth() + 25,
                                kPlayYAdj * ofGetWindowHeight() + 50,
                                kPlayWidthAdj * ofGetWindowWidth() + 60,
                                Button::kButtonFontSize, kRestartLabel,
                                *button_font, restartGame);
    store_button = new Button(kPlayXAdj * ofGetWindowWidth() + 25,
                              kPlayYAdj * ofGetWindowHeight() + 100,
                              kPlayWidthAdj * ofGetWindowWidth() + 60,
                              Button::kButtonFontSize, kStoreLabel,
                              *button_font, openStore);
    inventory_button =
        new Button(0, ofGetWindowHeight() - (Button::kButtonFontSize),
                   Button::kButtonFontSize + 100, Button::kButtonFontSize,
                   kInventoryLabel, *info_font, openInventory);
    back_store_button =
        new Button(0, 0, kPlayWidthAdj * ofGetWindowWidth() / 2 + 10,
                   kInfoFontSize + 15, kBackLabel, *info_font, closeStore);
    back_inventory_button =
        new Button(0, 0, kPlayWidthAdj * ofGetWindowWidth() / 2 + 11,
                   kInfoFontSize + 15, kBackLabel, *info_font, closeInventory);
    next_store_button = new Button(
        ofGetWindowWidth() - (kPlayWidthAdj * ofGetWindowWidth() / 2 + 11),
        kInfoFontSize + 15,
        kPlayWidthAdj * ofGetWindowWidth() / 2 + 11, kInfoFontSize + 15,
        kNextLabel, *info_font, increaseStorePage);
    next_inv_button = new Button(
        ofGetWindowWidth() - (kPlayWidthAdj * ofGetWindowWidth() / 2 + 11),
        kInfoFontSize + 14,
        kPlayWidthAdj * ofGetWindowWidth() / 2 + 11,
        kInfoFontSize + 15, kNextLabel, *info_font, increaseInvPage);
    prev_store_button = new Button(
        0, kInfoFontSize + 15, kPlayWidthAdj * ofGetWindowWidth() / 2 + 10,
        kInfoFontSize + 15, kPrevLabel, *info_font, decreaseStorePage);
    prev_inv_button = new Button(
        0, kInfoFontSize + 15, kPlayWidthAdj * ofGetWindowWidth() / 2 + 11,
        kInfoFontSize + 15, kPrevLabel, *info_font, decreaseInvPage);
    buttons.push_back(play_button);
}

//--------------------------------------------------------------
void ofApp::deleteButtons() {
    delete (play_button);
    delete (restart_button);
    delete (store_button);
    delete (inventory_button);
    delete (back_store_button);
    delete (back_inventory_button);
    delete (next_store_button);
    delete (next_inv_button);
    delete (prev_store_button);
    delete (prev_inv_button);
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
    if (player.getExp() < kExpLimit) {
        if (lvls_inc_ > 0) {
            draw();
            Sleep(400);
        }
        lvls_inc_ = 0;
    } else {
        lvlUp();
    }
    if (energy_left_ <= 0) {
        player_is_fighting_ = false;
    }
    if (player_is_fighting_) {
        battleEnemy();
    }
    updatePlayerPos();
    mineResources();
    // TODO: Create arrays of string file paths and ofSoundPlayers, creating
    // a looping soundtrack increment a variable to check times songs
    // switched, or just start playing at track1, instead of track0
    if (energy_left_ > 0 && background_music_enabled_ &&
        !background_music_player->isPlaying()) {
        background_music_player->play();
    }
}

//--------------------------------------------------------------
void ofApp::lvlUp() {
    player.lvl++;
    lvls_inc_++;
    player.atk += kLvlUpGain;
    player.def += kLvlUpGain;
    max_health_ += kLvlUpGain;
    player.health = max_health_;
    player.exp -= kExpLimit;
}

//--------------------------------------------------------------
void ofApp::setupWorld() {
    buttons.remove(play_button);
    buttons.push_back(inventory_button);
    stage_num_ = 1;
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
    if (!fight_is_init_) {
        setupBattle();
        fight_is_init_ = true;
        background_music_player->setPaused(true);
        Sleep(kAtkDelay);
        battle_music_player->play();
    } else {
        Sleep(kAtkDelay);
        turns_fought_++;
        is_crit_hit_ = false;
        checkBattleEnded();  // called before takeBattleTurn,
                             // so battle can be drawn when hp = 0
        takeBattleTurn();
    }
}

//-------------------------------------------------------------
void ofApp::setupBattle() {
    for (int dir = UP; dir <= RIGHT; dir++) {
        move_key_is_pressed[dir] = false;
    }
    buttons.remove(inventory_button);
    // keeping stage_num_ inside allows for larger range of rand() % numbers,
    // otherwise numbers would just be divisible by stage_num_
    int gold =
        max(rand() % kEnemyMaxGold * stage_num_, kEnemyMinGold * stage_num_);
    int exp =
        max(rand() % kEnemyMaxExp * stage_num_, kEnemyMinExp * stage_num_);
    int atk =
        max(rand() % kEnemyMaxAtk * stage_num_, kEnemyMinAtk * stage_num_);
    int def =
        max(rand() % kEnemyMaxDef * stage_num_, kEnemyMinDef * stage_num_);
    int hp = max(rand() % kEnemyMaxHp * stage_num_, kEnemyMinHp * stage_num_);
    int crit = 2 * kStartCrit;
    enemy = Enemy(0, 0, gold, exp, atk, def, hp, crit);
    fight_is_init_ = true;
    energy_left_ -= kEnergyBattle;
}

//-------------------------------------------------------------
void ofApp::checkBattleEnded() {
    if (enemy.getHealth() <= 0) {
        player_is_fighting_ = false;
        fight_is_init_ = false;
        player.health = max_health_;
        player.exp += enemy.getExp();
        player.gold += enemy.getGold();
        is_player_atk_turn_ = true;
        turns_fought_ = 0;
        battle_music_player->stop();
        background_music_player->setPaused(false);
        buttons.push_back(inventory_button);
    }
    if (player.getHealth() <= 0) {
        energy_left_ -= kEnergyBattleLost;
        is_player_atk_turn_ = true;
        player_is_fighting_ = false;
        fight_is_init_ = false;
        player.health = max_health_;
        turns_fought_ = 0;
        battle_music_player->stop();
        background_music_player->setPaused(false);
    }
}
//-------------------------------------------------------------
void ofApp::takeBattleTurn() {
    if (is_player_atk_turn_) {
        int player_atk = player.getAtk();
        if (rand() % 100 <= player.getCrit()) {
            player_atk *= (kInitCritMult * crit_mult_);
            is_crit_hit_ = true;
        }
        atk_damage_ = max(player_atk - enemy.getDef(), stage_num_);
        enemy.health -= atk_damage_;
    } else {
        int enemy_atk = enemy.getAtk();
        if (rand() % 100 <= enemy.getCrit()) {
            enemy_atk *= kInitCritMult;
            is_crit_hit_ = true;
        }
        atk_damage_ = max(enemy_atk - player.getDef(), stage_num_);
        player.health -= atk_damage_;
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
    if (player_is_fighting_) {
        drawBattle();
    } else if (store_is_open_) {
        drawStore();
    } else if (inventory_is_open_) {
        drawInventory();
    } else if (energy_left_ <= 0) {
        drawGameOver();
    } else if (stage_num_ == 0) {
        drawStartingScreen();
    } else {
        drawWorld();
    }
    drawButtons();
}

//--------------------------------------------------------------
void ofApp::drawButtons() {
    for (auto& button : buttons) {
        button->draw();
	}
}

//--------------------------------------------------------------
void ofApp::drawLvlUp() {
    ofSetColor(kGreen);
    button_font->draw("LEVEL UP!", ofGetWindowWidth() * 3.0 / 7.0,
                      ofGetWindowHeight() * 2.0 / 7.0);
}

//--------------------------------------------------------------
void ofApp::drawGameOver() {
    if (!game_over_is_set_up_) {
        setupGameOver();
    }
    ofBackground(kBlack);
    ofSetColor(kWhite);
    string game_over_msg = "GAME OVER!";
    ofSetWindowTitle(game_over_msg);
    button_font->draw(game_over_msg, kPlayXAdj * ofGetWindowWidth(),
                      kPlayYAdj * ofGetWindowHeight());
    restart_button->draw();
    store_button->draw();
}

//--------------------------------------------------------------
void ofApp::setupGameOver() {
    if (background_music_player->isPlaying()) {
        background_music_player->stop();
    }
    if (battle_music_player
            ->isPlaying()) {          // if starting battle makes energy <= 0,
        battle_music_player->stop();  // checkBattleEnded doesn't get a chance
    }                                 // to stop battle music
    buttons.remove(inventory_button);
    buttons.push_back(restart_button);
    buttons.push_back(store_button);
    game_over_is_set_up_ = true;
}

//--------------------------------------------------------------
void ofApp::drawStartingScreen() {
    ofBackground(kWhite);
    ofSetColor(kBlack);
    play_button->draw();
}

//--------------------------------------------------------------
void ofApp::drawWorld() {
    ofSetWindowTitle("fantanstic-finale-amorris6");
    ofBackground(kWhite);
    drawInfo();
    drawPlayer();
    drawResources();
    if (lvls_inc_ > 0) {
        drawLvlUp();
    }
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
        atk_sound_player->play();
        ofDrawLine(enemy_fight_x_, kEnemyFightY,
                   enemy_fight_x_ + kEnemyFightWidth,
                   kEnemyFightY + kEnemyFightHeight);
        info_font->draw(crit_message, enemy_fight_x_ + kEnemyFightWidth + 10,
                        kEnemyFightY + kEnemyFightHeight / 2);
        is_player_atk_turn_ = !is_player_atk_turn_;
    } else if (!is_player_atk_turn_ && turns_fought_ > 0) {
        atk_sound_player->play();
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
    string stage_num = to_string(stage_num_);
    string stage_message = "STAGE: " + stage_num;
    string level = to_string(player.getLvl());
    string lvl_message = "LEVEL: " + level;
    string battle_chance =
        to_string(max((int)(battle_chance_ * battle_multiplier_), 0));
    string battle_message = "Battle Chance: " + battle_chance + "%";
    info_font->draw(gold_message, 0, kInfoFontSize);
    info_font->draw(exp_message, 0, 2 * kInfoFontSize);
    info_font->draw(lvl_message, 0, 3 * kInfoFontSize);
    info_font->draw(stage_message, 3.0 * ofGetWindowWidth() / 7.0,
                    3.0 * ofGetWindowHeight() / 7.0);
    info_font->draw(battle_message, 3.0 * ofGetWindowWidth() / 7.0,
                    kInfoFontSize);
    // puts energy_message in top right corner
    info_font->draw(energy_message, ofGetWindowWidth() - 10 * kInfoFontSize,
                    kInfoFontSize);
    inventory_button->draw();
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
    if (stage_num_ == 0 || player_is_fighting_ || store_is_open_ ||
        inventory_is_open_) {
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
    if (stage_num_ == 0 || player_is_fighting_ || store_is_open_ ||
        inventory_is_open_) {
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
    for (auto button : buttons) {
        if (button->mouseIsInside(x, y)) {
            button->getFuncWhenPressed()();
            break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::restartGame() {
    game_over_is_set_up_ = false;
    ofSetWindowTitle("fantastic-finale-amorris6");
    stage_num_ = 0;
    energy_left_ = kInitialEnergy;
    battle_start_ = kStartBattle;
    player = Player(kStartX, kStartY, kStartGold, kStartExp, kStartAtk,
                    kStartDef, kStartHealth, kStartCrit);
    player.player_sprite->load(kPlayerSpritePath);
    buttons.push_back(play_button);
}
//--------------------------------------------------------------
void ofApp::openInventory() {
    ofSetWindowTitle("INVENTORY");
    for (int dir = UP; dir <= RIGHT; dir++) {
        move_key_is_pressed[dir] = false;
    }
    inventory_is_open_ = true;
    buttons.remove(inventory_button);
    buttons.push_back(back_inventory_button);
    buttons.push_back(next_inv_button);
}

//-------------------------------------------------------------
void ofApp::closeInventory() {
    page_num_ = 0;
    inventory_is_open_ = false;
    buttons.remove(back_inventory_button);
    buttons.remove(next_inv_button);
    buttons.remove(prev_inv_button);
    buttons.push_back(inventory_button);
}
//-------------------------------------------------------------
void ofApp::drawInventory() {
    ofBackground(kTan);
    ofSetColor(kBlack);
    back_inventory_button->draw();
}

//--------------------------------------------------------------
void ofApp::increaseInvPage() { 
	page_num_ = min(++page_num_, kMaxInvPageNum); 
	if (page_num_ == 1) {
		buttons.push_back(prev_inv_button);    
	} else if (page_num_ == kMaxInvPageNum) {
		buttons.remove(next_inv_button);    
	}
}

//--------------------------------------------------------------
void ofApp::decreaseInvPage() { 
	page_num_ = max(--page_num_, 0); 
	if (page_num_ == 0) {
        buttons.remove(prev_inv_button);
    } else if (page_num_ == kMaxInvPageNum - 1) {
        buttons.push_back(next_inv_button);
    }
}

//--------------------------------------------------------------
void ofApp::openStore() {
    ofSetWindowTitle("STORE");
    for (int dir = UP; dir <= RIGHT; dir++) {
        move_key_is_pressed[dir] = false;
    }
    store_is_open_ = true;
    buttons.remove(store_button);
    buttons.remove(restart_button);
    buttons.push_back(back_store_button);
    buttons.push_back(next_store_button);
}

//-------------------------------------------------------------
void ofApp::closeStore() {
    page_num_ = 0;
    store_is_open_ = false;
    buttons.remove(back_store_button);
    buttons.remove(next_store_button);
    buttons.remove(prev_inv_button);
    buttons.push_back(restart_button);
    buttons.push_back(store_button);
}

//-------------------------------------------------------------
void ofApp::drawStore() {
    ofBackground(kTan);
    ofSetColor(kBlack);
    for (auto& item : items) {
        ofDrawRectangle(item.store_pos_, item.kWidth, item.kHeight);
        item.buy_button->draw();
        item.store_equip_button->draw();
    }
    back_store_button->draw();
}

//--------------------------------------------------------------
void ofApp::increaseStorePage() {
    page_num_ = min(++page_num_, kMaxStorePageNum);
    if (page_num_ == 1) {
        buttons.push_back(prev_store_button);
    } else if (page_num_ == kMaxStorePageNum) {
        buttons.remove(next_store_button);
    }
}

//--------------------------------------------------------------
void ofApp::decreaseStorePage() { 
	page_num_ = max(--page_num_, 0); 
	if (page_num_ == 0) {
        buttons.remove(prev_store_button);
    } else if (page_num_ == kMaxStorePageNum - 1) {
        buttons.push_back(next_store_button);
    }
}

//-------------------------------------------------------------
void ofApp::exit() {
    deleteButtons();
    delete (background_music_player);
    delete (atk_sound_player);
    delete (battle_music_player);
    delete (player.player_sprite);
}