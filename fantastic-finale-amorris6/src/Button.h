#pragma once
#include "ofMain.h"
#include "ofxSmartFont.h"

class Button : public ofBaseApp {
   private:
    friend class ofApp;
    const static float kLabelYAdj;

    function<void()> func_when_pressed_[1];
    float x_;
    float y_;
    float width_;
    float height_;
    string label_;
    shared_ptr<ofxSmartFont> label_font_;

   public:
    Button(float x, float y, 
		   float width, 
		   float height, 
		   string label,
           shared_ptr<ofxSmartFont> label_font, 
		   function<void()> function)
        : x_(x),
          y_(y),
          width_(width),
          height_(height),
          label_(label),
          label_font_(label_font) {
          func_when_pressed_[0] = function;
    }
    Button() {}

    const static int kButtonFontSize = 28;

    function<void()> getFuncWhenPressed();

    bool mouseIsInside(int mouse_x, int mouse_y);
    void draw();
    bool operator==(Button const& other) const;
    bool operator!=(Button const& other) const;
};