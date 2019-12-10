#include "Button.h"
#include "ofApp.h"

const float Button::kLabelYAdj = 0.5;

std::function<void()> Button::getFuncWhenPressed() { return func_when_pressed_[0]; }

bool Button::mouseIsInside(int mouse_x, int mouse_y) {
    if (x_ <= mouse_x 
		&& mouse_x <= x_ + width_ 
		&& y_ <= mouse_y 
		&& mouse_y <= y_ + height_) {
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
    ofDrawRectangle(x_, y_, width_, height_);
    label_font_->draw(label_, x_, y_ + (height_ + kButtonFontSize) * kLabelYAdj);
    ofFill();
}

bool Button::operator==(Button const& other) const {
    return this->x_ == other.x_ 
		&& this->y_ == other.y_ 
		&& this->width_ == other.width_ 
		&& this->height_ == other.height_ 
		&& this->label_ == other.label_;
}

bool Button::operator!=(Button const& other) const {
    return !(*this == other);
}