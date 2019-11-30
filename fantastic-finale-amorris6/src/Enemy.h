#pragma once
#include "Character.h"

class Enemy : public Character {
   private:
   public:
    Enemy(float x, float y, int gold) : Character(x, y, gold) {}
    Enemy(float x, float y) : Character(x, y) {}
    Enemy() : Character() {}
};
