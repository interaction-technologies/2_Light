// Include FastLED library by Daniel Garcia
#include <FastLED.h>

// Common naming from FastLED demos
#define DATA_PIN 9
#define NUM_LEDS 1

// Array of led data
CRGB leds[NUM_LEDS];

void setup() { 
   // 8mm Neopixel pins are WS2812B chipset, RGB ordering
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
   FastLED.clear();
}

// Create a gradient palette with red at one end and green at the other
// |-----------------------|
// RED.................GREEN
DEFINE_GRADIENT_PALETTE(my_gradient){
   0,    255,0,0,
   255,  0,255,0,
};
CRGBPalette256 red_green_fade = my_gradient; 

// Variable used to calculate timing of fade
uint8_t position = 0;

void loop() { 
   // Repeat every n milliseconds
   EVERY_N_MILLIS(50){

      // Select colour from palette at position
      leds[0] = ColorFromPalette(red_green_fade, position); 

      // Show LED
      FastLED.show();

      // Increase count by 1 for next time (will automatically loop from 255->0)
      position++; 
   }
}
