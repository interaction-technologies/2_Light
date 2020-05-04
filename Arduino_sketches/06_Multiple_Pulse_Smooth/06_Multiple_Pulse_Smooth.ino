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
      
      // Same as beat8(x) but eases in and out at each end
      uint8_t pos = beat8(bpm); 

      // Convert the position to an index for the LED on our strip
      uint8_t led = map8(pos,0,NUM_LEDS-1);

      // Smoothly move pulse along strip
      // Tip: add a piece of paper over the LEDs to see the effect clearly
      uint8_t scaler = pos*NUM_LEDS;
      leds[led] += CHSV(0, 0, brighten8_raw(255-scaler));
      leds[addmod8(led,1,NUM_LEDS)] += CHSV(0, 0, brighten8_raw(scaler));
      FastLED.show();
   }
}
