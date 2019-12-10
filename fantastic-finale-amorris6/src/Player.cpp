#include "Player.h"
#include "ofApp.h"
const float Player::kMoveSideDistFactor = 1.0 / 205.0;
const float Player::kMoveVertDistFactor = 1.0 / 96.0;

ofRectangle Player::getRect() {
    // width/2 fits the player sprite
    return ofRectangle(position, kPlayerWidth, Character::kCharHeight);
}

int Player::getLvl() { return lvl; }

bool Player::canMoveInDirection(PlayerDirection direction) {
    move_side_distance = (int)(ofGetWindowWidth() * kMoveSideDistFactor);
    move_vert_distance = (int)(ofGetWindowHeight() * kMoveVertDistFactor);
    switch (direction) {
        case UP:
            if (position.y >= move_vert_distance) {
                return true;
            }
            return false;
        case DOWN:
            if (position.y 
				<= ((int)ofGetWindowHeight() 
				- (Character::kCharHeight + move_vert_distance))) {
                return true;
            }
            return false;
        case LEFT:
            if (position.x >= move_side_distance) {
                return true;
            }
            return false;
        case RIGHT:
            if (position.x 
				<= ((int)ofGetWindowWidth() 
				- (Character::kCharWidth + move_side_distance))) {
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
                position.y -= move_vert_distance;
            } else {
                position.y = ofGetWindowHeight();
                ofApp::setupResources();
                ofApp::stage_num_ += ofApp::kStageNumChangeUp;
            }
            break;
        case DOWN:
            if (canMoveInDirection(DOWN)) {
                position.y += move_vert_distance;
            } else {
                position.y = (int)ofGetWindowHeight() - Character::kCharHeight;
            }
            break;
        case LEFT:
            if (canMoveInDirection(LEFT)) {
                position.x -= move_side_distance;
            } else {
                position.x = 0;
            }
            break;
        case RIGHT:
            if (canMoveInDirection(RIGHT)) {
                position.x += move_vert_distance;
            } else {
                position.x = 0;
                ofApp::setupResources();
                ofApp::stage_num_ += ofApp::kStageNumChangeRight;
            }
            break;
    }
}