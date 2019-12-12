#include "Button.h"
#include "Enemy.h"
#include "Player.h"
#include "ofxSmartFont.h"
class Test {
   public:
    static void dummyFunc();
};

void Test::dummyFunc() {}

int main() {
    // setup
    const static int kWindowWidth = 1025;
    const static int kWindowHeight = 480;
    ofSetupOpenGL(kWindowWidth, kWindowHeight, OF_WINDOW);
    const static int kStartGold = 50;
    const static int kStartExp = 20;
    const static int kStartAtk = 10;
    const static int kStartDef = 30;
    const static int kStartHealth = 40;
    const static int kStartCritChance = 5;
    Player player = Player(0, 0, kStartGold, kStartExp, kStartAtk, kStartDef,
                           kStartHealth, kStartCritChance);
	//distance player moves horizontally and vertically
	//in a window of size (kWindowWidth, kWindowHeight)
    const static int kMoveDist = 5;

    // player movement tests

    // Player Can Move Down (TEST 1)
    player.moveInDirection(DOWN);
    if (player.getPos().x == 0 && player.getPos().y == kMoveDist) {
        cout << "TEST 1 PASSED" << endl;
    } else {
        cout << "TEST 1 FAILED" << endl;
    }

    // Player Can Move Right (TEST 2)
    player.moveInDirection(RIGHT);
    if (player.getPos().x == kMoveDist &&
        player.getPos().y == kMoveDist) {
        cout << "TEST 2 PASSED" << endl;
    } else {
        cout << "TEST 2 FAILED" << endl;
    }

    // Player Can Move Up (TEST 3)
    player.moveInDirection(UP);
    if (player.getPos().x == kMoveDist && player.getPos().y == 0) {
        cout << "TEST 3 PASSED" << endl;
    } else {
        cout << "TEST 3 FAILED" << endl;
    }

    // Player Can Move Left (TEST 4)
    player.moveInDirection(LEFT);
    if (player.getPos().x == 0 && player.getPos().y == 0) {
        cout << "TEST 4 PASSED" << endl;
    } else {
        cout << "TEST 4 FAILED" << endl;
    }

    // Player Can Exit Window Up (TEST 5)
    player.moveInDirection(UP);
    if (player.getPos().x == 0 && player.getPos().y == ofGetWindowHeight()) {
        cout << "TEST 5 PASSED" << endl;
    } else {
        cout << "TEST 5 FAILED" << endl;
    }

    // Player Can't Exit Window Left (TEST 6)
    player.moveInDirection(LEFT);
    if (player.getPos().x == 0 && player.getPos().y == ofGetWindowHeight()) {
        cout << "TEST 6 PASSED" << endl;
    } else {
        cout << "TEST 6 FAILED" << endl;
    }

    // Player Can leave Scene Right (TEST 7)
    for (int i = 0; i < 250; ++i) {
        player.moveInDirection(RIGHT);
        if (player.getPos().x > ofGetWindowWidth() - (Character::kCharWidth + kMoveDist)) {
            player.moveInDirection(RIGHT);
            break;
        }
    }
    if (player.getPos().x == 0 && player.getPos().y == ofGetWindowHeight()) {
        cout << "TEST 7 PASSED" << endl;
    } else {
        cout << "TEST 7 FAILED" << endl;
    }

    // Player Can't Exit Window Down (TEST 8)
    for (int i = 0; i < 250; ++i) {
        player.moveInDirection(DOWN);
    }
    if (player.getPos().x == 0 &&
        player.getPos().y == ofGetWindowHeight() - Character::kCharHeight) {
        cout << "TEST 8 PASSED" << endl;
    } else {
        cout << "TEST 8 FAILED" << endl;
    }

    // Constructor/getter tests

    // getGold() gets gold (TEST 9)
    if (player.getGold() == kStartGold) {
        cout << "TEST 9 PASSED" << endl;
    } else {
        cout << "TEST 9 FAILED" << endl;
    }

    // getExp() gets exp (TEST 10)
    if (player.getExp() == kStartExp) {
        cout << "TEST 10 PASSED" << endl;
    } else {
        cout << "TEST 10 FAILED" << endl;
    }

    // getAtk() gets atk (TEST 11)
    if (player.getAtk() == kStartAtk) {
        cout << "TEST 11 PASSED" << endl;
    } else {
        cout << "TEST 11 FAILED" << endl;
    }

    // getDef() gets def (TEST 12)
    if (player.getDef() == kStartDef) {
        cout << "TEST 12 PASSED" << endl;
    } else {
        cout << "TEST 12 FAILED" << endl;
    }

    // getHealth() gets health (TEST 13)
    if (player.getHealth() == kStartHealth) {
        cout << "TEST 13 PASSED" << endl;
    } else {
        cout << "TEST 13 FAILED" << endl;
    }

    // getCrit() gets crit_chance (TEST 14)
    if (player.getCrit() == kStartCritChance) {
        cout << "TEST 14 PASSED" << endl;
    } else {
        cout << "TEST 14 FAILED" << endl;
    }

    // getRect() gets player.rect (TEST 15)
    if (player.getRect().getX() == player.getPos().x &&
        player.getRect().getY() == player.getPos().y &&
        player.getRect().getWidth() ==
            Character::kCharWidth / 2  // so the sprite takes up whole width
        && player.getRect().getHeight() == Character::kCharHeight) {
        cout << "TEST 15 PASSED" << endl;
    } else {
        cout << "TEST 15 FAILED" << endl;
    }

    // Button tests setup
    const static int kStartX = 0;
    const static int kStartY = 0;
    const static int kWidth = 20;
    const static int kHeight = 20;
    const static string kLabel = "LABEL";
    const string kFontFilePath = "C:\\CS 126\\Fonts\\Roboto-Black.ttf";
    const string kFontName = "Roboto-Black";
    ofxSmartFont::add(kFontFilePath, Button::kButtonFontSize, kFontName);
    shared_ptr<ofxSmartFont> kFont = ofxSmartFont::get(kFontName);
    Button button =
        Button(kStartX, kStartY, kWidth, kHeight, kLabel, kFont, Test::dummyFunc);

    // mouseIsInside outputs true if
    // (x, y) is inside (TEST 16)
    if (button.mouseIsInside((kStartX + kWidth) / 2, (kStartY + kHeight) / 2)) {
        cout << "TEST 16 PASSED" << endl;
    } else {
        cout << "TEST 16 FAILED" << endl;
    }

    // item and subclass test setup
    string kGemName = "gem";
    int kGemPrice = 300;
    float kGemPosX = 400;
    float kGemPosY = 100;
    string kSwordName = "sword";
    int kSwordPrice = 300;
    float kSwordPosX = 100;
    float kSwordPosY = 100;
    int kSwordAtkBoost = 4000;
    string kHelmetName = "helmet";
    int kHelmetPrice = 300;
    float kHelmetPosX = 250;
    float kHelmetPosY = 100;
    int kHelmetDefBoost = 2000;
    int kHelmetHpBoost = 3000;
    Item gem = Item(kGemName, kGemPrice, 0, kGemPosX, kGemPosY, Test::dummyFunc,
                    Test::dummyFunc, kFont);
    Weapon sword = Weapon(kSwordName, kSwordPrice, 0, kSwordPosX, kSwordPosY,
                          kSwordAtkBoost, kFont);
    Armor helmet = Armor(kHelmetName, kHelmetPrice, 0, kHelmetPosX, kHelmetPosY,
                         kHelmetDefBoost, kHelmetHpBoost, kFont);

	//getters work correctly (TESTS 17-21)
    if (gem.getName() == kGemName) {
        cout << "TEST 17 PASSED" << endl;
    } else {
        cout << "TEST 17 FAILED" << endl;
    }

	if (gem.getPrice() == kGemPrice) {
        cout << "TEST 18 PASSED" << endl;
    } else {
        cout << "TEST 18 FAILED" << endl;
    }

	if (sword.getAtkBoost() == kSwordAtkBoost) {
        cout << "TEST 19 PASSED" << endl;
    } else {
        cout << "TEST 19 FAILED" << endl;
    }

	if (helmet.getDefBoost() == kHelmetDefBoost) {
        cout << "TEST 20 PASSED" << endl;
    } else {
        cout << "TEST 20 FAILED" << endl;
    }

	if (helmet.getHpBoost() == kHelmetHpBoost) {
        cout << "TEST 21 PASSED" << endl;
    } else {
        cout << "TEST 21 FAILED" << endl;
    }
}