#include "Character.h"

ofVec2f Character::getPos() { return position_; }

int Character::getGold() { return gold_; }

int Character::getExp() { return exp_; }

int Character::getAtk() { return atk_; }

int Character::getDef() { return def_; }

int Character::getHealth() { return health_; }

float Character::getCrit() { return crit_chance_; }

ofRectangle Character::getRect() {
    return ofRectangle(position_.x, position_.y, kCharWidth, kCharHeight);
}

bool Character::operator==(Character const& other) const {
    return this->position_ == other.position_ 
		&& this->gold_ == other.gold_ 
		&& this->exp_ == other.exp_ 
		&& this->atk_ == other.atk_ 
		&& this->def_ == other.def_ 
		&& this->health_ == other.health_ 
		&& this->crit_chance_ == other.crit_chance_;
}

bool Character::operator!=(Character const& other) const {
    return !(*this == other);
}