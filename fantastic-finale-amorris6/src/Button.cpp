#include "Button.h"

const float Button::kLabelYAdj = 0.5;

bool Button::mouseIsInside(int mouse_x, int mouse_y) {
    if (x <= mouse_x && mouse_x <= x + width && y <= mouse_y &&
        mouse_y <= y + height) {
        return true;
    }
    return false;
}

void Button::draw() {
    ofNoFill();
    ofDrawRectangle(x, y, width, height);
    label_font.draw(label, x, y + (height + kButtonFontSize) * kLabelYAdj);
    ofFill();
}