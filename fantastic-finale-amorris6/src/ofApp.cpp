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
list<Resource> ofApp::resources = {};
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
Player ofApp::player = Player(kStartX, kStartY, kStartGold, kStartExp,
                              kStartAtk, kStartDef, kStartHealth, kStartCrit);
Button* ofApp::play_button = nullptr;
Button* ofApp::restart_button = nullptr;
Button* ofApp::store_button = nullptr;
Button* ofApp::inventory_button = nullptr;
Button* ofApp::settings_button = nullptr;
Button* ofApp::toggle_bkgrd_music_button = nullptr;
Button* ofApp::toggle_battle_music_button = nullptr;
Button* ofApp::toggle_atk_sound_button = nullptr;
Button* ofApp::back_button = nullptr;
Button* ofApp::next_button = nullptr;
Button* ofApp::prev_button = nullptr;
shared_ptr<ofxSmartFont> ofApp::button_font = nullptr;
shared_ptr<ofxSmartFont> ofApp::info_font = nullptr;
shared_ptr<ofxSmartFont> ofApp::store_font = nullptr;
list<Button*> ofApp::buttons = {};

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
    background_music_player = new ofSoundPlayer();
    atk_sound_player = new ofSoundPlayer();
    battle_music_player = new ofSoundPlayer();
    background_music_player->load(kBkgrndMusicFilePath);
    atk_sound_player->load(kAtkSoundFilePath);
    atk_sound_player->setVolume(0.2);
    battle_music_player->load(kBattleMusicFilePath);
    battle_music_player->setLoop(true);
    ofxSmartFont::add(kFontFilePath, Button::kButtonFontSize, kFontName);
    ofxSmartFont::add(kFontFilePath, kInfoFontSize, kSmallFontName);
    ofxSmartFont::add(kFontFilePath, kStoreFontSize, kStoreFontName);
    button_font = ofxSmartFont::get(kFontName);
    info_font = ofxSmartFont::get(kSmallFontName);
    store_font = ofxSmartFont::get(kStoreFontName);
    setupButtons();
    items = {nullptr};
    setupItems();
    player.player_sprite->load(kPlayerSpritePath);
    setupResources();
}

//--------------------------------------------------------------
// One page can hold 32 items, if have more than 32, go to second page
void ofApp::setupItems() {
    items.clear();
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
    Weapon* sword = new Weapon(kSwordName, kSwordPrice, kSwordPageNum,
                               pos[kSwordPosIndex], kSwordAtkBoost, store_font);
    Armor* helmet = new Armor(kHelmetName, kHelmetPrice, kHelmetPageNum,
                              pos[kHelmetPosIndex], kHelmetDefBoost,
                              kHelmetHpBoost, store_font);
    Item* fast_battle_gem =
        new Item(kFastBattleGemName, kFastBattleGemPrice, kFastBattleGemPageNum,
                 pos[kFastBattleGemPosIndex], speedBattleChance,
                 slowBattleChance, store_font);
    Item* slow_battle_gem =
        new Item(kSlowBattleGemName, kSlowBattleGemPrice, kSlowBattleGemPageNum,
                 pos[kSlowBattleGemPosIndex], slowBattleChance,
                 speedBattleChance, store_font);
    Item* more_exp_gem = new Item(kMoreExpGemName, kMoreGoldGemPrice,
                                  kMoreExpGemPageNum, pos[kMoreExpGemPosIndex],
                                  increaseExpGain, decreaseExpGain, store_font);
    Item* more_gold_gem =
        new Item(kMoreGoldGemName, kMoreGoldGemPrice, kMoreGoldGemPageNum,
                 pos[kMoreGoldGemPosIndex], increaseGoldGain, decreaseGoldGain,
                 store_font);

    items.push_back(sword);
    items.push_back(helmet);
    items.push_back(fast_battle_gem);
    items.push_back(slow_battle_gem);
    items.push_back(more_exp_gem);
    items.push_back(more_gold_gem);
}

//--------------------------------------------------------------
void ofApp::deleteItems() {
    for (auto& item : items) {
        delete (item);
    }
}

//--------------------------------------------------------------
void ofApp::setupButtons() {
    deleteButtons();
    play_button = new Button(
	     kCenterXFactor * ofGetWindowWidth(),
         kCenterYFactor * ofGetWindowHeight(),
         kPlayWidthAdj * ofGetWindowWidth(), 
		 Button::kButtonFontSize,
         kPlayLabel, 
		 button_font, 
		 setupWorld);
    settings_button = new Button(
        kCenterXFactor * ofGetWindowWidth() + kSettingsYAdj,
        kCenterYFactor * ofGetWindowHeight() + kSettingsXAdj,
        kSettingsWidthAdj * ofGetWindowWidth(), 
		Button::kButtonFontSize,
        kSettingsLabel, 
		button_font, 
		openSettings);
    toggle_bkgrd_music_button = new Button(
        kCenterXFactor * ofGetWindowWidth() + kToggleXAdj,
        kCenterYFactor * ofGetWindowHeight() + kToggleSpaceAdj, 
		kToggleWidth,
        kToggleHeight, 
		kToggleLabel, 
		button_font, 
		toggleBkgrdMusic);
    toggle_atk_sound_button = new Button(
		kCenterXFactor * ofGetWindowWidth() + kToggleXAdj,
        toggle_bkgrd_music_button->y + kToggleSpaceAdj, 
		kToggleWidth,
        kToggleHeight, 
		kToggleLabel, 
		button_font, 
		toggleAtkSound);
    toggle_battle_music_button = new Button(
		kCenterXFactor * ofGetWindowWidth() + kToggleXAdj,
        toggle_atk_sound_button->y + kToggleSpaceAdj,
		kToggleWidth,
        kToggleHeight, kToggleLabel, 
		button_font, 
		toggleBattleMusic);
    restart_button = new Button(
        kCenterXFactor * ofGetWindowWidth() + kRestartXAdj,
        kCenterYFactor * ofGetWindowHeight() + kRestartYAdj,
        kPlayWidthAdj * ofGetWindowWidth() + kRestartWidthAdj,
        Button::kButtonFontSize, 
		kRestartLabel, 
		button_font, 
		restartGame);
    store_button = new Button(
        kCenterXFactor * ofGetWindowWidth() + kStoreXAdj,
        kCenterYFactor * ofGetWindowHeight() + kStoreYAdj,
        kPlayWidthAdj * ofGetWindowWidth() + kStoreWidthAdj,
        Button::kButtonFontSize, 
		kStoreLabel,
		button_font, 
		openStore);
    inventory_button = new Button(
        0, 
		ofGetWindowHeight() - (Button::kButtonFontSize),
        Button::kButtonFontSize + kInventoryWidthAdj, 
		Button::kButtonFontSize,
        kInventoryLabel, 
		info_font, 
		openInventory);
    back_button = new Button(
        0, 
		0, 
		kPlayWidthAdj * ofGetWindowWidth() + kBackWidthAdj,
        kInfoFontSize + kBackHeightAdj,
		kBackLabel, 
		info_font, 
		closePage);
    next_button = new Button(
        ofGetWindowWidth() - (kPlayWidthAdj * ofGetWindowWidth() + kNextXAdj),
        kInfoFontSize + kNextYAdj,
        kPlayWidthAdj * ofGetWindowWidth() + kNextWidthAdj,
        kInfoFontSize + kNextHeightAdj, 
		kNextLabel,
		info_font, 
		increasePage);
    prev_button = new Button(
		0,
		kInfoFontSize + kPrevYAdj,
        kPlayWidthAdj * ofGetWindowWidth() + kPrevWidthAdj,
        kInfoFontSize + kPrevHeightAdj, 
		kPrevLabel,
        info_font, 
		decreasePage);
    buttons.push_back(play_button);
    buttons.push_back(settings_button);
}

//--------------------------------------------------------------
void ofApp::deleteButtons() {
    delete (play_button);
    delete (settings_button);
    delete (toggle_bkgrd_music_button);
    delete (toggle_atk_sound_button);
    delete (toggle_battle_music_button);
    delete (restart_button);
    delete (store_button);
    delete (inventory_button);
    delete (back_button);
    delete (next_button);
    delete (prev_button);
}
//--------------------------------------------------------------
void ofApp::setupResources() {
    resources.clear();
    // creates 1 to kMaxresources resources
    int num_resources = (rand() % kMaxResourceNum) + 1;
    // randomly places the resources, but makes sure they don't intersect player
    // at start. Puts resources in a smaller, similar rectangle to window
    for (int i = 0; i < num_resources; ++i) {
        int x = (rand() % (ofGetWindowWidth() -
                           kResourcePosAdj * Character::kCharWidth)) +
                Character::kCharWidth;
        int y = (rand() % (ofGetWindowHeight() -
                           kResourcePosAdj * Character::kCharHeight)) +
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
    // TODO: Create arrays of string file paths and ofSoundPlayers, creating
    // a looping soundtrack increment a variable to check times songs
    // switched, or just start playing at track1, instead of track0
    if (energy_left_ > 0 && background_music_enabled_ &&
        !background_music_player->isPlaying()) {
        background_music_player->play();
    } else if (!background_music_enabled_ &&
               background_music_player->isPlaying()) {
        background_music_player->stop();
    }
}

//--------------------------------------------------------------
void ofApp::lvlUp() {
    player.lvl++;
    lvls_inc_++;
    player.atk += kLvlUpGain;
    player.def += kLvlUpGain;
    player.max_health_ += kLvlUpGain;
    player.health = player.max_health_;
    player.exp -= kExpLimit;
}

//--------------------------------------------------------------
void ofApp::setupWorld() {
    buttons.remove(play_button);
    buttons.remove(settings_button);
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
        background_music_player->setPaused(true);
        Sleep(kAtkDelay);
        if (battle_music_enabled_) {
            battle_music_player->play();
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
    int crit = kEnemyCritFactor * kStartCrit;
    enemy = Enemy(0, 0, gold, exp, atk, def, hp, crit);
    fight_is_init_ = true;
    energy_left_ -= kEnergyBattle;
}

//-------------------------------------------------------------
void ofApp::checkBattleEnded() {
    if (enemy.getHealth() <= 0) {
        player_is_fighting_ = false;
        fight_is_init_ = false;
        player.health = player.max_health_;
        player.exp += (enemy.getExp() * exp_mult_);
        player.gold += (enemy.getGold() * gold_mult_);
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
        player.health = player.max_health_;
        turns_fought_ = 0;
        battle_music_player->stop();
        background_music_player->setPaused(false);
        buttons.push_back(inventory_button);
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
            player.gold += (resource.getGold() * gold_mult_);
            player.exp += (resource.getExp() * exp_mult_);
            resources.remove(resource);
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
    for (auto& button : buttons) {
        button->draw();
    }
}

//--------------------------------------------------------------
void ofApp::drawLvlUp() {
    ofSetColor(kGreen);
    button_font->draw(kLvlUpMessage, ofGetWindowWidth() * kCenterXFactor,
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
    button_font->draw(kGameOverMessage, kCenterXFactor * ofGetWindowWidth(),
                      kCenterYFactor * ofGetWindowHeight());
}

//--------------------------------------------------------------
void ofApp::setupGameOver() {
    fight_is_init_ = false;
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
        crit_message = kCritMessage;
    }
    if (is_player_atk_turn_ && turns_fought_ > 0) {
        if (atk_sound_enabled_) {
            atk_sound_player->play();
        }
        ofDrawLine(enemy_fight_x_, kEnemyFightY,
                   enemy_fight_x_ + kEnemyFightWidth,
                   kEnemyFightY + kEnemyFightHeight);
        info_font->draw(crit_message,
                        enemy_fight_x_ + kEnemyFightWidth + kCritMsgXAdj,
                        kEnemyFightY + kEnemyFightHeight * kCritMsgYAdjFactor);
        is_player_atk_turn_ = !is_player_atk_turn_;
    } else if (!is_player_atk_turn_ && turns_fought_ > 0) {
        if (atk_sound_enabled_) {
            atk_sound_player->play();
        }
        ofDrawLine(kPlayerFightX + kEnemyAtkXAdj, kPlayerFightY + kEnemyAtkYAdj,
                   kPlayerFightX + kPlayerFightWidth + kEnemyAtkXAdj,
                   kPlayerFightY + kPlayerFightHeight + kEnemyAtkYAdj);
        info_font->draw(crit_message,
                        kPlayerFightX + kPlayerFightWidth + kCritMsgXAdj,
                        kEnemyFightY + kEnemyFightHeight * kCritMsgYAdjFactor);
        is_player_atk_turn_ = !is_player_atk_turn_;
    }
}
//--------------------------------------------------------------
void ofApp::drawBattleInfo() {
    ofSetColor(kWhite);
    string player_hp = to_string(max(player.getHealth(), 0));
    string enemy_hp = to_string(max(enemy.getHealth(), 0));
    string player_hp_message = kHpLabel + player_hp;
    string enemy_hp_message = kHpLabel + enemy_hp;
    info_font->draw(player_hp_message, 
		            kPlayerFightX + kPlayerHpMsgXAdj,
                    kPlayerFightY + kPlayerHpMsgYAdj);
    info_font->draw(enemy_hp_message, 
		            enemy_fight_x_ + kEnemyHpMsgXAdj,
                    kEnemyFightY + kEnemyHpMsgYAdj);
    if (enemy.getHealth() <= 0) {
        drawWinBattleInfo();
    }
}

//--------------------------------------------------------------
void ofApp::drawWinBattleInfo() {
    string enemy_gold = to_string(enemy.getGold());
    string enemy_exp = to_string(enemy.getExp());
    string gold_message = kGetRewardMsg + enemy_gold + kGetGoldMsg;
    string exp_message = kGetRewardMsg + enemy_exp + kGetExpMsg;
    info_font->draw(gold_message, ofGetWindowWidth() * kCenterXFactor,
                    ofGetWindowHeight() - kGoldMsgYAdjFactor * kInfoFontSize);
    info_font->draw(exp_message, ofGetWindowWidth() * kCenterYFactor,
                    ofGetWindowHeight() - kInfoFontSize);
}

//--------------------------------------------------------------
void ofApp::drawInfo() {
    ofSetColor(0, 0, 0);
    string gold_gathered = to_string(player.getGold());
    string gold_message = kGoldLabel + gold_gathered;
    string exp_gathered = to_string(player.getExp());
    string exp_message = kExpLabel + exp_gathered;
    string energy_left = to_string(energy_left_);
    string energy_message = kEnergyLabel + energy_left;
    string stage_num = to_string(stage_num_);
    string stage_message = kStageLabel + stage_num;
    string level = to_string(player.getLvl());
    string lvl_message = kLvlLabel + level;
    string battle_chance =
        to_string(max((int)(battle_chance_ * battle_multiplier_), 0));
    string battle_message = kBattleChanceLabel + battle_chance + kPercentString;
    info_font->draw(gold_message, 0, kInfoFontSize);
    info_font->draw(exp_message, 0, kExpMsgYFactor * kInfoFontSize);
    info_font->draw(lvl_message, 0, kLvlMsgYFactor * kInfoFontSize);
    info_font->draw(stage_message, ofGetWindowWidth() * kCenterXFactor,
                    ofGetWindowHeight() * kCenterYFactor);
    info_font->draw(battle_message, ofGetWindowWidth() * kCenterXFactor,
                    kInfoFontSize);
    // puts energy_message in top right corner
    info_font->draw(energy_message,
                    ofGetWindowWidth() - kEnergyMsgYFactor * kInfoFontSize,
                    kInfoFontSize);
}
//--------------------------------------------------------------
void ofApp::drawPlayer() {
    ofSetColor(kSkin);
    // makes the boundaries of the sprite line up with the hitbox
    // discovered through trial and error
    player.player_sprite->draw(player.getPos().x + kPlayerSpritePosAdj,
                               player.getPos().y + kPlayerSpritePosAdj,
                               kPlayerSpriteWidth, kPlayerSpriteHeight);
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
    for (auto& button : buttons) {
        if (button->mouseIsInside(x, y)) {
            button->getFuncWhenPressed()();
            break;
        }
    }
    if (inventory_is_open_ || store_is_open_) {
        for (auto& item : items) {
            Button item_buttons[kItemButtonsOnScreen];
            if (inventory_is_open_) {
                item_buttons[0] = item->inv_buttons_[0];
                item_buttons[1] = item->inv_buttons_[1];
            } else {
                item_buttons[0] = item->store_buttons_[0];
                item_buttons[1] = item->store_buttons_[1];
            }
            if (checkIfItemEquipped(item)) {
                item_buttons[1] = item->store_buttons_[2];
            }
            for (auto& item_button : item_buttons) {
                if (item_button.mouseIsInside(x, y)) {
                    item_button.getFuncWhenPressed()();
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
        return player.equipped_weapon_ == item_weapon;
    }
    if (item_armor) {
        return player.equipped_armor_ == item_armor;
    }
    if (item) {
        return player.equipped_misc_ == item;
    }
    return false;
}

//--------------------------------------------------------------
void ofApp::buyItem(Item* item) {
    if (item->price_ > player.getGold()) {
        not_enough_gold_ = true;
        return;
    }
    if (checkIfItemInInventory(item)) {
        item_already_owned_ = true;
        return;
    }
    purchase_made_ = true;
    player.gold -= item->price_;
    player.inventory.push_back(item);
}

//--------------------------------------------------------------
void ofApp::sellItem(Item* item) {
    unequipItem(item);
    sale_made_ = true;
    player.gold += (item->price_ * gold_mult_);
    player.inventory.remove(item);
}

//--------------------------------------------------------------
void ofApp::unequipItem(Item* item) {
    if (!item) {
        return;
    }
    Weapon* item_weapon = dynamic_cast<Weapon*>(item);
    Armor* item_armor = dynamic_cast<Armor*>(item);
    if (item_weapon) {
        if (player.equipped_weapon_ == item_weapon) {
            player.atk -= player.equipped_weapon_->getAtkBoost();
            player.equipped_weapon_ = nullptr;
        }
    } else if (item_armor) {
        if (player.equipped_armor_ == item_armor) {
            player.def -= player.equipped_armor_->getDefBoost();
            player.max_health_ -= player.equipped_armor_->getHpBoost();
            player.health = player.max_health_;
            player.equipped_armor_ = nullptr;
        }
    } else {
        if (player.equipped_misc_ == item) {
            item->getFuncWhenUnequipped()();
            player.equipped_misc_ = nullptr;
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
        unequipItem(player.equipped_weapon_);
        player.equipped_weapon_ = item_weapon;
        player.atk += player.equipped_weapon_->getAtkBoost();
    } else if (item_armor) {
        unequipItem(player.equipped_armor_);
        player.equipped_armor_ = item_armor;
        player.def += player.equipped_armor_->getDefBoost();
        player.max_health_ += player.equipped_armor_->getHpBoost();
        player.health = player.max_health_;
    } else {
        unequipItem(player.equipped_misc_);
        player.equipped_misc_ = item;
        item->getFuncWhenEquipped()();
    }
    equip_success_ = true;
}

//--------------------------------------------------------------
bool ofApp::checkIfItemInInventory(Item* item) {
    bool item_is_found = false;
    for (auto& item2 : player.inventory) {
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
    buttons.clear();
    buttons.push_back(play_button);
    buttons.push_back(settings_button);
}

//--------------------------------------------------------------
void ofApp::resetPlayer() {
    auto tmp_player_weapon = player.equipped_weapon_;
    auto tmp_player_armor = player.equipped_armor_;
    auto tmp_player_misc = player.equipped_misc_;
    auto tmp_inventory = player.inventory;
    if (player.equipped_misc_) {
        player.equipped_misc_->getFuncWhenUnequipped()();
    }
    player = Player(kStartX, kStartY, kStartGold, kStartExp, kStartAtk,
                    kStartDef, kStartHealth, kStartCrit);
    player.player_sprite->load(kPlayerSpritePath);
    player.inventory = tmp_inventory;
    player.equipped_weapon_ = tmp_player_weapon;
    player.equipped_armor_ = tmp_player_armor;
    player.equipped_misc_ = tmp_player_misc;
    if (player.equipped_weapon_ != nullptr) {
        player.atk += player.equipped_weapon_->getAtkBoost();
    }
    if (player.equipped_armor_ != nullptr) {
        player.def += player.equipped_armor_->getDefBoost();
        player.max_health_ += player.equipped_armor_->getHpBoost();
        player.health = player.max_health_;
    }
    if (player.equipped_misc_) {
        player.equipped_misc_->getFuncWhenEquipped()();
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
    buttons.remove(inventory_button);
    buttons.push_back(back_button);
    buttons.push_back(next_button);
}

//-------------------------------------------------------------
void ofApp::closeInventory() {
    page_num_ = 0;
    inventory_is_open_ = false;
    buttons.remove(back_button);
    buttons.remove(next_button);
    buttons.remove(prev_button);
    buttons.push_back(inventory_button);
}

//-------------------------------------------------------------
void ofApp::drawInventory() {
    if (should_delay_) {
        Sleep(kMessageDelay);
        should_delay_ = false;
    }
    ofBackground(kTan);
    for (auto& item : player.inventory) {
        if (page_num_ != item->page_) {
            continue;
        }
        ofSetColor(kBlack);
        info_font->draw(item->getName(), 
			            item->pos_.x,
                        item->pos_.y - kItemNameYFactor * kInfoFontSize);
        string equipped_status = kUnequippedMsg;
        if (checkIfItemEquipped(item)) {
            equipped_status = kEquippedMsg;
            item->unequip_button->draw();
        } else {
            item->equip_button->draw();
        }
        info_font->draw(equipped_status, 
			            item->pos_.x + kEquippedXAdj,
                        item->pos_.y - kInfoFontSize * kEquippedYFactor);
        ofDrawRectangle(item->pos_, item->kWidth, item->kHeight);
        item->sell_button->draw();
    };
    drawInventoryNotices();
}

//--------------------------------------------------------------
void ofApp::drawInventoryNotices() {
    ofSetColor(kWhite);
    if (sale_made_) {
        info_font->draw(kSaleMadeMsg, 
			            ofGetWindowWidth() * kCenterYFactor,
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
        buttons.push_back(prev_button);
    } else if (page_num_ == kMaxPageNum) {
        buttons.remove(next_button);
    }
}

//--------------------------------------------------------------
void ofApp::decreasePage() {
    page_num_ = max(--page_num_, 0);
    if (page_num_ == 0) {
        buttons.remove(prev_button);
    } else if (page_num_ == kMaxPageNum - 1) {
        buttons.push_back(next_button);
    }
}

//--------------------------------------------------------------
void ofApp::openStore() {
    ofSetWindowTitle(kStoreLabel);
    for (int dir = UP; dir <= RIGHT; dir++) {
        move_key_is_pressed[dir] = false;
    }
    store_is_open_ = true;
    buttons.remove(store_button);
    buttons.remove(restart_button);
    buttons.push_back(back_button);
    buttons.push_back(next_button);
}

//-------------------------------------------------------------
void ofApp::closeStore() {
    page_num_ = 0;
    store_is_open_ = false;
    buttons.remove(back_button);
    buttons.remove(next_button);
    buttons.remove(prev_button);
    buttons.push_back(restart_button);
    buttons.push_back(store_button);
}

//-------------------------------------------------------------
void ofApp::drawStore() {
    if (should_delay_) {
        Sleep(kMessageDelay);
        should_delay_ = false;
    }
    ofBackground(kTan);
    ofSetColor(kBlack);
    for (auto& item : items) {
        if (page_num_ != item->page_) {
            continue;
        }
        info_font->draw(item->getName(), 
			            item->pos_.x,
                        item->pos_.y - kItemNameYFactor * kInfoFontSize);
        string price = to_string(item->getPrice());
        info_font->draw(kPriceLabel + price, 
			            item->pos_.x + kPriceXAdj,
                        item->pos_.y - kInfoFontSize * kPriceYFactor);
        ofDrawRectangle(item->pos_, item->kWidth, item->kHeight);
        item->buy_button->draw();
        if (!checkIfItemEquipped(item)) {
            item->equip_button->draw();
        } else {
            item->unequip_button->draw();
        }
    };
    string gold = to_string(player.getGold());
    info_font->draw(kGoldLabel + gold, 
		            ofGetWindowWidth() * kStoreGoldXFactor,
                    kInfoFontSize);
    ofSetColor(kWhite);
    drawStoreNotices();
}

//--------------------------------------------------------------
void ofApp::drawStoreNotices() {
    if (purchase_made_) {
        info_font->draw(kPurchaseMadeMsg, 
			            ofGetWindowWidth() * kCenterXFactor,
                        ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        purchase_made_ = false;
    } else if (not_enough_gold_) {
        info_font->draw(kNotEnoughGoldMsg, 
			            ofGetWindowWidth() * kCenterXFactor,
                        ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        not_enough_gold_ = false;
    } else if (item_already_owned_) {
        info_font->draw(kAlreadyOwnedMsg, 
			            ofGetWindowWidth() * kCenterXFactor,
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
        info_font->draw(kNoOwnMsg, 
			            ofGetWindowWidth() * kCenterXFactor,
                        ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        tried_equip_not_own_ = false;
    } else if (already_equipped_) {
        info_font->draw(kAlreadyEquippedMsg,
                        ofGetWindowWidth() * kCenterXFactor,
                        ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        already_equipped_ = false;
    } else if (equip_success_) {
        info_font->draw(kEquipSuccessMsg, 
			            ofGetWindowWidth() * kCenterXFactor,
                        ofGetWindowHeight() * kCenterYFactor);
        should_delay_ = true;
        equip_success_ = false;
    }
}

//-------------------------------------------------------------
void ofApp::openSettings() {
    ofSetWindowTitle(kSettingsLabel);
    settings_is_open_ = true;
    buttons.remove(play_button);
    buttons.remove(settings_button);
    buttons.push_back(back_button);
    buttons.push_back(toggle_bkgrd_music_button);
    buttons.push_back(toggle_atk_sound_button);
    buttons.push_back(toggle_battle_music_button);
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
    settings_is_open_ = false;
    buttons.push_back(play_button);
    buttons.push_back(settings_button);
    buttons.remove(back_button);
    buttons.remove(toggle_bkgrd_music_button);
    buttons.remove(toggle_atk_sound_button);
    buttons.remove(toggle_battle_music_button);
}

//-------------------------------------------------------------
void ofApp::drawSettings() {
    ofSetColor(kBlack);
    drawToggleMessage(toggle_bkgrd_music_button, kBkgrdMusicEnabledMsg);
    drawToggleMessage(toggle_atk_sound_button, kAtkSoundEnabledMsg);
    drawToggleMessage(toggle_battle_music_button, kBattleMusicEnabledMsg);
    if (background_music_enabled_) {
        drawXOnButton(toggle_bkgrd_music_button);
    }
    if (battle_music_enabled_) {
        drawXOnButton(toggle_battle_music_button);
    }
    if (atk_sound_enabled_) {
        drawXOnButton(toggle_atk_sound_button);
    }
}

//-------------------------------------------------------------
void ofApp::drawToggleMessage(Button* button, string message) {
    info_font->draw(
        message, (button->x + button->width) + kToggleMsgXAdj,
        ((button->y + button->height * kToggleMsgYFactor) + kToggleMsgYAdj));
}

//-------------------------------------------------------------
void ofApp::drawXOnButton(Button* button) {
    ofDrawLine(button->x, button->y, 
		       button->x + button->width,
               button->y + button->height);
    ofDrawLine(button->x + button->width, 
		       button->y, 
		       button->x,
               button->y + button->height);
}

//-------------------------------------------------------------
void ofApp::exit() {
    deleteButtons();
    deleteItems();
    delete (background_music_player);
    delete (atk_sound_player);
    delete (battle_music_player);
    delete (player.player_sprite);
}