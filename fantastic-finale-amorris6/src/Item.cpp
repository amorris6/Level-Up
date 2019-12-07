#include "Item.h"
#include "ofApp.h"

bool Item::wants_to_buy_ = false;
bool Item::wants_to_sell_ = false;
bool Item::wants_to_equip_ = false;

Item::Item(string name, int price, int store_page, int inv_page,
           float store_pos_x, float store_pos_y, float inv_pos_x,
           float inv_pos_y, ofxSmartFont button_font)
    : name_(name), price_(price), store_page_(store_page), inv_page_(inv_page) {
    store_pos_.set(store_pos_x, store_pos_y);
    inv_pos_.set(inv_pos_x, inv_pos_y);
    buy_button =
        new Button(store_pos_x + kBuyXAdj, store_pos_y + kBuyYAdj,
                   kBuyButtonWidth, kHeight, "BUY", button_font, buyItem);
    sell_button =
        new Button(inv_pos_x + kSellXAdj, inv_pos_y + kSellYAdj,
                   kSellButtonWidth, kHeight, "SELL", button_font, sellItem);
    store_equip_button =
        new Button(store_pos_x + kEquipXAdj, store_pos_y + kEquipYAdj,
                   kEquipButtonWidth, kHeight, "EQUIP", button_font, equipItem);
    inv_equip_button =
        new Button(inv_pos_x + kEquipXAdj, inv_pos_y + kEquipYAdj,
                   kEquipButtonWidth, kHeight, "EQUIP", button_font, equipItem);
}

Item::Item(string name,
	       int price, 
	       int store_page, 
	       int inv_page, 
	       ofVec2f store_pos, 
	       ofVec2f inv_pos, 
	       ofxSmartFont button_font)
    : Item(name, 
		   price, 
		   store_page, 
		   inv_page, 
		   store_pos.x, store_pos.y, 
		   inv_pos.x, inv_pos.y, 
		   button_font) {}

string Item::getName() { return name_; }

bool Item::operator==(Item const& other) const {
    return this->name_ == other.name_ 
		&& this->price_ == other.price_ 
		&& this->inv_pos_ == other.inv_pos_ 
		&& this->store_pos_ == other.store_pos_ 
		&& this->buy_button == other.buy_button 
		&& this->sell_button == other.sell_button 
		&& this->store_equip_button == other.store_equip_button
		&& this->inv_equip_button == other.inv_equip_button;
}

bool Item::operator!=(Item const& other) const { return !(*this == other); }

void Item::buyItem() { wants_to_buy_ = true; }

void Item::sellItem() { wants_to_sell_ = true; }

void Item::equipItem() { wants_to_equip_ = true; }