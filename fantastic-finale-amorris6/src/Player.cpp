#include "Player.h"
#include "ofApp.h"

ofRectangle Player::getRect() {
    // width/2 fits the player sprite
    return ofRectangle(position, Character::kCharWidth / 2,
                       Character::kCharHeight);
}

int Player::getLvl() { return lvl; }
bool Player::canMoveInDirection(PlayerDirection direction) {
    kMoveSideSpeed = ofGetWindowWidth() / 205;
    kMoveUpSpeed = ofGetWindowHeight() / 96;
    switch (direction) {
        case UP:
            if (position.y >= kMoveUpSpeed) {
                return true;
            }
            return false;
        case DOWN:
            if (position.y <=
                (int)ofGetWindowHeight() -
                    (Character::kCharHeight + kMoveUpSpeed)) {
                return true;
            }
            return false;
        case LEFT:
            if (position.x >= kMoveSideSpeed) {
                return true;
            }
            return false;
        case RIGHT:
            if (position.x <=
                (int)ofGetWindowWidth() -
                    (Character::kCharWidth + kMoveSideSpeed)) {
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
                position.y -= kMoveUpSpeed;
            } else {
                position.y = ofGetWindowHeight();
                ofApp::setupResources();
                ofApp::stage_num_ += ofApp::kStageNumChangeUp;
            }
            break;
        case DOWN:
            if (canMoveInDirection(DOWN)) {
                position.y += kMoveUpSpeed;
            } else {
                position.y = (int)ofGetWindowHeight() - Character::kCharHeight;
            }
            break;
        case LEFT:
            if (canMoveInDirection(LEFT)) {
                position.x -= kMoveSideSpeed;
            } else {
                position.x = 0;
            }
            break;
        case RIGHT:
            if (canMoveInDirection(RIGHT)) {
                position.x += kMoveUpSpeed;
            } else {
                position.x = 0;
                ofApp::setupResources();
                ofApp::stage_num_ += ofApp::kStageNumChangeRight;
            }
            break;
    }
}