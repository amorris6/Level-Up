#pragma once
#include "ofxSmartFont.h"
#include "ofMain.h"

class Button : public ofBaseApp {
   private:
    const static float kLabelYAdj;

    float x;
    float y;
    float width;
    float height;
    std::string label;
    ofxSmartFont label_font;

   public:
    const static int kButtonFontSize = 28;

    Button(float x, float y, float width, float height, std::string label,
           ofxSmartFont label_font)
        : x(x),
          y(y),
          width(width),
          height(height),
          label(label),
          label_font(label_font) {}
    bool mouseIsInside(int mouse_x, int mouse_y);
    void draw();
};