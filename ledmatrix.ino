#include <FastLED.h>
#include "LEDMatrix.h"

#define SIZE_X 32
#define SIZE_Y 8
#define DATA_PIN 9

CRGB leds[SIZE_X * SIZE_Y];
LEDMatrix* ledMatrixP;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, SIZE_X * SIZE_Y, 0);
  ledMatrixP = new LEDMatrix(SIZE_X, SIZE_Y, leds);
  Serial.begin(9600);
  Serial.println("Start");
  FastLED.clear();
  FastLED.show();
  ledMatrixP->showTextHSV("12:34", 0, 100, 250, 255);
}

void loop() {
 ledMatrixP->updateText();
  FastLED.show();
}
