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
    int gold;
    friend void moveInDirection(Player& player, int direction_index);
    Player(float x, float y, int gold) : Character(x, y, gold) {
        this->gold = gold;
    }
    Player(float x, float y) : Character(x, y) { 
		Player(x, y, 0); 
	}
    Player() : Character() { 
		Player(0, 0, 0);
	}

    int getGold();
};