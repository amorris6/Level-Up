#pragma once
#include "Item.h"

class Armor : public Item {
   private:
    int def_boost_;
    int health_boost_;

   public:
    Armor(string name, 
		  int price, 
		  int page,
          float store_pos_x, 
		  float store_pos_y, 
		  int def_boost,
          int health_boost, 
		  shared_ptr<ofxSmartFont> button_font)
        : Item(name, 
			   price, 
			   page, 
			   store_pos_x, store_pos_y,
               button_font) {
        def_boost_ = def_boost;
        health_boost_ = health_boost;
    }
    Armor(string name, 
		  int price, 
		  int page,
          ofVec2f store_pos, 
		  int def_boost,
          int health_boost, 
		  shared_ptr<ofxSmartFont> button_font)
        : Item(name, 
			   price, 
			   page, 
			   store_pos,
               button_font) {
        def_boost_ = def_boost;
        health_boost_ = health_boost;
    }
    Armor() : Item() {}

    int getDefBoost();
    int getHpBoost();
};
