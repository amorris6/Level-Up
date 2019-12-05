#pragma once
#include "ofMain.h"
#include "ofxSmartFont.h"

class Button : public ofBaseApp {
   private:
    const static float kLabelYAdj;

    std::function<void()> func_when_pressed[1];
    float x;
    float y;
    float width;
    float height;
    std::string label;
    ofxSmartFont label_font;

   public:
    std::function<void()> getFuncWhenPressed();
    const static int kButtonFontSize = 28;

    Button(float x, float y, float width, float height, std::string label,
           ofxSmartFont label_font, std::function<void()> function)
        : x(x),
          y(y),
          width(width),
          height(height),
          label(label),
          label_font(label_font) {
          func_when_pressed[0] = function;
	}

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
    bool operator==(Button const& other) const;
    bool operator!=(Button const& other) const;
};