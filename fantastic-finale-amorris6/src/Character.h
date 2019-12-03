#pragma once
#include "ofMain.h"

class Character {
   protected:
    ofVec2f position;
    int gold;
    int exp;
    int atk;
    int def;
    int health;
    float crit_chance;

   public:
    const static int kMoveSpeed = 5;
    const static int kCharWidth = 20;
    const static int kCharHeight = 20;

    ofVec2f getPos();
    int getGold();
    int getExp();
    int getAtk();
    int getDef();
    int getHealth();
    float getCrit();
    ofRectangle getRect();

    Character(float x, float y, int gold, int exp, int atk, int def, int health,
              int crit_chance)
        : position(x, y),
          gold(gold),
          exp(exp),
          atk(atk),
          def(def),
          health(health),
          crit_chance(crit_chance) {}
    Character() { Character(0, 0, 0, 0, 0, 0, 0, 0); }
    bool operator==(Character const& other) const;
    bool operator!=(Character const& other) const;
    friend class ofApp;
};