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

// How many pulses per minute
uint8_t bpm = 30;

void loop() { 
   EVERY_N_MILLIS(5) {
      // Clear strip
      FastLED.clear();
      
      // beat8(x) returns a number from 0 to 255, looping x times per minute
      uint8_t pos = beat8(bpm); 

      // Convert the position to an index for the LED on our strip
      uint8_t led = map8(pos,0,NUM_LEDS-1);
      leds[led] = CRGB::White;
      FastLED.show();
   }
}
