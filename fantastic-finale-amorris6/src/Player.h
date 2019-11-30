#pragma once
#include "Character.h"

// taken from serious-snakes-amorris6
typedef enum { UP = 0, DOWN, LEFT, RIGHT } PlayerDirection;

class Player : public Character {
   private:
    // verifies that player can move in direction of keyPressed
    // helper function of moveInDirection
    bool canMoveInDirection(PlayerDirection direction);

   public:
    ofRectangle getRect();
    ofImage* player_sprite;
    friend void moveInDirection(Player& player, int direction_index);
    Player(float x, float y, int gold, int exp, int atk, int def, int health,
           float crit_chance)
        : Character(x, y, gold, exp, atk, def, health, crit_chance) {
        player_sprite = new ofImage();
    }
    Player() : Character() { player_sprite = new ofImage(); }
};