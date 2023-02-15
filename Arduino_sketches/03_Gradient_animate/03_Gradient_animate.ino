// Include FastLED library by Daniel Garcia
#include <FastLED.h>

// Common naming from FastLED demos
#define DATA_PIN 9
#define NUM_LEDS 24

// Array of led data
CRGB leds[NUM_LEDS];

// Create a gradient palette 
// |-----------------------|
// GREEN......RED.......BLUE
CRGBPalette256 my_gradient = CRGBPalette256(
	CRGB::Green,
	CRGB::Blue,
	CRGB::Red
); 

void setup() { 
  // Neopixel ring is WS2812B chipset, GRB ordering
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  FastLED.clear();
}

uint8_t pos = 0;

void loop() {
  EVERY_N_MILLIS(5){
    for(uint8_t i=0; i<NUM_LEDS; i++){
      // Calculate position with map() then use pos to cycle it around the ring a bit
      uint8_t this_position = map(i,0,NUM_LEDS-1,0,255)+pos;
      leds[i] = ColorFromPalette(my_gradient,this_position);
    }
    FastLED.show();
    pos++;
  }
}
