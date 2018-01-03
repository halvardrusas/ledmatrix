/*

   Author: per-olav & halvardrusas
   With relays for power
*/

#include <FastLED.h>
#include "LEDMatrix.h"

#define SIZE_X 32
#define SIZE_Y 8
#define DATA_PIN 9

const int relayPin1 = 49; //relay
const int relayPin2 = 51;
const int buzzerPin = 53;

CRGB leds[SIZE_X * SIZE_Y];
LEDMatrix* ledMatrixP;

void setup() {

  pinMode(relayPin1, OUTPUT); //relay
  pinMode(relayPin2, OUTPUT);
  pinMode(buzzerPin,OUTPUT);

  digitalWrite(relayPin1, LOW); //LOW IS HIGH, HIGH IS LOW
  digitalWrite(relayPin2, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(200);
  digitalWrite(buzzerPin,HIGH);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, SIZE_X * SIZE_Y, 0);
  ledMatrixP = new LEDMatrix(SIZE_X, SIZE_Y, leds);
  Serial.begin(9600);
  Serial.println("Start");
  FastLED.clear();
  FastLED.show();
  ledMatrixP->showTextHSV("120", 0, 0, 250, 50);
  ledMatrixP->drawRectangleRGB(28,2,4,4,20,0,0);
  //ledMatrixP->drawRectangleRGB(29,3,3,2,0,20,0);
  //ledMatrixP->drawRectangleRGB(29,6,3,2,0,0,20);
}


void loop() {
  ledMatrixP->updateText();

  FastLED.show();
}
