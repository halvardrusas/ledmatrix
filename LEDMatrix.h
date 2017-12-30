

#ifndef LEDMATRIX_H
#define LEDMATRIX_H

#include <FastLED.h>

class LEDMatrix {
  private:
    CRGB* leds;
    int sizeX;
    int sizeY;
    int pixel(int x, int y);
    static const int maxCharInText = 25;
    char text[maxCharInText+1];
    unsigned long timeWhenCalled;
    float startX_pos;
    int hue;
    int sat;
    int val;
  public:
    LEDMatrix(const int sizeX, const int sizeY, CRGB* leds);
    void setAllLedsHSV(const uint8_t hue, const uint8_t saturation,
                       const uint8_t intensity);
    void setAllLedsRGB(const uint8_t hue, const uint8_t saturation,
                       const uint8_t intensity);
    void showCharacterHSV(unsigned char c, float x_pos, int hue, int sat, int val);
    void showTextHSV(char* str, float x_pos, int hue, int sat, int val);
    void updateText();
};

#endif
