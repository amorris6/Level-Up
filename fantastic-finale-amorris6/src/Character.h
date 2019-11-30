#pragma once
#include "ofMain.h"

class Character {
   protected:
    ofVec2f position;
    int gold;
    
   public:
    const static int kMoveSpeed = 5;
    const static int kCharWidth = 20;
    const static int kCharHeight = 20;
    ofVec2f getPos();
    ofRectangle getRect();
    int getGold();
    Character(float x, float y, int input_gold) {
        position.set(x, y);
        gold = input_gold;
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
