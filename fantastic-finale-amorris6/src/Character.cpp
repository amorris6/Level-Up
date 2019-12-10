#include "Character.h"

ofVec2f Character::getPos() { return position; }

int Character::getGold() { return gold; }

int Character::getExp() { return exp; }

int Character::getAtk() { return atk; }

int Character::getDef() { return def; }

int Character::getHealth() { return health; }

float Character::getCrit() { return crit_chance; }

ofRectangle Character::getRect() {
    return ofRectangle(position.x, position.y, kCharWidth, kCharHeight);
}

bool Character::operator==(Character const& other) const {
    return this->position == other.position 
		&& this->gold == other.gold 
		&& this->exp == other.exp 
		&& this->atk == other.atk 
		&& this->def == other.def 
		&& this->health == other.health 
		&& this->crit_chance == other.crit_chance;
}

bool Character::operator!=(Character const& other) const {
    return !(*this == other);
}