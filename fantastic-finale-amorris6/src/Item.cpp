#include "Item.h"
#include "ofApp.h"

bool Item::wants_to_buy_ = false;
bool Item::wants_to_sell_ = false;
bool Item::wants_to_equip_ = false;

Item::Item(string name, int price, ofVec2f store_pos, ofVec2f inv_pos, ofxSmartFont button_font)
    : name_(name), price_(price), store_pos_(store_pos), inv_pos_(inv_pos) {
    buy_button = nullptr;
    buy_button =
        new Button(store_pos.x + kBuyXAdj, store_pos.y + kBuyYAdj, kWidth,
                   kHeight, "BUY", button_font, buyItem);
    sell_button =
        new Button(inv_pos.x + kSellXAdj, inv_pos.y + kSellYAdj, kWidth,
                   kHeight, "SELL", button_font, sellItem);
    store_equip_button =
        new Button(store_pos.x + kEquipXAdj, store_pos.y + kEquipYAdj, kWidth,
                   kHeight, "EQUIP", button_font, equipItem);
    inv_equip_button =
        new Button(inv_pos.x + kEquipXAdj, inv_pos.y + kEquipYAdj, kWidth,
                   kHeight, "EQUIP", button_font, equipItem);
}

string Item::getName() { return name_; }

bool Item::operator==(Item const& other) const {
    return this->name_ == other.name_ && this->price_ == other.price_ &&
           this->inv_pos_ == other.inv_pos_ &&
           this->store_pos_ == other.store_pos_ &&
           this->buy_button == other.buy_button &&
           this->sell_button == other.sell_button &&
           this->store_equip_button == other.store_equip_button &&
           this->inv_equip_button == other.inv_equip_button;
}

bool Item::operator!=(Item const& other) const { return !(*this == other); }

void Item::buyItem() { wants_to_buy_ = true; }

void Item::sellItem() { wants_to_sell_ = true; }

void Item::equipItem() { wants_to_equip_ = true; }