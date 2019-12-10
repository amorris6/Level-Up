#pragma once
#include "Character.h"

class Enemy : public Character {
   private:
   public:
    Enemy(float x, float y, 
		  int gold, 
		  int exp, 
		  int atk, 
		  int def, 
		  int health,
          int crit_chance)
        : Character(x, y, gold, exp, atk, def, health, crit_chance) {}
    Enemy() : Character() {}
};
