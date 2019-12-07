#pragma once
#include "Button.h"
#include "ofApp.h"

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
    string name_;
    ofVec2f store_pos_;
    ofVec2f inv_pos_;
    Button* buy_button;
    Button* sell_button;
    Button* store_equip_button;
    Button* inv_equip_button;
    void buyItem();
    void sellItem();
    void virtual equipItem(); 

   public:
    Item(string name, int price, ofVec2f store_pos, ofVec2f inv_pos)
        : name_(name), price_(price), store_pos_(store_pos), inv_pos_(inv_pos) {
        buy_button = new Button(store_pos.x + kBuyXAdj, store_pos.y + kBuyYAdj,
                                kWidth, kHeight, "BUY", *ofApp::button_font);
        sell_button = new Button(inv_pos.x + kSellXAdj, inv_pos.y + kSellYAdj,
                                 kWidth, kHeight, "SELL", *ofApp::button_font);
        store_equip_button = new Button(store_pos.x + kEquipXAdj, store_pos.y + kEquipYAdj,
                                        kWidth, kHeight, "EQUIP", *ofApp::button_font);
        inv_equip_button = new Button(inv_pos.x + kEquipXAdj, inv_pos.y + kEquipYAdj,
                                      kWidth, kHeight, "EQUIP", *ofApp::button_font);
    }
    bool operator==(Item const& other) const;
    bool operator!=(Item const& other) const;
    string getName();
};
