#pragma once
#include "ofMain.h"

class Character {
   protected:
    ofVec2f position_;
    int gold_;
    int exp_;
    int atk_;
    int def_;
    int health_;
    float crit_chance_;

   public:
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

    Character(float x, float y, 
		      int gold, 
		      int exp, 
		      int atk, 
		      int def, 
		      int health,
              int crit_chance)
        : position_(x, y),
          gold_(gold),
          exp_(exp),
          atk_(atk),
          def_(def),
          health_(health),
          crit_chance_(crit_chance) {}
    Character() : Character(0, 0, 0, 0, 0, 0, 0, 0) {}

    bool operator==(Character const& other) const;
    bool operator!=(Character const& other) const;
    friend class ofApp;
};