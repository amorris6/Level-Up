#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() { 
	ofSetWindowTitle("fantastic-finale-amorris6");
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int dir = UP; dir <= RIGHT; dir++) {
        if (move_key_is_pressed_[dir]) {
            moveInDirection(player, dir);
        }
    }
    draw();
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (num_of_keys_pressed_ != 0) {
        ofSetColor(255, 0, 0, 255);
    } else {
        ofSetColor(255, 255, 255, 255);
    }
    drawPlayer();
}

//--------------------------------------------------------------
void ofApp::drawPlayer() {
    ofDrawRectangle(player.getPos().x, player.getPos().y, Player::kPlayerWidth,
                    Player::kPlayerHeight);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    int upper_key = toupper(key);
    switch (upper_key) {
        case 'W':
            if (!move_key_is_pressed_[UP]) {
                num_of_keys_pressed_++;
                move_key_is_pressed_[UP] = true;
            }
            break;
        case 'S':
            if (!move_key_is_pressed_[DOWN]) {
                num_of_keys_pressed_++;
                move_key_is_pressed_[DOWN] = true;
            }
            break;
        case 'A':
            if (!move_key_is_pressed_[LEFT]) {
                num_of_keys_pressed_++;
                move_key_is_pressed_[LEFT] = true;
            }
            break;
        case 'D':
            if (!move_key_is_pressed_[RIGHT]) {
                num_of_keys_pressed_++;
                move_key_is_pressed_[RIGHT] = true;
            }
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    int upper_key = toupper(key);
    switch (upper_key) {
        case 'W':
            num_of_keys_pressed_--;
            move_key_is_pressed_[UP] = false;
            break;
        case 'S':
            num_of_keys_pressed_--;
            move_key_is_pressed_[DOWN] = false;
            break;
        case 'A':
            num_of_keys_pressed_--;
            move_key_is_pressed_[LEFT] = false;
            break;
        case 'D':
            num_of_keys_pressed_--;
            move_key_is_pressed_[RIGHT] = false;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
