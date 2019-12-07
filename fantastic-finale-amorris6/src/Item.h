#pragma once
#include "Button.h"
#include "ofxSmartFont.h"

class Item {
   private:
    const static int kWidth = 50;
    const static int kHeight = 50;
    const static int kBuyXAdj = 50;
    const static int kBuyYAdj = 50;
    const static int kSellXAdj = 50;
    const static int kSellYAdj = 50;
    const static int kEquipXAdj = -50;
    const static int kEquipYAdj = 50;
    friend class ofApp;
    int price_;
    static bool wants_to_buy_;
    static bool wants_to_sell_;
    static bool wants_to_equip_;
    string name_;
    ofVec2f store_pos_;
    ofVec2f inv_pos_;
    Button* buy_button;
    Button* sell_button;
    Button* store_equip_button;
    Button* inv_equip_button;
    static void buyItem();
    static void sellItem();
    static void equipItem();

   public:
    Item(){}
    Item(string name, int price, ofVec2f store_pos, ofVec2f inv_pos, ofxSmartFont button_font);
    bool operator==(Item const& other) const;
    bool operator!=(Item const& other) const;
    string getName();
};
