#pragma once
#include "Item.h"

class Armor : public Item {
   private:
    int def_boost_;
    int health_boost_;

   public:
    Armor(std::string name, int price, int store_page, int inv_page,
          float store_pos_x, float store_pos_y, float inv_pos_x,
          float inv_pos_y, shared_ptr<ofxSmartFont> button_font, int def_boost,
          int health_boost)
        : Item(name, price, store_page, inv_page, store_pos_x, store_pos_y,
               inv_pos_x, inv_pos_y, button_font) {
        def_boost_ = def_boost;
        health_boost_ = health_boost;
    }
    Armor(string name, int price, int store_page, int inv_page,
          ofVec2f store_pos, ofVec2f inv_pos,
          shared_ptr<ofxSmartFont> button_font, int def_boost, int health_boost)
        : Item(name, price, store_page, inv_page, store_pos, inv_pos,
               button_font) {
        def_boost_ = def_boost;
        health_boost_ = health_boost;
    }

    Armor() : Item() {}
    int getDefBoost();
    int getHpBoost();
};
