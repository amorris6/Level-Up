#pragma once
#include "Button.h"
#include "ofxSmartFont.h"

class Item {
   private:
    const static int kWidth = 50;
    const static int kHeight = 50;
    const static int kBuyButtonWidth = 50;
    const static int kSellButtonWidth = 50;
    const static int kEquipButtonWidth = 50;
    const static int kButtonHeight = Button::kButtonFontSize;
    const static int kBuyXAdj = 50;
    const static int kBuyYAdj = 50;
    const static int kSellXAdj = 50;
    const static int kSellYAdj = 50;
    const static int kEquipXAdj = -50;
    const static int kEquipYAdj = 50;
    friend class ofApp;
    int store_page_;
    int inv_page_;
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
    Item() {}
    Item(string name, int price, int store_page, int inv_page,
         float store_pos_x, float store_pos_y, float inv_pos_x, float inv_pos_y,
         ofxSmartFont button_font);
    Item(string name, int price, int store_page, int inv_page,
         ofVec2f store_pos, ofVec2f inv_pos, ofxSmartFont button_font);
    bool operator==(Item const& other) const;
    bool operator!=(Item const& other) const;
    string getName();
};
