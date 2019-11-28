#include "Character.h"

ofVec2f Character::getPos() { 
	return position; 
}

ofRectangle Character::getRect() { 
	return ofRectangle(position.x, position.y, kPlayerWidth, kPlayerHeight); 
}

bool Character::operator==(Character const& other) const { 
	return this->position == other.position; 
}

bool Character::operator!=(Character const& other) const { 
	return !(*this == other);
}

void moveInDirection(Character &player, int direction_index) {
    switch (direction_index) {
        case UP:
            if (player.canMoveInDirection(UP)) {
                player.position.y -= Character::kMoveSpeed;
            } else {
                player.position.y = 0;
            }
            break;
        case DOWN:
            if (player.canMoveInDirection(DOWN)) {
                player.position.y += Character::kMoveSpeed;
            } else {
                player.position.y =
                    (int)ofGetWindowHeight() - Character::kPlayerHeight;
            }
            break;
        case LEFT:
            if (player.canMoveInDirection(LEFT)) {
                player.position.x -= Character::kMoveSpeed;
            } else {
                player.position.x = 0;
            }
            break;
        case RIGHT:
            if (player.canMoveInDirection(RIGHT)) {
                player.position.x += Character::kMoveSpeed;
            } else {
                player.position.x =
                    (int)ofGetWindowWidth() - Character::kPlayerWidth;
            }
            break;
    }
}

bool Character::canMoveInDirection(PlayerDirection direction) {
    switch (direction) {
        case UP:
            if (position.y >= Character::kMoveSpeed) {
                return true;
            }
            return false;
        case DOWN:
            if (position.y <=
                (int)ofGetWindowHeight() -
                    (Character::kPlayerHeight + Character::kMoveSpeed)) {
                return true;
            }
            return false;
        case LEFT:
            if (position.x >= Character::kMoveSpeed) {
                return true;
            }
            return false;
        case RIGHT:
            if (position.x <= (int)ofGetWindowWidth() -
                    (Character::kPlayerWidth + Character::kMoveSpeed)) {
                return true;
            }
            return false;
        default:
            return false;
    }
    return true;
}