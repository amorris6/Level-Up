#pragma once
#include "Item.h"

class Weapon : public Item {
   private:
    int atk_boost_;

   public:
    Weapon(string name, int price, int store_page, int inv_page,
           float store_pos_x, float store_pos_y, float inv_pos_x,
           float inv_pos_y, int atk_boost, shared_ptr<ofxSmartFont> button_font)
        : Item(name, price, store_page, inv_page, store_pos_x, store_pos_y,
               inv_pos_x, inv_pos_y, button_font) {
        atk_boost_ = atk_boost;
    }
    Weapon(string name, int price, int store_page, int inv_page,
           ofVec2f store_pos, ofVec2f inv_pos,
           int atk_boost,
           shared_ptr<ofxSmartFont> button_font)
        : Item(name, price, store_page, inv_page, store_pos, inv_pos,
               button_font) {
        atk_boost_ = atk_boost;
    }

    Weapon() : Item() {}

    int getAtkBoost();
};
