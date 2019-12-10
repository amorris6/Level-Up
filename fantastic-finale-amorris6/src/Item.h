#pragma once
#include "Button.h"
#include "ofxSmartFont.h"

class Item {
   protected:
    const static int kWidth = 50;
    const static int kHeight = 50;
    const static int kBuyButtonWidth = 35;
    const static int kSellButtonWidth = 60;
    const static int kEquipButtonWidth = 55;
    const static int kUnequipButtonWidth = 80;
    const static int kButtonHeight = Button::kButtonFontSize;
    const static int kBuyXAdj = 35;
    const static int kBuyYAdj = 50;
    const static int kSellXAdj = 35;
    const static int kSellYAdj = 50;
    const static int kEquipXAdj = -35;
    const static int kEquipYAdj = 50;
    const static int kUnequipXAdj = -50;
    const static int kUnequipYAdj = 50;
    const static string kBuyLabel;
    const static string kSellLabel;
    const static string kEquipLabel;
    const static string kUnequipLabel;

    friend class ofApp;
    int page_;
    int price_;
    static bool wants_to_buy_;
    static bool wants_to_sell_;
    static bool wants_to_equip_;
    static bool wants_to_unequip_;
    string name_;
    ofVec2f pos_;
    Button* buy_button_;
    Button* sell_button_;
    Button* equip_button_;
    Button* unequip_button_;
    Button store_buttons_[3];
    Button inv_buttons_[2];
    function<void()> func_when_equipped_[1];
    function<void()> func_when_unequipped_[1];

    Item(string name, 
		 int price, 
		 int page_num, 
		 float pos_x, float pos_y,
         shared_ptr<ofxSmartFont> button_font);
    Item(string name, 
		 int price, 
		 int page_num, 
		 ofVec2f pos,
         shared_ptr<ofxSmartFont> button_font);

    static void buyItem();
    static void sellItem();
    static void equipItem();
    static void unequipItem();

   public:
    Item() {}
    Item(string name, 
		 int price, 
		 int page_num, 
		 float pos_x, 
		 float pos_y,
         function<void()> func_when_equipped,
         function<void()> func_when_unequipped,
         shared_ptr<ofxSmartFont> button_font);
    Item(string name, 
		 int price, 
		 int page_num, 
		 ofVec2f pos,
         function<void()> func_when_equipped,
         function<void()> func_when_unequipped,
         shared_ptr<ofxSmartFont> button_font);

    virtual ~Item() {}
    bool operator==(Item const& other) const;
    bool operator!=(Item const& other) const;
    string getName();
    int getPrice();
    function<void()> getFuncWhenEquipped();
    function<void()> getFuncWhenUnequipped();
};
