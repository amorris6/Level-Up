#include "Item.h"
#include "ofApp.h"

bool Item::wants_to_buy_ = false;
bool Item::wants_to_sell_ = false;
bool Item::wants_to_equip_ = false;
bool Item::wants_to_unequip_ = false;
const string Item::kBuyLabel = "BUY";
const string Item::kSellLabel = "SELL";
const string Item::kEquipLabel = "EQUIP";
const string Item::kUnequipLabel = "UNEQUIP";

Item::Item(string name, 
	       int price, 
	       int page, 
	       float pos_x, 
	       float pos_y,
           shared_ptr<ofxSmartFont> button_font)
    : name_(name), price_(price), page_(page) {
    pos_.set(pos_x, pos_y);
    buy_button_ = new Button(pos_x + kBuyXAdj, 
		                     pos_y + kHeight, 
		                     kBuyButtonWidth,
                             kButtonHeight, 
		                     kBuyLabel, 
		                     button_font, 
		                     buyItem);
    sell_button_ = new Button(pos_x + kSellXAdj, 
		                      pos_y + kHeight, 
		                      kSellButtonWidth,
                              kButtonHeight, 
		                      kSellLabel, 
		                      button_font, 
		                      sellItem);
    equip_button_ = new Button(pos_x + kEquipXAdj, 
		                       pos_y + kHeight, 
		                       kEquipButtonWidth,
                               kButtonHeight, 
		                       kEquipLabel, 
		                       button_font, 
		                       equipItem);
    unequip_button_ = new Button(pos_x + kUnequipXAdj, 
		                         pos_y + kHeight, 
		                         kUnequipButtonWidth,
                                 kButtonHeight, 
		                         kUnequipLabel, 
		                         button_font, 
		                         unequipItem);
    store_buttons_[0] = *buy_button_;
    store_buttons_[1] = *equip_button_;
    store_buttons_[2] = *unequip_button_;
    inv_buttons_[0] = *sell_button_;
    inv_buttons_[1] = *equip_button_;
};

Item::Item(string name, 
	       int price, 
	       int page, 
	       ofVec2f pos,
           shared_ptr<ofxSmartFont> button_font)
    : Item(name, price, page, pos.x, pos.y, button_font) {}

Item::Item(string name, 
	       int price, 
	       int page, 
	       float pos_x, float pos_y,
           function<void()> func_when_equipped,
           function<void()> func_when_unequipped,
           shared_ptr<ofxSmartFont> button_font)
    : Item(name, price, page, pos_x, pos_y, button_font) {
    func_when_equipped_[0] = func_when_equipped;
    func_when_unequipped_[0] = func_when_unequipped;
}

Item::Item(string name, 
	       int price, 
	       int page, 
	       ofVec2f pos,
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
    return this->name_ == other.name_ 
		&& this->price_ == other.price_ 
		&& this->pos_ == other.pos_ 
		&& this->buy_button_ == other.buy_button_ 
		&& this->sell_button_ == other.sell_button_ 
		&& this->equip_button_ == other.equip_button_
		&&this->unequip_button_ == other.unequip_button_;
}

bool Item::operator!=(Item const& other) const { return !(*this == other); }

void Item::buyItem() { wants_to_buy_ = true; }

void Item::sellItem() { wants_to_sell_ = true; }

void Item::equipItem() { wants_to_equip_ = true; }

void Item::unequipItem() { wants_to_unequip_ = true; }