#include "Player.h"

ofVec2f Player::getPos() { return position; }

// TODO: const ref enum??
void moveInDirection(Player &player, int direction_index) {
    switch (direction_index) {
        case UP:
            if (player.canMoveInDirection(UP)) {
                player.position.y -= Player::kMoveSpeed;
            } else {
                player.position.y = 0;
            }
            break;
        case DOWN:
			if (player.canMoveInDirection(DOWN)) {
                player.position.y += Player::kMoveSpeed;
            } else {
                player.position.y =
                    (int) ofGetWindowHeight() - Player::kPlayerHeight;
            }
            break;
        case LEFT:
            if (player.canMoveInDirection(LEFT)) {
                player.position.x -= Player::kMoveSpeed;
            } else {
                player.position.x = 0;
            }
            break;
        case RIGHT:
            if (player.canMoveInDirection(RIGHT)) {
                player.position.x += Player::kMoveSpeed;
            } else {
                player.position.x =
                    (int) ofGetWindowWidth() - Player::kPlayerWidth;
            }
            break;
    }
}

bool Player::canMoveInDirection(PlayerDirection direction) {
    switch (direction) {
        case UP:
            if (position.y >= Player::kMoveSpeed) {
                return true;
            }
            return false;
        case DOWN:
            if (position.y <=
                (int) ofGetWindowHeight() -
                (Player::kPlayerHeight + Player::kMoveSpeed)) {
                return true;
            }
            return false;
        case LEFT:
            if (position.x >= Player::kMoveSpeed) {
                return true;
            }
            return false;
        case RIGHT:
            if (position.x <=
                (int) ofGetWindowWidth() -
                (Player::kPlayerWidth + Player::kMoveSpeed)) {
                return true;
            }
            return false;
    }
}