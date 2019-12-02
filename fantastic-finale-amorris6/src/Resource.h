#pragma once
#include "Character.h"
class Resource : public Character {
   public:
    Resource(float x, float y, int gold, int exp)
        : Character(x, y, gold, exp, 0, 0, 0, 0) {}
};
