#pragma once
#include "ofMain.h"

// taken from serious-snakes-amorris6
typedef enum { UP = 0, DOWN, LEFT, RIGHT } PlayerDirection;

class Player {
   private:
    ofVec2f position;
    const static int kMoveSpeed = 5;
    // verifies that player can move in direction of keyPressed
    // helper function of moveInDirection
    bool canMoveInDirection(PlayerDirection direction);

   public:
    const static int kPlayerWidth = 20;
    const static int kPlayerHeight = 20;
    friend void moveInDirection(Player &player, int direction_index);
    ofVec2f getPos();
};
