#include "Button.h"
#include "ofApp.h"

const float Button::kLabelYAdj = 0.5;

std::function<void()> Button::getFuncWhenPressed() { return func_when_pressed[0]; }

bool Button::mouseIsInside(int mouse_x, int mouse_y) {
    if (x <= mouse_x && mouse_x <= x + width && y <= mouse_y &&
        mouse_y <= y + height) {
        return true;
    }
    return false;
}

void Button::draw() {
    ofSetColor(ofApp::kBlack);
    if (ofGetBackgroundColor() == ofApp::kBlack) {
        ofSetColor(ofApp::kWhite);
    }
    ofNoFill();
    ofDrawRectangle(x, y, width, height);
    label_font->draw(label, x, y + (height + kButtonFontSize) * kLabelYAdj);
    ofFill();
}

bool Button::operator==(Button const& other) const {
    return this->x == other.x 
		&& this->y == other.y 
		&& this->width == other.width 
		&& this->height == other.height 
		&& this->label == other.label;
}

bool Button::operator!=(Button const& other) const {
    return !(*this == other);
}