#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("fantastic-finale-amorris6");
    ofBackground(255, 0, 255);
    background_music_enabled_ = true;
    background_music_player_.load("C:\\CS 126\\Vivaldi-Spring.mp3");
    ofxSmartFont::add("C:\\CS 126\\Fonts\\Roboto-Black.ttf", kFontSize, "Roboto-Black");
    myFont = ofxSmartFont::get("Roboto-Black");
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int dir = UP; dir <= RIGHT; dir++) {
        if (move_key_is_pressed_[dir]) {
            moveInDirection(player, dir);
        }
    }
    // TODO: Create arrays of string file paths and ofSoundPlayers, creating a
    // looping soundtrack increment a variable to check times songs switched, or
    // just start playing at track1, instead of track0
    if (background_music_enabled_ && !background_music_player_.isPlaying()) {
        background_music_player_.play();
        // background_music_player_.load("C:\\CS 126\\Vivaldi-Fall.mp3");
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
    myFont->draw("PLEASE GOD, WORK!", ofGetWindowWidth() / 2, ofGetWindowHeight()/2);
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
