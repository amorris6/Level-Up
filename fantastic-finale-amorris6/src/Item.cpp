#include "Item.h"
#include "ofApp.h"

bool Item::wants_to_buy_ = false;
bool Item::wants_to_sell_ = false;
bool Item::wants_to_equip_ = false;
bool Item::wants_to_unequip_ = false;

Item::Item(string name, int price, int page, float pos_x, float pos_y,
           shared_ptr<ofxSmartFont> button_font)
    : name_(name), price_(price), page_(page) {
    pos_.set(pos_x, pos_y);
    buy_button = new Button(pos_x + kBuyXAdj, pos_y + kHeight, kBuyButtonWidth,
                            kButtonHeight, "BUY", button_font, buyItem);
    sell_button =
        new Button(pos_x + kSellXAdj, pos_y + kHeight, kSellButtonWidth,
                   kButtonHeight, "SELL", button_font, sellItem);
    equip_button =
        new Button(pos_x + kEquipXAdj, pos_y + kHeight, kEquipButtonWidth,
                   kButtonHeight, "EQUIP", button_font, equipItem);
    unequip_button =
        new Button(pos_x + kUnequipXAdj, pos_y + kHeight, kUnequipButtonWidth,
                   kButtonHeight, "UNEQUIP", button_font, unequipItem);
    store_buttons_[0] = *buy_button;
    store_buttons_[1] = *equip_button;
    store_buttons_[2] = *unequip_button;
    inv_buttons_[0] = *sell_button;
    inv_buttons_[1] = *equip_button;
};

Item::Item(string name, int price, int page, ofVec2f pos,
           shared_ptr<ofxSmartFont> button_font)
    : Item(name, price, page, pos.x, pos.y, button_font) {}

Item::Item(string name, int price, int page, float pos_x, float pos_y,
           function<void()> func_when_equipped,
           function<void()> func_when_unequipped,
           shared_ptr<ofxSmartFont> button_font)
    : Item(name, price, page, pos_x, pos_y, button_font) {
    func_when_equipped_[0] = func_when_equipped;
    func_when_unequipped_[0] = func_when_unequipped;
}

Item::Item(string name, int price, int page, ofVec2f pos,
           function<void()> func_when_equipped,
           function<void()> func_when_unequipped,
           shared_ptr<ofxSmartFont> button_font)
    : Item(name, price, page, pos.x, pos.y, func_when_equipped,
           func_when_unequipped, button_font) {}

string Item::getName() { return name_; }

int Item::getPrice() { return price_; }

function<void()> Item::getFuncWhenEquipped() { return func_when_equipped_[0]; }

function<void()> Item::getFuncWhenUnequipped() {
    return func_when_unequipped_[0];
}

bool Item::operator==(Item const& other) const {
    return this->name_ == other.name_ && this->price_ == other.price_ &&
           this->pos_ == other.pos_ && this->buy_button == other.buy_button &&
           this->sell_button == other.sell_button &&
           this->equip_button == other.equip_button;
}

bool Item::operator!=(Item const& other) const { return !(*this == other); }

void Item::buyItem() { wants_to_buy_ = true; }

void Item::sellItem() { wants_to_sell_ = true; }

void Item::equipItem() { wants_to_equip_ = true; }

void Item::unequipItem() { wants_to_unequip_ = true; }