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

void loop() { 
   // Set to RED
   leds[0] = CRGB::Red;
   FastLED.show();
   delay(500);

   // Set to GREEN
   leds[0] = CRGB::Green;
   FastLED.show();
   delay(500);

}

