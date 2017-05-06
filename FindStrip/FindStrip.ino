#include <OctoWS2811.h>

const int config = WS2811_RGB | WS2811_800kHz;
const int ledsPerStrip = 50;
const int stripToFind = 8; // change this - [1 through 8; 0 to turn them all off]

DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

#define WHITE 0xFFFFFF

void setup() {
  leds.begin();
  
  int startingPixel = ledsPerStrip * (stripToFind-1);
  int endingPixel = startingPixel + ledsPerStrip;

  // First, turn off all existing pixels
  for (int i=0; i < leds.numPixels(); i++) {
    leds.setPixel(i, 0x000000);
  }

  // Then light up the current string
  for (int i=startingPixel; i<endingPixel; i++) {
    leds.setPixel(i, WHITE);
  }

  leds.show();


}

void loop() {}
