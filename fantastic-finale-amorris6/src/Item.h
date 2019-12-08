#pragma once
#include "Button.h"
#include "ofxSmartFont.h"

class Item {
   private:
    const static int kWidth = 50;
    const static int kHeight = 50;
    const static int kBuyButtonWidth = 50;
    const static int kSellButtonWidth = 60;
    const static int kEquipButtonWidth = 65;
    const static int kButtonHeight = Button::kButtonFontSize;
    const static int kBuyXAdj = 35;
    const static int kBuyYAdj = 50;
    const static int kSellXAdj = 35;
    const static int kSellYAdj = 50;
    const static int kEquipXAdj = -35;
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
    Button* equip_button;
    static void buyItem();
    static void sellItem();
    static void equipItem();
    Button store_buttons_[2];
    Button inv_buttons_[2];

   public:
    Item() {}
    Item(string name, int price, int store_page, int inv_page,
         float store_pos_x, float store_pos_y, float inv_pos_x, float inv_pos_y,
         shared_ptr<ofxSmartFont> button_font);
    Item(string name, int price, int store_page, int inv_page,
         ofVec2f store_pos, ofVec2f inv_pos,
         shared_ptr<ofxSmartFont> button_font);
    virtual ~Item() {}
    bool operator==(Item const& other) const;
    bool operator!=(Item const& other) const;
    string getName();
    int getPrice();
};
