#include "ofMain.h"
#pragma once

// taken from serious-snakes-amorris6
typedef enum { UP = 0, DOWN, RIGHT, LEFT } PlayerDirection;

class Player {
   private:
    ofVec2f position;
    const static int kMoveSpeed = 5;
    const static int kPlayerWidth = 20;
    const static int kPlayerHeight = 20;

   public:
    friend void MoveInDirection(Player player, PlayerDirection direction);
};
