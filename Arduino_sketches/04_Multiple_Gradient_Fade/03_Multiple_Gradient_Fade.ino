// Include FastLED library by Daniel Garcia
#include <FastLED.h>

// Common naming from FastLED demos
#define DATA_PIN 9
#define NUM_LEDS 5

// Array of led data
CRGB leds[NUM_LEDS];

void setup() { 
   // 8mm Neopixel pins are WS2812B chipset, RGB ordering
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
   FastLED.clear();
}

// Create a red->blue->red gradient
// |-----------------------|
// RED........BLUE.......RED
DEFINE_GRADIENT_PALETTE(red_blue_red_p){
   0,    255, 0, 0,
   127,  0,   0, 255, 
   255,  255, 0, 0
};
CRGBPalette256 red_blue_red = red_blue_red_p; 

// Variable used to calculate timing of fade
uint8_t pos = 0;

void loop() { 
   EVERY_N_MILLIS(5){
      // Move gradient slowly across strip
      // Tip: put a piece of white paper over the LEDs to diffuse them and see the effect clearly!
      for(uint8_t i=0; i<NUM_LEDS; i++){
         // Calculate position with map() then use pos to advance it
         uint8_t this_position = map(i,0,NUM_LEDS-1,0,255)+pos;
         leds[i] = ColorFromPalette(red_blue_red,this_position);
      }
      FastLED.show();
      pos++;
   }
}
