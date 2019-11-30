#include "Player.h"

int Player::getGold() { return gold; }

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

void moveInDirection(Player& player, int direction_index) {
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
                    (int)ofGetWindowHeight() - Character::kCharHeight;
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
                    (int)ofGetWindowWidth() - Character::kCharWidth;
            }
            break;
    }
}