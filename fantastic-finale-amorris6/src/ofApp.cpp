#include "ofApp.h"

const float ofApp::kInitCritMult = 1.75;
const float ofApp::kInitBattleMult = 0.25;
const float ofApp::kCenterXFactor = 3.0 / 7.0;
const float ofApp::kCenterYFactor = 3.0 / 7.0;
const float ofApp::kPlayWidthAdj = 0.1;
const float ofApp::kPlayHeightAdj = 0.125;
const float ofApp::kSettingsWidthAdj = 0.18;
const float ofApp::kCritMsgYAdjFactor = 0.5;
const float ofApp::kEquippedYFactor = 0.5;
const float ofApp::kPriceYFactor = 0.5;
const float ofApp::kToggleMsgYFactor = 0.5;
const float ofApp::kStoreGoldXFactor = 1.0 / 7.0;
const string ofApp::kPlayLabel = "PLAY";
const string ofApp::kRestartLabel = "RESTART";
const string ofApp::kStoreLabel = "STORE";
const string ofApp::kInventoryLabel = "INVENTORY";
const string ofApp::kSettingsLabel = "SETTINGS";
const string ofApp::kToggleLabel = "";
const string ofApp::kBackLabel = "BACK";
const string ofApp::kNextLabel = "NEXT";
const string ofApp::kPrevLabel = "PREV";
const string ofApp::kLvlUpMessage = "LEVEL UP";
const string ofApp::kGameOverMessage = "GAME OVER";
const string ofApp::kCritMessage = "CRIT!";
const string ofApp::kGoldLabel = "GOLD: ";
const string ofApp::kPriceLabel = "PRICE: ";
const string ofApp::kHpLabel = "HP: ";
const string ofApp::kExpLabel = "EXP: ";
const string ofApp::kEnergyLabel = "ENERGY LEFT: ";
const string ofApp::kStageLabel = "STAGE: ";
const string ofApp::kLvlLabel = "LEVEL: ";
const string ofApp::kBattleChanceLabel = "BATTLE CHANCE: ";
const string ofApp::kPercentString = "%";
const string ofApp::kGetRewardMsg = "YOU GOT: ";
const string ofApp::kGetExpMsg = " EXP!";
const string ofApp::kGetGoldMsg = " GOLD!";
const string ofApp::kSaleMadeMsg = "Sold Successfully!";
const string ofApp::kPurchaseMadeMsg = "Bought Successfully";
const string ofApp::kNotEnoughGoldMsg = "Not Enough Gold";
const string ofApp::kEquipSuccessMsg = "Equipped";
const string ofApp::kNoOwnMsg = "You don't own this item";
const string ofApp::kAlreadyEquippedMsg = "Already Equipped";
const string ofApp::kAlreadyOwnedMsg = "Already Owned";
const string ofApp::kBkgrdMusicEnabledMsg = "Background Music Enabled";
const string ofApp::kBattleMusicEnabledMsg = "Battle Music Enabled";
const string ofApp::kAtkSoundEnabledMsg = "Attack Sound Enabled";
const string ofApp::kWorldTitle = "fantastic-finale-amorris6";
const string ofApp::kSwordName = "sword";
const string ofApp::kHelmetName = "helmet";
const string ofApp::kFastBattleGemName = "battle++";
const string ofApp::kSlowBattleGemName = "battle--";
const string ofApp::kMoreExpGemName = "exp++";
const string ofApp::kMoreGoldGemName = "gold++";
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
const string ofApp::kStoreFontName = "Roboto-Black-Store";
const string ofApp::kFontName = "Roboto-Black";
const string ofApp::kUnequippedMsg = "UNEQUIPPED";
const string ofApp::kEquippedMsg = "EQUIPPED";
list<Resource> ofApp::resources_ = {};
float ofApp::battle_multiplier_ = kInitBattleMult;
const float ofApp::kBattleMultFactor = 2;
float ofApp::exp_mult_ = 1;
const float ofApp::kExpMultFactor = 1.3;
float ofApp::gold_mult_ = 1;
const float ofApp::kGoldMultFactor = 1.3;
int ofApp::battle_chance_ = 0;
int ofApp::page_num_ = 0;
int ofApp::stage_num_ = 0;
int ofApp::lvls_inc_ = 0;
int ofApp::energy_left_ = kInitialEnergy;
int ofApp::battle_start_ = kStartBattle;
bool ofApp::store_is_open_ = false;
bool ofApp::inventory_is_open_ = false;
bool ofApp::settings_is_open_ = false;
bool ofApp::game_over_is_set_up_ = false;
bool ofApp::not_enough_gold_ = false;
bool ofApp::item_already_owned_ = false;
bool ofApp::background_music_enabled_ = true;
bool ofApp::atk_sound_enabled_ = true;
bool ofApp::battle_music_enabled_ = true;
bool ofApp::move_key_is_pressed[4] = {};
Player ofApp::player_ = Player(kStartX, kStartY, kStartGold, kStartExp,
                               kStartAtk, kStartDef, kStartHealth, kStartCrit);
Button* ofApp::play_button_ = nullptr;
Button* ofApp::restart_button_ = nullptr;
Button* ofApp::store_button_ = nullptr;
Button* ofApp::inventory_button_ = nullptr;
Button* ofApp::settings_button_ = nullptr;
Button* ofApp::toggle_bkgrd_music_button_ = nullptr;
Button* ofApp::toggle_battle_music_button_ = nullptr;
Button* ofApp::toggle_atk_sound_button_ = nullptr;
Button* ofApp::back_button_ = nullptr;
Button* ofApp::next_button_ = nullptr;
Button* ofApp::prev_button_ = nullptr;
shared_ptr<ofxSmartFont> ofApp::button_font_ = nullptr;
shared_ptr<ofxSmartFont> ofApp::info_font_ = nullptr;
shared_ptr<ofxSmartFont> ofApp::store_font_ = nullptr;
list<Button*> ofApp::buttons_ = {};

void ofApp::setup() {
    srand(time(NULL));
    ofSetWindowTitle(kWorldTitle);
    fight_is_init_ = false;
    is_player_atk_turn_ = true;
    should_delay_ = false;
    purchase_made_ = false;
    sale_made_ = false;
    tried_equip_not_own_ = false;
    already_equipped_ = false;
    equip_success_ = false;
    turns_fought_ = 0;
    crit_mult_ = 1.0;
    battle_chance_ = kFightInit * 1 / (battle_multiplier_);
    player_is_fighting_ = false;
    enemy_fight_x_ = 0;
    atk_damage_ = 0;
    background_music_player_ = new ofSoundPlayer();
    atk_sound_player_ = new ofSoundPlayer();
    battle_music_player_ = new ofSoundPlayer();
    background_music_player_->load(kBkgrndMusicFilePath);
    atk_sound_player_->load(kAtkSoundFilePath);
    atk_sound_player_->setVolume(0.2);
    battle_music_player_->load(kBattleMusicFilePath);
    battle_music_player_->setLoop(true);
    ofxSmartFont::add(kFontFilePath, Button::kButtonFontSize, kFontName);
    ofxSmartFont::add(kFontFilePath, kInfoFontSize, kSmallFontName);
    ofxSmartFont::add(kFontFilePath, kStoreFontSize, kStoreFontName);
    button_font_ = ofxSmartFont::get(kFontName);
    info_font_ = ofxSmartFont::get(kSmallFontName);
    store_font_ = ofxSmartFont::get(kStoreFontName);
    setupButtons();
    items_ = {nullptr};
    setupItems();
    player_.player_sprite->load(kPlayerSpritePath);
    setupResources();
}

//--------------------------------------------------------------
// One page can hold 32 items, if have more than 32, go to second page
void ofApp::setupItems() {
    items_.clear();
    ofVec2f pos[kMaxItemsOnPage];
    int i = 0;
    for (int y = kStorePosYStart; y < ofGetWindowHeight() - kStorePosYEndAdj;
         y += kStorePosXEndAdj) {
        for (int x = kStorePosXStart; x < ofGetWindowWidth() - kStorePosXEndAdj;
             x += kStorePosXInc) {
            ofVec2f pos_;
            pos_.set(x, y);
            pos[i] = pos_;
            i++;
        }
    }
    Weapon* sword =
        new Weapon(kSwordName, kSwordPrice, kSwordPageNum, pos[kSwordPosIndex],
                   kSwordAtkBoost, store_font_);
    Armor* helmet = new Armor(kHelmetName, kHelmetPrice, kHelmetPageNum,
                              pos[kHelmetPosIndex], kHelmetDefBoost,
                              kHelmetHpBoost, store_font_);
    Item* fast_battle_gem =
        new Item(kFastBattleGemName, kFastBattleGemPrice, kFastBattleGemPageNum,
                 pos[kFastBattleGemPosIndex], speedBattleChance,
                 slowBattleChance, store_font_);
    Item* slow_battle_gem =
        new Item(kSlowBattleGemName, kSlowBattleGemPrice, kSlowBattleGemPageNum,
                 pos[kSlowBattleGemPosIndex], slowBattleChance,
                 speedBattleChance, store_font_);
    Item* more_exp_gem =
        new Item(kMoreExpGemName, kMoreGoldGemPrice, kMoreExpGemPageNum,
                 pos[kMoreExpGemPosIndex], increaseExpGain, decreaseExpGain,
                 store_font_);
    Item* more_gold_gem =
        new Item(kMoreGoldGemName, kMoreGoldGemPrice, kMoreGoldGemPageNum,
                 pos[kMoreGoldGemPosIndex], increaseGoldGain, decreaseGoldGain,
                 store_font_);

    items_.push_back(sword);
    items_.push_back(helmet);
    items_.push_back(fast_battle_gem);
    items_.push_back(slow_battle_gem);
    items_.push_back(more_exp_gem);
    items_.push_back(more_gold_gem);
}

//--------------------------------------------------------------
void ofApp::deleteItems() {
    for (auto& item : items_) {
        delete (item);
    }
}

//--------------------------------------------------------------
void ofApp::setupButtons() {
    deleteButtons();
    play_button_ =
        new Button(kCenterXFactor * ofGetWindowWidth(),
                   kCenterYFactor * ofGetWindowHeight(),
                   kPlayWidthAdj * ofGetWindowWidth(), Button::kButtonFontSize,
                   kPlayLabel, button_font_, setupWorld);
    settings_button_ = new Button(
        kCenterXFactor * ofGetWindowWidth() + kSettingsYAdj,
        kCenterYFactor * ofGetWindowHeight() + kSettingsXAdj,
        kSettingsWidthAdj * ofGetWindowWidth(), Button::kButtonFontSize,
        kSettingsLabel, button_font_, openSettings);
    toggle_bkgrd_music_button_ = new Button(
        kCenterXFactor * ofGetWindowWidth() + kToggleXAdj,
        kCenterYFactor * ofGetWindowHeight() + kToggleSpaceAdj, kToggleWidth,
        kToggleHeight, kToggleLabel, button_font_, toggleBkgrdMusic);
    toggle_atk_sound_button_ = new Button(
        kCenterXFactor * ofGetWindowWidth() + kToggleXAdj,
        toggle_bkgrd_music_button_->y_ + kToggleSpaceAdj, kToggleWidth,
        kToggleHeight, kToggleLabel, button_font_, toggleAtkSound);
    toggle_battle_music_button_ = new Button(
        kCenterXFactor * ofGetWindowWidth() + kToggleXAdj,
        toggle_atk_sound_button_->y_ + kToggleSpaceAdj, kToggleWidth,
        kToggleHeight, kToggleLabel, button_font_, toggleBattleMusic);
    restart_button_ = new Button(
        kCenterXFactor * ofGetWindowWidth() + kRestartXAdj,
        kCenterYFactor * ofGetWindowHeight() + kRestartYAdj,
        kPlayWidthAdj * ofGetWindowWidth() + kRestartWidthAdj,
        Button::kButtonFontSize, kRestartLabel, button_font_, restartGame);
    store_button_ = new Button(
        kCenterXFactor * ofGetWindowWidth() + kStoreXAdj,
        kCenterYFactor * ofGetWindowHeight() + kStoreYAdj,
        kPlayWidthAdj * ofGetWindowWidth() + kStoreWidthAdj,
        Button::kButtonFontSize, kStoreLabel, button_font_, openStore);
    inventory_button_ = new Button(
        0, ofGetWindowHeight() - (Button::kButtonFontSize),
        Button::kButtonFontSize + kInventoryWidthAdj, Button::kButtonFontSize,
        kInventoryLabel, info_font_, openInventory);
    back_button_ = new Button(
        0, 0, kPlayWidthAdj * ofGetWindowWidth() + kBackWidthAdj,
        kInfoFontSize + kBackHeightAdj, kBackLabel, info_font_, closePage);
    next_button_ = new Button(
        ofGetWindowWidth() - (kPlayWidthAdj * ofGetWindowWidth() + kNextXAdj),
        kInfoFontSize + kNextYAdj,
        kPlayWidthAdj * ofGetWindowWidth() + kNextWidthAdj,
        kInfoFontSize + kNextHeightAdj, kNextLabel, info_font_, increasePage);
    prev_button_ = new Button(
        0, kInfoFontSize + kPrevYAdj,
        kPlayWidthAdj * ofGetWindowWidth() + kPrevWidthAdj,
        kInfoFontSize + kPrevHeightAdj, kPrevLabel, info_font_, decreasePage);
    buttons_.push_back(play_button_);
    buttons_.push_back(settings_button_);
}

//--------------------------------------------------------------
void ofApp::deleteButtons() {
    delete (play_button_);
    delete (settings_button_);
    delete (toggle_bkgrd_music_button_);
    delete (toggle_atk_sound_button_);
    delete (toggle_battle_music_button_);
    delete (restart_button_);
    delete (store_button_);
    delete (inventory_button_);
    delete (back_button_);
    delete (next_button_);
    delete (prev_button_);
}
//--------------------------------------------------------------
void ofApp::setupResources() {
    resources_.clear();
    // creates 1 to kMaxresources resources
    int num_resources = (rand() % kMaxResourceNum) + 1;
    // randomly places the resources, but makes sure they don't intersect
    // player_ at start. Puts resources in a smaller, similar rectangle to
    // window
    for (int i = 0; i < num_resources; ++i) {
        int x = (rand() % (ofGetWindowWidth() -
                           kResourcePosAdj * Character::kCharWidth)) +
                Character::kCharWidth;
        int y = (rand() % (ofGetWindowHeight() -
                           kResourcePosAdj * Character::kCharHeight)) +
                Character::kCharHeight;
        int gold = rand() % kResourceMaxGold + 1;
        int exp = kResourceMaxExp - gold;
        resources_.push_back(Resource(x, y, gold, exp));
    }
    // makes sure resources aren't intersecting each other
    for (auto& resource1 : resources_) {
        bool is_reordered = false;
        for (auto& resource2 : resources_) {
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
    if (player_.getExp() < kExpLimit) {
        if (lvls_inc_ > 0) {
            draw();
            Sleep(kMessageDelay);
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
    // TODO: Create arrays of string file paths and ofSoundplayer_s, creating
    // a looping soundtrack increment a variable to check times songs
    // switched, or just start playing at track1, instead of track0
    if (energy_left_ > 0 && background_music_enabled_ &&
        !background_music_player_->isPlaying()) {
        background_music_player_->play();
    } else if (!background_music_enabled_ &&
               background_music_player_->isPlaying()) {
        background_music_player_->stop();
    }
}

//--------------------------------------------------------------
void ofApp::lvlUp() {
    player_.lvl_++;
    lvls_inc_++;
    player_.atk_ += kLvlUpGain;
    player_.def_ += kLvlUpGain;
    player_.max_health_ += kLvlUpGain;
    player_.health_ = player_.max_health_;
    player_.exp_ -= kExpLimit;
}

//--------------------------------------------------------------
void ofApp::setupWorld() {
    buttons_.remove(play_button_);
    buttons_.remove(settings_button_);
    buttons_.push_back(inventory_button_);
    stage_num_ = 1;
}

//--------------------------------------------------------------
void ofApp::updatePlayerPos() {
    bool player_is_moving = false;
    bool battle_chance_inc = false;
    for (int dir = UP; dir <= RIGHT; dir++) {
        if (move_key_is_pressed[dir]) {
            player_is_moving = true;
            player_.moveInDirection(dir);
        }
        if (player_is_moving && !battle_chance_inc) {
            battle_chance_inc = true;
            battle_chance_++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::slowBattleChance() { battle_multiplier_ /= kBattleMultFactor; }

//--------------------------------------------------------------
void ofApp::speedBattleChance() { battle_multiplier_ *= kBattleMultFactor; }

//--------------------------------------------------------------
void ofApp::increaseGoldGain() { gold_mult_ *= kGoldMultFactor; }

//--------------------------------------------------------------
void ofApp::decreaseGoldGain() { gold_mult_ /= kGoldMultFactor; }

//--------------------------------------------------------------
void ofApp::increaseExpGain() { exp_mult_ *= kExpMultFactor; }

//--------------------------------------------------------------
void ofApp::decreaseExpGain() { exp_mult_ /= kExpMultFactor; }

//--------------------------------------------------------------
void ofApp::battleEnemy() {
    if (!fight_is_init_) {
        setupBattle();
        fight_is_init_ = true;
        background_music_player_->setPaused(true);
        Sleep(kAtkDelay);
        if (battle_music_enabled_) {
            battle_music_player_->play();
        }
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
    buttons_.remove(inventory_button_);
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
    int crit = kEnemyCritFactor * kStartCrit;
    enemy_ = Enemy(0, 0, gold, exp, atk, def, hp, crit);
    fight_is_init_ = true;
    energy_left_ -= kEnergyBattle;
}

//-------------------------------------------------------------
void ofApp::checkBattleEnded() {
    if (enemy_.getHealth() <= 0) {
        player_is_fighting_ = false;
        fight_is_init_ = false;
        player_.health_ = player_.max_health_;
        player_.exp_ += (enemy_.getExp() * exp_mult_);
        player_.gold_ += (enemy_.getGold() * gold_mult_);
        is_player_atk_turn_ = true;
        turns_fought_ = 0;
        battle_music_player_->stop();
        background_music_player_->setPaused(false);
        buttons_.push_back(inventory_button_);
    }
    if (player_.getHealth() <= 0) {
        energy_left_ -= kEnergyBattleLost;
        is_player_atk_turn_ = true;
        player_is_fighting_ = false;
        fight_is_init_ = false;
        player_.health_ = player_.max_health_;
        turns_fought_ = 0;
        battle_music_player_->stop();
        background_music_player_->setPaused(false);
        buttons_.push_back(inventory_button_);
    }
}
//-------------------------------------------------------------
void ofApp::takeBattleTurn() {
    if (is_player_atk_turn_) {
        int player_atk = player_.getAtk();
        if (rand() % 100 <= player_.getCrit()) {
            player_atk *= (kInitCritMult * crit_mult_);
            is_crit_hit_ = true;
        }
        atk_damage_ = max(player_atk - enemy_.getDef(), stage_num_);
        enemy_.health_ -= atk_damage_;
    } else {
        int enemy_atk = enemy_.getAtk();
        if (rand() % 100 <= enemy_.getCrit()) {
            enemy_atk *= kInitCritMult;
            is_crit_hit_ = true;
        }
        atk_damage_ = max(enemy_atk - player_.getDef(), stage_num_);
        player_.health_ -= atk_damage_;
    }
}

//--------------------------------------------------------------
void ofApp::mineResources() {
    for (auto& resource : resources_) {
        if (player_.getRect().intersects(resource.getRect())) {
            energy_left_--;
            player_.gold_ += (resource.getGold() * gold_mult_);
            player_.exp_ += (resource.getExp() * exp_mult_);
            resources_.remove(resource);
            break;
        }
    }
}
//--------------------------------------------------------------
void ofApp::draw() {
    if (store_is_open_) {
        drawStore();
    } else if (inventory_is_open_) {
        drawInventory();
    } else if (energy_left_ <= 0) {
        drawGameOver();
    } else if (player_is_fighting_) {
        drawBattle();
    } else if (settings_is_open_) {
        drawSettings();
    } else if (stage_num_ == 0) {
        drawStartingScreen();
    } else {
        drawWorld();
    }
    drawButtons();
}

//--------------------------------------------------------------
void ofApp::drawButtons() {
    for (auto& button : buttons_) {
        button->draw();
    }
}

//--------------------------------------------------------------
void ofApp::drawLvlUp() {
    ofSetColor(kGreen);
    button_font_->draw(kLvlUpMessage, ofGetWindowWidth() * kCenterXFactor,
                       ofGetWindowHeight() * kCenterYFactor + kLvlUpYAdj);
}

//--------------------------------------------------------------
void ofApp::drawGameOver() {
    if (!game_over_is_set_up_) {
        setupGameOver();
    }
    ofBackground(kBlack);
    ofSetColor(kWhite);
    ofSetWindowTitle(kGameOverMessage);
    button_font_->draw(kGameOverMessage, kCenterXFactor * ofGetWindowWidth(),
                       kCenterYFactor * ofGetWindowHeight());
}

//--------------------------------------------------------------
void ofApp::setupGameOver() {
    fight_is_init_ = false;
    if (background_music_player_->isPlaying()) {
        background_music_player_->stop();
    }
    if (battle_music_player_
            ->isPlaying()) {           // if starting battle makes energy <= 0,
        battle_music_player_->stop();  // checkBattleEnded doesn't get a chance
    }                                  // to stop battle music
    buttons_.remove(inventory_button_);
    buttons_.push_back(restart_button_);
    buttons_.push_back(store_button_);
    game_over_is_set_up_ = true;
}

//--------------------------------------------------------------
void ofApp::drawStartingScreen() { ofBackground(kWhite); }

//--------------------------------------------------------------
void ofApp::drawWorld() {
    ofSetWindowTitle(kWorldTitle);
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
    player_.player_sprite->draw(kPlayerFightX, kPlayerFightY,
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
        crit_message = kCritMessage;
    }
    if (is_player_atk_turn_ && turns_fought_ > 0) {
        if (atk_sound_enabled_) {
            atk_sound_player_->play();
        }
        ofDrawLine(enemy_fight_x_, kEnemyFightY,
                   enemy_fight_x_ + kEnemyFightWidth,
                   kEnemyFightY + kEnemyFightHeight);
        info_font_->draw(crit_message,
                         enemy_fight_x_ + kEnemyFightWidth + kCritMsgXAdj,
                         kEnemyFightY + kEnemyFightHeight * kCritMsgYAdjFactor);
        is_player_atk_turn_ = !is_player_atk_turn_;
    } else if (!is_player_atk_turn_ && turns_fought_ > 0) {
        if (atk_sound_enabled_) {
            atk_sound_player_->play();
        }
        ofDrawLine(kPlayerFightX + kEnemyAtkXAdj, kPlayerFightY + kEnemyAtkYAdj,
                   kPlayerFightX + kPlayerFightWidth + kEnemyAtkXAdj,
                   kPlayerFightY + kPlayerFightHeight + kEnemyAtkYAdj);
        info_font_->draw(crit_message,
                         kPlayerFightX + kPlayerFightWidth + kCritMsgXAdj,
                         kEnemyFightY + kEnemyFightHeight * kCritMsgYAdjFactor);
        is_player_atk_turn_ = !is_player_atk_turn_;
    }
}
//--------------------------------------------------------------
void ofApp::drawBattleInfo() {
    ofSetColor(kWhite);
    string player_hp = to_string(max(player_.getHealth(), 0));
    string enemy_hp = to_string(max(enemy_.getHealth(), 0));
    string player_hp_message = kHpLabel + player_hp;
    string enemy_hp_message = kHpLabel + enemy_hp;
    info_font_->draw(player_hp_message, kPlayerFightX + kPlayerHpMsgXAdj,
                     kPlayerFightY + kPlayerHpMsgYAdj);
    info_font_->draw(enemy_hp_message, enemy_fight_x_ + kEnemyHpMsgXAdj,
                     kEnemyFightY + kEnemyHpMsgYAdj);
    if (enemy_.getHealth() <= 0) {
        drawWinBattleInfo();
    }
}

//--------------------------------------------------------------
void ofApp::drawWinBattleInfo() {
    string enemy_gold = to_string(enemy_.getGold());
    string enemy_exp = to_string(enemy_.getExp());
    string gold_message = kGetRewardMsg + enemy_gold + kGetGoldMsg;
    string exp_message = kGetRewardMsg + enemy_exp + kGetExpMsg;
    info_font_->draw(gold_message, ofGetWindowWidth() * kCenterXFactor,
                     ofGetWindowHeight() - kGoldMsgYAdjFactor * kInfoFontSize);
    info_font_->draw(exp_message, ofGetWindowWidth() * kCenterYFactor,
                     ofGetWindowHeight() - kInfoFontSize);
}

//--------------------------------------------------------------
void ofApp::drawInfo() {
    ofSetColor(0, 0, 0);
    string gold_gathered = to_string(player_.getGold());
    string gold_message = kGoldLabel + gold_gathered;
    string exp_gathered = to_string(player_.getExp());
    string exp_message = kExpLabel + exp_gathered;
    string energy_left = to_string(energy_left_);
    string energy_message = kEnergyLabel + energy_left;
    string stage_num = to_string(stage_num_);
    string stage_message = kStageLabel + stage_num;
    string level = to_string(player_.getLvl());
    string lvl_message = kLvlLabel + level;
    string battle_chance =
        to_string(max((int)(battle_chance_ * battle_multiplier_), 0));
    string battle_message = kBattleChanceLabel + battle_chance + kPercentString;
    info_font_->draw(gold_message, 0, kInfoFontSize);
    info_font_->draw(exp_message, 0, kExpMsgYFactor * kInfoFontSize);
    info_font_->draw(lvl_message, 0, kLvlMsgYFactor * kInfoFontSize);
    info_font_->draw(stage_message, ofGetWindowWidth() * kCenterXFactor,
                     ofGetWindowHeight() * kCenterYFactor);
    info_font_->draw(battle_message, ofGetWindowWidth() * kCenterXFactor,
                     kInfoFontSize);
    // puts energy_message in top right corner
    info_font_->draw(energy_message,
                     ofGetWindowWidth() - kEnergyMsgXFactor * kInfoFontSize,
                     kInfoFontSize);
}
//--------------------------------------------------------------
void ofApp::drawPlayer() {
    ofSetColor(kSkin);
    // makes the boundaries of the sprite line up with the hitbox
    // discovered through trial and error
    player_.player_sprite->draw(player_.getPos().x + kPlayerSpritePosAdj,
                                player_.getPos().y + kPlayerSpritePosAdj,
                                kPlayerSpriteWidth, kPlayerSpriteHeight);
}

//--------------------------------------------------------------
void ofApp::drawResources() {
    for (auto& resource : resources_) {
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
    for (auto& button : buttons_) {
        if (button->mouseIsInside(x, y)) {
            button->getFuncWhenPressed()();
            break;
        }
    }
    if (inventory_is_open_ || store_is_open_) {
        for (auto& item : items_) {
            Button item_button_s_[kItemButtonsOnScreen];
            if (inventory_is_open_) {
                item_button_s_[0] = item->inv_buttons_[0];
                item_button_s_[1] = item->inv_buttons_[1];
            } else {
                item_button_s_[0] = item->store_buttons_[0];
                item_button_s_[1] = item->store_buttons_[1];
            }
            if (checkIfItemEquipped(item)) {
                item_button_s_[1] = item->store_buttons_[2];
            }
            for (auto& item_button_ : item_button_s_) {
                if (item_button_.mouseIsInside(x, y)) {
                    item_button_.getFuncWhenPressed()();
                    break;
                }
            }
            if (item->wants_to_buy_) {
                buyItem(item);
                item->wants_to_buy_ = false;
                break;
            } else if (item->wants_to_sell_) {
                sellItem(item);
                item->wants_to_sell_ = false;
                break;
            } else if (item->wants_to_equip_) {
                equipItem(item);
                item->wants_to_equip_ = false;
                break;
            } else if (item->wants_to_unequip_) {
                unequipItem(item);
                item->wants_to_unequip_ = false;
                break;
            }
        }
    }
}

//--------------------------------------------------------------
bool ofApp::checkIfItemEquipped(Item* item) {
    Weapon* item_weapon = dynamic_cast<Weapon*>(item);
    Armor* item_armor = dynamic_cast<Armor*>(item);
    if (item_weapon) {
        return player_.equipped_weapon_ == item_weapon;
    }
    if (item_armor) {
        return player_.equipped_armor_ == item_armor;
    }
    if (item) {
        return player_.equipped_misc_ == item;
    }
    return false;
}

//--------------------------------------------------------------
void ofApp::buyItem(Item* item) {
    if (item->price_ > player_.getGold()) {
        not_enough_gold_ = true;
        return;
    }
    if (checkIfItemInInventory(item)) {
        item_already_owned_ = true;
        return;
    }
    purchase_made_ = true;
    player_.gold_ -= item->price_;
    player_.inventory_.push_back(item);
}

//--------------------------------------------------------------
void ofApp::sellItem(Item* item) {
    unequipItem(item);
    sale_made_ = true;
    player_.gold_ += (item->price_ * gold_mult_);
    player_.inventory_.remove(item);
}

//--------------------------------------------------------------
void ofApp::unequipItem(Item* item) {
    if (!item) {
        return;
    }
    Weapon* item_weapon = dynamic_cast<Weapon*>(item);
    Armor* item_armor = dynamic_cast<Armor*>(item);
    if (item_weapon) {
        if (player_.equipped_weapon_ == item_weapon) {
            player_.atk_ -= player_.equipped_weapon_->getAtkBoost();
            player_.equipped_weapon_ = nullptr;
        }
    } else if (item_armor) {
        if (player_.equipped_armor_ == item_armor) {
            player_.def_ -= player_.equipped_armor_->getDefBoost();
            player_.max_health_ -= player_.equipped_armor_->getHpBoost();
            player_.health_ = player_.max_health_;
            player_.equipped_armor_ = nullptr;
        }
    } else {
        if (player_.equipped_misc_ == item) {
            item->getFuncWhenUnequipped()();
            player_.equipped_misc_ = nullptr;
        }
    }
}

//--------------------------------------------------------------
void ofApp::equipItem(Item* item) {
    if (!checkIfItemInInventory(item)) {
        tried_equip_not_own_ = true;
        return;
    }
    Weapon* item_weapon = dynamic_cast<Weapon*>(item);
    Armor* item_armor = dynamic_cast<Armor*>(item);
    if (checkIfItemEquipped(item)) {
        already_equipped_ = true;
        return;
    }
    if (item_weapon) {
        unequipItem(player_.equipped_weapon_);
        player_.equipped_weapon_ = item_weapon;
        player_.atk_ += player_.equipped_weapon_->getAtkBoost();
    } else if (item_armor) {
        unequipItem(player_.equipped_armor_);
        player_.equipped_armor_ = item_armor;
        player_.def_ += player_.equipped_armor_->getDefBoost();
        player_.max_health_ += player_.equipped_armor_->getHpBoost();
        player_.health_ = player_.max_health_;
    } else {
        unequipItem(player_.equipped_misc_);
        player_.equipped_misc_ = item;
        item->getFuncWhenEquipped()();
    }
    equip_success_ = true;
}

//--------------------------------------------------------------
bool ofApp::checkIfItemInInventory(Item* item) {
    bool item_is_found = false;
    for (auto& item2 : player_.inventory_) {
        if (item2 == item) {
            item_is_found = true;
            break;
        }
    }
    return item_is_found;
}

//--------------------------------------------------------------
void ofApp::restartGame() {
    game_over_is_set_up_ = false;
    ofSetWindowTitle(kWorldTitle);
    stage_num_ = 0;
    energy_left_ = kInitialEnergy;
    battle_start_ = kStartBattle;
    battle_chance_ = kFightInit * 1 / (battle_multiplier_);
    resetPlayer();
    buttons_.clear();
    buttons_.push_back(play_button_);
    buttons_.push_back(settings_button_);
}

//--------------------------------------------------------------
void ofApp::resetPlayer() {
    auto tmp_player_weapon = player_.equipped_weapon_;
    auto tmp_player_armor = player_.equipped_armor_;
    auto tmp_player_misc = player_.equipped_misc_;
    auto tmp_inventory = player_.inventory_;
    if (player_.equipped_misc_) {
        player_.equipped_misc_->getFuncWhenUnequipped()();
    }
    player_ = Player(kStartX, kStartY, kStartGold, kStartExp, kStartAtk,
                     kStartDef, kStartHealth, kStartCrit);
    player_.player_sprite->load(kPlayerSpritePath);
    player_.inventory_ = tmp_inventory;
    player_.equipped_weapon_ = tmp_player_weapon;
    player_.equipped_armor_ = tmp_player_armor;
    player_.equipped_misc_ = tmp_player_misc;
    if (player_.equipped_weapon_ != nullptr) {
        player_.atk_ += player_.equipped_weapon_->getAtkBoost();
    }
    if (player_.equipped_armor_ != nullptr) {
        player_.def_ += player_.equipped_armor_->getDefBoost();
        player_.max_health_ += player_.equipped_armor_->getHpBoost();
        player_.health_ = player_.max_health_;
    }
    if (player_.equipped_misc_) {
        player_.equipped_misc_->getFuncWhenEquipped()();
    }
}

//--------------------------------------------------------------
void ofApp::closePage() {
    if (inventory_is_open_) {
        closeInventory();
    } else if (store_is_open_) {
        closeStore();
    } else if (settings_is_open_) {
        closeSettings();
    }
}

//--------------------------------------------------------------
void ofApp::openInventory() {
    ofSetWindowTitle(kInventoryLabel);
    for (int dir = UP; dir <= RIGHT; dir++) {
        move_key_is_pressed[dir] = false;
    }
    inventory_is_open_ = true;
    buttons_.remove(inventory_button_);
    buttons_.push_back(back_button_);
    buttons_.push_back(next_button_);
}

//-------------------------------------------------------------
void ofApp::closeInventory() {
    page_num_ = 0;
    inventory_is_open_ = false;
    buttons_.remove(back_button_);
    buttons_.remove(next_button_);
    buttons_.remove(prev_button_);
    buttons_.push_back(inventory_button_);
}

//-------------------------------------------------------------
void ofApp::drawInventory() {
    if (should_delay_) {
        Sleep(kMessageDelay);
        should_delay_ = false;
    }
    ofBackground(kTan);
    for (auto& item : player_.inventory_) {
        if (page_num_ != item->page_) {
            continue;
        }
        ofSetColor(kBlack);
        info_font_->draw(item->getName(), item->pos_.x,
                         item->pos_.y - kItemNameYFactor * kInfoFontSize);
        string equipped_status = kUnequippedMsg;
        if (checkIfItemEquipped(item)) {
            equipped_status = kEquippedMsg;
            item->unequip_button_->draw();
        } else {
            item->equip_button_->draw();
        }
        info_font_->draw(equipped_status, item->pos_.x + kEquippedXAdj,
                         item->pos_.y - kInfoFontSize * kEquippedYFactor);
        ofDrawRectangle(item->pos_, item->kWidth, item->kHeight);
        item->sell_button_->draw();
    };
    drawInventoryNotices();
}

//--------------------------------------------------------------
void ofApp::drawInventoryNotices() {
    ofSetColor(kWhite);
    if (sale_made_) {
        info_font_->draw(kSaleMadeMsg, ofGetWindowWidth() * kCenterYFactor,
                         ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        sale_made_ = false;
    } else {
        drawEquipNotices();
    }
}

//--------------------------------------------------------------
void ofApp::increasePage() {
    page_num_ = min(++page_num_, kMaxPageNum);
    if (page_num_ == 1) {
        buttons_.push_back(prev_button_);
    } else if (page_num_ == kMaxPageNum) {
        buttons_.remove(next_button_);
    }
}

//--------------------------------------------------------------
void ofApp::decreasePage() {
    page_num_ = max(--page_num_, 0);
    if (page_num_ == 0) {
        buttons_.remove(prev_button_);
    } else if (page_num_ == kMaxPageNum - 1) {
        buttons_.push_back(next_button_);
    }
}

//--------------------------------------------------------------
void ofApp::openStore() {
    ofSetWindowTitle(kStoreLabel);
    for (int dir = UP; dir <= RIGHT; dir++) {
        move_key_is_pressed[dir] = false;
    }
    store_is_open_ = true;
    buttons_.remove(store_button_);
    buttons_.remove(restart_button_);
    buttons_.push_back(back_button_);
    buttons_.push_back(next_button_);
}

//-------------------------------------------------------------
void ofApp::closeStore() {
    page_num_ = 0;
    store_is_open_ = false;
    buttons_.remove(back_button_);
    buttons_.remove(next_button_);
    buttons_.remove(prev_button_);
    buttons_.push_back(restart_button_);
    buttons_.push_back(store_button_);
}

//-------------------------------------------------------------
void ofApp::drawStore() {
    if (should_delay_) {
        Sleep(kMessageDelay);
        should_delay_ = false;
    }
    ofBackground(kTan);
    ofSetColor(kBlack);
    for (auto& item : items_) {
        if (page_num_ != item->page_) {
            continue;
        }
        info_font_->draw(item->getName(), item->pos_.x,
                         item->pos_.y - kItemNameYFactor * kInfoFontSize);
        string price = to_string(item->getPrice());
        info_font_->draw(kPriceLabel + price, item->pos_.x + kPriceXAdj,
                         item->pos_.y - kInfoFontSize * kPriceYFactor);
        ofDrawRectangle(item->pos_, item->kWidth, item->kHeight);
        item->buy_button_->draw();
        if (!checkIfItemEquipped(item)) {
            item->equip_button_->draw();
        } else {
            item->unequip_button_->draw();
        }
    };
    string gold = to_string(player_.getGold());
    info_font_->draw(kGoldLabel + gold, ofGetWindowWidth() * kStoreGoldXFactor,
                     kInfoFontSize);
    ofSetColor(kWhite);
    drawStoreNotices();
}

//--------------------------------------------------------------
void ofApp::drawStoreNotices() {
    if (purchase_made_) {
        info_font_->draw(kPurchaseMadeMsg, ofGetWindowWidth() * kCenterXFactor,
                         ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        purchase_made_ = false;
    } else if (not_enough_gold_) {
        info_font_->draw(kNotEnoughGoldMsg, ofGetWindowWidth() * kCenterXFactor,
                         ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        not_enough_gold_ = false;
    } else if (item_already_owned_) {
        info_font_->draw(kAlreadyOwnedMsg, ofGetWindowWidth() * kCenterXFactor,
                         ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        item_already_owned_ = false;
    } else {
        drawEquipNotices();
    }
}

//--------------------------------------------------------------
void ofApp::drawEquipNotices() {
    if (tried_equip_not_own_) {
        info_font_->draw(kNoOwnMsg, ofGetWindowWidth() * kCenterXFactor,
                         ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        tried_equip_not_own_ = false;
    } else if (already_equipped_) {
        info_font_->draw(kAlreadyEquippedMsg,
                         ofGetWindowWidth() * kCenterXFactor,
                         ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        already_equipped_ = false;
    } else if (equip_success_) {
        info_font_->draw(kEquipSuccessMsg, ofGetWindowWidth() * kCenterXFactor,
                         ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        equip_success_ = false;
    }
}

//-------------------------------------------------------------
void ofApp::openSettings() {
    ofSetWindowTitle(kSettingsLabel);
    settings_is_open_ = true;
    buttons_.remove(play_button_);
    buttons_.remove(settings_button_);
    buttons_.push_back(back_button_);
    buttons_.push_back(toggle_bkgrd_music_button_);
    buttons_.push_back(toggle_atk_sound_button_);
    buttons_.push_back(toggle_battle_music_button_);
}

//-------------------------------------------------------------
void ofApp::toggleBkgrdMusic() {
    background_music_enabled_ = !background_music_enabled_;
}

//-------------------------------------------------------------
void ofApp::toggleAtkSound() { atk_sound_enabled_ = !atk_sound_enabled_; }

//-------------------------------------------------------------
void ofApp::toggleBattleMusic() {
    battle_music_enabled_ = !battle_music_enabled_;
}

//-------------------------------------------------------------
void ofApp::closeSettings() {
    ofSetWindowTitle(kWorldTitle);
    settings_is_open_ = false;
    buttons_.push_back(play_button_);
    buttons_.push_back(settings_button_);
    buttons_.remove(back_button_);
    buttons_.remove(toggle_bkgrd_music_button_);
    buttons_.remove(toggle_atk_sound_button_);
    buttons_.remove(toggle_battle_music_button_);
}

//-------------------------------------------------------------
void ofApp::drawSettings() {
    ofSetColor(kBlack);
    drawToggleMessage(toggle_bkgrd_music_button_, kBkgrdMusicEnabledMsg);
    drawToggleMessage(toggle_atk_sound_button_, kAtkSoundEnabledMsg);
    drawToggleMessage(toggle_battle_music_button_, kBattleMusicEnabledMsg);
    if (background_music_enabled_) {
        drawXOnButton(toggle_bkgrd_music_button_);
    }
    if (battle_music_enabled_) {
        drawXOnButton(toggle_battle_music_button_);
    }
    if (atk_sound_enabled_) {
        drawXOnButton(toggle_atk_sound_button_);
    }
}

//-------------------------------------------------------------
void ofApp::drawToggleMessage(Button* button, string message) {
    info_font_->draw(
        message, (button->x_ + button->width_) + kToggleMsgXAdj,
        ((button->y_ + button->height_ * kToggleMsgYFactor) + kToggleMsgYAdj));
}

//-------------------------------------------------------------
void ofApp::drawXOnButton(Button* button) {
    ofDrawLine(button->x_, button->y_, button->x_ + button->width_,
               button->y_ + button->height_);
    ofDrawLine(button->x_ + button->width_, button->y_, button->x_,
               button->y_ + button->height_);
}

//-------------------------------------------------------------
void ofApp::exit() {
    deleteButtons();
    deleteItems();
    delete (background_music_player_);
    delete (atk_sound_player_);
    delete (battle_music_player_);
    delete (player_.player_sprite);
}