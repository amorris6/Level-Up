#pragma once
#include "ofMain.h"
#include "ofxSmartFont.h"

class Button : public ofBaseApp {
   private:
    friend class ofApp;
    const static float kLabelYAdj;

    function<void()> func_when_pressed[1];
    float x;
    float y;
    float width;
    float height;
    std::string label;
    shared_ptr<ofxSmartFont> label_font;

   public:
    Button(float x, float y, float width, float height, std::string label,
           shared_ptr<ofxSmartFont> label_font, function<void()> function)
        : x(x),
          y(y),
          width(width),
          height(height),
          label(label),
          label_font(label_font) {
        func_when_pressed[0] = function;
    }

    Button() {}

    const static int kButtonFontSize = 28;
    std::function<void()> getFuncWhenPressed();

    bool mouseIsInside(int mouse_x, int mouse_y);
    void draw();
    bool operator==(Button const& other) const;
    bool operator!=(Button const& other) const;
};