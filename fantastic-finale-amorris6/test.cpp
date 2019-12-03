#include "Enemy.h"
#include "Player.h"
#include "ofxUnitTests.h"

int main() {
    // setup
    ofSetupOpenGL(1025, 480, OF_WINDOW);
    int init_gold = 50;
    int init_exp = 20;
    int init_atk = 10;
    int init_def = 30;
    int init_health = 40;
    int init_crit_chance = 5;
    Player player = Player(0, 0, init_gold, init_exp, init_atk, init_def,
                           init_health, init_crit_chance);

    // player movement tests

    // Player Can Move Down (TEST 1)
    player.moveInDirection(DOWN);
    if (player.getPos().x == 0 && player.getPos().y == player.kMoveSpeed) {
        cout << "TEST 1 PASSED" << endl;
    } else {
        cout << "TEST 1 FAILED" << endl;
    }

    // Player Can Move Right (TEST 2)
    player.moveInDirection(RIGHT);
    if (player.getPos().x == player.kMoveSpeed &&
        player.getPos().y == player.kMoveSpeed) {
        cout << "TEST 2 PASSED" << endl;
    } else {
        cout << "TEST 2 FAILED" << endl;
    }

    // Player Can Move Up (TEST 3)
    player.moveInDirection(UP);
    if (player.getPos().x == player.kMoveSpeed && player.getPos().y == 0) {
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

    // Player Can't Exit Window Up (TEST 5)
    player.moveInDirection(UP);
    if (player.getPos().x == 0 && player.getPos().y == 0) {
        cout << "TEST 5 PASSED" << endl;
    } else {
        cout << "TEST 5 FAILED" << endl;
    }

    // Player Can't Exit Window Left (TEST 6)
    player.moveInDirection(LEFT);
    if (player.getPos().x == 0 && player.getPos().y == 0) {
        cout << "TEST 6 PASSED" << endl;
    } else {
        cout << "TEST 6 FAILED" << endl;
    }

    // Player Can leave Scene Right (TEST 7)
    for (int i = 0; i < 250; ++i) {
        player.moveInDirection(RIGHT);
        if (player.getPos().x > ofGetWindowWidth() - (Character::kCharWidth +
                                                      Character::kMoveSpeed)) {
            player.moveInDirection(RIGHT);
            break;
        }
    }
    if (player.getPos().x == 0 && player.getPos().y == 0) {
        cout << "TEST 7 PASSED" << endl;
    } else {
        cout << "TEST 7 FAILED" << endl;
        cout << player.getPos().x << endl;
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
    if (player.getGold() == init_gold) {
        cout << "TEST 9 PASSED" << endl;
    } else {
        cout << "TEST 9 FAILED" << endl;
    }

    // getExp() gets exp (TEST 10)
    if (player.getExp() == init_exp) {
        cout << "TEST 10 PASSED" << endl;
    } else {
        cout << "TEST 10 FAILED" << endl;
    }

    // getAtk() gets atk (TEST 11)
    if (player.getAtk() == init_atk) {
        cout << "TEST 11 PASSED" << endl;
    } else {
        cout << "TEST 11 FAILED" << endl;
    }

    // getDef() gets def (TEST 12)
    if (player.getDef() == init_def) {
        cout << "TEST 12 PASSED" << endl;
    } else {
        cout << "TEST 12 FAILED" << endl;
    }

    // getHealth() gets health (TEST 13)
    if (player.getHealth() == init_health) {
        cout << "TEST 13 PASSED" << endl;
    } else {
        cout << "TEST 13 FAILED" << endl;
    }

    // getCrit() gets crit_chance (TEST 14)
    if (player.getCrit() == init_crit_chance) {
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
}