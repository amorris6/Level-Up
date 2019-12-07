#include "Item.h"

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

string Item::getName() { return name_; }