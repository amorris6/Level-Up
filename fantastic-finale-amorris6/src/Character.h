#pragma once
#include "ofMain.h"

// taken from serious-snakes-amorris6
typedef enum { UP = 0, DOWN, LEFT, RIGHT } PlayerDirection;

class Character {
   private:
    ofVec2f position;
    const static int kMoveSpeed = 5;
    // verifies that player can move in direction of keyPressed
    // helper function of moveInDirection
    bool canMoveInDirection(PlayerDirection direction);

   public:
    int gold;
    const static int kPlayerWidth = 20;
    const static int kPlayerHeight = 20;
    friend void moveInDirection(Character& player, int direction_index);
    ofVec2f getPos();
    ofRectangle getRect();
    int getGold();
    Character(float x, float y, int input_gold) {
        position.set(x, y);
        gold = input_gold;
        input_gold++;
    }
    Character(float x, float y) { 
		Character(x, y, 0); 
	}
    Character() { 
		Character(0, 0, 0); 
	}
    bool operator==(Character const& other) const;
    bool operator!=(Character const& other) const;
};
