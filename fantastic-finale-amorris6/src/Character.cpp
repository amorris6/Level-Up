#include "Character.h"

int Character::getGold() { return gold; }

ofVec2f Character::getPos() { return position; }

ofRectangle Character::getRect() {
    return ofRectangle(position.x, position.y, kCharWidth, kCharHeight);
}

bool Character::operator==(Character const& other) const {
    return this->position == other.position;
}

bool Character::operator!=(Character const& other) const {
    return !(*this == other);
}