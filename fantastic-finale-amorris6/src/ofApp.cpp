#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {}

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
void ofApp::draw() { drawPlayer(); }

//--------------------------------------------------------------
void ofApp::drawPlayer() {
    ofDrawRectangle(player.getPos().x, player.getPos().y, Player::kPlayerWidth,
                    Player::kPlayerHeight);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    ofSetColor(255, 0, 0, 255);
    int upper_key = toupper(key);
    switch (upper_key) {
        case 'W':
            move_key_is_pressed_[UP] = true;
            break;
        case 'S':
            move_key_is_pressed_[DOWN] = true;
            break;
        case 'A':
            move_key_is_pressed_[LEFT] = true;
            break;
        case 'D':
            move_key_is_pressed_[RIGHT] = true;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    ofSetColor(255, 255, 255, 255);
    int upper_key = toupper(key);
    switch (upper_key) {
        case 'W':
            move_key_is_pressed_[UP] = false;
            break;
        case 'S':
            move_key_is_pressed_[DOWN] = false;
            break;
        case 'A':
            move_key_is_pressed_[LEFT] = false;
            break;
        case 'D':
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
