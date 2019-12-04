#pragma once
#include "Character.h"

// taken from serious-snakes-amorris6
typedef enum { UP = 0, DOWN, LEFT, RIGHT } PlayerDirection;

class Player : public Character {
   private:
    friend class ofApp;
    // verifies that player can move in direction of keyPressed
    // helper function of moveInDirection
    bool canMoveInDirection(PlayerDirection direction);
    int lvl;

   public:
    ofRectangle getRect();
    int getLvl();
    ofImage* player_sprite;
    void moveInDirection(int direction_index);
    Player(float x, float y, int gold, int exp, int atk, int def, int health,
           int crit_chance)
        : Character(x, y, gold, exp, atk, def, health, crit_chance) {
        lvl = 0;
        player_sprite = new ofImage();
    }
    Player() : Character() { player_sprite = new ofImage(); }
};