// Include FastLED library by Daniel Garcia
#include <FastLED.h>

// Common naming from FastLED demos
#define DATA_PIN 9
#define NUM_LEDS 24

// Array of led data
CRGB leds[NUM_LEDS];

// Create a gradient palette 
// |-----------------------|
// BLUE...RED...BLUE
DEFINE_GRADIENT_PALETTE(blue_red_p){
   0,    0,   0, 255,
   127,  255, 0, 0,
   255,  0, 0, 255
};
CRGBPalette256 my_gradient = blue_red_p; 

void setup() { 
   // Neopixel ring is WS2812B chipset, GRB ordering
   FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
   FastLED.clear();

   // Draw gradient around ring using map()
   for(uint8_t i=0; i<NUM_LEDS; i++){
      leds[i] = ColorFromPalette(my_gradient, map(i,0,NUM_LEDS-1,0,255));
   }
   FastLED.show();
}

void loop() { 
}
