#pragma once
#include "Armor.h"
#include "Character.h"
#include "Weapon.h"

// taken from serious-snakes-amorris6
typedef enum { UP = 0, DOWN, LEFT, RIGHT } PlayerDirection;

class Player : public Character {
   private:
    friend class ofApp;
    // verifies that player can move in direction of keyPressed
    // helper function of moveInDirection
    bool canMoveInDirection(PlayerDirection direction);
    int kMoveSideSpeed;
    int kMoveUpSpeed;
    int lvl;
    int max_health_;
    // have to use ptrs for dynamic casting
    Weapon* equipped_weapon_;
    Armor* equipped_armor_;
    Item* equipped_misc_;
    list<Item*> inventory;

   public:
    ofRectangle getRect();
    int getLvl();
    ofImage* player_sprite;
    void moveInDirection(int direction_index);
    Player(float x, float y, int gold, int exp, int atk, int def, int health,
           int crit_chance)
        : Character(x, y, gold, exp, atk, def, health, crit_chance) {
        lvl = 0;
        max_health_ = health;
        equipped_weapon_ = nullptr;
        equipped_armor_ = nullptr;
        player_sprite = new ofImage();
    }
    Player() : Player(0, 0, 0, 0, 0, 0, 0, 0) {}
};