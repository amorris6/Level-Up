#include "Player.h"
#include "ofApp.h"

ofRectangle Player::getRect() {
	//width/2 fits the player sprite
    return ofRectangle(position, Character::kCharWidth / 2,
                       Character::kCharHeight);
}

bool Player::canMoveInDirection(PlayerDirection direction) {
    switch (direction) {
        case UP:
            if (position.y >= Character::kMoveSpeed) {
                return true;
            }
            return false;
        case DOWN:
            if (position.y <=
                (int)ofGetWindowHeight() -
                    (Character::kCharHeight + Character::kMoveSpeed)) {
                return true;
            }
            return false;
        case LEFT:
            if (position.x >= Character::kMoveSpeed) {
                return true;
            }
            return false;
        case RIGHT:
            if (position.x <=
                (int)ofGetWindowWidth() -
                    (Character::kCharWidth + Character::kMoveSpeed)) {
                return true;
            }
            return false;
        default:
            return false;
    }
    return true;
}

void Player::moveInDirection(int direction_index) {
    switch (direction_index) {
        case UP:
            if (canMoveInDirection(UP)) {
                position.y -= Character::kMoveSpeed;
            } else {
                position.y = 0;
            }
            break;
        case DOWN:
            if (canMoveInDirection(DOWN)) {
                position.y += Character::kMoveSpeed;
            } else {
                position.y =
                    (int)ofGetWindowHeight() - Character::kCharHeight;
            }
            break;
        case LEFT:
            if (canMoveInDirection(LEFT)) {
                position.x -= Character::kMoveSpeed;
            } else {
                position.x = 0;
            }
            break;
        case RIGHT:
            if (canMoveInDirection(RIGHT)) {
                position.x += Character::kMoveSpeed;
            } else {
                position.x = 0;
                ofApp::setupResources();
            }
            break;
    }
}